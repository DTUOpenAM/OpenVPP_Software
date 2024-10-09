#ifndef DLN_PWM_H_INCLUDED
#define DLN_PWM_H_INCLUDED


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


#define DLN_PIN_ROLE_PWM    ((DLN_PIN_ROLE)1)


#define DLN_MSG_ID_PWM_GET_PORT_COUNT       DLN_BUILD_MSG_ID(0x00, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_GET_CHANNEL_COUNT    DLN_BUILD_MSG_ID(0x01, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_ENABLE               DLN_BUILD_MSG_ID(0x02, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_DISABLE              DLN_BUILD_MSG_ID(0x03, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_IS_ENABLED           DLN_BUILD_MSG_ID(0x04, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_CHANNEL_ENABLE       DLN_BUILD_MSG_ID(0x05, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_CHANNEL_DISABLE      DLN_BUILD_MSG_ID(0x06, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_CHANNEL_IS_ENABLED   DLN_BUILD_MSG_ID(0x07, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_SET_FREQUENCY        DLN_BUILD_MSG_ID(0x08, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_GET_FREQUENCY        DLN_BUILD_MSG_ID(0x09, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_SET_DUTY_CYCLE       DLN_BUILD_MSG_ID(0x0A, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_GET_DUTY_CYCLE       DLN_BUILD_MSG_ID(0x0B, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_GET_MIN_FREQUENCY    DLN_BUILD_MSG_ID(0x40, DLN_MODULE_PWM)
#define DLN_MSG_ID_PWM_GET_MAX_FREQUENCY    DLN_BUILD_MSG_ID(0x41, DLN_MODULE_PWM)

#define DLN_PWM_ENABLED             1
#define DLN_PWM_DISABLED            0
#define DLN_PWM_CHANNEL_ENABLED     1
#define DLN_PWM_CHANNEL_DISABLED    0


typedef struct
{
    DLN_MSG_HEADER header;
} __PACKED_ATTR DLN_PWM_GET_PORT_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_PWM_GET_PORT_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_PWM_GET_CHANNEL_COUNT_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t count;
} __PACKED_ATTR DLN_PWM_GET_CHANNEL_COUNT_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_PWM_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t conflict;
} __PACKED_ATTR DLN_PWM_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_PWM_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_PWM_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_PWM_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_PWM_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_PWM_CHANNEL_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_PWM_CHANNEL_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_PWM_CHANNEL_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
} __PACKED_ATTR DLN_PWM_CHANNEL_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_PWM_CHANNEL_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint8_t enabled;
} __PACKED_ATTR DLN_PWM_CHANNEL_IS_ENABLED_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
    uint32_t frequency;
} __PACKED_ATTR DLN_PWM_SET_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_PWM_SET_FREQUENCY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_PWM_GET_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_PWM_GET_FREQUENCY_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
    uint16_t bpDutyCycle;
} __PACKED_ATTR DLN_PWM_SET_DUTY_CYCLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t bpDutyCycle;
} __PACKED_ATTR DLN_PWM_SET_DUTY_CYCLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
    uint8_t channel;
} __PACKED_ATTR DLN_PWM_GET_DUTY_CYCLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint16_t bpDutyCycle;
} __PACKED_ATTR DLN_PWM_GET_DUTY_CYCLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;
    uint8_t port;
} __PACKED_ATTR DLN_PWM_GET_MIN_FREQUENCY_CMD;

typedef struct
{
    DLN_MSG_HEADER header;
    DLN_RESULT result;
    uint32_t frequency;
} __PACKED_ATTR DLN_PWM_GET_MIN_FREQUENCY_RSP;

#define DLN_PWM_GET_MAX_FREQUENCY_CMD    DLN_PWM_GET_MIN_FREQUENCY_CMD
#define DLN_PWM_GET_MAX_FREQUENCY_RSP    DLN_PWM_GET_MIN_FREQUENCY_RSP


DLN_RESULT DlnPwmGetPortCount(HDLN handle, uint8_t *count);
DLN_RESULT DlnPwmGetChannelCount(HDLN handle, uint8_t port, uint8_t *count);
DLN_RESULT DlnPwmEnable(HDLN handle, uint8_t port, uint16_t *conflict);
DLN_RESULT DlnPwmDisable(HDLN handle, uint8_t port);
DLN_RESULT DlnPwmIsEnabled(HDLN handle, uint8_t port, uint8_t *enabled);
DLN_RESULT DlnPwmChannelEnable(HDLN handle, uint8_t port, uint8_t channel);
DLN_RESULT DlnPwmChannelDisable(HDLN handle, uint8_t port, uint8_t channel);
DLN_RESULT DlnPwmChannelIsEnabled(HDLN handle, uint8_t port, uint8_t channel, uint8_t *enabled);
DLN_RESULT DlnPwmSetFrequency(HDLN handle, uint8_t port, uint8_t channel, uint32_t frequency, uint32_t *actualFrequency);
DLN_RESULT DlnPwmGetFrequency(HDLN handle, uint8_t port, uint8_t channel, uint32_t *frequency);
DLN_RESULT DlnPwmSetDutyCycle(HDLN handle, uint8_t port, uint8_t channel, double dutyCycle, double *actualDutyCycle);
DLN_RESULT DlnPwmGetDutyCycle(HDLN handle, uint8_t port, uint8_t channel, double *dutyCycle);
DLN_RESULT DlnPwmGetMinFrequency(HDLN handle, uint8_t port, uint32_t *frequency);
DLN_RESULT DlnPwmGetMaxFrequency(HDLN handle, uint8_t port, uint32_t *frequency);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif //DLN_PWM_H_INCLUDED
