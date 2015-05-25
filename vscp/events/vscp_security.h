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
@brief  VSCP class 1 type Security events
@file   vscp_security.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
Security related events for alarms and similar devices.

This file is automatically generated. Don't change it manually.

*******************************************************************************/
/** @defgroup vscp_security Security events abstraction
 * Level 1 security events abstraction
 * @{
 * @ingroup vscp_l1_events_abstraction
 */

#ifndef __VSCP_SECURITY_H__
#define __VSCP_SECURITY_H__

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include <stdint.h>
#include "vscp_types.h"

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
 * Undefined security issue.
 *
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendUndefinedEvent(void);

/**
 * A motion has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendMotionDetectEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A glass break event has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all subzones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendGlassBreakEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A beam break event has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendBeamBreakEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A sensor tamper has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendSensorTamperEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A shock sensor event has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendShockSensorEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A smoke sensor event has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendSmokeSensorEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A heat sensor event has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendHeatSensorEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A panic switch event has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendPanicSwitchEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Indicates a door sensor reports that a door is open.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendDoorContactEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Indicates a window sensor reports that a window is open.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendWindowContactEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * CO sensor has detected CO at non secure level
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendCoSensorEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * A frost sensor condition is detected
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendFrostDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Flame is detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendFlameDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Low oxygen level detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendOxygenLowEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Weight-detector triggered.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendWeightDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Water has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendWaterDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Condensation (humidity) detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendCondensationDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Noise (sound) has been detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendNoiseDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Harmful sound levels detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendHarmfulSoundLevelsDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Tamper detected.
 *
 * @param[in] userData User defined data.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_security_sendTamperDetectedEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

#endif /* __VSCP_SECURITY_H__ */

/** @} */
