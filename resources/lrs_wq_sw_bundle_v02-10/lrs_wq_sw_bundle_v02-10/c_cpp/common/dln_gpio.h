#ifndef DLN_GPIO_H
#define DLN_GPIO_H
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

////////////////////////////////////////////////////////////////////////////////
//// Logical port names
////////////////////////////////////////////////////////////////////////////////

#define DLN_PIN_ROLE_GPIO_DIN  ((DLN_PIN_ROLE)0)
#define DLN_PIN_ROLE_GPIO_DOUT ((DLN_PIN_ROLE)1)

#define DLN_PORT_WIDTH (8)	///< port width
#define DLN_PIN(port, bit) ((port) * DLN_PORT_WIDTH + (bit))

#define DLN_PORTA		0	///< Port on DB-26 connector
#define DLN_PORTB		1	///< Port on DB-26 connector
#define DLN_PORTC		2	///< Port on DB-26 connector
#define DLN_PORTD		3	///< Port on top connector
#define DLN_PORTE		4	///< Port on bottom connector
#define DLN_PORTF		5	///< Port on bottom connector
#define DLN_PORT_COUNT 6	///< count of logical port

#define DLN_BIT0 (1<<0)	///< Bit 0
#define DLN_BIT1 (1<<1)	///< Bit 1
#define DLN_BIT2 (1<<2)	///< Bit 2
#define DLN_BIT3 (1<<3)	///< Bit 3
#define DLN_BIT4 (1<<4)	///< Bit 4
#define DLN_BIT5 (1<<5)	///< Bit 5
#define DLN_BIT6 (1<<6)	///< Bit 6
#define DLN_BIT7 (1<<7)	///< Bit 7

#define DLN_PIN_A0 DLN_PIN(DLN_PORTA, 0)	///< Pin 0 of port A
#define DLN_PIN_A1 DLN_PIN(DLN_PORTA, 1)	///< Pin 1 of port A
#define DLN_PIN_A2 DLN_PIN(DLN_PORTA, 2)	///< Pin 2 of port A
#define DLN_PIN_A3 DLN_PIN(DLN_PORTA, 3)	///< Pin 3 of port A
#define DLN_PIN_A4 DLN_PIN(DLN_PORTA, 4)	///< Pin 4 of port A
#define DLN_PIN_A5 DLN_PIN(DLN_PORTA, 5)	///< Pin 5 of port A
#define DLN_PIN_A6 DLN_PIN(DLN_PORTA, 6)	///< Pin 6 of port A
#define DLN_PIN_A7 DLN_PIN(DLN_PORTA, 7)	///< Pin 7 of port A

#define DLN_PIN_B0 DLN_PIN(DLN_PORTB, 0)	///< Pin 0 of port B
#define DLN_PIN_B1 DLN_PIN(DLN_PORTB, 1)	///< Pin 1 of port B
#define DLN_PIN_B2 DLN_PIN(DLN_PORTB, 2)	///< Pin 2 of port B
#define DLN_PIN_B3 DLN_PIN(DLN_PORTB, 3)	///< Pin 3 of port B
#define DLN_PIN_B4 DLN_PIN(DLN_PORTB, 4)	///< Pin 4 of port B
#define DLN_PIN_B5 DLN_PIN(DLN_PORTB, 5)	///< Pin 5 of port B
#define DLN_PIN_B6 DLN_PIN(DLN_PORTB, 6)	///< Pin 6 of port B
#define DLN_PIN_B7 DLN_PIN(DLN_PORTB, 7)	///< Pin 7 of port B

#define DLN_PIN_C0 DLN_PIN(DLN_PORTC, 0)	///< Pin 0 of port C
#define DLN_PIN_C1 DLN_PIN(DLN_PORTC, 1)	///< Pin 1 of port C
#define DLN_PIN_C2 DLN_PIN(DLN_PORTC, 2)	///< Pin 2 of port C
#define DLN_PIN_C3 DLN_PIN(DLN_PORTC, 3)	///< Pin 3 of port C
#define DLN_PIN_C4 DLN_PIN(DLN_PORTC, 4)	///< Pin 4 of port C
#define DLN_PIN_C5 DLN_PIN(DLN_PORTC, 5)	///< Pin 5 of port C
#define DLN_PIN_C6 DLN_PIN(DLN_PORTC, 6)	///< Pin 6 of port C
#define DLN_PIN_C7 DLN_PIN(DLN_PORTC, 7)	///< Pin 7 of port C

#define DLN_PIN_D0 DLN_PIN(DLN_PORTD, 0)	///< Pin 0 of port D
#define DLN_PIN_D1 DLN_PIN(DLN_PORTD, 1)	///< Pin 1 of port D
#define DLN_PIN_D2 DLN_PIN(DLN_PORTD, 2)	///< Pin 2 of port D
#define DLN_PIN_D3 DLN_PIN(DLN_PORTD, 3)	///< Pin 3 of port D
#define DLN_PIN_D4 DLN_PIN(DLN_PORTD, 4)	///< Pin 4 of port D
#define DLN_PIN_D5 DLN_PIN(DLN_PORTD, 5)	///< Pin 5 of port D
#define DLN_PIN_D6 DLN_PIN(DLN_PORTD, 6)	///< Pin 6 of port D
#define DLN_PIN_D7 DLN_PIN(DLN_PORTD, 7)	///< Pin 7 of port D

#define DLN_PIN_E0 DLN_PIN(DLN_PORTE, 0)	///< Pin 0 of port E
#define DLN_PIN_E1 DLN_PIN(DLN_PORTE, 1)	///< Pin 1 of port E
#define DLN_PIN_E2 DLN_PIN(DLN_PORTE, 2)	///< Pin 2 of port E
#define DLN_PIN_E3 DLN_PIN(DLN_PORTE, 3)	///< Pin 3 of port E
#define DLN_PIN_E4 DLN_PIN(DLN_PORTE, 4)	///< Pin 4 of port E
#define DLN_PIN_E5 DLN_PIN(DLN_PORTE, 5)	///< Pin 5 of port E
#define DLN_PIN_E6 DLN_PIN(DLN_PORTE, 6)	///< Pin 6 of port E
#define DLN_PIN_E7 DLN_PIN(DLN_PORTE, 7)	///< Pin 7 of port E

#define DLN_PIN_F0 DLN_PIN(DLN_PORTF, 0)	///< Pin 0 of port F
#define DLN_PIN_F1 DLN_PIN(DLN_PORTF, 1)	///< Pin 1 of port F
#define DLN_PIN_F2 DLN_PIN(DLN_PORTF, 2)	///< Pin 2 of port F
#define DLN_PIN_F3 DLN_PIN(DLN_PORTF, 3)	///< Pin 3 of port F
#define DLN_PIN_F4 DLN_PIN(DLN_PORTF, 4)	///< Pin 4 of port F
#define DLN_PIN_F5 DLN_PIN(DLN_PORTF, 5)	///< Pin 5 of port F
#define DLN_PIN_F6 DLN_PIN(DLN_PORTF, 6)	///< Pin 6 of port F
#define DLN_PIN_F7 DLN_PIN(DLN_PORTF, 7)	///< Pin 7 of port F

