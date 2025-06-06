#include "stdafx.h"
#include "InterEx.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "PrintPlayer.h"
#include "Interface.h"
#include "Protect.h"
#include "Util.h"
#include "User.h"
#include "SItemOption.h"
#include "CustomPet.h"
#include "MiniMap.h"
#include "InfoLog.h"
#include "WindowsStruct.h"
#include "Common.h"
#include "NPCRuud.h"

CEx700 gCRenderEx700;

void CEx700::ClearMasterInfo()
{
	for(int i = 0; i < MAX_MASTER_SKILL_LIST; i++ )
	{
		this->m_MasterSkillInfo[i].skill = -1;
		this->m_MasterSkillInfo[i].RelatedSkill = -1;
	}
	this->MasterSkillCount = 0;
}

void CEx700::InsertMasterSkillInfo(PMSG_MASTER_SKILL_LIST * lpInfo)
{
	this->m_MasterSkillInfo[this->MasterSkillCount].skill = lpInfo->skill;
	this->m_MasterSkillInfo[this->MasterSkillCount].RelatedSkill = lpInfo->RelatedSkill;
	this->MasterSkillCount++;
}

void CEx700::RecvMasterSkill(PMSG_MASTER_SKILL_LIST_SEND * lpMsg)
{
	this->ClearMasterInfo();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_MASTER_SKILL_LIST * lpInfo = (PMSG_MASTER_SKILL_LIST*)(((BYTE*)lpMsg) + sizeof(PMSG_MASTER_SKILL_LIST_SEND) + (sizeof(PMSG_MASTER_SKILL_LIST) * n));
		this->InsertMasterSkillInfo(lpInfo);
	}
}

double CRenderNumberEx(float a1, float a2, int a3, float a4, DWORD ModelID)
{
	double result; // st7@2
	float v5; // ST44_4@5
	float v6; // ST38_4@5
	signed int i; // [sp+38h] [bp-30h]@3
	float v8; // [sp+3Ch] [bp-2Ch]@3
	signed int v9; // [sp+44h] [bp-24h]@3
	char v10[32]; // [sp+48h] [bp-20h]@3
	float v11; // [sp+70h] [bp+8h]@3

	EnableAlphaTest(1);
	glColor4f(50, 50, 50, 190);
				
	if ( a4 >= 0.300000011920929 )
	{
		v8 = (a4 - 0.4800000119209290) * 12.0;
		itoa(a3, v10, 10);
		v9 = strlen(v10);
		v11 = a1 - (double)v9 * v8 / 2.0;
		for ( i = 0; i < v9; ++i )
		{
			v6 = (double)(v10[i] - 48) * 12.0 / 128.0;
			v5 = (a4 - 0.400000011920929) * 16.0;
			RenderBitmap(ModelID, v11, a2, v8, v5, v6, 0.0, 0.09375, 0.875, 1, 1, 0.0);
			v11 = v8 * 0.800000011920929 + v11;
		}
		result = v11;
	}
	else
	{
		result = a1;
	}
	pGLSupremo();
	return result;
}

__declspec(naked) void RenderPointSkillMaster()
{
	static DWORD Addr_JMP = 0x0081AF3B;
	static DWORD Addr_Call1 = 0x009CEBF0;
	static DWORD Addr_Call2 = 0x0041FE10;
	static double x = 32.0;
	static double y = 18.0;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EDX,DWORD PTR SS:[EBP-0x128]
		PUSH EDX
		FLD DWORD PTR SS:[EBP-0x138]
		FADD QWORD PTR DS:[y]
		CALL Addr_Call1
		PUSH EAX
		FLD DWORD PTR SS:[EBP-0x12C]
		FADD QWORD PTR DS:[x]
		CALL Addr_Call1
		PUSH EAX
		CALL Addr_Call2
		MOV ECX, EAX                             ; |
		JMP[Addr_JMP]
	}
}

