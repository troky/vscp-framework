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
@brief  VSCP class 1 type Weather events
@file   vscp_weather.c
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
@see vscp_weather.h

This file is automatically generated. Don't change it manually.

@section svn Subversion
$Author: amerkle $
$Rev: 449 $
$Date: 2015-01-05 20:23:52 +0100 (Mo, 05 Jan 2015) $
*******************************************************************************/

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "vscp_weather.h"
#include "vscp_core.h"
#include "vscp_class_l1.h"
#include "vscp_type_weather.h"

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
extern BOOL vscp_weather_sendUndefinedEvent(void)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_UNDEFINED, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 0;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * The winter season as started.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSeasonWinterEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SEASON_WINTER, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * The spring season has started.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSeasonSpringEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SEASON_SPRING, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * The summer season has started.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSeasonSummerEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SEASON_SUMMER, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * The autumn season has started.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAutumnSummerEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AUTUMN_SUMMER, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * No wind
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendWinNoneEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_WIN_NONE, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Low wind speed conditions.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendLowWindEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_LOW_WIND, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Medium wind speed conditions.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendMediumWindEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_MEDIUM_WIND, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * High wind speed conditions.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendHighWindEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_HIGH_WIND, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Very high wind speed conditions.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendVeryHighWindEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_VERY_HIGH_WIND, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Fogg.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAirFoggyEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AIR_FOGGY, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Freezing.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAirFreezingEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AIR_FREEZING, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Cold
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendColdEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_COLD, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Very cold
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendVeryColdEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_VERY_COLD, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Air normal
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAirNormalEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AIR_NORMAL, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Air hot
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAirHotEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AIR_HOT, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Air very hot
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAirVeryHotEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AIR_VERY_HOT, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Pollution low
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendPollutionLowEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_POLLUTION_LOW, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Pollution medium
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendPollutionMediumEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_POLLUTION_MEDIUM, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Pollution high
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendPollutionHighEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_POLLUTION_HIGH, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Air humid
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAirHumidEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AIR_HUMID, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Air dry
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendAirDryEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_AIR_DRY, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * soil humid
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSoilHumidEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SOIL_HUMID, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * soil dry
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSoilDryEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SOIL_DRY, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Rain none
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendRainNoneEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_RAIN_NONE, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Rain light
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendRainLightEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_RAIN_LIGHT, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Rain heavy
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendRainHeavyEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_RAIN_HEAVY, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Rain very heavy
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendRainVeryHeavyEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_RAIN_VERY_HEAVY, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Sun none
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSunNoneEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SUN_NONE, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Sun light
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSunLightEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SUN_LIGHT, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Sun heavy
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSunHeavyEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SUN_HEAVY, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Snow none.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSnowNoneEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SNOW_NONE, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Snow light.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSnowLightEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SNOW_LIGHT, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Snow heavy.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendSnowHeavyEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_SNOW_HEAVY, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Dew point.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendDewPointEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_DEW_POINT, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Storm.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendStormEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_STORM, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Flood.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendFloodEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_FLOOD, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Earthquake
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendEarthquakeEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_EARTHQUAKE, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Nuclera disaster
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendNuclearDisasterEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_NUCLEAR_DISASTER, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Fire.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendFireEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_FIRE, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Lightning.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendLightningEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_LIGHTNING, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Radiation low.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendUvRadiationLowEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_UV_RADIATION_LOW, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Radiation medium.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendUvRadiationMediumEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_UV_RADIATION_MEDIUM, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Radiation normal.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendUvRadiationNormalEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_UV_RADIATION_NORMAL, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Radiation high.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendUvRadiationHighEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_UV_RADIATION_HIGH, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Radiation very high.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendUvRadiationVeryHighEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_UV_RADIATION_VERY_HIGH, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Warning level 1. This is the lowest varning level.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendWarningLevel1Event(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_WARNING_LEVEL_1, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Warninglevel 2.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendWarningLevel2Event(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_WARNING_LEVEL_2, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Warninglevel 3.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendWarningLevel3Event(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_WARNING_LEVEL_3, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Warning level 4.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendWarningLevel4Event(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_WARNING_LEVEL_4, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * Warning level 5. This is the highest warning level.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendWarningLevel5Event(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_WARNING_LEVEL_5, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/**
 * The final warning level not seen by humans.
 * 
 * @param[in] index Index.
 * @param[in] zone Zone for which event applies to (0-255). 255 is all zones.
 * @param[in] subZone Sub-zone for which event applies to (0-255). 255 is all sub-zones.
 * @return Status
 * @retval FALSE Failed to send the event
 * @retval TRUE  Event successul sent
 * 
 */
extern BOOL vscp_weather_sendArmageddonEvent(uint8_t index, uint8_t zone, uint8_t subZone)
{
	vscp_TxMessage txMsg;

	vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_WEATHER, VSCP_TYPE_WEATHER_ARMAGEDDON, VSCP_PRIORITY_3_NORMAL);

	txMsg.dataNum = 3;
	txMsg.data[0] = index;
	txMsg.data[1] = zone;
	txMsg.data[2] = subZone;

	return vscp_core_sendEvent(&txMsg);
}

/*******************************************************************************
    LOCAL FUNCTIONS
*******************************************************************************/