////////////////////////////////////////////////////////////////////////////////
//// GPIO commands and structures
////////////////////////////////////////////////////////////////////////////////

// GPIO command list
#define DLN_MSG_ID_GPIO_GET_PORT_COUNT          DLN_BUILD_MSG_ID(0x00, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_GET_PIN_COUNT           DLN_BUILD_MSG_ID(0x01, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PORT_SET_CFG			DLN_BUILD_MSG_ID(0x02, DLN_MODULE_GPIO)		///< Configure GPIO port
#define DLN_MSG_ID_GPIO_PORT_GET_CFG			DLN_BUILD_MSG_ID(0x03, DLN_MODULE_GPIO)		///< Get configuration of GPIO port
#define DLN_MSG_ID_GPIO_SET_DEBOUNCE			DLN_BUILD_MSG_ID(0x04, DLN_MODULE_GPIO)		///< Setup debounce parameter
#define DLN_MSG_ID_GPIO_GET_DEBOUNCE            DLN_BUILD_MSG_ID(0x05, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PORT_GET_VAL			DLN_BUILD_MSG_ID(0x06, DLN_MODULE_GPIO)		///< Get values currently present on the GPIO port pins
#define DLN_MSG_ID_GPIO_PORT_SET_OUT_VAL		DLN_BUILD_MSG_ID(0x07, DLN_MODULE_GPIO)		///< Set output value
#define DLN_MSG_ID_GPIO_PORT_GET_OUT_VAL        DLN_BUILD_MSG_ID(0x08, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_SET_CFG    			DLN_BUILD_MSG_ID(0x09, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_GET_CFG     		DLN_BUILD_MSG_ID(0x0A, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_GET_VAL				DLN_BUILD_MSG_ID(0x0B, DLN_MODULE_GPIO)		///< Get values currently present on the GPIO port pin
#define DLN_MSG_ID_GPIO_PIN_SET_OUT_VAL			DLN_BUILD_MSG_ID(0x0C, DLN_MODULE_GPIO)		///< Set output value
#define DLN_MSG_ID_GPIO_PIN_GET_OUT_VAL        	DLN_BUILD_MSG_ID(0x0D, DLN_MODULE_GPIO)

#define DLN_MSG_ID_GPIO_CONDITION_MET_EV  DLN_BUILD_MSG_ID(0x0F, DLN_MODULE_GPIO)

#define DLN_MSG_ID_GPIO_PIN_ENABLE                  DLN_BUILD_MSG_ID(0x10, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_DISABLE                 DLN_BUILD_MSG_ID(0x11, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_IS_ENABLED              DLN_BUILD_MSG_ID(0x12, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_SET_DIRECTION           DLN_BUILD_MSG_ID(0x13, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_GET_DIRECTION           DLN_BUILD_MSG_ID(0x14, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_OPENDRAIN_ENABLE        DLN_BUILD_MSG_ID(0x15, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_OPENDRAIN_DISABLE       DLN_BUILD_MSG_ID(0x16, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_OPENDRAIN_IS_ENABLED    DLN_BUILD_MSG_ID(0x17, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_PULLUP_ENABLE           DLN_BUILD_MSG_ID(0x18, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_PULLUP_DISABLE          DLN_BUILD_MSG_ID(0x19, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_PULLUP_IS_ENABLED       DLN_BUILD_MSG_ID(0x1A, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_DEBOUNCE_ENABLE         DLN_BUILD_MSG_ID(0x1B, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_DEBOUNCE_DISABLE        DLN_BUILD_MSG_ID(0x1C, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_DEBOUNCE_IS_ENABLED     DLN_BUILD_MSG_ID(0x1D, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_SET_EVENT_CFG           DLN_BUILD_MSG_ID(0x1E, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_GET_EVENT_CFG           DLN_BUILD_MSG_ID(0x1F, DLN_MODULE_GPIO)

#define DLN_MSG_ID_GPIO_PIN_PULLDOWN_ENABLE         DLN_BUILD_MSG_ID(0x20, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_PULLDOWN_DISABLE        DLN_BUILD_MSG_ID(0x21, DLN_MODULE_GPIO)
#define DLN_MSG_ID_GPIO_PIN_PULLDOWN_IS_ENABLED     DLN_BUILD_MSG_ID(0x22, DLN_MODULE_GPIO)

#define DLN_MSG_ID_GPIO_PIN_GET_SUPPORTED_EVENT_TYPES   DLN_BUILD_MSG_ID(0x40, DLN_MODULE_GPIO)


// validFields bitmask
#if 0 //changed to DLN_GPIO_*_BIT constants. Will be removed soon
    #define DLN_GPIO_ENABLED		(1<<0)	///< field 'isEnabled' of 'config' is populated
    #define DLN_GPIO_OUTPUT			(1<<1)	///< field 'isOutput' of 'config' is populated
    #define DLN_GPIO_OUTPUT_VAL		(1<<2)	///< field 'outputValue' of 'config' is populated
    #define DLN_GPIO_OPEN_DRAIN		(1<<3)	///< field 'isOpenDrain' of 'config' is populated
    #define DLN_GPIO_PULLUP_EN		(1<<4)	///< field 'isPullUpEnable' of 'config' is populated
    #define DLN_GPIO_DEBOUNCE_EN		(1<<5)	///< field 'isDebounceEnable' of 'config' is populated
    #define DLN_GPIO_EVENT_TYPE		(1<<8)	///< field 'eventType' of 'config' is populated
    #define DLN_GPIO_EVENT_PERIOD		(1<<9)	///< field 'eventPeriod' of 'config' is populated
#endif
//configuration bit's name(for "conflict", "valid" and "config" variables)
#define DLN_GPIO_ENABLE_BIT		(1<<0)	///< field 'isEnabled' of 'config' is populated
#define DLN_GPIO_OUTPUT_BIT		(1<<1)	///< field 'isOutput' of 'config' is populated
#define DLN_GPIO_OUTPUT_VAL_BIT		(1<<2)	///< field 'outputValue' of 'config' is populated
#define DLN_GPIO_OPEN_DRAIN_BIT		(1<<3)	///< field 'isOpenDrain' of 'config' is populated
#define DLN_GPIO_PULL_UP_BIT		(1<<4)	///< field 'isPullUpEnable' of 'config' is populated
#define DLN_GPIO_DEBOUNCE_BIT		(1<<5)	///< field 'isDebounceEnable' of 'config' is populated
#define DLN_GPIO_PULL_DOWN_BIT		(1<<6)	///< field 'isPullDownEnable' of 'config' is populated
#define DLN_GPIO_EVENT_TYPE_BIT		(1<<8)	///< field 'eventType' of 'config' is populated
#define DLN_GPIO_EVENT_PERIOD_BIT	(1<<9)	///< field 'eventPeriod' of 'config' is populated
#define DLN_GPIO_ALL_FIELDS 0xFFFF
#define DLN_GPIO_VALID_FIELDS 0x37F

