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
@brief  VSCP class 1 type Control events
@file   vscp_control.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
Control functionality. One of the main concepts of VSCP is that it is an event driven protocol.
Commands are sent out as events to the network not as events to specific devices. A device can
belong to a zone which select limit events of interest for the particular node.. If there is a need
to control a specific device the registry model should be used. This is the only way to directly
control a device.

This file is automatically generated. Don't change it manually.

@section svn Subversion
$Author: amerkle $
$Rev: 449 $
$Date: 2015-01-05 20:23:52 +0100 (Mo, 05 Jan 2015) $
*******************************************************************************/
/** @defgroup vscp_control Control events abstraction
 * Level 1 control events abstraction
 * @{
 * @ingroup vscp_l1_events_abstraction
 */
 
#ifndef __VSCP_CONTROL_H__
#define __VSCP_CONTROL_H__

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
 * General control.
 * 
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendUndefinedEvent(void);

/**
 * Mute/Un-mute all sound generating nodes in a zone
 * 
 * @param[in] mute If equal to zero no mute else mute.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendMuteOnOffEvent(uint8_t mute, uint8_t zone, uint8_t subZone);

/**
 * Turn on/off lamps on nodes in zone.
 * 
 * @param[in] on If equal to zero off else on.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendLampOnOffEvent(uint8_t on, uint8_t zone, uint8_t subZone);

/**
 * Perform open on all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendOpenEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Perform close on all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendCloseEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Turn On a nodes in a zone/subzone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendTurnOnEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Turn Off a nodes in a zone/subzone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendTurnOffEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Start all nodes in a zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendStartEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Stop all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendStopEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Perform Reset on all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendResetEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Perform Interrupt on all nodes in zone.
 * 
 * @param[in] level Interrupt level. (0 – 255 , zero is lowest interrupt level. ).
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendInterruptEvent(uint8_t level, uint8_t zone, uint8_t subZone);

/**
 * Perform Sleep on all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendSleepEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Wakeup all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendWakeupEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Resume all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendResumeEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Pause all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendPauseEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Activate all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendActivateEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Deactivate all nodes in zone.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendDeactivateEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * Dim all dimmer devices on a segment to a specified dim value.
 * 
 * @param[in] value Value (0 – 100) . 0 = off, 100 = full on. 254 dim down one step. 255 dim up one
 * step.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendDimLampEvent(uint8_t value, uint8_t zone, uint8_t subZone);

/**
 * This is typical for changing TV channels or for changing AV amp input source etc.
 * 
 * @param[in] value A value between 0 and 127 indicates the channel number. A value between 128 to 157
 * is change down by the specified number of channels. A value between 160 to 191 is change up by the
 * specified number of channels. A value of 255 means that this is an extended change channel event
 * and that the channel number is sent in byte 3 and after if needed.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendChangeChannelEvent(uint8_t value, uint8_t zone, uint8_t subZone);

/**
 * Change an absolute level.
 * 
 * @param[in] level Absolute level.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendChangeLevelEvent(uint8_t level, uint8_t zone, uint8_t subZone);

/**
 * 
 * 
 * @param[in] level Relative level.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendRelativeChangeLevelEvent(uint8_t level, uint8_t zone, uint8_t subZone);

/**
 * 
 * 
 * @param[in] index Zero indicates all measurements supported by node should be sent (as separate
 * events). Non-zero indicates a node specific index specifying which measurement to send.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendMeasurementRequestEvent(uint8_t index, uint8_t zone, uint8_t subZone);

/**
 * 
 * 
 * @param[in] sequenceNumber Sequence number which is increase by one for each stream data event sent.
 * @param[in] data Stream data.
 * @param[in] dataSize Size in bytes (1-7)
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendStreamDataEvent(uint8_t sequenceNumber, uint8_t const * const data, uint8_t dataSize);

/**
 * Synchronize events on a segment.
 * 
 * @param[in] index Index for subunits within modules. 255 is all subunits.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendSynchronizeEvent(uint8_t index, uint8_t zone, uint8_t subZone);

/**
 * 
 * 
 * @param[in] sequenceNumber Sequence number which is increase by one for each stream data event sent.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @param[in] data Stream data.
 * @param[in] dataSize Size in bytes (1-5)
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendStreamDataWithZoneEvent(uint8_t sequenceNumber, uint8_t zone, uint8_t subZone, uint8_t const * const data, uint8_t dataSize);

/**
 * Some nodes may have pre-set configurations to choose from. With this event a pre-set can be set for
 * a zone/sub-zone.
 * 
 * A node that receive and act on this event send CLASS1.INFORMATION,
 * 
 * Type=48 as a response event.
 * 
 * @param[in] code Code for pre-set to set.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendSetPresetEvent(uint8_t code, uint8_t zone, uint8_t subZone);

/**
 * Toggle the state of a node.
 * 
 * Note: This may be a bad design option as it often demands that the state should be known for the
 * node on beforehand.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendToggleStateEvent(uint8_t userData, uint8_t zone, uint8_t subZone);

/**
 * With this event it is possible to generate a timed pulse that is on for a specified time.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @param[in] d Control byte.
 * @param[in] e Set time as a long with MSB in the first byte.
 * @param[in] eSize Size in bytes (1-4)
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendTimedPulseOnEvent(uint8_t userData, uint8_t zone, uint8_t subZone, uint8_t d, uint8_t const * const e, uint8_t eSize);

/**
 * With this event it is possible to generate a timed pulse that is off for a specified time.
 * 
 * @param[in] userData Optional byte that have a meaning given by the issuer of the event.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @param[in] control Control byte.
 * @param[in] time Set time as a long with MSB in the first byte.
 * @param[in] timeSize Size in bytes (1-4)
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendTimedPulseOffEvent(uint8_t userData, uint8_t zone, uint8_t subZone, uint8_t control, uint8_t const * const time, uint8_t timeSize);

/**
 * Set country language.
 * 
 * @param[in] countryCode Country/Language code.
 * @param[in] customCodedSystem Custom coded system
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @param[in] countryCodeSpecific Country/Language code specific
 * @param[in] countryCodeSpecificSize Size in bytes (1-5)
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendSetCountryLanguageEvent(uint8_t countryCode, uint8_t customCodedSystem, uint8_t zone, uint8_t subZone, uint8_t const * const countryCodeSpecific, uint8_t countryCodeSpecificSize);

/**
 * Big Change level can be used in situations when the one byte level of CLASS1.CONTROL, Type=22 is
 * not enough.
 * 
 * @param[in] index Index
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @param[in] level Level as signed Integer. The range can be adjusted by the user by sending the
 * needed number of bytes 1-5.
 * @param[in] levelSize Size in bytes (1-5)
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_control_sendBigChangeLevelEvent(uint8_t index, uint8_t zone, uint8_t subZone, int8_t const * const level, uint8_t levelSize);

#endif /* __VSCP_CONTROL_H__ */

/** @} */