int CEx700::findMasterSkill(int Skill)
{
	for(int n = 0; n < this->MasterSkillCount; n++)
	{
//-- Blade Master
		//-- Skill Death Stab
		if( (Skill == MASTER_SKILL_ADD_DEATH_STAB_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DEATH_STAB_ENHANCED) 
			|| (Skill == MASTER_SKILL_ADD_DEATH_STAB_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DEATH_STAB_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Frozen Stab
		if( (Skill == MASTER_SKILL_ADD_FROZEN_STAB_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FROZEN_STAB_ENHANCED) 
			|| (Skill == MASTER_SKILL_ADD_FROZEN_STAB_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FROZEN_STAB_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Five Shot
		if( (Skill == MASTER_SKILL_ADD_FIVE_SHOT_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIVE_SHOT_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Greater Life
		if( (Skill == MASTER_SKILL_ADD_GREATER_LIFE_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_GREATER_LIFE_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
//-- Soul Master
		//-- Skill Mana Shield
		if( (Skill == MASTER_SKILL_ADD_MANA_SHIELD_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_MANA_SHIELD_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Ice Storm
		if( (Skill == 39 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_ICE_STORM_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_ICE_STORM_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_ICE_STORM_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Meteorite
		if( (Skill == 2 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_METEORITE_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_METEORITE_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_METEORITE_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
//-- Fist Master
		//-- Skill CHAIN_DRIVER
		if( (Skill == MASTER_SKILL_ADD_CHAIN_DRIVER_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_CHAIN_DRIVER_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill DARK_SIDE
		if( (Skill == MASTER_SKILL_ADD_DARK_SIDE_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DARK_SIDE_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill DRAGON_LORE
		if( (Skill == MASTER_SKILL_ADD_DRAGON_LORE_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DRAGON_LORE_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill DRAGON_SLAYER
		if( (Skill == 265 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DRAGON_SLAYER_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_DRAGON_SLAYER_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DRAGON_SLAYER_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		
		//-- Skill SWORD_SLASH
		if( (Skill == 236 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_SWORD_SLASH_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_SWORD_SLASH_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_SWORD_SLASH_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- FIRE_SLASH
		if((Skill == 55 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIRE_SLASH_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_FIRE_SLASH_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIRE_SLASH_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- LIGHTNING_STORM
		if( (Skill == 237 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_LIGHTNING_STORM_IMPROVED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == 65 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_ELECTRIC_SPARK_IMPROVED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == MASTER_SKILL_ADD_FIRE_SCREAM_IMPROVED && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIRE_SCREAM_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == 238 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_BIRDS_IMPROVED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == MASTER_SKILL_ADD_GREATER_CRITICAL_DAMAGE_MASTERED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_GREATER_CRITICAL_DAMAGE_EXTENDED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
	}

	return Skill;
}

void SkillView(int This, int Skill, float a6, float a7, float a8, float a9,int Type, float scaleX, float scaleY)
{
	signed int v8; // [sp+30h] [bp-4h]@1
	float v5; // ST24_4@2
	float v6; // ST20_4@2
	float v7; // ST18_4@2
	int v9; // edx@35
	int v10; // ecx@35
	signed int green; // ST28_4@35
	signed int blue; // ST2C_4@106
	float v13; // STE0_4@195
	float v14; // STFC_4@195
	float v15; // ST44_4@195
	float v16; // ST40_4@195
	float v17; // ST3C_4@196
	float v18; // ST38_4@196
	float y; // ST34_4@203
	float x; // ST30_4@203
	int v21; // [sp+8Ch] [bp-78h]@1
	signed int i; // [sp+90h] [bp-74h]@197
	signed int v23; // [sp+94h] [bp-70h]@152
	signed int v24; // [sp+98h] [bp-6Ch]@152
	signed int v25; // [sp+A0h] [bp-64h]@84
	signed int v26; // [sp+A4h] [bp-60h]@84
	signed int v27; // [sp+B0h] [bp-54h]@70
	signed int v28; // [sp+B4h] [bp-50h]@70
	signed int v29; // [sp+C4h] [bp-40h]@18
	signed int v30; // [sp+C8h] [bp-3Ch]@18
	unsigned __int16 v31; // [sp+CCh] [bp-38h]@1
	char v32; // [sp+D3h] [bp-31h]@2
	int v33; // [sp+D4h] [bp-30h]@174
	float v34; // [sp+DCh] [bp-28h]@115
	signed int v35; // [sp+E0h] [bp-24h]@35
	signed int v36; // [sp+E4h] [bp-20h]@2
	signed int v37; // [sp+ECh] [bp-18h]@115
	char v38; // [sp+F3h] [bp-11h]@2
	float v39; // [sp+F8h] [bp-Ch]@115
	signed int v40; // [sp+FCh] [bp-8h]@177
	signed int v41; // [sp+100h] [bp-4h]@197

	float RSkillX = (double) (( 256.0f / 100) * scaleX);
	float RSkillY = (double) (( 256.0f / 100) * scaleY);
	float MRSkillX = (double) (( 512.0f / 100) * scaleX);
	float MRSkillY = (double) (( 512.0f / 100) * scaleY);

	v31 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * Skill + 120);
	
	v31 = gCRenderEx700.findMasterSkill(v31);

	if ( v31 )
	{
		v32 = 0;
		v38 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v31 + 55);
		v36 = *(WORD *)(*(DWORD *)0x8128ABC + 88 * v31 + 72);
		if ( !sub_4AD0E0(v31) )
			v32 = 1;
		if ( !sub_5B89C0(v31) )
			v32 = 1;
		if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 19) && v38 == 2 )
			v32 = 1;
		if ( v31 == 47
			&& ((signed int)*(WORD *)(*(DWORD *)0x7BC4F04 + 556) < 7829 || (signed int)*(WORD *)(*(DWORD *)0x7BC4F04 + 556) > 7830)
			&& *(WORD *)(*(DWORD *)0x7BC4F04 + 556) != 7864 )
		{
			v32 = 1;
		}
		if ( v31 == 47 && (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v30 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
			v29 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
			if ( (v30 < 1536 || v30 >= 2048) && (v29 < 1536 || v29 >= 2048) )
			v32 = 1;
		}
		if ( (signed int)v31 >= 18 && (signed int)v31 <= 23 && (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v32 = 1;
		}
		if ( (v31 == 56 || v31 == 482)
			&& (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v32 = 1;
		}
		v9 = *(WORD *)(*(DWORD *)0x8128AC8 + 30);
		v10 = *(WORD *)(*(DWORD *)0x8128AC8 + 56);
		v35 = v10 + v9;
		green = v10 + v9;
		pUserStat();
		if ( sub_4E8D80(v31, green, 0) )
			v32 = 1;
		if ( v31 == 63 && *(DWORD *)0x81F6B6C <= 0 )
			v32 = 1;
		if ( v31 == 63 && (*(DWORD *)0xE61E18 == 65 || *(DWORD *)0xE61E18 == 66 || *(DWORD *)0xE61E18 == 67 || *(DWORD *)0xE61E18 == 68) )
			v32 = 1;
		if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512)
			&& (!*(BYTE *)(*(DWORD *)0x8128AC4 + 5550) 
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) != 7831 
			&& gCustomPet2.GetInfoPetType(*(WORD *)(*(DWORD *)0x7BC4F04 + 556) - 1171) != 6) )
		{
			v32 = 1;
		}

		if ( v31 == 77 || v31 == 233 || v31 == 380 || v31 == 383 || v31 == 441 )
		{
			pUserStat();
			if ( sub_4E8D80(v31, v35, 0) )
				v32 = 1;
			if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 6)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 143)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 82)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 138)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 139) )
			{
				v32 = 1;
			}
		}
		if ( v31 == 55 || v31 == 490 )
		{
			if ( (signed int)(unsigned __int16)(*(WORD *)(*(DWORD *)0x8128AC8 + 50) + *(WORD *)(*(DWORD *)0x8128AC8 + 24)) < 596 )
				v32 = 1;
			v28 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
			v27 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
			if ( v27 == -1 || v27 >= 2560 && v27 < 3072 || v28 >= 2560 && v28 < 3072 )
				v32 = 1;
		}
		if ( (v31 == 51 || v31 == 424) && (signed int)(unsigned __int16)(*(WORD *)(*(DWORD *)0x8128AC8 + 52) + *(WORD *)(*(DWORD *)0x8128AC8 + 26)) < 646 )
		{
			v32 = 1;
		}
		//-- Twisting Slash
		if ( v31 == 41 || v31 == 330 || v31 == 481 || v31 == 332 )
		{
			if(*(WORD *)(*(DWORD *)0x7BC4F04 + 448) < 1171 || *(WORD *)(*(DWORD *)0x7BC4F04 + 448) > 3072)
			{
				v32 = 1;
			}
		}
		if ( sub_4E65A0(*(DWORD *)0xE61E18) == 1 )
		{
			if ( v31 == 62
			|| v31 == 49
			|| v31 == 510
			|| v31 == 516
			|| (signed int)v31 >= 120 && (signed int)v31 <= 123
			|| v31 == 512 )
			{
				v32 = 1;
			}
		}
		else if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512) && !*(BYTE *)(*(DWORD *)0x8128AC4 + 5550) )
		{
			v32 = 1;
		}
		blue = *(WORD *)(*(DWORD *)0x8128AC8 + 62) + *(WORD *)(*(DWORD *)0x8128AC8 + 32);
		pUserStat();
		if ( sub_4E8D80(v31, v35, blue) )
			v32 = 1;
		if ( !sub_5111D0(v31) )
			v32 = 1;
		if ( sub_511110(v31, *(WORD *)(*(DWORD *)0x7BC4F04 + 556)) )
			v32 = 1;
		if ( sub_511290(
				*(WORD *)(*(DWORD *)0x8128AC4 + 5849),
				*(WORD *)(*(DWORD *)0x8128AC4 + 5742),
				*(DWORD *)(*(DWORD *)0x8128AC4 + 5851),
				*(DWORD *)(*(DWORD *)0x8128AC4 + 5744))
			&& pGetCharClass(*(BYTE *)(*(DWORD *)0x7BC4F04 + 19)) == 6 )
		{
			v32 = 1;
		}
		v34 = 0.0;
		v39 = 0.0;
		v37 = 0;
		pUserStat();
		if ( !sub_4EAC90( v31) )
			v32 = 1;
		pUserStat();
		if ( !sub_4EAC90( v31) )
			v32 = 1;
		if ( (signed int)v31 < 120 || (signed int)v31 > 124 )
		{
			if ( v31 == 76 )
			{
				v34 = a8 * 4.0 / RSkillX;
				v39 = 0.0;
				v37 = 1;
			}
			else if ( (signed int)v31 < 214 || (signed int)v31 > 217 )
			{
				if ( (signed int)v31 < 219 || (signed int)v31 > 220 )
				{
					if ( v31 == 218 )
					{
						v34 = a8 * 10.0 / RSkillX;
						v39 = a9 * 3.0 / RSkillY;
						v37 = 3;
					}
					else if ( (signed int)v31 < 221 || (signed int)v31 > 222 )
					{
						if ( (signed int)v31 < 223 || (signed int)v31 > 224 )
						{
							if ( v31 == 225 )
							{
								v34 = a8 * 11.0 / RSkillX;
								v39 = a9 * 3.0 / RSkillY;
								v37 = 3;
							}
							else if ( v31 == 232 )
							{
								v34 = a8 * 7.0 / RSkillX;
								v39 = a9 * 2.0 / RSkillY;
								v37 = 3;
							}
							else if ( v31 != 523 )
							{
								switch ( v31 )
								{
								case 0xEEu:
									v34 = a8 * 3.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xEAu:
									v34 = a8 * 9.0 / RSkillX;
									v39 = a9 * 2.0 / RSkillY;
									v37 = 3;
									break;
								case 0xEBu:
									if ( !sub_587A80() )
										v32 = 1;
									v34 = a8 * 0.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xECu:
									v24 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
									v23 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
									if ( v23 == -1 || v23 >= 2560 && v23 < 3072 || v24 >= 2560 && v24 < 3072 )
										v32 = 1;
									v34 = a8 * 1.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xEDu:
									v34 = a8 * 2.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xE6u:
									v34 = a8 * 2.0 / RSkillX;
									v39 = a9 * 3.0 / RSkillY;
									v37 = 3;
									break;
								case 0x1C8u:
									v34 = a8 * 6.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xE9u:
									v34 = a8 * 8.0 / RSkillX;
									v39 = a9 * 2.0 / RSkillY;
									v37 = 3;
									break;
								default:
									if ( v38 == 4 )
									{
										v34 = a8 / RSkillX * (double)(v36 % 12);
										v39 = a9 / RSkillY * (double)(v36 / 12 + 4);
										v37 = 3;
									}
									else if ( (signed int)v31 < 260 )
									{
										if ( (signed int)v31 < 57 )
										{
											v34 = (double)((v31 - 1) % 8) * a8 / RSkillX;
											v39 = (double)((v31 - 1) / 8) * a9 / RSkillY;
											v37 = 2;
										}
										else
										{
											v34 = (double)((v31 - 57) % 8) * a8 / RSkillX;
											v39 = (double)((v31 - 57) / 8) * a9 / RSkillY;
											v37 = 3;
										}
									}
									else
									{
										v34 = (double)((v31 - 260) % 12) * a8 / RSkillX;
										v39 = (double)((v31 - 260) / 12) * a9 / RSkillY;
										v37 = 4;
									}
									break;
								}
							}
						}
						else
						{
							v34 = (double)((v31 - 217) % 8) * a8 / RSkillX;
							v39 = a9 * 3.0 / RSkillY;
							v37 = 3;
						}
					}
					else
					{
						v34 = (double)(v31 - 213) * a8 / RSkillX;
						v39 = a9 * 3.0 / RSkillY;
						v37 = 3;
					}
				}
				else
				{
					v34 = (double)((v31 - 215) % 8) * a8 / RSkillX;
					v39 = a9 * 3.0 / RSkillY;
					v37 = 3;
				}
			}
			else
			{
				v34 = (double)((v31 - 214) % 8) * a8 / RSkillX;
				v39 = a9 * 3.0 / RSkillY;
				v37 = 3;
			}
		}
		else
		{
			v34 = (double)((v31 - 120) % 8) * a8 / RSkillX;
			v39 = (double)((v31 - 120) / 8) * a9 / RSkillY;
			( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) ) ? v32 = 0 : v32 = 1;
			v37 = 1;
		}
		
		v33 = *(DWORD *)0x8128ABC + 88 * v31;

		if ( v33 && *(BYTE *)(v33 + 55) == 4 )
			v37 = 5;

		v40 = 0;

		switch ( v37 )
		{
			case 1:
				v40 = 31310;
				if ( v32 == 1 )
					v40 = 31316;
			break;
			case 2:
				v40 = 31308;
				if ( v32 == 1 )
					v40 = 31314;
			break;
			case 3:
				v40 = 31309;
				if ( v32 == 1 )
					v40 = 31315;
			break;
			case 4:
				v40 = 31311;
				if ( v32 == 1 )
					v40 = 31317;
			break;
			case 5:
				v40 = 31534;
				if ( v32 == 1 )
					v40 = 31535;
			break;
			default:
			break;
		}
		if ( v40 )
		{
			if ( v33 && *(BYTE *)(v33 + 55) == 4 )
			{
				v13 = a8 / MRSkillX * (double)(*(WORD *)(v33 + 72) % 25);
				v14 = a9 / MRSkillY * (double)(*(WORD *)(v33 + 72) / 25);
				v16 = a8 / MRSkillX;
				v15 = a9 / MRSkillY;
				RenderBitmap(v40, a6, a7, Return2X(TransForX(a8)), ReturnY(TransForY(a9)), v13, v14, v16, v15, 1, 1, 0.0);
			}
			else
			{
				v17 = a9 / RSkillY;
				v18 = a8 / RSkillX;
				RenderBitmap(v40, a6, a7, Return2X(TransForX(a8)), ReturnY(TransForY(a9)), v34, v39, v18, v17, 1, 1, 0.0);
			}
		}

		if ( (v31 != 262 && v31 != 265 && v31 != 264 && v31 != 558 && v31 != 560 || !v32) 
			&& v31 != 77 && v31 != 233 && v31 != 380 && v31 != 383 && v31 != 441 )
		{
			v8 = *(DWORD *)(*(DWORD *)0x8128AC8 + 4 * Skill + 2072);
			if ( v8 > 0 )
			{
				v5 = (double)v8 / (double)*(signed int *)(*(DWORD *)0x8128ABC + 88 * *(WORD *)(*(DWORD *)0x8128AC8 + 2 * Skill + 120) + 44);
				EnableAlphaTest(1);
				glColor4f(1.0, 0.5, 0.5, 0.5);
				v6 = a9 * v5;
				v7 = a7 + a9 - v6;
				pDrawBarForm(a6, v7, Return2X(TransForX(a8)), ReturnY(TransForY(v6)), 0.0, 0);
				pGLSupremo();
			}
		}
	}
}

void Render_SkillTooltip(int x, int y, int nCount, int witd, int height,int type, int Align)
{
	tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
	int * ColorTexto = (int*)NewAddressData1;
	int * LineWeight = (int*)NewAddressData2;
	
	HDC hDC = GetDC(*(HWND*)(0x00E8C578));
	HGDIOBJ font = pFontNormal;
	//--
	SIZE psizl; // [sp+90h] [bp-1Ch]@1
	int counter1; // [sp+88h] [bp-24h]@1
	int counter2; // [sp+A8h] [bp-4h]@1
	float cRenderW; // [sp+8Ch] [bp-20h]@1
	float cRenderH; // [sp+98h] [bp-14h]@1
	float cRenderX; // [sp+A0h] [bp-Ch]@22
	float cRenderY; // [sp+9Ch] [bp-10h]@26
	float SaltoLine;
	//--
	float v64; // [sp+68h] [bp-44h]@53
	float v71; // [sp+84h] [bp-28h]@1
	float v76; // [sp+9Ch] [bp-10h]@26

	v71 = (( pCheckWindow(pWindowThis(), 57) == true ) ? 1.3 : 1.1 );
	//-- principal
	counter1 = 0;
	counter2 = 0;
	cRenderX = (double) (signed int) x;
	cRenderW = 0.0;
	cRenderH = 0.0;
	psizl.cx = 0;
	psizl.cy = 0;
	
	for(int n = 0; n < nCount; ++n)
	{
		if(!TooltipLine[n]) { nCount = n; break; }

		if( LineWeight[n] == 1 )
			font = pFontBold;
		else
			font = pFontNormal;

		SelectObject(hDC, font);
		
		GetTextExtentPoint32(hDC, TooltipLine[n], strlen(TooltipLine[n]), &psizl);

		if ( cRenderW < (double)(signed int)psizl.cx )
			cRenderW = (double)(signed int)psizl.cx;
		if (lstrlenA(TooltipLine[n]) < 2 )
			++counter2;
		else
			++counter1;
	}
	cRenderH = (double) ( counter1 * psizl.cy ) + (double) (signed int) psizl.cy / 2.0 * (double) counter2;
	
	cRenderH = (double) ( cRenderH / ( pWinHeightReal / v71 ));

	cRenderY = (double) (signed int) (( y + cRenderH > 420 ) ? 420 - cRenderH : y - 10 );

	pSetBlend(true);

	cRenderW = (double) (( witd > 0 ) ? ( (double)witd / pWinWidthReal + (double)witd / pWinWidthReal ) : ( ( cRenderW / pWinWidthReal ) + 4.0 ));

	cRenderX = (double) (cRenderX - cRenderW / 2.0 );

	cRenderX = (( cRenderX < 0 ) ? 1.0 : cRenderX);

	cRenderX = (((double) pWinWidth / pWinWidthReal < (double) cRenderX + cRenderW ) ? ((double) pWinWidth / pWinWidthReal - cRenderW - 1.0 ) : cRenderX );

	v76 = (double) (( type == 8 ) ? ( cRenderY - cRenderH) : cRenderY );

	SaltoLine = (double) (( type == 8 ) ? ( cRenderY - cRenderH) : cRenderY );

	if ( Align == 1 && nCount > 0 )
	{
		gCItemSetOption.ItemTooltipS15(cRenderX, cRenderY, cRenderW, cRenderH, 0.0, 0);
	}
	//-- Escritura
	for( int k = 0; k < nCount; ++k )
	{
		//-- Texto Principal
		if( LineWeight[k] )
			font = pFontBold;
		else
			font = pFontNormal;

		pSetFont(pTextThis(), (int)font);
		
		v64 = 0.0;
		if( ((DWORD) TooltipLine[k] != 10 && ( DWORD) TooltipLine[k] != 32 || (DWORD) TooltipLine[k] ) && lstrlenA(TooltipLine[k]) > 2 )
		{
			gCItemSetOption.RenderColor( ColorTexto[k] );

			pDrawText( pTextThis(), (double)(cRenderX + 1), v76, TooltipLine[k], ( cRenderW - 1.0f ), 0, (LPINT)height, 0 );
			
			SelectObject(hDC, font);
			GetTextExtentPoint32(hDC, TooltipLine[k], strlen(TooltipLine[k]), &psizl);
			v64 = (double)(signed int)psizl.cy / pWinHeightReal / 1.0;
		}
		else
		{
			SelectObject(hDC, font);
			GetTextExtentPoint32(hDC, TooltipLine[k], strlen(TooltipLine[k]), &psizl);

			if ( lstrlenA(TooltipLine[k]) > 2 )
				v64 = (double)(signed int)psizl.cy / pWinHeightReal / 1.0;
			else
				v64 = (double)(signed int)psizl.cy / pWinHeightReal / 2.0;
		}

		v76 = v64 * v71 + v76;
	}

	glColor4f(1.0, 1.0, 1.0, 1.0);
	pGLSwitch();
}

int ReturnSkillX(int number, int type)
{
	float xInterface = TransFor2X( 320 ) - TransForX( 320 / 2 );
	int x;

	switch(number)
	{
	case 1:
		x = Return2X(xInterface + TransForX( (type == 2) ? 11 : 2));
		break;
	case 2:
		x = Return2X(xInterface + TransForX( (type == 2) ? 42 : 33));
		break;
	case 3:
		x = Return2X(xInterface + TransForX( (type == 2) ? 74 : 65 ));
		break;
	case 4:
		x = Return2X(xInterface + TransForX( (type == 2) ? 105 : 96 ));
		break;
	case 5:
		x = Return2X(xInterface + TransForX( (type == 2) ? 137 : 128 ));
		break;
	case 6:
		x = Return2X(xInterface + TransForX( (type == 2) ? 168 : 159 ));
		break;
	case 7:
		x = Return2X(xInterface + TransForX( (type == 2) ? 199 : 190 ));
		break;
	case 8:
		x = Return2X(xInterface + TransForX( (type == 2) ? 231 : 222 ));
		break;
	case 9:
		x = Return2X(xInterface + TransForX( (type == 2) ? 263 : 254 ));
		break;
	case 10:
		x = Return2X(xInterface + TransForX( (type == 2) ? 295 : 286 ));
		break;
	}
	return x;
}

bool CEx700::SkillMouseOver(DWORD a1)
{
	bool result; // al@2
	unsigned __int8 v5; // ST4F_1@3
	int v62; // [sp+Ch] [bp-54h]@1
	int v64; // [sp+18h] [bp-48h]@84
	unsigned __int16 v66; // [sp+24h] [bp-3Ch]@53
	signed int v67; // [sp+2Ch] [bp-34h]@40
	signed int v68; // [sp+30h] [bp-30h]@40
	unsigned __int16 v69; // [sp+38h] [bp-28h]@76
	float v70; // [sp+40h] [bp-20h]@5
	float v71; // [sp+40h] [bp-20h]@28
	float v72; // [sp+40h] [bp-20h]@40
	float v73; // [sp+40h] [bp-20h]@73
	float v74; // [sp+40h] [bp-20h]@116
	float v75; // [sp+44h] [bp-1Ch]@5
	float v76; // [sp+44h] [bp-1Ch]@28
	float v77; // [sp+44h] [bp-1Ch]@73
	char v78; // [sp+4Bh] [bp-15h]@73
	float v79; // [sp+4Ch] [bp-14h]@73
	signed int v80; // [sp+50h] [bp-10h]@73
	int v81; // [sp+54h] [bp-Ch]@73
	float v82; // [sp+58h] [bp-8h]@5
	float v83; // [sp+58h] [bp-8h]@28
	float v84; // [sp+58h] [bp-8h]@40
	float v85; // [sp+58h] [bp-8h]@85
	float v86; // [sp+58h] [bp-8h]@116
	float v87; // [sp+5Ch] [bp-4h]@5
	float v88; // [sp+5Ch] [bp-4h]@28
	float v89; // [sp+5Ch] [bp-4h]@40
	float v90; // [sp+5Ch] [bp-4h]@73
	float v91; // [sp+5Ch] [bp-4h]@116*/
	signed int j; // [sp+10h] [bp-50h]@116
	signed int i; // [sp+20h] [bp-40h]@73

	float xInterface = TransFor2X( 320 ) - TransForX( 320 );

	float xSwitch = TransFor2X( 320 ) - TransForX( 320 / 2 );
	float ySwitch = TransForY( 480 ) - TransForY( 160 );
	int ContadorSkill = 0;

	float wSkillSelect = (double) 20;
	float hSkillSelect = (double) (( 28.0f / 100) * 89.2857);

	float Skill_Height = (double) (( 28.0f / 100) * 75);
	float Skill_Width = (double) (( 20.0f / 100) * 75);

	v62 = a1;
	if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 98) )
	{
		*(BYTE *)(v62 + 64) = 0;
		result = 1;
	}
	else
	{
		v5 = *(BYTE *)(*(DWORD *)0x8128AC8 + 118);
		*(BYTE *)(v62 + 65) = 0;
		if ( (signed int)v5 > 0 )
		{
			//308.0, 447.5, (double) (( 20.0f / 100) * 83.00001145), (double) (( 28.0f / 100) * 75)
			//-- skill en uso
			v82 = Return2X(xInterface + TransForX( 306 )); //-- x
			v87 = ReturnY(TransForY(444)); //-- y
			v70 = Return2X(TransForX(wSkillSelect)); //-- w
			v75 = ReturnY(TransForY(hSkillSelect)); //-- h

			if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
			{
				if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) )
				{
					if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 != 1 && *(BYTE *)0x8793380 != 1 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
					{
						if ( *(DWORD *)(v62 + 80) != 2 || *(BYTE *)0x8793384 || *(BYTE *)0x8793380 )
						{
							if ( *(DWORD *)(v62 + 80) == 1 )
							{
								*(BYTE *)(v62 + 65) = 1;
								*(DWORD *)(v62 + 68) = *(BYTE *)(*(DWORD *)0x7BC4F04 + 50);
								*(DWORD *)(v62 + 72) = v82 - 5.0;
								*(DWORD *)(v62 + 76) = v87;
								result = 0;
							}
							else if ( *(DWORD *)(v62 + 80) == 2 )
							{
								result = 0;
							}
							else
							{
								//-- DrawSkill Bar
								v83 = Return2X(xInterface + TransForX( 335 ));
								v88 = 445.5;
								v71 = Return2X(TransForX( Skill_Width )) + Return2X(xInterface + TransForX( 424 )) - Return2X(xInterface + TransForX( 335 ));
								v76 = ReturnY(TransForY(Skill_Height));
								if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
								{
									if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) )
									{
										if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 != 1 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
										{
										//-- DrawSkill Bar Slot 5
											v84 = 315.0;
											v89 = 445.5;
											v72 = Return2X(TransForX( Skill_Width ));
											v68 = 0;
											v67 = *(BYTE *)(v62 + 20) != 1 ? 1 : 6;
											while ( v68 < 5 )
											{
												v84 = v84 + v72;
												if ( v67 == 10 )
													v67 = 0;

												switch(v68)
												{
												case 0:
													v84 = Return2X(xInterface + TransForX( 335 ));
													break;
												case 1:
													v84 = Return2X(xInterface + TransForX( 357 ));
													break;
												case 2:
													v84 = Return2X(xInterface + TransForX( 381 ));
													break;
												case 3:
													v84 = Return2X(xInterface + TransForX( 402 ));
													break;
												case 4:
													v84 = Return2X(xInterface + TransForX( 424 ));
													break;
												}
												if ( pCheckMouseOver(v84, v89, v72, ReturnY(TransForY(Skill_Height))) == 1 )
												{
													if ( *(DWORD *)(v62 + 4 * v67 + 24) == -1 )
													{
														if ( *(DWORD *)(v62 + 80) == 3 )
														{
															*(BYTE *)(v62 + 65) = 0;
															*(DWORD *)(v62 + 68) = -1;
														}
														if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															*(DWORD *)(v62 + 80) = 0;
													}
													else
													{
														v66 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(DWORD *)(v62 + 4 * v67 + 24) + 120);
														if ( v66 && ((signed int)v66 < 67 || (signed int)v66 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v66 + 55) != 3 )
														{
															if ( *(DWORD *)(v62 + 80) == 3 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = *(DWORD *)(v62 + 4 * v67 + 24);
																*(DWORD *)(v62 + 72) = v84 - 5.0;
																*(DWORD *)(v62 + 76) = v89;
																return 1;
															}
															if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															{
																if ( *(DWORD *)(v62 + 68) == *(DWORD *)(v62 + 4 * v67 + 24) )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = *(BYTE *)(v62 + 4 * v67 + 24);
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
																*(DWORD *)(v62 + 80) = 0;
															}
														}
													}
												}
												++v68;
												++v67;
											}
											if ( *(DWORD *)(v62 + 80) == 4 )
											{
												//-- DrawSkill Bar
												if ( *(BYTE *)0x8793384 || pCheckMouseOver((int)330.0, (int)447.5, (int)100.0, (int)32.0))
												{
													result = 0;
												}
												else
												{
													*(DWORD *)(v62 + 80) = 0;
													result = 1;
												}
											}
											else if ( *(BYTE *)(v62 + 64) )
											{
												//-- SkillBarSwitch
												v80 = 0;
												v78 = 0;
												v90 = 370.0;//-- y
												v73 = 32.0;//-- w
												v77 = 38.0;//-- h
												v79 = 302.0;//-- x
												v81 = *(DWORD *)(v62 + 80);
												for ( i = 0; i < 150; ++i )
												{
													v69 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);
													if ( v69 && ((signed int)v69 < 67 || (signed int)v69 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v69 + 55) != 3 )
													{
														++v80;

					if( SkillPage == 1 && v80 > 20)
					{
						continue;
					}
					else if( SkillPage == 2 && v80 <= 20)
					{
						continue;
					}

					if( v80 <= 10 || v80 > 20  &&  v80 <= 30 )
					{
						ContadorSkill = ( v80 <= 10 ) ? v80 : v80 - 20;
						v90 = ReturnY(ySwitch );
					}
					else
					{
						ContadorSkill = ( v80 > 10 && v80 <= 20|| v80 > 30 ) ? v80 - 10 : v80 - 30;
						v90 = ReturnY(ySwitch + TransForY(39));
					}

					v85 = ReturnSkillX(ContadorSkill, 1);
														
														if ( pCheckMouseOver(v85, v90, Return2X(TransForX(v73)), ReturnY(TransForY(v77))) == 1 )
														{
															v78 = 1;
															if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
															{
																*(DWORD *)(v62 + 80) = 5;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(DWORD *)(v62 + 80) = 6;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && !*(BYTE *)0x8793384 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = i;
																*(DWORD *)(v62 + 72) = v85;
																*(DWORD *)(v62 + 76) = v90;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == i )
														{
															if ( pCheckMouseOver(v85, v90, Return2X(TransForX(v73)), ReturnY(TransForY(v77))) == 1 )
															{
																*(DWORD *)(v62 + 80) = 0;
																*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = i;
																*(BYTE *)(v62 + 64) = 0;
																PlayBuffer(25, 0, 0);
																return 0;
															}
														}
													}
												}
												if ( v81 == *(DWORD *)(v62 + 80) )
												{
													if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
													{
														//-- SkillFixRaven
														v86 = 270.0;
														v91 = 356.0;
														v74 = 32.0;
														float v1259;
														int contadorsito = 0;
														for ( j = 150; j < 154; ++j )
														{
															contadorsito++;
															v1259 = ReturnSkillX(contadorsito, 1);
															if ( pCheckMouseOver(v1259, v91, v74, (float)38.0) == 1 )
															{
																v78 = 1;
																if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
																{
																	*(DWORD *)(v62 + 80) = 5;
																	return 1;
																}
																if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
																{
																	*(DWORD *)(v62 + 80) = 6;
																	return 0;
																}
																if ( *(DWORD *)(v62 + 80) == 5 )
																{
																	*(BYTE *)(v62 + 65) = 1;
																	*(DWORD *)(v62 + 68) = j;
																	*(DWORD *)(v62 + 72) = v86;
																	*(DWORD *)(v62 + 76) = v91;
																}
																if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == j )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = j;
																	*(BYTE *)(v62 + 64) = 0;
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
															}
															v86 = v86 + v74;
														}
													}
													if ( v78 || *(DWORD *)(v62 + 80) != 5 )
													{
														if ( v78 || *(BYTE *)0x8793384 || *(DWORD *)(v62 + 80) != 6 )
														{
															if ( *(DWORD *)(v62 + 80) == 6 )
															{
																if ( *(BYTE *)0x8793384 )
																{
																	result = 0;
																}
																else
																{
																	*(DWORD *)(v62 + 80) = 0;
																	result = 1;
																}
															}
															else
															{
																result = 1;
															}
														}
														else
														{
															*(DWORD *)(v62 + 80) = 0;
															result = 0;
														}
													}
													else
													{
														*(DWORD *)(v62 + 80) = 0;
														result = 1;
													}
												}
												else
												{
													result = !*(DWORD *)(v62 + 80) || *(DWORD *)(v62 + 80) == 5;
												}
											}
											else
											{
												result = 1;
											}
										}
										else
										{
											*(DWORD *)(v62 + 80) = 4;
											result = 0;
										}
									}
									else
									{
										*(DWORD *)(v62 + 80) = 0;
										result = 1;
									}
								}
								else
								{
									*(DWORD *)(v62 + 80) = 3;
									result = 1;
								}
							}
						}
						else
						{
							if ( pCheckMouseOver(v82, v87, v70, v75) == 1 )
							{
								*(BYTE *)(v62 + 64) = *(BYTE *)(v62 + 64) == 0;
								PlayBuffer(25, 0, 0);
								*(DWORD *)(v62 + 80) = 0;
								result = 0;
							}
							else
							{
								*(DWORD *)(v62 + 80) = 0;
								result = 1;
							}
						}
					}
					else
					{
						*(DWORD *)(v62 + 80) = 2;
						result = 0;
					}
				}
				else
				{
					*(DWORD *)(v62 + 80) = 0;
					result = 1;
				}
			}
			else
			{
				*(DWORD *)(v62 + 80) = 1;
				result = 1;
			}
		}
		else
		{
			result = 1;
		}
	}
	return result;
}

void CEx700::SkillRavenSwitchBar(DWORD * a1)
{
	float v4; // ST18_4@7
	float v5; // ST14_4@7
	int v6; // [sp+18h] [bp-18h]@1
	signed int i; // [sp+1Ch] [bp-14h]@2
	float v8; // [sp+20h] [bp-10h]@2
	float v9; // [sp+24h] [bp-Ch]@2
	float v10; // [sp+28h] [bp-8h]@2
	float v11; // [sp+2Ch] [bp-4h]@2
	float Height = (double) (( 28.0f / 100) * 75);
	float Width = (double) (( 20.0f / 100) * 75);

	v6 = *(DWORD *)a1;
	if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
	{
		v10 = 270.0;
		v11 = 356.0;
		v8 = 32.0;
		v9 = 38.0;

		int contador = 0;

		for ( i = 150; i < 154; ++i )
		{
			//if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )
			//	pDrawGUI(31313, v10, v11, v8, v9);
			//else
			//	pDrawGUI(31312, v10, v11, v8, v9);

			v4 = v11 + 9.0;
			contador++;
			v5 = ReturnSkillX(contador, 2);
			//v5 = v10 + 8.0;

			for (int k = 0; k < 10; ++k )
			{
				if ( *(DWORD *)(a1 + 4 * k + 24) == i )
				{
					CRenderNumberEx(v5 + Return2X(TransForX(Width)), v4 + ReturnY(TransForY(Height- 5)), k, 1.00, 31337);
					break;
				}
			}

			SkillView(*(DWORD*)a1, i, v5, v4, (double) (( 20.0f / 100) * 83.00001145), (double) (( 28.0f / 100) * 75), 2, 83.00001145, 75);
		}
	}
}

void Render_772EA0(int ThisR)
{
	static DWORD Addr1 = 0x00815040;
	static DWORD Addr2_Call = 0x00772EA0;
	static DWORD This = 0x00772EA0;

	This = ThisR;

	_asm
	{
		PUSH 0                              ; /Arg5 = 00000000
		PUSH 0                              ; |Arg4 = 00000000
		MOV ECX,This                        ; |
		PUSH ECX                            ; |Arg3
		PUSH Addr1                          ; |Arg2 = 00815040
		PUSH ECX                            ; |Arg1
		FLD DWORD PTR DS:[0xD2CA40]         ; |
		FSTP DWORD PTR SS:[ESP]             ; |
		MOV EDX,This                        ; |
		MOV ECX,DWORD PTR DS:[EDX + 0x10]   ; |
		CALL Addr2_Call                     ; \main1.00772EA0
	}
}

char CEx700::SkillSwitchBar(int This)
{
	float v4; // ST18_4@26
	float v5; // ST14_4@26
	int v7; // [sp+28h] [bp-34h]@1
	int v8; // [sp+30h] [bp-2Ch]@15
	char v9; // [sp+37h] [bp-25h]@9
	float v10; // [sp+38h] [bp-24h]@3
	signed int v11; // [sp+3Ch] [bp-20h]@3
	signed int v12; // [sp+40h] [bp-1Ch]@6
	float v13; // [sp+44h] [bp-18h]@3
	float v14; // [sp+48h] [bp-14h]@3
	signed int i; // [sp+50h] [bp-Ch]@3
	float v16; // [sp+54h] [bp-8h]@16
	float v17; // [sp+58h] [bp-4h]@3
	float Height = (double) (( 28.0f / 100) * 75);
	float Width = (double) (( 20.0f / 100) * 75);

	float xInterface = TransFor2X( 320 ) - TransForX( 320 / 2 );
	float yInterface = TransForY( 480 ) - TransForY( 160 );

	v7 = This;
	int ContadorSkill;

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	if ( (signed int)*(BYTE *)(*(DWORD *)0x8128AC8 + 118) > 0 && *(BYTE *)(v7 + 64) == 1 )
	{
		OpenSwicthSkill = 1;
		RenderBitmap(61546, xInterface, yInterface, TransForX( 320 ), TransForY( 76 ), 0.0, 0.0, 1.0, 1.0, 0, 0, 0);

		v17 = 370.0;
		v13 = 32.0;
		v14 = 38.0;
		v10 = 302.0;
		v11 = 0;

		for ( i = 0; i < 150; ++i )
		{
			v12 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);

			if ( *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120) && (v12 < 67 || v12 > 72) )
			{
				v9 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v12 + 55);
				
				if ( v9 != 1 && v9 != 3 )
				{
					++v11;

					if( SkillPage == 1 && v11 > 20)
					{
						continue;
					}
					else if( SkillPage == 2 && v11 <= 20)
					{
						continue;
					}

					if( v11 <= 10 || v11 > 20  &&  v11 <= 30 )
					{
						ContadorSkill = ( v11 <= 10 ) ? v11 : v11 - 20;
						v4 = ReturnY(yInterface + TransForY(10));
					}
					else
					{
						ContadorSkill = ( v11 > 10 && v11 <= 20|| v11 > 30 ) ? v11 - 10 : v11 - 30;
						v4 = ReturnY(yInterface + TransForY(47));
					}

					v5 = ReturnSkillX(ContadorSkill, 2);
					
					SkillView(This, i, v5, v4, (double) (( 20.0f / 100) * 83.00001145), (double) (( 28.0f / 100) * 75), 2, 83.00001145, 75);

					for (int k = 0; k < 10; ++k )
					{
						if ( *(DWORD *)(This + 4 * k + 24) == i )
						{
							CRenderNumberEx(v5 + Return2X(TransForX(Width)), v4 + ReturnY(TransForY(Height- 5)), k, 1.00, 31337);
							break;
						}
					}
				}
			}
		}
		this->SkillRavenSwitchBar((DWORD *)This);
	}
	else
	{
		OpenSwicthSkill = 0;
	}

	if(OpenSwicthSkill == 1)
	{
		RenderBitmap(61547, xInterface + TransForX( 323 ), yInterface + TransForY( 17 ), TransForX( 17 ), TransForY( 42 ), 0.0, 0.0, 0.2399999946, 1.0, 0, 0, 0);
		
		if(v11 > 20)
		{
			//-- Boton Arriba
			if(CheckButtonPressed(Return2X(xInterface + TransForX( 325 )), ReturnY(yInterface + TransForY( 19 )), Return2X(TransForX( 13 )), ReturnY(TransForY( 13 ))))
			{
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 19 ), TransForX( 13 ), TransForY( 13 ), 0.3870000243, 0.4429999888, 0.1380000114, 0.2490001172, 0, 0, 0);
				PlayBuffer(25, 0, 0);
			}
			else
			{
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 19 ), TransForX( 13 ), TransForY( 13 ), 0.3870000243, 0.7100000381, 0.1380000114, 0.2490001172, 0, 0, 0);
			}
			//-- Boton Abajo
			if(CheckButtonPressed(Return2X(xInterface + TransForX( 325 )), ReturnY(yInterface + TransForY( 43 )), Return2X(TransForX( 13 )), ReturnY(TransForY( 13 ))))
			{
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 43 ), TransForX( 13 ), TransForY( 13 ), 0.2470000237, 0.4429999888, 0.1380000114, 0.2490001172, 0, 0, 0);
				PlayBuffer(25, 0, 0);
			}
			else
			{
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 43 ), TransForX( 13 ), TransForY( 13 ), 0.2470000237, 0.7100000381, 0.1380000114, 0.2490001172, 0, 0, 0);
			}
		}
		else
		{
			//-- Arriba
			RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 19 ), TransForX( 13 ), TransForY( 13 ), 0.3870000243, 0.1729999632, 0.1380000114, 0.2490001172, 0, 0, 0);
			//-- Abajo
			RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 43 ), TransForX( 13 ), TransForY( 13 ), 0.2470000237, 0.1729999632, 0.1380000114, 0.2490001172, 0, 0, 0);
		}
	}

	if ( *(BYTE *)(This + 65) == 1 && *(DWORD *)(This + 16) )
	{
		Render_772EA0( This );
		*(BYTE *)(This + 65) = 0;
	}

	pGLSwitch();
	EnableAlphaTest(0);

	return 1;
}