//GPIO pin configuration
#define DLN_GPIO_ENABLED		    (1<<0)	///< pin is enabled
#define DLN_GPIO_DISABLED	    (0<<0)	///< pin is disabled
#define DLN_GPIO_OUTPUT		    (1<<1)	///< pin is configured for output
#define DLN_GPIO_INPUT		    (0<<1)	///< pin is configured for input
#define DLN_GPIO_OUTPUT_VAL_1	    (1<<2)	///< pin output value is 1
#define DLN_GPIO_OUTPUT_VAL_0	    (0<<2)	///< pin output value is 0
#define DLN_GPIO_OPEN_DRAIN_ENABLED  (1<<3)	///< pin is configured as open drain
#define DLN_GPIO_OPEN_DRAIN_DISABLED (0<<3)	///< pin isn't configured as open drain
#define DLN_GPIO_PULLUP_ENABLED	    (1<<4)	///< pin is configured as pull up
#define DLN_GPIO_PULLUP_DISABLED	    (0<<4)	///< pin isn't configured as pull up
#define DLN_GPIO_DEBOUNCE_ENABLED	    (1<<5)	///< debouncing filter is enabled for the pin
#define DLN_GPIO_DEBOUNCE_DISABLED 	    (0<<5)	///< glitch filter is enabled for the pin
#define DLN_GPIO_PULLDOWN_ENABLED	    (1<<6)	///< pin is configured as pull down
#define DLN_GPIO_PULLDOWN_DISABLED	    (0<<6)	///< pin isn't configured as pull dowm
#define DLN_GPIO_EVENT_ENABLED	    (1<<8)	///< events is enabled
#define DLN_GPIO_EVENT_DISABLED     (0<<8)	///< events is disabled
#define DLN_GPIO_EVENT_PERIODIC        (1<<9)	///< generating of events periodically
#define DLN_GPIO_EVENT_SINGLE         (0<<9)	///< generating of one event

// event type
#define DLN_GPIO_EVENT_NONE			0       ///< No events are generated.
#define DLN_GPIO_EVENT_CHANGE			1       ///< Events are generated when the level on the digital input line changes.
#define DLN_GPIO_EVENT_LEVEL_HIGH		2       ///< Events are generated when the high level (logical 1) is detected on the digital input line.
#define DLN_GPIO_EVENT_LEVEL_LOW		3       ///< Events are generated when the low level (logical 0) is detected on the digital input line.
#define DLN_GPIO_EVENT_ALWAYS			4       ///< Events are generated continuously, regardless of the signal level.

/*!
\struct DLN_GPIO_GET_PORT_COUNT_CMD
 The command retrieves the number of GPIO ports available in the DLN-series adapter.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
} __PACKED_ATTR DLN_GPIO_GET_PORT_COUNT_CMD;

/*!
\struct DLN_GPIO_GET_PORT_COUNT_RSP
 The response contains the available number of GPIO ports.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
												///  Possible values:
												///  DLN_RES_SUCCESS - the GPIO port count has been successfully retrieved.
    uint8_t count;								///< Contains the available number of the GPIO ports.
} __PACKED_ATTR DLN_GPIO_GET_PORT_COUNT_RSP;

/*!
\struct DLN_GPIO_GET_PIN_COUNT_CMD
 The command retrieves the total number of GPIO pins available in the DLN-series adapter.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
} __PACKED_ATTR DLN_GPIO_GET_PIN_COUNT_CMD;

/*!
\struct DLN_GPIO_GET_PIN_COUNT_RSP
 The response contains the available number of GPIO pins.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t count;								///< Contains the available number of pins.
} __PACKED_ATTR DLN_GPIO_GET_PIN_COUNT_RSP;

/*!
\struct DLN_GPIO_PORT_CONFIG
This structure is used to store configuration of GPIO pins from a port.
 */
/*
typedef struct
{
        uint8_t isEnabled;						///< Defines whether the pins are configured as general purpose inputs/outputs.
        uint8_t isOutput;                       ///< Defines whether the pins are configured as inputs or as outputs.
        uint8_t outputValue;                    ///< Defines the output value on the pins.
        uint8_t isOpenDrain;                    ///< Defines whether the output is push pull or open drain.
        uint8_t isPullUpEnabled;                ///< Defines whether the pull-up resistors are on or off.
        uint8_t isDebounceEnabled;              ///< Defines whether the debounce algorithm is implemented or not.
        uint8_t eventType[DLN_PORT_WIDTH];      ///< This is an 8-element array. Each element defines the condition of the event generation for the corresponding pin.
        uint16_t eventPeriod[DLN_PORT_WIDTH];   ///< This is an 8-element array. Each element defines the repeat interval for DLN_GPIO_EVENT event generation on the current pin.
} __PACKED_ATTR DLN_GPIO_PORT_CONFIG;
*/

/*!
\struct DLN_GPIO_PIN_CONFIG
This structure is used to store configuration of a single GPIO pin.
*/
typedef struct
{
    uint16_t cfg;								///< A bit field that defines the pin configuration.
    uint8_t eventType;							///< Defines the condition of event generation for the pin.
    uint16_t eventPeriod;       				///< Defines the repeat interval for DLN_GPIO_CONDIION_MET event generation on the pin.
} __PACKED_ATTR DLN_GPIO_PIN_CONFIG;			

/*!
\struct DLN_GPIO_PORT_CONFIG
This structure is used to store configuration of GPIO pins from a single port.
*/
typedef struct
{
    DLN_GPIO_PIN_CONFIG pins[8];				///< An 8-element array.
												///  Each of its elements corresponds to DLN_GPIO_PIN_CONFIG structure for each pin of the port.
} __PACKED_ATTR DLN_GPIO_PORT_CONFIG;

