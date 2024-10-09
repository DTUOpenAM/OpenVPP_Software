#ifndef DLN_SPI_SLAVE_H
#define DLN_SPI_SLAVE_H
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


#define DLN_PIN_ROLE_SPI_SLAVE_MISO     ((DLN_PIN_ROLE)1)
#define DLN_PIN_ROLE_SPI_SLAVE_MOSI     ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_SPI_SLAVE_SCLK     ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_SPI_SLAVE_SS       ((DLN_PIN_ROLE)0)


#define DLN_MSG_ID_SPI_SLAVE_GET_PORT_COUNT     DLN_BUILD_MSG_ID(0x00, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_ENABLE             DLN_BUILD_MSG_ID(0x01, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_DISABLE            DLN_BUILD_MSG_ID(0x02, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_IS_ENABLED         DLN_BUILD_MSG_ID(0x03, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_MODE           DLN_BUILD_MSG_ID(0x04, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_MODE           DLN_BUILD_MSG_ID(0x05, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_FRAME_SIZE     DLN_BUILD_MSG_ID(0x06, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_FRAME_SIZE     DLN_BUILD_MSG_ID(0x07, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_LOAD_REPLY         DLN_BUILD_MSG_ID(0x08, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_REPLY_SHORTAGE_ACTION      DLN_BUILD_MSG_ID(0x0B, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_REPLY_SHORTAGE_ACTION      DLN_BUILD_MSG_ID(0x0C, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_ENQUEUE_REPLY      DLN_BUILD_MSG_ID(0x0D, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_REPLY_MODE     DLN_BUILD_MSG_ID(0x0E, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_REPLY_MODE     DLN_BUILD_MSG_ID(0x0F, DLN_MODULE_SPI_SLAVE)

#define DLN_MSG_ID_SPI_SLAVE_DATA_RECEIVED_EV   DLN_BUILD_MSG_ID(0x10, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_TRANSFER_EV        DLN_MSG_ID_SPI_SLAVE_DATA_RECEIVED_EV

#define DLN_MSG_ID_SPI_SLAVE_ENABLE_EVENT               DLN_BUILD_MSG_ID(0x11, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_DISABLE_EVENT              DLN_BUILD_MSG_ID(0x12, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_IS_EVENT_ENABLED           DLN_BUILD_MSG_ID(0x13, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_EVENT_SIZE             DLN_BUILD_MSG_ID(0x14, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_EVENT_SIZE             DLN_BUILD_MSG_ID(0x15, DLN_MODULE_SPI_SLAVE)

#define DLN_MSG_ID_SPI_SLAVE_SET_CPOL                   DLN_BUILD_MSG_ID(0x16, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_CPOL                   DLN_BUILD_MSG_ID(0x17, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_CPHA                   DLN_BUILD_MSG_ID(0x18, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_CPHA                   DLN_BUILD_MSG_ID(0x19, DLN_MODULE_SPI_SLAVE)

#define DLN_MSG_ID_SPI_SLAVE_ENABLE_SS_RISE_EVENT       DLN_BUILD_MSG_ID(0x1A, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_DISABLE_SS_RISE_EVENT      DLN_BUILD_MSG_ID(0x1B, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_IS_SS_RISE_EVENT_ENABLED   DLN_BUILD_MSG_ID(0x1C, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_SS_IDLE_TIMEOUT        DLN_BUILD_MSG_ID(0x1D, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_SS_IDLE_TIMEOUT        DLN_BUILD_MSG_ID(0x1E, DLN_MODULE_SPI_SLAVE)

#define DLN_MSG_ID_SPI_SLAVE_ENABLE_IDLE_EVENT          DLN_BUILD_MSG_ID(0x1F, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_DISABLE_IDLE_EVENT         DLN_BUILD_MSG_ID(0x20, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_IS_IDLE_EVENT_ENABLED      DLN_BUILD_MSG_ID(0x21, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_SET_IDLE_EVENT_TIMEOUT     DLN_BUILD_MSG_ID(0x22, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_IDLE_EVENT_TIMEOUT     DLN_BUILD_MSG_ID(0x23, DLN_MODULE_SPI_SLAVE)

#define DLN_MSG_ID_SPI_SLAVE_GET_SUPPORTED_MODES        DLN_BUILD_MSG_ID(0x40, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_SUPPORTED_FRAME_SIZES  DLN_BUILD_MSG_ID(0x41, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_SUPPORTED_CPOL_VALUES  DLN_BUILD_MSG_ID(0x42, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_SUPPORTED_CPHA_VALUES  DLN_BUILD_MSG_ID(0x43, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_SUPPORTED_SHORTAGE_ACTIONS DLN_BUILD_MSG_ID(0x44, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_SUPPORTED_EVENT_TYPES  DLN_BUILD_MSG_ID(0x45, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_SUPPORTED_REPLY_MODES  DLN_BUILD_MSG_ID(0x46, DLN_MODULE_SPI_SLAVE)

