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
@file   vscp_evt_alarm.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
Alarm events that indicate that something not ordinary has occurred. Note that the priority bits
can be used as a mean to level alarm for severity.

This file is automatically generated. Don't change it manually.

*******************************************************************************/

#ifndef __VSCP_EVT_ALARM_H__
#define __VSCP_EVT_ALARM_H__

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include <stdint.h>
#include "vscp_platform.h"

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
    VARIABLES
*******************************************************************************/

/*******************************************************************************
    FUNCTIONS
*******************************************************************************/

/**
 * General event
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendGeneralEvent(void);

/**
 * Warning
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendWarning(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Alarm occurred
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendAlarmOccurred(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Alarm sound on/off
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendAlarmSoundOnOff(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Alarm light on/off
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendAlarmLightOnOff(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Power on/off
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendPowerOnOff(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Emergency Stop
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendEmergencyStop(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Emergency Pause
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendEmergencyPause(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Emergency Reset
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendEmergencyReset(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Emergency Resume
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendEmergencyResume(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Arm
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendArm(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Disarm
 * 
 * @param[in] onOff Alarm is on/off.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendDisarm(uint8_t onOff, uint8_t zone, uint8_t subZone);

/**
 * Watchdog
 * 
 * @param[in] index index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_alarm_sendWatchdog(uint8_t index, uint8_t zone, uint8_t subZone);

#endif  /* __VSCP_EVT_ALARM_H__ */
