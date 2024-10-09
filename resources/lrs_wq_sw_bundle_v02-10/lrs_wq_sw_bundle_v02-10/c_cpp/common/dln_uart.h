#ifndef DLN_UART_H
#define DLN_UART_H
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


#define DLN_PIN_ROLE_UART_TX        ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_UART_RX        ((DLN_PIN_ROLE)1)


#define DLN_MSG_ID_UART_GET_PORT_COUNT          DLN_BUILD_MSG_ID(0x00, DLN_MODULE_UART)

#define DLN_MSG_ID_UART_ENABLE                  DLN_BUILD_MSG_ID(0x01, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_DISABLE                 DLN_BUILD_MSG_ID(0x02, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_IS_ENABLED              DLN_BUILD_MSG_ID(0x03, DLN_MODULE_UART)

#define DLN_MSG_ID_UART_SET_BAUDRATE            DLN_BUILD_MSG_ID(0x10, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_BAUDRATE            DLN_BUILD_MSG_ID(0x11, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_SET_CHARACTER_LENGTH    DLN_BUILD_MSG_ID(0x12, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_CHARACTER_LENGTH    DLN_BUILD_MSG_ID(0x13, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_SET_PARITY              DLN_BUILD_MSG_ID(0x14, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_PARITY              DLN_BUILD_MSG_ID(0x15, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_SET_STOPBITS            DLN_BUILD_MSG_ID(0x16, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_STOPBITS            DLN_BUILD_MSG_ID(0x17, DLN_MODULE_UART)

#define DLN_MSG_ID_UART_WRITE                   DLN_BUILD_MSG_ID(0x20, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_READ                    DLN_BUILD_MSG_ID(0x21, DLN_MODULE_UART)

#define DLN_MSG_ID_UART_ENABLE_EVENT            DLN_BUILD_MSG_ID(0x30, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_DISABLE_EVENT           DLN_BUILD_MSG_ID(0x31, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_IS_EVENT_ENABLED        DLN_BUILD_MSG_ID(0x32, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_SET_EVENT_PERIOD        DLN_BUILD_MSG_ID(0x33, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_EVENT_PERIOD        DLN_BUILD_MSG_ID(0x34, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_SET_EVENT_SIZE          DLN_BUILD_MSG_ID(0x35, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_EVENT_SIZE          DLN_BUILD_MSG_ID(0x36, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_DATA_EV                 DLN_BUILD_MSG_ID(0xFF, DLN_MODULE_UART)

#define DLN_MSG_ID_UART_GET_MIN_BAUDRATE                DLN_BUILD_MSG_ID(0x40, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_MAX_BAUDRATE                DLN_BUILD_MSG_ID(0x41, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_SUPPORTED_CHARACTER_LENGTHS DLN_BUILD_MSG_ID(0x42, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_SUPPORTED_PARITIES          DLN_BUILD_MSG_ID(0x43, DLN_MODULE_UART)
#define DLN_MSG_ID_UART_GET_SUPPORTED_STOPBITS          DLN_BUILD_MSG_ID(0x44, DLN_MODULE_UART)



#define DLN_UART_DISABLED                       0
#define DLN_UART_ENABLED                        1

#define DLN_UART_CHARACTER_LENGTH_5             5
#define DLN_UART_CHARACTER_LENGTH_6             6
#define DLN_UART_CHARACTER_LENGTH_7             7
#define DLN_UART_CHARACTER_LENGTH_8             8
#define DLN_UART_CHARACTER_LENGTH_9             9

#define DLN_UART_PARITY_EVEN                    0
#define DLN_UART_PARITY_ODD                     1
#define DLN_UART_PARITY_SPACE                   2
#define DLN_UART_PARITY_MARK                    3
#define DLN_UART_PARITY_NONE                    4

#define DLN_UART_STOPBITS_1                     0
#define DLN_UART_STOPBITS_1_5                   1
#define DLN_UART_STOPBITS_2                     2

#define DLN_UART_EVENT_DISABLED                 0
#define DLN_UART_EVENT_ENABLED                  1

#define DLN_UART_MAX_TRANSFER_SIZE              256


typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_UART_GET_PORT_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_UART_GET_PORT_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t conflict;
} __PACKED_ATTR DLN_UART_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_UART_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t baudrate;
} __PACKED_ATTR DLN_UART_SET_BAUDRATE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t baudrate;
} __PACKED_ATTR DLN_UART_SET_BAUDRATE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_BAUDRATE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t baudrate;
} __PACKED_ATTR DLN_UART_GET_BAUDRATE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t characterLength;
} __PACKED_ATTR DLN_UART_SET_CHARACTER_LENGTH_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_SET_CHARACTER_LENGTH_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_CHARACTER_LENGTH_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t characterLength;
} __PACKED_ATTR DLN_UART_GET_CHARACTER_LENGTH_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t parity;
} __PACKED_ATTR DLN_UART_SET_PARITY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_SET_PARITY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_PARITY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t parity;
} __PACKED_ATTR DLN_UART_GET_PARITY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t stopbits;
} __PACKED_ATTR DLN_UART_SET_STOPBITS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_SET_STOPBITS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_STOPBITS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t stopbits;
} __PACKED_ATTR DLN_UART_GET_STOPBITS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t size;
    uint8_t attribute;
    uint8_t buffer[DLN_UART_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_UART_WRITE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_WRITE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t size;
} __PACKED_ATTR DLN_UART_READ_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t size;
    uint8_t buffer[DLN_UART_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_UART_READ_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_ENABLE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_ENABLE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_DISABLE_EVENT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_DISABLE_EVENT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_IS_EVENT_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_UART_IS_EVENT_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t period;
} __PACKED_ATTR DLN_UART_SET_EVENT_PERIOD_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_SET_EVENT_PERIOD_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_EVENT_PERIOD_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t period;
} __PACKED_ATTR DLN_UART_GET_EVENT_PERIOD_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t size;
} __PACKED_ATTR DLN_UART_SET_EVENT_SIZE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_UART_SET_EVENT_SIZE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_EVENT_SIZE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t size;
} __PACKED_ATTR DLN_UART_GET_EVENT_SIZE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint16_t eventCount;
    uint8_t port;
    uint16_t size;
    uint8_t attribute;
    uint8_t buffer[DLN_UART_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_UART_DATA_EV;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_MIN_BAUDRATE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t baudrate;
} __PACKED_ATTR DLN_UART_GET_MIN_BAUDRATE_RSP;