/*!
\struct DLN_GPIO_SET_PIN_CFG_CMD
 The command changes the configuration of a single GPIO pin and sets the conditions of DLN_GPIO_EVENT generation.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A pin to be configured.
    uint16_t validFields;						///< A bit field that defines the configuration parameters to be updated by this function.
    DLN_GPIO_PIN_CONFIG config;					///< A configuration to be set.
} __PACKED_ATTR DLN_GPIO_PIN_SET_CFG_CMD;

/*!
\struct DLN_GPIO_SET_PIN_CFG_RSP
 The response informs a user if the settings were successfully configured.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.												
    uint16_t conflict;                          ///< Contains the set of unsupported bits which intersect with validFields
} __PACKED_ATTR DLN_GPIO_PIN_SET_CFG_RSP;

/*!
\struct DLN_GPIO_GET_PIN_CFG_CMD
The command retrieves the current configuration settings of a single GPIO pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A pin to get the configuration from.
} __PACKED_ATTR DLN_GPIO_PIN_GET_CFG_CMD;

/*!
\struct DLN_GPIO_GET_PIN_CFG_RSP
The response contains current configuration of the specified GPIO pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    DLN_GPIO_PIN_CONFIG config;					///< Contains the pin configuration
} __PACKED_ATTR DLN_GPIO_PIN_GET_CFG_RSP;

/*!
\struct DLN_GPIO_SET_PORT_CFG_CMD
The command is used to change the configuration of the GPIO pins from the specified port and set the conditions of the DLN_GPIO_CONDITION_MET event generation.
*/
typedef struct
{
        DLN_MSG_HEADER header;					///< Defines the DLN message header.
        uint8_t port;							///< The port whose pins will be configured.
        uint8_t mask;							///< Defines, which I/O lines are to be configured.
        uint16_t validFields;					///< Fields in 'config' which should be processed.
        DLN_GPIO_PORT_CONFIG config;			///< A configuration to be set.
} __PACKED_ATTR DLN_GPIO_PORT_SET_CFG_CMD;

/*!
\struct DLN_GPIO_SET_PORT_CFG_RSP
The response informs a user if the settings were successfully configured.

result can hold the following values:
DLN_RES_SUCCESS
DLN_RES_INVALID_COMMAND_SIZE
DLN_RES_INVALID_PORT_NUMBER
DLN_RES_INVALID_EVENT_TYPE
DLN_RES_PIN_IN_USE
DLN_RES_PIN_NOT_CONNECTED_TO_MODULE
*/
typedef struct
{
        DLN_MSG_HEADER header;				///< Defines the DLN message header.
        DLN_RESULT result;					///< Contains the result of the command execution.
        uint16_t conflictedPin;				///< A number of a conflicted pin of the port, if any.
} __PACKED_ATTR DLN_GPIO_PORT_SET_CFG_RSP;

/*!
\struct DLN_GPIO_GET_PORT_CFG_CMD
The command is used to retrieve the current configuration settings of a GPIO port.
*/
typedef struct
{
        DLN_MSG_HEADER header;				///< Defines the DLN message header.
        uint8_t port;						///< The port to get configuration from.
} __PACKED_ATTR DLN_GPIO_PORT_GET_CFG_CMD;

/*!
\struct DLN_GPIO_GET_PORT_CFG_RSP
The response contain the port configuration settings.
*/
typedef struct
{
        DLN_MSG_HEADER header;				///< Defines the DLN message header.
        DLN_RESULT result;					///< Contains the result of the command execution.
        DLN_GPIO_PORT_CONFIG config;		///< Contains the port configuration.
} __PACKED_ATTR DLN_GPIO_PORT_GET_CFG_RSP;

/*!
\struct DLN_GPIO_SET_DEBOUNCE_CMD
The command specifies the minimum duration of the pulse to be registered.
*/
typedef struct
{
        DLN_MSG_HEADER header;				///< Defines the DLN message header.
        uint32_t duration;              	///< Minimum duration of the pulse to be registered (µs).
} __PACKED_ATTR DLN_GPIO_SET_DEBOUNCE_CMD;

/*!
\struct DLN_GPIO_SET_DEBOUNCE_RSP
 The response contains the minimum pulse duration.
*/
typedef struct
{
        DLN_MSG_HEADER header;				///< Defines the DLN message header.
        DLN_RESULT result;					///< Contains the result of the command execution.
        uint32_t duration;					///< Minimum duration of the pulse to be registered, approximated as the closest to user-defined value.
} __PACKED_ATTR DLN_GPIO_SET_DEBOUNCE_RSP;

/*!
\struct DLN_GPIO_GET_DEBOUNCE_CMD_CMD
The command retrieves the debounce interval
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
} __PACKED_ATTR DLN_GPIO_GET_DEBOUNCE_CMD;

/*!
\struct DLN_GPIO_GET_DEBOUNCE_RSP_RSP
The response contains the debounce interval
*/
typedef struct
{
    DLN_MSG_HEADER header; ///< Defines the DLN message header.
    DLN_RESULT result; ///< Contains the result of the command execution.
    uint32_t duration; ///< Minimum duration of the pulse to be registered, approximated as the closest to user-defined value.
} __PACKED_ATTR DLN_GPIO_GET_DEBOUNCE_RSP;

/*!
\struct DLN_GPIO_SET_PORT_OUT_VAL_CMD
 The command is used to set the output values for the specified GPIO port pins.
*/
typedef struct
{
        DLN_MSG_HEADER header;				///< Defines the DLN message header.
        uint8_t port;						///< The port whose pins will be configured.
        uint8_t mask;						///< A bit field that defines, which I/O lines are to be configured.
        uint8_t values;						///< A bit field, which contains new port output values to be set.
} __PACKED_ATTR DLN_GPIO_PORT_SET_OUT_VAL_CMD;

