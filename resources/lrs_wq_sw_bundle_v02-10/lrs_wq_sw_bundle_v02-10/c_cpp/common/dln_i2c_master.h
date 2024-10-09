#ifndef DLN_I2C_MASTER_H_INCLUDED
#define DLN_I2C_MASTER_H_INCLUDED


#include "dln.h"


#ifdef __cplusplus
extern "C" {
#endif


#if defined(__ICCARM__)
        #pragma pack(1)
        #define __PACKED_ATTR   /*nothing*/
        //#define __attribute__(...)
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(push,1)
        #define __PACKED_ATTR   /*nothing*/
        //#define __attribute__(...)
#else
        #define __PACKED_ATTR __attribute__ ((packed))
#endif


#define DLN_PIN_ROLE_I2C_MASTER_SDA     ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_I2C_MASTER_SCL     ((DLN_PIN_ROLE)0)


#define DLN_MSG_ID_I2C_MASTER_GET_PORT_COUNT        DLN_BUILD_MSG_ID(0x00, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_ENABLE                DLN_BUILD_MSG_ID(0x01, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_DISABLE               DLN_BUILD_MSG_ID(0x02, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_IS_ENABLED            DLN_BUILD_MSG_ID(0x03, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_SET_FREQUENCY         DLN_BUILD_MSG_ID(0x04, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_GET_FREQUENCY         DLN_BUILD_MSG_ID(0x05, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_WRITE                 DLN_BUILD_MSG_ID(0x06, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_READ                  DLN_BUILD_MSG_ID(0x07, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_SCAN_DEVICES          DLN_BUILD_MSG_ID(0x08, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_PULLUP_ENABLE         DLN_BUILD_MSG_ID(0x09, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_PULLUP_DISABLE        DLN_BUILD_MSG_ID(0x0A, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_PULLUP_IS_ENABLED     DLN_BUILD_MSG_ID(0x0B, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_TRANSFER              DLN_BUILD_MSG_ID(0x0C, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_SET_MAX_REPLY_COUNT   DLN_BUILD_MSG_ID(0x0D, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_GET_MAX_REPLY_COUNT   DLN_BUILD_MSG_ID(0x0E, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_GET_MIN_FREQUENCY     DLN_BUILD_MSG_ID(0x40, DLN_MODULE_I2C_MASTER)
#define DLN_MSG_ID_I2C_MASTER_GET_MAX_FREQUENCY     DLN_BUILD_MSG_ID(0x41, DLN_MODULE_I2C_MASTER)


#define DLN_I2C_MASTER_ENABLED              1
#define DLN_I2C_MASTER_DISABLED             0

#define DLN_I2C_MASTER_MEM_ADDRESS_NONE     0
#define DLN_I2C_MASTER_MEM_ADDRESS_1_BYTE   1
#define DLN_I2C_MASTER_MEM_ADDRESS_2_BYTES  2
#define DLN_I2C_MASTER_MEM_ADDRESS_3_BYTES  3
#define DLN_I2C_MASTER_MEM_ADDRESS_4_BYTES  4

#define DLN_I2C_MASTER_PULLUP_ENABLED       1
#define DLN_I2C_MASTER_PULLUP_DISABLED      0


typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_I2C_MASTER_GET_PORT_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_I2C_MASTER_GET_PORT_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t conflict;
} __PACKED_ATTR DLN_I2C_MASTER_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_MASTER_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_IS_ENABLED_CMD;


typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_I2C_MASTER_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t frequency;
} __PACKED_ATTR DLN_I2C_MASTER_SET_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_I2C_MASTER_SET_FREQUENCY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_GET_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_I2C_MASTER_GET_FREQUENCY_RSP;


#define DLN_I2C_MASTER_MAX_TRANSFER_SIZE 256

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t slaveDeviceAddress;
    uint8_t memoryAddressLength;
    uint32_t memoryAddress;
    uint16_t bufferLength;
    uint8_t buffer[DLN_I2C_MASTER_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_I2C_MASTER_WRITE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_MASTER_WRITE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t slaveDeviceAddress;
    uint8_t memoryAddressLength;
    uint32_t memoryAddress;
    uint16_t bufferLength;
} __PACKED_ATTR DLN_I2C_MASTER_READ_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t bufferLength;
    uint8_t buffer[DLN_I2C_MASTER_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_I2C_MASTER_READ_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_SCAN_DEVICES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t addressCount;
    uint8_t addressList[128];
} __PACKED_ATTR DLN_I2C_MASTER_SCAN_DEVICES_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_PULLUP_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_MASTER_PULLUP_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_PULLUP_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_MASTER_PULLUP_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_PULLUP_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_I2C_MASTER_PULLUP_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t slaveDeviceAddress;
    uint16_t writeLength;
    uint16_t readLength;
    uint8_t writeBuffer[DLN_I2C_MASTER_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_I2C_MASTER_TRANSFER_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t readLength;
    uint8_t readBuffer[DLN_I2C_MASTER_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_I2C_MASTER_TRANSFER_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_GET_MIN_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_I2C_MASTER_GET_MIN_FREQUENCY_RSP;

#define DLN_I2C_MASTER_GET_MAX_FREQUENCY_CMD    DLN_I2C_MASTER_GET_MIN_FREQUENCY_CMD
#define DLN_I2C_MASTER_GET_MAX_FREQUENCY_RSP    DLN_I2C_MASTER_GET_MIN_FREQUENCY_RSP


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t maxReplyCount;
} __PACKED_ATTR DLN_I2C_MASTER_SET_MAX_REPLY_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_MASTER_SET_MAX_REPLY_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_MASTER_GET_MAX_REPLY_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t maxReplyCount;
} __PACKED_ATTR DLN_I2C_MASTER_GET_MAX_REPLY_COUNT_RSP;