#define DLN_UART_GET_MAX_BAUDRATE_CMD   DLN_UART_GET_MIN_BAUDRATE_CMD
#define DLN_UART_GET_MAX_BAUDRATE_RSP   DLN_UART_GET_MIN_BAUDRATE_RSP


typedef struct
{
    uint8_t count;
    uint8_t lengths[8];
} __PACKED_ATTR DLN_UART_CHARACTER_LENGTHS;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_SUPPORTED_CHARACTER_LENGTHS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_UART_CHARACTER_LENGTHS supportedLengths;
} __PACKED_ATTR DLN_UART_GET_SUPPORTED_CHARACTER_LENGTHS_RSP;


typedef struct
{
    uint8_t count;
    uint8_t parities[8];
} __PACKED_ATTR DLN_UART_PARITIES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_SUPPORTED_PARITIES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_UART_PARITIES supportedParities;
} __PACKED_ATTR DLN_UART_GET_SUPPORTED_PARITIES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t stopbits[8];
} __PACKED_ATTR DLN_UART_STOPBITS;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_UART_GET_SUPPORTED_STOPBITS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_UART_STOPBITS supportedStopbits;
} __PACKED_ATTR DLN_UART_GET_SUPPORTED_STOPBITS_RSP;


DLN_RESULT DlnUartGetPortCount(HDLN handle, uint8_t *count);

DLN_RESULT DlnUartEnable(HDLN handle, uint8_t port, uint16_t *conflict);
DLN_RESULT DlnUartDisable(HDLN handle, uint8_t port);
DLN_RESULT DlnUartIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

DLN_RESULT DlnUartSetBaudrate(HDLN handle, uint8_t port, uint32_t baudrate, uint32_t *actualBaudrate);
DLN_RESULT DlnUartGetBaudrate(HDLN handle, uint8_t port, uint32_t *baudrate);

DLN_RESULT DlnUartSetCharacterLength(HDLN handle, uint8_t port, uint8_t characterLength);
DLN_RESULT DlnUartGetCharacterLength(HDLN handle, uint8_t port, uint8_t *characterLength);

DLN_RESULT DlnUartSetParity(HDLN handle, uint8_t port, uint8_t parity);
DLN_RESULT DlnUartGetParity(HDLN handle, uint8_t port, uint8_t *parity);

DLN_RESULT DlnUartSetStopbits(HDLN handle, uint8_t port, uint8_t stopbits);
DLN_RESULT DlnUartGetStopbits(HDLN handle, uint8_t port, uint8_t *stopbits);

DLN_RESULT DlnUartWrite(HDLN handle, uint8_t port, uint16_t size, uint8_t *buffer);
DLN_RESULT DlnUartRead(HDLN handle, uint8_t port, uint16_t size, uint8_t *buffer, uint16_t *actualSize);

DLN_RESULT DlnUartEnableEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnUartDisableEvent(HDLN handle, uint8_t port);
DLN_RESULT DlnUartIsEventEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

DLN_RESULT DlnUartSetEventPeriod(HDLN handle, uint8_t port, uint32_t period);
DLN_RESULT DlnUartGetEventPeriod(HDLN handle, uint8_t port, uint32_t *period);

DLN_RESULT DlnUartSetEventSize(HDLN handle, uint8_t port, uint16_t size);
DLN_RESULT DlnUartGetEventSize(HDLN handle, uint8_t port, uint16_t *size);

DLN_RESULT DlnUartGetMinBaudrate(HDLN handle, uint8_t port, uint32_t *minBaudrate);
DLN_RESULT DlnUartGetMaxBaudrate(HDLN handle, uint8_t port, uint32_t *maxBaudrate);

DLN_RESULT DlnUartGetSupportedCharacterLengths(HDLN handle, uint8_t port, DLN_UART_CHARACTER_LENGTHS *supportedLengths);
DLN_RESULT DlnUartGetSupportedParities(HDLN handle, uint8_t port, DLN_UART_PARITIES *supportedParities);
DLN_RESULT DlnUartGetSupportedStopbits(HDLN handle, uint8_t port, DLN_UART_STOPBITS *supportedStopbits);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif //DLN_UART_H
