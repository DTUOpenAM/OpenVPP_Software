#ifndef DLN_SPI_MASTER_H
#define DLN_SPI_MASTER_H
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


#define DLN_PIN_ROLE_SPI_MASTER_MISO  ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_SPI_MASTER_MOSI  ((DLN_PIN_ROLE)1)
#define DLN_PIN_ROLE_SPI_MASTER_SCLK  ((DLN_PIN_ROLE)1)
#define DLN_PIN_ROLE_SPI_MASTER_SS    ((DLN_PIN_ROLE)1)


// SPI command list
#define DLN_MSG_ID_SPI_MASTER_GET_PORT_COUNT                DLN_BUILD_MSG_ID(0x00, DLN_MODULE_SPI_MASTER)
// Enable, disable
#define DLN_MSG_ID_SPI_MASTER_ENABLE                        DLN_BUILD_MSG_ID(0x11, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_DISABLE                       DLN_BUILD_MSG_ID(0x12, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_IS_ENABLED                    DLN_BUILD_MSG_ID(0x13, DLN_MODULE_SPI_MASTER)
// CPOL + CPHA
#define DLN_MSG_ID_SPI_MASTER_SET_MODE                      DLN_BUILD_MSG_ID(0x14, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MODE                      DLN_BUILD_MSG_ID(0x15, DLN_MODULE_SPI_MASTER)
// Transfer size
#define DLN_MSG_ID_SPI_MASTER_SET_FRAME_SIZE                DLN_BUILD_MSG_ID(0x16, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_FRAME_SIZE                DLN_BUILD_MSG_ID(0x17, DLN_MODULE_SPI_MASTER)
// Frequency
#define DLN_MSG_ID_SPI_MASTER_SET_FREQUENCY                 DLN_BUILD_MSG_ID(0x18, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_FREQUENCY                 DLN_BUILD_MSG_ID(0x19, DLN_MODULE_SPI_MASTER)
// Transfer
#define DLN_MSG_ID_SPI_MASTER_READ_WRITE                    DLN_BUILD_MSG_ID(0x1A, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_READ                          DLN_BUILD_MSG_ID(0x1B, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_WRITE                         DLN_BUILD_MSG_ID(0x1C, DLN_MODULE_SPI_MASTER)
// Delays
#define DLN_MSG_ID_SPI_MASTER_SET_DELAY_BETWEEN_SS          DLN_BUILD_MSG_ID(0x20, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_DELAY_BETWEEN_SS          DLN_BUILD_MSG_ID(0x21, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SET_DELAY_AFTER_SS            DLN_BUILD_MSG_ID(0x22, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_DELAY_AFTER_SS            DLN_BUILD_MSG_ID(0x23, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SET_DELAY_BETWEEN_FRAMES      DLN_BUILD_MSG_ID(0x24, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_DELAY_BETWEEN_FRAMES      DLN_BUILD_MSG_ID(0x25, DLN_MODULE_SPI_MASTER)
// SS control
#define DLN_MSG_ID_SPI_MASTER_SET_SS                        DLN_BUILD_MSG_ID(0x26, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_SS                        DLN_BUILD_MSG_ID(0x27, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_RELEASE_SS                    DLN_BUILD_MSG_ID(0x28, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_VARIABLE_ENABLE            DLN_BUILD_MSG_ID(0x2B, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_VARIABLE_DISABLE           DLN_BUILD_MSG_ID(0x2C, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_VARIABLE_IS_ENABLED        DLN_BUILD_MSG_ID(0x2D, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_AAT_ENABLE                 DLN_BUILD_MSG_ID(0x2E, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_AAT_DISABLE                DLN_BUILD_MSG_ID(0x2F, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_AAT_IS_ENABLED             DLN_BUILD_MSG_ID(0x30, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_BETWEEN_FRAMES_ENABLE      DLN_BUILD_MSG_ID(0x31, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_BETWEEN_FRAMES_DISABLE     DLN_BUILD_MSG_ID(0x32, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_BETWEEN_FRAMES_IS_ENABLED  DLN_BUILD_MSG_ID(0x33, DLN_MODULE_SPI_MASTER)

#define DLN_MSG_ID_SPI_MASTER_SET_CPHA                      DLN_BUILD_MSG_ID(0x34, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_CPHA                      DLN_BUILD_MSG_ID(0x35, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SET_CPOL                      DLN_BUILD_MSG_ID(0x36, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_CPOL                      DLN_BUILD_MSG_ID(0x37, DLN_MODULE_SPI_MASTER)

#define DLN_MSG_ID_SPI_MASTER_SS_MULTI_ENABLE               DLN_BUILD_MSG_ID(0x38, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_MULTI_DISABLE              DLN_BUILD_MSG_ID(0x39, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_SS_MULTI_IS_ENABLED           DLN_BUILD_MSG_ID(0x3A, DLN_MODULE_SPI_MASTER)