void sub_813740(int This)
{
	float v4; // ST18_4@17
	float v5; // ST14_4@17
	int v6; // [sp+18h] [bp-34h]@1
	int v7; // [sp+20h] [bp-2Ch]@13
	int v8; // [sp+24h] [bp-28h]@7
	int v9; // [sp+2Ch] [bp-20h]@18
	signed int v10; // [sp+30h] [bp-1Ch]@2
	float w; // [sp+34h] [bp-18h]@4
	signed int i; // [sp+40h] [bp-Ch]@4
	float x; // [sp+44h] [bp-8h]@4
	float y; // [sp+48h] [bp-4h]@4

	int TypeSlot = gProtect.m_MainInfo.CustomInterfaceType;

	float xInterface = TransFor2X( 320 ) - TransForX( 320 );

	float wSkillSelect = (double) (TypeSlot == 4) ? (( 20.0f / 100) * 112.5) : 20 ;
	float hSkillSelect = (double) (TypeSlot == 4) ? (( 28.0f / 100) * 99.99998639285714) : 25;

	float Skill_Height = (double) (TypeSlot == 4) ? (( 28.0f / 100) *  89.28571428571429) : 21;
	float Skill_Width = (double) (TypeSlot == 4) ? (( 20.0f / 100) * 90) : 15;

	v6 = This;

	if ( (signed int)*(BYTE *)(oUserObjectStruct + 118) > 0 )
	{
		v10 = 1;
		if ( *(BYTE *)(This + 20) )
			v10 = 6;
		y = 441.0;
		w = 20.0;

		for ( i = 0; i < 5; ++i )
		{
			v8 = i + v10;
			if ( i + v10 == 10 )
				v8 = 0;
			switch( i )
			{
			case 0:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 333.2999878 : 335));
				break;
			case 1:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 355.6000061 : 357));
				break;
			case 2:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 379 : 381));
				break;
			case 3:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 400.5 : 402));
				break;
			case 4:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 422.5 : 424));
				break;
			}

			/*if(*(DWORD *)(v6 + 4 * v8 + 24) > 150 && *(DWORD *)(v6 + 4 * v8 + 24) <= 154 && *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) == 0)
			{
				continue;
			}*/

			if ( *(DWORD *)(v6 + 4 * v8 + 24) != -1 && (*(DWORD *)(v6 + 4 * v8 + 24) < 120 || *(DWORD *)(v6 + 4 * v8 + 24) >= 124 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 676)) )
			{
				v7 = *(DWORD *)0x8128ABC + 88 * *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(DWORD *)(v6 + 4 * v8 + 24) + 120);
				
				if ( !v7 || *(BYTE *)(v7 + 55) != 3 )
				{
					SkillView(This, *(DWORD *)(v6 + 4 * v8 + 24), x, (TypeSlot == 4) ? 442.2999878: y + 4.5, Skill_Width, Skill_Height, 1, (TypeSlot == 4) ? 90 : 75, (TypeSlot == 4) ? 89.28571428571429 : 75);

					if ( *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) == *(DWORD *)(v6 + 4 * v8 + 24) )
					{
						RenderBitmap(51500, x - Return2X(TransForX( 6 )), y - 2.5, Return2X(TransForX(28)), ReturnY(TransForY(58)), 0, 0, 1.0, 1.0, 1, 1, 0.0); //-- Slot en Uso
					}
				}
			}
			CRenderNumberEx(x + 6, y - 1.5, v8, 1.02,6829);
		}

		v9 = *(DWORD *)0x8128ABC + 88 * *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);

		if ( v9 && *(BYTE *)(v9 + 55) != 3 )
		{
				SkillView(This, *(BYTE *)(*(DWORD *)0x7BC4F04 + 50), 
					Return2X(xInterface + TransForX((TypeSlot == 4) ? 305.35 : 306 )), 
					(TypeSlot == 4) ? 440.5 : 444, wSkillSelect, hSkillSelect, 0, (TypeSlot == 4) ? 112.5 : 100, (TypeSlot == 4) ? 99.99998639285714 : 89.2857); //-- Slot en Uso
		}
	}
}

