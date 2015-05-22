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
@file   vscp_control.c
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
@see vscp_control.h

This file is automatically generated. Don't change it manually.

*******************************************************************************/

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "vscp_control.h"
#include "vscp_core.h"
#include "vscp_class_l1.h"
#include "vscp_type_control.h"

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

/*******************************************************************************
    GLOBAL VARIABLES
*******************************************************************************/

/*******************************************************************************
    GLOBAL FUNCTIONS
*******************************************************************************/

/**
 * General control.
 *
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_control_sendUndefinedEvent(void)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_UNDEFINED, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendMuteOnOffEvent(uint8_t mute, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MUTE_ON_OFF, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = mute;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendLampOnOffEvent(uint8_t on, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_LAMP_ON_OFF, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = on;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendOpenEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_OPEN, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendCloseEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_CLOSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendTurnOnEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_TURN_ON, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendTurnOffEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_TURN_OFF, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendStartEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_START, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendStopEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_STOP, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendResetEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_RESET, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendInterruptEvent(uint8_t level, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_INTERRUPT, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = level;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendSleepEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_SLEEP, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendWakeupEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_WAKEUP, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendResumeEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_RESUME, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendPauseEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_PAUSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendActivateEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_ACTIVATE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendDeactivateEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_DEACTIVATE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendDimLampEvent(uint8_t value, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_DIM_LAMP, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = value;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendChangeChannelEvent(uint8_t value, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_CHANGE_CHANNEL, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = value;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendChangeLevelEvent(uint8_t level, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_CHANGE_LEVEL, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = level;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendRelativeChangeLevelEvent(uint8_t level, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_RELATIVE_CHANGE_LEVEL, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = level;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendMeasurementRequestEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MEASUREMENT_REQUEST, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendStreamDataEvent(uint8_t sequenceNumber, uint8_t const * const data, uint8_t dataSize)
{
    uint8_t byteIndex = 0;
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_STREAM_DATA, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 1;
    txMsg.data[0] = sequenceNumber;

    for(byteIndex = 0; byteIndex < dataSize; ++byteIndex)
    {
        txMsg.data[1 + byteIndex] = data[byteIndex];
        ++txMsg.dataNum;

        if (VSCP_L1_DATA_SIZE <= txMsg.dataNum)
        {
            break;
        }
    }

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendSynchronizeEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_SYNCHRONIZE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendStreamDataWithZoneEvent(uint8_t sequenceNumber, uint8_t zone, uint8_t subZone, uint8_t const * const data, uint8_t dataSize)
{
    uint8_t byteIndex = 0;
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_STREAM_DATA_WITH_ZONE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = sequenceNumber;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    for(byteIndex = 0; byteIndex < dataSize; ++byteIndex)
    {
        txMsg.data[3 + byteIndex] = data[byteIndex];
        ++txMsg.dataNum;

        if (VSCP_L1_DATA_SIZE <= txMsg.dataNum)
        {
            break;
        }
    }

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendSetPresetEvent(uint8_t code, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_SET_PRESET, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = code;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendToggleStateEvent(uint8_t userData, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_TOGGLE_STATE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendTimedPulseOnEvent(uint8_t userData, uint8_t zone, uint8_t subZone, uint8_t d, uint8_t const * const e, uint8_t eSize)
{
    uint8_t byteIndex = 0;
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_TIMED_PULSE_ON, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 4;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;
    txMsg.data[3] = d;

    for(byteIndex = 0; byteIndex < eSize; ++byteIndex)
    {
        txMsg.data[4 + byteIndex] = e[byteIndex];
        ++txMsg.dataNum;

        if (VSCP_L1_DATA_SIZE <= txMsg.dataNum)
        {
            break;
        }
    }

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendTimedPulseOffEvent(uint8_t userData, uint8_t zone, uint8_t subZone, uint8_t control, uint8_t const * const time, uint8_t timeSize)
{
    uint8_t byteIndex = 0;
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_TIMED_PULSE_OFF, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 4;
    txMsg.data[0] = userData;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;
    txMsg.data[3] = control;

    for(byteIndex = 0; byteIndex < timeSize; ++byteIndex)
    {
        txMsg.data[4 + byteIndex] = time[byteIndex];
        ++txMsg.dataNum;

        if (VSCP_L1_DATA_SIZE <= txMsg.dataNum)
        {
            break;
        }
    }

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendSetCountryLanguageEvent(uint8_t countryCode, uint8_t customCodedSystem, uint8_t zone, uint8_t subZone, uint8_t const * const countryCodeSpecific, uint8_t countryCodeSpecificSize)
{
    uint8_t byteIndex = 0;
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_SET_COUNTRY_LANGUAGE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 4;
    txMsg.data[0] = countryCode;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    for(byteIndex = 0; byteIndex < countryCodeSpecificSize; ++byteIndex)
    {
        txMsg.data[3 + byteIndex] = countryCodeSpecific[byteIndex];
        ++txMsg.dataNum;

        if (VSCP_L1_DATA_SIZE <= txMsg.dataNum)
        {
            break;
        }
    }
    txMsg.data[0] = customCodedSystem;

    return vscp_core_sendEvent(&txMsg);
}

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
extern BOOL vscp_control_sendBigChangeLevelEvent(uint8_t index, uint8_t zone, uint8_t subZone, int8_t const * const level, uint8_t levelSize)
{
    uint8_t byteIndex = 0;
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_BIG_CHANGE_LEVEL, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    for(byteIndex = 0; byteIndex < levelSize; ++byteIndex)
    {
        txMsg.data[3 + byteIndex] = level[byteIndex];
        ++txMsg.dataNum;

        if (VSCP_L1_DATA_SIZE <= txMsg.dataNum)
        {
            break;
        }
    }

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Move shutter up.
 *
 * @param[in] index Index
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_control_sendMoveShutterUpEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MOVE_SHUTTER_UP, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Move shutter down.
 *
 * @param[in] index Index
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_control_sendMoveShutterDownEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MOVE_SHUTTER_DOWN, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Move shutter left.
 *
 * @param[in] index Index
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_control_sendMoveShutterLeftEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MOVE_SHUTTER_LEFT, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Move shutter right.
 *
 * @param[in] index Index
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_control_sendMoveShutterRightEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MOVE_SHUTTER_RIGHT, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Move shutter to middle position.
 *
 * @param[in] index Index
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_control_sendMoveShutterMiddlePosEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MOVE_SHUTTER_MIDDLE_POS, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 3;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Move shutter to preset position.
 *
 * @param[in] index Index
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @param[in] pos Position 0-100
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 *
 */
extern BOOL vscp_control_sendMoveShutterPresetPosEvent(uint8_t index, uint8_t zone, uint8_t subZone, uint8_t pos)
{
    vscp_TxMessage txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_CONTROL, VSCP_TYPE_CONTROL_MOVE_SHUTTER_PRESET_POS, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 4;
    txMsg.data[0] = index;
    txMsg.data[1] = zone;
    txMsg.data[2] = subZone;
    txMsg.data[3] = pos;

    return vscp_core_sendEvent(&txMsg);
}

/*******************************************************************************
    LOCAL FUNCTIONS
*******************************************************************************/

