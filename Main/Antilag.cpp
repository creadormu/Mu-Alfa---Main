#pragma once 
#include "stdafx.h"
#include "Antilag.h"
#include "Util.h"
#include "TrayModeNew.h"


__declspec(naked) void DelectlpViewPlayer()
{
	static DWORD Buff_lpViewPlayer = 0x0057D27F;

	if(gTrayMode.InTray)
	{
		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0
			JMP [Buff_lpViewPlayer]
		}
	}
	else
	{
		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],400
			JMP [Buff_lpViewPlayer]
		}
	}
}

__declspec(naked) void DelectEffectDynamic()
{
	static DWORD Buff_EffectDynamic = 0x0074CD57;

	if(gTrayMode.InTray)
	{
		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0
			JMP [Buff_EffectDynamic]
		}
	}
	else
	{
		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0x0BB8
			JMP [Buff_EffectDynamic]
		}
	}
}

__declspec(naked) void DelectEffectStatic()
{
	static DWORD Buff_EffectStatic = 0x0077132F;

	if(gTrayMode.InTray)
	{
		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0
			JMP [Buff_EffectStatic]
		}
	}
	else
	{
		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0x3E8
			JMP [Buff_EffectStatic]
		}
	}
}

void InitReduceCPU()
{
	SetCompleteHook(0xE9, 0x0057D278, &DelectlpViewPlayer);
	SetCompleteHook(0xE9, 0x0074CD50, &DelectEffectDynamic);
	SetCompleteHook(0xE9, 0x00771328, &DelectEffectStatic);
}