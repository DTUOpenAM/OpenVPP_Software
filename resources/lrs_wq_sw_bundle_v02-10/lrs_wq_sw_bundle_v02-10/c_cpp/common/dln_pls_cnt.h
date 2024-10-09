#ifndef DLN_PLS_CNT_H_INCLUDED
#define DLN_PLS_CNT_H_INCLUDED


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


#define DLN_PIN_ROLE_PLS_CNT    ((DLN_PIN_ROLE)0)


#define DLN_MSG_ID_PLS_CNT_GET_PORT_COUNT       DLN_BUILD_MSG_ID(0x00, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_GET_RESOLUTION       DLN_BUILD_MSG_ID(0x01, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_ENABLE               DLN_BUILD_MSG_ID(0x02, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_DISABLE              DLN_BUILD_MSG_ID(0x03, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_IS_ENABLED           DLN_BUILD_MSG_ID(0x04, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_SUSPEND              DLN_BUILD_MSG_ID(0x05, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_RESUME               DLN_BUILD_MSG_ID(0x06, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_IS_SUSPENDED         DLN_BUILD_MSG_ID(0x07, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_RESET                DLN_BUILD_MSG_ID(0x08, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_SET_MODE             DLN_BUILD_MSG_ID(0x09, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_GET_MODE             DLN_BUILD_MSG_ID(0x0A, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_GET_VALUE            DLN_BUILD_MSG_ID(0x0B, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_SET_EVENT_CFG        DLN_BUILD_MSG_ID(0x0C, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_GET_EVENT_CFG        DLN_BUILD_MSG_ID(0x0D, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_CONDITION_MET_EV     DLN_BUILD_MSG_ID(0xFF, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_GET_SUPPORTED_MODES          DLN_BUILD_MSG_ID(0x40, DLN_MODULE_PLS_CNT)
#define DLN_MSG_ID_PLS_CNT_GET_SUPPORTED_EVENT_TYPES    DLN_BUILD_MSG_ID(0x41, DLN_MODULE_PLS_CNT)


// Resolutions
#define DLN_PLS_CNT_RESOLUTION_8BIT     8
#define DLN_PLS_CNT_RESOLUTION_16BIT    16
#define DLN_PLS_CNT_RESOLUTION_32BIT    32
// Enable
#define DLN_PLS_CNT_ENABLED             1
#define DLN_PLS_CNT_DISABLED            0
// Suspend
#define DLN_PLS_CNT_SUSPENDED           1
#define DLN_PLS_CNT_RUNNING             0
// Counter modes
#define DLN_PLS_CNT_MODE_FREE_RUN       0
#define DLN_PLS_CNT_MODE_TIME_BASED     1
#define DLN_PLS_CNT_MODE_PULSE_BASED    2
// Event types
#define DLN_PLS_CNT_EVENT_NONE          0
#define DLN_PLS_CNT_EVENT_OVERFLOW      1
#define DLN_PLS_CNT_EVENT_MATCH         2
#define DLN_PLS_CNT_EVENT_REPEAT        4