#define DLN_MSG_ID_SPI_SLAVE_GET_MIN_IDLE_EVENT_TIMEOUT DLN_BUILD_MSG_ID(0x47, DLN_MODULE_SPI_SLAVE)
#define DLN_MSG_ID_SPI_SLAVE_GET_MAX_IDLE_EVENT_TIMEOUT DLN_BUILD_MSG_ID(0x48, DLN_MODULE_SPI_SLAVE)



#define DLN_SPI_SLAVE_BUFFER_SIZE               256

#define DLN_SPI_SLAVE_ENABLED                   1
#define DLN_SPI_SLAVE_DISABLED                  0
#define DLN_SPI_SLAVE_CANCEL_TRANSFERS          0
#define DLN_SPI_SLAVE_WAIT_FOR_TRANSFERS        1

#define DLN_SPI_SLAVE_CPHA_BIT                  (1 << 0)
#define DLN_SPI_SLAVE_CPHA_0                    (0 << 0)
#define DLN_SPI_SLAVE_CPHA_1                    (1 << 0)
#define DLN_SPI_SLAVE_CPOL_BIT                  (1 << 1)
#define DLN_SPI_SLAVE_CPOL_0                    (0 << 1)
#define DLN_SPI_SLAVE_CPOL_1                    (1 << 1)

#define DLN_SPI_SLAVE_FRAME_SIZE_8              8
#define DLN_SPI_SLAVE_FRAME_SIZE_9              9
#define DLN_SPI_SLAVE_FRAME_SIZE_10             10
#define DLN_SPI_SLAVE_FRAME_SIZE_11             11
#define DLN_SPI_SLAVE_FRAME_SIZE_12             12
#define DLN_SPI_SLAVE_FRAME_SIZE_13             13
#define DLN_SPI_SLAVE_FRAME_SIZE_14             14
#define DLN_SPI_SLAVE_FRAME_SIZE_15             15
#define DLN_SPI_SLAVE_FRAME_SIZE_16             16

#define DLN_SPI_SLAVE_EVENT_ENABLED             1
#define DLN_SPI_SLAVE_EVENT_DISABLED            0

#define DLN_SPI_SLAVE_EVENT_NONE                0
#define DLN_SPI_SLAVE_EVENT_SS_RISE             1
#define DLN_SPI_SLAVE_EVENT_BUFFER_FULL         2
#define DLN_SPI_SLAVE_EVENT_IDLE                3

#define DLN_SPI_SLAVE_REPLY_SHORTAGE_SEND_ZEROES    0
#define DLN_SPI_SLAVE_REPLY_SHORTAGE_REUSE          1

#define DLN_SPI_SLAVE_REPLY_MODE_OFF           0
#define DLN_SPI_SLAVE_REPLY_MODE_SS_BASED       1
#define DLN_SPI_SLAVE_REPLY_MODE_COUNT_BASED    2

#define DLN_SPI_SLAVE_SS_IDLE_TIMEOUT_MIN       1
#define DLN_SPI_SLAVE_SS_IDLE_TIMEOUT_MAX       1000


typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_PORT_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_PORT_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t conflict;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t waitForTransferCompletion;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t mode;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_MODE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_MODE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_MODE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t mode;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_MODE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t frameSize;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_FRAME_SIZE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_FRAME_SIZE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_FRAME_SIZE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t frameSize;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_FRAME_SIZE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t size;
    uint8_t attribute;  // reserved
    uint8_t buffer[DLN_SPI_SLAVE_BUFFER_SIZE];
} __PACKED_ATTR DLN_SPI_SLAVE_ENQUEUE_REPLY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_ENQUEUE_REPLY_RSP;

#define DLN_SPI_SLAVE_LOAD_REPLY_CMD    DLN_SPI_SLAVE_ENQUEUE_REPLY_CMD
#define DLN_SPI_SLAVE_LOAD_REPLY_RSP    DLN_SPI_SLAVE_ENQUEUE_REPLY_RSP


