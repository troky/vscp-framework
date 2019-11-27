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
@brief  Security
@file   vscp_evt_security.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
Security related events for alarms and similar devices.

This file is automatically generated. Don't change it manually.

*******************************************************************************/

#ifndef __VSCP_EVT_SECURITY_H__
#define __VSCP_EVT_SECURITY_H__

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
extern BOOL vscp_evt_security_sendGeneralEvent(void);

/**
 * Motion Detect
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendMotionDetect(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Glass break
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendGlassBreak(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Beam break
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendBeamBreak(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Sensor tamper
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendSensorTamper(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Shock sensor
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendShockSensor(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Smoke sensor
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendSmokeSensor(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Heat sensor
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendHeatSensor(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Panic switch
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendPanicSwitch(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Door Contact
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendDoorContact(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Window Contact
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendWindowContact(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * CO Sensor
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendCoSensor(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Frost detected
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendFrostDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Flame detected
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendFlameDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Oxygen Low
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendOxygenLow(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Weight detected.
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendWeightDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Water detected.
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendWaterDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Condensation detected.
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendCondensationDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Noise (sound) detected.
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendNoiseSoundDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Harmful sound levels detected.
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendHarmfulSoundLevelsDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Tamper detected.
 * 
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendTamperDetected(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Authenticated
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendAuthenticated(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Unauthenticated
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendUnauthenticated(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Authorized
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendAuthorized(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Unauthorized
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendUnauthorized(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * ID check
 * 
 * @param[in] data0 ID check bits.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendIdCheck(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Valid pin
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendValidPin(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Invalid pin
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendInvalidPin(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Pin warning
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendPinWarning(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Pin error
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendPinError(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Valid password
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendValidPassword(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Invalid password
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendInvalidPassword(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Password warning
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendPasswordWarning(uint8_t data0, uint8_t zone, uint8_t subZone);

/**
 * Password error
 * 
 * @param[in] data0 User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_security_sendPasswordError(uint8_t data0, uint8_t zone, uint8_t subZone);

#endif  /* __VSCP_EVT_SECURITY_H__ */