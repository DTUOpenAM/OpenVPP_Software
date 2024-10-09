////////////////////////////////////////////////////////////////////////////////
//// Return codes
////////////////////////////////////////////////////////////////////////////////

#ifndef DLN_RESULTS_H
#define DLN_RESULTS_H

#if defined(_MSC_VER) && _MSC_VER < 1600
#include "stdint.h"
#else // _MSC_VER
#include <stdint.h>
#endif // _MSC_VER


typedef uint16_t DLN_RESULT;
#define DLN_RES_ERROR_C(x)                                  (((DLN_RESULT)(0x80 + (x))))
#define DLN_SUCCEEDED(Result)                               ((DLN_RESULT)(Result) < 0x40)
#define DLN_WARNING(Result)	                                (((DLN_RESULT)(Result) >= 0x20) && ((DLN_RESULT)(Result) < 0x40))
#define DLN_FAILED(Result)                                  ((DLN_RESULT)(Result) >= 0x40)

// Successful return codes  (DLN_RESULT<0x80)

#define DLN_RES_SUCCESS                                     ((DLN_RESULT)0)
#define DLN_RES_SUCCESSFUL_REINIT                           ((DLN_RESULT)1)
#define DLN_RES_PENDING                                     ((DLN_RESULT)2)
#define DLN_RES_TRANSFER_CANCELLED                          ((DLN_RESULT) 0x20)
#define DLN_RES_VALUE_ROUNDED                               ((DLN_RESULT) 0x21)

// Error codes  (DLN_RESULT>0x80)

#define DLN_RES_HARDWARE_NOT_FOUND                          ((DLN_RESULT)0x81)
#define DLN_RES_OUTDATED_DRIVER                             ((DLN_RESULT)0x82)
#define DLN_RES_FAIL                                        ((DLN_RESULT)0x83)
#define DLN_RES_MESSAGE_ABSENT                              ((DLN_RESULT)0x84)
#define DLN_RES_BAD_PARAMETER                               ((DLN_RESULT)0x85)
#define DLN_RES_MEMORY_ERROR                                ((DLN_RESULT)0x86)
#define DLN_RES_NOT_INITIALIZED                             ((DLN_RESULT)0x87)
#define DLN_RES_INVALID_COMMAND_SIZE                        ((DLN_RESULT)0x88)
#define DLN_RES_INVALID_RESPONSE_SIZE                       ((DLN_RESULT)0x89)
#define DLN_RES_INVALID_MESSAGE_SIZE                        ((DLN_RESULT)0x8A)
#define DLN_RES_NOTIFICATION_NOT_REGISTERED                 ((DLN_RESULT) 0x8B)
//#define DLN_RES_INVALID_STREAM_NUMBER ((DLN_RESULT) 0x8C)
// Use DLN_RES_RESPONSE_TIMEOUT instead of DLN_RES_TRANSACTION_TIMEOUT
#define DLN_RES_TRANSACTION_TIMEOUT                         ((DLN_RESULT) 0x8D)
#define DLN_RES_OPERATION_TIMEOUT                           DLN_RES_TRANSACTION_TIMEOUT
#define DLN_RES_RESPONSE_WAIT_TIMEOUT                       DLN_RES_TRANSACTION_TIMEOUT
#define DLN_RES_DEVICE_REMOVED                              ((DLN_RESULT) 0x8E)
#define DLN_RES_INVALID_HANDLE                              ((DLN_RESULT) 0x8F)
#define DLN_RES_INVALID_MESSAGE_TYPE                        ((DLN_RESULT) 0x90)

