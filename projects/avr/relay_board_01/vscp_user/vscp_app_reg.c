/* The MIT License (MIT)
 *
 * Copyright (c) 2014 - 2020, Andreas Merkle
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
@brief  VSCP application registers
@file   vscp_app_reg.c
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
@see vscp_app_reg.h

This file is automatically generated. Don't change it manually.

*******************************************************************************/

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "vscp_app_reg.h"
#include "vscp_types.h"
#include "vscp_ps_user.h"
#include "buttonObserver.h"
#include "windDrv.h"
#include "vscp_transport.h"

/*******************************************************************************
    COMPILER SWITCHES
*******************************************************************************/

/*******************************************************************************
    CONSTANTS
*******************************************************************************/

/**
 * Application register offset of page 0 of button enable.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_ENABLE    0

/**
 * Application register offset of page 0 of wind enable.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_WIND_ENABLE  1

/**
 * Application register offset of page 0 of relay enable.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_RELAY_ENABLE 2

/**
 * Application register offset of page 0 of shutter enable.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_ENABLE   3

/**
 * Application register offset of page 0 of relay event config.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_CONFIG   4

/**
 * Application register offset of page 0 of shutter event config.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_CONFIG 5

/**
 * Application register offset of page 0 of relay switching duty cycle.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE   6

/**
 * Application register offset of page 0 of relay holding duty cycle.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE 8

/**
 * Application register offset of page 0 of node zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_NODE_ZONE    10

/**
 * Application register offset of page 0 of node sub zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_NODE_SUB_ZONE    11

/**
 * Application register offset of page 0 of button event zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE    12

/**
 * Application register offset of page 0 of button event sub zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE    20

/**
 * Application register offset of page 0 of relay event zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE 28

/**
 * Application register offset of page 0 of relay event sub zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE 36

/**
 * Application register offset of page 0 of shutter event zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE   44

/**
 * Application register offset of page 0 of shutter event sub zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE   48

/**
 * Application register offset of page 0 of wind event zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_WIND_EVENT_ZONE  52

/**
 * Application register offset of page 0 of wind event sub zone.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_WIND_EVENT_SUB_ZONE  53

/**
 * Application register offset of page 0 of wind speed medium.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_MEDIUM    54

/**
 * Application register offset of page 0 of wind speed high.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_HIGH  55

/**
 * Application register offset of page 0 of wind speed very high.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_VERY_HIGH 56

/**
 * Application register offset of page 0 of shutter max up time.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME  57

/**
 * Application register offset of page 0 of shutter max down time.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME    65

/**
 * Application register offset of page 0 of shutter turn time.
 */
#define VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME    73

/**
 * Application register offset of page 4 of log id.
 */
#define VSCP_APP_REG_PAGE_4_OFFSET_LOG_ID   0

/**
 * Application register offset of page 4 of tp errors.
 */
#define VSCP_APP_REG_PAGE_4_OFFSET_TP_ERRORS    1

/*******************************************************************************
    MACROS
*******************************************************************************/

/*******************************************************************************
    TYPES AND STRUCTURES
*******************************************************************************/

/*******************************************************************************
    PROTOTYPES
*******************************************************************************/

/*******************************************************************************
    LOCAL VARIABLES
*******************************************************************************/

/*******************************************************************************
    GLOBAL VARIABLES
*******************************************************************************/

/*******************************************************************************
    GLOBAL FUNCTIONS
*******************************************************************************/

/**
 * This function initializes this module.
 */
extern void vscp_app_reg_init(void)
{
    /* Initialize user specific persistent storage */
    vscp_ps_user_init();

    return;
}

/**
 * Restore the application specific factory default settings.
 */
