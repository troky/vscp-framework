/* The MIT License (MIT)
 * 
 * Copyright (c) 2014 - 2015, Andreas Merkle
 * http://www.blue-andi.de
 * vscp@blue-andi.de
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

/*******************************************************************************
    DESCRIPTION
*******************************************************************************/
/**
@brief  Main entry point
@file   main.c
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
This module contains the main entry point.

@section svn Subversion
$Author: amerkle $
$Rev: 450 $
$Date: 2015-01-06 00:31:00 +0100 (Di, 06 Jan 2015) $
*******************************************************************************/

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "system.h"
#include <stdint.h>
#include "hw.h"
#include "timerDrv.h"
#include "vscp_core.h"
#include "vscp_timer.h"
#include "vscp_portable.h"
#include "swTimer.h"
#include "time.h"
#include "pushButton.h"
#include "relay.h"
#include "windDrv.h"
#include "windObserver.h"
#include "buttonObserver.h"
#include "vscp_ps_user.h"
#include "shutterDrv.h"
#include "shutter.h"

/*******************************************************************************
    COMPILER SWITCHES
*******************************************************************************/

/*******************************************************************************
    CONSTANTS
*******************************************************************************/

/** 10 ms software timer id */
#define MAIN_SWTIMER_10MS_ID        0

/** 10 ms software timer period */
#define MAIN_SWTIMER_10MS_PERIOD    10

/** 250 ms software timer id */
#define MAIN_SWTIMER_250MS_ID       1

/** 250 ms software timer period */
#define MAIN_SWTIMER_250MS_PERIOD   250

/** Segment initialization button debouncing time in ms. */
#define MAIN_SEG_INIT_DEBOUNCE_TIME 100

/** 1 s software timer period, based on the 250 ms software timer */
#define MAIN_SWTIMER_1S_PERIOD      (1000 / MAIN_SWTIMER_250MS_PERIOD)

/** Shutter timer period in ms */
#define MAIN_SHUTTER_TIMER_PERIOD   100

/*******************************************************************************
    MACROS
*******************************************************************************/

/*******************************************************************************
    TYPES AND STRUCTURES
*******************************************************************************/

/** This type defines the supported function return values. */
typedef enum
{
    MAIN_RET_OK = 0,    /**< Successful */
    MAIN_RET_ERROR,     /**< Failed */
    MAIN_RET_ENULL      /**< Unexpected NULL pointer */

} MAIN_RET;

/** This type defines the states of the main loop state machine. */
typedef enum
{
    MAIN_STATE_START_UP = 0,    /**< VSCP framework starts up */
    MAIN_STATE_ACTIVE,          /**< VSCP framework is active */
    MAIN_STATE_SHUTDOWN,        /**< System shutdown */
    MAIN_STATE_IDLE             /**< System is idle */

} MAIN_STATE;

/*******************************************************************************
    PROTOTYPES
*******************************************************************************/

static MAIN_RET main_initRunLevel1(void);
static MAIN_RET main_initRunLevel2(void);
static void main_timerCb(void);
static void main_processStatusLamp(void);

/*******************************************************************************
    LOCAL VARIABLES
*******************************************************************************/

/** Segment init button state */
static volatile BOOL    main_isInitButtonPressed    = FALSE;

/*******************************************************************************
    GLOBAL VARIABLES
*******************************************************************************/

/*******************************************************************************
    GLOBAL FUNCTIONS
*******************************************************************************/

/**
 * Main entry point.
 *
 * @return Not used
 */
