#include <intrin.h>

#define UNDEFINED_ROLE 0
#define COMPUTOR 1
#define CANDIDATE 2
#define MINER 3

////////// Settings \\\\\\\\\\

volatile static unsigned char role = UNDEFINED_ROLE;
static const unsigned char tcp4Address[4] = { 0, 0, 0, 0 };
static const unsigned char tcp4Mask[4] = { 255, 255, 255, 255 };
static const unsigned char defaultRouteAddress[4] = { 0, 0, 0, 0 };
static const unsigned char defaultRouteMask[4] = { 0, 0, 0, 0 };
static const unsigned char defaultRouteGateway[4] = { 0, 0, 0, 0 };

////////// UEFI \\\\\\\\\\

#define CONST const
#define EFIAPI __cdecl
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF
#define FALSE ((BOOLEAN)0)
#define IN
#define NULL 0
#define OPTIONAL
#define OUT
#define TRUE ((BOOLEAN)1)

#define EFI_SUCCESS 0
#define EFI_LOAD_ERROR 1
#define EFI_INVALID_PARAMETER 2
#define EFI_UNSUPPORTED 3
#define EFI_BAD_BUFFER_SIZE 4
#define EFI_BUFFER_TOO_SMALL 5
#define EFI_NOT_READY 6
#define EFI_DEVICE_ERROR 7
#define EFI_WRITE_PROTECTED 8
#define EFI_OUT_OF_RESOURCES 9
#define EFI_VOLUME_CORRUPTED 10
#define EFI_VOLUME_FULL 11
#define EFI_NO_MEDIA 12
#define EFI_MEDIA_CHANGED 13
#define EFI_NOT_FOUND 14
#define EFI_ACCESS_DENIED 15
#define EFI_NO_RESPONSE 16
#define EFI_NO_MAPPING 17
#define EFI_TIMEOUT 18
#define EFI_NOT_STARTED 19
#define EFI_ALREADY_STARTED 20
#define EFI_ABORTED 21
#define EFI_ICMP_ERROR 22
#define EFI_TFTP_ERROR 23
#define EFI_PROTOCOL_ERROR 24
#define EFI_INCOMPATIBLE_VERSION 25
#define EFI_SECURITY_VIOLATION 26
#define EFI_CRC_ERROR 27
#define EFI_END_OF_MEDIA 28
#define EFI_END_OF_FILE 31
#define EFI_INVALID_LANGUAGE 32
#define EFI_COMPROMISED_DATA 33
#define EFI_IP_ADDRESS_CONFLICT 34
#define EFI_HTTP_ERROR 35

#define EFI_MP_SERVICES_PROTOCOL_GUID {0x3fdda605, 0xa76e, 0x4f46, {0xad, 0x29, 0x12, 0xf4, 0x53, 0x1b, 0x3d, 0x08}}
#define EFI_TCP4_PROTOCOL_GUID {0x65530BC7, 0xA359, 0x410f, {0xB0, 0x10, 0x5A, 0xAD, 0xC7, 0xEC, 0x2B, 0x62}}
#define EFI_TCP4_SERVICE_BINDING_PROTOCOL_GUID {0x00720665, 0x67EB, 0x4a99, {0xBA, 0xF7, 0xD3, 0xC3, 0x3A, 0x1C, 0x7C, 0xC9}}

#define END_OF_CPU_LIST 0xFFFFFFFF
#define EVT_NOTIFY_SIGNAL 0x00000200
#define EVT_NOTIFY_WAIT 0x00000100
#define EVT_RUNTIME 0x40000000
#define EVT_SIGNAL_EXIT_BOOT_SERVICES 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202
#define EVT_TIMER 0x80000000
#define MAX_MCAST_FILTER_CNT 16
#define PROCESSOR_AS_BSP_BIT 0x00000001
#define PROCESSOR_ENABLED_BIT 0x00000002
#define PROCESSOR_HEALTH_STATUS_BIT 0x00000004
#define TPL_APPLICATION 4
#define TPL_CALLBACK 8
#define TPL_HIGH_LEVEL 31
#define TPL_NOTIFY 16

typedef unsigned char BOOLEAN;
typedef unsigned short CHAR16;
typedef signed short INT16;
typedef signed int INT32;
typedef signed long long INT64;
typedef signed char INT8;
typedef INT64 INTN;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef unsigned char UINT8;
typedef UINT64 UINTN;
typedef void VOID;

typedef VOID* EFI_EVENT;
typedef VOID* EFI_HANDLE;
typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINTN EFI_STATUS;
typedef UINTN EFI_TPL;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef enum
{
	AllocateAnyPages,
	AllocateMaxAddress,
	AllocateAddress,
	MaxAllocateType
} EFI_ALLOCATE_TYPE;

