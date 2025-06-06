#include "StdAfx.h"
#include "Util.h"
#include "SItemSetOption.h"

CSItemSetOption g_csItemOption;


CSItemSetOption::CSItemSetOption(void)
{
	memset(this->m_ItemSetOption, 0, sizeof(this->m_ItemSetOption));
}

CSItemSetOption::~CSItemSetOption(void)
{
}

__declspec(naked) void AncientOptionData_1( )
{
	static DWORD var_addr = 0x004E957B;
	static DWORD var_25C = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     ecx, [var_25C]
		lea     edx, [ecx+eax]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_2( )
{
	static DWORD var_addr = 0x004E9275;
	static DWORD var_14 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     ecx, [var_14]
		lea     edx, [ecx+eax]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_3( )
{
	static DWORD var_addr = 0x004EBD8C;
	static DWORD var_118 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     edx, [var_118]
		lea     eax, [edx+ecx]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_4( )
{
	static DWORD var_addr = 0x004EBEF3;
	static DWORD var_28 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     eax, [var_28]
		lea     ecx, [eax+edx]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_5( )
{
	static DWORD var_addr = 0x004EC2AF;
	static DWORD var_54 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     eax, [var_54]
		lea     ecx, [eax+edx]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_6( )
{
	static DWORD var_addr = 0x004EC3B3;
	static DWORD var_54 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     eax, [var_54]
		lea     ecx, [eax + edx]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_7( )
{
	static DWORD var_addr = 0x004EC4CE;
	static DWORD var_54 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     edx, [var_54]
		lea     eax, [edx + ecx]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_8( )
{
	static DWORD var_addr = 0x004ECAB4;
	static DWORD var_54 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     ecx, [var_54]
		lea     edx, [ecx + eax]
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_0( )
{
	static DWORD var_addr = 0x004E8CE2;
	static DWORD var_54 = (DWORD)&g_csItemOption.m_ItemSetOption;

	_asm
	{
		mov     eax, dword ptr ss:[var_54]
		lea     ecx, dword ptr ds:[eax+edx]
		push    ecx
		jmp     [var_addr]
	}
}

__declspec(naked) void AncientOptionData_Lea( )
{
	static DWORD var_addr1 = 0x004E8CB1;
	static DWORD var_addr2 = 0x004E8CFB;

	_asm
	{
		mov     dword ptr ss:[ebp-0x118], eax
		cmp     dword ptr ss:[ebp-0x118], MAX_SET_OPTION
		Je      EXIT
		mov     ecx, dword ptr ss:[ebp-0xc]
		push    ecx
		jmp     [var_addr1]
EXIT:
		jmp     [var_addr2]
	}
}

void CSItemSetOption::Init()
{
	SetByte(0x004E8BB7 + 2, 0x9u);
	SetByte(0x004E8BDB + 2, 0x9u);
	SetByte(0x004E8C13 + 2, 0x9u);
	SetCompleteHook(0xE9, 0x004E8CD4, &AncientOptionData_0);
	SetCompleteHook(0xE9, 0x004E8C9E, &AncientOptionData_Lea);
	//--
	SetCompleteHook(0xE9, 0x004E956E, &AncientOptionData_1);
	SetCompleteHook(0xE9, 0x004E926B, &AncientOptionData_2);
	SetCompleteHook(0xE9, 0x004EBD7F, &AncientOptionData_3);
	SetCompleteHook(0xE9, 0x004EBEE9, &AncientOptionData_4);
	SetCompleteHook(0xE9, 0x004EC2A5, &AncientOptionData_5);
	SetCompleteHook(0xE9, 0x004EC3A9, &AncientOptionData_6);
	SetCompleteHook(0xE9, 0x004EC4C4, &AncientOptionData_7); //-- tooltip normal
	SetCompleteHook(0xE9, 0x004ECAAA, &AncientOptionData_8);
}