/*!
\struct DLN_GPIO_SET_PORT_OUT_VAL_RSP
The response informs if the settings were successfully configured.
*/
typedef struct
{
        DLN_MSG_HEADER header;				///< Defines the DLN message header.
        DLN_RESULT result;					///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PORT_SET_OUT_VAL_RSP;

/*!
\struct DLN_GPIO_GET_PORT_VAL_CMD
The command retrieves current values on the GPIO pins.
*/
typedef struct
{
        DLN_MSG_HEADER header;					///< Defines the DLN message header.
        uint8_t port;							///< The port to get the pin values from.
} __PACKED_ATTR DLN_GPIO_PORT_GET_VAL_CMD;

/*!
\struct DLN_GPIO_GET_PORT_VAL_RSP
The response contains current values on the pins.
*/
typedef struct
{
        DLN_MSG_HEADER header;                  ///< Defines the DLN message header.
        DLN_RESULT result;						///< Contains the result of the command execution.
        uint8_t port;							///< A port to get the pin values from.
        uint8_t values;     					///< A bit field, which contains the current pin values for the port.
} __PACKED_ATTR DLN_GPIO_PORT_GET_VAL_RSP;

/*!
\struct DLN_GPIO_GET_PORT_OUT_VAL_CMD
The command retrieves the port's pin output values, stored in internal latches
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint8_t port;								///< A port to get the pin output values from.
} __PACKED_ATTR DLN_GPIO_PORT_GET_OUT_VAL_CMD;

/*!
\struct DLN_GPIO_GET_PORT_OUT_VAL_RSP
The response contains output values on the pins.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint8_t port;								///< A port to get the pin output values from.
    uint8_t values;								///< A bit field, which contains the pin output values for the port.
} __PACKED_ATTR DLN_GPIO_PORT_GET_OUT_VAL_RSP;

/*!
\struct DLN_GPIO_SET_PIN_OUT_VAL_CMD
The command sets the output value for the specified pin.
*/
typedef struct
{
        DLN_MSG_HEADER header;					///< Defines the DLN message header.
        uint16_t pin;							///< A pin to be configured.
        uint8_t value;							///< A pin output value to be set.
} __PACKED_ATTR DLN_GPIO_PIN_SET_OUT_VAL_CMD;

/*!
\struct DLN_GPIO_SET_PIN_OUT_VAL_RSP
The response informs if the setting has been successfully configured.
*/
typedef struct
{
        DLN_MSG_HEADER header;					///< Defines the DLN message header.
        DLN_RESULT result;						///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_SET_OUT_VAL_RSP;

/*!
\struct DLN_CMD_GPIO_GET_PIN_VAL_CMD
The command retrieves the current value on the specified GPIO pin.
*/
typedef struct
{
        DLN_MSG_HEADER header;					///< Defines the DLN message header.
        uint16_t pin;							///< A pin to get the value from.
} __PACKED_ATTR DLN_GPIO_PIN_GET_VAL_CMD;

/*!
\struct DLN_CMD_GPIO_GET_PIN_VAL_RSP
The response contains the current value on the specified pin.
*/
typedef struct
{
        DLN_MSG_HEADER header;                  ///< Defines the DLN message header.
        DLN_RESULT result;						///< Contains the result of the command execution.
        uint16_t pin;							///< A pin to get the value from.
        uint8_t value;     						///< The current value on the pin.
} __PACKED_ATTR DLN_GPIO_PIN_GET_VAL_RSP;
/*!
\struct DLN_GPIO_GET_PIN_OUT_VAL_CMD
The command retrieves the pin output value, stored in the internal latch.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A pin to get the output value from.
} __PACKED_ATTR DLN_GPIO_PIN_GET_OUT_VAL_CMD;

/*!
 \struct DLN_GPIO_GET_PIN_OUT_VAL_RSP
 The response contains the output value on the pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< A pin to get the output value from.
    uint8_t value;								///< The output value on the pin.
} __PACKED_ATTR DLN_GPIO_PIN_GET_OUT_VAL_RSP;

/*!
\struct DLN_GPIO_CONDITION_MET_EV
The GPIO event structure
*/
typedef struct
{
        DLN_MSG_HEADER header;  				///< Defines the DLN message header.
        uint16_t eventCount;    				///< The  number  of  generated  events  since  the  previous  level  change.
        uint8_t eventType;      				///< The type of event to be generated.
        uint16_t pin;            				///< The number of the pin which caused the event generation.
        uint8_t value;          				///< The current  value  of  the pin.
} __PACKED_ATTR DLN_GPIO_CONDITION_MET_EV;

/*!
\struct DLN_GPIO_PIN_ENABLE_CMD
The command is used to configure a pin as general purpose input/output.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_ENABLE_CMD;

/*!
\struct DLN_GPIO_PIN_ENABLE_RSP
The response informs if the pin has been successfully configured as general purpose input/output.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_ENABLE_RSP;

/*!
\struct DLN_GPIO_PIN_DISABLE_CMD
The command is used to disable a pin as general purpose input/output.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_DISABLE_CMD;

/*!
\struct DLN_GPIO_PIN_DISABLE_RSP;
The response informs if the pin has been successfully disabled as general purpose input/output.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_DISABLE_RSP;

/*!
\struct DLN_GPIO_PIN_IS_ENABLED_CMD
The command is used to retrieve information on whether a pin is configured as general purpose input/output.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A pin to retrieve the information from.
} __PACKED_ATTR DLN_GPIO_PIN_IS_ENABLED_CMD;

/*!
\struct DLN_GPIO_PIN_IS_ENABLED_RSP;
The response informs whether the specified pin is configured as general purpose input/output.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains the number of the pin.
    uint8_t enabled;							///< Contains the current configuration of the pin.
} __PACKED_ATTR DLN_GPIO_PIN_IS_ENABLED_RSP;

/*!
\struct DLN_GPIO_PIN_SET_DIRECTION_CMD
The command is used to configure the pin as input or as output.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to set direction for.
    uint8_t direction;							///< Must contain the new direction of the pin.
} __PACKED_ATTR DLN_GPIO_PIN_SET_DIRECTION_CMD;

/*!
\struct DLN_GPIO_PIN_SET_DIRECTION_RSP
The response informs if the pin direction has been successfully set.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_SET_DIRECTION_RSP;

/*!
\struct DLN_GPIO_PIN_GET_DIRECTION_CMD
The command is used to retrieve currently set direction of the pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to retrieve the information from.
} __PACKED_ATTR DLN_GPIO_PIN_GET_DIRECTION_CMD;

/*!
\struct DLN_GPIO_PIN_GET_DIRECTION_RSP
The response contains currently selected direction of the specified pin
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains the number of the pin.
    uint8_t direction;							///< Contains the currently set direction of the specified pin.
} __PACKED_ATTR DLN_GPIO_PIN_GET_DIRECTION_RSP;

/*!
\struct DLN_GPIO_PIN_OPENDRAIN_ENABLE_CMD
The command is used to enable open drain mode for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_OPENDRAIN_ENABLE_CMD;

/*!
\struct DLN_GPIO_PIN_OPENDRAIN_ENABLE_RSP
The response informs if the open drain mode has been successfully enabled for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_OPENDRAIN_ENABLE_RSP;

/*!
\struct DLN_GPIO_PIN_OPENDRAIN_DISABLE_CMD
The command is used to disable the open drain mode for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_OPENDRAIN_DISABLE_CMD;

/*!
\struct DLN_GPIO_PIN_OPENDRAIN_DISABLE_RSP
The response informs if the open drain mode has been successfully disabled for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_OPENDRAIN_DISABLE_RSP;

/*!
\struct DLN_GPIO_PIN_OPENDRAIN_IS_ENABLED_CMD
The command is used to retrieve information on whether the open drain mode is enabled for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to retrieve the information from.
} __PACKED_ATTR DLN_GPIO_PIN_OPENDRAIN_IS_ENABLED_CMD;

/*!
\struct DLN_GPIO_PIN_OPENDRAIN_IS_ENABLED_RSP
The response informs a user whether the open drain mode is enabled for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains the number of the pin.
    uint8_t enabled;							///< Contains the current configuration of the pin.
} __PACKED_ATTR DLN_GPIO_PIN_OPENDRAIN_IS_ENABLED_RSP;

/*!
\struct DLN_GPIO_PIN_PULLUP_ENABLE_CMD
The command is used to enable embedded pull-up resistor for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_PULLUP_ENABLE_CMD;

/*!
\struct DLN_GPIO_PIN_PULLUP_ENABLE_RSP
The response informs a user if a pull-up resistor has been successfully activated for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_PULLUP_ENABLE_RSP;

/*!
\struct DLN_GPIO_PIN_PULLUP_DISABLE_CMD
The command is used to disable the embedded pull-up resistor for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.		
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_PULLUP_DISABLE_CMD;

/*!
\struct DLN_GPIO_PIN_PULLUP_DISABLE_RSP
The response informs a user if the embedded pull-up resistor has been successfully disabled for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_PULLUP_DISABLE_RSP;

/*!
\struct DLN_GPIO_PIN_PULLUP_IS_ENABLED_CMD
The command is used to retrieve information on whether the embedded pull-up resistor is currently activated for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_PULLUP_IS_ENABLED_CMD;

/*!
\struct DLN_GPIO_PIN_PULLUP_IS_ENABLED_RSP
The response informs a user whether the embedded pull-up resistor is enabled for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains the number of the pin.
    uint8_t enabled;							///< Contains the current configuration of the pin.
} __PACKED_ATTR DLN_GPIO_PIN_PULLUP_IS_ENABLED_RSP;

/*!
\struct DLN_GPIO_PIN_DEBOUNCE_ENABLE_CMD
The command is used to enable debounce filtering for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_DEBOUNCE_ENABLE_CMD;

/*!
\struct DLN_GPIO_PIN_DEBOUNCE_ENABLE_RSP
The response informs a user if debounce filtering has been successfully activated for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_DEBOUNCE_ENABLE_RSP;

/*!
\struct DLN_GPIO_PIN_DEBOUNCE_DISABLE_CMD
The command is used to disable debounce filtering for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_DEBOUNCE_DISABLE_CMD;

/*!
\struct DLN_GPIO_PIN_DEBOUNCE_DISABLE_RSP
The response informs if debounce filtering has been successfully deactivated for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_DEBOUNCE_DISABLE_RSP;

/*!
\struct DLN_GPIO_PIN_DEBOUNCE_IS_ENABLED_CMD
The command is used to retrieve information on whether debounce filtering is currently activated for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_DEBOUNCE_IS_ENABLED_CMD;

/*!
\struct DLN_GPIO_PIN_DEBOUNCE_IS_ENABLED_RSP
The response informs a user whether debounce filtering is currently enabled for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains the number of the pin.
    uint8_t enabled;							///< Contains the current configuration of the pin.
} __PACKED_ATTR DLN_GPIO_PIN_DEBOUNCE_IS_ENABLED_RSP;

/*!
\struct DLN_GPIO_PIN_SET_EVENT_CFG_CMD;
The command is used to configure the event generation conditions for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to set direction for.
    uint8_t eventType;							///< Must contain the condition for event generation for the pin.
    uint16_t eventPeriod;						///< Must contain the repeat interval for event generation on the pin.
} __PACKED_ATTR DLN_GPIO_PIN_SET_EVENT_CFG_CMD;

/*!
\struct DLN_GPIO_PIN_SET_EVENT_CFG_RSP
The response informs if the event generation conditions for the pin have been successfully set.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_SET_EVENT_CFG_RSP;

/*!
\struct DLN_GPIO_PIN_GET_EVENT_CFG_CMD
The command is used to retrieve currently set event generation conditions for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to retrieve the information from.
} __PACKED_ATTR DLN_GPIO_PIN_GET_EVENT_CFG_CMD;

/*!
\struct DLN_GPIO_PIN_GET_EVENT_CFG_RSP
The response contains currently set event generation conditions for the specified pin.
*/
typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains a number of the pin.
    uint8_t eventType;							///< Contains the event generation condition for the pin.
    uint16_t eventPeriod;						///< Contains the repeat interval for event generation on the pin.
} __PACKED_ATTR DLN_GPIO_PIN_GET_EVENT_CFG_RSP;



typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_PULLDOWN_ENABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_PULLDOWN_ENABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_PULLDOWN_DISABLE_CMD;

typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
} __PACKED_ATTR DLN_GPIO_PIN_PULLDOWN_DISABLE_RSP;


typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< A number of the pin to be configured.
} __PACKED_ATTR DLN_GPIO_PIN_PULLDOWN_IS_ENABLED_CMD;

typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains the number of the pin.
    uint8_t enabled;							///< Contains the current configuration of the pin.
} __PACKED_ATTR DLN_GPIO_PIN_PULLDOWN_IS_ENABLED_RSP;


typedef struct
{
    uint8_t count;
    uint8_t eventTypes[8];
} __PACKED_ATTR DLN_GPIO_PIN_EVENT_TYPES;

typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    uint16_t pin;								///< Contains the number of the pin.
} __PACKED_ATTR DLN_GPIO_PIN_GET_SUPPORTED_EVENT_TYPES_CMD;

typedef struct
{
    DLN_MSG_HEADER header;						///< Defines the DLN message header.
    DLN_RESULT result;							///< Contains the result of the command execution.
    uint16_t pin;								///< Contains the number of the pin.
    DLN_GPIO_PIN_EVENT_TYPES supportedEventTypes;///< Contains supported event types for the pin.
} __PACKED_ATTR DLN_GPIO_PIN_GET_SUPPORTED_EVENT_TYPES_RSP;


/*!
Retrieves the total number of the GPIO ports available in the DLN-series device.
\param handle - a handle to the DLN-series adapter;
\param count - a pointer to an unsigned 8-bit integer. This integer will be filled with the number of available ports after function execution;
\retval DLN_RES_SUCCESS - the port count has been successfully retrieved.
*/
DLN_RESULT DlnGpioGetPortCount(HDLN handle, uint8_t *count);
/*!
Retrieves the total number of GPIO pins available in the DLN-series device.
\param handle - a handle to the DLN-series adapter;
\param count - a pointer to an unsigned 16-bit integer. This integer will be filled with the number of available pins after function execution;
\retval DLN_RES_SUCCESS - the pin count has been successfully retrieved.
*/
DLN_RESULT DlnGpioGetPinCount(HDLN handle, uint16_t *count);