#define DLN_MSG_ID_SPI_MASTER_GET_SUPPORTED_MODES           DLN_BUILD_MSG_ID(0x40, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_SUPPORTED_CPHA_VALUES     DLN_BUILD_MSG_ID(0x41, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_SUPPORTED_CPOL_VALUES     DLN_BUILD_MSG_ID(0x42, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_SUPPORTED_FRAME_SIZES     DLN_BUILD_MSG_ID(0x43, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_SS_COUNT                  DLN_BUILD_MSG_ID(0x44, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MIN_FREQUENCY             DLN_BUILD_MSG_ID(0x45, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MAX_FREQUENCY             DLN_BUILD_MSG_ID(0x46, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS      DLN_BUILD_MSG_ID(0x47, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MAX_DELAY_BETWEEN_SS      DLN_BUILD_MSG_ID(0x48, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MIN_DELAY_AFTER_SS        DLN_BUILD_MSG_ID(0x49, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MAX_DELAY_AFTER_SS        DLN_BUILD_MSG_ID(0x4A, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MIN_DELAY_BETWEEN_FRAMES  DLN_BUILD_MSG_ID(0x4B, DLN_MODULE_SPI_MASTER)
#define DLN_MSG_ID_SPI_MASTER_GET_MAX_DELAY_BETWEEN_FRAMES  DLN_BUILD_MSG_ID(0x4C, DLN_MODULE_SPI_MASTER)




// SPI definitions

// Enabled
#define DLN_SPI_MASTER_ENABLED                  1
#define DLN_SPI_MASTER_DISABLED                 0
// SPI disable
#define DLN_SPI_MASTER_CANCEL_TRANSFERS         0
#define DLN_SPI_MASTER_WAIT_FOR_TRANSFERS       1
// Mode: CPHA
#define DLN_SPI_MASTER_CPHA_BIT                 (1 << 0)
#define DLN_SPI_MASTER_CPHA_0                   (0 << 0)
#define DLN_SPI_MASTER_CPHA_1                   (1 << 0)
// Mode: CPOL
#define DLN_SPI_MASTER_CPOL_BIT                 (1 << 1)
#define DLN_SPI_MASTER_CPOL_0                   (0 << 1)
#define DLN_SPI_MASTER_CPOL_1                   (1 << 1)
// Transfer size
#define DLN_SPI_MASTER_FRAME_SIZE_8             8
#define DLN_SPI_MASTER_FRAME_SIZE_9             9
#define DLN_SPI_MASTER_FRAME_SIZE_10            10
#define DLN_SPI_MASTER_FRAME_SIZE_11            11
#define DLN_SPI_MASTER_FRAME_SIZE_12            12
#define DLN_SPI_MASTER_FRAME_SIZE_13            13
#define DLN_SPI_MASTER_FRAME_SIZE_14            14
#define DLN_SPI_MASTER_FRAME_SIZE_15            15
#define DLN_SPI_MASTER_FRAME_SIZE_16            16
// SS control
#define DLN_SPI_MASTER_SS_0                     0xFE
#define DLN_SPI_MASTER_SS_1                     0xFD
#define DLN_SPI_MASTER_SS_2                     0xFB
#define DLN_SPI_MASTER_SS_3                     0xF7
#define DLN_SPI_MASTER_SS_DECODE_ENABLED        1
#define DLN_SPI_MASTER_SS_DECODE_DISABLED       0
#define DLN_SPI_MASTER_SS_VARIABLE_ENABLED      1
#define DLN_SPI_MASTER_SS_VARIABLE_DISABLED     0
#define DLN_SPI_MASTER_SS_AAT_ENABLED           1
#define DLN_SPI_MASTER_SS_AAT_DISABLED          0
#define DLN_SPI_MASTER_SS_BETWEEN_FRAMES_ENABLED  1
#define DLN_SPI_MASTER_SS_BETWEEN_FRAMES_DISABLED 0

// ReadWriteEx attributes
#define DLN_SPI_MASTER_ATTR_LEAVE_SS_LOW	(1 << 0)
#define DLN_SPI_MASTER_ATTR_RELEASE_SS		(0 << 0)


