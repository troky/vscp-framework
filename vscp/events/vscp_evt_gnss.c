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
@brief  Position (GNSS)
@file   vscp_evt_gnss.c
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
@see vscp_evt_gnss.h

This file is automatically generated. Don't change it manually.

*******************************************************************************/

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "vscp_evt_gnss.h"
#include "vscp_core.h"
#include "vscp_class_l1.h"
#include "vscp_type_gnss.h"

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
extern BOOL vscp_evt_gnss_sendGeneralEvent(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_GNSS, VSCP_TYPE_GNSS_GENERAL, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Position
 * 
 * @param[in] latitude Latitude as floating point value.
 * @param[in] longitude Longitude as floating point value.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_gnss_sendPosition(float_t latitude, float_t longitude)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_GNSS, VSCP_TYPE_GNSS_POSITION, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[4] = ((uint8_t*)&latitude)[3];
    txMsg.data[5] = ((uint8_t*)&latitude)[2];
    txMsg.data[6] = ((uint8_t*)&latitude)[1];
    txMsg.data[7] = ((uint8_t*)&latitude)[0];
    size += 4;

    txMsg.data[8] = ((uint8_t*)&longitude)[3];
    txMsg.data[9] = ((uint8_t*)&longitude)[2];
    txMsg.data[10] = ((uint8_t*)&longitude)[1];
    txMsg.data[11] = ((uint8_t*)&longitude)[0];
    size += 4;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Satellites
 * 
 * @param[in] count Number of satellites used.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_gnss_sendSatellites(uint8_t count)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_GNSS, VSCP_TYPE_GNSS_SATELLITES, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = count;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