/*!
Changes the configuration of the specified GPIO pin.
\param handle - A handle to the DLN-series adapter.
\param pin - A pin number to be configured.
\param validFields - A bit field that defines valid DLN_GPIO_PIN_CONFIG structure members.
\param config - A configuration to be set.
\retval DLN_RES_SUCCESS - The new configuration has been successfully applied.
\retval DLN_RES_INVALID_HANDLE - The specified handle is not valid.
\retval DLN_RES_CONNECTION_LOST - The connection to the DLN server was interrupted.
\retval DLN_RES_INVALID_PIN_NUMBER - The number of the pin is out of range. Use DLN_GpioGetPinCount() function to get the number
    of the pins available for current DLN-series adapter.
\retval DLN_RES_NON_ZERO_REZERVED_BIT - One or more of the reserved bits in validFields or in config parameters are set to 1.
*/
DLN_RESULT DlnGpioPinSetCfg(HDLN handle, uint16_t pin, uint16_t validFields, DLN_GPIO_PIN_CONFIG config);

/*!
Retrieves current configuration of the specified  GPIO pin.
\param handle - a handle to the DLN-series adapter.
\param pin - a pin number to get configuration for.
\param config - a pointer to the DLN_GPIO_PIN_CONFIG structure, which will be filled with the pin configuration after function execution.
\retval DLN_RES_SUCCESS - the configuration has been successfully retrieved.
\retval DLN_RES_INVALID_HANDLE - the specified handle is not valid.
\retval DLN_RES_CONNECTION_LOST - the connection to the DLN server was interrupted.
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinGetCfg(HDLN handle, uint16_t pin, DLN_GPIO_PIN_CONFIG *config);

/*!
Retrieves current configuration of the GPIO pins from the specified port.
\param handle - a handle to the DLN-series adapter;
\param port - a port to get configuration for;
\param config - a pointer to the DLN_GPIO_PORT_CONFIG structure, which will be filled with the configuration after function execution.
*/
DLN_RESULT DlnGpioPortGetCfg(HDLN handle, uint8_t port, DLN_GPIO_PORT_CONFIG *config);
/*!
Changes the configuration of the GPIO pins from the specified port.
\param handle - a handle to the DLN-series adapter;
\param validFields - a bit field that defines valid DLN_GPIO_PORT_CONFIG fields;
\param port - a port, whose I/O lines are to be configured;
\param mask -  a bit field that defines, which I/O lines are to be configured;
\param config - a configuration to be set. See "DLN_GPIO_PORT_CONFIG structure" for details.
\param conflictedPin - A number of the conflicted pin, if any.
*/

DLN_RESULT DlnGpioPortSetCfg(HDLN handle, uint8_t port, uint8_t mask, uint16_t validFields, DLN_GPIO_PORT_CONFIG config, uint16_t *conflictedPin);
/*!
Retrieves current level on the I/O lines from the specified port.
\param handle - a handle to the DLN-series adapter;
\param port - a port to get pin values from;
\param values - a pointer to an unsigned 8-bit integer. This integer will be filled with the pin values after function execution.
*/
DLN_RESULT DlnGpioPortGetVal(HDLN handle, uint8_t port, uint8_t *values);
/*!
Sets output values for I/O lines from the specified GPIO port.
\param handle - a handle to the DLN-series adapter;
\param port - a port, whose output values are to be changed;
\param mask - a bit field that defines I/O lines, whose output values are to be changed;
\param values - values to be set.
*/
DLN_RESULT DlnGpioPortSetOutVal(HDLN handle, uint8_t port, uint8_t mask, uint8_t values);
/*!
Retrieves current output values for the GPIO pins from the specified port.
\param handle - a handle to the DLN-series adapter;
\param port - a port to get pin output values from;
\param values - a pointer to an unsigned 8-bit integer. This integer will be filled with pin output values after function execution.
*/
DLN_RESULT DlnGpioPortGetOutVal(HDLN handle, uint8_t port, uint8_t *values);

/*!
Specifies the minimum duration of the pulse to be registered (the Debounce interval).
\param handle - a handle to the DLN-series adapter;
\param duration - debounce duration unsigned 32-bit integer value;
\parma realDuration - a pointer to an unsigned 32-bit integer. This integer will be filled with the value, approximated (increased) as the closest debounce duration supported by the adapter after the function execution;
\retval DLN_RES_SUCCESS - the debounce interval has been successfully set;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - the debounce is not supported in the adapter.
*/
DLN_RESULT DlnGpioSetDebounce(HDLN handle, uint32_t duration, uint32_t *realDuration);

/*!
Retrieves the current setting of the minimum duration of the pulse to be registered (the Debounce interval).
\param handle - a handle to the DLN-series adapter;
\param duration - a pointer to an unsigned 32-bit integer. This integer will be filled with the debounce interval value after the function execution;
\retval DLN_RES_SUCCESS - the debounce interval has been successfully retrieved;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - the adapter does not support debounce filtering.
*/
DLN_RESULT DlnGpioGetDebounce(HDLN handle, uint32_t *duration);

/*!
Retrieves the pin output value, stored in the internal latch.
\param handle - a handle to the DLN-series adapter;
\param pin - a pin to get the output value from;
\param value - a pointer to an unsigned 8-bit integer. This integer will be filled with the pin output value after the function execution;
\retval DLN_RES_SUCCESS - the pin output value has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinGetOutVal(HDLN handle, uint16_t pin, uint8_t *value);

/*!
Sets the output value for the specified GPIO pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a pin to be configured;
\param value - a pin output value to be set;
\retval DLN_RES_SUCCESS - the pin output value has been successfully set;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinSetOutVal(HDLN handle, uint16_t pin, uint8_t value);
/*!
Retrieves the current value on the specified GPIO pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a pin to get the value from;
\param value - a pointer to an unsigned 8-bit integer. This integer will be filled with the pin value after the function execution;
\retval DLN_RES_SUCCESS - the pin value has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_PIN_NOT_CONNECTED_TO_MODULE - the pin is not assigned to GPIO module of the adapter and its value cannot be retrieved.
*/
DLN_RESULT DlnGpioPinGetVal(HDLN handle, uint16_t pin, uint8_t *value);