/*!
\struct DLN_SPI_MASTER_GET_PORT_COUNT_CMD
 The command retrieves The number of an SPI master ports available in the DLN device.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
} __PACKED_ATTR DLN_SPI_MASTER_GET_PORT_COUNT_CMD;

/*!
\struct DLN_SPI_MASTER_GET_PORT_COUNT_RSP
 The response contains the available number of SPI master ports.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    DLN_RESULT result;												///< Contains the result of the command execution.
    uint8_t count;													///< Contains the available number of SPI master ports.
} __PACKED_ATTR DLN_SPI_MASTER_GET_PORT_COUNT_RSP;

/*!
\struct DLN_SPI_MASTER_ENABLE_CMD
The command is used to activate the corresponding SPI master port of your DLN-series adapter.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.				
    uint8_t port;													///< The number of an SPI master port to be activated.
} __PACKED_ATTR DLN_SPI_MASTER_ENABLE_CMD;

/*!
\struct DLN_SPI_MASTER_ENABLE_RSP
The response informs if the SPI master port has been successfully activated.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    DLN_RESULT result;												///< Contains the result of the command execution.
    uint16_t conflict;												///< The number of the conflicted pin, if any.
} __PACKED_ATTR DLN_SPI_MASTER_ENABLE_RSP;

/*!
\struct DLN_SPI_MASTER_DISABLE_CMD
The command is used to deactivate the specified SPI master port of your DLN device.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    uint8_t port;													///< The number of an SPI master port to be deactivated.
    uint8_t waitForTransferCompletion;								///< Ñhoose whether the device should wait for data transfers to complete or cancel them.
} __PACKED_ATTR DLN_SPI_MASTER_DISABLE_CMD;

/*!
\struct DLN_SPI_MASTER_DISABLE_RSP
The response informs if the SPI master port has been successfully deactivated.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    DLN_RESULT result;												///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_DISABLE_RSP;


/*!
\struct DLN_SPI_MASTER_IS_ENABLED_CMD
The command is used to retrieve information, whether the SPI master port is activated.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    uint8_t port;													///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_IS_ENABLED_CMD;

/*!
\struct DLN_SPI_MASTER_IS_ENABLED_RSP
The response informs a user whether the specified SPI master port is activated.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    DLN_RESULT result;												///< Contains the result of the command execution.
    uint8_t enabled;												///< Informs whether the port is configured as SPI master.
} __PACKED_ATTR DLN_SPI_MASTER_IS_ENABLED_RSP;

/*!
\struct DLN_SPI_MASTER_SET_MODE_CMD
The command is used to set CPOL and CPHA parameters
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    uint8_t port;													///< The number of an SPI master port to apply configuraion to.
    uint8_t mode;													///< A mode to be set.
} __PACKED_ATTR DLN_SPI_MASTER_SET_MODE_CMD;

/*!
\struct DLN_SPI_MASTER_SET_MODE_RSP
The response informs whether the configuration has been successfully changed.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    DLN_RESULT result;												///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_SET_MODE_RSP;

/*!
\struct DLN_SPI_MASTER_GET_MODE_CMD
The command is used to retrieve current configuration of a SPI master port.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    uint8_t port;													///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_GET_MODE_CMD;

/*!
\struct DLN_SPI_MASTER_GET_MODE_RSP
The response contains  current mode of the specified SPI master port.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    DLN_RESULT result;												///< Contains the result of the command execution.
    uint8_t mode;													///< SPI  transmission  mode.
} __PACKED_ATTR DLN_SPI_MASTER_GET_MODE_RSP;

/*!
\struct DLN_SPI_MASTER_SET_TRANSFER_SIZE_CMD
The  command  is  used  to  set  the  number  of  bits transfered via SPI.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    uint8_t port;													///< The number of an SPI master port to be configured.
    uint8_t frameSize;												///< A number of bits to be transfered.
} __PACKED_ATTR DLN_SPI_MASTER_SET_FRAME_SIZE_CMD;

/*!
\struct DLN_SPI_MASTER_SET_TRANSFER_SIZE_RSP
The response informs a user if the transfer size has been successfully set.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    DLN_RESULT result;												///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_SET_FRAME_SIZE_RSP;

/*!
\struct DLN_SPI_MASTER_GET_TRANSFER_SIZE_CMD
The command is used to retrieve current size setting for data transfered via SPI.
*/
typedef struct
{
    DLN_MSG_HEADER header;											///< Defines the DLN message header.
    uint8_t port;													///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_GET_FRAME_SIZE_CMD;

/*!
\struct DLN_SPI_MASTER_GET_TRANSFER_SIZE_RSP
The response contains current setting for the number of bits per transfer.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint8_t frameSize;													///< A number of bits to be transfered.
} __PACKED_ATTR DLN_SPI_MASTER_GET_FRAME_SIZE_RSP;

/*!
\struct DLN_SPI_MASTER_SET_FREQUENCY_CMD
The command is used to set the clock frequency on the SCLK line.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be configured.
    uint32_t frequency;													///< SCLK line frequency value, specified in Hz.
} __PACKED_ATTR DLN_SPI_MASTER_SET_FREQUENCY_CMD;

/*!
\struct DLN_SPI_MASTER_SET_FREQUENCY_RSP
The response informs a user if the SPI clock frequency has been successfully set.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t frequency;													///< The frequency approximated as the closest to user-defined lower value.
} __PACKED_ATTR DLN_SPI_MASTER_SET_FREQUENCY_RSP;

/*!
\struct DLN_SPI_MASTER_GET_FREQUENCY_CMD
The command is used to retrieve current setting for SPI clock frequency.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_GET_FREQUENCY_CMD;

/*!
\struct DLN_SPI_MASTER_GET_FREQUENCY_RSP
The response contains current SPI clock frequency setting.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t frequency;													///< Current SPI clock frequency value in Hz.
} __PACKED_ATTR DLN_SPI_MASTER_GET_FREQUENCY_RSP;


#define DLN_SPI_MASTER_MAX_TRANSFER_SIZE 256
/*!
\struct DLN_SPI_MASTER_READ_WRITE_CMD
The command is used to send and receive data via SPI.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be used.
    uint16_t size;														///< A size of the message buffer.
    uint8_t attribute;													///< Can contain the information to be sent to a slave.
    uint8_t buffer[DLN_SPI_MASTER_MAX_TRANSFER_SIZE];
} __PACKED_ATTR DLN_SPI_MASTER_READ_WRITE_CMD;

/*!
\struct DLN_SPI_MASTER_READ_WRITE_RSP
The response contains confirmation for data transfer as well as data received from a slave.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint16_t size;														///< A size of the message buffer.
    uint8_t buffer[DLN_SPI_MASTER_MAX_TRANSFER_SIZE];												///< Can contain the information received from a slave.
} __PACKED_ATTR DLN_SPI_MASTER_READ_WRITE_RSP;


#define DLN_SPI_MASTER_WRITE_CMD  DLN_SPI_MASTER_READ_WRITE_CMD

typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_WRITE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be used.
    uint16_t size;														///< A size of the message buffer.
    uint8_t attribute;													///< Can contain the information to be sent to a slave.
} __PACKED_ATTR DLN_SPI_MASTER_READ_CMD;

#define DLN_SPI_MASTER_READ_RSP   DLN_SPI_MASTER_READ_WRITE_RSP


/*!
\struct DLN_SPI_MASTER_SET_DELAY_BETWEEN_SS_CMD
The  command  is  used  to  set  a  delay between release of an SS line and ascertion of another SS line.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be configured.
    uint32_t delayBetweenSS;											///< The delay value.
} __PACKED_ATTR DLN_SPI_MASTER_SET_DELAY_BETWEEN_SS_CMD;

/*!
\struct DLN_SPI_MASTER_SET_DELAY_BETWEEN_SS_RSP
The response informs if the delay between release of an SS line and ascertion of another SS line has been set successfully. It also contains actual delay setting.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t delayBetweenSS;											///< Actual set delay value.
} __PACKED_ATTR DLN_SPI_MASTER_SET_DELAY_BETWEEN_SS_RSP;

/*!
\struct DLN_SPI_MASTER_GET_DELAY_BETWEEN_SS_CMD
The command is used to retrieve current delay setting between release of an SS line and ascertion of another SS line.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_GET_DELAY_BETWEEN_SS_CMD;

/*!
\struct DLN_SPI_MASTER_GET_DELAY_BETWEEN_SS_RSP
The response contains current delay setting between release of an SS line and ascertion of another SS line.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.				
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t delayBetweenSS;											///< Current delay value.
} __PACKED_ATTR DLN_SPI_MASTER_GET_DELAY_BETWEEN_SS_RSP;

/*!
\struct DLN_SPI_MASTER_SET_DELAY_AFTER_SS_CMD
The command is used to set a delay duration between ascertion of an SS line and first data frame.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.		
    uint8_t port;														///< The number of an SPI master port to be configured.
    uint32_t delayAfterSS;												///< The delay value.
} __PACKED_ATTR DLN_SPI_MASTER_SET_DELAY_AFTER_SS_CMD;

/*!
\struct DLN_SPI_MASTER_SET_DELAY_AFTER_SS_RSP
The response informs if the delay between ascertion of an SS line and first data frame has been set successfully. It also contains actual delay setting.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.	
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t delayAfterSS;												///< Actual set delay value.
} __PACKED_ATTR DLN_SPI_MASTER_SET_DELAY_AFTER_SS_RSP;

/*!
\struct DLN_SPI_MASTER_GET_DELAY_AFTER_SS_CMD
The command is used to retrieve current delay setting between ascertion of an SS line and first data frame.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_GET_DELAY_AFTER_SS_CMD;

/*!
\struct DLN_SPI_MASTER_GET_DELAY_AFTER_SS_RSP
The response contains current setting for delay between ascertion of an SS line and first data frame.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.	
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t delayAfterSS;												///< Current delay value.
} __PACKED_ATTR DLN_SPI_MASTER_GET_DELAY_AFTER_SS_RSP;

/*!
\struct DLN_SPI_MASTER_SET_DELAY_BETWEEN_FRAMES_CMD
The command is used to set a delay between data frames with a single slave device.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be configured.
    uint32_t delayBetweenFrames;										///< The delay value.
} __PACKED_ATTR DLN_SPI_MASTER_SET_DELAY_BETWEEN_FRAMES_CMD;

/*!
\struct DLN_SPI_MASTER_SET_DELAY_BETWEEN_FRAME_RSP
The response informs if the minimum between data frames with a single slave has been set successfully. It also contains actual delay setting.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t delayBetweenFrames;										///< Actual set delay value.
} __PACKED_ATTR DLN_SPI_MASTER_SET_DELAY_BETWEEN_FRAMES_RSP;

/*!
\struct DLN_SPI_MASTER_GET_DELAY_BETWEEN_FRAMES_CMD
The command is used to retrieve current setting for delay between data frames with a single slave device.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_GET_DELAY_BETWEEN_FRAMES_CMD;

/*!
\struct DLN_SPI_MASTER_GET_DELAY_BETWEEN_FRAMES_RSP
The response contains current setting for delay between data frames with a single slave device.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint32_t delayBetweenFrames;										///< Current delay value.
} __PACKED_ATTR DLN_SPI_MASTER_GET_DELAY_BETWEEN_FRAMES_RSP;


/*!
\struct DLN_SPI_MASTER_SET_SS_CMD;
The command is used to select an SS line.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be configured.
    uint8_t ss;															///< The number of an SS line to be activated.
} __PACKED_ATTR DLN_SPI_MASTER_SET_SS_CMD;

/*!
\struct DLN_SPI_MASTER_SET_SS_RSP
The response informs if an SS line has been successfully selected.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_SET_SS_RSP;

/*!
\struct DLN_SPI_MASTER_GET_SS_CMD
The command is used to retrieve current SS line.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to retrieve the information from.
} __PACKED_ATTR DLN_SPI_MASTER_GET_SS_CMD;

/*!
\struct DLN_SPI_MASTER_GET_SS_RSP
The response contains currently selected SS line.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint8_t ss;															///< The number of number of an SS line.
} __PACKED_ATTR DLN_SPI_MASTER_GET_SS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be configured.
} __PACKED_ATTR DLN_SPI_MASTER_RELEASE_SS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_RELEASE_SS_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_SS_VARIABLE_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SS_VARIABLE_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_SS_VARIABLE_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SS_VARIABLE_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_SS_VARIABLE_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_MASTER_SS_VARIABLE_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_SS_AAT_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SS_AAT_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_SS_AAT_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SS_AAT_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_SS_AAT_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_MASTER_SS_AAT_IS_ENABLED_RSP;

/*!
\struct DLN_SPI_MASTER_SS_BETWEEN_FRAMES_ENABLE_CMD
The command is used to enable release of an SS line between data frames exchanged with a single slave device.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be configured.
} __PACKED_ATTR DLN_SPI_MASTER_SS_BETWEEN_FRAMES_ENABLE_CMD;

/*!
\struct DLN_SPI_MASTER_SS_BETWEEN_FRAMES_ENABLE_RSP
The response informs if release of an SS line between data frames, exchanged with a single slave device, has been successfully enabled.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_SS_BETWEEN_FRAMES_ENABLE_RSP;

/*!
\struct DLN_SPI_MASTER_SS_BETWEEN_FRAMES_DISABLE_CMD
The command is used to disable release of an SS line between data frames exchanged with a single slave device.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to be configured.
} __PACKED_ATTR DLN_SPI_MASTER_SS_BETWEEN_FRAMES_DISABLE_CMD;

/*!
\struct DLN_SPI_MASTER_SS_BETWEEN_FRAMES_DISABLE_RSP
The response informs if release of an SS line between data frames exchanged with a single slave device has been successfully disabled.
*/
typedef struct
{				
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
} __PACKED_ATTR DLN_SPI_MASTER_SS_BETWEEN_FRAMES_DISABLE_RSP;

/*!
\struct DLN_SPI_MASTER_SS_BETWEEN_FRAMES_IS_ENABLED_CMD
The command is used to retrieve information whether release of an SS line between data frames exchanged with a single slave device is enabled.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    uint8_t port;														///< The number of an SPI master port to get the information from.
} __PACKED_ATTR DLN_SPI_MASTER_SS_BETWEEN_FRAMES_IS_ENABLED_CMD;

/*!
\struct DLN_SPI_MASTER_SS_BETWEEN_FRAMES_IS_ENABLED_RSP
 The response informs if release of an SS line between data frames exchanged with a single slave device is enabled.
*/
typedef struct
{
    DLN_MSG_HEADER header;												///< Defines the DLN message header.
    DLN_RESULT result;													///< Contains the result of the command execution.
    uint8_t enabled;            										///< Indicates whether release of an SS line is enabled.
} __PACKED_ATTR DLN_SPI_MASTER_SS_BETWEEN_FRAMES_IS_ENABLED_RSP;



typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t cpha;
} __PACKED_ATTR DLN_SPI_MASTER_SET_CPHA_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SET_CPHA_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_CPHA_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t cpha;
} __PACKED_ATTR DLN_SPI_MASTER_GET_CPHA_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t cpol;
} __PACKED_ATTR DLN_SPI_MASTER_SET_CPOL_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SET_CPOL_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_CPOL_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t cpol;
} __PACKED_ATTR DLN_SPI_MASTER_GET_CPOL_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t ss;
} __PACKED_ATTR DLN_SPI_MASTER_SS_MULTI_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SS_MULTI_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t ss;
} __PACKED_ATTR DLN_SPI_MASTER_SS_MULTI_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_SPI_MASTER_SS_MULTI_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_SS_MULTI_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_SPI_MASTER_SS_MULTI_IS_ENABLED_RSP;