//typedef struct
//{
//    DLN_MSG_HEADER header;
//    uint8_t port;
//    uint8_t eventType;
//    uint16_t bufferSize;
//} __PACKED_ATTR DLN_SPI_SLAVE_SET_EVENT_CMD;
//
//typedef struct
//{
//    DLN_MSG_HEADER header;
//    DLN_RESULT result;
//} __PACKED_ATTR DLN_SPI_SLAVE_SET_EVENT_RSP;
//
//
//typedef struct
//{
//    DLN_MSG_HEADER header;
//    uint8_t port;
//} __PACKED_ATTR DLN_SPI_SLAVE_GET_EVENT_CMD;
//
//typedef struct
//{
//    DLN_MSG_HEADER header;
//    DLN_RESULT result;
//    uint8_t eventType;
//    uint16_t bufferSize;
//} __PACKED_ATTR DLN_SPI_SLAVE_GET_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t action;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_REPLY_SHORTAGE_ACTION_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_REPLY_SHORTAGE_ACTION_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_REPLY_SHORTAGE_ACTION_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t action;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_REPLY_SHORTAGE_ACTION_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t replyMode;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_REPLY_MODE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_REPLY_MODE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_REPLY_MODE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t replyMode;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_REPLY_MODE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint16_t eventCount;
    uint8_t  eventType;
    uint8_t port;
    uint16_t size;
    uint8_t buffer[DLN_SPI_SLAVE_BUFFER_SIZE];
} __PACKED_ATTR DLN_SPI_SLAVE_DATA_RECEIVED_EV;

#define DLN_SPI_SLAVE_TRANSFER_EV DLN_SPI_SLAVE_DATA_RECEIVED_EV


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_EVENT_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_EVENT_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t size;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_EVENT_SIZE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_EVENT_SIZE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_EVENT_SIZE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t size;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_EVENT_SIZE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t cpol;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_CPOL_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_CPOL_RSP;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_CPOL_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t cpol;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_CPOL_RSP;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t cpha;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_CPHA_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_CPHA_RSP;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_CPHA_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t cpha;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_CPHA_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_SS_RISE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_SS_RISE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_SS_RISE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_SS_RISE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_SS_RISE_EVENT_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_SS_RISE_EVENT_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t timeout;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_SS_IDLE_TIMEOUT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_SS_IDLE_TIMEOUT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SS_IDLE_TIMEOUT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t timeout;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SS_IDLE_TIMEOUT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_IDLE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_ENABLE_IDLE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_IDLE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_DISABLE_IDLE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_IDLE_EVENT_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_SLAVE_IS_IDLE_EVENT_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t timeout;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_IDLE_EVENT_TIMEOUT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_SLAVE_SET_IDLE_EVENT_TIMEOUT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_IDLE_EVENT_TIMEOUT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t timeout;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_IDLE_EVENT_TIMEOUT_RSP;


#define DLN_SPI_SLAVE_GET_MIN_IDLE_EVENT_TIMEOUT_CMD    DLN_SPI_SLAVE_GET_IDLE_EVENT_TIMEOUT_CMD
#define DLN_SPI_SLAVE_GET_MAX_IDLE_EVENT_TIMEOUT_CMD    DLN_SPI_SLAVE_GET_IDLE_EVENT_TIMEOUT_CMD
#define DLN_SPI_SLAVE_GET_MIN_IDLE_EVENT_TIMEOUT_RSP    DLN_SPI_SLAVE_GET_IDLE_EVENT_TIMEOUT_RSP
#define DLN_SPI_SLAVE_GET_MAX_IDLE_EVENT_TIMEOUT_RSP    DLN_SPI_SLAVE_GET_IDLE_EVENT_TIMEOUT_RSP


typedef struct
{
    uint8_t count;
    uint8_t values[4];
} __PACKED_ATTR DLN_SPI_SLAVE_MODE_VALUES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_MODES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_SLAVE_MODE_VALUES values;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_MODES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t values[2];
} __PACKED_ATTR DLN_SPI_SLAVE_CPOL_VALUES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_CPOL_VALUES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_SLAVE_CPOL_VALUES values;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_CPOL_VALUES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t values[2];
} __PACKED_ATTR DLN_SPI_SLAVE_CPHA_VALUES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_CPHA_VALUES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_SLAVE_CPHA_VALUES values;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_CPHA_VALUES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t frameSizes[36];
} __PACKED_ATTR DLN_SPI_SLAVE_FRAME_SIZES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_FRAME_SIZES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_SLAVE_FRAME_SIZES supportedSizes;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_FRAME_SIZES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t actions[10];
} __PACKED_ATTR DLN_SPI_SLAVE_SHORTAGE_ACTIONS;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_SHORTAGE_ACTIONS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_SLAVE_SHORTAGE_ACTIONS supportedActions;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_SHORTAGE_ACTIONS_RSP;


