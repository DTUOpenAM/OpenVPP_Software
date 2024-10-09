#ifndef DLN_GENERIC_H
#define DLN_GENERIC_H
#include "dln.h"

#if defined(WIN32) && !defined(_NTDDK_) && !defined(DOT_NET)
#include <windows.h>
#elif defined(WIN64)
#include <windows.h>
#elif defined(Q_OS_WIN)
// we need nothing for QT5 under windows
#else
typedef unsigned long       DWORD;
typedef void *HWND;
typedef void *HANDLE;
typedef unsigned int        UINT;
#endif


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

#define DLN_PIN_ROLE_NOT_IN_USE  ((DLN_PIN_ROLE)0)


#define DLN_MSG_ID_REGISTER_NOTIFICATION DLN_BUILD_MSG_ID(0x00, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_UNREGISTER_NOTIFICATION DLN_BUILD_MSG_ID(0x01, DLN_MODULE_GENERIC)

#define DLN_MSG_ID_CONNECT				DLN_BUILD_MSG_ID(0x10, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_DISCONNECT			DLN_BUILD_MSG_ID(0x11, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_DISCONNECT_ALL		DLN_BUILD_MSG_ID(0x12, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_SRV_UUID			DLN_BUILD_MSG_ID(0x13, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_CLEANUP				DLN_BUILD_MSG_ID(0x14, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_CONNECTION_LOST_EV	DLN_BUILD_MSG_ID(0x1F, DLN_MODULE_GENERIC)


#define DLN_MSG_ID_GET_DEVICE_COUNT DLN_BUILD_MSG_ID(0x20, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_OPEN_DEVICE DLN_BUILD_MSG_ID(0x21, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_OPEN_STREAM DLN_BUILD_MSG_ID(0x22, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_CLOSE_HANDLE DLN_BUILD_MSG_ID(0x23, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_CLOSE_ALL_HANDLES DLN_BUILD_MSG_ID(0x24, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_DEVICE_REMOVED_EV DLN_BUILD_MSG_ID(0x2E, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_DEVICE_ADDED_EV DLN_BUILD_MSG_ID(0x2F, DLN_MODULE_GENERIC)


#define DLN_MSG_ID_GET_VER	DLN_BUILD_MSG_ID(0x30, DLN_MODULE_GENERIC)	///< Get HW, SW and protocol version
#define DLN_MSG_ID_GET_DEVICE_SN       DLN_BUILD_MSG_ID(0x31, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_SET_DEVICE_ID       DLN_BUILD_MSG_ID(0x32, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_DEVICE_ID       DLN_BUILD_MSG_ID(0x33, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_HARDWARE_TYPE		DLN_BUILD_MSG_ID(0x34, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_HARDWARE_VERSION	DLN_BUILD_MSG_ID(0x35, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_FIRMWARE_VERSION	DLN_BUILD_MSG_ID(0x36, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_SERVER_VERSION DLN_BUILD_MSG_ID(0x37, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_LIBRARY_VERSION DLN_BUILD_MSG_ID(0x38, DLN_MODULE_GENERIC)

#define DLN_MSG_ID_GET_PIN_CFG DLN_BUILD_MSG_ID(0x40, DLN_MODULE_GENERIC)

#define DLN_MSG_ID_GET_COMMAND_RESTRICTION      DLN_BUILD_MSG_ID(0x41, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_DELAY                        DLN_BUILD_MSG_ID(0x42, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_RESTART                      DLN_BUILD_MSG_ID(0x43, DLN_MODULE_GENERIC)

#define DLN_MSG_ID_SET_SRV_PARAMS               DLN_BUILD_MSG_ID(0x44, DLN_MODULE_GENERIC)
#define DLN_MSG_ID_GET_SRV_PARAMS               DLN_BUILD_MSG_ID(0x45, DLN_MODULE_GENERIC)


	////////////////////////////////////////////////////////////////////////////////
	//// Device types
	////////////////////////////////////////////////////////////////////////////////