typedef struct
{
    uint8_t count;
    uint8_t values[4];
} __PACKED_ATTR DLN_SPI_MASTER_MODE_VALUES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_MODES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_MASTER_MODE_VALUES values;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_MODES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t values[2];
} __PACKED_ATTR DLN_SPI_MASTER_CPHA_VALUES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_CPHA_VALUES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_MASTER_CPHA_VALUES values;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_CPHA_VALUES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t values[2];
} __PACKED_ATTR DLN_SPI_MASTER_CPOL_VALUES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_CPOL_VALUES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_MASTER_CPOL_VALUES values;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_CPOL_VALUES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t frameSizes[36];
} __PACKED_ATTR DLN_SPI_MASTER_FRAME_SIZES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_FRAME_SIZES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_SPI_MASTER_FRAME_SIZES supportedSizes;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SUPPORTED_FRAME_SIZES_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SS_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t count;
} __PACKED_ATTR DLN_SPI_MASTER_GET_SS_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_MIN_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_SPI_MASTER_GET_MIN_FREQUENCY_RSP;

#define DLN_SPI_MASTER_GET_MAX_FREQUENCY_CMD    DLN_SPI_MASTER_GET_MIN_FREQUENCY_CMD
#define DLN_SPI_MASTER_GET_MAX_FREQUENCY_RSP    DLN_SPI_MASTER_GET_MIN_FREQUENCY_RSP


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t delay;
} __PACKED_ATTR DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_RSP;