int main(void)
{
    BOOL        lastSegInitButtonState  = FALSE;                    /* Used for "raising edge" detection */
    BOOL        swTimer10MSTriggered    = FALSE;                    /* Signals that the 10 ms software timer triggered */
    uint8_t     swTimer1S               = MAIN_SWTIMER_1S_PERIOD;   /* Based on 250 ms software timer */
    MAIN_STATE  state                   = MAIN_STATE_START_UP;      /* Main loop state machine state */
    uint8_t     index                   = 0;

    /* ********** Run level 1 - interrupts disabled ********** */

    /* Enter run level 1 */
    if (MAIN_RET_OK != main_initRunLevel1())
    {
        /* Error */
        HALT();
    }

    /* ********** Run level 2 - interrupts enabled ********** */
    
    /* Enable interrupts */
    sei();

    /* Enter run level 2 */
    if (MAIN_RET_OK != main_initRunLevel2())
    {
        /* Error */
        HALT();
    }

    /* ********** Run level 3 - main loop starts ********** */

    /* Main loop */
    for(;;)
    {
        /* Process VSCP framework */
        vscp_core_process();

        /* Initialize the VSCP segment, because user pressed the segment
         * initialization button?
         *
         * If the user keeps the button pressed and it looks like the user never
         * release it, the initialization will anyway take place only once.
         */
        if ((TRUE == main_isInitButtonPressed) &&
            (FALSE == lastSegInitButtonState))
        {
            vscp_core_startNodeSegmentInit();
        }

        lastSegInitButtonState = main_isInitButtonPressed;

        /* 10 ms period */
        if (TRUE == swTimer_getStatus(MAIN_SWTIMER_10MS_ID))
        {
            /* Process every 10ms the shutter module. */
            (void)shutter_process();

            /* Process every 10ms the shutter control. */
            (void)shutterDrv_process();

            swTimer10MSTriggered = TRUE;
        }

        /* 250 ms period */
        if (TRUE == swTimer_getStatus(MAIN_SWTIMER_250MS_ID))
        {
            /* Process VSCP timers */
            vscp_timer_process(MAIN_SWTIMER_250MS_PERIOD);

            /* Process VSCP lamp blinking */
            main_processStatusLamp();

            /* Process the time */
            time_process(MAIN_SWTIMER_250MS_PERIOD);

            /* Derive a 1 s timer */
            if (0 < swTimer1S)
            {
                --swTimer1S;
            }
        }

        /* Main state machine */
        switch(state)
        {
        /* Node starts up and try to get online */
        case MAIN_STATE_START_UP:
            /* Wait until node is online */
            if (TRUE == vscp_core_isActive())
            {
                state = MAIN_STATE_ACTIVE;
            }
            break;

        /* Node is online */
        case MAIN_STATE_ACTIVE:
            /* If the node is offline, shutdown the system */
            if (FALSE == vscp_core_isActive())
            {
                state = MAIN_STATE_SHUTDOWN;
            }
            else
            {
                /* 10 ms period */
                if (TRUE == swTimer10MSTriggered)
                {
                    /* Process every 10ms the button observer. */
                    buttonObserver_process();
                }

                /* 1 s period */
                if (0 == swTimer1S)
                {
                    swTimer1S = MAIN_SWTIMER_1S_PERIOD;

                    /* Observe the wind speed and send VSCP events. */
                    windObserver_process();
                }
            }
            break;

        /* Node left online state and went offline */
        case MAIN_STATE_SHUTDOWN:
            /* Stop all shutter */
            for(index = 0; index < SHUTTER_NUM; ++index)
            {
                shutter_drive(index, SHUTTER_DIR_STOP, 0);
                shutter_enable(index, FALSE);
            }

            state = MAIN_STATE_IDLE;
            break;

        /* Node waits for a reset */
        case MAIN_STATE_IDLE:
            /* Nothing to do. */
            break;

        default:
            /* Should never happen. */
            break;
        }

        /* Reset software timer flags */
        swTimer10MSTriggered = FALSE;
    }

    return 0;
}

/*******************************************************************************
    LOCAL FUNCTIONS
*******************************************************************************/

/**
 * This function initializes run level 1.
 * Precondition: Interrupts are disabled
 *
 * @return Status
 */
