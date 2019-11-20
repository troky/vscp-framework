/* The MIT License (MIT)
 *
 * Copyright (c) 2014 - 2019, Andreas Merkle
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
@brief  Alarm functionality
@file   vscp_type_alarm.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
Alarm events that indicate that something not ordinary has occurred. Note that the priority bits
can be used as a mean to level alarm for severity.

This file is automatically generated. Don't change it manually.

*******************************************************************************/

#ifndef __VSCP_TYPE_ALARM_H__
#define __VSCP_TYPE_ALARM_H__

/** @defgroup vscp_type_alarm Alarm functionality
 * Level 1 protocol class types
 * @{
 * @ingroup vscp_l1
 */

/*******************************************************************************
    INCLUDES
*******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
    COMPILER SWITCHES
*******************************************************************************/

/*******************************************************************************
    CONSTANTS
*******************************************************************************/

/**
 * General Event.
 */
#define VSCP_TYPE_ALARM_GENERAL          0

/**
 * Indicates a warning condition.
 */
#define VSCP_TYPE_ALARM_WARNING          1

/**
 * Indicates an alarm condition.
 */
#define VSCP_TYPE_ALARM_ALARM            2

/**
 * Alarm sound should be turned on or off.
 */
#define VSCP_TYPE_ALARM_SOUND            3

/**
 * Alarm light should be turned on or off.
 */
#define VSCP_TYPE_ALARM_LIGHT            4

/**
 * Power has been lost or is available again.
 */
#define VSCP_TYPE_ALARM_POWER            5

/**
 * Emergency stop has been hit/activated. All systems on the zone/sub-zone should go to their
 * inactive/safe state.
 */
#define VSCP_TYPE_ALARM_EMERGENCY_STOP   6

/**
 * Emergency pause has been hit/activated. All systems on the zone/sub-zone should go to their
 * inactive/safe state but preserve there settings.
 */
#define VSCP_TYPE_ALARM_EMERGENCY_PAUSE  7

/**
 * Issued after an emergency stop or pause in order for nodes to reset and start operating .
 */
#define VSCP_TYPE_ALARM_EMERGENCY_RESET  8

/**
 * Issued after an emergency pause in order for nodes to start operating from where they left of
 * without resetting their registers .
 */
#define VSCP_TYPE_ALARM_EMERGENCY_RESUME 9

/**
 * Issued after an alarm system has been armed.
 */
#define VSCP_TYPE_ALARM_ARM              10

/**
 * Issued after an alarm system has been disarmed.
 */
#define VSCP_TYPE_ALARM_DISARM           11

/**
 * Issued when a watchdog has been triggered.
 */
#define VSCP_TYPE_ALARM_WATCHDOG         12

/*******************************************************************************
    MACROS
*******************************************************************************/

/*******************************************************************************
    TYPES AND STRUCTURES
*******************************************************************************/

/*******************************************************************************
    VARIABLES
*******************************************************************************/

/*******************************************************************************
    FUNCTIONS
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif  /* __VSCP_TYPE_ALARM_H__ */

/** @} */