/*!
\retval DLN_RES_SUCCESS - the port count has been successfully retrieved.
*/
DLN_RESULT DlnI2cMasterGetPortCount(HDLN handle, uint8_t *count);

/*!
\retval DLN_RES_SUCCESS - the I2C master module has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_PIN_IN_USE - the I2C pins are assigned to another module of the adapter and cannot be enabled as I2C.
*/
DLN_RESULT DlnI2cMasterEnable(HDLN handle, uint8_t port, uint16_t *conflict);

/*!
\retval DLN_RES_SUCCESS - the I2C master module has been successfully disabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cMasterDisable(HDLN handle, uint8_t port);

/*!
\retval DLN_RES_SUCCESS - the I2C master state has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cMasterIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

/*!
\retval DLN_RES_SUCCESS - the frequency has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_BUSY - could not change frequency while the I2C master module is busy transferring;
\retval DLN_RES_VALUE_ROUNDED - the frequency value has been approximated as the closest supported value.
*/
DLN_RESULT DlnI2cMasterSetFrequency(HDLN handle, uint8_t port, uint32_t frequency, uint32_t *actualFrequency);

/*!
\retval DLN_RES_SUCCESS - the frequency has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cMasterGetFrequency(HDLN handle, uint8_t port, uint32_t *frequency);

/*!
\retval DLN_RES_SUCCESS - the I2C master write opreration has been successfully performed;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_DISABLED - could not write while the I2C master module is disabled.
*/
DLN_RESULT DlnI2cMasterWrite(HDLN handle, uint8_t port, uint8_t slaveDeviceAddress, uint8_t memoryAddressLength, uint32_t memoryAddress, uint16_t bufferLength, uint8_t *buffer);

/*!
\retval DLN_RES_SUCCESS - the I2C master read opreration has been successfully performed;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_DISABLED - could not read while the I2C master module is disabled.
*/
DLN_RESULT DlnI2cMasterRead(HDLN handle, uint8_t port, uint8_t slaveDeviceAddress, uint8_t memoryAddressLength, uint32_t memoryAddress, uint16_t bufferLength, uint8_t *buffer);


/*!
\retval DLN_RES_SUCCESS - the I2C master scan opreration has been successfully performed;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_DISABLED - could not scan while the I2C master module is disabled;
\retval DLN_RES_BUSY - could not scan while the I2C master module is busy transferring.
*/
DLN_RESULT DlnI2cMasterScanDevices(HDLN handle, uint8_t port, uint8_t *addressCount, uint8_t *addressList);


/*!
\retval DLN_RES_SUCCESS - the I2C master transfer opreration has been successfully performed;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_DISABLED - could not perform transfer while the I2C master module is disabled;
\retval DLN_RES_INVALID_BUFFER_SIZE buffer size values are invalid.
*/
DLN_RESULT DlnI2cMasterTransfer(HDLN handle, uint8_t port, uint8_t slaveDeviceAddress, uint16_t writeLength, uint16_t readLength, uint8_t *writeBuffer, uint8_t *readBuffer);


/*!
\retval DLN_RES_SUCCESS - the maximum reply count has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_BUSY - could not change maximum reply count while the I2C master module is busy transferring;
\retval DLN_RES_INVALID_VALUE - zero value provided.
*/
DLN_RESULT DlnI2cMasterSetMaxReplyCount(HDLN handle, uint8_t port, uint16_t maxReplyCount);


/*!
\retval DLN_RES_SUCCESS - the maximum reply count has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
*/
DLN_RESULT DlnI2cMasterGetMaxReplyCount(HDLN handle, uint8_t port, uint16_t *maxReplyCount);


#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif //DLN_I2C_MASTER_H_INCLUDED