#define DLN_HW_TYPE uint32_t
#define DLN_HW_TYPE_DLN5  ((DLN_HW_TYPE)0x0500)
#define DLN_HW_TYPE_DLN4M ((DLN_HW_TYPE)0x0401)
#define DLN_HW_TYPE_DLN4S ((DLN_HW_TYPE)0x0402)
#define DLN_HW_TYPE_DLN3  ((DLN_HW_TYPE)0x0300)
#define DLN_HW_TYPE_DLN2  ((DLN_HW_TYPE)0x0200)
#define DLN_HW_TYPE_DLN1  ((DLN_HW_TYPE)0x0100)

	//call back(handler of the asynchronous operations)
	typedef void (* PDLN_CALLBACK)(HDLN handle, void* context);
	typedef uint16_t DLN_NOTIFICATION_TYPE;
#define DLN_NOTIFICATION_TYPE_NO_NOTIFICATION ((DLN_NOTIFICATION_TYPE)0x00)
#define DLN_NOTIFICATION_TYPE_CALLBACK 0x01
#ifdef WIN32
#define DLN_NOTIFICATION_TYPE_EVENT_OBJECT 0x02
#define DLN_NOTIFICATION_TYPE_WINDOW_MESSAGE 0x03
#define DLN_NOTIFICATION_TYPE_THREAD_MESSAGE 0x04
#define DLN_NOTIFICATION_TYPE_LAB_VIEW_EVENT 0x05
#endif // WIN32


	typedef struct _DLN_NOTIFICATION
	{
		uint16_t type;
		union
		{
			struct
			{
				PDLN_CALLBACK function;
				void *context;
			} callback;
#ifdef WIN32
			HANDLE event;
			struct
			{
				HWND handle;
				UINT message;
			} windowMessage;
			struct
			{
				DWORD thread;
				UINT message;
			} threadMessage;
#endif // WIN32
			struct
			{
				void *eventRef;
			} labViewEvent;
			uint8_t reserved[64];
		};

	} __PACKED_ATTR DLN_NOTIFICATION;

	////////////////////////////////////////////////////////////////////////////////
	//// Common commands
	////////////////////////////////////////////////////////////////////////////////
	/*!
	\struct DLN_REGISTER_NOTIFICATION_CMD
	The command registers notification settings
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		DLN_NOTIFICATION notification;			///< Defines the notification settings.
	} __PACKED_ATTR DLN_REGISTER_NOTIFICATION_CMD;

	/*!
	\struct DLN_REGISTER_NOTIFICATION_RSP
	The response notifies whether the settings were successfully registered.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		DLN_RESULT result;						///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_REGISTER_NOTIFICATION_RSP;

	/*!
	\struct DLN_UNREGISTER_NOTIFICATION_CMD
	The command unregisters notification settings.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
	} __PACKED_ATTR DLN_UNREGISTER_NOTIFICATION_CMD;

	/*!
	\struct DLN_UNREGISTER_NOTIFICATION_RSP
	The response notifies whether the settings were successfully unregistered.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		DLN_RESULT result;						///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_UNREGISTER_NOTIFICATION_RSP;

#define DLN_MAX_HOST_LENGTH 50
#define DLN_DEFAULT_SERVER_PORT (uint16_t)9656
	/*!
	\struct DLN_CONNECT_CMD
	The command establishes the connection to the DLN server.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		///  For the header.handle the HDLN_ALL_DEVICES value must be used.
		char host[DLN_MAX_HOST_LENGTH+1];		///< A server to establish the connection to.
		uint16_t port;							///< A port number of the DLN server.
	} __PACKED_ATTR DLN_CONNECT_CMD;
	/*!
	\struct DLN_CONNECT_RSP
	The response notifies if the connection was successfully established.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		DLN_RESULT result;						///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_CONNECT_RSP;


	/*!
	\struct DLN_DISCONNECT_CMD
	The closes the connection to the specified DLN server.

	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		///  For the header.handle the HDLN_ALL_DEVICES value must be used.
		char host[DLN_MAX_HOST_LENGTH+1];		///< A server to close the connection to.
		uint16_t port;							///< A port number of the DLN server.
	} __PACKED_ATTR DLN_DISCONNECT_CMD;

	/*!
	\struct DLN_DISCONNECT_RSP
	The response notifies if the connection was successfully closed.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		DLN_RESULT result;						///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_DISCONNECT_RSP;

	/*!
	\struct DLN_DISCONNECT_ALL_CMD
	The command closes connections to all servers at once.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		///  For the header.handle the HDLN_ALL_DEVICES value must be used.
	} __PACKED_ATTR DLN_DISCONNECT_ALL_CMD;


	/*!
	\struct DLN_DISCONNECT_ALL_RSP
	The response notifies if all the connections were successfully closed.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;					///< Defines the DLN message header.
		///  For the header.handle the HDLN_ALL_DEVICES value must be used.
		DLN_RESULT result;						///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_DISCONNECT_ALL_RSP;


	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_GET_SRV_UUID_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		uint8_t uuid[16];
	} __PACKED_ATTR DLN_GET_SRV_UUID_RSP;


	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_CLEANUP_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
	} __PACKED_ATTR DLN_CLEANUP_RSP;

	/*!
	\struct DLN_CONNECTION_LOST_EV
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;
		char host[DLN_MAX_HOST_LENGTH+1];
		uint16_t port;
	} __PACKED_ATTR DLN_CONNECTION_LOST_EV;


#define DLN_DEVICE_FILTER_NUMBER (1<<0)
#define DLN_DEVICE_FILTER_HW_TYPE	(1<<1)
#define DLN_DEVICE_FILTER_SN	(1<<2)
#define DLN_DEVICE_FILTER_ID	(1<<3)

	/*!
	\struct DLN_GET_DEVICE_COUNT_CMD
	The command retrieves the total number of DLN-devices available.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header; 				///< Defines the DLN message header.
		///  For the header.handle the HDLN_ALL_DEVICES value must be used.
		uint16_t filter;
		uint32_t hardwareType;				///< A type of the device.
		uint32_t sn;						///< A serial number of the device.
		uint32_t id;						///< An ID number of the device.
	} __PACKED_ATTR DLN_GET_DEVICE_COUNT_CMD;

	/*!
	\struct DLN_GET_DEVICE_COUNT_RSP
	The response notifies if the device was successfully opened.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
		DLN_RESULT result;					///< Contains the result of the command execution.
		uint32_t deviceCount;				///< The number of connected devices.
	} __PACKED_ATTR DLN_GET_DEVICE_COUNT_RSP;

	/*!
	\struct DLN_OPEN_DEVICE_CMD
	The command opens the specified device.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
		///  For the header.handle the HDLN_ALL_DEVICES value must be used.
		uint16_t filter;				///< Defines which parameters are used to choose the device.
		uint32_t number;				///< A number of the device to open (bit 0 of the filter must be set to use the number field).
		DLN_HW_TYPE hardwareType;			///< A type of the device.
		uint32_t sn;					///< A type of the device.
		uint32_t id;					///< An ID number of the device.
	} __PACKED_ATTR DLN_OPEN_DEVICE_CMD;

	/*!
	\struct DLN_OPEN_DEVICE_RSP
	The response notifies if the device was successfully opened.
	*/

	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
		DLN_RESULT result;					///< Contains the result of the command execution.
		HDLN deviceHandle;					///< A handle to the DLN device.
	} __PACKED_ATTR DLN_OPEN_DEVICE_RSP;

	/*!
	\struct DLN_OPEN_STREAM_CMD
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_OPEN_STREAM_CMD;

	/*!
	\struct DLN_OPEN_STREAM_RSP
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		HDLN streamHandle;
	} __PACKED_ATTR DLN_OPEN_STREAM_RSP;

	/*!
	\struct DLN_CLOSE_HANDLE_CMD
	The command closes the handle to the opened DLN device (stream).
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
	} __PACKED_ATTR DLN_CLOSE_HANDLE_CMD;

	/*!
	\struct DLN_CLOSE_HANDLE_RSP
	The response notifies if the connection was successfully closed.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
		DLN_RESULT result;					///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_CLOSE_HANDLE_RSP;

	/*!
	\struct DLN_CLOSE_ALL_HANDLES_CMD
	The command closes all handles to opened DLN devices (stream).
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
		///  For the header.handle the HDLN_ALL_DEVICES value must be used.
	} __PACKED_ATTR DLN_CLOSE_ALL_HANDLES_CMD;

	/*!
	\struct DLN_CLOSE_ALL_HANDLES_RSP
	The response notifies if all connections were successfully closed.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
		DLN_RESULT result;					///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_CLOSE_ALL_HANDLES_RSP;

	/*!
	\struct DLN_DEVICE_REMOVED_EV
	The event notifies about a device having being disconnected from a server.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
	} __PACKED_ATTR DLN_DEVICE_REMOVED_EV;

	/*!
	\struct DLN_DEVICE_ADDED_EV
	The event notifies about a device being connected to a server.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;				///< Defines the DLN message header.
		DLN_HW_TYPE hardwareType;				///< The type of the device.
		uint32_t id;						///< The device ID number.
		uint32_t sn;						///< The device serial number.
	} __PACKED_ATTR DLN_DEVICE_ADDED_EV;



	/*!
	\struct DLN_VERSION
	The structure is used to store the DLN device and software version data.
	*/
	typedef struct
	{
		DLN_HW_TYPE hardwareType;			///< A type of the device.
		uint32_t hardwareVersion;		///< A version of the hardware, used in he device.
		uint32_t firmwareVersion;		///< A version of the firmware, installed in the device.
		uint32_t serverVersion;			///< A version of the DLN server.
		uint32_t libraryVersion;		///< A version of the DLN-library.
	} __PACKED_ATTR DLN_VERSION;

	/*!
	\struct DLN_GET_VER_CMD
	The command retrieves the DLN device and software version data.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
	} __PACKED_ATTR DLN_GET_VER_CMD;
	/*!
	\struct DLN_GET_VER_RSP
	The response contains the retrieved information.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
		DLN_RESULT result;				///< Contains the result of the command execution.
		DLN_VERSION version;			///< The DLN_VERSION structure, containing the version information.
	} __PACKED_ATTR DLN_GET_VER_RSP;

	/*!
	\struct DLN_GET_DEVICE_SN_CMD
	The command retrieves a device serial number.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
	} __PACKED_ATTR DLN_GET_DEVICE_SN_CMD;

	/*!
	\struct DLN_GET_DEVICE_SN_RSP
	The response contains a device serial number.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;		 	///< Defines the DLN message header.
		DLN_RESULT result;				///< Contains the result of the command execution.
		uint32_t sn;					///< A device serial number.
	} __PACKED_ATTR DLN_GET_DEVICE_SN_RSP;

	/*!
	\struct DLN_SET_DEVICE_ID_CMD
	The command sets a new ID to the DLN device.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
		uint32_t id;					///< A new device ID to be set.
	} __PACKED_ATTR DLN_SET_DEVICE_ID_CMD;

	/*!
	\struct DLN_SET_DEVICE_ID_RSP
	The response notifies if the ID was successfully set.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
		DLN_RESULT result;				///< Contains the result of the command execution.
	} __PACKED_ATTR DLN_SET_DEVICE_ID_RSP;

	/*!
	\struct DLN_GET_DEVICE_ID_CMD
	The command retrieves the device ID number.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
	} __PACKED_ATTR DLN_GET_DEVICE_ID_CMD;

	/*!
	\struct DLN_GET_DEVICE_ID_RSP
	The response contains the retrieved device ID number.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
		DLN_RESULT result;				///< Contains the result of the command execution.
		uint32_t id;					///< A device ID number.
	} __PACKED_ATTR DLN_GET_DEVICE_ID_RSP;

	/*!
	\struct DLN_GET_HARDWARE_TYPE_CMD
	The command retrieves the device hardware type (e.g DLN_HW_TYPE_DLN4M, DLN_HW_TYPE_DLN2)
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_GET_HARDWARE_TYPE_CMD;

	/*!
	\struct DLN_GET_HARDWARE_TYPE_RSP
	The response contains the retrieved device hardware type.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		DLN_HW_TYPE type;
	} __PACKED_ATTR DLN_GET_HARDWARE_TYPE_RSP;


	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_GET_HARDWARE_VERSION_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		uint32_t version;
	} __PACKED_ATTR DLN_GET_HARDWARE_VERSION_RSP;

	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_GET_FIRMWARE_VERSION_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		uint32_t version;
	} __PACKED_ATTR DLN_GET_FIRMWARE_VERSION_RSP;

	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_GET_SERVER_VERSION_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		uint32_t version;
	} __PACKED_ATTR DLN_GET_SERVER_VERSION_RSP;

	typedef struct
	{
		DLN_MSG_HEADER header;
	} __PACKED_ATTR DLN_GET_LIBRARY_VERSION_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		uint32_t version;
	} __PACKED_ATTR DLN_GET_LIBRARY_VERSION_RSP;


	/*!
	\struct DLN_PIN_CFG
	The structure is used to store the configuration of a single DLN device pin.
	*/
	typedef struct
	{
		DLN_MODULE module;				///< A module, to which the pin is connected.
		DLN_PIN_ROLE role;				///< A role performed by the pin.
	} __PACKED_ATTR DLN_PIN_CFG;

