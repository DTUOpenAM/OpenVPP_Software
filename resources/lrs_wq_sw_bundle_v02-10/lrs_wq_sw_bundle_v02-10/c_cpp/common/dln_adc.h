#ifndef DLN_ADC_H_INCLUDED
#define DLN_ADC_H_INCLUDED


#include "dln.h"


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


#define DLN_PIN_ROLE_ADC        ((DLN_PIN_ROLE)0)


#define DLN_MSG_ID_ADC_GET_PORT_COUNT       DLN_BUILD_MSG_ID(0x00, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_GET_CHANNEL_COUNT    DLN_BUILD_MSG_ID(0x01, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_ENABLE               DLN_BUILD_MSG_ID(0x02, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_DISABLE              DLN_BUILD_MSG_ID(0x03, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_IS_ENABLED           DLN_BUILD_MSG_ID(0x04, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_CHANNEL_ENABLE       DLN_BUILD_MSG_ID(0x05, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_CHANNEL_DISABLE      DLN_BUILD_MSG_ID(0x06, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_CHANNEL_IS_ENABLED   DLN_BUILD_MSG_ID(0x07, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_SET_RESOLUTION       DLN_BUILD_MSG_ID(0x08, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_GET_RESOLUTION       DLN_BUILD_MSG_ID(0x09, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_GET_VALUE            DLN_BUILD_MSG_ID(0x0A, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_GET_ALL_VALUES       DLN_BUILD_MSG_ID(0x0B, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_CHANNEL_SET_CFG      DLN_BUILD_MSG_ID(0x0C, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_CHANNEL_GET_CFG      DLN_BUILD_MSG_ID(0x0D, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_CONDITION_MET_EV     DLN_BUILD_MSG_ID(0x10, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_GET_SUPPORTED_RESOLUTIONS    DLN_BUILD_MSG_ID(0x40, DLN_MODULE_ADC)
#define DLN_MSG_ID_ADC_GET_SUPPORTED_EVENT_TYPES    DLN_BUILD_MSG_ID(0x41, DLN_MODULE_ADC)

#define DLN_ADC_CHANNEL_COUNT_MAX   8

#define DLN_ADC_ENABLED             1
#define DLN_ADC_DISABLED            0
#define DLN_ADC_CHANNEL_ENABLED     1
#define DLN_ADC_CHANNEL_DISABLED    0

#define DLN_ADC_RESOLUTION_8BIT     8
#define DLN_ADC_RESOLUTION_10BIT    10
#define DLN_ADC_RESOLUTION_12BIT    12

#define DLN_ADC_EVENT_NONE          0
#define DLN_ADC_EVENT_BELOW         1
#define DLN_ADC_EVENT_ABOVE         2
#define DLN_ADC_EVENT_OUTSIDE       3
#define DLN_ADC_EVENT_INSIDE        4
#define DLN_ADC_EVENT_ALWAYS        5


typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_ADC_GET_PORT_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_ADC_GET_PORT_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_GET_CHANNEL_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_ADC_GET_CHANNEL_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t conflict;
} __PACKED_ATTR DLN_ADC_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_ADC_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_ADC_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_ADC_CHANNEL_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_ADC_CHANNEL_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_ADC_CHANNEL_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_ADC_CHANNEL_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_ADC_CHANNEL_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_ADC_CHANNEL_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t resolution;
} __PACKED_ATTR DLN_ADC_SET_RESOLUTION_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_ADC_SET_RESOLUTION_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_GET_RESOLUTION_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t resolution;
} __PACKED_ATTR DLN_ADC_GET_RESOLUTION_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_ADC_GET_VALUE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t value;
} __PACKED_ATTR DLN_ADC_GET_VALUE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_GET_ALL_VALUES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t channelMask;
    uint16_t values[DLN_ADC_CHANNEL_COUNT_MAX];
} __PACKED_ATTR DLN_ADC_GET_ALL_VALUES_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
    uint8_t eventType;
    uint16_t eventPeriod;
    uint16_t thresholdLow;
    uint16_t thresholdHigh;
} __PACKED_ATTR DLN_ADC_CHANNEL_SET_CFG_CMD;


typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_ADC_CHANNEL_SET_CFG_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_ADC_CHANNEL_GET_CFG_CMD;


typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t eventType;
    uint16_t eventPeriod;
    uint16_t thresholdLow;
    uint16_t thresholdHigh;
} __PACKED_ATTR DLN_ADC_CHANNEL_GET_CFG_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint16_t eventCount;
    uint8_t port;
    uint8_t channel;
    uint16_t value;
    uint8_t eventType;
} __PACKED_ATTR DLN_ADC_CONDITION_MET_EV;


#define DlnAdcChannelSetCfg DlnAdcSetChannelCfg
#define DlnAdcChannelGetCfg DlnAdcGetChannelCfg


typedef struct
{
    uint8_t count;
    uint8_t resolutions[16];
} __PACKED_ATTR DLN_ADC_RESOLUTIONS;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_GET_SUPPORTED_RESOLUTIONS_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_ADC_RESOLUTIONS supportedResolutions;
} __PACKED_ATTR DLN_ADC_GET_SUPPORTED_RESOLUTIONS_RSP;