/*!
Configures a pin as general purpose input/output.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to be configured;
\retval DLN_RES_SUCCESS - the GPIO pin has been successfully enabled;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_PIN_IN_USE - the pin is assigned to another module of the adapter and cannot be enabled as GPIO.
*/
DLN_RESULT DlnGpioPinEnable(HDLN handle, uint16_t pin);
/*!
Disables a pin as general purpose input/output.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to be configured;
\retval DLN_RES_SUCCESS - the GPIO pin has been successfully disabled;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_PIN_NOT_CONNECTED_TO_MODULE - the pin is not assigned to GPIO module of the adapter and cannot be disabled as GPIO.
*/
DLN_RESULT DlnGpioPinDisable(HDLN handle, uint16_t pin);
/*!
Informs whether a pin is currently configured as general purpose input/output.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to retrieve information about;
\param enabled - a pointer to an unsigned 8-bit integer. The integer will be filled with current pin configuration after the function execution;
\retval DLN_RES_SUCCESS - the pin information has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinIsEnabled(HDLN handle, uint16_t pin, uint8_t* enabled);

/*!
Configures a pin as input or as output.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the GPIO pin to be configured;
\param direction - direction of a pin, set to 0 for input or 1 for output.
\retval DLN_RES_SUCCESS - the pin direction has been successfully set;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinSetDirection(HDLN handle, uint16_t pin, uint8_t direction);
/*!
Retrieves current direction of a pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a pin to get the information from;
\param direction - A pointer to an unsigned 8-bit integer. The integer will be filled with the pin current direction after the function execution;
\retval DLN_RES_SUCCESS - the pin direction has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinGetDirection(HDLN handle, uint16_t pin, uint8_t* direction);

/*!
Enables Open Drain mode for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to be configured.
\retval DLN_RES_SUCCESS - the open drain mode has been successfully enabled;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified or the pin specified is not open drain capabile.
*/
DLN_RESULT DlnGpioPinOpendrainEnable(HDLN handle, uint16_t pin);
/*!
Disables Open Drain mode for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to be configured;
\retval DLN_RES_SUCCESS - the open drain has been successfully disabled;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified or the pin specified is open drain only.
*/
DLN_RESULT DlnGpioPinOpendrainDisable(HDLN handle, uint16_t pin);
/*!
Informs whether the pin output is currently configured as push pull or Open Drain.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to retrieve information about;
\param enabled - a pointer to an unsigned 8-bit integer. The integer will be filled with current pin configuration after the function execution;
\retval DLN_RES_SUCCESS - the open drain state has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinOpendrainIsEnabled(HDLN handle, uint16_t pin, uint8_t* enabled);

/*!
Activates an embedded pull-up resistor for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to enable a pull-up resistor for;
\retval DLN_RES_SUCCESS - the pull-up resistor has been successfully activated;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified or the pin specified have no pull-up resistor.
*/
DLN_RESULT DlnGpioPinPullupEnable(HDLN handle, uint16_t pin);
/*!
Deactivates an embedded pull-up resistor for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to disable a pull-up resistor for.
\retval DLN_RES_SUCCESS - the pull-up resistor has been successfully deactivated;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinPullupDisable(HDLN handle, uint16_t pin);
/*!
Informs whether an embedded pull-up resistor is enabled for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to retrieve the information from;
\param enabled - a pointer to an unsigned 8-bit integer. The integer will be filled with current state of a pull-up resistor after the function execution;
\retval DLN_RES_SUCCESS - the pull-up resistor state has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinPullupIsEnabled(HDLN handle, uint16_t pin, uint8_t* enabled);

/*!
Enables debounce filtering for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - number of the pin to be configured;
\retval DLN_RES_SUCCESS - the debounce has been successfully enabled;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - debounce filtering is unavailable for the adapter.
*/
DLN_RESULT DlnGpioPinDebounceEnable(HDLN handle, uint16_t pin);
/*!
Disables debounce filtering for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to be configured;
\retval DLN_RES_SUCCESS - the debounce has been successfully disabled;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - debounce filtering is unavailable for the adapter.
*/
DLN_RESULT DlnGpioPinDebounceDisable(HDLN handle, uint16_t pin);
/*!
Informs whether the debounce filtering is currently enabled for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - number of the pin to retrieve information about;
\param enabled - a pointer to an unsigned 8-bit integer. The integer will be filled with current pin configuration after the function execution;
\retval DLN_RES_SUCCESS - the debounce state has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - debounce is unavailable for the adapter.
*/
DLN_RESULT DlnGpioPinDebounceIsEnabled(HDLN handle, uint16_t pin, uint8_t* enabled);

/*!
Configures the event generation conditions for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to configure the event generation conditions for;
\param eventType - defines the condition for event generation for the pin;
\param eventPeriod - defines the repeat interval for event generation on the pin.
\retval DLN_RES_SUCCESS - the event conditions were successfully configured;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_INVALID_EVENT_TYPE - invalid event type was specified;
\retval DLN_RES_INVALID_EVENT_PERIOD - invalid event period was specified;
*/
DLN_RESULT DlnGpioPinSetEventCfg(HDLN handle, uint16_t pin, uint8_t eventType, uint16_t eventPeriod);
/*!
Retrieves current event generation conditions for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to retrieve the information from;
\param eventType - a pointer to an unsigned 8-bit integer. The integer will be filled with currently set event generation conditions for the pin after the function execution;
\param eventPeriod - a pointer to an unsigned 8-bit integer. The integer will be filled with current event repeat interval after the function execution;
\retval DLN_RES_SUCCESS - the event conditions were successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified.
*/
DLN_RESULT DlnGpioPinGetEventCfg(HDLN handle, uint16_t pin, uint8_t* eventType, uint16_t* eventPeriod);

/*!
Activates an embedded pull-down resistor for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to enable a pull-down resistor for;
\retval DLN_RES_SUCCESS - the pull-down has been successfully activated;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified or the pin specified have no pull-down resistor;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - pull-down resistors are unavailable for the adapter.
*/
DLN_RESULT DlnGpioPinPulldownEnable(HDLN handle, uint16_t pin);
/*!
Deactivates an embedded pull-down resistor for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to disable a pull-down resistor for;
\retval DLN_RES_SUCCESS - the pull-down has been successfully activated;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified or the pin specified have no pull-down resistor;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - pull-down resistors are unavailable for the adapter.
*/
DLN_RESULT DlnGpioPinPulldownDisable(HDLN handle, uint16_t pin);
/*!
Informs whether an embedded pull-down resistor is enabled for the specified pin.
\param handle - a handle to the DLN-series adapter;
\param pin - a number of the pin to retrieve the information from;
\param enabled - a pointer to an unsigned 8-bit integer. The integer will be filled with current state of a pull-down resistor after the function execution;
\retval DLN_RES_SUCCESS - the pull-down state has been successfully retrieved;
\retval DLN_RES_INVALID_PIN_NUMBER - invalid pin number was specified;
\retval DLN_RES_COMMAND_NOT_SUPPORTED - pull-down resistors are unavailable for the adapter.
*/
DLN_RESULT DlnGpioPinPulldownIsEnabled(HDLN handle, uint16_t pin, uint8_t* enabled);

DLN_RESULT DlnGpioPinGetSupportedEventTypes(HDLN handle, uint16_t pin, DLN_GPIO_PIN_EVENT_TYPES* supportedEventTypes);

#ifdef __ICCARM__
        #pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
        #pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif


#endif // DLN_GPIO_H