#define DLN_SPI_MASTER_GET_MAX_DELAY_BETWEEN_SS_CMD     DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_CMD
#define DLN_SPI_MASTER_GET_MAX_DELAY_BETWEEN_SS_RSP     DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_RSP

#define DLN_SPI_MASTER_GET_MIN_DELAY_AFTER_SS_CMD       DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_CMD
#define DLN_SPI_MASTER_GET_MIN_DELAY_AFTER_SS_RSP       DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_RSP
#define DLN_SPI_MASTER_GET_MAX_DELAY_AFTER_SS_CMD       DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_CMD
#define DLN_SPI_MASTER_GET_MAX_DELAY_AFTER_SS_RSP       DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_RSP

#define DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_FRAMES_CMD  DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_CMD
#define DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_FRAMES_RSP  DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_RSP
#define DLN_SPI_MASTER_GET_MAX_DELAY_BETWEEN_FRAMES_CMD  DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_CMD
#define DLN_SPI_MASTER_GET_MAX_DELAY_BETWEEN_FRAMES_RSP  DLN_SPI_MASTER_GET_MIN_DELAY_BETWEEN_SS_RSP


/*!
Retrieves the total number of SPI master ports available in your DLN-series adapter.
\param handle - A handle to the DLN-series adapter.
\param count - A pointer to an unsigned 8-bit integer. This integer will be filled with the number of available ports after the function execution.
\retval DLN_RES_SUCCESS - the port count has been successfully retrieved.
*/
DLN_RESULT DlnSpiMasterGetPortCount(HDLN handle, uint8_t *count);

