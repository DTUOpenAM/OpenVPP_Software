#ifndef DLN_H_INCLUDED
#define DLN_H_INCLUDED

#if defined(_MSC_VER) && _MSC_VER < 1600
#include "stdint.h"
#else // _MSC_VER
#include <stdint.h>
#endif // _MSC_VER

#include "dln_results.h"
#include "dln_restrictions.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__ICCARM__)
        #pragma pack(1)
        #define __PACKED_ATTR   /*nothing*/
        //#define __attribute__(...)
#elif defined(WIN32) || defined(__BORLANDC__) || defined(WIN64)
        #pragma pack(push,1)
        #define __PACKED_ATTR   /*nothing*/
        //#define __attribute__(...)
#else
        #define __PACKED_ATTR __attribute__ ((packed))
#endif


typedef uint16_t HDLN;
#define HDLN_ALL_DEVICES (HDLN)0
#define HDLN_INVALID_HANDLE (HDLN)0xFFFF

#define DLN_MAX_MSG_SIZE 288


////////////////////////////////////////////////////////////////////////////////
//// Commands group and macros
////////////////////////////////////////////////////////////////////////////////
#define DLN_MSG_ID uint16_t
#define DLN_MODULE uint8_t
#define DLN_MODULE_GENERIC		((DLN_MODULE)0x00)		///< Common commands
#define DLN_MODULE_GPIO			((DLN_MODULE)0x01)		///< Command for GPIO module
#define DLN_MODULE_SPI_MASTER	((DLN_MODULE)0x02)		///< Command for SPI module
#define DLN_MODULE_I2C_MASTER	((DLN_MODULE)0x03)		///< Command for I2C module
#define DLN_MODULE_LED			((DLN_MODULE)0x04)		///< Command for LED module
#define DLN_MODULE_BOOT			((DLN_MODULE)0x05)		///< Command for BOOT module
#define DLN_MODULE_ADC			((DLN_MODULE)0x06)		///< Command for ADC module
#define DLN_MODULE_PWM			((DLN_MODULE)0x07)		///< Command for PWM module
#define DLN_MODULE_FREQ			((DLN_MODULE)0x08)		///< Command for Freq. counter module
#define DLN_MODULE_I2S			((DLN_MODULE)0x09)
#define DLN_MODULE_SDIO			((DLN_MODULE)0x0A)		///< Command for SDIO module
#define DLN_MODULE_SPI_SLAVE	((DLN_MODULE)0x0B)
#define DLN_MODULE_I2C_SLAVE	((DLN_MODULE)0x0C)
#define DLN_MODULE_PLS_CNT      ((DLN_MODULE)0x0D)      ///< Command for pulse counter module
#define DLN_MODULE_UART         ((DLN_MODULE)0x0E)
#define DLN_MODULE_SPI_SLAVE_SYNC ((DLN_MODULE)0x0F)
#define DLN_MODULE_I2C_EEPROM   ((DLN_MODULE)0x10)
#define DLN_MODULE_SPI_EEPROM   ((DLN_MODULE)0x11)
#define DLN_MODULE_SPI_FLASH    ((DLN_MODULE)0x12)
#define DLN_MODULE_I2C_DATAFLASH ((DLN_MODULE)0x13)
#define DLN_MODULE_ANALYZER     ((DLN_MODULE)0x14)

#define DLN_MODULE_COUNT 0x15
#define DLN_MSG_MODULE_POSITION	8			///< bit position of group code
#define DLN_BUILD_MSG_ID(id, module)	((id) | ((module)<<DLN_MSG_MODULE_POSITION))
#define DLN_GET_MSG_MODULE(x)	(((x)>>DLN_MSG_MODULE_POSITION) & 0xFF)

#define DLN_PIN_ROLE uint8_t




/*!
\struct DLN_MSG_HEADER
The message header is the first field of each message, sent from a host to a device or vice versa. It is used to identify and route the message correctly.
 */
typedef struct
{
        uint16_t size;			///< The size of the message.
        DLN_MSG_ID msgId;			///< The code defining the message.
        uint16_t echoCounter;	///< Used to establish a one-one link between a command/response pair.
								/// In case the message is an event, this is a freerunning counter.
        HDLN handle;			///< A handle to the DLN device.
} __PACKED_ATTR DLN_MSG_HEADER;

/*!
\struct DLN_BASIC_RSP
 */
typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_BASIC_RSP;

/*!
\struct DLN_BASIC_CMD
 */
typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_BASIC_CMD;



//global function for work with library
/*!
Sends a specified message (an asynchronous command) to the device.
\param message - a pointer to a variable that contains a message to be sent.
*/
DLN_RESULT DlnSendMessage(void *message);
/*!
Sends a synchronous command, waits for a response and returns the response details.
\param command - a pointer to a variable that contains a command to be sent;
\param responseBuffer - a pointer to the buffer that receives the response information;
\param responseBufferSize - the maximum number of bytes to be retrieved.
*/
DLN_RESULT DlnTransaction(void *command, void *responseBuffer, uint16_t responseBufferSize);
/*!
Retrieves a message (response or event) sent by the device.
\param handle - a handle to the the DLN device;
\param messageBuffer - a pointer to the buffer that receives the message information;
\param messageSize - the maximum number of bytes to be retrieved.
*/
DLN_RESULT DlnGetMessage(HDLN handle, void *messageBuffer, uint16_t messageSize);

const char* DlnMsgIdToStringA(DLN_MSG_ID msgId);
const char* DlnRestrictionToStringA(DLN_RESTRICTION restriction);
const char* DlnResultToStringA(DLN_RESULT result);
const char* DlnModuleToStringA(DLN_MODULE module);
const char* DlnSpiMasterMsgIdToStringA(DLN_MSG_ID msgId);
const char* DlnSpiSlaveMsgIdToStringA(DLN_MSG_ID msgId);
const char* DlnSpiSlaveShortageActionToStringA(uint8_t shortageAction);
const char* DlnPwmMsgIdToStringA(DLN_MSG_ID msgId);
const char* DlnAdcMsgIdToStringA(DLN_MSG_ID msgId);
const char* DlnSpiSlaveReplyModeToStringA(uint8_t replyMode);
const char* DlnGpioPinEventTypeToStringA(uint8_t eventType);
const char* DlnAdcResolutionToStringA(uint8_t eventType);
const char* DlnAdcEventTypeToStringA(uint8_t eventType);
const char* DlnUartCharacterLengthToStringA(uint8_t characterLength);
const char* DlnUartParityToStringA(uint8_t parity);
const char* DlnUartStopbitToStringA(uint8_t stopbit);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif



#endif //DLN_H_INCLUDED





