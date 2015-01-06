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
@brief  VSCP portable support package
@file   vscp_portable.c
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
@see vscp_portable.h

@section svn Subversion
$Author: amerkle $
$Rev: 449 $
$Date: 2015-01-05 20:23:52 +0100 (Mo, 05 Jan 2015) $
*******************************************************************************/

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "platform.h"
#include "vscp_portable.h"
#include "vscp_core.h"
#include "vscp_dm.h"
#include "vscp_dm_ng.h"
#include "vscp_ps.h"
#include "vscp_class_l1.h"
#include "vscp_type_information.h"
#include <stdio.h>
#include "eeprom.h"
#include "log.h"

/*******************************************************************************
    COMPILER SWITCHES
*******************************************************************************/

/*******************************************************************************
    CONSTANTS
*******************************************************************************/

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

#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION )

/** Decision matrix next generation rule set */
static uint8_t	vscp_portable_ruleSet[] =
{
    /* Number of rules */
    0x02,

    /* Rule 1: Execute action if node id is 4 or 5. */
    0x09, 0x01, 0x00,
        /* Condition 1 */
        VSCP_DM_NG_LOGIC_OP_OR   | VSCP_DM_NG_BASIC_OP_EQUAL, VSCP_DM_NG_EVENT_PAR_ID_OADDR, 0x04,
        /* Condition 2 */
        VSCP_DM_NG_LOGIC_OP_LAST | VSCP_DM_NG_BASIC_OP_EQUAL, VSCP_DM_NG_EVENT_PAR_ID_OADDR, 0x05,

    /* Rule 2: Execute action if class is information. */
    0x07, 0x02, 0x00,
        /* Condition 1 */
        VSCP_DM_NG_LOGIC_OP_LAST | VSCP_DM_NG_BASIC_OP_EQUAL, VSCP_DM_NG_EVENT_PAR_ID_CLASS, 0x00, 0x14
};

#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION ) */

/*******************************************************************************
    GLOBAL VARIABLES
*******************************************************************************/

/*******************************************************************************
    GLOBAL FUNCTIONS
*******************************************************************************/

/**
 * This function initializes this module.
 */
extern void vscp_portable_init(void)
{
    /* Implement your code here ... */
    
    return;
}

/**
 * Restore the application specific factory default settings.
 */
extern void vscp_portable_restoreFactoryDefaultSettings(void)
{
#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM ) || VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION )

    uint8_t             index   = 0;
    uint8_t*            ps      = eeprom_getBase(NULL);
    
#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM ) || VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION ) */
    
#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION )

    uint8_t*            dmNG    = NULL;

#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION ) */
    
#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM )
    
    vscp_dm_MatrixRow*  dm      = NULL;
    
#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_EXTENSION )
    
    vscp_dm_ExtRow*     dmExt   = NULL;
    
#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_EXTENSION ) */
        
    if (NULL == ps)
    {
        LOG_ERROR("Couldn't get EEPROM base address.");
        return;
    }

    printf("Restore application factory default settings.\n");
    
    dm = (vscp_dm_MatrixRow*)&ps[VSCP_PS_ADDR_DM];
       
    /* Set up a simple decision matrix configuration */
    for(index = 0; index < VSCP_CONFIG_DM_ROWS; ++index)
    {
        dm[index].flags         = VSCP_DM_FLAG_ENABLE | VSCP_DM_FLAG_CHECK_OADDR;
        dm[index].classMask     = VSCP_CLASS_L1_INFORMATION;
        dm[index].classFilter   = VSCP_CLASS_L1_INFORMATION;
        dm[index].typeMask      = VSCP_TYPE_INFORMATION_BUTTON;
        dm[index].typeFilter    = VSCP_TYPE_INFORMATION_BUTTON;
        dm[index].oaddr         = index + 2;
        dm[index].action        = index;
    }

#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_EXTENSION )

    dmExt = (vscp_dm_ExtRow*)&ps[VSCP_PS_ADDR_DM_EXTENSION];
    
    /* Set up a simple decision matrix configuration */
    for(index = 0; index < VSCP_CONFIG_DM_ROWS; ++index)
    {
        dm[index].flags     = VSCP_DM_FLAG_ENABLE;
        dm[index].oaddr     = 0;
        dm[index].action    = VSCP_DM_ACTION_EXTENDED_DM;
        dm[index].actionPar = VSCP_DM_EXTFLAG_MATCH_PAR_0;
        
        dmExt[index].par0   = index;
        dmExt[index].action = index;
    }
    
#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_EXTENSION ) */
    
#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM ) */
    
#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION )
    
    dmNG = &ps[VSCP_PS_ADDR_DM_NEXT_GENERATION];
    
    for(index = 0; index < sizeof(vscp_portable_ruleSet); ++index)
    {
        dmNG[index] = vscp_portable_ruleSet[index];
    }
    
#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ENABLE_DM_NEXT_GENERATION ) */
    
    return;
}

