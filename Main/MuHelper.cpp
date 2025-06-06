#include "stdafx.h"
#include "MuHelper.h"
#include "Import.h"
#include "PrintPlayer.h"
#include "Offset.h"
#include "Util.h"
#include "Protect.h"
#include "User.h"
#include "Defines.h"
#include "InfoLog.h"

cMuOffHelper gMuHelper;

void cMuOffHelper::Load()
{
	this->m_Disconnect = false;
}

void cMuOffHelper::RunningOffHelper()
{
	if( !*(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 0x08) )
	{
		return;
	}

	this->m_Disconnect = true;
	CG_OFFMODE_RESULT pRequest;
	pRequest.h.set((LPBYTE)&pRequest, 0xFB, 0x3D, sizeof(pRequest));
	//-- Range Attack
	pRequest.HuntingRange = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 172);
	//-- Auto Heling, Drain and Potion
	pRequest.RecoveryPotionOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 176);
	pRequest.RecoveryPotionPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 177);
	pRequest.RecoveryHealOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 178);
	pRequest.RecoveryHealPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 179);
	pRequest.RecoveryDrainOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 180);
	pRequest.RecoveryDrainPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 181);
	//-- Attack
	pRequest.DistanceLongOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 182);
	pRequest.DistanceReturnOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 183);
	pRequest.DistanceMin = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 184);
	pRequest.SkillBasicID = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 188);
	pRequest.ComboOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 240);
	//-- Party Settings
	pRequest.PartyModeOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 241);
	pRequest.PartyModeHealOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 242);
	pRequest.PartyModeHealPercent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 243);
	pRequest.PartyModeBuffOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 244);
	//-- AutoBuffo
	pRequest.BuffOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 260);
	pRequest.BuffSkill[0] = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 264);
	pRequest.BuffSkill[1] = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 268);
	pRequest.BuffSkill[2] = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 272);
	//-- PickObtain
	pRequest.ObtainRange = *(WORD*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 288);
	pRequest.ObtainRepairOn = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 292);
	pRequest.ObtainPickNear = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 293);
	pRequest.ObtainPickSelected = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 294);
	pRequest.ObtainPickMoney = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 297);
	pRequest.ObtainPickJewels = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 295);
	pRequest.ObtainPickExcellent = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 298);
	pRequest.ObtainPickAncient = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 296);
	pRequest.ObtainPickExtra = *(BYTE*)(*(DWORD*)(MAIN_HELPER_STRUCT) + 299);

	pRequest.ObtainPickExtraCount = 0;

	for(int i = 0 ; i < 12 ; i++)
	{
		ZeroMemory(pRequest.ObtainPickItemList[i], sizeof(pRequest.ObtainPickItemList[i]));
		wsprintf(pRequest.ObtainPickItemList[i], pGetItemList( i ));

		if(( strcmp(pGetItemList( i ), "" ) != 0 ))
		{
			pRequest.ObtainPickExtraCount++;
		}
	}

	DataSend((LPBYTE)&pRequest, pRequest.h.size);
}

__declspec(naked) void CheckHelperMana( )
{
	static DWORD main_addr;
	static DWORD SkillUsedMana;

	_asm
	{
		MOV EDX, DWORD PTR SS:[EBP-0xC]
		MOV SkillUsedMana, EDX
	}
	
	if( SkillUsedMana <= ViewCurMP )
		main_addr = 0x0095F9BD;
	else
		main_addr = 0x0095F9BF;

	_asm
	{
		JMP [main_addr]
	}
}

__declspec(naked) void CheckHelperBP( )
{
	static DWORD main_addr;
	static DWORD SkillUsedBP;

	_asm
	{
		MOV EDX, DWORD PTR SS:[EBP-0x4]
		MOV SkillUsedBP, EDX
	}


	if( SkillUsedBP <= ViewCurBP )
		main_addr = 0x0095F9F7;
	else
		main_addr = 0x0095F9F0;

	_asm
	{
		JMP [main_addr]
	}
}

__declspec(naked) void CheckAttckBP( )
{
	static DWORD main_addr;
	static DWORD SkillUsedBP;

	_asm
	{
		MOV EDX, DWORD PTR SS:[EBP-0x1C]
		MOV SkillUsedBP, EDX
	}

	if( SkillUsedBP > ViewCurBP )
		main_addr = 0x0059B9D2;
	else
		main_addr = 0x0059B9D9;

	_asm
	{
		JMP [main_addr]
	}
}

__declspec(naked) void CheckAutoPote( )
{
	static DWORD Pointer;
	static DWORD main_addr = 0x0095E1C4;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x1874]
		MOV Pointer,ECX
	}

	if ( *(BYTE *)(Pointer + 176) )
	{
		if ( ViewCurHP < ( ViewMaxHP * *(BYTE *)(Pointer + 177) / 100 )
		&& *(BYTE *)(*(DWORD *)(Pointer + 4) + 780) == 1
		&& ViewCurHP > 0 )
		{
			main_addr = 0x0095E1B9;
		}
	}

	_asm
	{
		JMP [main_addr]
	}
}

__declspec(naked) void CheckAutoHealing( )
{
	static DWORD Pointer;
	static DWORD main_addr = 0x0095E970;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x1874]
		MOV Pointer,ECX
	}

	if (!*(BYTE *)(Pointer + 178) 
		|| (pGetSkillPos(26) < 0 && pGetSkillPos(413) < 0) 
		|| (ViewCurHP >= (ViewMaxHP * *(BYTE *)(Pointer + 179) / 100) || 
		*(BYTE *)(*(DWORD *)(Pointer + 4) + 780) != 1|| ViewCurHP <= 0 || 
		!pHelperUseBuff((MUHelper*) Pointer, (ObjectPreview*) *(DWORD *)(Pointer + 4)))
		)
	{
		main_addr = 0x0095E2BA;
	}

	_asm
	{
		JMP [main_addr]
	}
}

void cMuOffHelper::LoadHelper()
{
	//--
	SetCompleteHook(0xE9, 0x0095E1AB, &CheckAutoPote);
	SetCompleteHook(0xE9, 0x0095E1C4, &CheckAutoHealing);
	//--
	SetCompleteHook(0xE9, 0x0095F9B0, &CheckHelperMana);
	//SetCompleteHook(0xE9, 0x0095F9E2, &CheckHelperBP);
	//SetCompleteHook(0xE9, 0x0059B9C4, &CheckAttckBP);
}