__declspec(naked) void CEx700::SkillSelectBar()
{
	static DWORD This;
	static DWORD Addr_JMP = 0x00813968;

	_asm
	{
		MOV DWORD PTR SS:[EBP-0x34],ECX
		MOV EDX, DWORD PTR SS:[EBP-0x34]
		MOV This, EDX
	}

	sub_813740(This);
	
	_asm
	{
		JMP[Addr_JMP]
	}
}

void RenderSands(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
{
	if (World == 8)//Tarkan
	{
		if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
	if (World == 34)//LaCleon
	{
		if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
	if (World == 56)//LaCleon
	{
		if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
	if (World == 57)//LaCleon
	{
		if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
}

bool MouseClickRender(int a1, int a2, int a3, int a4)
{
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		int Width = TransForX( 190 );

		if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
			|| gInterface.CheckWindow(8)
			|| gInterface.CheckWindow(12)
			|| gInterface.CheckWindow(9)
			|| gInterface.CheckWindow(7)
			|| gInterface.CheckWindow(14)
			|| gInterface.CheckWindow(15)
			|| gInterface.CheckWindow(60)
			|| gInterface.CheckWindow(76) )
		{
			a3 = Return2X(TransFor2X(640) - (Width * 2));
		}
		else
		{
			if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
			{
				a3 = Return2X(TransFor2X(640) - (Width*2));
			}
			else
			{
				if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
				{
					a3 = Return2X(TransFor2X(640) - (Width*2));
				}
				else
				{
					if ( gInterface.CheckWindow(27) )
					{
						a3 = Return2X(TransFor2X(640) - (Width*2));
					}
					else
					{
						if ( gInterface.CheckWindow(13)
						|| gInterface.CheckWindow(16)
						|| gInterface.CheckWindow(3)
						|| gInterface.CheckWindow(21)
						|| gInterface.CheckWindow(6)
						|| gInterface.CheckWindow(22)
						|| gInterface.CheckWindow(23)
						|| gInterface.CheckWindow(24)
						|| gInterface.CheckWindow(4)
						|| gInterface.CheckWindow(18)
						|| gInterface.CheckWindow(10)
						|| gInterface.CheckWindow(5)
						|| gInterface.CheckWindow(25)
						|| gInterface.CheckWindow(26)
						|| gInterface.CheckWindow(19)
						|| gInterface.CheckWindow(20)
						|| gInterface.CheckWindow(58)
						|| gInterface.CheckWindow(59)
						|| gInterface.CheckWindow(62)
						|| gInterface.CheckWindow(73)
						|| gInterface.CheckWindow(68)
						|| gInterface.CheckWindow(69)
						|| gInterface.CheckWindow(70)
						|| gInterface.CheckWindow(66)
						|| gInterface.CheckWindow(75)
						|| gInterface.CheckWindow(74) )
						{
							a3 = Return2X(TransFor2X(640) - Width);
						}
						else
						{
							if ( gInterface.CheckWindow(79) )
							{
								if ( gInterface.CheckWindow(80) )
								{
									a3 = Return2X(TransFor2X(640) - (Width*2));
								}
								else
								{
									a3 = Return2X(TransFor2X(640) - Width);
								}	
							}
							else
							{
								a3 = Return2X(TransFor2X(640));
							}
						}
					}
				}
			}
		}
  
		if ( gInterface.CheckWindow(77) )
		{
			if ( gInterface.CheckWindow(Warehouse) ||
				gInterface.CheckWindow(ChaosBox) ||
				gInterface.CheckWindow(Store) ||
				gInterface.CheckWindow(OtherStore) ||
				gInterface.CheckWindow(Character))
			{
				a3 = Return2X(TransFor2X(640) - (Width * 3));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
		}
		else if ( gInterface.CheckWindow(78) )
		{
				a3 = Return2X(TransFor2X(640) - (Width * 3));
		}

		if ( gInterface.CheckWindow( Shop ) )
		{
			int t = Return2X( Width );

			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			return pCursorX > t && pCursorX < a3 && pCursorY < a4;
		}
		else if ( gInterface.CheckWindow(Warehouse) )
		{
			int t = Return2X( Width );

			if( gInterface.CheckWindow(ExpandWarehouse) )
			{
				t = Return2X( Width * 2 );
			}
			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			return pCursorX > t && pCursorX < a3 && pCursorY < a4;
		}
		else
		{
			return pCursorX < a3 && pCursorY < a4;
		}
	}
	else
	{
		if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(8)
		|| gInterface.CheckWindow(12)
		|| gInterface.CheckWindow(9)
		|| gInterface.CheckWindow(7)
		|| gInterface.CheckWindow(14)
		|| gInterface.CheckWindow(15)
		|| gInterface.CheckWindow(60)
		|| gInterface.CheckWindow(76) )
		{
			a3 = 260;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
			{
				a3 = 260;
			}
			else
			{
				if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
				{
					a3 = 260;
				}
				else
				{
					if ( gInterface.CheckWindow(27) )
					{
						a3 = 260;
					}
					else
					{
						if ( gInterface.CheckWindow(13)
						|| gInterface.CheckWindow(16)
						|| gInterface.CheckWindow(3)
						|| gInterface.CheckWindow(21)
						|| gInterface.CheckWindow(6)
						|| gInterface.CheckWindow(22)
						|| gInterface.CheckWindow(23)
						|| gInterface.CheckWindow(24)
						|| gInterface.CheckWindow(4)
						|| gInterface.CheckWindow(18)
						|| gInterface.CheckWindow(10)
						|| gInterface.CheckWindow(5)
						|| gInterface.CheckWindow(25)
						|| gInterface.CheckWindow(26)
						|| gInterface.CheckWindow(19)
						|| gInterface.CheckWindow(20)
						|| gInterface.CheckWindow(58)
						|| gInterface.CheckWindow(59)
						|| gInterface.CheckWindow(62)
						|| gInterface.CheckWindow(73)
						|| gInterface.CheckWindow(68)
						|| gInterface.CheckWindow(69)
						|| gInterface.CheckWindow(70)
						|| gInterface.CheckWindow(66)
						|| gInterface.CheckWindow(75)
						|| gInterface.CheckWindow(74) )
						{
							a3 = 450;
						}
						else
						{
							if ( gInterface.CheckWindow(79) )
							{
								if ( gInterface.CheckWindow(80) )
								{
									a3 = 260;
								}
								else
								{
									a3 = 450;
								}	
							}
							else
							{
								a3 = 640;
							}
						}
					}
				}
			}
		}
  
		if ( gInterface.CheckWindow(77) )
		{
			if ( gInterface.CheckWindow(Warehouse) ||
				gInterface.CheckWindow(ChaosBox) ||
				gInterface.CheckWindow(Store) ||
				gInterface.CheckWindow(OtherStore) ||
				gInterface.CheckWindow(Character))
			{
				a3 = 70;
			}
			else
			{
				a3 = 260;
			}
		}
		else if ( gInterface.CheckWindow(78) )
		{
				a3 = 70;
		}
		//-----------------------
		return pCursorX < a3 && pCursorY < a4;
	}
}

__declspec(naked) void PartyWindowsMove()
{
	static DWORD PartyWindows_Buff = 0x0084B965;
	static DWORD X;
if (gProtect.m_MainInfo.CustomInterfaceType== 3)
	{
		X = 79;//<<Cord Base

		if (gInterface.CheckWindow(13) && gInterface.CheckWindow(8)
			|| gInterface.CheckWindow(12)
			|| gInterface.CheckWindow(9)
			|| gInterface.CheckWindow(7)
			|| gInterface.CheckWindow(14)
			|| gInterface.CheckWindow(15)
			|| gInterface.CheckWindow(60)
			|| gInterface.CheckWindow(76))
		{
			X = 459;
		}
		else
		{
			if (gInterface.CheckWindow(27))
			{
				X = 459;
			}
			else
			{
				if (gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74))
				{
					X = 269;
				}
				else
				{
					if (gInterface.CheckWindow(79))
					{
						if (gInterface.CheckWindow(80))
						{
							X = 459;
						}
						else
						{
							X = 269;
						}
					}
				}
			}
		}

		if (gInterface.CheckWindow(77))
		{
			if (gInterface.CheckWindow(Warehouse) ||
				gInterface.CheckWindow(ChaosBox) ||
				gInterface.CheckWindow(Store) ||
				gInterface.CheckWindow(OtherStore))
			{

			}
			else
			{
				X = 459;
			}
		}
		else if (gInterface.CheckWindow(78))
		{
			X = 459;
		}

		_asm
		{
			MOV EDX, DWORD PTR SS : [EBP + 0x8]; |
				SUB EDX, X; |
				PUSH EDX; | Arg1
				JMP PartyWindows_Buff; |
		}
	}

else if (gProtect.m_MainInfo.CustomInterfaceType== 4)
	{
			X = 79;//<<Cord Base

		   if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
			|| gInterface.CheckWindow(8)
			|| gInterface.CheckWindow(12)
			|| gInterface.CheckWindow(9)
			|| gInterface.CheckWindow(7)
			|| gInterface.CheckWindow(14)
			|| gInterface.CheckWindow(15)
			|| gInterface.CheckWindow(60)
			|| gInterface.CheckWindow(76) )
			{
				X = 459;
			}
			else
			{
				if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
				{
					X = 459;
				}
				else
				{
					if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
					{
						X = 459;
					}
					else
					{
						if ( gInterface.CheckWindow(27) )
						{
							X = 459;
						}
						else
						{
							if ( gInterface.CheckWindow(13)
							|| gInterface.CheckWindow(16)
							|| gInterface.CheckWindow(3)
							|| gInterface.CheckWindow(21)
							|| gInterface.CheckWindow(6)
							|| gInterface.CheckWindow(22)
							|| gInterface.CheckWindow(23)
							|| gInterface.CheckWindow(24)
							|| gInterface.CheckWindow(4)
							|| gInterface.CheckWindow(18)
							|| gInterface.CheckWindow(10)
							|| gInterface.CheckWindow(5)
							|| gInterface.CheckWindow(25)
							|| gInterface.CheckWindow(26)
							|| gInterface.CheckWindow(19)
							|| gInterface.CheckWindow(20)
							|| gInterface.CheckWindow(58)
							|| gInterface.CheckWindow(59)
							|| gInterface.CheckWindow(62)
							|| gInterface.CheckWindow(73)
							|| gInterface.CheckWindow(68)
							|| gInterface.CheckWindow(69)
							|| gInterface.CheckWindow(70)
							|| gInterface.CheckWindow(66)
							|| gInterface.CheckWindow(75)
							|| gInterface.CheckWindow(74) )
							{
								X = 269;
							}
							else
							{
								if ( gInterface.CheckWindow(79) )
								{
									if ( gInterface.CheckWindow(80) )
									{
										X = 459;
									}
									else
									{
										X = 269;
									}	
								}
							}
						}
					}
				}
			}
  
			if ( gInterface.CheckWindow(77) )
			{
				if ( gInterface.CheckWindow(Warehouse) ||
					gInterface.CheckWindow(ChaosBox) ||
					gInterface.CheckWindow(Store) ||
					gInterface.CheckWindow(OtherStore) ||
					gInterface.CheckWindow(Character))
				{
			
				}
				else
				{
					X = 459;
				}
			}
			else if ( gInterface.CheckWindow(78) )
			{
					X = 459;
			}

			_asm
			{
				MOV EDX,DWORD PTR SS:[EBP+0x8]           ; |
				SUB EDX, X                                ; |
				PUSH EDX                                 ; |Arg1
				JMP PartyWindows_Buff                    ; |
			}
	}
}



void RenderMasterSkill(DWORD a1, float x, float y, float w, float h)
{
	pDrawGUI(a1, x, y, w, 428);
}

void RenderBarExp(int ImageID, float PosX, float PosY, float Width, float Height, float CurrentMoveX, float CurrentMoveY, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)
{
	float xInterface = TransFor2X( 640 / 2 ) - TransForX( 640 ) / 2;
	float RenderW = TransForX((Width / 629.0f) * 518.125f);

	RenderBitmap(ImageID, Return2X(xInterface + TransForX(60)), ReturnY(TransForY(474)), Return2X(RenderW), ReturnY(TransForY(Height)), CurrentMoveX, CurrentMoveY, ScaleX, ScaleY, ScaleSize, ScalePosition, ScaleAlpha);
}

void RenderBar2Exp(int ImageID, float PosX, float PosY, float Width, float Height, float CurrentMoveX, float CurrentMoveY, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)
{
	float xInterface = TransFor2X( 640 / 2 ) - TransForX( 640 ) / 2;
	float RenderW = TransForX((Width / 629.0f) * 518.125f);

	RenderBitmap(ImageID, (PosX == 2.0f) ? Return2X(xInterface + TransForX(60)) : Return2X(TransForX((((( PosX - 2.0f ) / 629.0) * 518.125f) + 85.0f))), ReturnY(TransForY(474)),
		Return2X(RenderW), ReturnY(TransForY(Height)), CurrentMoveX, CurrentMoveY, ScaleX, ScaleY, ScaleSize, ScalePosition, ScaleAlpha);
}

void RenderBarExpAdd(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	float xInterface = TransFor2X( 640 / 2 ) - TransForX( 640 ) / 2;
	float RenderW = Return2X(TransForX((Width / 629.0f) * 518.125f));

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 0.70000002);
	pDrawBarForm((PosX == 2.0f) ? Return2X(xInterface + TransForX(60)) : Return2X(TransForX((((( PosX - 2.0f ) / 629.0) * 518.125f) + 85.0f))),
		ReturnY(TransForY(474)), RenderW, ReturnY(TransForY(Height)), Arg5, Arg6);
	pGLSupremo();
}