/**
 * This function set the current lamp state.
 *
 * @param[in]   state   Lamp state to set
 */
extern void vscp_portable_setLampState(VSCP_LAMP_STATE state)
{
    static VSCP_LAMP_STATE  currentState    = VSCP_LAMP_STATE_OFF;

    if (state != currentState)
    {
        switch(state)
        {
        case VSCP_LAMP_STATE_OFF:
            platform_setTextColor(PLATFORM_COLOR_YELLOW);
            log_printf("Lamp off\n");
            platform_setTextColor(PLATFORM_COLOR_GREY);
            break;

        case VSCP_LAMP_STATE_ON:
            platform_setTextColor(PLATFORM_COLOR_LIGHT_YELLOW);
            log_printf("Lamp on\n");
            platform_setTextColor(PLATFORM_COLOR_GREY);
            break;

        case VSCP_LAMP_STATE_BLINK:
            platform_setTextColor(PLATFORM_COLOR_LIGHT_YELLOW);
            log_printf("Lamp blinking\n");
            platform_setTextColor(PLATFORM_COLOR_GREY);
            break;

        default:
            break;
        }

        currentState = state;
    }

    return;
}

#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_IDLE_CALLOUT )

/**
 * If VSCP stops its work and enters idle state, this function will be called.
 */
extern void vscp_portable_idleStateEntered(void)
{
    log_printf("Entered IDLE state.\n");

    return;
}

#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_IDLE_CALLOUT ) */

#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ERROR_CALLOUT )

/**
 * If VSCP stops its work and enters error state, this function will be called.
 */
extern void vscp_portable_errorStateEntered(void)
{
    log_printf("Entered ERROR state.\n");
    
    return;
}

#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_ERROR_CALLOUT ) */

/**
 * This function requests a reset.
 * It requests it and doesn't expect that it will be immediately.
 * Because the application needs time to change to a safe state before.
 */
extern void vscp_portable_resetRequest(void)
{
    log_printf("Reset request.\n");

    return;
}

#if VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_BOOT_LOADER_SUPPORTED )

/**
 * This function returns the supported boot loader algorithm.
 *
 * @return  Boot loader algorithm
 * @retval  0xFF    No boot loader supported
 */
extern uint8_t  vscp_portable_getBootLoaderAlgorithm(void)
{
    uint8_t algorithm   = 0xFF;

    /* Implement your code here ... */

    return algorithm;
}

/**
 * This function requests a jump to the bootloader.
 * It requests it and doesn't expect that it will be immediately.
 * Because the application needs time to change to a safe state before.
 */
extern void vscp_portable_bootLoaderRequest(void)
{
    /* Implement your code here ... */

    return;
}

#endif  /* VSCP_CONFIG_BASE_IS_ENABLED( VSCP_CONFIG_BOOT_LOADER_SUPPORTED ) */

/**
 * This function provides received VSCP events, except the PROTOCOL class.
 *
 * @param[out]  msg Message
 */
extern void vscp_portable_provideEvent(vscp_RxMessage const * const msg)
{
    /* Implement your code here ... */
    
    return;
}

/*******************************************************************************
    LOCAL FUNCTIONS
*******************************************************************************/