/*!
Activates corresponding SPI master port on your DLN-series adapter
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be enabled as master.
\param conflict - A pointer to an unsigned 16-bit integer. This integer can be filled with a number of the conflicted pin.
\retval DLN_RES_SUCCESS - the SPI master port has been successfully enabled.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_PIN_IN_USE - the SPI pins are assigned to another module of the adapter and cannot be enabled as SPI.
\retval DLN_RES_NO_FREE_DMA_CHANNEL - all DMA channels are assigned to another modules of the adapter.
*/
DLN_RESULT DlnSpiMasterEnable(HDLN handle, uint8_t port, uint16_t *conflict);

/*!
Deactivates corresponding SPI master port on your DLN-Series adapter.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be disabled as master.
\param waitForTransferCompletion - Wait for current data transfers to complete or disable instantly.
\retval DLN_RES_SUCCESS - the SPI master port has been successfully disabled.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_TRANSFER_CANCELLED - the pending transfers were cancelled.
*/
DLN_RESULT DlnSpiMasterDisable(HDLN handle, uint8_t port, uint8_t waitForTransferCompletion);

/*!
Retrieves information whether the specified SPI master port is activated.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param enabled - A pointer A pointer to an unsigned 8-bit integer. The integer will be filled with information whether the specified SPI master port is activated after the function execution.
\retval DLN_RES_SUCCESS - the SPI master port state has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

/*!
Sets SPI transmission parameters
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to apply configuration to.
\param mode - A bit field describing the SPI master mode to be set.
\retval DLN_RES_SUCCESS - the SPI master port mode has been successfully set.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master is busy transferring.
*/
DLN_RESULT DlnSpiMasterSetMode(HDLN handle, uint8_t port, uint8_t mode);

/*!
 Retrieves current configuration of the specified SPI master port.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param mode - A pointer to an unsigned 8 bit integer. This integer will be filled with the SPI mode description after the function execution.
\retval DLN_RES_SUCCESS - the SPI master port mode has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterGetMode(HDLN handle, uint8_t port, uint8_t *mode);

/*!
Sets the size of a single SPI data frame.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\param frameSize - A number of bits to be transferred in a single frame.
\retval DLN_RES_SUCCESS - the SPI master port frame size has been successfully set.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_SPI_INVALID_FRAME_SIZE - the frame size is out of range.
\retval DLN_RES_BUSY - the SPI master is busy transferring.
*/
DLN_RESULT DlnSpiMasterSetFrameSize(HDLN handle, uint8_t port, uint8_t frameSize);