typedef struct
{
    uint8_t count;
    uint8_t eventTypes[8];
} __PACKED_ATTR DLN_SPI_SLAVE_EVENT_TYPES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_EVENT_TYPES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_SLAVE_EVENT_TYPES supportedEventTypes;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_EVENT_TYPES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t replyModes[8];
} __PACKED_ATTR DLN_SPI_SLAVE_REPLY_MODES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_REPLY_MODES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_SLAVE_REPLY_MODES supportedReplyModes;
} __PACKED_ATTR DLN_SPI_SLAVE_GET_SUPPORTED_REPLY_MODES_RSP;


/*!
\retval DLN_RES_SUCCESS - the port count has been successfully retrieved.
*/
DLN_RESULT DlnSpiSlaveGetPortCount(HDLN handle, uint8_t *count);

/*!
\retval DLN_RES_SUCCESS - the SPI slave module has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_PIN_IN_USE - the SPI pins are assigned to another module of the adapter and cannot be enabled as SPI.
*/
DLN_RESULT DlnSpiSlaveEnable(HDLN handle, uint8_t port, uint16_t *conflict);

/*!
\retval DLN_RES_SUCCESS - the SPI slave module has been successfully disabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_TRANSFER_CANCELLED - the pending transfers were cancelled.
*/
DLN_RESULT DlnSpiSlaveDisable(HDLN handle, uint8_t port, uint8_t waitForTransferCompletion);

/*!
\retval DLN_RES_SUCCESS - the SPI slave state has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiSlaveIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

/*!
\retval DLN_RES_SUCCESS - the SPI slave port mode has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_MUST_BE_DISABLED - could not change mode while the SPI slave module is enabled.
\retval DLN_RES_INVALID_MODE - invalid value is provided as mode parameter.
    Use DlnSpiSlaveGetSupportedModes() function to check supported modes for
    current SPI Slave port.
*/
DLN_RESULT DlnSpiSlaveSetMode(HDLN handle, uint8_t port, uint8_t mode);

/*!
\retval DLN_RES_SUCCESS - the SPI slave port mode has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiSlaveGetMode(HDLN handle, uint8_t port, uint8_t *mode);

/*!
\retval DLN_RES_SUCCESS - the SPI slave port frame size has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_SPI_INVALID_FRAME_SIZE - the frame size is out of range;
\retval DLN_RES_BUSY - could not change frame size while the SPI slave module is enabled.
*/
DLN_RESULT DlnSpiSlaveSetFrameSize(HDLN handle, uint8_t port, uint8_t frameSize);

/*!
\retval DLN_RES_SUCCESS - the SPI slave port frame size has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiSlaveGetFrameSize(HDLN handle, uint8_t port, uint8_t *frameSize);


DLN_RESULT DlnSpiSlaveGetSupportedFrameSizes(HDLN handle, uint8_t port, DLN_SPI_SLAVE_FRAME_SIZES *supportedSizes);

/*!
\retval DLN_RES_SUCCESS - the SPI slave reply has been successfully loaded;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_BUSY - could not load reply while the SPI slave module is enabled;
\retval DLN_RES_INVALID_BUFFER_SIZE - the buffer size is out of range.
*/
DLN_RESULT DlnSpiSlaveLoadReply(HDLN handle, uint8_t port, uint16_t size, uint8_t *buffer);

/*!
\retval DLN_RES_SUCCESS - the SPI slave event has been successfully configured;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_BUSY - could not configure event while the SPI slave module is enabled;
\retval DLN_RES_INVALID_EVENT_TYPE - the event type is out of range;
\retval DLN_RES_INVALID_BUFFER_SIZE - the buffer size is out of range.
*/
//DLN_RESULT DlnSpiSlaveSetEvent(HDLN handle, uint8_t port, uint8_t eventType, uint16_t bufferSize);