extern void vscp_app_reg_restoreFactoryDefaultSettings(void)
{
    uint8_t index = 0;

    vscp_ps_user_writeButtonEnable(0);

    vscp_ps_user_writeWindEnable(0);

    vscp_ps_user_writeRelayEnable(0);

    vscp_ps_user_writeShutterEnable(0);

    vscp_ps_user_writeRelayEventConfig(0);

    vscp_ps_user_writeShutterEventConfig(0);

    for(index = 0; index < 1; ++index)
    {
        vscp_ps_user_writeRelaySwitchingDutyCycle(index * 2 + 0, (((uint16_t)400) >> 0) & 0xff);
        vscp_ps_user_writeRelaySwitchingDutyCycle(index * 2 + 1, (((uint16_t)400) >> 8) & 0xff);
    }

    for(index = 0; index < 1; ++index)
    {
        vscp_ps_user_writeRelayHoldingDutyCycle(index * 2 + 0, (((uint16_t)240) >> 0) & 0xff);
        vscp_ps_user_writeRelayHoldingDutyCycle(index * 2 + 1, (((uint16_t)240) >> 8) & 0xff);
    }

    for(index = 0; index < VSCP_PS_USER_SIZE_BUTTON_EVENT_ZONE; ++index)
    {
        vscp_ps_user_writeButtonEventZone(index, 255);
    }

    for(index = 0; index < VSCP_PS_USER_SIZE_BUTTON_EVENT_SUB_ZONE; ++index)
    {
        vscp_ps_user_writeButtonEventSubZone(index, 255);
    }

    for(index = 0; index < VSCP_PS_USER_SIZE_RELAY_EVENT_ZONE; ++index)
    {
        vscp_ps_user_writeRelayEventZone(index, 255);
    }

    for(index = 0; index < VSCP_PS_USER_SIZE_RELAY_EVENT_SUB_ZONE; ++index)
    {
        vscp_ps_user_writeRelayEventSubZone(index, 255);
    }

    for(index = 0; index < VSCP_PS_USER_SIZE_SHUTTER_EVENT_ZONE; ++index)
    {
        vscp_ps_user_writeShutterEventZone(index, 255);
    }

    for(index = 0; index < VSCP_PS_USER_SIZE_SHUTTER_EVENT_SUB_ZONE; ++index)
    {
        vscp_ps_user_writeShutterEventSubZone(index, 255);
    }

    vscp_ps_user_writeWindEventZone(255);

    vscp_ps_user_writeWindEventSubZone(255);

    vscp_ps_user_writeWindSpeedMedium(40);

    vscp_ps_user_writeWindSpeedHigh(80);

    vscp_ps_user_writeWindSpeedVeryHigh(160);

    for(index = 0; index < 4; ++index)
    {
        vscp_ps_user_writeShutterMaxUpTime(index * 2 + 0, (((uint16_t)270) >> 0) & 0xff);
        vscp_ps_user_writeShutterMaxUpTime(index * 2 + 1, (((uint16_t)270) >> 8) & 0xff);
    }

    for(index = 0; index < 4; ++index)
    {
        vscp_ps_user_writeShutterMaxDownTime(index * 2 + 0, (((uint16_t)260) >> 0) & 0xff);
        vscp_ps_user_writeShutterMaxDownTime(index * 2 + 1, (((uint16_t)260) >> 8) & 0xff);
    }

    for(index = 0; index < 4; ++index)
    {
        vscp_ps_user_writeShutterTurnTime(index * 2 + 0, (((uint16_t)0) >> 0) & 0xff);
        vscp_ps_user_writeShutterTurnTime(index * 2 + 1, (((uint16_t)0) >> 8) & 0xff);
    }

    return;
}

/**
 * This function returns the number of used pages.
 * Its used in the register abstraction model.
 * Deprecated since VSCP spec. v1.10.2
 *
 * @return Pages used
 * @retval 0    More than 255 pages are used.
 */
extern uint8_t vscp_app_reg_getPagesUsed(void)
{
    uint8_t pagesUsed = 1;  /* At least one page, which is mandatory. */

    /* DM is at page 1
     * DM NG is at page 2
     * Debugging stuff is at page 3
     */
    pagesUsed += 3;

    return pagesUsed;
}

/**
 * This function reads a application specific register and returns the value.
 *
 * @param[in]   page    Page
 * @param[in]   addr    Register address@return Register value
 */