void RenderNumberExp(float a4, float a5, int Number, float a7)
{
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	float xInterface = TransFor2X( 640 / 2 ) - TransForX( 640 ) / 2;

	if(gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		RenderBitmap(59000, xInterface, TransForY( 480 ) - TransForY( 73 ), TransForX( 640 ), TransForY( 73 ), 0.0, 0.0, 0.9129598141, 0.8629598618, 0, 0, 0.0);
	}

	CRenderNumberEx(Return2X(xInterface + TransForX(604.375)), ReturnY(TransForY(470)), Number, 0.96, 31337);

	pGLSwitch();
	EnableAlphaTest(0);
}

void RenderSkillMasterBox(DWORD ModelID, float x, float y, float Width, float Height, float arg1, float arg2, DWORD ScaleAlpha)
{
	RenderBitMapColored(ModelID, x + 4.5, y + 3, 37.5, 28.5, 0.0, 0.0, 0.7506249547, 0.5771092772, ScaleAlpha);
}

void RenderSkillMasterArrow(DWORD ModelID, float x, float y, float Width, float Height, float arg1, float arg2, DWORD ScaleAlpha)
{
	pDrawColorButton(ModelID, x, y - 3, Width, Height, arg1, arg2, ScaleAlpha);
}
//-- master skill activado
void RenderSkillUsedMaster(int ModelID, float x, float y, float Width, float Height, float CurrentMoveX, float CurrentMoveY, float ScaleX, float ScaleY, int ScaleAlpha)
{
	float W = (Width / 100) * 75;
	float H = (Height / 100) * 75;

	RenderBitMapColored(ModelID, x + 3, y + 2, W, H, CurrentMoveX, CurrentMoveY, ScaleX, ScaleY, ScaleAlpha);
}