typedef struct
{
    uint8_t count;
    uint8_t eventTypes[16];
} __PACKED_ATTR DLN_ADC_EVENT_TYPES;

typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_ADC_GET_SUPPORTED_EVENT_TYPES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    DLN_ADC_EVENT_TYPES supportedEventTypes;
} __PACKED_ATTR DLN_ADC_GET_SUPPORTED_EVENT_TYPES_RSP;


/*!
\retval DLN_RES_SUCCESS - the port count has been successfully retrieved.
*/
DLN_RESULT DlnAdcGetPortCount(HDLN handle ,uint8_t *count);

/*!
\retval DLN_RES_SUCCESS - the channel count has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnAdcGetChannelCount(HDLN handle, uint8_t port, uint8_t *count);

/*!
\retval DLN_RES_SUCCESS - the ADC port has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
\retval DLN_RES_PIN_IN_USE - the ADC pins are assigned to another module of the adapter and cannot be enabled as ADC.
*/
DLN_RESULT DlnAdcEnable(HDLN handle, uint8_t port, uint16_t *conflict);

/*!
\retval DLN_RES_SUCCESS - the ADC port has been successfully disabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnAdcDisable(HDLN handle, uint8_t port);

/*!
\retval DLN_RES_SUCCESS - the ADC port information has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnAdcIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);

/*!
\retval DLN_RES_SUCCESS - the ADC channel has been successfully enabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_INVALID_CHANNEL_NUMBER - the channel number is out of range;
\retval DLN_RES_BUSY - the ADC port is enabled. A channel can only be enabled/disabled while ADC port is disabled.
*/
DLN_RESULT DlnAdcChannelEnable(HDLN handle, uint8_t port, uint8_t channel);

/*!
\retval DLN_RES_SUCCESS - the ADC channel has been successfully disabled;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_INVALID_CHANNEL_NUMBER - the channel number is out of range;
\retval DLN_RES_BUSY - the ADC port is enabled. A channel can only be enabled/disabled while ADC port is disabled.
*/
DLN_RESULT DlnAdcChannelDisable(HDLN handle, uint8_t port, uint8_t channel);

/*!
\retval DLN_RES_SUCCESS - the ADC channel information has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_INVALID_CHANNEL_NUMBER - the channel number is out of range.
*/
DLN_RESULT DlnAdcChannelIsEnabled(HDLN handle, uint8_t port, uint8_t channel, uint8_t *enabled);

/*!
\retval DLN_RES_SUCCESS - the ADC resolution has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_ADC_INVALID_RESOLUTION - the resolution value is out of range.
*/
DLN_RESULT DlnAdcSetResolution(HDLN handle, uint8_t port, uint8_t resolution);

/*!
\retval DLN_RES_SUCCESS - the ADC resolution has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnAdcGetResolution(HDLN handle, uint8_t port, uint8_t *resolution);

/*!
\retval DLN_RES_SUCCESS - the ADC channel value has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_INVALID_CHANNEL_NUMBER - the channel number is out of range;
\retval DLN_RES_CHANNEL_DISABLED - the channel  is disabled.
*/
DLN_RESULT DlnAdcGetValue(HDLN handle, uint8_t port, uint8_t channel, uint16_t *value);

/*!
\retval DLN_RES_SUCCESS - the ADC values have been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range.
*/
DLN_RESULT DlnAdcGetAllValues(HDLN handle, uint8_t port, uint16_t *channelMask, uint16_t *values);

/*!
\retval DLN_RES_SUCCESS - the ADC channel event configuration has been successfully set;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_INVALID_CHANNEL_NUMBER - the channel number is out of range;
\retval DLN_RES_INVALID_EVENT_TYPE - the event type value is invalid.
*/
DLN_RESULT DlnAdcChannelSetCfg(HDLN handle, uint8_t port, uint8_t channel, uint8_t eventType, uint16_t eventPeriod, uint16_t thresholdLow, uint16_t thresholdHigh);

/*!
\retval DLN_RES_SUCCESS - the ADC channel event configuration has been successfully retrieved;
\retval DLN_RES_INVALID_PORT_NUMBER - the port number is out of range;
\retval DLN_RES_INVALID_CHANNEL_NUMBER - the channel number is out of range.
*/
DLN_RESULT DlnAdcChannelGetCfg(HDLN handle, uint8_t port, uint8_t channel, uint8_t *eventType, uint16_t *eventPeriod, uint16_t *thresholdLow, uint16_t *thresholdHigh);

DLN_RESULT DlnAdcGetSupportedResolutions(HDLN handle, uint8_t port, DLN_ADC_RESOLUTIONS *supportedResolutions);
DLN_RESULT DlnAdcGetSupportedEventTypes(HDLN handle, uint8_t port, DLN_ADC_EVENT_TYPES *supportedEventTypes);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif //DLN_ADC_H_INCLUDED