/*!
Retrieves current size setting for SPI data frames.
\param handle - A handle to the DLN-series adapter.
\param  port - The number of an SPI master port to retrieve the information from.
\param frameSize - A number of bits to be transferred in a single frame.
\retval DLN_RES_SUCCESS - the SPI master port frame size has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterGetFrameSize(HDLN handle, uint8_t port, uint8_t *frameSize);

/*!
Sets  the clock  frequency  on  the SCLK  line.
actualFrequency can be NULL
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\param frequency - SCLK line frequency value, specified in Hz.
\param actualFrequency - A pointer to an unsigned 32-bit integer. This integer will be filled with the frequency approximated as the closest to user-defined lower value.
\retval DLN_RES_SUCCESS - the SPI master port frequency has been successfully set.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master is busy transferring.
\retval DLN_RES_VALUE_ROUNDED - the frequency value has been approximated as the closest supported value.
*/
DLN_RESULT DlnSpiMasterSetFrequency(HDLN handle, uint8_t port, uint32_t frequency, uint32_t *actualFrequency);

/*!
 Retrieves current setting for SPI clock frequency.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param frequency - A pointer to an unsigned 32-bit integer. This integer will be filled with current SPI clock frequency after the function execution.
\retval DLN_RES_SUCCESS - the SPI master port frequency has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterGetFrequency(HDLN handle, uint8_t port, uint32_t *frequency);

/*!
 Sends and receives data via SPI.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port.
\param size - The size of the message buffer.
\param writeBuffer - A pointer to an unsigned 8-bit integer. This integer will be filled with data to be transferred from master to slave after the function execution.
\param readBuffer - A pointer to an unsigned 8-bit integer. This integer will be filled with data to be transferred from slave to master after the function execution.
\retval DLN_RES_SUCCESS - the SPI master port transaction has been successfully performed.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_DISABLED - the SPI master port is disabled.
*/
DLN_RESULT DlnSpiMasterReadWrite(HDLN handle, uint8_t port, uint16_t size, uint8_t *writeBuffer, uint8_t *readBuffer);
DLN_RESULT DlnSpiMasterReadWriteEx(HDLN handle, uint8_t port, uint16_t size, uint8_t *writeBuffer, uint8_t *readBuffer, uint8_t attribute);

DLN_RESULT DlnSpiMasterWrite(HDLN handle, uint8_t port, uint16_t size, uint8_t *writeBuffer);
DLN_RESULT DlnSpiMasterWriteEx(HDLN handle, uint8_t port, uint16_t size, uint8_t *writeBuffer, uint8_t attribute);

DLN_RESULT DlnSpiMasterRead(HDLN handle, uint8_t port, uint16_t size, uint8_t *readBuffer);
DLN_RESULT DlnSpiMasterReadEx(HDLN handle, uint8_t port, uint16_t size, uint8_t *readBuffer, uint8_t attribute);

/*!
Sends and receives 2-byte frames via SPI.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port.
\param count - The number of 2-byte array elements.
\param writeBuffer - A pointer to an unsigned 16-bit integer. This integer will be filled with data to be transferred from master to slave after the function execution.
\param readBuffer - A pointer to an unsigned 16-bit integer. This integer will be filled with data to be transferred from slave to master after the function execution.
\retval DLN_RES_SUCCESS - the SPI master port transaction has been successfully performed.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_DISABLED - the SPI master port is disabled.
*/
DLN_RESULT DlnSpiMasterReadWrite16(HDLN handle, uint8_t port, uint16_t count, uint16_t *writeBuffer, uint16_t *readBuffer);

/*!
Sets a minimum delay between release of an SS line and assertion of another SS line.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\param delayBetweenSS - The delay value in nanoseconds.
\param actualDelayBetweenSS - Actual set delay value in nanoseconds.
\retval DLN_RES_SUCCESS - the delay has been successfully set.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master is busy transferring.
\retval DLN_RES_VALUE_ROUNDED - the delay value has been approximated as the closest supported value.
*/
DLN_RESULT DlnSpiMasterSetDelayBetweenSS(HDLN handle, uint8_t port, uint32_t delayBetweenSS, uint32_t *actualDelayBetweenSS);

/*!
Retrieves  current  setting  for  minimum  delay between release of an SS line and assertion of another SS line.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param delayBetweenSS - A  pointer  to  an  unsigned  32-bit  integer.  The  integer  will  be  filled  with  current  delay  value  in nanoseconds.
\retval DLN_RES_SUCCESS - the delay has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterGetDelayBetweenSS(HDLN handle, uint8_t port, uint32_t *delayBetweenSS);

/*!
Sets a delay duration between assertion of an SS line and first data frame.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\param delayAfterSS - The delay value in nanoseconds.
\param actualDelayAfterSS - Actual set delay value in nanoseconds.
\retval DLN_RES_SUCCESS - the delay has been successfully set.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master is busy transferring.
\retval DLN_RES_VALUE_ROUNDED - the delay value has been approximated as the closest supported value.
*/
DLN_RESULT DlnSpiMasterSetDelayAfterSS(HDLN handle, uint8_t port, uint32_t delayAfterSS, uint32_t *actualDelayAfterSS);