/*!
\retval DLN_RES_SUCCESS - the SPI slave event state has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
//DLN_RESULT DlnSpiSlaveGetEvent(HDLN handle, uint8_t port, uint8_t *eventType, uint16_t *bufferSize);

DLN_RESULT DlnSpiSlaveEnableEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiSlaveDisableEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiSlaveIsEventEnabled(HDLN handle, uint8_t port, uint8_t *enabled);
DLN_RESULT DlnSpiSlaveSetEventSize(HDLN handle, uint8_t port, uint16_t size);
DLN_RESULT DlnSpiSlaveGetEventSize(HDLN handle, uint8_t port, uint16_t *size);

/*!
\retval DLN_RES_SUCCESS - the SPI slave CPOL configuratin values has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_MUST_BE_DISABLED - could not change CPOL value while the SPI slave module is enabled.
\retval DLN_RES_INVALID_CPOL- - invalid value is provided as cpol parameter.
    Use DlnSpiSlaveGetSupportedCpolValues() function to check supported CPOL values for
    current SPI Slave port.
*/
DLN_RESULT DlnSpiSlaveSetCpol(HDLN handle, uint8_t port, uint8_t cpol);
/*!
\retval DLN_RES_SUCCESS
*/
DLN_RESULT DlnSpiSlaveGetCpol(HDLN handle, uint8_t port, uint8_t *cpol);
/*!
\retval DLN_RES_SUCCESS - the SPI slave port mode has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_MUST_BE_DISABLED - could not change CPHA value while the SPI slave module is enabled.
\retval DLN_RES_INVALID_CPHA - - invalid value is provided as cpha parameter.
    Use DlnSpiSlaveGetSupportedCphaValues() function to check supported CPHA values for
    current SPI Slave port.
*/
DLN_RESULT DlnSpiSlaveSetCpha(HDLN handle, uint8_t port, uint8_t cpha);
/*!
\retval DLN_RES_SUCCESS
*/
DLN_RESULT DlnSpiSlaveGetCpha(HDLN handle, uint8_t port, uint8_t *cpha);

DLN_RESULT DlnSpiSlaveEnableSSRiseEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiSlaveDisableSSRiseEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiSlaveIsSSRiseEventEnabled(HDLN handle, uint8_t port, uint8_t *enabled);
DLN_RESULT DlnSpiSlaveSetSSIdleTimeout(HDLN handle, uint8_t port, uint32_t timeout);
DLN_RESULT DlnSpiSlaveGetSSIdleTimeout(HDLN handle, uint8_t port, uint32_t *timeout);

DLN_RESULT DlnSpiSlaveGetSupportedFrameSizes(HDLN handle, uint8_t port, DLN_SPI_SLAVE_FRAME_SIZES *supportedSizes);
DLN_RESULT DlnSpiSlaveSetReplyShortageAction(HDLN handle, uint8_t port, uint8_t action);
DLN_RESULT DlnSpiSlaveGetReplyShortageAction(HDLN handle, uint8_t port, uint8_t *action);
DLN_RESULT DlnSpiSlaveEnqueueReply(HDLN handle, uint8_t port, uint16_t size, uint8_t *buffer);


DLN_RESULT DlnSpiSlaveGetSupportedModes(HDLN handle, uint8_t port, DLN_SPI_SLAVE_MODE_VALUES *values);
DLN_RESULT DlnSpiSlaveGetSupportedCpolValues(HDLN handle, uint8_t port, DLN_SPI_SLAVE_CPOL_VALUES *values);
DLN_RESULT DlnSpiSlaveGetSupportedCphaValues(HDLN handle, uint8_t port, DLN_SPI_SLAVE_CPHA_VALUES *values);

DLN_RESULT DlnSpiSlaveGetSupportedShortageActions(HDLN handle, uint8_t port, DLN_SPI_SLAVE_SHORTAGE_ACTIONS *supportedSizes);

DLN_RESULT DlnSpiSlaveSetReplyMode(HDLN handle, uint8_t port, uint8_t replyMode);
DLN_RESULT DlnSpiSlaveGetReplyMode(HDLN handle, uint8_t port, uint8_t *replyMode);

DLN_RESULT DlnSpiSlaveGetSupportedReplyModes(HDLN handle, uint8_t port, DLN_SPI_SLAVE_REPLY_MODES *supportedReplyModes);


DLN_RESULT DlnSpiSlaveEnableIdleEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiSlaveDisableIdleEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiSlaveIsIdleEventEnabled(HDLN handle, uint8_t port, uint8_t *enabled);
DLN_RESULT DlnSpiSlaveSetIdleEventTimeout(HDLN handle, uint8_t port, uint32_t timeout);
DLN_RESULT DlnSpiSlaveGetIdleEventTimeout(HDLN handle, uint8_t port, uint32_t *timeout);
DLN_RESULT DlnSpiSlaveGetMinIdleEventTimeout(HDLN handle, uint8_t port, uint32_t *timeout);
DLN_RESULT DlnSpiSlaveGetMaxIdleEventTimeout(HDLN handle, uint8_t port, uint32_t *timeout);


#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif // DLN_SPI_SLAVE_H