void sub_81A5B0(int a1)
{
	char MasterSkill_1[256] = { 0 }; // eax@6
	char MasterSkill_2[256] = { 0 }; // eax@6
	char MasterSkill_3[256] = { 0 }; // eax@6
	int v26; // ST18_4@6
	int v36; // [sp+10h] [bp-14Ch]@1

	v36 = a1;

	pSetTextColor(pTextThis(), 0xFFu, 0x9Bu, 0, 0xFFu);
	//-- 1751 "Peace: %d"
	v26 = *(DWORD *)(v36 + 300);
	wsprintf(MasterSkill_1, pGetTextLine(pTextLineThis, v26), gCRenderEx700.MasterPoint_1);
	pDrawText(pTextThis(), 92, 40, MasterSkill_1, 0, 0, (PINT) 1, 0);
	//-- 1752 "Wisdom: %d"
	v26 = *(DWORD *)(v36 + 300) + 1;
	wsprintf(MasterSkill_2, pGetTextLine(pTextLineThis, v26), gCRenderEx700.MasterPoint_2);
	pDrawText(pTextThis(), 302, 40, MasterSkill_2, 0, 0, (PINT) 1, 0);
	//-- 1753 "Overcome: %d"
	v26 = *(DWORD *)(v36 + 300) + 2;
	wsprintf(MasterSkill_3, pGetTextLine(pTextLineThis, v26), gCRenderEx700.MasterPoint_3);
	pDrawText(pTextThis(), 513, 40, MasterSkill_3, 0, 0, (PINT) 1, 0);
}

__declspec(naked) void ResetPoint()
{
	static DWORD Addr_JMP= 0x00651C9C;
	static DWORD Sumatoria;
	static DWORD Addr;

	_asm
	{
	MOV EAX,DWORD PTR SS:[EBP+8]
	MOV DWORD PTR SS:[EBP-4],EAX
	}

	gCRenderEx700.MasterPoint_1 = 0;
	gCRenderEx700.MasterPoint_2 = 0;
	gCRenderEx700.MasterPoint_3 = 0;

	_asm
	{
		JMP [Addr_JMP]
	}
}

__declspec(naked) void sub_819D60()
{
	static DWORD Addr_JMP= 0x00819EC9;
	static DWORD Sumatoria;
	static DWORD Addr;

	_asm
	{
		MOVZX ECX, BYTE PTR SS:[EBP-0x64]
		MOV Addr, ECX
		MOVZX ECX,BYTE PTR SS:[EBP+0xC]
		MOV Sumatoria, ECX
	}

	if ( Addr == 0 )
	{
		gCRenderEx700.MasterPoint_1 += Sumatoria;
		Addr_JMP= 0x00819E7A;
	}
	else if ( Addr == 1 )
	{
		gCRenderEx700.MasterPoint_2 += Sumatoria;
		Addr_JMP= 0x00819E95;
	}
	else if ( Addr == 2 )
	{
		gCRenderEx700.MasterPoint_3 += Sumatoria;
		Addr_JMP= 0x00819EB0;
	}

	_asm
	{
		JMP [Addr_JMP]
	}
}

__declspec(naked) void Render_81A1BE()
{
	static DWORD Addr_JMP = 0x0081AAA1;
	static DWORD Addr;

	_asm
	{
		MOV EDX, DWORD PTR SS:[EBP-0x14C]
		MOV Addr, EDX
	}

	sub_81A5B0(Addr);

	_asm
	{
		JMP [Addr_JMP]
	}
}

