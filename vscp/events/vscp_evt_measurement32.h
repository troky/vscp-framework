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
@brief  Single precision floating point measurement
@file   vscp_evt_measurement32.h
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
Floating point single precision measurements. This class mirrors the standard measurement events is
CLASS1.MEASUREMENT=10. The measurement unit is always the standard unit.

This file is automatically generated. Don't change it manually.

*******************************************************************************/

#ifndef __VSCP_EVT_MEASUREMENT32_H__
#define __VSCP_EVT_MEASUREMENT32_H__

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
extern BOOL vscp_evt_measurement32_sendGeneralEvent(void);

/* "Count" not supported. No frame defined. */

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendLengthDistance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendMass(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendTime(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendElectricCurrent(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendTemperature(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendAmountOfSubstance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendLuminousIntensityIntensityOfLight(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendFrequency(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendRadioactivityAndOtherRandomEvents(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendForce(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendPressure(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendEnergy(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendPower(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendElectricalCharge(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendElectricalPotentialVoltage(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendElectricalCapacitance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendElectricalResistance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendElectricalConductance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendMagneticFieldStrength(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendMagneticFlux(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendMagneticFluxDensity(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendInductance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendLuminousFlux(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendIlluminance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendRadiationDose(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendCatalyticActivity(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendVolume(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSoundIntensity(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendAngle(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendPositionWgs84(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSpeed(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendAcceleration(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendTension(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendDampMoistHygrometerReading(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendFlow(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendThermalResistance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendRefractiveOpticalPower(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendDynamicViscosity(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSoundImpedance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSoundResistance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendElectricElastance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendLuminousEnergy(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendLuminance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendChemicalConcentration(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/* "Reserved" not supported. No frame defined. */

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendDoseEquivalent(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/* "Reserved" not supported. No frame defined. */

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendDewPoint(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendRelativeLevel(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendAltitude(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendArea(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendRadiantIntensity(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendRadiance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendIrradianceExitanceRadiosity(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSpectralRadiance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSpectralIrradiance(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSoundPressureAcousticPressure(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSoundEnergyDensity(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

/**
 * Count
 * 
 * @param[in] dataCoding Data coding.
 * @param[in] data Data with format defined by byte 0.  (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_measurement32_sendSoundLevel(uint8_t dataCoding, uint8_t const * const data, uint8_t dataSize);

#endif  /* __VSCP_EVT_MEASUREMENT32_H__ */