static MAIN_RET main_initRunLevel1(void)
{
    MAIN_RET    status              = MAIN_RET_OK;
    uint8_t     index               = 0;
    uint16_t    switchingPwmValue   = 0;
    uint16_t    holdingPwmValue     = 0;

    /* Initialize the hardware */
    hw_init();

    /* Initialize a hardware timer */
    timerDrv_init();
    timerDrv_setCallback(main_timerCb);

    /* Initialize push button driver */
    pushButton_init();

    /* Initialize relay driver */
    relay_init();

    /* Initialize wind driver */
    windDrv_init();
    
    /* Initialize the VSCP framework */
    if (VSCP_CORE_RET_OK != vscp_core_init())
    {
        status = MAIN_RET_ERROR;
    }

    /* Initialize software timer */
    swTimer_init();

    /* Initialize the time module */
    time_init();

    /* Initialize wind speed observer */
    windObserver_init();

    /* Initialize button observer */
    buttonObserver_init();

    /* Initialize the shutter control */
    shutterDrv_init();

    /* Initialize the shutter module */
    shutter_init();

    /* Configure all software timer */
    swTimer_start(MAIN_SWTIMER_10MS_ID, MAIN_SWTIMER_10MS_PERIOD, FALSE);
    swTimer_start(MAIN_SWTIMER_250MS_ID, MAIN_SWTIMER_250MS_PERIOD, FALSE);

    /* Configure wind measurement */
    if (1 == vscp_ps_user_readWindEnable())
    {
        buttonObserver_setFilter(0x7f); /* Disable observation of button 8 */
        windDrv_enable(TRUE);
    }

    /* Configure relays */
    switchingPwmValue  = ((uint16_t)vscp_ps_user_readRelayControl(0)) << 0;
    switchingPwmValue |= ((uint16_t)vscp_ps_user_readRelayControl(1)) << 8;
    relay_setSwitchingPwm(switchingPwmValue);

    holdingPwmValue  = ((uint16_t)vscp_ps_user_readRelayControl(2)) << 0;
    holdingPwmValue |= ((uint16_t)vscp_ps_user_readRelayControl(3)) << 8;
    relay_setHoldingPwm(holdingPwmValue);

    /* Configure shutters */
    for(index = 0; index < SHUTTER_NUM; ++index)
    {
        uint16_t    maxUpTime   = 0;
        uint16_t    maxDownTime = 0;
        uint16_t    turnTime    = 0;

        maxUpTime  = (uint16_t)vscp_ps_user_readShutterMaxUpTime(index * 2 + 0);
        maxUpTime |= (uint16_t)vscp_ps_user_readShutterMaxUpTime(index * 2 + 1) << 8;

        maxDownTime  = (uint16_t)vscp_ps_user_readShutterMaxDownTime(index * 2 + 0);
        maxDownTime |= (uint16_t)vscp_ps_user_readShutterMaxDownTime(index * 2 + 1) << 8;

        turnTime  = (uint16_t)vscp_ps_user_readShutterTurnTime(index * 2 + 0);
        turnTime |= (uint16_t)vscp_ps_user_readShutterTurnTime(index * 2 + 1) << 8;

        shutter_configure(index, index * 2, index * 2 + 1, maxUpTime, maxDownTime, turnTime);

        /* Disable shutter? */
        if (0 == ((vscp_ps_user_readShutterEnable() >> index) & 0x01))
        {
            shutter_enable(index, FALSE);
        }
        /* Enable shutter */
        else
        {
            shutter_enable(index, TRUE);
        }
    }

    return status;
}

/**
 * This function initializes run level 2.
 * Precondition: Interrupts are enabled
 *
 * @return Status
 */
static MAIN_RET main_initRunLevel2(void)
{
    MAIN_RET    status  = MAIN_RET_OK;
    
    /* Implement your code here ... */

    return status;
}

/**
 * This function is called by the timer ISR every tick!
 */
static void main_timerCb(void)
{
    static volatile uint8_t segmentInitButtonDebounceCnt    = 0;
    static volatile uint8_t shutterCnt                      = 0;

    /* Is the segment initialization button released? */
    if (FALSE == hw_getSegInitButtonState())
    {
        segmentInitButtonDebounceCnt = 0;
        main_isInitButtonPressed = FALSE;
    }
    /* Segment initialization button is pressed.
     * Perform debouncing!
     */
    else if (TIMERDRV_MS(MAIN_SEG_INIT_DEBOUNCE_TIME) <= segmentInitButtonDebounceCnt)
    {
        main_isInitButtonPressed = TRUE;
    }
    else
    {
        ++segmentInitButtonDebounceCnt;
    }

    /* Process all software timer */
    swTimer_process();

    /* Process all shutter timers in a 100 ms cycle period.
     * It is important to do that in the ISR, because the shutter timer are used
     * to determine the shutter position. Every deviation in time is bad.
     * Also the timer is used to drive the shutter a specific time in one direction.
     */
    if (0 < shutterCnt)
    {
        --shutterCnt;
    }
    else
    {
        shutterCnt = MAIN_SHUTTER_TIMER_PERIOD;

        shutter_processTimers();
    }

    return;
}

/**
 * This function process the status lamp.
 */
static void main_processStatusLamp(void)
{
    VSCP_LAMP_STATE state   = vscp_portable_getLampState();

    switch(state)
    {
    case VSCP_LAMP_STATE_OFF:
        HW_DISABLE_STATUS_LED();
        break;

    case VSCP_LAMP_STATE_ON:
        HW_ENABLE_STATUS_LED();
        break;

    case VSCP_LAMP_STATE_BLINK:
        HW_TOGGLE_STATUS_LED();
        break;

    default:
        break;
    }

    return;
}
