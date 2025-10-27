#include "stdafx.h"
#include "ImprovedHackCheck.h"
#include "HackCheck.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "AdvancedFPSManager.h"

typedef int(WINAPI*WSRECV)(SOCKET,char*,int,int);
typedef int(WINAPI*WSSEND)(SOCKET,char*,int,int);

extern WSRECV HookRecv;
extern WSSEND HookSend;
extern BYTE EncDecKey1;
extern BYTE EncDecKey2;
extern DWORD FrameValue;
extern DWORD SpeedValue;
extern DWORD MainTickCount;
extern DWORD SyncTickCount;
extern DWORD CountModifier;
extern DWORD DelayModifier;
extern DWORD HasteModifier;
extern DWORD SleepModifier;
extern DWORD SpeedModifier1;
extern DWORD SpeedModifier2;
extern DWORD ModelModifier1;
extern DWORD ModelModifier2;
extern DWORD ModelModifier3;

// Dynamic FPS configuration
static DWORD g_DynamicFPSLimit = 60; // Default to 60 FPS
static DWORD g_MinFrameTime = 8;     // Minimum frame time (125 FPS cap for stability)

void SetDynamicFPSLimit(int targetFPS)
{
	if (targetFPS <= 0)
	{
		// Unlimited FPS (capped at 125 for stability)
		g_DynamicFPSLimit = g_MinFrameTime;
	}
	else if (targetFPS >= 240)
	{
		g_DynamicFPSLimit = 4; // 250 FPS (1000/4)
	}
	else if (targetFPS >= 144)
	{
		g_DynamicFPSLimit = 7; // ~142 FPS (1000/7)
	}
	else if (targetFPS >= 120)
	{
		g_DynamicFPSLimit = 8; // 125 FPS (1000/8)
	}
	else if (targetFPS >= 60)
	{
		g_DynamicFPSLimit = 16; // ~62 FPS (1000/16)
	}
	else if (targetFPS >= 30)
	{
		g_DynamicFPSLimit = 33; // ~30 FPS (1000/33)
	}
	else
	{
		g_DynamicFPSLimit = 40; // 25 FPS (original)
	}
	
	// Update the FPS manager
	gAdvancedFPSManager.SetTargetFPS(targetFPS <= 0 ? TARGET_FPS_UNLIMITED : targetFPS);
}

int GetCurrentFPSLimit()
{
	return (int)(1000.0f / g_DynamicFPSLimit);
}

_declspec(naked) void CheckTickCount1_Improved()
{
	static DWORD CheckTickCountAddress1 = 0x004DA29B;

	_asm
	{
		Mov Dword Ptr Ss:[Ebp-0x68],0x00
		Mov Edx,MainTickCount
		Mov Dword Ptr Ss:[Ebp-0x74],Edx
		Call Dword Ptr Ds:[GetTickCount]
		Mov MainTickCount,Eax
		Mov SyncTickCount,Eax
		Jmp [CheckTickCountAddress1]
	}
}

static DWORD FPS_Improved;

