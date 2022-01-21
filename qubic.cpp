#include <intrin.h>
#include "uefi.h"

static EFI_SYSTEM_TABLE* st;
static EFI_RUNTIME_SERVICES* rs;
static EFI_BOOT_SERVICES* bs;

static UINT64 tscScaledFrequencyNumerator, tscScaledFrequencyDenominator;

static UINTN numberOfProcessors;

static EFI_TCP4_PROTOCOL* tcp4Protocol;

UINT64 timestamp()
{
	return __rdtsc() * tscScaledFrequencyDenominator / tscScaledFrequencyNumerator;
}

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

VOID setNumber(CHAR16* dst, UINT64 number)
{
	dst[0] = 0;
	appendNumber(dst, number);
}

VOID appendStatus(CHAR16* dst, EFI_STATUS status)
{
	switch (status & 0x7FFFFFFFFFFFFFFF)
	{
	case EFI_SUCCESS:				appendText(dst, L"EFI_SUCCESS");				break;
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

EFI_STATUS efi_main(EFI_HANDLE imageHandle, EFI_SYSTEM_TABLE* systemTable)
{
	st = systemTable;
	rs = st->RuntimeServices;
	bs = st->BootServices;
	
	bs->SetWatchdogTimer(0, 0, 0, NULL);

	st->ConOut->ClearScreen(st->ConOut);
	log(L"Qubic 0.0.1 is launched.");

	CHAR16 message[256];

	INT32 cpuInfo[4];
	__cpuid(cpuInfo, 0x15);
	if (cpuInfo[2] == 0 || cpuInfo[1] == 0 || cpuInfo[0] == 0)
	{
		UINT64 startingTick = __rdtsc();
		bs->Stall(1000000);
		UINT64 finishingTick = __rdtsc();
		tscScaledFrequencyDenominator = 1000;
		tscScaledFrequencyNumerator = ((finishingTick - startingTick) / 1000000) * 1000;
	}
	else
	{
		tscScaledFrequencyDenominator = ((UINT64)((UINT32)cpuInfo[0])) * 1000;
		tscScaledFrequencyNumerator = ((UINT64)((UINT32)cpuInfo[1])) * ((UINT32)cpuInfo[2]) / 1000;
	}
	setText(message, L"Time Stamp Counter frequency is ");
	appendNumber(message, tscScaledFrequencyNumerator * 1000000 / tscScaledFrequencyDenominator);
	appendText(message, L" Hz.");
	log(message);

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

	UINT16 processorIndex;
	for (processorIndex = 0; processorIndex < numberOfProcessors; processorIndex++)
	{
		EFI_PROCESSOR_INFORMATION processorInformation;
		mpServicesProtocol->GetProcessorInfo(mpServicesProtocol, processorIndex, &processorInformation);
		if ((processorInformation.StatusFlag & (PROCESSOR_ENABLED_BIT | PROCESSOR_HEALTH_STATUS_BIT)) != (PROCESSOR_ENABLED_BIT | PROCESSOR_HEALTH_STATUS_BIT))
		{
			break;
		}
	}
	if (processorIndex != numberOfProcessors)
	{
		log(L"Not all processors are healthy!");
	}
	else {

		log(L"All processors are healthy.");
	}

	mpServicesProtocol->SwitchBSP(mpServicesProtocol, 0, TRUE);

	EFI_STATUS status;

	EFI_GUID tcp4ServiceBindingProtocolGuid = EFI_TCP4_SERVICE_BINDING_PROTOCOL_GUID;
	UINTN numberOfHandles;
	EFI_HANDLE* handles;
	if ((status = bs->LocateHandleBuffer(ByProtocol, &tcp4ServiceBindingProtocolGuid, NULL, &numberOfHandles, &handles)) != EFI_SUCCESS) {

		setText(message, L"TCPv4 service binding protocol is not located (");
		appendStatus(message, status);
		appendText(message, L")!");
		log(message);
	}
	if (handles != NULL) {

		bs->FreePool(handles);
	}

	EFI_GUID tcp4ProtocolGuid = EFI_TCP4_PROTOCOL_GUID;
	if ((status = bs->LocateProtocol(&tcp4ProtocolGuid, NULL, (VOID**)&tcp4Protocol)) != EFI_SUCCESS)
	{
		setText(message, L"TCPv4 protocol is not located (");
		appendStatus(message, status);
		appendText(message, L")!");
		log(message);
	}

	EFI_GUID tcpSimpleNetworkProtocolGuid = EFI_SIMPLE_NETWORK_PROTOCOL_GUID;
	if ((status = bs->LocateProtocol(&tcpSimpleNetworkProtocolGuid, NULL, (VOID**)&tcp4Protocol)) != EFI_SUCCESS)
	{
		setText(message, L"Simple network protocol is not located (");
		appendStatus(message, status);
		appendText(message, L")!");
		log(message);
	}

	log(L"Test is finished.");

	bs->Stall(1000000);
	st->ConIn->Reset(st->ConIn, FALSE);
	UINTN eventIndex;
	bs->WaitForEvent(1, &st->ConIn->WaitForKey, &eventIndex);

	return EFI_SUCCESS;
}