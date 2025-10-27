#include "stdafx.h"
#include "FPSManagerHook.h"
#include "AdvancedFPSManager.h"
#include "Util.h"

// Hook for main rendering loop
// This function is called EVERY frame, regardless of game state
// (login, character selection, gameplay, etc.)

static DWORD FPSManagerHookReturn = 0x004DA2AC + 5;

__declspec(naked) void FPSManagerHookFunction()
{
	_asm
	{
		// Save registers
		pushad
		pushfd
	}
	
	// Update FPS manager every frame
	gAdvancedFPSManager.Update();
	
	_asm
	{
		// Restore registers
		popfd
		popad
		
		// Execute original code that was replaced
		// (5 bytes at 0x004DA2AC)
		// Original instruction will be here
		
		// Jump back
		jmp [FPSManagerHookReturn]
	}
}

void InitFPSManagerHook()
{
	// Hook the main rendering call
	// This is called every frame in all game states
	SetCompleteHook(0xE9, 0x004DA2AC, &FPSManagerHookFunction);
}