/*!
\struct DLN_PLS_CNT_GET_PORT_COUNT_CMD
 The command retrieves the number of Pulse Counter master ports available in the DLN device.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
} __PACKED_ATTR DLN_PLS_CNT_GET_PORT_COUNT_CMD;

/*!
\struct DLN_PLS_CNT_GET_PORT_COUNT_RSP
 The response contains the available number of Pulse Counter master ports.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint8_t count; ///< Contains the available number of Pulse Counter master ports.
} __PACKED_ATTR DLN_PLS_CNT_GET_PORT_COUNT_RSP;

/*!
\struct DLN_PLS_CNT_GET_RESOLUTION_CMD
 The command is used to retrieve the resolution value.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port.
} __PACKED_ATTR DLN_PLS_CNT_GET_RESOLUTION_CMD;

/*!
\struct DLN_PLS_CNT_GET_RESOLUTION_RSP
 The response contains current resolution value.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint8_t resolution; ///< Resolution value.
} __PACKED_ATTR DLN_PLS_CNT_GET_RESOLUTION_RSP;

/*!
\struct DLN_PLS_CNT_ENABLE_CMD
The command is used to activate the corresponding Pulse Counter port of your DLN-series adapter.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port to be activated.
} __PACKED_ATTR DLN_PLS_CNT_ENABLE_CMD;

/*!
\struct DLN_PLS_CNT_ENABLE_RSP
The response informs if the Pulse Counter port has been successfully activated.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint16_t conflict; ///< The number of the conflicted pin, if any.
} __PACKED_ATTR DLN_PLS_CNT_ENABLE_RSP;

/*
\struct DLN_PLS_CNT_DISABLE_CMD
The command is used to deactivate the corresponding Pulse Counter port of your DLN-series adapter.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port to be deactivated.
} __PACKED_ATTR DLN_PLS_CNT_DISABLE_CMD;

/*!
\struct DLN_PLS_CNT_DISABLE_RSP
The response informs if the Pulse Counter port has been successfully deactivated.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
} __PACKED_ATTR DLN_PLS_CNT_DISABLE_RSP;

/*!
\struct DLN_PLS_CNT_IS_ENABLED_CMD
The command is used to retrieve information, whether the Pulse Counter port is activated.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port to be checked.
} __PACKED_ATTR DLN_PLS_CNT_IS_ENABLED_CMD;

/*!
\struct DLN_PLS_CNT_IS_ENABLED_RSP
The response informs a user whether the pulse counter port is activated.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint8_t enabled; ///< Informs whether the port is configured as Pulse Counter.
} __PACKED_ATTR DLN_PLS_CNT_IS_ENABLED_RSP;

/*!
\struct DLN_PLS_CNT_SUSPEND_CMD
The command is used to suspend counter on the Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port to be suspended.
} __PACKED_ATTR DLN_PLS_CNT_SUSPEND_CMD;

/*!
\struct DLN_PLS_CNT_SUSPEND_RSP
The response informs if the Pulse Counter port has been successfully suspended.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
} __PACKED_ATTR DLN_PLS_CNT_SUSPEND_RSP;

/*!
\struct DLN_PLS_CNT_RESUME_CMD
The command is used to resume counter on the Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port to be resumed.
} __PACKED_ATTR DLN_PLS_CNT_RESUME_CMD;

/*!
\struct DLN_PLS_CNT_RESUME_RSP
The response informs if the Pulse Counter port has been successfully resumed.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
} __PACKED_ATTR DLN_PLS_CNT_RESUME_RSP;

/*!
\struct DLN_PLS_CNT_IS_SUSPENDED_CMD
The command is used to retrieve information, whether the Pulse Counter port is suspended.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port to be checked.
} __PACKED_ATTR DLN_PLS_CNT_IS_SUSPENDED_CMD;

/*!
\struct DLN_PLS_CNT_IS_SUSPENDED_RSP
The response informs a user whether the pulse counter port is suspended.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint8_t suspended; ///< Informs whether the Pulse Counter port is suspended.
} __PACKED_ATTR DLN_PLS_CNT_IS_SUSPENDED_RSP;

/*!
\struct DLN_PLS_CNT_RESET_CMD
The command is used to reset timer or/and counter on the Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of an Pulse Counter port to be reset.
    uint8_t resetTimer; ///< Defines whether timer need to be reset.
    uint8_t resetCounter; ///< Defines whether counter need to be reset.
} __PACKED_ATTR DLN_PLS_CNT_RESET_CMD;

/*!
\struct DLN_PLS_CNT_RESET_RSP
The response informs a user whether the Pulse Counter port has been succesfully reset.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
} __PACKED_ATTR DLN_PLS_CNT_RESET_RSP;

/*!
\struct DLN_PLS_CNT_SET_MODE_CMD
The command is used to set mode and limit parameters of specified Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of the Pulse Counter port to apply configuration to.
    uint8_t mode; ///< Defines the mode parameter of the Pulse Counter port.
    uint32_t limit; ///< Defines the limit parameter of the Pulse Counter port.
} __PACKED_ATTR DLN_PLS_CNT_SET_MODE_CMD;

/*!
\struct DLN_PLS_CNT_SET_MODE_RSP
The response informs a user whether the mode of Pulse Counter port has been succesfully set.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
} __PACKED_ATTR DLN_PLS_CNT_SET_MODE_RSP;

/*!
\struct DLN_PLS_CNT_GET_MODE_CMD
The command is used to get current mode and limit parameters of specified Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of the Pulse Counter port to get configuration from.
} __PACKED_ATTR DLN_PLS_CNT_GET_MODE_CMD;

/*!
\struct DLN_PLS_CNT_GET_MODE_RSP
The response informs a user whether the mode of Pulse Counter port has been succesfully retrieved.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint8_t mode; ///< Defines the current mode parameter of the Pulse Counter port.
    uint32_t limit; ///< Defines the current limit parameter of the Pulse Counter port.
} __PACKED_ATTR DLN_PLS_CNT_GET_MODE_RSP;

/*!
\struct DLN_PLS_CNT_GET_VALUE_CMD
The command is used to get current timer and counter values of specified Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< The number of the Pulse Counter port to get values from.
} __PACKED_ATTR DLN_PLS_CNT_GET_VALUE_CMD;

/*!
\struct DLN_PLS_CNT_GET_VALUE_RSP
The response informs a user whether the mode of Pulse Counter port has been succesfully retrieved.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint32_t timerValue; ///< Defines the current timer value of the specified Pulse Counter port.
    uint32_t counterValue; ///< Defines the current counter value of the specified Pulse Counter port.
} __PACKED_ATTR DLN_PLS_CNT_GET_VALUE_RSP;

/*!
\struct DLN_PLS_CNT_SET_EVENT_CFG_CMD;
The command is used to configure the event generation conditions for the specified Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< Defines the Pulse Counter port to configure event generation for.
    uint8_t eventType; ///< Defines the event type.
    uint32_t repeatInterval; ///< Defines the repeat interval for event to be received.
} __PACKED_ATTR DLN_PLS_CNT_SET_EVENT_CFG_CMD;

/*!
\struct DLN_PLS_CNT_SET_EVENT_CFG_RSP
The response informs a user whether the event configuration of Pulse Counter port has been succesfully set.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
} __PACKED_ATTR DLN_PLS_CNT_SET_EVENT_CFG_RSP;

/*!
\struct DLN_PLS_CNT_GET_EVENT_CFG_CMD;
The command is used to get the configuration of the event generation conditions for the specified Pulse Counter port.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint8_t port; ///< Defines the Pulse Counter port to get event generation for.
} __PACKED_ATTR DLN_PLS_CNT_GET_EVENT_CFG_CMD;

/*!
\struct DLN_PLS_CNT_GET_EVENT_CFG_RSP
The response informs a user whether the event configuration of Pulse Counter port has been succesfully retrieved.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint8_t eventType; ///< Defines the current event type.
    uint32_t repeatInterval; ///< Defines the current repeat interval for event to be received.
} __PACKED_ATTR DLN_PLS_CNT_GET_EVENT_CFG_RSP;

/*!
\struct DLN_PLS_CNT_CONDITION_MET_EV
The structure represents the DLN Pulse Counter Module event.
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    uint16_t eventCount; ///< Defines the incremented event counter value.
    uint8_t port; ///< Defines the Pulse Counter port.
    uint8_t eventType; ///< Defines the current event type.
    uint32_t timerValue;  ///< Defines the current timer value of the specified Pulse Counter port.
    uint32_t counterValue; ///< Defines the current counter value of the specified Pulse Counter port.
} __PACKED_ATTR DLN_PLS_CNT_CONDITION_MET_EV;


typedef struct
{
    uint8_t count;
    uint8_t modes[8];
} __PACKED_ATTR DLN_PLS_CNT_MODES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_PLS_CNT_GET_SUPPORTED_MODES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_PLS_CNT_MODES supportedModes;
} __PACKED_ATTR DLN_PLS_CNT_GET_SUPPORTED_MODES_RSP;


typedef struct
{
    uint8_t count;
    uint8_t eventTypes[8];
} __PACKED_ATTR DLN_PLS_CNT_EVENT_TYPES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_PLS_CNT_GET_SUPPORTED_EVENT_TYPES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_PLS_CNT_EVENT_TYPES supportedEventTypes;
} __PACKED_ATTR DLN_PLS_CNT_GET_SUPPORTED_EVENT_TYPES_RSP;


/*!
Retrieves the total number of the Pulse Counter ports available in the DLN-series device.
\param handle - a handle to the DLN-series adapter;
\param count - a pointer to an unsigned 8-bit integer. This integer will be filled with the number of available ports after function execution;
\retval DLN_RES_SUCCESS - the port count has been successfully retrieved.
*/
DLN_RESULT DlnPlsCntGetPortCount(HDLN handle, uint8_t *count);
/*!
Retrieves the current Pulse Counter Module resolution.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be configured;
\param resolution - a pointer to an unsigned 8-bit integer. This integer will be filled with the resolution value after the function execution;
\retval DLN_RES_SUCCESS - the resolution has been successfully retrieved;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - the adapter does not support debounce filtering.
*/
DLN_RESULT DlnPlsCntGetResolution(HDLN handle, uint8_t port, uint8_t *resolution);
/*!
Configures a port as pulse counter.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be configured;
\retval DLN_RES_SUCCESS - the Pulse Counter port has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntEnable(HDLN handle, uint8_t port, uint16_t *conflict);
/*!
Disables a port as pulse counter.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be configured;
\retval DLN_RES_SUCCESS - the pulse counter port has been successfully disabled;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntDisable(HDLN handle, uint8_t port);
/*!
Informs whether a port is currently configured as pulse counter.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to retrieve information about;
\param enabled - a pointer to an unsigned 8-bit integer. The integer will be filled with current port configuration after the function execution;
\retval DLN_RES_SUCCESS - the port information has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);
/*!
Suspends pulse counter operation state on the Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be suspended;
\retval DLN_RES_SUCCESS - the Pulse Counter port has been successfully suspended;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntSuspend(HDLN handle, uint8_t port);
/*!
Resumes pulse counter operation state on the Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be resumed;
\retval DLN_RES_SUCCESS - the Pulse Counter port has been successfully resumed;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntResume(HDLN handle, uint8_t port);
/*!
Informs whether a port is currently suspended.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to retrieve information about;
\param suspended - a pointer to an unsigned 8-bit integer. The integer will be filled with current port configuration after the function execution;
\retval DLN_RES_SUCCESS - the port information has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntIsSuspended(HDLN handle, uint8_t port, uint8_t *suspended);
/*!
Resets timer and/or counter on the Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be suspended;
\param resetTimer - Defines whether timer need to be reset;
\param resetCounter - Defines whether counter need to be reset;
\retval DLN_RES_SUCCESS - the Pulse Counter port has been successfully reset;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntReset(HDLN handle, uint8_t port, uint8_t resetTimer, uint8_t resetCounter);
/*!
Is used to set mode and limit parameters of specified Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be configured;
\param mode - defines the mode parameter of the Pulse Counter port;
\param limit - defines the limit parameter of the Pulse Counter port;
\retval DLN_RES_SUCCESS - the Pulse Counter port has been successfully configured;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntSetMode(HDLN handle, uint8_t port, uint8_t mode, uint32_t limit);
/*!
Is used to get mode and limit parameters of specified Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port;
\param mode - a pointer to an unsigned 8-bit integer. Defines the current mode parameter of the Pulse Counter port;
\param limit - a pointer to an unsigned 32-bit integer. Defines the current limit parameter of the Pulse Counter port;
\retval DLN_RES_SUCCESS - the Pulse Counter port has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntGetMode(HDLN handle, uint8_t port, uint8_t *mode, uint32_t *limit);
/*!
Retrieves the current timer and counter values of specified Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port;
\param timerValue - a pointer to an unsigned 32-bit integer. This integer will be filled with the timer value after the function execution;
\param counterValue - a pointer to an unsigned 32-bit integer. This integer will be filled with the counter value after the function execution;
\retval DLN_RES_SUCCESS - the mode and limit parameters have been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntGetValue(HDLN handle, uint8_t port, uint32_t *timerValue, uint32_t *counterValue);
/*!
Is used to set event configuration of specified Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to be configured;
\param eventType - defines the event type parameter;
\param repeatInterval - defines the repeat interval parameter;
\retval DLN_RES_SUCCESS - the Pulse Counter port has been successfully configured;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntSetEventCfg(HDLN handle, uint8_t port, uint8_t eventType, uint32_t repeatInterval);
/*!
Is used to get event configuration of specified Pulse Counter port.
\param handle - a handle to the DLN-series adapter;
\param port - a number of the port to get configuration;
\param eventType -  a pointer to an unsigned 8-bit integer. Defines the current event type parameter;
\param repeatInterval -  a pointer to an unsigned 32-bit integer. Defines the current repeat interval parameter;
\retval DLN_RES_SUCCESS - event type and repeat interval have been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - invalid port number was specified.
*/
DLN_RESULT DlnPlsCntGetEventCfg(HDLN handle, uint8_t port, uint8_t *eventType, uint32_t *repeatInterval);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif //DLN_PLS_CNT_H_INCLUDED