int ItemDrawPotion(int *This)
{
	void *v2; // [sp+10h] [bp-44h]@11
	void *v3; // [sp+14h] [bp-40h]@8
	void *v4; // [sp+18h] [bp-3Ch]@5
	void *v5; // [sp+1Ch] [bp-38h]@2
	int *v6; // [sp+20h] [bp-34h]@1
	void *v7; // [sp+24h] [bp-30h]@10
	void *v8; // [sp+2Ch] [bp-28h]@7
	void *v9; // [sp+34h] [bp-20h]@4
	void *v10; // [sp+3Ch] [bp-18h]@1
	void *v11; // [sp+44h] [bp-10h]@4
	int v12; // [sp+50h] [bp-4h]@1

	float xInterface = TransFor2X( 640 / 2 ) - TransForX( 640 / 2);

	v6 = This;
	//-- Q
	v10 = operator new(0x3Cu);
	v12 = 0;
	if ( v10 )
		v5 = CHotKeyQStateItem_CHotKeyQStateItem(v10, Return2X(xInterface + TransForX( 189 )), 445.5, Return2X(xInterface + TransForX( 206 )), 460);
	else
		v5 = 0;
	v12 = -1;
	v11 = v5;
	sub_896420((void *)v6, (int *)&v11);
	//-- W
	v9 = operator new(0x3Cu);
	v12 = 1;
	if ( v9 )
		v4 = CHotKeyWStateItem_CHotKeyWStateItem(v9, Return2X(xInterface + TransForX( 217 )), 445.5, Return2X(xInterface + TransForX( 234 )), 460);
	else
		v4 = 0;
	v12 = -1;
	v11 = v4;
	sub_896420((void *)v6, (int *)&v11);
	//-- E
	v8 = operator new(0x3Cu);
	v12 = 2;
	if ( v8 )
		v3 = CHotKeyEStateItem_CHotKeyEStateItem(v8, Return2X(xInterface + TransForX( 247 )), 445.5, Return2X(xInterface + TransForX( 261 )), 460);
	else
		v3 = 0;
	v12 = -1;
	v11 = v3;
	sub_896420((void *)v6, (int *)&v11);
	//-- R
	v7 = operator new(0x3Cu);
	v12 = 3;
	if ( v7 )
		v2 = CHotKeyRStateItem_CHotKeyRStateItem(v7, Return2X(xInterface + TransForX( 277 )), 445.5, Return2X(xInterface + TransForX( 291 )), 460);
	else
		v2 = 0;
	v12 = -1;
	v11 = v2;
	return sub_896420((void *)v6, (int *)&v11);
	//--
}

void ChangeShopInfo(int This)
{
	float x = TransFor2X( 320 ) - TransForX( 320 ) + TransForX( 43.5f );
	ChangeButtonInfo((char *)(This + 56), (int) Return2X( x ), (int) ReturnY( TransForY( 449.3 ) ), (int) Return2X(TransForX( 21.5 )),(int ) 21.5 );
}

__declspec(naked) void EnlaceAsm1()
{
	static DWORD main_Addr = 0x0080F2ED;
	static DWORD Addr;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x28]
		MOV Addr, EAX
	}

	ChangeShopInfo( Addr );
	
	_asm
	{
		JMP[main_Addr]
	}
}

void ChangeCharacterInfo(int This)
{
	float x = TransFor2X( 320 ) - TransForX( 320 ) + TransForX( 67.0f );
	ChangeButtonInfo((char *)(This + 228), (int) Return2X( x ), (int) ReturnY( TransForY( 449.3 ) ), (int) Return2X(TransForX( 21.5 )),(int ) 21.5 );
}

__declspec(naked) void EnlaceAsm2()
{
	static DWORD main_Addr = 0x0080F3D8;
	static DWORD Addr;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x28]
		MOV Addr, EAX
	}

	ChangeCharacterInfo( Addr );
	
	_asm
	{
		JMP[main_Addr]
	}
}

void ChangeInventoryInfo(int This)
{
	float x = TransFor2X( 320 ) - TransForX( 320 ) + TransForX( 92.0f );
	ChangeButtonInfo((char *)(This + 400), (int) Return2X( x ), (int) ReturnY( TransForY( 449.3 ) ), (int) Return2X(TransForX( 21.5 )),(int ) 21.5 );
}

__declspec(naked) void EnlaceAsm3()
{
	static DWORD main_Addr = 0x0080F4CC;
	static DWORD Addr;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x28]
		MOV Addr, EAX
	}

	ChangeInventoryInfo( Addr );
	
	_asm
	{
		JMP[main_Addr]
	}
}

void ChangeComunityInfo(int This)
{
	float x = TransFor2X( 320 ) - TransForX( 320 ) + TransForX( 552.0f );
	ChangeButtonInfo((char *)(This + 572), (int) Return2X( x ), (int) ReturnY( TransForY( 449.3 ) ), (int) Return2X(TransForX( 21.5 )),(int ) 21.5 );
}

__declspec(naked) void EnlaceAsm4()
{
	static DWORD main_Addr = 0x0080F5C0;
	static DWORD Addr;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x28]
		MOV Addr, EAX
	}

	ChangeComunityInfo( Addr );
	
	_asm
	{
		JMP[main_Addr]
	}
}

void ChangeSettingsInfo(int This)
{
	float x = TransFor2X( 320 ) - TransForX( 320 ) + TransForX( 576.0f );
	ChangeButtonInfo((char *)(This + 744), (int) Return2X( x ), (int) ReturnY( TransForY( 449.3 ) ), (int) Return2X(TransForX( 21.5 )),(int ) 21.5 );
}

__declspec(naked) void EnlaceAsm5()
{
	static DWORD main_Addr = 0x0080F6B4;
	static DWORD Addr;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x28]
		MOV Addr, EAX
	}

	ChangeSettingsInfo( Addr );
	
	_asm
	{
		JMP[main_Addr]
	}
}

void SDCurrentLive( )
{
	char String[255]; // [sp+58h] [bp-128h]@19
	float XSDScale; // ST38_4@18
	float nWidth; // [sp+158h] [bp-28h]@18
	float YSDCoord; // [sp+15Ch] [bp-24h]@18
	float Width; // [sp+160h] [bp-20h]@18
	float Height; // [sp+160h] [bp-20h]@18
	float SDFill; // [sp+46h] [bp-13Ah]@13
	float XSDCoord; // [sp+170h] [bp-10h]@18

	int Type = gProtect.m_MainInfo.CustomInterfaceType;

	XSDCoord = TransFor2X( 320 ) - TransForX( 320 );
	YSDCoord = ( Type == 4 ) ? TransForY( 428.675 ) : TransForY( 427.875 ) ;
	Height = ( Type == 4 ) ? TransForY( 8 ) : TransForY( 9.375 ) ;

	DWORD CurrentSD = (ViewCurSD > ViewMaxSD) ? ViewMaxSD : ((ViewCurSD < 0) ? 0 : ViewCurSD);

	Width = TransForX( 65.3 );
	SDFill = (double) ViewMaxSD / 100;
	XSDScale = ((double) CurrentSD / SDFill) * ( 0.009539999366 );
	nWidth = ((double) CurrentSD / SDFill) * ( Width / 100 );

	RenderBitmap(31300, XSDCoord + TransForX(( Type == 4 ) ? 179.375 : 179.975 ), YSDCoord, nWidth, Height, 0.0, 0.0, XSDScale, 1.0, 0, 0, 0.0);
//--
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
//--
	ZeroMemory(String, sizeof(String));
	wsprintf(String, pGetTextLine(pTextLineThis, 1181), CurrentSD, ViewMaxSD);
	pDrawText(pTextThis(), Return2X( XSDCoord + TransForX( 179.375 ) ), ReturnY( YSDCoord ) + 1, String, Return2X( Width ), 0, (LPINT)3, 0);
//--
	//-- HP
	ZeroMemory(String, sizeof(String));
	wsprintf(String, pGetTextLine(pTextLineThis, 1181), ViewCurHP, ViewMaxHP);
	pDrawText(pTextThis(), Return2X(XSDCoord + TransForX(107.25)), ReturnY(TransForY(440)), String, Return2X(TransForX(63.75)), 0, (LPINT)3, 0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C588);
}

void BPCurrentLive( )
{
	char String[255]; // [sp+58h] [bp-128h]@19
	float XBPDropMove; // ST38_4@18
	float XBPScale; // ST38_4@18
	float nWidth; // [sp+158h] [bp-28h]@18
	float YBPCoord; // [sp+15Ch] [bp-24h]@18
	float Width; // [sp+160h] [bp-20h]@18
	float Height; // [sp+160h] [bp-20h]@18
	float BPFill; // [sp+46h] [bp-13Ah]@13
	float XBPCoord; // [sp+170h] [bp-10h]@18
	float nXBPCoord; // [sp+170h] [bp-10h]@18
	float DropScale = 0.9399999976; // [sp+170h] [bp-10h]@18

	int Type = gProtect.m_MainInfo.CustomInterfaceType;

	DropScale = ( Type == 4 ) ? 0.9399999976 : 0.9499999881 ;

	XBPCoord = TransFor2X( 320 ) - TransForX( 320 );
	YBPCoord = ( Type == 4 ) ? TransForY( 429 ) : TransForY( 427.875 ) ;

	DWORD CurrentBP = (ViewCurBP > ViewMaxBP) ? ViewMaxBP : ((ViewCurBP < 0) ? 0 : ViewCurBP);

	Width = ( Type == 4 ) ? TransForX( 60 ) : TransForX( 70 ) ;
	BPFill = (double) ViewMaxBP / 100;
	XBPScale = ((double) CurrentBP / BPFill) * ( DropScale / 100 ); //-- XBPScale
	XBPDropMove = DropScale - XBPScale; //-- xBPCurrent
	nWidth = ((double) CurrentBP / BPFill) * ( Width / 100 ); //-- nWBPSize

	Height = ( Type == 4 ) ? TransForY( 8.3 ) : TransForY( 9.375 ) ;
	nXBPCoord = XBPCoord + TransForX(( Type == 4 ) ? 397 : 395 ) + Width - nWidth; //-- XBPCoord
	//--
	RenderBitmap(31299, nXBPCoord, YBPCoord, nWidth, Height, XBPDropMove, 0.0, XBPScale, 1.0, 0, 0, 0.0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	ZeroMemory(String, sizeof(String));
	wsprintf(String, pGetTextLine(pTextLineThis, 1181), CurrentBP, ViewMaxBP);
	pDrawText(pTextThis(), Return2X(XBPCoord + TransForX( 395 )), ReturnY( YBPCoord ), String, Return2X( Width ), 0, (LPINT)3, 0);

	//-- MP
	ZeroMemory(String, sizeof(String));
	wsprintf(String, pGetTextLine(pTextLineThis, 1181), ViewCurMP, ViewMaxMP);
	pDrawText(pTextThis(), Return2X(XBPCoord + TransForX(463.75)), ReturnY(TransForY(440)), String, Return2X(TransForX(63.75)), 0, (LPINT)3, 0);
	
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C588);
}

DWORD VKBUTTONQUEST_DELAY;

void Interface::DrawInterfaceCustom()
{
	float Width = TransForX( 640 );
	float y = TransForY( 480 - 73);
	float x = TransFor2X( 320 ) - TransForX( 320 );
	int Active;
	float nRenderX;
	float nRenderY;
	float nDropMoveY;

	float LiveRate; // [sp+16Ch] [bp-14h]@16;
	float nHeight; // [sp+158h] [bp-28h]@18
	float nCoord; // [sp+170h] [bp-10h]@18
	float nDropScale1; // ST38_4@18
	float nDropScale2; // ST38_4@18
	float nScale; // ST38_4@18

//-- HP
	nDropScale1 = (gProtect.m_MainInfo.CustomInterfaceType == 4) ? 0.6760000587 : 0.986000061 ;
	nDropScale2 = (gProtect.m_MainInfo.CustomInterfaceType == 4) ? 0.6460000873 : 0.986000061 ;

	LiveRate = (double) ViewMaxHP / 100;
	nScale = ((double) ViewCurHP / LiveRate) * ( nDropScale1 / 100 );
	nDropMoveY = nDropScale1 - nScale; //-- HPCurrent
	nHeight = ((double) ViewCurHP / LiveRate) * ( TransForY( 63.75 ) / 100 );
	nCoord = TransForY( 408.125 ) + TransForY( 63.75 ) - nHeight;

	nRenderX = (gProtect.m_MainInfo.CustomInterfaceType == 4) ? x + TransForX( 106.2 ) : x + TransForX( 107.25 ) ;

	RenderBitmap(51502, nRenderX, TransForY(408.125), TransForX(63.75), TransForY(63.75), 0.0, 0.0, nDropScale2, nDropScale1, 0, 0, 0);

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 55) )
	{
		RenderBitmap(31297, nRenderX, nCoord, TransForX(63.75), nHeight, 0.0, nDropMoveY, nDropScale2, nScale, 0, 0, 0);
	}
	else
	{
		RenderBitmap(31298, nRenderX, nCoord, TransForX(63.75), nHeight, 0.0, nDropMoveY, nDropScale2, nScale, 0, 0, 0);
	}
