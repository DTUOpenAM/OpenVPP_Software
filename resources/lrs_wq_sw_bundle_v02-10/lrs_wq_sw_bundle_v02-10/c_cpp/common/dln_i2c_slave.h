#ifndef DLN_I2C_SLAVE_H_INCLUDED
#define DLN_I2C_SLAVE_H_INCLUDED


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


#define DLN_PIN_ROLE_I2C_SLAVE_SDA     ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_I2C_SLAVE_SCL     ((DLN_PIN_ROLE)1)


#define DLN_MSG_ID_I2C_SLAVE_GET_PORT_COUNT             DLN_BUILD_MSG_ID(0x00, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_ENABLE                     DLN_BUILD_MSG_ID(0x01, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_DISABLE                    DLN_BUILD_MSG_ID(0x02, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_IS_ENABLED                 DLN_BUILD_MSG_ID(0x03, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_GET_ADDRESS_COUNT          DLN_BUILD_MSG_ID(0x04, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_SET_ADDRESS                DLN_BUILD_MSG_ID(0x05, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_GET_ADDRESS                DLN_BUILD_MSG_ID(0x06, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_GENERAL_CALL_ENABLE        DLN_BUILD_MSG_ID(0x07, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_GENERAL_CALL_DISABLE       DLN_BUILD_MSG_ID(0x08, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_GENERAL_CALL_IS_ENABLED    DLN_BUILD_MSG_ID(0x09, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_LOAD_REPLY                 DLN_BUILD_MSG_ID(0x0A, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_SET_EVENT                  DLN_BUILD_MSG_ID(0x0B, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_GET_EVENT                  DLN_BUILD_MSG_ID(0x0C, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_READ_EV                    DLN_BUILD_MSG_ID(0x10, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_WRITE_EV                   DLN_BUILD_MSG_ID(0x11, DLN_MODULE_I2C_SLAVE)
#define DLN_MSG_ID_I2C_SLAVE_GET_SUPPORTED_EVENT_TYPES  DLN_BUILD_MSG_ID(0x40, DLN_MODULE_I2C_SLAVE)

#define DLN_I2C_SLAVE_BUFFER_SIZE           256

#define DLN_I2C_SLAVE_ENABLED               1
#define DLN_I2C_SLAVE_DISABLED              0
#define DLN_I2C_SLAVE_CANCEL_TRANSFERS      0
#define DLN_I2C_SLAVE_WAIT_FOR_TRANSFERS    1

#define DLN_I2C_SLAVE_ADDRESS_DISABLED      0
#define DLN_I2C_SLAVE_GENERAL_CALL_ENABLED  1
#define DLN_I2C_SLAVE_GENERAL_CALL_DISABLED 0

#define DLN_I2C_SLAVE_EVENT_NONE            0
#define DLN_I2C_SLAVE_EVENT_READ            1
#define DLN_I2C_SLAVE_EVENT_WRITE           2
#define DLN_I2C_SLAVE_EVENT_READ_WRITE      3


typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_PORT_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_PORT_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_SLAVE_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t conflict;
} __PACKED_ATTR DLN_I2C_SLAVE_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t waitForTransferCompletion;
} __PACKED_ATTR DLN_I2C_SLAVE_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_SLAVE_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_SLAVE_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_I2C_SLAVE_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_ADDRESS_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_ADDRESS_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t slaveAddressNumber;
    uint8_t address;
} __PACKED_ATTR DLN_I2C_SLAVE_SET_ADDRESS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_SLAVE_SET_ADDRESS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t slaveAddressNumber;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_ADDRESS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t address;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_ADDRESS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_SLAVE_GENERAL_CALL_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_SLAVE_GENERAL_CALL_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_SLAVE_GENERAL_CALL_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_SLAVE_GENERAL_CALL_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_SLAVE_GENERAL_CALL_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_I2C_SLAVE_GENERAL_CALL_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t size;
    uint8_t buffer[DLN_I2C_SLAVE_BUFFER_SIZE];
} __PACKED_ATTR DLN_I2C_SLAVE_LOAD_REPLY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_SLAVE_LOAD_REPLY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t slaveAddressNumber;
    uint8_t eventType;
} __PACKED_ATTR DLN_I2C_SLAVE_SET_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_I2C_SLAVE_SET_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t slaveAddressNumber;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t eventType;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint16_t eventCount;
    uint8_t  eventType;
    uint8_t port;
    uint8_t slaveAddress;
    uint16_t size;
} __PACKED_ATTR DLN_I2C_SLAVE_READ_EV;

