#ifndef __DLN_SPI_FLASH_H__
#define __DLN_SPI_FLASH_H__

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


#define DLN_PIN_ROLE_SPI_FLASH_MISO     ((DLN_PIN_ROLE)1)
#define DLN_PIN_ROLE_SPI_FLASH_MOSI     ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_SPI_FLASH_SCLK     ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_SPI_FLASH_SS       ((DLN_PIN_ROLE)0)


#define DLN_MSG_ID_SPI_FLASH_GET_PORT_COUNT     DLN_BUILD_MSG_ID(0x00, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_ENABLE             DLN_BUILD_MSG_ID(0x01, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_DISABLE            DLN_BUILD_MSG_ID(0x02, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_IS_ENABLED         DLN_BUILD_MSG_ID(0x03, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_SET_FREQUENCY      DLN_BUILD_MSG_ID(0x04, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_GET_FREQUENCY      DLN_BUILD_MSG_ID(0x05, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_SET_SS             DLN_BUILD_MSG_ID(0x06, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_GET_SS             DLN_BUILD_MSG_ID(0x07, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_SET_SS_MASK        DLN_BUILD_MSG_ID(0x08, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_GET_SS_MASK        DLN_BUILD_MSG_ID(0x09, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_PROGRAM_PAGE       DLN_BUILD_MSG_ID(0x10, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_READ_PAGE          DLN_BUILD_MSG_ID(0x11, DLN_MODULE_SPI_FLASH)
#define DLN_MSG_ID_SPI_FLASH_COMMAND            DLN_BUILD_MSG_ID(0x12, DLN_MODULE_SPI_FLASH)


#define DLN_SPI_FLASH_ENABLED           1
#define DLN_SPI_FLASH_DISABLED          0

#define DLN_SPI_FLASH_TIMEOUT_NONE      0
#define DLN_SPI_FLASH_TIMEOUT_INFINITE  (~0)


typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_SPI_FLASH_GET_PORT_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_SPI_FLASH_GET_PORT_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_FLASH_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t conflict;
} __PACKED_ATTR DLN_SPI_FLASH_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_FLASH_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_FLASH_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_FLASH_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_FLASH_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t frequency;
} __PACKED_ATTR DLN_SPI_FLASH_SET_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_FLASH_SET_FREQUENCY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_FLASH_GET_FREQUENCY_CMD;


typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_SPI_FLASH_GET_FREQUENCY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t ss;
} __PACKED_ATTR DLN_SPI_FLASH_SET_SS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_FLASH_SET_SS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_FLASH_GET_SS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t ss;
} __PACKED_ATTR DLN_SPI_FLASH_GET_SS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t ssMask;
} __PACKED_ATTR DLN_SPI_FLASH_SET_SS_MASK_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_FLASH_SET_SS_MASK_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_FLASH_GET_SS_MASK_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t ssMask;
} __PACKED_ATTR DLN_SPI_FLASH_GET_SS_MASK_RSP;

#define DLN_SPI_FLASH_MAX_TRANSFER_SIZE 256
typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t address;
    uint16_t size;
    uint32_t timeout;
    uint8_t reserved;
    uint8_t buffer[DLN_SPI_FLASH_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_SPI_FLASH_PROGRAM_PAGE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_FLASH_PROGRAM_PAGE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint32_t address;
    uint16_t size;
} __PACKED_ATTR DLN_SPI_FLASH_READ_PAGE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t size;
    uint8_t buffer[DLN_SPI_FLASH_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_SPI_FLASH_READ_PAGE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint16_t txSize;
    uint16_t rxSize;
    uint32_t timeout;
    uint8_t reserved[3];
    uint8_t buffer[DLN_SPI_FLASH_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_SPI_FLASH_COMMAND_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t size;
    uint8_t buffer[DLN_SPI_FLASH_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_SPI_FLASH_COMMAND_RSP;


// HW functions
DLN_RESULT DlnSpiFlashGetPortCount(HDLN handle, uint8_t *count);
DLN_RESULT DlnSpiFlashEnable(HDLN handle, uint8_t port, uint16_t *conflict);
DLN_RESULT DlnSpiFlashDisable(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiFlashIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);
DLN_RESULT DlnSpiFlashSetFrequency(HDLN handle, uint8_t port, uint32_t frequency);
DLN_RESULT DlnSpiFlashGetFrequency(HDLN handle, uint8_t port, uint32_t *frequency);
DLN_RESULT DlnSpiFlashSetSS(HDLN handle, uint8_t port, uint8_t ss);
DLN_RESULT DlnSpiFlashGetSS(HDLN handle, uint8_t port, uint8_t *ss);
DLN_RESULT DlnSpiFlashSetSSMask(HDLN handle, uint8_t port, uint8_t ssMask);
DLN_RESULT DlnSpiFlashGetSSMask(HDLN handle, uint8_t port, uint8_t *ssMask);
DLN_RESULT DlnSpiFlashProgramPage(HDLN handle, uint8_t port, uint32_t address, uint8_t *buffer, uint16_t size, uint32_t timeout);
DLN_RESULT DlnSpiFlashReadPage(HDLN handle, uint8_t port, uint32_t address, uint8_t *buffer, uint16_t size);
DLN_RESULT DlnSpiFlashCommand(HDLN handle, uint8_t port, uint8_t *txBuffer, uint16_t txSize, uint8_t *rxBuffer, uint16_t rxSize, uint32_t timeout);

// Library functions
DLN_RESULT DlnSpiFlashGetID(HDLN handle, uint8_t port, uint32_t *id);
DLN_RESULT DlnSpiFlashErase(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiFlashProgram(HDLN handle, uint8_t port, uint32_t startAddress, uint8_t *buffer, uint16_t size);
DLN_RESULT DlnSpiFlashProgramVerify(HDLN handle, uint8_t port, uint32_t startAddress, uint8_t *buffer, uint16_t size);
DLN_RESULT DlnSpiFlashRead(HDLN handle, uint8_t port, uint32_t startAddress, uint8_t *buffer, uint16_t size);


#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif

#endif //__DLN_SPI_FLASH_H__