//-- MP
	nDropScale1 = (gProtect.m_MainInfo.CustomInterfaceType == 4) ? 0.6760000587 : 0.986000061 ;
	nDropScale2 = (gProtect.m_MainInfo.CustomInterfaceType == 4) ? 0.6460000873 : 0.986000061 ;

	LiveRate = (double) ViewMaxMP / 100;
	nScale = ((double) ViewCurMP / LiveRate) * ( nDropScale1 / 100 );
	nDropMoveY = nDropScale1 - nScale;
	nHeight = ((double) ViewCurMP / LiveRate) * ( TransForY(63.75) / 100 );
	nCoord = TransForY(408.125) + TransForY( 63.75 ) - nHeight;

	nRenderX = (gProtect.m_MainInfo.CustomInterfaceType == 4) ? x + TransForX( 461 ) : x + TransForX( 463.75 ) ;

	RenderBitmap(51501, nRenderX, TransForY(408.125), TransForX(63.75), TransForY(63.75), 0.0, 0.0, nDropScale2, nDropScale1, 0, 0, 0);
	RenderBitmap(31296, nRenderX, nCoord, TransForX(63.75), nHeight, 0.0, nDropMoveY, nDropScale2, nScale, 0, 0, 0); 

//-- Interface
	RenderBitmap(31293, x, y, Width, TransForY( 73 ), 0.0, 0.0, 0.9129598141, 0.8629598618, 0, 0, 0.0);

	for ( int i = 0; i < 6; i++ )
	{
		nRenderY = y + TransForY( 42.3 );
		Active = 0;

		switch ( i )
		{
		case 0: //-- XShop
			nRenderX = x + TransForX( 43.5f );
			nDropMoveY = 0.0017000035f;

			if( pCheckWindow(pWindowThis(), CashShop) )
			{
				Active = 1;
			}
			break;
		case 1: //-- Character
			nRenderX = x + TransForX( 67.0f );
			nDropMoveY = 0.1100000367f;

			if( pCheckWindow(pWindowThis(), Character) )
			{
				Active = 1;
			}
			break;
		case 2: //-- Inventory
			nRenderX = x + TransForX( 92.0f );
			nDropMoveY = 0.2199999988f;

			if( pCheckWindow(pWindowThis(), Inventory) )
			{
				Active = 1;
			}
			break;
		case 3: //-- Quest
			nRenderX = x + TransForX( 527.5 );
			nDropMoveY = 0.3319000006f;

			if( pCheckWindow(pWindowThis(), Quest) )
			{
				Active = 1;
			}
			break;
		case 4: //-- FrientList
			nRenderX = x + TransForX( 552.0f );
			nRenderY = y + TransForY( 42.3 );
			nDropMoveY = 0.4429999590f;

			if( pCheckWindow(pWindowThis(), FriendList) )
			{
				Active = 1;
			}
			break;
		case 5: //-- Settings
			nRenderX = x + TransForX( 576.0f );
			nRenderY = y + TransForY( 41.4 );
			nDropMoveY = 0.5518001318;

			if( pCheckWindow(pWindowThis(), FastMenu) )
			{
				Active = 1;
			}
			break;
		}

		if( pCheckMouseOver(Return2X( nRenderX ), ReturnY( nRenderY ), Return2X(TransForX( 21.5 )), 21.5 ) &&  i == 3 )
		{
			pDrawToolTip(Return2X( nRenderX ), ReturnY( nRenderY - 15), pGetTextLine(pTextLineThis, 3427));
		}

		if( CheckButtonPressed(Return2X( nRenderX ), ReturnY( nRenderY ), Return2X(TransForX( 21.5 )), 21.5 ) )
		{
			RenderBitmap(0x901, nRenderX, nRenderY, TransForX( 21.5 ), TransForY( 21.5 ), 0.4560999572, nDropMoveY, 0.4390000105, 0.1105510294, 0, 0, 0.0);
			
			if( i == 3 ) //-- Evento Boton Quest
			{
				if(GetTickCount() >= VKBUTTONQUEST_DELAY + 200)
				{
					if( pCheckWindow(pWindowThis(), Quest) )
					{
						pCloseWindow(pWindowThis(), Quest);
					}
					else
					{
						pOpenWindow(pWindowThis(), Quest);
						PlayBuffer(25, 0, 0);
					}
					VKBUTTONQUEST_DELAY = GetTickCount();
				}
			}
		}
		else
		{
			RenderBitmap(0x901, nRenderX, nRenderY, TransForX( 21.5 ), TransForY( 21.5 ), ( Active == 1 ) ? 0.4560999572 : 0.0, nDropMoveY, 0.4390000105, 0.1105510294, 0, 0, 0.0);
		}
	}

	if ( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535)
		{
			gCRenderEx700.BarPetMuun();
		}
	}
}

DWORD VKBUTTON_DELAY;

void CEx700::BarPetMuun()
{
	int y = 31;

	RenderBitmap(61545, 2, y, Return2X(TransForX(74)), ReturnY(TransForY(20)), 0.0, 0.0, 0.75,0.1678999364, 1, 1, 0); //-- Barra

	if(MinimizarPet == 0)
	{
		if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(2)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(2)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.6000000238, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY + 200 )
			{
				MinimizarPet = 1;
				VKBUTTON_DELAY = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(2)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.4829999804, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
		}
	}
	else
	{
		if(CheckButtonPressed( Return2X(TransForX(61)), y + ReturnY(TransForY(2)), Return2X(TransForX(14)), ReturnY(TransForY(14))))
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(2)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.1289999783, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
			if( GetTickCount() >= VKBUTTON_DELAY + 200 )
			{
				MinimizarPet = 0;
				VKBUTTON_DELAY = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(61545, Return2X(TransForX(61)), y + ReturnY(TransForY(2)), Return2X(TransForX(14)), ReturnY(TransForY(14)), 0.01299999934, 0.4131799936, 0.1090999693, 0.09779000282,1, 1, 0); //-- Boton Minimizar
		}
	}
}

void InventoryWindows(DWORD id, float x, float y, float w, float h)
{
	//-- NPC RUUD
//=============================
	jCRenderRuud.OpenRuud();
//=============================
	pDrawGUI(id, x, y, w, h);
}

int sub_895600(float x, float y, int number)
{
	int result; // eax@1

	pSetBlend( 1 );

	result = CRenderNumberEx(x, y, number, ( pWinWidthReal <= 1.6 ) ? 1.0 : 0.90, 31337);

	return result;
}

void CEx700::Init()
{
	SetCompleteHook(0xE9, 0x00895600, &sub_895600); //-- Number Stack

	//-- Windows Inventory
	SetCompleteHook(0xE8, 0x00836EF6, &InventoryWindows);
	SetRange((LPVOID)0x0080F845, 5, ASM::NOP); //-- HP | MP
	SetCompleteHook(0xE8, 0x0080F84D, &SDCurrentLive);
	SetCompleteHook(0xE8, 0x0080F855, &BPCurrentLive);
	//--
	SetDword(0x0080F34C + 1, 0xD5D);//-- Tooltip In-game Shop
	SetCompleteHook(0xE9, 0x0080F2D2, &EnlaceAsm1); //-- CashShop
	SetCompleteHook(0xE9, 0x0080F3BA, &EnlaceAsm2); //-- Character
	SetCompleteHook(0xE9, 0x0080F4AE, &EnlaceAsm3); //-- Inventory
	SetDword(0x0080F625 + 1, 0xD64);//-- Tooltip Community
	SetCompleteHook(0xE9, 0x0080F5A2, &EnlaceAsm4); //-- FriendList
	SetDword(0x0080F710 + 1, 0xD65);//-- Tooltip System
	SetCompleteHook(0xE9, 0x0080F696, &EnlaceAsm5); //-- Settings
	//--
	SetCompleteHook(0xE8, 0x0089599E, &ItemDrawPotion);

	SetCompleteHook(0xE9, 0x00651C96, &ResetPoint); //-- Obtain Skill Point Reset
	SetCompleteHook(0xE9, 0x00819E66, &sub_819D60); //-- Obtain Skill Point
	SetCompleteHook(0xE9, 0x0081A999, &Render_81A1BE);
	//--
	SetCompleteHook(0xE8, 0x0081B182, &RenderSkillMasterArrow);
	SetCompleteHook(0xE9, 0x0081AF01, &RenderPointSkillMaster);
	SetCompleteHook(0xE8, 0x0081AEAC, &RenderSkillUsedMaster);
	SetCompleteHook(0xE8, 0x0081ADDF, &RenderSkillMasterBox);
	SetCompleteHook(0xE8, 0x004F9477, &Render_SkillTooltip); //-- Tooltip Skill Raven
	SetCompleteHook(0xE8, 0x005C6680, &Render_SkillTooltip); //-- Tooltip Skill
	//--
	SetCompleteHook(0xE9, 0x008126C0, &CEx700::SkillMouseOver);
	SetCompleteHook(0xE9, 0x00813970, &CEx700::SkillSwitchBar);
	SetCompleteHook(0xE9, 0x00813746, &CEx700::SkillSelectBar);
	//--
	SetCompleteHook(0xE8, 0x0081A146, &RenderMasterSkill);
	SetCompleteHook(0xE8, 0x0081A199, &RenderMasterSkill);
	//-- Fix Mapas
	SetCompleteHook(0xE8, 0x005B97DC,&RenderSands);
	SetCompleteHook(0xE8, 0x005B984C,&RenderSands);
	SetCompleteHook(0xE8, 0x008C2E0F,&RenderSands);
	SetCompleteHook(0xE8, 0x008C2E7F,&RenderSands);
	SetCompleteHook(0xE8, 0x008EF65A,&RenderSands);
	SetCompleteHook(0xE8, 0x008EF5C5,&RenderSands);
	SetCompleteHook(0xE8, 0x00914FC9,&RenderSands);
	SetCompleteHook(0xE8, 0x0091503E,&RenderSands);
	//-- ExpBar || Master Exp
	SetCompleteHook(0xE8, 0x00810F45, &RenderNumberExp);
	SetCompleteHook(0xE8, 0x008117EE, &RenderNumberExp);
	SetCompleteHook(0xE8, 0x00810A1A, &RenderBarExp);
	SetCompleteHook(0xE8, 0x00810BE5, &RenderBar2Exp);
	SetCompleteHook(0xE8, 0x00810D2C, &RenderBarExp);
	SetCompleteHook(0xE8, 0x00810DC3, &RenderBarExp);
	SetCompleteHook(0xE8, 0x00810EF0, &RenderBarExp);
	SetCompleteHook(0xE8, 0x008112A6, &RenderBarExp);
	SetCompleteHook(0xE8, 0x0081147F, &RenderBar2Exp);
	SetCompleteHook(0xE8, 0x008115C9, &RenderBarExp);
	SetCompleteHook(0xE8, 0x00811660, &RenderBarExp);
	SetCompleteHook(0xE8, 0x00811790, &RenderBarExp);
	SetCompleteHook(0xE8, 0x00810A97, &RenderBarExpAdd);
	SetCompleteHook(0xE8, 0x00810C62, &RenderBarExpAdd);
	SetCompleteHook(0xE8, 0x00810E40, &RenderBarExpAdd);
	SetCompleteHook(0xE8, 0x00811323, &RenderBarExpAdd);
	SetCompleteHook(0xE8, 0x008114FC, &RenderBarExpAdd);
	SetCompleteHook(0xE8, 0x008116DD, &RenderBarExpAdd);
	//-- PartyBar
	SetByte(0x0085AF21, 25); //--
	SetRange((LPVOID)0x0084B95E, 5, ASM::NOP);
	SetJmp((LPVOID)0x0084B95E, PartyWindowsMove);
	SetOp((LPVOID)0x00834700, (LPVOID)MouseClickRender, ASM::CALL);
	SetDword(0x004D9746 + 3, 480); //Size Background
}