typedef struct
{
    DLN_MSG_HEADER header;
    uint16_t eventCount;
    uint8_t  eventType;
    uint8_t port;
    uint8_t slaveAddress;
    uint16_t size;
    uint8_t buffer[DLN_I2C_SLAVE_BUFFER_SIZE];
} __PACKED_ATTR DLN_I2C_SLAVE_WRITE_EV;


typedef struct
{
    uint8_t count;
    uint8_t eventTypes[8];
} __PACKED_ATTR DLN_I2C_SLAVE_EVENT_TYPES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_SUPPORTED_EVENT_TYPES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_I2C_SLAVE_EVENT_TYPES supportedEventTypes;
} __PACKED_ATTR DLN_I2C_SLAVE_GET_SUPPORTED_EVENT_TYPES_RSP;


/*!
\retval DLN_RES_SUCCESS - the port count has been successfully retrieved.
*/
DLN_RESULT DlnI2cSlaveGetPortCount(HDLN handle, uint8_t *count);

/*!
\retval DLN_RES_SUCCESS - the I2C slave module has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_PIN_IN_USE - the I2C pins are assigned to another module of the adapter and cannot be enabled as I2C;
\retval DLN_RES_I2C_SLAVE_ADDRESS_NEEDED - I2C slave address must be set before enabling.
*/
DLN_RESULT DlnI2cSlaveEnable(HDLN handle, uint8_t port, uint16_t *conflict);

/*!
\retval DLN_RES_SUCCESS - the I2C slave module has been successfully disabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_TRANSFER_CANCELLED - the pending transfers were cancelled.
*/
DLN_RESULT DlnI2cSlaveDisable(HDLN handle, uint8_t port, uint8_t waitForTransferCompletion);

/*!
\retval DLN_RES_SUCCESS - the I2C slave state has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cSlaveIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

/*!
\retval DLN_RES_SUCCESS - the I2C slave address count has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cSlaveGetAddressCount(HDLN handle, uint8_t port, uint8_t *count);

/*!
\retval DLN_RES_SUCCESS - the I2C slave address has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_BUSY - could not change address while the I2C slave module is enabled;
\retval DLN_RES_INVALID_ADDRESS - the address is out of range.
*/
DLN_RESULT DlnI2cSlaveSetAddress(HDLN handle, uint8_t port, uint8_t slaveAddressNumber, uint8_t address);

/*!
\retval DLN_RES_SUCCESS - the I2C slave address has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
*/
DLN_RESULT DlnI2cSlaveGetAddress(HDLN handle, uint8_t port, uint8_t slaveAddressNumber, uint8_t *address);

/*!
\retval DLN_RES_SUCCESS - the I2C slave general call has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cSlaveGeneralCallEnable(HDLN handle, uint8_t port);

/*!
\retval DLN_RES_SUCCESS - the I2C slave general call has been successfully disabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cSlaveGeneralCallDisable(HDLN handle, uint8_t port);

/*!
\retval DLN_RES_SUCCESS - the I2C slave general call state has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
*/
DLN_RESULT DlnI2cSlaveGeneralCallIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

/*!
\retval DLN_RES_SUCCESS - the I2C slave reply has been successfully loaded;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_BUSY - could not load reply while the I2C slave module is enabled;
\retval DLN_RES_INVALID_BUFFER_SIZE - the buffer size is out of range.
*/
DLN_RESULT DlnI2cSlaveLoadReply(HDLN handle, uint8_t port, uint16_t size, uint8_t *buffer);

/*!
\retval DLN_RES_SUCCESS - the I2C slave event has been successfully configured;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_BUSY - could not configure event while the I2C slave module is enabled;
\retval DLN_RES_INVALID_EVENT_TYPE - the event type is out of range.
*/
DLN_RESULT DlnI2cSlaveSetEvent(HDLN handle, uint8_t port, uint8_t slaveAddressNumber, uint8_t eventType);

/*!
\retval DLN_RES_SUCCESS - the I2C slave event state has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnI2cSlaveGetEvent(HDLN handle, uint8_t port, uint8_t slaveAddressNumber, uint8_t *eventType);

DLN_RESULT DlnI2cSlaveGetSupportedEventTypes(HDLN handle, uint8_t port, DLN_I2C_SLAVE_EVENT_TYPES *supportedEventTypes);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif //DLN_I2C_SLAVE_H_INCLUDED