extern uint8_t vscp_app_reg_readRegister(uint16_t page, uint8_t addr)
{
    uint8_t value = 0;

    if (0 == page)
    {
        if ((VSCP_REGISTER_APP_START_ADDR <= addr) &&
            (VSCP_REGISTER_APP_END_ADDR >= addr))
        {
            if (VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_ENABLE == addr)
            {
                value = vscp_ps_user_readButtonEnable();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_ENABLE == addr)
            {
                value = vscp_ps_user_readWindEnable();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_RELAY_ENABLE == addr)
            {
                value = vscp_ps_user_readRelayEnable();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_ENABLE == addr)
            {
                value = vscp_ps_user_readShutterEnable();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_CONFIG == addr)
            {
                value = vscp_ps_user_readRelayEventConfig();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_CONFIG == addr)
            {
                value = vscp_ps_user_readShutterEventConfig();
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE + 2) > addr))
            {
                value = vscp_ps_user_readRelaySwitchingDutyCycle((VSCP_PS_USER_SIZE_RELAY_SWITCHING_DUTY_CYCLE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE + 2) > addr))
            {
                value = vscp_ps_user_readRelayHoldingDutyCycle((VSCP_PS_USER_SIZE_RELAY_HOLDING_DUTY_CYCLE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE)) - 1);
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_NODE_ZONE == addr)
            {
                value = vscp_ps_readNodeZone();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_NODE_SUB_ZONE == addr)
            {
                value = vscp_ps_readNodeSubZone();
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE + 8) > addr))
            {
                value = vscp_ps_user_readButtonEventZone((VSCP_PS_USER_SIZE_BUTTON_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE + 8) > addr))
            {
                value = vscp_ps_user_readButtonEventSubZone((VSCP_PS_USER_SIZE_BUTTON_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE + 8) > addr))
            {
                value = vscp_ps_user_readRelayEventZone((VSCP_PS_USER_SIZE_RELAY_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE + 8) > addr))
            {
                value = vscp_ps_user_readRelayEventSubZone((VSCP_PS_USER_SIZE_RELAY_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE + 4) > addr))
            {
                value = vscp_ps_user_readShutterEventZone((VSCP_PS_USER_SIZE_SHUTTER_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE + 4) > addr))
            {
                value = vscp_ps_user_readShutterEventSubZone((VSCP_PS_USER_SIZE_SHUTTER_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE)) - 1);
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_EVENT_ZONE == addr)
            {
                value = vscp_ps_user_readWindEventZone();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_EVENT_SUB_ZONE == addr)
            {
                value = vscp_ps_user_readWindEventSubZone();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_MEDIUM == addr)
            {
                value = vscp_ps_user_readWindSpeedMedium();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_HIGH == addr)
            {
                value = vscp_ps_user_readWindSpeedHigh();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_VERY_HIGH == addr)
            {
                value = vscp_ps_user_readWindSpeedVeryHigh();
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME + 8) > addr))
            {
                value = vscp_ps_user_readShutterMaxUpTime((VSCP_PS_USER_SIZE_SHUTTER_MAX_UP_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME + 8) > addr))
            {
                value = vscp_ps_user_readShutterMaxDownTime((VSCP_PS_USER_SIZE_SHUTTER_MAX_DOWN_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME + 8) > addr))
            {
                value = vscp_ps_user_readShutterTurnTime((VSCP_PS_USER_SIZE_SHUTTER_TURN_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME)) - 1);
            }
        }
    }
    else if (4 == page)
    {
        if (VSCP_APP_REG_PAGE_4_OFFSET_LOG_ID == addr)
        {
            value = vscp_ps_readLogId();
        }
        else if (VSCP_APP_REG_PAGE_4_OFFSET_TP_ERRORS == addr)
        {
            value = vscp_transport_getTransmitErrors();
        }
    }

    return value;
}

/**
 * This function writes a value to an application specific register.
 *
 * @param[in]   page    Page
 * @param[in]   addr    Register address@param[in]  value   Value to write@return Register value
 */