typedef enum
{
	EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

typedef enum
{
	AllHandles,
	ByRegisterNotify,
	ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef enum
{
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiPersistentMemory,
	EfiUnacceptedMemoryType,
	EfiMaxMemoryType
} EFI_MEMORY_TYPE;

typedef enum
{
	EfiResetCold,
	EfiResetWarm,
	EfiResetShutdown,
	EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef enum
{
	Tcp4StateClosed = 0,
	Tcp4StateListen = 1,
	Tcp4StateSynSent = 2,
	Tcp4StateSynReceived = 3,
	Tcp4StateEstablished = 4,
	Tcp4StateFinWait1 = 5,
	Tcp4StateFinWait2 = 6,
	Tcp4StateClosing = 7,
	Tcp4StateTimeWait = 8,
	Tcp4StateCloseWait = 9,
	Tcp4StateLastAck = 10
} EFI_TCP4_CONNECTION_STATE;

typedef enum
{
	TimerCancel,
	TimerPeriodic,
	TimerRelative
} EFI_TIMER_DELAY;

typedef struct
{
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8 Data4[8];
} EFI_GUID;

typedef struct
{
	EFI_GUID CapsuleGuid;
	UINT32 HeaderSize;
	UINT32 Flags;
	UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

typedef struct
{
	UINT32 Package;
	UINT32 Core;
	UINT32 Thread;
} EFI_CPU_PHYSICAL_LOCATION;

typedef struct
{
	UINT8 Type;
	UINT8 SubType;
	UINT8 Length[2];
} EFI_DEVICE_PATH_PROTOCOL;

typedef struct
{
	UINT16 ScanCode;
	CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

typedef struct
{
	UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

typedef struct
{
	UINT8 DefaultProtocol;
	BOOLEAN AcceptAnyProtocol;
	BOOLEAN AcceptIcmpErrors;
	BOOLEAN AcceptBroadcast;
	BOOLEAN AcceptPromiscuous;
	BOOLEAN UseDefaultAddress;
	EFI_IPv4_ADDRESS StationAddress;
	EFI_IPv4_ADDRESS SubnetMask;
	UINT8 TypeOfService;
	UINT8 TimeToLive;
	BOOLEAN DoNotFragment;
	BOOLEAN RawData;
	UINT32 ReceiveTimeout;
	UINT32 TransmitTimeout;
} EFI_IP4_CONFIG_DATA;

typedef struct
{
	UINT8 Type;
	UINT8 Code;
} EFI_IP4_ICMP_TYPE;

typedef struct
{
	EFI_IPv4_ADDRESS SubnetAddress;
	EFI_IPv4_ADDRESS SubnetMask;
	EFI_IPv4_ADDRESS GatewayAddress;
} EFI_IP4_ROUTE_TABLE;

typedef struct
{
	BOOLEAN IsStarted;
	UINT32 MaxPacketSize;
	EFI_IP4_CONFIG_DATA ConfigData;
	BOOLEAN IsConfigured;
	UINT32 GroupCount;
	EFI_IPv4_ADDRESS* GroupTable;
	UINT32 RouteCount;
	EFI_IP4_ROUTE_TABLE* RouteTable;
	UINT32 IcmpTypeCount;
	EFI_IP4_ICMP_TYPE* IcmpTypeList;
} EFI_IP4_MODE_DATA;

typedef struct
{
	UINT8 Addr[32];
} EFI_MAC_ADDRESS;

typedef struct
{
	UINT32 ReceivedQueueTimeoutValue;
	UINT32 TransmitQueueTimeoutValue;
	UINT16 ProtocolTypeFilter;
	BOOLEAN EnableUnicastReceive;
	BOOLEAN EnableMulticastReceive;
	BOOLEAN EnableBroadcastReceive;
	BOOLEAN EnablePromiscuousReceive;
	BOOLEAN FlushQueuesOnReset;
	BOOLEAN EnableReceiveTimestamps;
	BOOLEAN DisableBackgroundPolling;
} EFI_MANAGED_NETWORK_CONFIG_DATA;

typedef struct
{
	UINT32 Type;
	EFI_PHYSICAL_ADDRESS PhysicalStart;
	EFI_VIRTUAL_ADDRESS VirtualStart;
	UINT64 NumberOfPages;
	UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef struct
{
	EFI_HANDLE AgentHandle;
	EFI_HANDLE ControllerHandle;
	UINT32 Attributes;
	UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef struct
{
	UINT64 ProcessorId;
	UINT32 StatusFlag;
	EFI_CPU_PHYSICAL_LOCATION Location;
} EFI_PROCESSOR_INFORMATION;

typedef struct
{
	UINT32 State;
	UINT32 HwAddressSize;
	UINT32 MediaHeaderSize;
	UINT32 MaxPacketSize;
	UINT32 NvRamSize;
	UINT32 NvRamAccessSize;
	UINT32 ReceiveFilterMask;
	UINT32 ReceiveFilterSetting;
	UINT32 MaxMCastFilterCount;
	UINT32 MCastFilterCount;
	EFI_MAC_ADDRESS MCastFilter[MAX_MCAST_FILTER_CNT];
	EFI_MAC_ADDRESS CurrentAddress;
	EFI_MAC_ADDRESS BroadcastAddress;
	EFI_MAC_ADDRESS PermanentAddress;
	UINT8 IfType;
	BOOLEAN MacAddressChangeable;
	BOOLEAN MultipleTxSupported;
	BOOLEAN MediaPresentSupported;
	BOOLEAN MediaPresent;
} EFI_SIMPLE_NETWORK_MODE;

typedef struct
{
	UINT64 Signature;
	UINT32 Revision;
	UINT32 HeaderSize;
	UINT32 CRC32;
	UINT32 Reserved;
} EFI_TABLE_HEADER;

typedef struct
{
	BOOLEAN UseDefaultAddress;
	EFI_IPv4_ADDRESS StationAddress;
	EFI_IPv4_ADDRESS SubnetMask;
	UINT16 StationPort;
	EFI_IPv4_ADDRESS RemoteAddress;
	UINT16 RemotePort;
	BOOLEAN ActiveFlag;
} EFI_TCP4_ACCESS_POINT;

typedef struct
{
	EFI_EVENT Event;
	EFI_STATUS Status;
} EFI_TCP4_COMPLETION_TOKEN;

typedef struct
{
	EFI_TCP4_COMPLETION_TOKEN CompletionToken;
	BOOLEAN AbortOnClose;
} EFI_TCP4_CLOSE_TOKEN;

typedef struct
{
	UINT32 ReceiveBufferSize;
	UINT32 SendBufferSize;
	UINT32 MaxSynBackLog;
	UINT32 ConnectionTimeout;
	UINT32 DataRetries;
	UINT32 FinTimeout;
	UINT32 TimeWaitTimeout;
	UINT32 KeepAliveProbes;
	UINT32 KeepAliveTime;
	UINT32 KeepAliveInterval;
	BOOLEAN EnableNagle;
	BOOLEAN EnableTimeStamp;
	BOOLEAN EnableWindowScaling;
	BOOLEAN EnableSelectiveAck;
	BOOLEAN EnablePathMtuDiscovery;
} EFI_TCP4_OPTION;

typedef struct
{
	UINT8 TypeOfService;
	UINT8 TimeToLive;
	EFI_TCP4_ACCESS_POINT AccessPoint;
	EFI_TCP4_OPTION* ControlOption;
} EFI_TCP4_CONFIG_DATA;

typedef struct
{
	EFI_TCP4_COMPLETION_TOKEN CompletionToken;
} EFI_TCP4_CONNECTION_TOKEN;

typedef struct
{
	UINT32 FragmentLength;
	VOID* FragmentBuffer;
} EFI_TCP4_FRAGMENT_DATA;

typedef struct
{
	BOOLEAN UrgentFlag;
	UINT32 DataLength;
	UINT32 FragmentCount;
	EFI_TCP4_FRAGMENT_DATA FragmentTable[1];
} EFI_TCP4_RECEIVE_DATA;

typedef struct
{
	BOOLEAN Push;
	BOOLEAN Urgent;
	UINT32 DataLength;
	UINT32 FragmentCount;
	EFI_TCP4_FRAGMENT_DATA FragmentTable[1];
} EFI_TCP4_TRANSMIT_DATA;

typedef struct
{
	EFI_TCP4_COMPLETION_TOKEN CompletionToken;
	union {
		EFI_TCP4_RECEIVE_DATA* RxData;
		EFI_TCP4_TRANSMIT_DATA* TxData;
	} Packet;
} EFI_TCP4_IO_TOKEN;

typedef struct
{
	EFI_TCP4_COMPLETION_TOKEN CompletionToken;
	EFI_HANDLE NewChildHandle;
} EFI_TCP4_LISTEN_TOKEN;

typedef struct
{
	UINT16 Year;
	UINT8 Month;
	UINT8 Day;
	UINT8 Hour;
	UINT8 Minute;
	UINT8 Second;
	UINT8 Pad1;
	UINT32 Nanosecond;
	INT16 TimeZone;
	UINT8 Daylight;
	UINT8 Pad2;
} EFI_TIME;

typedef struct
{
	UINT32 Resolution;
	UINT32 Accuracy;
	BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef struct
{
	INT32 MaxMode;
	INT32 Mode;
	INT32 Attribute;
	INT32 CursorColumn;
	INT32 CursorRow;
	BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

typedef EFI_STATUS(EFIAPI* EFI_ALLOCATE_PAGES) (IN EFI_ALLOCATE_TYPE Type, IN EFI_MEMORY_TYPE MemoryType, IN UINTN Pages, IN OUT EFI_PHYSICAL_ADDRESS* Memory);
typedef EFI_STATUS(EFIAPI* EFI_ALLOCATE_POOL) (IN EFI_MEMORY_TYPE PoolType, IN UINTN Size, OUT VOID** Buffer);
typedef VOID(EFIAPI* EFI_AP_PROCEDURE) (IN VOID* ProcedureArgument);
typedef EFI_STATUS(EFIAPI* EFI_CALCULATE_CRC32) (IN VOID* Data, IN UINTN DataSize, OUT UINT32* Crc32);
typedef EFI_STATUS(EFIAPI* EFI_CHECK_EVENT) (IN EFI_EVENT Event);
typedef EFI_STATUS(EFIAPI* EFI_CLOSE_EVENT) (IN EFI_EVENT Event);
typedef EFI_STATUS(EFIAPI* EFI_CLOSE_PROTOCOL) (IN EFI_HANDLE Handle, IN EFI_GUID* Protocol, IN EFI_HANDLE AgentHandle, IN EFI_HANDLE ControllerHandle);
typedef EFI_STATUS(EFIAPI* EFI_CONNECT_CONTROLLER) (IN EFI_HANDLE ControllerHandle, IN EFI_HANDLE* DriverImageHandle OPTIONAL, IN EFI_DEVICE_PATH_PROTOCOL* RemainingDevicePath OPTIONAL, IN BOOLEAN Recursive);
typedef EFI_STATUS(EFIAPI* EFI_CONVERT_POINTER) (IN UINTN DebugDisposition, IN OUT VOID** Address);
typedef VOID(EFIAPI* EFI_COPY_MEM) (IN VOID* Destination, IN VOID* Source, IN UINTN Length);
typedef EFI_STATUS(EFIAPI* EFI_CREATE_EVENT) (IN UINT32 Type, IN EFI_TPL NotifyTpl, IN VOID* NotifyFunction, OPTIONAL IN VOID* NotifyContext, OPTIONAL OUT EFI_EVENT* Event);
typedef EFI_STATUS(EFIAPI* EFI_CREATE_EVENT_EX) (IN UINT32 Type, IN EFI_TPL NotifyTpl, IN VOID* NotifyFunction OPTIONAL, IN CONST VOID* NotifyContext OPTIONAL, IN CONST EFI_GUID* EventGroup OPTIONAL, OUT EFI_EVENT* Event);
typedef EFI_STATUS(EFIAPI* EFI_DISCONNECT_CONTROLLER) (IN EFI_HANDLE ControllerHandle, IN EFI_HANDLE DriverImageHandle OPTIONAL, IN EFI_HANDLE ChildHandle OPTIONAL);
typedef VOID(EFIAPI* EFI_EVENT_NOTIFY) (IN EFI_EVENT Event, IN VOID* Context);
typedef EFI_STATUS(EFIAPI* EFI_EXIT) (IN EFI_HANDLE ImageHandle, IN EFI_STATUS ExitStatus, IN UINTN ExitDataSize, IN CHAR16* ExitData OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_EXIT_BOOT_SERVICES) (IN EFI_HANDLE ImageHandle, IN UINTN MapKey);
typedef EFI_STATUS(EFIAPI* EFI_FREE_PAGES) (IN EFI_PHYSICAL_ADDRESS Memory, IN UINTN Pages);
typedef EFI_STATUS(EFIAPI* EFI_FREE_POOL) (IN VOID* Buffer);
typedef EFI_STATUS(EFIAPI* EFI_GET_MEMORY_MAP) (IN OUT UINTN* MemoryMapSize, OUT EFI_MEMORY_DESCRIPTOR* MemoryMap, OUT UINTN* MapKey, OUT UINTN* DescriptorSize, OUT UINT32* DescriptorVersion);
typedef EFI_STATUS(EFIAPI* EFI_GET_NEXT_HIGH_MONO_COUNT) (OUT UINT32* HighCount);
typedef EFI_STATUS(EFIAPI* EFI_GET_NEXT_MONOTONIC_COUNT) (OUT UINT64* Count);
typedef EFI_STATUS(EFIAPI* EFI_GET_NEXT_VARIABLE_NAME) (IN OUT UINTN* VariableNameSize, IN OUT CHAR16* VariableName, IN OUT EFI_GUID* VendorGuid);
typedef EFI_STATUS(EFIAPI* EFI_GET_TIME) (OUT EFI_TIME* Time, OUT EFI_TIME_CAPABILITIES* Capabilities OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_GET_VARIABLE) (IN CHAR16* VariableName, IN EFI_GUID* VendorGuid, OUT UINT32* Attributes OPTIONAL, IN OUT UINTN* DataSize, OUT VOID* Data);
typedef EFI_STATUS(EFIAPI* EFI_GET_WAKEUP_TIME) (OUT BOOLEAN* Enabled, OUT BOOLEAN* Pending, OUT EFI_TIME* Time);
typedef EFI_STATUS(EFIAPI* EFI_HANDLE_PROTOCOL) (IN EFI_HANDLE Handle, IN EFI_GUID* Protocol, OUT VOID** Interface);
typedef EFI_STATUS(EFIAPI* EFI_IMAGE_LOAD) (IN BOOLEAN BootPolicy, IN EFI_HANDLE ParentImageHandle, IN EFI_DEVICE_PATH_PROTOCOL* DevicePath, IN VOID* SourceBuffer OPTIONAL, IN UINTN SourceSize, OUT EFI_HANDLE* ImageHandle);
typedef EFI_STATUS(EFIAPI* EFI_IMAGE_START) (IN EFI_HANDLE ImageHandle, OUT UINTN* ExitDataSize, OUT CHAR16** ExitData OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_IMAGE_UNLOAD) (IN EFI_HANDLE ImageHandle);
typedef EFI_STATUS(EFIAPI* EFI_INPUT_READ_KEY) (IN VOID* This, OUT EFI_INPUT_KEY* Key);
typedef EFI_STATUS(EFIAPI* EFI_INPUT_RESET) (IN VOID* This, IN BOOLEAN ExtendedVerification);
typedef EFI_STATUS(EFIAPI* EFI_INSTALL_CONFIGURATION_TABLE) (IN EFI_GUID* Guid, IN VOID* Table);
typedef EFI_STATUS(EFIAPI* EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (IN OUT EFI_HANDLE* Handle, ...);
typedef EFI_STATUS(EFIAPI* EFI_INSTALL_PROTOCOL_INTERFACE) (IN OUT EFI_HANDLE* Handle, IN EFI_GUID* Protocol, IN EFI_INTERFACE_TYPE InterfaceType, IN VOID* Interface);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_DEVICE_PATH) (IN EFI_GUID* Protocol, IN OUT EFI_DEVICE_PATH_PROTOCOL** DevicePath, OUT EFI_HANDLE* Device);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_HANDLE) (IN EFI_LOCATE_SEARCH_TYPE SearchType, IN EFI_GUID* Protocol OPTIONAL, IN VOID* SearchKey OPTIONAL, IN OUT UINTN* BufferSize, OUT EFI_HANDLE* Buffer);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_HANDLE_BUFFER) (IN EFI_LOCATE_SEARCH_TYPE SearchType, IN EFI_GUID* Protocol OPTIONAL, IN VOID* SearchKey OPTIONAL, OUT UINTN* NoHandles, OUT EFI_HANDLE** Buffer);
typedef EFI_STATUS(EFIAPI* EFI_LOCATE_PROTOCOL) (IN EFI_GUID* Protocol, IN VOID* Registration OPTIONAL, OUT VOID** Interface);
typedef EFI_STATUS(EFIAPI* EFI_MP_SERVICES_ENABLEDISABLEAP) (IN VOID* This, IN UINTN ProcessorNumber, IN BOOLEAN EnableAP, IN UINT32* HealthFlag OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_MP_SERVICES_GET_NUMBER_OF_PROCESSORS) (IN VOID* This, OUT UINTN* NumberOfProcessors, OUT UINTN* NumberOfEnabledProcessors);
typedef EFI_STATUS(EFIAPI* EFI_MP_SERVICES_GET_PROCESSOR_INFO) (IN VOID* This, IN UINTN ProcessorNumber, OUT EFI_PROCESSOR_INFORMATION* ProcessorInfoBuffer);
typedef EFI_STATUS(EFIAPI* EFI_MP_SERVICES_STARTUP_ALL_APS) (IN VOID* This, IN EFI_AP_PROCEDURE Procedure, IN BOOLEAN SingleThread, IN EFI_EVENT WaitEvent OPTIONAL, IN UINTN TimeoutInMicroSeconds, IN VOID* ProcedureArgument OPTIONAL, OUT UINTN** FailedCpuList OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_MP_SERVICES_STARTUP_THIS_AP) (IN VOID* This, IN EFI_AP_PROCEDURE Procedure, IN UINTN ProcessorNumber, IN EFI_EVENT WaitEvent OPTIONAL, IN UINTN TimeoutInMicroseconds, IN VOID* ProcedureArgument OPTIONAL, OUT BOOLEAN* Finished OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_MP_SERVICES_SWITCH_BSP) (IN VOID* This, IN UINTN ProcessorNumber, IN BOOLEAN EnableOldBSP);
typedef EFI_STATUS(EFIAPI* EFI_MP_SERVICES_WHOAMI) (IN VOID* This, OUT UINTN* ProcessorNumber);
typedef EFI_STATUS(EFIAPI* EFI_OPEN_PROTOCOL) (IN EFI_HANDLE Handle, IN EFI_GUID* Protocol, OUT VOID** Interface OPTIONAL, IN EFI_HANDLE AgentHandle, IN EFI_HANDLE ControllerHandle, IN UINT32 Attributes);
typedef EFI_STATUS(EFIAPI* EFI_OPEN_PROTOCOL_INFORMATION) (IN EFI_HANDLE Handle, IN EFI_GUID* Protocol, OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY** EntryBuffer, OUT UINTN* EntryCount);
typedef EFI_STATUS(EFIAPI* EFI_PROTOCOLS_PER_HANDLE) (IN EFI_HANDLE Handle, OUT EFI_GUID*** ProtocolBuffer, OUT UINTN* ProtocolBufferCount);
typedef EFI_STATUS(EFIAPI* EFI_QUERY_CAPSULE_CAPABILITIES) (IN EFI_CAPSULE_HEADER** CapsuleHeaderArray, IN UINTN CapsuleCount, OUT UINT64* MaximumCapsuleSize, OUT EFI_RESET_TYPE* ResetType);
typedef EFI_STATUS(EFIAPI* EFI_QUERY_VARIABLE_INFO) (IN UINT32 Attributes, OUT UINT64* MaximumVariableStorageSize, OUT UINT64* RemainingVariableStorageSize, OUT UINT64* MaximumVariableSize);
typedef EFI_TPL(EFIAPI* EFI_RAISE_TPL) (IN EFI_TPL NewTpl);
typedef EFI_STATUS(EFIAPI* EFI_REGISTER_PROTOCOL_NOTIFY) (IN EFI_GUID* Protocol, IN EFI_EVENT Event, OUT VOID** Registration);
typedef EFI_STATUS(EFIAPI* EFI_REINSTALL_PROTOCOL_INTERFACE) (IN EFI_HANDLE Handle, IN EFI_GUID* Protocol, IN VOID* OldInterface, IN VOID* NewInterface);
typedef EFI_STATUS(EFIAPI* EFI_RESET_SYSTEM) (IN EFI_RESET_TYPE ResetType, IN EFI_STATUS ResetStatus, IN UINTN DataSize, IN CHAR16* ResetData OPTIONAL);
typedef VOID(EFIAPI* EFI_RESTORE_TPL) (IN EFI_TPL OldTpl);
typedef EFI_STATUS(EFIAPI* EFI_SERVICE_BINDING_CREATE_CHILD) (IN VOID* This, IN OUT EFI_HANDLE* ChildHandle);
typedef EFI_STATUS(EFIAPI* EFI_SERVICE_BINDING_DESTROY_CHILD) (IN VOID* This, IN EFI_HANDLE ChildHandle);
typedef VOID(EFIAPI* EFI_SET_MEM) (IN VOID* Buffer, IN UINTN Size, IN UINT8 Value);
typedef EFI_STATUS(EFIAPI* EFI_SET_TIME) (IN EFI_TIME* Time);
typedef EFI_STATUS(EFIAPI* EFI_SET_TIMER) (IN EFI_EVENT Event, IN EFI_TIMER_DELAY Type, IN UINT64 TriggerTime);
typedef EFI_STATUS(EFIAPI* EFI_SET_VARIABLE) (IN CHAR16* VariableName, IN EFI_GUID* VendorGuid, IN UINT32 Attributes, IN UINTN DataSize, IN VOID* Data);
typedef EFI_STATUS(EFIAPI* EFI_SET_VIRTUAL_ADDRESS_MAP) (IN UINTN MemoryMapSize, IN UINTN DescriptorSize, IN UINT32 DescriptorVersion, IN EFI_MEMORY_DESCRIPTOR* VirtualMap);
typedef EFI_STATUS(EFIAPI* EFI_SET_WAKEUP_TIME) (IN BOOLEAN Enable, IN EFI_TIME* Time OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_SET_WATCHDOG_TIMER) (IN UINTN Timeout, IN UINT64 WatchdogCode, IN UINTN DataSize, IN CHAR16* WatchdogData OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_SIGNAL_EVENT) (IN EFI_EVENT Event);
typedef EFI_STATUS(EFIAPI* EFI_STALL) (IN UINTN Microseconds);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_ACCEPT) (IN VOID* This, IN EFI_TCP4_LISTEN_TOKEN* ListenToken);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_CANCEL)(IN VOID* This, IN EFI_TCP4_COMPLETION_TOKEN* Token OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_CLOSE)(IN VOID* This, IN EFI_TCP4_CLOSE_TOKEN* CloseToken);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_CONFIGURE) (IN VOID* This, IN EFI_TCP4_CONFIG_DATA* TcpConfigData OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_CONNECT) (IN VOID* This, IN EFI_TCP4_CONNECTION_TOKEN* ConnectionToken);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_GET_MODE_DATA) (IN VOID* This, OUT EFI_TCP4_CONNECTION_STATE* Tcp4State OPTIONAL, OUT EFI_TCP4_CONFIG_DATA* Tcp4ConfigData OPTIONAL, OUT EFI_IP4_MODE_DATA* Ip4ModeData OPTIONAL, OUT EFI_MANAGED_NETWORK_CONFIG_DATA* MnpConfigData OPTIONAL, OUT EFI_SIMPLE_NETWORK_MODE* SnpModeData OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_POLL) (IN VOID* This);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_RECEIVE) (IN VOID* This, IN EFI_TCP4_IO_TOKEN* Token);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_ROUTES) (IN VOID* This, IN BOOLEAN DeleteRoute, IN EFI_IPv4_ADDRESS* SubnetAddress, IN EFI_IPv4_ADDRESS* SubnetMask, IN EFI_IPv4_ADDRESS* GatewayAddress);
typedef EFI_STATUS(EFIAPI* EFI_TCP4_TRANSMIT) (IN VOID* This, IN EFI_TCP4_IO_TOKEN* Token);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_CLEAR_SCREEN) (IN VOID* This);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_ENABLE_CURSOR) (IN VOID* This, IN BOOLEAN Visible);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_QUERY_MODE) (IN VOID* This, IN UINTN ModeNumber, OUT UINTN* Columns, OUT UINTN* Rows);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_RESET) (IN VOID* This, IN BOOLEAN ExtendedVerification);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_SET_ATTRIBUTE) (IN VOID* This, IN UINTN Attribute);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_SET_CURSOR_POSITION) (IN VOID* This, IN UINTN Column, IN UINTN Row);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_SET_MODE) (IN VOID* This, IN UINTN ModeNumber);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_STRING) (IN VOID* This, IN CHAR16* String);
typedef EFI_STATUS(EFIAPI* EFI_TEXT_TEST_STRING) (IN VOID* This, IN CHAR16* String);
typedef EFI_STATUS(EFIAPI* EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (IN EFI_HANDLE Handle, ...);
typedef EFI_STATUS(EFIAPI* EFI_UNINSTALL_PROTOCOL_INTERFACE) (IN EFI_HANDLE Handle, IN EFI_GUID* Protocol, IN VOID* Interface);
typedef EFI_STATUS(EFIAPI* EFI_UPDATE_CAPSULE) (IN EFI_CAPSULE_HEADER** CapsuleHeaderArray, IN UINTN CapsuleCount, IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL);
typedef EFI_STATUS(EFIAPI* EFI_WAIT_FOR_EVENT) (IN UINTN NumberOfEvents, IN EFI_EVENT* Event, OUT UINTN* Index);

typedef struct
{
	EFI_TABLE_HEADER Hdr;
	EFI_RAISE_TPL RaiseTPL;
	EFI_RESTORE_TPL RestoreTPL;
	EFI_ALLOCATE_PAGES AllocatePages;
	EFI_FREE_PAGES FreePages;
	EFI_GET_MEMORY_MAP GetMemoryMap;
	EFI_ALLOCATE_POOL AllocatePool;
	EFI_FREE_POOL FreePool;
	EFI_CREATE_EVENT CreateEvent;
	EFI_SET_TIMER SetTimer;
	EFI_WAIT_FOR_EVENT WaitForEvent;
	EFI_SIGNAL_EVENT SignalEvent;
	EFI_CLOSE_EVENT CloseEvent;
	EFI_CHECK_EVENT CheckEvent;
	EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
	EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInterface;
	EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;
	EFI_HANDLE_PROTOCOL HandleProtocol;
	VOID* Reserved;
	EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
	EFI_LOCATE_HANDLE LocateHandle;
	EFI_LOCATE_DEVICE_PATH LocateDevicePath;
	EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;
	EFI_IMAGE_LOAD LoadImage;
	EFI_IMAGE_START StartImage;
	EFI_EXIT Exit;
	EFI_IMAGE_UNLOAD UnloadImage;
	EFI_EXIT_BOOT_SERVICES ExitBootServices;
	EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
	EFI_STALL Stall;
	EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;
	EFI_CONNECT_CONTROLLER ConnectController;
	EFI_DISCONNECT_CONTROLLER DisconnectController;
	EFI_OPEN_PROTOCOL OpenProtocol;
	EFI_CLOSE_PROTOCOL CloseProtocol;
	EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;
	EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
	EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
	EFI_LOCATE_PROTOCOL LocateProtocol;
	EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;
	EFI_CALCULATE_CRC32 CalculateCrc32;
	EFI_COPY_MEM CopyMem;
	EFI_SET_MEM SetMem;
	EFI_CREATE_EVENT_EX CreateEventEx;
} EFI_BOOT_SERVICES;

typedef struct
{
	EFI_GUID VendorGuid;
	VOID* VendorTable;
} EFI_CONFIGURATION_TABLE;

typedef struct
{
	EFI_MP_SERVICES_GET_NUMBER_OF_PROCESSORS GetNumberOfProcessors;
	EFI_MP_SERVICES_GET_PROCESSOR_INFO GetProcessorInfo;
	EFI_MP_SERVICES_STARTUP_ALL_APS StartupAllAPs;
	EFI_MP_SERVICES_STARTUP_THIS_AP StartupThisAP;
	EFI_MP_SERVICES_SWITCH_BSP SwitchBSP;
	EFI_MP_SERVICES_ENABLEDISABLEAP EnableDisableAP;
	EFI_MP_SERVICES_WHOAMI WhoAmI;
} EFI_MP_SERVICES_PROTOCOL;

typedef struct
{
	EFI_TABLE_HEADER Hdr;
	EFI_GET_TIME GetTime;
	EFI_SET_TIME SetTime;
	EFI_GET_WAKEUP_TIME GetWakeupTime;
	EFI_SET_WAKEUP_TIME SetWakeupTime;
	EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
	EFI_CONVERT_POINTER ConvertPointer;
	EFI_GET_VARIABLE GetVariable;
	EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
	EFI_SET_VARIABLE SetVariable;
	EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
	EFI_RESET_SYSTEM ResetSystem;
	EFI_UPDATE_CAPSULE UpdateCapsule;
	EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;
	EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

typedef struct
{
	EFI_SERVICE_BINDING_CREATE_CHILD CreateChild;
	EFI_SERVICE_BINDING_DESTROY_CHILD DestroyChild;
} EFI_SERVICE_BINDING_PROTOCOL;

typedef struct
{
	EFI_INPUT_RESET Reset;
	EFI_INPUT_READ_KEY ReadKeyStroke;
	EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef struct
{
	EFI_TEXT_RESET Reset;
	EFI_TEXT_STRING OutputString;
	EFI_TEXT_TEST_STRING TestString;
	EFI_TEXT_QUERY_MODE QueryMode;
	EFI_TEXT_SET_MODE SetMode;
	EFI_TEXT_SET_ATTRIBUTE SetAttribute;
	EFI_TEXT_CLEAR_SCREEN ClearScreen;
	EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
	EFI_TEXT_ENABLE_CURSOR EnableCursor;
	SIMPLE_TEXT_OUTPUT_MODE* Mode;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct
{
	EFI_TABLE_HEADER Hdr;
	CHAR16* FirmwareVendor;
	UINT32 FirmwareRevision;
	EFI_HANDLE ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL* ConIn;
	EFI_HANDLE ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut;
	EFI_HANDLE StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* StdErr;
	EFI_RUNTIME_SERVICES* RuntimeServices;
	EFI_BOOT_SERVICES* BootServices;
	UINTN NumberOfTableEntries;
	EFI_CONFIGURATION_TABLE* ConfigurationTable;
} EFI_SYSTEM_TABLE;

typedef struct
{
	EFI_TCP4_GET_MODE_DATA GetModeData;
	EFI_TCP4_CONFIGURE Configure;
	EFI_TCP4_ROUTES Routes;
	EFI_TCP4_CONNECT Connect;
	EFI_TCP4_ACCEPT Accept;
	EFI_TCP4_TRANSMIT Transmit;
	EFI_TCP4_RECEIVE Receive;
	EFI_TCP4_CLOSE Close;
	EFI_TCP4_CANCEL Cancel;
	EFI_TCP4_POLL Poll;
} EFI_TCP4_PROTOCOL;

////////// Application \\\\\\\\\\

static EFI_SYSTEM_TABLE* st;
static EFI_RUNTIME_SERVICES* rs;
static EFI_BOOT_SERVICES* bs;

volatile static INTN state = 0;

static UINTN numberOfProcessors;

static EFI_TCP4_PROTOCOL* tcp4Protocol;
static EFI_TCP4_LISTEN_TOKEN listenToken;

static VOID appendText(CHAR16* dst, CONST CHAR16* src)
{
	UINT16 dstIndex = 0;
	while (dst[dstIndex] != 0)
	{
		dstIndex++;
	}
	UINT16 srcIndex = 0;
	while ((dst[dstIndex++] = src[srcIndex++]) != 0)
	{
	}
}

static VOID setText(CHAR16* dst, CONST CHAR16* src)
{
	dst[0] = 0;
	appendText(dst, src);
}

static VOID appendNumber(CHAR16* dst, UINT64 number)
{
	CHAR16 text[27];
	INT8 textLength = 0;
	do
	{
		text[textLength++] = number % 10 + '0';
	} while ((number /= 10) > 0);
	UINT16 dstIndex = 0;
	while (dst[dstIndex] != 0)
	{
		dstIndex++;
	}
	while (--textLength >= 0)
	{
		dst[dstIndex++] = text[textLength];
		if (textLength % 3 == 0 && textLength != 0)
		{
			dst[dstIndex++] = '\'';
		}
	}
	dst[dstIndex] = 0;
}

static VOID setNumber(CHAR16* dst, CONST UINT64 number)
{
	dst[0] = 0;
	appendNumber(dst, number);
}

static VOID appendBoolean(CHAR16* dst, CONST BOOLEAN value)
{
	appendText(dst, value ? L"TRUE" : L"FALSE");
}

static VOID appendIPv4Address(CHAR16* dst, EFI_IPv4_ADDRESS address)
{
	appendNumber(dst, address.Addr[0]);
	appendText(dst, L".");
	appendNumber(dst, address.Addr[1]);
	appendText(dst, L".");
	appendNumber(dst, address.Addr[2]);
	appendText(dst, L".");
	appendNumber(dst, address.Addr[3]);
}
static VOID appendErrorStatus(CHAR16* dst, CONST EFI_STATUS status)
{
	switch (status & 0x7FFFFFFFFFFFFFFF)
	{
	case EFI_LOAD_ERROR:			appendText(dst, L"EFI_LOAD_ERROR");				break;
	case EFI_INVALID_PARAMETER:		appendText(dst, L"EFI_INVALID_PARAMETER");		break;
	case EFI_UNSUPPORTED:			appendText(dst, L"EFI_UNSUPPORTED");			break;
	case EFI_BAD_BUFFER_SIZE:		appendText(dst, L"EFI_BAD_BUFFER_SIZE");		break;
	case EFI_BUFFER_TOO_SMALL:		appendText(dst, L"EFI_BUFFER_TOO_SMALL");		break;
	case EFI_NOT_READY:				appendText(dst, L"EFI_NOT_READY");				break;
	case EFI_DEVICE_ERROR:			appendText(dst, L"EFI_DEVICE_ERROR");			break;
	case EFI_WRITE_PROTECTED:		appendText(dst, L"EFI_WRITE_PROTECTED");		break;
	case EFI_OUT_OF_RESOURCES:		appendText(dst, L"EFI_OUT_OF_RESOURCES");		break;
	case EFI_VOLUME_CORRUPTED:		appendText(dst, L"EFI_VOLUME_CORRUPTED");		break;
	case EFI_VOLUME_FULL:			appendText(dst, L"EFI_VOLUME_FULL");			break;
	case EFI_NO_MEDIA:				appendText(dst, L"EFI_NO_MEDIA");				break;
	case EFI_MEDIA_CHANGED:			appendText(dst, L"EFI_MEDIA_CHANGED");			break;
	case EFI_NOT_FOUND:				appendText(dst, L"EFI_NOT_FOUND");				break;
	case EFI_ACCESS_DENIED:			appendText(dst, L"EFI_ACCESS_DENIED");			break;
	case EFI_NO_RESPONSE:			appendText(dst, L"EFI_NO_RESPONSE");			break;
	case EFI_NO_MAPPING:			appendText(dst, L"EFI_NO_MAPPING");				break;
	case EFI_TIMEOUT:				appendText(dst, L"EFI_TIMEOUT");				break;
	case EFI_NOT_STARTED:			appendText(dst, L"EFI_NOT_STARTED");			break;
	case EFI_ALREADY_STARTED:		appendText(dst, L"EFI_ALREADY_STARTED");		break;
	case EFI_ABORTED:				appendText(dst, L"EFI_ABORTED");				break;
	case EFI_ICMP_ERROR:			appendText(dst, L"EFI_ICMP_ERROR");				break;
	case EFI_TFTP_ERROR:			appendText(dst, L"EFI_TFTP_ERROR");				break;
	case EFI_PROTOCOL_ERROR:		appendText(dst, L"EFI_PROTOCOL_ERROR");			break;
	case EFI_INCOMPATIBLE_VERSION:	appendText(dst, L"EFI_INCOMPATIBLE_VERSION");	break;
	case EFI_SECURITY_VIOLATION:	appendText(dst, L"EFI_SECURITY_VIOLATION");		break;
	case EFI_CRC_ERROR:				appendText(dst, L"EFI_CRC_ERROR");				break;
	case EFI_END_OF_MEDIA:			appendText(dst, L"EFI_END_OF_MEDIA");			break;
	case EFI_END_OF_FILE:			appendText(dst, L"EFI_END_OF_FILE");			break;
	case EFI_INVALID_LANGUAGE:		appendText(dst, L"EFI_INVALID_LANGUAGE");		break;
	case EFI_COMPROMISED_DATA:		appendText(dst, L"EFI_COMPROMISED_DATA");		break;
	case EFI_IP_ADDRESS_CONFLICT:	appendText(dst, L"EFI_IP_ADDRESS_CONFLICT");	break;
	case EFI_HTTP_ERROR:			appendText(dst, L"EFI_HTTP_ERROR");				break;
	default: appendNumber(dst, status);
	}
}

static VOID log(CONST CHAR16* message)
{
	CHAR16 timestampedMessage[256];

	EFI_TIME time;
	rs->GetTime(&time, NULL);
	timestampedMessage[0] = time.Year / 1000 + '0';
	timestampedMessage[1] = (time.Year %= 1000) / 100 + '0';
	timestampedMessage[2] = (time.Year %= 100) / 10 + '0';
	timestampedMessage[3] = time.Year % 10 + '0';
	timestampedMessage[4] = '-';
	timestampedMessage[5] = time.Month / 10 + '0';
	timestampedMessage[6] = time.Month % 10 + '0';
	timestampedMessage[7] = '-';
	timestampedMessage[8] = time.Day / 10 + '0';
	timestampedMessage[9] = time.Day % 10 + '0';
	timestampedMessage[10] = ' ';
	timestampedMessage[11] = time.Hour / 10 + '0';
	timestampedMessage[12] = time.Hour % 10 + '0';
	timestampedMessage[13] = ':';
	timestampedMessage[14] = time.Minute / 10 + '0';
	timestampedMessage[15] = time.Minute % 10 + '0';
	timestampedMessage[16] = ':';
	timestampedMessage[17] = time.Second / 10 + '0';
	timestampedMessage[18] = time.Second % 10 + '0';
	timestampedMessage[19] = ' ';
	timestampedMessage[20] = '|';
	timestampedMessage[21] = ' ';
	timestampedMessage[22] = 0;

	appendText(timestampedMessage, message);
	appendText(timestampedMessage, L"\r\n");

	st->ConOut->OutputString(st->ConOut, timestampedMessage);
}

static VOID log(CONST CHAR16* message, CONST EFI_STATUS status)
{
	CHAR16 extendedMessage[256];
	setText(extendedMessage, message);
	appendText(extendedMessage, L" (");
	appendErrorStatus(extendedMessage, status);
	appendText(extendedMessage, L")!");
	log(extendedMessage);
}

static VOID processAcceptEvent(EFI_EVENT event, VOID* context)
{
	bs->CloseEvent(event);

	log(L"CONNECTED.");

	bs->CreateEvent(EVT_NOTIFY_SIGNAL, TPL_CALLBACK, processAcceptEvent, NULL, &listenToken.CompletionToken.Event);
	tcp4Protocol->Accept(tcp4Protocol, &listenToken);
}

EFI_STATUS efi_main(EFI_HANDLE imageHandle, EFI_SYSTEM_TABLE* systemTable)
{
	st = systemTable;
	rs = st->RuntimeServices;
	bs = st->BootServices;
	
	bs->SetWatchdogTimer(0, 0, 0, NULL);

	st->ConOut->ClearScreen(st->ConOut);
	log(L"Qubic 0.0.6 is launched.");

	CHAR16 message[256];

	EFI_GUID mpServiceProtocolGuid = EFI_MP_SERVICES_PROTOCOL_GUID;
	EFI_MP_SERVICES_PROTOCOL* mpServicesProtocol;
	bs->LocateProtocol(&mpServiceProtocolGuid, NULL, (VOID**)&mpServicesProtocol);
	UINTN numberOfEnabledProcessors;
	mpServicesProtocol->GetNumberOfProcessors(mpServicesProtocol, &numberOfProcessors, &numberOfEnabledProcessors);
	setNumber(message, numberOfEnabledProcessors);
	appendText(message, L"/");
	appendNumber(message, numberOfProcessors);
	appendText(message, L" processors are enabled.");
	log(message);

	EFI_STATUS status;
	EFI_GUID tcp4ProtocolGuid = EFI_TCP4_PROTOCOL_GUID;
	if (status = bs->LocateProtocol(&tcp4ProtocolGuid, NULL, (VOID**)&tcp4Protocol))
	{
		log(L"EFI_TCP4_PROTOCOL is not located", status);
	}
	else
	{
		EFI_TCP4_CONFIG_DATA configData;
		bs->SetMem(&configData, sizeof(configData), 0);
		configData.TimeToLive = 64;
		if (!*((int*)&tcp4Address))
		{
			configData.AccessPoint.UseDefaultAddress = TRUE;
		}
		else
		{
			bs->CopyMem(&configData.AccessPoint.StationAddress, (VOID*)&tcp4Address, sizeof(configData.AccessPoint.StationAddress));
			bs->CopyMem(&configData.AccessPoint.SubnetMask, (VOID*)&tcp4Mask, sizeof(configData.AccessPoint.SubnetMask));
		}
		configData.AccessPoint.StationPort = 21841;
		if (status = tcp4Protocol->Configure(tcp4Protocol, &configData))
		{
			log(L"EFI_TCP4_PROTOCOL.Configure() fails", status);
		}
		else
		{
			if (*((int*)&defaultRouteGateway))
			{
				if (status = tcp4Protocol->Routes(tcp4Protocol, FALSE, (EFI_IPv4_ADDRESS*)&defaultRouteAddress, (EFI_IPv4_ADDRESS*)&defaultRouteMask, (EFI_IPv4_ADDRESS*)&defaultRouteGateway))
				{
					log(L"EFI_TCP4_PROTOCOL.Routes() fails", status);
				}
			}

			EFI_IP4_MODE_DATA modeData;
			if (status = tcp4Protocol->GetModeData(tcp4Protocol, NULL, &configData, &modeData, NULL, NULL))
			{

				log(L"EFI_TCP4_PROTOCOL.GetModeData() fails", status);
			}
			else
			{
				if (!modeData.IsStarted || !modeData.IsConfigured)
				{
					log(L"EFI_TCP4_PROTOCOL is not configured!");
				}
				else
				{
					setText(message, L"IPv4 address = ");
					appendIPv4Address(message, configData.AccessPoint.StationAddress);
					appendText(message, L".");
					log(message);

					if (!modeData.RouteCount)
					{
						log(L"No routes found.");
					}
					else
					{
						log(L"Routes:");
						for (unsigned int i = 0; i < modeData.RouteCount; i++)
						{
							setText(message, L"Address = ");
							appendIPv4Address(message, modeData.RouteTable[i].SubnetAddress);
							appendText(message, L" | mask = ");
							appendIPv4Address(message, modeData.RouteTable[i].SubnetMask);
							appendText(message, L" | gateway = ");
							appendIPv4Address(message, modeData.RouteTable[i].GatewayAddress);
							appendText(message, L".");
							log(message);
						}
					}

					bs->CreateEvent(EVT_NOTIFY_SIGNAL, TPL_CALLBACK, processAcceptEvent, NULL, &listenToken.CompletionToken.Event);
					if (status = tcp4Protocol->Accept(tcp4Protocol, &listenToken))
					{
						log(L"EFI_TCP4_PROTOCOL.Accept() fails", status);
					}
					else
					{
						while (!state && role == UNDEFINED_ROLE)
						{
							tcp4Protocol->Poll(tcp4Protocol);
						}
					}
				}
			}
		}
	}

	bs->Stall(1000000);
	st->ConIn->Reset(st->ConIn, FALSE);
	UINTN eventIndex;
	bs->WaitForEvent(1, &st->ConIn->WaitForKey, &eventIndex);

	return EFI_SUCCESS;
}