/*!
    DLN_RES_COMMAND_NOT_SUPPORTED is returned when current command is
    not supported by the DLN-series adapter.
    There are 2 possible reasons for DLN_RES_COMMAND_NOT_SUPPORTED:
    1) This command is not supported by this device type. If you need this
    functionality, you have to order another DLN-series adapter.
    2) You adapter has old firmware version. To enable this functionality simply
    update the device firmware.
*/
#define DLN_RES_NOT_IMPLEMENTED                             ((DLN_RESULT) 0x91)
#define DLN_RES_COMMAND_NOT_SUPPORTED                       DLN_RES_NOT_IMPLEMENTED
#define DLN_RES_TOO_MANY_CONNECTIONS                        ((DLN_RESULT) 0x92)
#define DLN_RES_ALREADY_INITIALIZED                         ((DLN_RESULT) 0x93)
/*!
    The specified host exists, but the library can't connect to the DLN server
    at this host. This can happen when DLN server is not running or its port differs
    from the specified one.
*/
#define DLN_RES_CONNECTION_FAILED                           ((DLN_RESULT) 0x94)
/*
    The DLN_RES_MUST_BE_DISABLED error code is returned when the module is enabled
    and application makes the configuration changes that are allowed only while
    module is disabled. For example SPI frame size can't be changed after you
    enable the SPI port.
    If you need to change this configuration settings you have to disable the module first.
*/
#define DLN_RES_MUST_BE_DISABLED                            ((DLN_RESULT) 0x95)
#define DLN_RES_INTERNAL_ERROR                              ((DLN_RESULT) 0x96)
#define DLN_RES_DEVICE_NUMBER_OUT_OF_RANGE                  ((DLN_RESULT) 0x97)
/*! The host name is longer that DLN_MAX_HOST_LENGTH chars */
#define DLN_RES_HOST_NAME_TOO_LONG                          ((DLN_RESULT) 0x98)
/*!
    The connection to the same DLN server exists.
    If the connection was broken and you want to restore it, close the original connection first.
    You can use the DlnDisconnect() function to close the original connection.
    Afterwards you can call the DlnConnect() function once again to reestablish the connection.
*/
#define DLN_RES_ALREADY_CONNECTED                           ((DLN_RESULT) 0x99)

#define DLN_RES_SINGLE_INSTANCE								((DLN_RESULT) 0x9A)
/*!
    Is is returned after the attempt of sending message through closed connection.
    Also it is possible to get it when using handle, which was created with custom connection and
    later this connection was closed (by calling DlnDisconnect() function, by loosing connection with DLN Server or if
    DLN Server service was stopped).
 */
#define DLN_RES_CONNECTION_LOST                             ((DLN_RESULT) 0xA0)
/*!
    It is returned by DlnDisconnect() function in case of no connection with specified server,
    DlnDisconnectAll() returns this result if there are no any connections,
    Also it is returned when you try to open device, if there are no connections with DLN server.
*/

#define DLN_RES_NOT_CONNECTED                               ((DLN_RESULT) 0xA1)
#define DLN_RES_MESSAGE_SENDING_FAILED                      ((DLN_RESULT) 0xA2)
#define DLN_RES_NO_FREE_STREAM                              ((DLN_RESULT) 0xA3)
// Server connection errors
/*! The specified host does not exist or it is impossible to determine its IP. */
#define DLN_RES_HOST_LOOKUP_FAILED                          ((DLN_RESULT) 0xA4)
#define DLN_RES_PIN_IN_USE                                  ((DLN_RESULT) 0xA5)
#define DLN_RES_INVALID_LED_NUMBER                          ((DLN_RESULT) 0xA6)
#define DLN_RES_INVALID_LED_STATE                           ((DLN_RESULT) 0xA7)
#define DLN_RES_INVALID_PORT_NUMBER                         ((DLN_RESULT) 0xA8)
#define DLN_RES_INVALID_EVENT_TYPE                          ((DLN_RESULT) 0xA9)

