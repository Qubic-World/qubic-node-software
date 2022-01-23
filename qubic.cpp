#define __WINDOWS__
#define _AMD64_
#define _AVX2_

#include <intrin.h>
//#include "FourQ_64bit_and_portable\FourQ_api.h"
#include "uefi.h"

static CONST EFI_IPv4_ADDRESS tcp4Address = { 192, 168, 0, 1 };
static CONST EFI_IPv4_ADDRESS tcp4Mask = { 255, 255, 255, 0 };
static CONST UINT16 tcp4Port = 21841;
static CONST UINT8 aesIV[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
static CONST UINT8 identity[32] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 };

static EFI_SYSTEM_TABLE* st;
static EFI_RUNTIME_SERVICES* rs;
static EFI_BOOT_SERVICES* bs;

volatile static INTN state = 0;

static UINTN numberOfProcessors;

static EFI_TCP4_PROTOCOL* tcp4Protocol;
static EFI_TCP4_LISTEN_TOKEN listenToken;

VOID appendText(CHAR16* dst, CONST CHAR16* src)
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

VOID setText(CHAR16* dst, CONST CHAR16* src)
{
	dst[0] = 0;
	appendText(dst, src);
}

VOID appendNumber(CHAR16* dst, UINT64 number)
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

VOID setNumber(CHAR16* dst, CONST UINT64 number)
{
	dst[0] = 0;
	appendNumber(dst, number);
}

VOID appendBoolean(CHAR16* dst, CONST BOOLEAN value)
{
	appendText(dst, value ? L"TRUE" : L"FALSE");
}

VOID appendIPv4Address(CHAR16* dst, EFI_IPv4_ADDRESS address)
{
	appendNumber(dst, address.Addr[0]);
	appendText(dst, L".");
	appendNumber(dst, address.Addr[1]);
	appendText(dst, L".");
	appendNumber(dst, address.Addr[2]);
	appendText(dst, L".");
	appendNumber(dst, address.Addr[3]);
}
VOID appendErrorStatus(CHAR16* dst, CONST EFI_STATUS status)
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

VOID log(CONST CHAR16* message)
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

VOID log(CONST CHAR16* message, CONST EFI_STATUS status)
{
	CHAR16 extendedMessage[256];
	setText(extendedMessage, message);
	appendText(extendedMessage, L" (");
	appendErrorStatus(extendedMessage, status);
	appendText(extendedMessage, L")!");
	log(extendedMessage);
}

VOID processAcceptEvent(EFI_EVENT event, VOID* context)
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
	log(L"Qubic 0.0.5 is launched.");

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

	UINT32 numberOfHealtyProcessors = 0;
	for (UINT16 processorIndex = 0; processorIndex < numberOfProcessors; processorIndex++)
	{
		EFI_PROCESSOR_INFORMATION processorInformation;
		mpServicesProtocol->GetProcessorInfo(mpServicesProtocol, processorIndex, &processorInformation);
		if ((processorInformation.StatusFlag & PROCESSOR_HEALTH_STATUS_BIT) == PROCESSOR_HEALTH_STATUS_BIT)
		{
			numberOfHealtyProcessors++;
		}
	}
	setNumber(message, numberOfHealtyProcessors);
	appendText(message, L"/");
	appendNumber(message, numberOfProcessors);
	appendText(message, L" processors are healthy.");
	log(message);

	EFI_STATUS status;
	EFI_GUID tcp4ProtocolGuid = EFI_TCP4_PROTOCOL_GUID;
	if ((status = bs->LocateProtocol(&tcp4ProtocolGuid, NULL, (VOID**)&tcp4Protocol)) != EFI_SUCCESS)
	{
		log(L"EFI_TCP4_PROTOCOL is not located", status);
	}
	else
	{
		EFI_TCP4_CONFIG_DATA configData;
		bs->SetMem(&configData, sizeof(configData), 0);
		configData.TimeToLive = 64;
		bs->CopyMem(&configData.AccessPoint.StationAddress, (VOID*)&tcp4Address, sizeof(configData.AccessPoint.StationAddress));
		bs->CopyMem(&configData.AccessPoint.SubnetMask, (VOID*)&tcp4Mask, sizeof(configData.AccessPoint.SubnetMask));
		configData.AccessPoint.StationPort = tcp4Port;
		if ((status = tcp4Protocol->Configure(tcp4Protocol, &configData)) != EFI_SUCCESS) {

			log(L"EFI_TCP4_PROTOCOL.Configure() fails", status);
		}
		else
		{
			EFI_IP4_MODE_DATA modeData;
			if ((status = tcp4Protocol->GetModeData(tcp4Protocol, NULL, &configData, &modeData, NULL, NULL)) != EFI_SUCCESS) {

				log(L"EFI_TCP4_PROTOCOL.GetModeData() fails", status);
			}
			else
			{
				if (!modeData.IsStarted || !modeData.IsConfigured) {

					log(L"EFI_TCP4_PROTOCOL is not configured!");
				}
				else
				{
					bs->CreateEvent(EVT_NOTIFY_SIGNAL, TPL_CALLBACK, processAcceptEvent, NULL, &listenToken.CompletionToken.Event);
					if ((status = tcp4Protocol->Accept(tcp4Protocol, &listenToken)) != EFI_SUCCESS)
					{
						log(L"EFI_TCP4_PROTOCOL.Accept() fails", status);
					}
					else
					{
						while (!state) {

							tcp4Protocol->Poll(tcp4Protocol);
						}
					}
				}
			}
		}
	}

	bs->Stall(5000000);
	st->ConIn->Reset(st->ConIn, FALSE);
	UINTN eventIndex;
	bs->WaitForEvent(1, &st->ConIn->WaitForKey, &eventIndex);

	return EFI_SUCCESS;
}