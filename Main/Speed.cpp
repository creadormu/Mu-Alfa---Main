#include "stdafx.h"
#include "Speed.h"
/*
void Attack_Value()
{
    CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(KillHackProtection),NULL,0,0); 
    //MessageBoxA(NULL, "Virtual memory Value changed!", "Hack Protection", MB_SERVICE_NOTIFICATION | MB_ICONSTOP); 
    ExitProcess(0);
}

bool Virt()
{
if	(
//---------------------------------------------------
	// Moving Speed FPS -> 100%
	(*(unsigned short*)0x004DA3E0 != 40) ||
//---------------------------------------------------
	// Moving Speed -> 100%
//	(*(unsigned short*)0x00564D30 != 3467) ||
//----------------------------------------------------
	// Speed V2 ->	100%
	(*(unsigned short*)0x004D9F02 != 37008) || 
//----------------------------------------------------
	// Hide Object -> 100%
	(*(unsigned short*)0x005DE2B3 != 34063) || 
//----------------------------------------------------
	// No Attack Delay 1 -> 100%
	(*(unsigned short*)0x0054539E != 11637) || 
//----------------------------------------------------
	// No Attack Delay 2 -> 100%
	(*(unsigned short*)0x00545248 != 11898) ||
//----------------------------------------------------
//---------------------------------------------------
	// Cooldown + AG Hack -> 100%
	(*(unsigned short*)5858560 != 35669) ||
//---------------------------------------------------
//---------------------------------------------------
	// Knock Back Resist -> 100%
	(*(unsigned short*)6555584 != 35669) ||
//---------------------------------------------------
//---------------------------------------------------
	// AntiReflect -> 100%
	(*(unsigned short*)5580960 != 35669) ||
//---------------------------------------------------
//---------------------------------------------------
	// Resist Bad Effect -> 100%
	(*(unsigned short*)5017344 != 35669) ||
//---------------------------------------------------
//---------------------------------------------------
	// Invisible DW Detection -> 100%
	(*(unsigned short*)7641648 != 65260) ||
//---------------------------------------------------
	(*(unsigned short*)0x00545248 != 11898) ||

	(*(unsigned short*)0x0056174C != 16582)
//---------------------------------------------------	
	)
{ 
		CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(KillHackProtection),NULL,0,0); 
		//MessageBoxA(NULL, "Virtual memory Value changed!", "Hack Protection", MB_SERVICE_NOTIFICATION | MB_ICONSTOP);
		ExitProcess(0);
		//TerminateProcess("Main.exe",0);
		//Attack_Value();
		//return true;	
	}
	else
	{
		return false;	
	}
}

void VirtA()
{	
again:
	Virt();
	Sleep (735);
    goto again;

}
	
void Virtual_Attack()
{
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(VirtA),NULL,0,0);
}
*/