#define DLN_DMA_ROLE uint8_t
#define DLN_DMA_ROLE_NOT_IN_USE DLN_DMA_ROLE(0)
#define DLN_DMA_ROLE_TX  DLN_DMA_ROLE(1)
#define DLN_DMA_ROLE_RX DLN_DMA_ROLE(2)
	/*!
	\struct DLN_GET_PIN_CFG_CMD
	*/
	typedef struct
	{
		DLN_MODULE module;
		DLN_DMA_ROLE role;
	} __PACKED_ATTR DLN_DMA_CFG;

	/*!
	\struct DLN_GET_PIN_CFG_CMD
	The command retrieves current configuration of the DLN device pin.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
		uint16_t pin;					///< A pin to get the configuration from.
	} __PACKED_ATTR DLN_GET_PIN_CFG_CMD;

	/*!
	\struct DLN_GET_PIN_CFG_RSP
	The  response contains current configuration of the specified DLN device pin.
	*/
	typedef struct
	{
		DLN_MSG_HEADER header;			///< Defines the DLN message header.
		DLN_RESULT result;				///< Contains the result of the command execution.
		DLN_PIN_CFG cfg;				///< The current configuration of the pin.
	} __PACKED_ATTR DLN_GET_PIN_CFG_RSP;


	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_MSG_ID msgId;
		uint16_t entity;
	} __PACKED_ATTR DLN_GET_COMMAND_RESTRICTION_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
		DLN_RESTRICTION restriction;
	} __PACKED_ATTR DLN_GET_COMMAND_RESTRICTION_RSP;


	typedef struct
	{
		DLN_MSG_HEADER header;
		uint32_t delay;
	} __PACKED_ATTR DLN_DELAY_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
	} __PACKED_ATTR DLN_DELAY_RSP;


    typedef struct
    {
        DLN_MSG_HEADER header;
    } __PACKED_ATTR DLN_RESTART_CMD;

	typedef struct
	{
		DLN_MSG_HEADER header;
		DLN_RESULT result;
	} __PACKED_ATTR DLN_RESTART_RSP;


    typedef struct
    {
        uint8_t uuid[16];
        uint16_t deviceHandle;
        uint8_t macAddress[6];
        uint8_t ipAddress[4];
        uint8_t subnetMask[4];
        uint8_t gatewayIp[4];
        uint16_t port;
    } __PACKED_ATTR DLN_SRV_PARAMS;

    typedef struct
    {
        DLN_MSG_HEADER header;
        DLN_SRV_PARAMS params;
    } __PACKED_ATTR DLN_SET_SRV_PARAMS_CMD;

    typedef struct
    {
        DLN_MSG_HEADER header;
        DLN_RESULT result;
    } __PACKED_ATTR DLN_SET_SRV_PARAMS_RSP;

    typedef struct
    {
        DLN_MSG_HEADER header;
    } __PACKED_ATTR DLN_GET_SRV_PARAMS_CMD;

    typedef struct
    {
        DLN_MSG_HEADER header;
        DLN_RESULT result;
        DLN_SRV_PARAMS params;
    } __PACKED_ATTR DLN_GET_SRV_PARAMS_RSP;



	/*!
	Registers notification settings
	\param handle - A handle to the DLN device.
	\param notification - Defines the notification settings.
	*/
	DLN_RESULT DlnRegisterNotification(HDLN handle, DLN_NOTIFICATION notification);
	/*!
	Unregisters notification settings.
	\param handle - A handle to the DLN device.
	*/
	DLN_RESULT DlnUnregisterNotification(HDLN handle);


	/*!
	Establishes the connection to the DLN server.
	\param host - A server to establish the connection to.
	\param port - A port number of the DLN server.
	\retval DLN_RES_INSUFFICIENT_RESOURCES
	\retval DLN_RES_SOCKET_INITIALIZATION_FAILED
	*/
	DLN_RESULT DlnConnect(const char* host, uint16_t port);
	/*!
	Closes the connection to the specified DLN server.
	\param host - A server to close the connection to.
	\param port - A port of the DLN server.
	*/
	DLN_RESULT DlnDisconnect(const char* host, uint16_t port);
	/*!
	Closes connections to all servers at once.
	\retval DLN_RES_SUCCESS - connections to all servers were successfully closed;
	\retval DLN_RES_NOT_CONNECTED - no connections were present during the command execution.
	*/
	DLN_RESULT DlnDisconnectAll();
	//DLN_RESULT DLN_Init();            //dll library init
	//DLN_RESULT DLN_Uninit();                                       //dll library Uninit

	/*!
	Closes all connections and frees the resources used.
	\retval DLN_RES_SUCCESS
	*/
	DLN_RESULT DlnCleanup();

	/*!
	Retrieves the total number of DLN-devices available.
	\param deviceCount - A pointer to an unsigned 32-bit integer. This integer will be filled with the total number of available DLN devices.
	*/
	DLN_RESULT DlnGetDeviceCount(uint32_t *deviceCount);
	/*!
	Opens the specified device corresponding to the specified deviceNumber.
	If successful, returns the handle of the opened device as deviceHandle.
	\param deviceNumber - A number of the device to be opened.
	\param deviceHandle - A pointer to the variable that receives the device handle after the function execution.
	\retval DLN_RES_SUCCESS - The device was successfully opened. The deviceHandle parameter contains a valid handle.
	\retval DLN_RES_NOT_CONNECTED - The library was not connected to any server.
	\retval DLN_RES_MEMORY_ERROR - Not enough memory to process this command.
	\retval DLN_RES_HARDWARE_NOT_FOUND - The number of available devices is less than deviceNumber+1
	\retval DLN_RES_DEVICE_REMOVED - The device was disconnected while opening.
	*/
	DLN_RESULT DlnOpenDevice(uint32_t deviceNumber, HDLN *deviceHandle);
	/*!
	Opens a specified defined by its serial number.
	\param sn - A serial number of the DLN device.
	\param deviceHandle - A pointer to the variable that receives the device handle after the function execution.
	*/
	DLN_RESULT DlnOpenDeviceBySn(uint32_t sn, HDLN *deviceHandle);
	/*!
	Opens a specified defined by its ID number.
	\param id - An ID number of the DLN device.
	\param deviceHandle - A pointer to the variable that receives the device handle after the function execution.
	*/
	DLN_RESULT DlnOpenDeviceById(uint32_t id, HDLN *deviceHandle);


	DLN_RESULT DlnOpenDeviceByHwType(DLN_HW_TYPE hwType, HDLN *deviceHandle);

	DLN_RESULT DlnOpenStream(HDLN deviceHandle, HDLN *streamHandle);
	/*!
	Closes the handle to an opened DLN device (stream).
	\param handle - A handle to the DLN device.
	*/
	DLN_RESULT DlnCloseHandle(HDLN handle);
	/*!
	Closes handles to all opened DLN devices and streams.
	*/
	DLN_RESULT DlnCloseAllHandles();

	/*!
	Retrieves the DLN device and software version data.
	\param handle - A handle to the DLN device.
	\param version - A pointer to a DLN_VERSION structure that receives version information after the function execution.
	*/
	DLN_RESULT DlnGetVersion(HDLN handle, DLN_VERSION *version);
	/*!
	Retrieves the device serial number.
	\param handle - A handle to the DLN device.
	\param sn - A pointer to the variable that receives the device serial number after the function execution.
	*/
	DLN_RESULT DlnGetDeviceSn(HDLN handle, uint32_t *sn);
	/*!
	Sets a new ID number to the DLN device.
	\param handle - A handle to the DLN device.
	\param id - An ID number to be set.
	*/
	DLN_RESULT DlnSetDeviceId(HDLN handle, uint32_t id);
	/*!
	Retrieves the device ID number.
	\param handle - A handle to the DLN device.
	\param id - A pointer to an unsigned 32-bit integer. This integer will be filled with the ID number after the function execution.
	*/
	DLN_RESULT DlnGetDeviceId(HDLN handle, uint32_t *id);

	DLN_RESULT DlnGetHardwareType (HDLN handle, DLN_HW_TYPE *type);
	DLN_RESULT DlnGetHardwareVersion (HDLN handle, uint32_t *version);
	DLN_RESULT DlnGetFirmwareVersion (HDLN handle, uint32_t *version);
	DLN_RESULT DlnGetServerVersion (HDLN handle, uint32_t *version);
	DLN_RESULT DlnGetLibraryVersion (HDLN handle, uint32_t *version);


	/*!
	Retrieves current configuration of the specified DLN device pin.
	\param handle - A handle to the DLN device.
	\param pin - A pin to get the configuration from.
	\param cfg - A pointer to the DLN_PIN_CONFIG structure which will be filled with the configuration after function execution.

	\retval DLN_RES_SUCCESS - The pin configuration is successfully retrieved.
	\retval DLN_RES_INVALID_PIN_NUMBER - An invalid pin number has been specified.
	*/
	DLN_RESULT DlnGetPinCfg(HDLN handle, uint16_t pin, DLN_PIN_CFG *cfg);

	DLN_RESULT DlnGetCommandRestriction(HDLN handle, DLN_MSG_ID msgId, uint16_t entity, DLN_RESTRICTION *restriction);
	DLN_RESULT DlnDelay(HDLN handle, uint32_t delay);
    DLN_RESULT DlnRestart(HDLN handle);

    DLN_RESULT DlnSetSrvParams(HDLN handle, DLN_SRV_PARAMS *params);
    DLN_RESULT DlnGetSrvParams(HDLN handle, DLN_SRV_PARAMS *params);

	//#endif


#ifdef __ICCARM__
#pragma pack()
#elif defined(WIN32) || defined(__BORLANDC__)  || defined(WIN64)
#pragma pack(pop)
#endif

#ifdef __cplusplus
}
#endif




#endif // DLN_GENERIC_H