/*!
Retrieves current setting for minimum delay between assertion of an SS line and first data frame.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param delayAfterSS - A  pointer  to  an  unsigned  32-bit  integer.  The  integer  will  be  filled  with  current  delay  value  in nanoseconds.
\retval DLN_RES_SUCCESS - the delay has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterGetDelayAfterSS(HDLN handle, uint8_t port, uint32_t *delayAfterSS);

/*!
Sets  a  delay  between  data  frames exchanged with a single slave device.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\param delayBetweenFrames - The delay value in nanoseconds.
\param actualDelayBetweenFrames - Actual set delay value in nanoseconds.
\retval DLN_RES_SUCCESS - the delay has been successfully set.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master is busy transferring.
\retval DLN_RES_VALUE_ROUNDED - the delay value has been approximated as the closest supported value.
*/
DLN_RESULT DlnSpiMasterSetDelayBetweenFrames(HDLN handle, uint8_t port, uint32_t delayBetweenFrames, uint32_t *actualDelayBetweenFrames);

/*!
Retrieves current setting for delay between data frames exchanged with a single slave device.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param delayBetweenFrames - A  pointer  to  an  unsigned  32-bit  integer.  The  integer  will  be  filled  with  current  delay  value  in nanoseconds.
\retval DLN_RES_SUCCESS - the delay has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterGetDelayBetweenFrames(HDLN handle, uint8_t port, uint32_t *delayBetweenFrames);

/*!
Selects a Slave Select (SS) line.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\param ss - An SS line to be activated.
\retval DLN_RES_SUCCESS - the slave select has been successfully set.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master port is busy transferring.
\retval DLN_RES_SPI_MASTER_INVALID_SS_NUMBER - the SS value is out of range.
*/
DLN_RESULT DlnSpiMasterSetSS(HDLN handle, uint8_t port, uint8_t ss);

/*!
Retrieves current Slave Select (SS)line.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param ss - A pointer to an unsigned 8-bit integer. This integer will be filled with the number of the currently selected SS line.
\retval DLN_RES_SUCCESS - the slave select has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterGetSS(HDLN handle, uint8_t port, uint8_t *ss);

DLN_RESULT DlnSpiMasterReleaseSS(HDLN handle, uint8_t port);

/*Do not work*/
DLN_RESULT DlnSpiMasterSSVariableEnable(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiMasterSSVariableDisable(HDLN handle, uint8_t port);
DLN_RESULT DlnSpiMasterSSVariableIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

/*!
Enables release of an SS line between data frames exchanged with a single slave device.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\retval DLN_RES_SUCCESS - the SS between frames has been successfully enabled.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master port is busy transferring.
*/
DLN_RESULT DlnSpiMasterSSBetweenFramesEnable(HDLN handle, uint8_t port);

/*!
Disables release of an SS line between data frames exchanged with a single slave device.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to be configured.
\retval DLN_RES_SUCCESS - the SS between frames has been successfully disabled.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_BUSY - the SPI master port is busy transferring.
*/
DLN_RESULT DlnSpiMasterSSBetweenFramesDisable(HDLN handle, uint8_t port);

/*!
Retrieves information whether release of an SS line between data frames exchanged with a slave device is enabled.
\param handle - A handle to the DLN-series adapter.
\param port - The number of an SPI master port to retrieve the information from.
\param enabled - A pointer to an unsigned 8-bit integer. The integer will be filled with information whether release of an SS line between data frames exchanged with a slave device is enabled after the function execution.
\retval DLN_RES_SUCCESS - the SS between frames state has been successfully retrieved.
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnSpiMasterSSBetweenFramesIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

DLN_RESULT DlnSpiMasterSetCpha(HDLN handle, uint8_t port, uint8_t cpha);
DLN_RESULT DlnSpiMasterGetCpha(HDLN handle, uint8_t port, uint8_t *cpha);
DLN_RESULT DlnSpiMasterSetCpol(HDLN handle, uint8_t port, uint8_t cpol);
DLN_RESULT DlnSpiMasterGetCpol(HDLN handle, uint8_t port, uint8_t *cpol);
DLN_RESULT DlnSpiMasterGetSupportedModes(HDLN handle, uint8_t port, DLN_SPI_MASTER_MODE_VALUES *values);
DLN_RESULT DlnSpiMasterGetSupportedCphaValues(HDLN handle, uint8_t port, DLN_SPI_MASTER_CPHA_VALUES *values);
DLN_RESULT DlnSpiMasterGetSupportedCpolValues(HDLN handle, uint8_t port, DLN_SPI_MASTER_CPOL_VALUES *values);
DLN_RESULT DlnSpiMasterGetSupportedFrameSizes(HDLN handle, uint8_t port, DLN_SPI_MASTER_FRAME_SIZES *supportedSizes);

DLN_RESULT DlnSpiMasterGetSSCount(HDLN handle, uint8_t port, uint16_t *count);

DLN_RESULT DlnSpiMasterSSMultiEnable(HDLN handle, uint8_t port, uint8_t ssMask);
DLN_RESULT DlnSpiMasterSSMultiDisable(HDLN handle, uint8_t port, uint8_t ssMask);
DLN_RESULT DlnSpiMasterSSMultiIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

DLN_RESULT DlnSpiMasterSSEnable(HDLN handle, uint8_t port, uint8_t ss);
DLN_RESULT DlnSpiMasterSSDisable(HDLN handle, uint8_t port, uint8_t ss);
DLN_RESULT DlnSpiMasterSSIsEnabled(HDLN handle, uint8_t port, uint8_t ss, uint8_t *enabled);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif // DLN_SPI_H