extern uint8_t vscp_app_reg_writeRegister(uint16_t page, uint8_t addr, uint8_t value)
{
    uint8_t readBackValue = 0;

    if (0 == page)
    {
        if ((VSCP_REGISTER_APP_START_ADDR <= addr) &&
            (VSCP_REGISTER_APP_END_ADDR >= addr))
        {
            if (VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_ENABLE == addr)
            {
                /* If the wind measurement is enabled, disable the button which uses the same pin. */
                if (1 == vscp_ps_user_readWindEnable())
                {
                    /* Disable observation of button */
                    BIT_CLR(value, WINDDRV_BUTTON_INDEX);
                }

                vscp_ps_user_writeButtonEnable(value);
                readBackValue = vscp_ps_user_readButtonEnable();

                /* Set button observation filter to apply changes now. */
                buttonObserver_setFilter(readBackValue);
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_ENABLE == addr)
            {
                value &= 0x01;
                vscp_ps_user_writeWindEnable(value);
                readBackValue = vscp_ps_user_readWindEnable();

                /* Apply changes now to the wind measurement */
                if (0 == readBackValue)
                {
                    windDrv_enable(FALSE);
                }
                else
                {
                    uint8_t buttonEnableMask    = vscp_ps_user_readButtonEnable();

                    /* If the wind measurement is enabled, disable the button which uses the same pin. */
                    if (TRUE == IS_BIT_SET(buttonEnableMask, WINDDRV_BUTTON_INDEX))
                    {
                        /* Disable observation of button */
                        BIT_CLR(buttonEnableMask, WINDDRV_BUTTON_INDEX);
                        vscp_ps_user_writeButtonEnable(buttonEnableMask);
                        buttonObserver_setFilter(buttonEnableMask);
                    }

                    windDrv_enable(TRUE);
                }
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_RELAY_ENABLE == addr)
            {
                vscp_ps_user_writeRelayEnable(value);
                readBackValue = vscp_ps_user_readRelayEnable();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_ENABLE == addr)
            {
                value &= 0x0f;
                vscp_ps_user_writeShutterEnable(value);
                readBackValue = vscp_ps_user_readShutterEnable();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_CONFIG == addr)
            {
                vscp_ps_user_writeRelayEventConfig(value);
                readBackValue = vscp_ps_user_readRelayEventConfig();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_CONFIG == addr)
            {
                value &= 0x0f;
                vscp_ps_user_writeShutterEventConfig(value);
                readBackValue = vscp_ps_user_readShutterEventConfig();
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE + 2) > addr))
            {
                vscp_ps_user_writeRelaySwitchingDutyCycle((VSCP_PS_USER_SIZE_RELAY_SWITCHING_DUTY_CYCLE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE)) - 1, value);
                readBackValue = vscp_ps_user_readRelaySwitchingDutyCycle((VSCP_PS_USER_SIZE_RELAY_SWITCHING_DUTY_CYCLE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_SWITCHING_DUTY_CYCLE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE + 2) > addr))
            {
                vscp_ps_user_writeRelayHoldingDutyCycle((VSCP_PS_USER_SIZE_RELAY_HOLDING_DUTY_CYCLE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE)) - 1, value);
                readBackValue = vscp_ps_user_readRelayHoldingDutyCycle((VSCP_PS_USER_SIZE_RELAY_HOLDING_DUTY_CYCLE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_HOLDING_DUTY_CYCLE)) - 1);
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_NODE_ZONE == addr)
            {
                vscp_ps_writeNodeZone(value);
                readBackValue = vscp_ps_readNodeZone();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_NODE_SUB_ZONE == addr)
            {
                vscp_ps_writeNodeSubZone(value);
                readBackValue = vscp_ps_readNodeSubZone();
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE + 8) > addr))
            {
                vscp_ps_user_writeButtonEventZone((VSCP_PS_USER_SIZE_BUTTON_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE)) - 1, value);
                readBackValue = vscp_ps_user_readButtonEventZone((VSCP_PS_USER_SIZE_BUTTON_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE + 8) > addr))
            {
                vscp_ps_user_writeButtonEventSubZone((VSCP_PS_USER_SIZE_BUTTON_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE)) - 1, value);
                readBackValue = vscp_ps_user_readButtonEventSubZone((VSCP_PS_USER_SIZE_BUTTON_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_BUTTON_EVENT_SUB_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE + 8) > addr))
            {
                vscp_ps_user_writeRelayEventZone((VSCP_PS_USER_SIZE_RELAY_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE)) - 1, value);
                readBackValue = vscp_ps_user_readRelayEventZone((VSCP_PS_USER_SIZE_RELAY_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE + 8) > addr))
            {
                vscp_ps_user_writeRelayEventSubZone((VSCP_PS_USER_SIZE_RELAY_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE)) - 1, value);
                readBackValue = vscp_ps_user_readRelayEventSubZone((VSCP_PS_USER_SIZE_RELAY_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_RELAY_EVENT_SUB_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE + 4) > addr))
            {
                vscp_ps_user_writeShutterEventZone((VSCP_PS_USER_SIZE_SHUTTER_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE)) - 1, value);
                readBackValue = vscp_ps_user_readShutterEventZone((VSCP_PS_USER_SIZE_SHUTTER_EVENT_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_ZONE)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE + 4) > addr))
            {
                vscp_ps_user_writeShutterEventSubZone((VSCP_PS_USER_SIZE_SHUTTER_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE)) - 1, value);
                readBackValue = vscp_ps_user_readShutterEventSubZone((VSCP_PS_USER_SIZE_SHUTTER_EVENT_SUB_ZONE - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_EVENT_SUB_ZONE)) - 1);
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_EVENT_ZONE == addr)
            {
                vscp_ps_user_writeWindEventZone(value);
                readBackValue = vscp_ps_user_readWindEventZone();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_EVENT_SUB_ZONE == addr)
            {
                vscp_ps_user_writeWindEventSubZone(value);
                readBackValue = vscp_ps_user_readWindEventSubZone();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_MEDIUM == addr)
            {
                vscp_ps_user_writeWindSpeedMedium(value);
                readBackValue = vscp_ps_user_readWindSpeedMedium();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_HIGH == addr)
            {
                vscp_ps_user_writeWindSpeedHigh(value);
                readBackValue = vscp_ps_user_readWindSpeedHigh();
            }
            else if (VSCP_APP_REG_PAGE_0_OFFSET_WIND_SPEED_VERY_HIGH == addr)
            {
                vscp_ps_user_writeWindSpeedVeryHigh(value);
                readBackValue = vscp_ps_user_readWindSpeedVeryHigh();
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME + 8) > addr))
            {
                vscp_ps_user_writeShutterMaxUpTime((VSCP_PS_USER_SIZE_SHUTTER_MAX_UP_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME)) - 1, value);
                readBackValue = vscp_ps_user_readShutterMaxUpTime((VSCP_PS_USER_SIZE_SHUTTER_MAX_UP_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_UP_TIME)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME + 8) > addr))
            {
                vscp_ps_user_writeShutterMaxDownTime((VSCP_PS_USER_SIZE_SHUTTER_MAX_DOWN_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME)) - 1, value);
                readBackValue = vscp_ps_user_readShutterMaxDownTime((VSCP_PS_USER_SIZE_SHUTTER_MAX_DOWN_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_MAX_DOWN_TIME)) - 1);
            }
            else if ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME <= addr) &&
                     ((VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME + 8) > addr))
            {
                vscp_ps_user_writeShutterTurnTime((VSCP_PS_USER_SIZE_SHUTTER_TURN_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME)) - 1, value);
                readBackValue = vscp_ps_user_readShutterTurnTime((VSCP_PS_USER_SIZE_SHUTTER_TURN_TIME - (addr - VSCP_APP_REG_PAGE_0_OFFSET_SHUTTER_TURN_TIME)) - 1);
            }
        }
    }
    else if (4 == page)
    {
        if (VSCP_APP_REG_PAGE_4_OFFSET_LOG_ID == addr)
        {
            vscp_ps_writeLogId(value);
            readBackValue = vscp_ps_readLogId();
        }
    }

    return readBackValue;
}

/*******************************************************************************
    LOCAL FUNCTIONS
*******************************************************************************/