_declspec(naked) void CheckTickCount2_Improved()
{
	static DWORD CheckTickCountAddress1 = 0x004DA3F0;
	
	// Use dynamic FPS limit instead of hardcoded value
	FPS_Improved = g_DynamicFPSLimit;
	
	_asm
	{
		Mov Ecx,Dword Ptr Ss:[Ebp-0x6C]
		Mov CountModifier,Ecx
		Mov Edx,Dword Ptr Ss:[Ebp-0x74]
		Mov DelayModifier,Edx
		Mov Ecx,Dword Ptr Ss:[Ebp-0x178]
		Mov HasteModifier,Ecx
		Mov Edx,Dword Ptr Ds:[MAIN_VIEWPORT_STRUCT]
		Mov Ecx,Dword Ptr Ds:[Edx+0x214]
		Mov SpeedModifier1,Ecx
		Mov Edx,Dword Ptr Ds:[MAIN_VIEWPORT_STRUCT]
		Mov Ecx,Dword Ptr Ds:[Edx+0x218]
		Mov SpeedModifier2,Ecx
		Mov Edx,Dword Ptr Ds:[MAIN_VIEWPORT_STRUCT]
		Mov Ecx,Dword Ptr Ds:[Edx+0x31A]
		Mov ModelModifier1,Ecx
		Mov Edx,Dword Ptr Ds:[MAIN_VIEWPORT_STRUCT]
		Mov Ecx,Dword Ptr Ds:[Edx+0x394]
		Mov ModelModifier2,Ecx
		Mov Edx,Dword Ptr Ds:[MAIN_VIEWPORT_STRUCT]
		Mov Ecx,Dword Ptr Ds:[Edx+0x398]
		Mov ModelModifier3,Ecx
		Mov Eax,MainTickCount
		Sub Eax,Dword Ptr Ss:[Ebp-0x74]
		Mov Dword Ptr Ss:[Ebp-0x68],Eax
		
		// Compare with dynamic frame time instead of hardcoded 0x28 (40ms)
		Mov Ecx,FPS_Improved
		Cmp Dword Ptr Ss:[Ebp-0x68],Ecx
		Jge CONTINUE
		
		Mov Ecx,FPS_Improved
		Sub Ecx,Dword Ptr Ss:[Ebp-0x68]
		Mov Dword Ptr Ss:[Ebp-0x18C],Ecx
		Mov Edx,Dword Ptr Ss:[Ebp-0x18C]
		Mov SleepModifier,Edx
		
		NEXT:
		Push 1
		Call Dword Ptr Ds:[Sleep]
		Call Dword Ptr Ds:[GetTickCount]
		Sub Eax,Dword Ptr Ss:[Ebp-0x074]
		Cmp Eax,Dword Ptr Ss:[Ebp-0x18C]
		Jl NEXT
		Mov Eax,MainTickCount
		Cmp SyncTickCount,Eax
		Jnz HACK
		Mov Ecx,Dword Ptr Ss:[Ebp-0x6C]
		Cmp CountModifier,Ecx
		Jnz HACK
		Mov Edx,Dword Ptr Ss:[Ebp-0x74]
		Cmp DelayModifier,Edx
		Jnz HACK
		Mov Ecx,Dword Ptr Ss:[Ebp-0x178]
		Cmp HasteModifier,Ecx
		Jnz HACK
		Mov Edx,Dword Ptr Ss:[Ebp-0x18C]
		Cmp SleepModifier,Edx
		Jnz HACK
		Mov Ecx,Dword Ptr Ds:[0x07BC4F04]
		Mov Edx,Dword Ptr Ds:[Ecx+0x214]
		Cmp SpeedModifier1,Edx
		Jnz HACK
		Mov Ecx,Dword Ptr Ds:[0x07BC4F04]
		Mov Edx,Dword Ptr Ds:[Ecx+0x218]
		Cmp SpeedModifier2,Edx
		Jnz HACK
		Mov Ecx,Dword Ptr Ds:[0x07BC4F04]
		Mov Edx,Dword Ptr Ds:[Ecx+0x31A]
		Cmp ModelModifier1,Edx
		Jnz HACK
		Mov Ecx,Dword Ptr Ds:[0x07BC4F04]
		Mov Edx,Dword Ptr Ds:[Ecx+0x394]
		Cmp ModelModifier2,Edx
		Jnz HACK
		Mov Ecx,Dword Ptr Ds:[0x07BC4F04]
		Mov Edx,Dword Ptr Ds:[Ecx+0x398]
		Cmp ModelModifier3,Edx
		Jnz HACK
		Add Eax,Dword Ptr Ss:[Ebp-0x18C]
		Mov MainTickCount,Eax
		
		// Set frame time to dynamic value instead of hardcoded 0x28
		Mov Ecx,FPS_Improved
		Mov Dword Ptr Ss:[Ebp-0x68],Ecx
		
		CONTINUE:
		Mov Ecx,Dword Ptr Ss:[Ebp-0x178]
		Add Ecx,Dword Ptr Ss:[Ebp-0x68]
		Mov Dword Ptr Ss:[Ebp-0x6C],Ecx
		Jmp [CheckTickCountAddress1]
		
		HACK:
		Push 0
		Call Dword Ptr Ds:[ExitProcess]
	}
}

void InitImprovedHackCheck()
{
	// Use the existing encryption setup from HackCheck
	WORD EncDecKey = 0;

	for(int n=0;n < sizeof(gProtect.m_MainInfo.CustomerName);n++)
	{
		EncDecKey += (BYTE)(gProtect.m_MainInfo.CustomerName[n]^gProtect.m_MainInfo.ClientSerial[(n%sizeof(gProtect.m_MainInfo.ClientSerial))]);
	}

	EncDecKey1 = (BYTE)0xF1;
	EncDecKey2 = (BYTE)0x1A;

	EncDecKey1 += LOBYTE(EncDecKey);
	EncDecKey2 += HIBYTE(EncDecKey);

	HookRecv = *(WSRECV*)(0x00D227B0);
	HookSend = *(WSSEND*)(0x00D227F8);

	SetDword(0x00D227B0,(DWORD)&MyRecv);
	SetDword(0x00D227F8,(DWORD)&MySend);
	
	// Set initial FPS limit from config
	SetDynamicFPSLimit(gProtect.m_MainInfo.LimitFPS);
}
