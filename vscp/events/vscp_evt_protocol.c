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
@brief  VSCP Protocol Functionality
@file   vscp_evt_protocol.c
@author Andreas Merkle, http://www.blue-andi.de

@section desc Description
@see vscp_evt_protocol.h

This file is automatically generated. Don't change it manually.

*******************************************************************************/

/*******************************************************************************
    INCLUDES
*******************************************************************************/
#include "vscp_evt_protocol.h"
#include "vscp_core.h"
#include "vscp_class_l1.h"
#include "vscp_type_protocol.h"

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
 * General event.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendGeneralEvent(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_GENERAL, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Segment Controller Heartbeat.
 * 
 * @param[in] crc 8-bit CRC of the segment controller GUID
 * @param[in] time Time since epoch. (optional)
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendSegmentControllerHeartbeat(uint8_t crc, uint32_t const * const time)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_SEGCTRL_HEARTBEAT, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = crc;
    size += 1;

    if (NULL != time)
    {
        txMsg.data[1] = (uint8_t)((*time >> 24) & 0xff);
        txMsg.data[2] = (uint8_t)((*time >> 18) & 0xff);
        txMsg.data[3] = (uint8_t)((*time >> 8) & 0xff);
        txMsg.data[4] = (uint8_t)((*time >> 0) & 0xff);
        size += 4;
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * New node on line / Probe.
 * 
 * @param[in] targetAddress This is the probe nickname that the new node is using to test if this is a
 * valid target node. If there is a node with this nickname address it should answer with probe ACK. A
 * probe always has 0xff as it's own temporary nickname while a new node on line use a non 0xff
 * nickname.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendNewNodeOnLineProbe(uint8_t targetAddress)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_NEW_NODE_ONLINE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = targetAddress;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Probe ACK.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendProbeAck(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_PROBE_ACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/* "Reserved for future use." not supported. No frame defined. */

/* "Reserved for future use." not supported. No frame defined. */

/**
 * Set nickname-ID for node.
 * 
 * @param[in] oldNickname Old nickname for node.
 * @param[in] newNickname The new nickname for the node.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendSetNicknameIdForNode(uint8_t oldNickname, uint8_t newNickname)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_SET_NICKNAME, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = oldNickname;
    size += 1;

    txMsg.data[1] = newNickname;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Nickname-ID accepted.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendNicknameIdAccepted(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_NICKNAME_ACCEPTED, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Drop nickname-ID / Reset Device.
 * 
 * @param[in] nickname The current nickname for the node.
 * @param[in] flags Flags. (optional)
 * @param[in] time Time the node should wait before it starts a nickname discovery or starts the
 * device. The time is in seconds. (optional)
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendDropNicknameIdResetDevice(uint8_t nickname, uint8_t const * const flags, uint8_t const * const time)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_DROP_NICKNAME, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nickname;
    size += 1;

    if (NULL != flags)
    {
        txMsg.data[1] = *flags;
        size += 1;
    }

    if (NULL != time)
    {
        txMsg.data[2] = *time;
        size += 1;
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Read register.
 * 
 * @param[in] nodeAddress Node address.
 * @param[in] registerAddress Register to read.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendReadRegister(uint8_t nodeAddress, uint8_t registerAddress)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_READ_REGISTER, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeAddress;
    size += 1;

    txMsg.data[1] = registerAddress;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Read/Write response.
 * 
 * @param[in] registerAddress Register address read/written.
 * @param[in] registerValue Value of register.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendReadWriteResponse(uint8_t registerAddress, uint8_t registerValue)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_RW_RESPONSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = registerAddress;
    size += 1;

    txMsg.data[1] = registerValue;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Write register.
 * 
 * @param[in] nodeAddress Node address.
 * @param[in] registerAddress Register to write.
 * @param[in] registerValue Value which to write to register.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendWriteRegister(uint8_t nodeAddress, uint8_t registerAddress, uint8_t registerValue)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_WRITE_REGISTER, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeAddress;
    size += 1;

    txMsg.data[1] = registerAddress;
    size += 1;

    txMsg.data[2] = registerValue;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Enter boot loader mode.
 * 
 * @param[in] nodeAddress The nickname for the node.
 * @param[in] bootloaderAlgorithm Code that select boot loader algorithm to use.
 * @param[in] guidByte0 GUID Byte 0 (MSB).
 * @param[in] guidByte3 GUID Byte 3 (MSB + 3).
 * @param[in] guidByte5 GUID Byte 5 (MSB + 5).
 * @param[in] guidByte7 GUID Byte 7 (MSB + 7).
 * @param[in] pageSelect Page select, content of register 0x92 and 0x93.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendEnterBootLoaderMode(uint8_t nodeAddress, uint8_t bootloaderAlgorithm, uint8_t guidByte0, uint8_t guidByte3, uint8_t guidByte5, uint8_t guidByte7, uint16_t pageSelect)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_ENTER_BOOT_LOADER, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeAddress;
    size += 1;

    txMsg.data[1] = bootloaderAlgorithm;
    size += 1;

    txMsg.data[2] = guidByte0;
    size += 1;

    txMsg.data[3] = guidByte3;
    size += 1;

    txMsg.data[4] = guidByte5;
    size += 1;

    txMsg.data[5] = guidByte7;
    size += 1;

    txMsg.data[6] = (uint8_t)((pageSelect >> 8) & 0xff);
    txMsg.data[7] = (uint8_t)((pageSelect >> 0) & 0xff);
    size += 2;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * ACK boot loader mode.
 * 
 * @param[in] flashBlockSize Flash block size in byte.
 * @param[in] numberOfBlocks Number of blocks available.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendAckBootLoaderMode(uint32_t flashBlockSize, uint32_t numberOfBlocks)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_ACK_BOOT_LOADER, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((flashBlockSize >> 24) & 0xff);
    txMsg.data[1] = (uint8_t)((flashBlockSize >> 18) & 0xff);
    txMsg.data[2] = (uint8_t)((flashBlockSize >> 8) & 0xff);
    txMsg.data[3] = (uint8_t)((flashBlockSize >> 0) & 0xff);
    size += 4;

    txMsg.data[4] = (uint8_t)((numberOfBlocks >> 24) & 0xff);
    txMsg.data[5] = (uint8_t)((numberOfBlocks >> 18) & 0xff);
    txMsg.data[6] = (uint8_t)((numberOfBlocks >> 8) & 0xff);
    txMsg.data[7] = (uint8_t)((numberOfBlocks >> 0) & 0xff);
    size += 4;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * NACK boot loader mode.
 * 
 * @param[in] errorCode Optional user defined error code. (optional)
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendNackBootLoaderMode(uint32_t const * const errorCode)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_NACK_BOOT_LOADER, VSCP_PRIORITY_3_NORMAL);

    if (NULL != errorCode)
    {
        txMsg.data[0] = (uint8_t)((*errorCode >> 24) & 0xff);
        txMsg.data[1] = (uint8_t)((*errorCode >> 18) & 0xff);
        txMsg.data[2] = (uint8_t)((*errorCode >> 8) & 0xff);
        txMsg.data[3] = (uint8_t)((*errorCode >> 0) & 0xff);
        size += 4;
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Start block data transfer.
 * 
 * @param[in] blockNumber Block number.
 * @param[in] memoryType Type of Memory we want to write.. (optional)
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendStartBlockDataTransfer(uint32_t blockNumber, uint8_t const * const memoryType)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_START_BLOCK, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((blockNumber >> 24) & 0xff);
    txMsg.data[1] = (uint8_t)((blockNumber >> 18) & 0xff);
    txMsg.data[2] = (uint8_t)((blockNumber >> 8) & 0xff);
    txMsg.data[3] = (uint8_t)((blockNumber >> 0) & 0xff);
    size += 4;

    if (NULL != memoryType)
    {
        txMsg.data[4] = *memoryType;
        size += 1;
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Block data.
 * 
 * @param[in] data Data. (array[8])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendBlockData(uint8_t const * const data, uint8_t dataSize)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == data) || (0 == dataSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_BLOCK_DATA, VSCP_PRIORITY_3_NORMAL);

    for(byteIndex = 0; byteIndex < dataSize; ++byteIndex)
    {
        txMsg.data[0 + byteIndex] = data[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * ACK data block.
 * 
 * @param[in] blockCrc CRC for block.
 * @param[in] writePointer Write pointer.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendAckDataBlock(uint16_t blockCrc, uint32_t writePointer)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_BLOCK_DATA_ACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((blockCrc >> 8) & 0xff);
    txMsg.data[1] = (uint8_t)((blockCrc >> 0) & 0xff);
    size += 2;

    txMsg.data[2] = (uint8_t)((writePointer >> 24) & 0xff);
    txMsg.data[3] = (uint8_t)((writePointer >> 18) & 0xff);
    txMsg.data[4] = (uint8_t)((writePointer >> 8) & 0xff);
    txMsg.data[5] = (uint8_t)((writePointer >> 0) & 0xff);
    size += 4;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * NACK data block.
 * 
 * @param[in] errorCode User defined error code.
 * @param[in] writePointer Write pointer.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendNackDataBlock(uint8_t errorCode, uint32_t writePointer)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_BLOCK_DATA_NACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = errorCode;
    size += 1;

    txMsg.data[1] = (uint8_t)((writePointer >> 24) & 0xff);
    txMsg.data[2] = (uint8_t)((writePointer >> 18) & 0xff);
    txMsg.data[3] = (uint8_t)((writePointer >> 8) & 0xff);
    txMsg.data[4] = (uint8_t)((writePointer >> 0) & 0xff);
    size += 4;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Program data block.
 * 
 * @param[in] blockNumber Block number.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendProgramDataBlock(uint32_t blockNumber)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_PROGRAM_BLOCK_DATA, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((blockNumber >> 24) & 0xff);
    txMsg.data[1] = (uint8_t)((blockNumber >> 18) & 0xff);
    txMsg.data[2] = (uint8_t)((blockNumber >> 8) & 0xff);
    txMsg.data[3] = (uint8_t)((blockNumber >> 0) & 0xff);
    size += 4;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * ACK program data block.
 * 
 * @param[in] blockNumber Block number.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendAckProgramDataBlock(uint32_t blockNumber)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_PROGRAM_BLOCK_DATA_ACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((blockNumber >> 24) & 0xff);
    txMsg.data[1] = (uint8_t)((blockNumber >> 18) & 0xff);
    txMsg.data[2] = (uint8_t)((blockNumber >> 8) & 0xff);
    txMsg.data[3] = (uint8_t)((blockNumber >> 0) & 0xff);
    size += 4;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * NACK program data block.
 * 
 * @param[in] errorCode User defined error code.
 * @param[in] blockNumber Block number.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendNackProgramDataBlock(uint8_t errorCode, uint32_t blockNumber)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_PROGRAM_BLOCK_DATA_NACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = errorCode;
    size += 1;

    txMsg.data[1] = (uint8_t)((blockNumber >> 24) & 0xff);
    txMsg.data[2] = (uint8_t)((blockNumber >> 18) & 0xff);
    txMsg.data[3] = (uint8_t)((blockNumber >> 8) & 0xff);
    txMsg.data[4] = (uint8_t)((blockNumber >> 0) & 0xff);
    size += 4;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Activate new image.
 * 
 * @param[in] crc CRC of full flash data block.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendActivateNewImage(uint16_t crc)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_ACTIVATE_NEW_IMAGE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((crc >> 8) & 0xff);
    txMsg.data[1] = (uint8_t)((crc >> 0) & 0xff);
    size += 2;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/* "GUID drop nickname-ID / reset device." not supported, because of multi frame. */

/**
 * Page read.
 * 
 * @param[in] nodeId Node-ID which registers should be read.
 * @param[in] index Index into page.
 * @param[in] numberOfBytes Number of bytes to read.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendPageRead(uint8_t nodeId, uint8_t index, uint8_t numberOfBytes)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_PAGE_READ, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeId;
    size += 1;

    txMsg.data[1] = index;
    size += 1;

    txMsg.data[2] = numberOfBytes;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Page write.
 * 
 * @param[in] nodeId Node-ID which registers should be read.
 * @param[in] registerStart Register start address.
 * @param[in] data Data to write. (array[6])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendPageWrite(uint8_t nodeId, uint8_t registerStart, uint8_t const * const data, uint8_t dataSize)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == data) || (0 == dataSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_PAGE_WRITE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeId;
    size += 1;

    txMsg.data[1] = registerStart;
    size += 1;

    for(byteIndex = 0; byteIndex < dataSize; ++byteIndex)
    {
        txMsg.data[2 + byteIndex] = data[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Read/Write page response.
 * 
 * @param[in] sequenceNumber Sequence number.
 * @param[in] data Data. (array[7])
 * @param[in] datasize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendReadWritePageResponse(uint8_t sequenceNumber, uint8_t const * const data, uint8_t dataSize)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == data) || (0 == dataSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_RW_PAGE_RESPONSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = sequenceNumber;
    size += 1;

    for(byteIndex = 0; byteIndex < dataSize; ++byteIndex)
    {
        txMsg.data[2 + byteIndex] = data[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * High end server/service probe.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendHighEndServerServiceProbe(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_HIGH_END_SERVER_PROBE, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * High end server/service response.
 * 
 * @param[in] capabilityCode VSCP server capability code.
 * @param[in] serverIp Server IP address. (array[4])
 * @param[in] serverIpsize Size in byte.
 * @param[in] serverPort Server port number.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendHighEndServerServiceResponse(uint16_t capabilityCode, uint8_t const * const serverIp, uint8_t serverIpSize, uint16_t serverPort)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == serverIp) || (0 == serverIpSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_HIGH_END_SERVER_RESPONSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((capabilityCode >> 8) & 0xff);
    txMsg.data[1] = (uint8_t)((capabilityCode >> 0) & 0xff);
    size += 2;

    for(byteIndex = 0; byteIndex < serverIpSize; ++byteIndex)
    {
        txMsg.data[2 + byteIndex] = serverIp[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.data[6] = (uint8_t)((serverPort >> 8) & 0xff);
    txMsg.data[7] = (uint8_t)((serverPort >> 0) & 0xff);
    size += 2;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Increment register.
 * 
 * @param[in] nodeId Node-ID.
 * @param[in] registerAddress Register to increment. (array[7])
 * @param[in] registerAddresssize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendIncrementRegister(uint8_t nodeId, uint8_t const * const registerAddress, uint8_t registerAddressSize)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == registerAddress) || (0 == registerAddressSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_INCREMENT_REGISTER, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeId;
    size += 1;

    for(byteIndex = 0; byteIndex < registerAddressSize; ++byteIndex)
    {
        txMsg.data[1 + byteIndex] = registerAddress[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Decrement register.
 * 
 * @param[in] nodeId Node-ID.
 * @param[in] registerAddress Register to decrement. (array[7])
 * @param[in] registerAddresssize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendDecrementRegister(uint8_t nodeId, uint8_t const * const registerAddress, uint8_t registerAddressSize)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == registerAddress) || (0 == registerAddressSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_DECREMENT_REGISTER, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeId;
    size += 1;

    for(byteIndex = 0; byteIndex < registerAddressSize; ++byteIndex)
    {
        txMsg.data[1 + byteIndex] = registerAddress[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Who is there?
 * 
 * @param[in] nodeId Node-ID or 0xFF for all nodes.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendWhoIsThere(uint8_t nodeId)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_WHO_IS_THERE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeId;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/* "Who is there response." not supported, because of multi frame. */

/**
 * Get decision matrix info.
 * 
 * @param[in] nodeAddress Node address.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendGetDecisionMatrixInfo(uint8_t nodeAddress)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_GET_MATRIX_INFO, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeAddress;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Decision matrix info response.
 * 
 * @param[in] matrixSize Matrix size (number of rows). Zero for a device with no decision matrix.
 * @param[in] offset Offset in register space.
 * @param[in] pageStart Page start. (optional)
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendDecisionMatrixInfoResponse(uint8_t matrixSize, uint8_t offset, uint16_t const * const pageStart)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_GET_MATRIX_INFO_RESPONSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = matrixSize;
    size += 1;

    txMsg.data[1] = offset;
    size += 1;

    if (NULL != pageStart)
    {
        txMsg.data[2] = (uint8_t)((*pageStart >> 8) & 0xff);
        txMsg.data[3] = (uint8_t)((*pageStart >> 0) & 0xff);
        size += 2;
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Get embedded MDF.
 * 
 * @param[in] nodeAddress Node address.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendGetEmbeddedMdf(uint8_t nodeAddress)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_GET_EMBEDDED_MDF, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeAddress;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Embedded MDF response.
 * 
 * @param[in] mdfDescriptionIndex MDF description index.
 * @param[in] mdfData MDF data.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendEmbeddedMdfResponse(uint16_t mdfDescriptionIndex, uint8_t mdfData)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_GET_EMBEDDED_MDF_RESPONSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = (uint8_t)((mdfDescriptionIndex >> 8) & 0xff);
    txMsg.data[1] = (uint8_t)((mdfDescriptionIndex >> 0) & 0xff);
    size += 2;

    txMsg.data[2] = mdfData;
    size += 1;

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Extended page read register.
 * 
 * @param[in] nodeAddress Node address.
 * @param[in] page Page where the register is located.
 * @param[in] offset Register to read (offset into page).
 * @param[in] number Number of registers to read. (optional)
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendExtendedPageReadRegister(uint8_t nodeAddress, uint16_t page, uint8_t offset, uint8_t const * const number)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_EXTENDED_PAGE_READ, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeAddress;
    size += 1;

    txMsg.data[1] = (uint8_t)((page >> 8) & 0xff);
    txMsg.data[2] = (uint8_t)((page >> 0) & 0xff);
    size += 2;

    txMsg.data[3] = offset;
    size += 1;

    if (NULL != number)
    {
        txMsg.data[4] = *number;
        size += 1;
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Extended page write register.
 * 
 * @param[in] nodeAddress Node address.
 * @param[in] page Page where the register is located.
 * @param[in] offset Register to write (offset into page).
 * @param[in] value Content for register. (array[4])
 * @param[in] valuesize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendExtendedPageWriteRegister(uint8_t nodeAddress, uint16_t page, uint8_t offset, uint8_t const * const value, uint8_t valueSize)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == value) || (0 == valueSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_EXTENDED_PAGE_WRITE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = nodeAddress;
    size += 1;

    txMsg.data[1] = (uint8_t)((page >> 8) & 0xff);
    txMsg.data[2] = (uint8_t)((page >> 0) & 0xff);
    size += 2;

    txMsg.data[3] = offset;
    size += 1;

    for(byteIndex = 0; byteIndex < valueSize; ++byteIndex)
    {
        txMsg.data[4 + byteIndex] = value[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Extended page read/write response.
 * 
 * @param[in] index Index (starts at zero).
 * @param[in] page Page where the register is located.
 * @param[in] offset Register read/written.
 * @param[in] value Content of register. (array[4])
 * @param[in] valuesize Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendExtendedPageReadWriteResponse(uint8_t index, uint16_t page, uint8_t offset, uint8_t const * const value, uint8_t valueSize)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == value) || (0 == valueSize))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_EXTENDED_PAGE_RESPONSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = index;
    size += 1;

    txMsg.data[1] = (uint8_t)((page >> 8) & 0xff);
    txMsg.data[2] = (uint8_t)((page >> 0) & 0xff);
    size += 2;

    txMsg.data[3] = offset;
    size += 1;

    for(byteIndex = 0; byteIndex < valueSize; ++byteIndex)
    {
        txMsg.data[4 + byteIndex] = value[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Get event interest.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendGetEventInterest(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_GET_EVENT_INTEREST, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Get event interest response.
 * 
 * @param[in] index Index.
 * @param[in] classBit9 Class bit 9.
 * @param[in] class1 Class 1.
 * @param[in] type1 Type 1. (array[4])
 * @param[in] type1size Size in byte.
 * @param[in] class2 Class 2.
 * @param[in] type2 Type 2. (array[4])
 * @param[in] type2size Size in byte.
 * @param[in] class3 Class 3.
 * @param[in] type3 Type 3. (array[4])
 * @param[in] type3size Size in byte.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendGetEventInterestResponse(uint8_t index, uint16_t classBit9, uint8_t class1, uint8_t const * const type1, uint8_t type1Size, uint8_t class2, uint8_t const * const type2, uint8_t type2Size, uint8_t class3, uint8_t const * const type3, uint8_t type3Size)
{
    vscp_TxMessage  txMsg;
    uint8_t         size    = 0;
    uint8_t         byteIndex   = 0;

    if ((NULL == type1) || (0 == type1Size))
    {
        return FALSE;
    }

    if ((NULL == type2) || (0 == type2Size))
    {
        return FALSE;
    }

    if ((NULL == type3) || (0 == type3Size))
    {
        return FALSE;
    }

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_GET_EVENT_INTEREST_RESPONSE, VSCP_PRIORITY_3_NORMAL);

    txMsg.data[0] = index;
    size += 1;

    txMsg.data[1] = (uint8_t)((classBit9 >> 8) & 0xff);
    txMsg.data[2] = (uint8_t)((classBit9 >> 0) & 0xff);
    size += 2;

    txMsg.data[2] = class1;
    size += 1;

    for(byteIndex = 0; byteIndex < type1Size; ++byteIndex)
    {
        txMsg.data[3 + byteIndex] = type1[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.data[4] = class2;
    size += 1;

    for(byteIndex = 0; byteIndex < type2Size; ++byteIndex)
    {
        txMsg.data[5 + byteIndex] = type2[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.data[6] = class3;
    size += 1;

    for(byteIndex = 0; byteIndex < type3Size; ++byteIndex)
    {
        txMsg.data[7 + byteIndex] = type3[byteIndex];
        size += 1;

        if (VSCP_L1_DATA_SIZE <= size)
        {
            break;
        }
    }

    txMsg.dataNum = size;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Activate new image ACK.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendActivateNewImageAck(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_ACTIVATE_NEW_IMAGE_ACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Activate new image NACK.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendActivateNewImageNack(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_ACTIVATE_NEW_IMAGE_NACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Block data transfer ACK.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendBlockDataTransferAck(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_START_BLOCK_ACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

/**
 * Block data transfer NACK.
 * 
 * @return If event is sent, it will return TRUE otherwise FALSE.
 */
extern BOOL vscp_evt_protocol_sendBlockDataTransferNack(void)
{
    vscp_TxMessage  txMsg;

    vscp_core_prepareTxMessage(&txMsg, VSCP_CLASS_L1_PROTOCOL, VSCP_TYPE_PROTOCOL_START_BLOCK_NACK, VSCP_PRIORITY_3_NORMAL);

    txMsg.dataNum = 0;

    return vscp_core_sendEvent(&txMsg);
}

