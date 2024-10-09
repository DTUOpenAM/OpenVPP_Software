#ifndef DLN_LED_H
#define DLN_LED_H
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


#define DLN_MSG_ID_LED_GET_COUNT    DLN_BUILD_MSG_ID(0x00, DLN_MODULE_LED)
#define DLN_MSG_ID_LED_SET_STATE    DLN_BUILD_MSG_ID(0x01, DLN_MODULE_LED)
#define DLN_MSG_ID_LED_GET_STATE    DLN_BUILD_MSG_ID(0x02, DLN_MODULE_LED)
#define DLN_MSG_ID_LED_GET_SUPPORTED_STATES DLN_BUILD_MSG_ID(0x40, DLN_MODULE_LED)

typedef uint8_t DLN_LED_STATE;
#define DLN_LED_STATE_OFF   ((DLN_LED_STATE)0)
#define DLN_LED_STATE_ON    ((DLN_LED_STATE)1)
#define DLN_LED_STATE_SLOW_BLINK ((DLN_LED_STATE)2)
#define DLN_LED_STATE_FAST_BLINK ((DLN_LED_STATE)3)
#define DLN_LED_STATE_DOUBLE_BLINK ((DLN_LED_STATE)4)
#define DLN_LED_STATE_TRIPLE_BLINK ((DLN_LED_STATE)5)

/*!
\struct DLN_LED_GET_COUNT_CMD
The command is used to is used to retrieve the number of user-controlled LEDs from a device.
*/
typedef struct
{
    DLN_MSG_HEADER header;        				///< Defines the DLN message header.
} __PACKED_ATTR DLN_LED_GET_COUNT_CMD;

/*!
\struct DLN_LED_GET_COUNT_RSP
The  response contains the number of user-controlled LEDs.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;          				///< Contains the result of the command execution.
    uint8_t count;								///< The number of user-controlled LEDs.
} __PACKED_ATTR DLN_LED_GET_COUNT_RSP;

/*!
\struct DLN_LED_SET_STATE_CMD
The command is used to set LED states.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint8_t ledNumber;							///< The number of the LED, whose state is to be changed.
    DLN_LED_STATE state;						///< The value of the state to be set.
} __PACKED_ATTR DLN_LED_SET_STATE_CMD;

/*!
\struct DLN_LED_SET_STATE_RSP
The response informs if a LED state was successfully set.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_LED_SET_STATE_RSP;

/*!
\struct  DLN_LED_GET_STATE_CMD
 The command is used to obtain current state of a LED.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint8_t ledNumber;							///< The number of the LED, whose state is to be retrieved.
} __PACKED_ATTR DLN_LED_GET_STATE_CMD;

/*!
\struct DLN_LED_GET_STATE_RSP
The response contains the retrieved state of the LED.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    DLN_LED_STATE state;						///< The obtained value of the state.
} __PACKED_ATTR DLN_LED_GET_STATE_RSP;


typedef struct
{
    uint8_t count;
    uint8_t states[16];
} __PACKED_ATTR DLN_LED_STATES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t ledNumber;
} __PACKED_ATTR DLN_LED_GET_SUPPORTED_STATES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_LED_STATES supportedStates;
} __PACKED_ATTR DLN_LED_GET_SUPPORTED_STATES_RSP;


/*!
Retrieves the total number of user-controlled LEDs available in the device.
\param handle - A handle to the DLN-series adapter.
\param count - A pointer to an unsigned 8-bit integer. This integer will be filled with the number of available user-controlled LEDs after the function execution.
\retval DLN_RES_SUCCESS - the LED count has been successfully retrieved.
*/
DLN_RESULT DlnLedGetCount(HDLN handle, uint8_t *count);

/*!
Sets a new state of the user-controlled LED.
\param handle - A handle to the DLN-series adapter.
\param ledNumber - A LED, whose state is to be changed.
\param state - A LED state to be set.
\retval DLN_RES_SUCCESS - the LED state was successfully set;
\retval DLN_RES_INVALID_LED_NUMBER - the LED number is invalid;
\retval DLN_RES_INVALID_LED_STATE - the LED state is invalid.
*/
DLN_RESULT DlnLedSetState(HDLN handle, uint8_t ledNumber, DLN_LED_STATE state);

/*!
Retreives the current state of the LED.
\param handle - A handle to the DLN-series adapter.
\param ledNumber - A LED to obtain a state from.
\param state - A pointer to a DLN_LED_STATE structure to store the obtained LED state.
\retval DLN_RES_SUCCESS - the LED state was successfully retrieved;
\retval DLN_RES_INVALID_LED_NUMBER - the LED number is invalid.
*/
DLN_RESULT DlnLedGetState(HDLN handle, uint8_t ledNumber, DLN_LED_STATE *state);


#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif // DLN_LED_H