#define DLN_RES_PIN_NOT_CONNECTED_TO_MODULE                 ((DLN_RESULT) 0xAA)
#define DLN_RES_INVALID_PIN_NUMBER                          ((DLN_RESULT) 0xAB)
#define DLN_RES_INVALID_EVENT_PERIOD                        ((DLN_RESULT) 0xAC)
/*!
    Some commands and configuration settings has bit settings reserved for future.
    This bits must be set to zero. If DLN-series adapter founds that any of these bits is
    set to 1, it returns the DLN_RES_CONFIGURATION_NOT_SUPPORTED error code.
*/
#define DLN_RES_NON_ZERO_RESERVED_BIT                       ((DLN_RESULT) 0xAD)
#define DLN_RES_INVALID_BUFFER_SIZE                         ((DLN_RESULT) 0xAE)
#define DLN_RES_NO_FREE_DMA_CHANNEL                         ((DLN_RESULT) 0xAF)
//#define DLN_RES_SPI_DISABLED            ((DLN_RESULT) 0xB0)
//#define DLN_RES_INVALID_SS_OPERATION    ((DLN_RESULT) 0xB1)
//#define DLN_RES_INVALID_SS_NUMBER       ((DLN_RESULT) 0xB2)
#define DLN_RES_INVALID_PLANE_NUMBER                        ((DLN_RESULT) 0xB3)
#define DLN_RES_INVALID_ADDRESS                             ((DLN_RESULT) 0xB4)
#define DLN_RES_OVERFLOW                                    ((DLN_RESULT) 0xB5)
#define DLN_RES_BUSY                                        ((DLN_RESULT) 0xB6)
#define DLN_RES_DISABLED                                    ((DLN_RESULT) 0xB7)
#define DLN_RES_SPI_INVALID_FRAME_SIZE                      ((DLN_RESULT) 0xB8)
#define DLN_RES_INVALID_CHARACTER_LENGTH                    DLN_RES_SPI_INVALID_FRAME_SIZE
#define DLN_RES_SPI_MASTER_INVALID_SS_VALUE                 ((DLN_RESULT) 0xB9)
#define DLN_RES_SPI_MASTER_INVALID_SS_NUMBER                DLN_RES_SPI_MASTER_INVALID_SS_VALUE // obsolete
#define DLN_RES_I2C_MASTER_SENDING_ADDRESS_FAILED           ((DLN_RESULT) 0xBA)
#define DLN_RES_I2C_MASTER_SENDING_DATA_FAILED              ((DLN_RESULT) 0xBB)
#define DLN_RES_I2C_MASTER_INVALID_MEM_ADDRESS_LENGTH       ((DLN_RESULT) 0xBC)
#define DLN_RES_I2C_MASTER_ARBITRATION_LOST                 ((DLN_RESULT) 0xBD)
#define DLN_RES_I2C_SLAVE_ADDRESS_NEEDED                    ((DLN_RESULT) 0xBE)
#define DLN_RES_INVALID_RESOLUTION                          ((DLN_RESULT) 0xBF)
#define DLN_RES_INVALID_CHANNEL_NUMBER                      ((DLN_RESULT) 0xC0)
#define DLN_RES_CHANNEL_DISABLED                            ((DLN_RESULT) 0xC1)
#define DLN_RES_ALL_CHANNELS_DISABLED                       ((DLN_RESULT) 0xC2)
#define DLN_RES_INVALID_FREQUENCY                           ((DLN_RESULT) 0xC3)
#define DLN_RES_INVALID_BAUDRATE                            DLN_RES_INVALID_FREQUENCY
#define DLN_RES_PWM_INVALID_DUTY_CYCLE                      ((DLN_RESULT) 0xC4)
#define DLN_RES_INVALID_REPLY_TYPE                          ((DLN_RESULT) 0xC5)
#define DLN_RES_INVALID_DELAY_VALUE                         ((DLN_RESULT) 0xC6)
#define DLN_RES_INVALID_MODE                                ((DLN_RESULT) 0xC7)
#define DLN_RES_INVALID_CPOL                                ((DLN_RESULT) 0xC8)
#define DLN_RES_INVALID_CPHA                                ((DLN_RESULT) 0xC9)
#define DLN_RES_INVALID_TIMEOUT_VALUE                       ((DLN_RESULT) 0xCA)
#define DLN_RES_SPI_SLAVE_SS_IDLE_TIMEOUT                   ((DLN_RESULT) 0xCB)
#define DLN_RES_INVALID_PARITY                              ((DLN_RESULT) 0xCC)
#define DLN_RES_INVALID_STOPBITS                            ((DLN_RESULT) 0xCD)
#define DLN_RES_CONFIGURATION_NOT_SUPPORTED                 ((DLN_RESULT) 0xCE)
#define DLN_RES_NO_FREE_TIMER                               ((DLN_RESULT) 0xD0)
#define DLN_RES_VERIFICATION_ERROR                          ((DLN_RESULT) 0xD1)
#define DLN_RES_SOCKET_INITIALIZATION_FAILED                ((DLN_RESULT) 0xE0)
#define DLN_RES_INSUFFICIENT_RESOURCES                      ((DLN_RESULT) 0xE1)
#define DLN_RES_INVALID_VALUE                               ((DLN_RESULT) 0xE2)

#endif // DLN_RESULTS_H
