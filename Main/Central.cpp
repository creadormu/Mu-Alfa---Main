#include "stdafx.h"
#include "Import.h"
#include "Util.h"
#include "Defines.h"
#include "Central.h"
#include "postInterface.h"
#include "Interface.h"
#include "Protect.h"
#include "PrintPlayer.h"
#include "Ruud.h"
#include "MiniMap.h"
#include "Common.h"
#include "CSCharacterS13.h"
#include "WindowsStruct.h"
#include "PartyBuffs.h"
#include "User.h"
#include "StatsAdvance.h"
#include "InfoLog.h"
#include "NPCRuud.h"
#include "JCOptionBox.h"

Centralizado gCentral;

Centralizado::Centralizado()
{
	this->JCOption[0].SetText("Effect Dinamic");
	this->JCOption[0].LoadAction(DisableDynamicEffect, JCDINAMIC_EFFECT);
	this->JCOption[1].SetText("Effect Static");
	this->JCOption[1].LoadAction(DisableStaticEffect, JCSTATIC_EFFECT);
	this->JCOption[2].SetText("Effect Skill");
	this->JCOption[2].LoadAction(DisableSkillEffect, JCSKILL_EFFECT);
	this->JCOption[3].SetText("Item Glow");
	this->JCOption[3].LoadAction(DisableGlowEffect, JCITEMGLOW_EFFECT);
	this->JCOption[4].SetText("Object Shadow");
	this->JCOption[4].LoadAction(DisableShadow, JCOBJECTSHADOW);
	this->JCOption[5].SetText("Map Object");
	this->JCOption[5].LoadAction(DisableObject, JCOBJECTWORLDHIDE);
}

Centralizado::~Centralizado()
{
}

//**********************************************//
//************ Takumi12 <- Client ************//
//**********************************************//
#if (takumi12 == 1)
void Centralizado::ClearPartyInfo()
{
	for (int i = 0; i < MAX_USER_IN_PARTY; i++)
	{
		ZeroMemory(this->m_PartyInfo[i].name, sizeof(this->m_PartyInfo[i].name));
		this->m_PartyInfo[i].number = -1;
		this->m_PartyInfo[i].CurMana = -1;
		this->m_PartyInfo[i].MaxMana = -1;
	}
	this->m_PartyCount = 0;
}

void Centralizado::InsertPartyInfo(PMSG_PARTY_LIST* lpInfo)
{
	memcpy(&this->m_PartyInfo[m_PartyCount].name, lpInfo->name, sizeof(this->m_PartyInfo[m_PartyCount].name));
	this->m_PartyInfo[m_PartyCount].number = lpInfo->number;
	this->m_PartyInfo[m_PartyCount].CurMana = lpInfo->CurMana;
	this->m_PartyInfo[m_PartyCount].MaxMana = lpInfo->MaxMana;
	this->m_PartyCount++;
}

void Centralizado::ClearPartyLife()
{
	for (int i = 0; i < MAX_USER_IN_PARTY; i++)
	{
		ZeroMemory(this->m_PartyLife[i].name, sizeof(this->m_PartyLife[i].name));
		this->m_PartyLife[i].mana = -1;
	}
	this->m_PartyCount = 0;
}

void Centralizado::InsertPartyLife(PMSG_PARTY_LIFE* lpInfo)
{
	memcpy(&this->m_PartyLife[m_PartyCount].name, lpInfo->name, sizeof(this->m_PartyLife[m_PartyCount].name));
	this->m_PartyLife[m_PartyCount].mana = lpInfo->mana;
	this->m_PartyCount++;
}

void Centralizado::CGPartyListRecv(PMSG_PARTY_LIST_SEND * lpMsg) // OK
{
	this->ClearPartyInfo();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_PARTY_LIST * lpInfo = (PMSG_PARTY_LIST*)(((BYTE*)lpMsg) + sizeof(PMSG_PARTY_LIST_SEND) + (sizeof(PMSG_PARTY_LIST) * n));
		this->InsertPartyInfo(lpInfo);
	}
}

void Centralizado::CGPartyLifeRecv(PMSG_PARTY_LIFE_SEND * lpMsg) // OK
{
	this->ClearPartyLife();

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_PARTY_LIFE* lpInfo = (PMSG_PARTY_LIFE*)(((BYTE*)lpMsg) + sizeof(PMSG_PARTY_LIFE_SEND) + (sizeof(PMSG_PARTY_LIFE) * n));
		this->InsertPartyLife( lpInfo);
	}
}
#endif

void Centralizado::RenderCursor()
{
	float v3; // STD0_4@11
	float v4; // STCC_4@11
	float v5; // STD0_4@11
	float v6; // STCC_4@11
	int v31; // eax@46
	int v36; // eax@50
	int v39; // eax@52
	float v44; // ST60_4@58
	DWORD *v51; // eax@63
	int v60; // [sp+D0h] [bp-Ch]@1
	float v61; // [sp+D4h] [bp-8h]@1
	float v62; // [sp+D8h] [bp-4h]@1

	int * dword_8787D58 = (int*)0x8787D58;

	pSetBlend(1);
	glColor3f(1.0, 1.0, 1.0);
	
	v61 = 0.0;
	v62 = 0.0;

	v3 = (double)CursorY - 2.0;
	v4 = (double)CursorX - 2.0;
	v5 = (double)CursorY + 18.0;
	v6 = (double)CursorX + 5.0;

	if (*(DWORD*) 0x81F6BE8 || *(DWORD*) 0xE8CB3C )	//-- bloquear cursor
	{
		if( pCheckWindow(pWindowThis(),10) )
		{
			v31 = sub_8615E0((int)pWindowThis());

			if( sub_78ECE0(v31) == 9)
			{
				RenderBitmap(31239, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}
			else
			{
				if ( sub_78ECE0(v31) )
				{
					if ( sub_78ECE0(v31) == 1 )
					{
						RenderBitmap( 30013, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}
				}
				else
				{
					RenderBitmap( 30012, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
			}
		}
		else
		{
			if ( pCheckWindow(pWindowThis(), 13)
			&& ( v36 = sub_861260((int)pWindowThis()), CheckRepairInv(v36) == 1)
			|| pCheckWindow(pWindowThis(), 12)
			&& (v39 = GetWindowShop((int)pWindowThis()), CheckRepairShop(v39) == 2) )
			{
				if ( *(BYTE*) 0x8793386 )
				{
					sub_637E80( 30017, v6, v5, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 45.0, 0.0, 0.0, 1.0, 1.0);
				}
				else
				{
					RenderBitmap( 30017, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
			}
			else if ( *(DWORD*)0x81F6BE0 == 2 )
			{
				v44 =*(float*)0x5EF5A1C * 0.01999999955296516;
				sub_4F6170(v44);
				if ( v44 <= 0.0 )
				{
					sub_637E80( 30017, v6, v5, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 45.0, 0.0, 0.0, 1.0, 1.0);
				}
				else
				{
					sub_637E80(30017, (double)*(DWORD*)0x879340C + 10.0, (double)*(DWORD*)0x8793410 + 10.0, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 0.0, 1.0, 1.0);
				}
			}
			else
			{
				if ( *(BYTE*)0x8793386 )
				{
					if ( !*(BYTE*)0x81C03AA )//-- clic
					{
						RenderBitmap( 30013, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}
				}
				else
				{
					RenderBitmap( 30012, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
			}
		}
	}
	else if(ItemTarget == -1)	//-- recoger item
	{
		if ( NpcTarget == -1 ) //-- NPC TARGET
		{
			if ( *(DWORD*)0xE61734 == -1 )
			{
				if ( *(BYTE *)(0x7BC4F04 + 14) || PlayerTarget == -1 ) //-- PLAYER TARGET
				{
					if( pCheckWindow(pWindowThis(),10) )
					{
						v31 = sub_8615E0((int)pWindowThis());

						if( sub_78ECE0(v31) == 9)
						{
							RenderBitmap(31239, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
						}
						else
						{
							if ( sub_78ECE0(v31) )
							{
								if ( sub_78ECE0(v31) == 1 )
								{
									if ( *(BYTE*)0x8793386 )
									{
										if ( !*(BYTE*)0x81C03AA )//-- clic
										{
											RenderBitmap( 30013, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
										}
									}
									else
									{
										RenderBitmap( 30012, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
									}
								}
							}
							else
							{
								RenderBitmap( 30012, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
						}
					}
					else
					{
						if ( pCheckWindow(pWindowThis(), 13)
						&& ( v36 = sub_861260((int)pWindowThis()), CheckRepairInv(v36) == 1)
						|| pCheckWindow(pWindowThis(), 12)
						&& (v39 = GetWindowShop((int)pWindowThis()), CheckRepairShop(v39) == 2) )
						{
							if ( *(BYTE*)0x8793386 )
							{
								sub_637E80( 30017, v6, v5, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 45.0, 0.0, 0.0, 1.0, 1.0);
							}
							else
							{
								RenderBitmap(30017, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
						}
						else if ( *(DWORD*)0x81F6BE0 == 2 )
						{
							v44 = *(float*)0x5EF5A1C * 0.01999999955296516;
							sub_4F6170(v44);
							if ( v44 <= 0.0 )
							{
								sub_637E80( 30017, v6, v5, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 45.0, 0.0, 0.0, 1.0, 1.0);
							}
							else
							{
								sub_637E80(30017, (double)*(DWORD*)0x879340C + 10.0, (double)*(DWORD*)0x8793410 + 10.0, TransFor2X(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 0.0, 1.0, 1.0);
							}
						}
						else
						{
							if ( pCheckWindow(pWindowThis(), 13)
							&& ( v51 = (DWORD *)GetWindowShop((int)pWindowThis()), sub_83C310(v51)) )
							{
								RenderBitmap(30021, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
							else if ( *(BYTE*)0x8793386 )
							{
								if ( *(BYTE*)0x81C03AA )
								{
									RenderBitmap(30020, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
								}
								else
								{
									RenderBitmap(30013, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
								}
							}
							else
							{
								RenderBitmap(30012, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
						}
					}
				}
				else if ( !sub_59A8B0() || *(BYTE*)0x813DDCE )
				{
					RenderBitmap(30012, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if ( (unsigned __int8)sub_4DB0E0(*(DWORD *)0xE61E18) )
				{
					RenderBitmap(30011, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else
				{
					RenderBitmap(30014, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				//-- finaliza la carroña
			}
			else if ( 
				(*(DWORD *)0xE61E18 || *(DWORD *)(dword_8787D58[3 * *(DWORD *)0xE61734] + 48) != 133)
			&& (*(DWORD *)0xE61E18 != 1 || *(DWORD *)(dword_8787D58[3 * *(DWORD *)0xE61734] + 48) != 60)
			&& (*(DWORD *)0xE61E18 != 2 || *(DWORD *)(dword_8787D58[3 * *(DWORD *)0xE61734] + 48) != 91)
			&& (*(DWORD *)0xE61E18 != 3 || *(DWORD *)(dword_8787D58[3 * *(DWORD *)0xE61734] + 48) != 38) )
			{
				RenderBitmap(30019, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}
			else
			{
				RenderBitmap(30018, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}
		}
		else if ( *(DWORD *)0xE61E18 == 38 )//-- ATACAR UN MONSTER
		{
			RenderBitmap( 30011, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		}
		else//-- HABLAR CON NPC
		{
			v60 = (int)(timeGetTime() * 0.009999999776482582) % 6;
			if ( v60 == 1 || v60 == 3 || v60 == 5 )
			{	v61 = 0.5;}
			if ( v60 == 2 || v60 == 3 || v60 == 4 )
			{	v62 = 0.5;}

			RenderBitmap( 30016, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), v61, v62, 0.5, 0.5, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(30015, v4, v3, ReturnX(TransForX(24.0)), ReturnY(TransForY(24.0)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}
}

int Centralizado::MoveRenderCameraDefault()
{
	pSetCursorFocus = false;
	int Width = TransForX( 190 );
	int a3 = 640;
	int t;

	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		if(gInterface.Data[eCONFIRM_MAIN].OnShow)
		{
			pSetCursorFocus = true;
		}

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
	
		if ( gInterface.CheckWindow(Shop) )
		{
				t = Return2X( Width);

			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			if( pCursorX <= t ||  pCursorX >= a3 )
			{
				pSetCursorFocus = true;
			}
		}
		else if ( gInterface.CheckWindow(Warehouse) )
		{
				t = Return2X( Width);

			if( gInterface.CheckWindow(ExpandWarehouse) )
			{
				t = Return2X(Width * 2);
			}
			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			if( pCursorX <= t ||  pCursorX >= a3 )
			{
				pSetCursorFocus = true;
			}
		}
		else if(pCursorX >= a3)
		{
			pSetCursorFocus = true;
		}

		if(gInterface.Data[eMenu_MAIN].OnShow||
			gInterface.Data[eMenu_MAINTWO].OnShow||
			gInterface.Data[eVip_MAIN].OnShow||
			gInterface.Data[eEventTimePANEL_MAIN].OnShow||
			gInterface.Data[eCommand_MAIN].OnShow||
			gInterface.Data[eRankPANEL_MAIN].OnShow||
			gInterface.Data[eCONFIRM_MAIN].OnShow||			
			gInterface.Data[ePARTYSETTINGS_MAIN].OnShow||
			gInterface.Data[ePARTYSEARCH_MAIN].OnShow||
			gInterface.Data[eVAULT_MAIN].OnShow||
			gInterface.Data[eCHANGINGCLASS_MAIN].OnShow||
			gInterface.Data[eCHANGE_RESET_MAIN].OnShow||
			gInterface.Data[eLuckyWheelMain].OnShow||			
			gInterface.Data[eSMITH_MAIN].OnShow||
			gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow||
			gInterface.Data[eTUCHAN_MAIN].OnShow||
			gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow||
			gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow||	
			
			gInterface.Data[eJEWELBANK_MAIN].OnShow)
		{
			pSetCursorFocus = true;
		}

		if ( gInterface.CheckWindow(33) )
		{
			if( pCheckMouseOver(0, *(signed int *)(*(DWORD *)(GetInstance() + 12) + 24) + 10,(int) Return2X(TransForX( 15.625 )),(int) ReturnY(TransForY( 15.625 ))))
			{
				pSetCursorFocus = true;
			}
		}

		if( gRenderMap.DataMap.ModelID != -1 && MiniMap )
		{
			if(pCheckMouseOver(gRenderMap.DataMap.XSW_Minimap, gRenderMap.DataMap.YSW_Minimap, 128, 128))
			{
				pSetCursorFocus = true;
			}
		}

		if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 )
		{
			if( pCheckMouseOver(2, 31, Return2X(TransForX(74)), 20) )
			{
				pSetCursorFocus = true;
			}
		}

		if( jCRenderRuud.OpeningRuud && pCheckWindow(pWindowThis(), 13) )
		{
			if( pCheckMouseOver(1, 0, Return2X( Width ), 429) )
			{
				pSetCursorFocus = true;
			}
		}

		if( jCRenderRuud.OpeningRuud && jCRenderRuud.OpenWindowConfirm && pCheckWindow(pWindowThis(), 13) )
		{
			pSetCursorFocus = true;
		}
	}
	else
	{
		if(gInterface.Data[eCONFIRM_MAIN].OnShow)
		{
			pSetCursorFocus = true;
		}
		else if ( gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix) ) //-- 76
		{
			gInterface.Data[eMenu_MAIN].OnShow = false;
			gInterface.Data[eMenu_MAINTWO].OnShow = false;	
			gInterface.Data[eVip_MAIN].OnShow = false;
			gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
			gInterface.Data[eCommand_MAIN].OnShow = false;
			gInterface.Data[eRankPANEL_MAIN].OnShow = false;
			gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
			gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
			gInterface.Data[eVAULT_MAIN].OnShow = false;
			gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
			gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
			gInterface.Data[eLuckyWheelMain].OnShow = false;
			gInterface.Data[eSMITH_MAIN].OnShow = false;
			gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
			gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
			gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
			gInterface.Data[eTUCHAN_MAIN].OnShow = false;
			gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;

			if(pCursorX >= 260)
			{
				pSetCursorFocus = true;
			}
		}
		else
		{
			if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
			{
				gInterface.Data[eMenu_MAIN].OnShow = false;
				gInterface.Data[eMenu_MAINTWO].OnShow = false;
				gInterface.Data[eVip_MAIN].OnShow = false;
				gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
				gInterface.Data[eCommand_MAIN].OnShow = false;
				gInterface.Data[eRankPANEL_MAIN].OnShow = false;
				gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
				gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
				gInterface.Data[eVAULT_MAIN].OnShow = false;
				gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
				gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
				gInterface.Data[eLuckyWheelMain].OnShow = false;
				gInterface.Data[eSMITH_MAIN].OnShow = false;
				gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
				gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
				gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
				gInterface.Data[eTUCHAN_MAIN].OnShow = false;
				gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;

				if(pCursorX >= 260)
				{
					pSetCursorFocus = true;
				}
			}
			else
			{
				if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
				{
					gInterface.Data[eMenu_MAIN].OnShow = false;
					gInterface.Data[eMenu_MAINTWO].OnShow = false;
					gInterface.Data[eVip_MAIN].OnShow = false;
					gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
					gInterface.Data[eCommand_MAIN].OnShow = false;
					gInterface.Data[eRankPANEL_MAIN].OnShow = false;
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
					gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
					gInterface.Data[eVAULT_MAIN].OnShow = false;
					gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
					gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
					gInterface.Data[eLuckyWheelMain].OnShow = false;
					gInterface.Data[eSMITH_MAIN].OnShow = false;
					gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
					gInterface.Data[eTUCHAN_MAIN].OnShow = false;
					gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;

					if(pCursorX >= 260)
					{
						pSetCursorFocus = true;
					}
				}
				else
				{
					if ( gInterface.CheckWindow(27) )
					{
						gInterface.Data[eMenu_MAIN].OnShow = false;
						gInterface.Data[eMenu_MAINTWO].OnShow = false;
						gInterface.Data[eVip_MAIN].OnShow = false;
						gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
						gInterface.Data[eCommand_MAIN].OnShow = false;
						gInterface.Data[eRankPANEL_MAIN].OnShow = false;
						gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
						gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
						gInterface.Data[eVAULT_MAIN].OnShow = false;
						gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
						gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
						gInterface.Data[eLuckyWheelMain].OnShow = false;
						gInterface.Data[eSMITH_MAIN].OnShow = false;
						gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
						gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
						gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
						gInterface.Data[eTUCHAN_MAIN].OnShow = false;
						gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;

						if(pCursorX >= 260)
						{
							pSetCursorFocus = true;
						}
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
							if(pCursorX >= 450)
							{
									pSetCursorFocus = true;
							
							}
						}
						else
						{
							if ( gInterface.CheckWindow(79) )
							{
								gInterface.Data[eMenu_MAIN].OnShow = false;
								gInterface.Data[eMenu_MAINTWO].OnShow = false;
								gInterface.Data[eVip_MAIN].OnShow = false;
								gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
								gInterface.Data[eCommand_MAIN].OnShow = false;
								gInterface.Data[eRankPANEL_MAIN].OnShow = false;
								gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
								gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
								gInterface.Data[eVAULT_MAIN].OnShow = false;
								gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
								gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
								gInterface.Data[eLuckyWheelMain].OnShow = false;
								gInterface.Data[eSMITH_MAIN].OnShow = false;
								gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
								gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
								gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
								gInterface.Data[eTUCHAN_MAIN].OnShow = false;
								gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;

								if ( gInterface.CheckWindow(80) )
								{
									if(pCursorX >= 260)
									{
										pSetCursorFocus = true;
									}
								}
								else
								{
									if(pCursorX >= 450)
									{
										pSetCursorFocus = true;
									}
								}	
							}
							else
							{
								if(gInterface.Data[eMenu_MAIN].OnShow || 
									gInterface.Data[eMenu_MAINTWO].OnShow || 
									gInterface.Data[eVip_MAIN].OnShow || 
									gInterface.Data[eEventTimePANEL_MAIN].OnShow ||
									gInterface.Data[eCommand_MAIN].OnShow ||
									gInterface.Data[eRankPANEL_MAIN].OnShow ||								
									gInterface.Data[ePARTYSETTINGS_MAIN].OnShow ||
									gInterface.Data[ePARTYSEARCH_MAIN].OnShow ||
									gInterface.Data[eVAULT_MAIN].OnShow ||
									gInterface.Data[eCHANGINGCLASS_MAIN].OnShow||
									gInterface.Data[eCHANGE_RESET_MAIN].OnShow||
									gInterface.Data[eLuckyWheelMain].OnShow||
									gInterface.Data[eSMITH_MAIN].OnShow||
									gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow||
									gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow||
									gInterface.Data[eTUCHAN_MAIN].OnShow||
									gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow||
									gInterface.Data[eJEWELBANK_MAIN].OnShow)
								{
									pSetCursorFocus = true;
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
					gInterface.CheckWindow(Character) ||
					gInterface.CheckWindow(Shop))
				{
					gInterface.Data[eMenu_MAIN].OnShow = false;
					gInterface.Data[eMenu_MAINTWO].OnShow = false;
					gInterface.Data[eVip_MAIN].OnShow = false;
					gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
					gInterface.Data[eCommand_MAIN].OnShow = false;
					gInterface.Data[eRankPANEL_MAIN].OnShow = false;
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
					gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
					gInterface.Data[eVAULT_MAIN].OnShow = false;
					gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
					gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
					gInterface.Data[eLuckyWheelMain].OnShow = false;
					gInterface.Data[eSMITH_MAIN].OnShow = false;
					gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
					gInterface.Data[eTUCHAN_MAIN].OnShow = false;
					gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;

					if(pCursorX >= 70)
					{
						pSetCursorFocus = true;
					}
				}
				else
				{
					gInterface.Data[eMenu_MAIN].OnShow = false;
					gInterface.Data[eMenu_MAINTWO].OnShow = false;
					gInterface.Data[eVip_MAIN].OnShow = false;
					gInterface.Data[eEventTimePANEL_MAIN].OnShow = false;
					gInterface.Data[eCommand_MAIN].OnShow = false;
					gInterface.Data[eRankPANEL_MAIN].OnShow = false;
					gInterface.Data[ePARTYSETTINGS_MAIN].OnShow = false;
					gInterface.Data[ePARTYSEARCH_MAIN].OnShow = false;
					gInterface.Data[eVAULT_MAIN].OnShow = false;
					gInterface.Data[eCHANGINGCLASS_MAIN].OnShow = false;
					gInterface.Data[eCHANGE_RESET_MAIN].OnShow = false;
					gInterface.Data[eLuckyWheelMain].OnShow = false;
					gInterface.Data[eSMITH_MAIN].OnShow = false;
					gInterface.Data[eJEWELBANK_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow = false;
					gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow = false;
					gInterface.Data[eTUCHAN_MAIN].OnShow = false;
					gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow = false;

					if(pCursorX >= 260)
					{
						pSetCursorFocus = true;
					}
				}
			}
			else if ( gInterface.CheckWindow(78) )
			{
				pSetCursorFocus = true;
			}
		}

		if( gRenderMap.DataMap.ModelID != -1 && MiniMap )
		{
			if(pCheckMouseOver(gRenderMap.DataMap.XSW_Minimap, gRenderMap.DataMap.YSW_Minimap, 128, 128))
			{
				pSetCursorFocus = true;
			}
		}

		if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 )
		{
			if( pCheckMouseOver(2, 31, Return2X(TransForX(74)), 20) )
			{
				pSetCursorFocus = true;
			}
		}

		if( jCRenderRuud.OpeningRuud && pCheckWindow(pWindowThis(), 13) )
		{
			if( pCheckMouseOver(1, 0, Return2X( Width ), 429) )
			{
				pSetCursorFocus = true;
			}
		}

		if( jCRenderRuud.OpeningRuud && jCRenderRuud.OpenWindowConfirm && pCheckWindow(pWindowThis(), 13) )
		{
			pSetCursorFocus = true;
		}
	}
	return 640;
}

int CameraGuiReset()
{
	int v49; // eax@55
	signed int v52; // [sp+0h] [bp-4h]@11

	pSetCursorFocus = false;
	
	if(gInterface.Data[eMenu_MAIN].OnShow||
		gInterface.Data[eMenu_MAINTWO].OnShow||
		gInterface.Data[eVip_MAIN].OnShow||
		gInterface.Data[eEventTimePANEL_MAIN].OnShow||
		gInterface.Data[eCommand_MAIN].OnShow||
		gInterface.Data[eRankPANEL_MAIN].OnShow||
		gInterface.Data[eCONFIRM_MAIN].OnShow||
		gInterface.Data[ePARTYSETTINGS_MAIN].OnShow||
		gInterface.Data[ePARTYSEARCH_MAIN].OnShow ||
		gInterface.Data[eVAULT_MAIN].OnShow||
		gInterface.Data[eCHANGINGCLASS_MAIN].OnShow||
		gInterface.Data[eCHANGE_RESET_MAIN].OnShow||
		gInterface.Data[eLuckyWheelMain].OnShow||
		gInterface.Data[eSMITH_MAIN].OnShow||
		gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow||
		gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow||
		gInterface.Data[eTUCHAN_MAIN].OnShow||
		gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow||
		gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		pSetCursorFocus = true;
	}

	if ( pCheckWindow(pWindowThis(), 13) && pCheckWindow(pWindowThis(), 16) //-- 13 & 16
	|| pCheckWindow(pWindowThis(), 8) //-- 8
	|| pCheckWindow(pWindowThis(), 12) //-- 12
	|| pCheckWindow(pWindowThis(), 9) //-- 9
	|| pCheckWindow(pWindowThis(), 7) //-- 7
	|| pCheckWindow(pWindowThis(), 14) //-- 14
	|| pCheckWindow(pWindowThis(), 15) //-- 15
	|| pCheckWindow(pWindowThis(), 60) //-- 60
	|| pCheckWindow(pWindowThis(), 76)) //-- 76
	{
		v52 = 260;
	}
	else
	{
		if ( pCheckWindow(pWindowThis(), 16)
			&& pCheckWindow(pWindowThis(), 4)
			|| pCheckWindow(pWindowThis(), 69))
		{
			v52 = 260;
		}
		else
		{
			if ( pCheckWindow(pWindowThis(), 16) && pCheckWindow(pWindowThis(), 11) )
			{
				v52 = 260;
			}
			else
			{
			if ( pCheckWindow(pWindowThis(), 27) )
			{
				v52 = 260;
			}
			else
			{
				if ( pCheckWindow(pWindowThis(), 13)
				|| (pCheckWindow(pWindowThis(), 16))
				|| (pCheckWindow(pWindowThis(), 3))
				|| (pCheckWindow(pWindowThis(), 21))
				|| (pCheckWindow(pWindowThis(), 6))
				|| (pCheckWindow(pWindowThis(), 22))
				|| (pCheckWindow(pWindowThis(), 23))
				|| (pCheckWindow(pWindowThis(), 24))
				|| (pCheckWindow(pWindowThis(), 4))
				|| (pCheckWindow(pWindowThis(), 18))
				|| (pCheckWindow(pWindowThis(), 10))
				|| (pCheckWindow(pWindowThis(), 5))
				|| (pCheckWindow(pWindowThis(), 25))
				|| (pCheckWindow(pWindowThis(), 26))
				|| (pCheckWindow(pWindowThis(), 19))
				|| (pCheckWindow(pWindowThis(), 20))
				|| (pCheckWindow(pWindowThis(), 58))
				|| (pCheckWindow(pWindowThis(), 59))
				|| (pCheckWindow(pWindowThis(), 62))
				|| (pCheckWindow(pWindowThis(), 73))
				|| (pCheckWindow(pWindowThis(), 68))
				|| (pCheckWindow(pWindowThis(), 69))
				|| (pCheckWindow(pWindowThis(), 70))
				|| (pCheckWindow(pWindowThis(), 66))
				|| (pCheckWindow(pWindowThis(), 75))
				|| (pCheckWindow(pWindowThis(), 74)) )
				{
					v52 = 450;
				}
				else
				{
				if ( pCheckWindow(pWindowThis(), 79) )
				{
					if ( pCheckWindow(pWindowThis(), 80) )
						v52 = 260;
					else
						v52 = 450;
				}
				else
				{
					v52 = 640;
				}
				}
			}
			}
		}
	}
	if ( pCheckWindow(pWindowThis(), 77) )
	{
		v49 = sub_861A60((int)pWindowThis());
		if ( sub_7D6270(v49, 0) )
			v52 = 70;
		else
			v52 = 260;
	}
	else
	{
		if ( pCheckWindow(pWindowThis(), 78) )
			v52 = 70;
	}

	if( gRenderMap.DataMap.ModelID != -1 && MiniMap )
	{
		if(pCheckMouseOver(gRenderMap.DataMap.XSW_Minimap_Frame, gRenderMap.DataMap.YSW_Minimap_Frame, 154, 162))
		{
			pSetCursorFocus = true;
		}
	}

	int Width = TransForX( 190 );

	if( jCRenderRuud.OpeningRuud && pCheckWindow(pWindowThis(), 13) )
	{
		if( pCheckMouseOver(1, 0, Return2X( Width ), 429) )
		{
			pSetCursorFocus = true;
		}
	}

	if( jCRenderRuud.OpeningRuud && jCRenderRuud.OpenWindowConfirm && pCheckWindow(pWindowThis(), 13) )
	{
		pSetCursorFocus = true;
	}


	return v52;
}


void Centralizado::PrintDropBox(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	EnableAlphaTest(1);

	glColor4f(0.0, 0.0, 0.0, 0.80000001);
	pDrawBarForm(PosX, PosY, Width, Height, Arg5, Arg6); //central

	float RightX = PosX - 8.0f;
	float LeftX = (PosX + Width) - 8.0f;
	float TopY = PosY - 8.0f;
	float DownY = (PosY + Height) - 8.0f;
	bool horizontal = true;
	bool vertical = true;
	//--
	float IniciarX = PosX - 8.0f;
	float w = 16.0f;
	//--
	float IniciarY = PosY - 8.0f;
	float H = 16.0f;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	while(vertical || horizontal)
	{
		if(vertical)
		{
			IniciarX += 16.0f;

			if((IniciarX + w) > LeftX)
			{
				vertical = false;
				w = LeftX - IniciarX;
			}
			pDrawGUI(71512, IniciarX, TopY, w, 16.0f); //arriba

			pDrawGUI(71517, IniciarX, DownY, w, 16.0f); //abajo
		}
		//-- abajo
		if(horizontal)
		{
			IniciarY += 16.0f;

			if((IniciarY + H) > DownY)
			{
				horizontal = false;
				H = DownY - IniciarY;
			}

			pDrawGUI(71514, RightX, IniciarY, 16.0f, H); // Lado Izquierdo

			pDrawGUI(71515, LeftX, IniciarY, 16.0f, H); //Lado Derecho
		}
	}

	pDrawGUI(71511, RightX, TopY, 16.0f, 16.0f); //esquina arriba izquierda

	pDrawGUI(71513, LeftX, TopY, 16.0f, 16.0f); //esquina arriba derecha

	pDrawGUI(71516, RightX, DownY, 16.0f, 16.0f);  //esquina abajo izquierda

	pDrawGUI(71518, LeftX, DownY, 16.0f, 16.0f);  //esquina abajo derecha

	pGLSwitch();
	EnableAlphaTest(0);
}

void RenderSellItem()
{
	//-- PostItem
	if (gPostInterface.item_post_ && pCursorX < 180)
	{
		gPostInterface.DrawItemToolTipText(gPostInterface.item_post_, 320, 150);

		if (gPostInterface.last_tickcount_view_ + 100 < GetTickCount())
		{
			gPostInterface.item_post_ = nullptr;
		}
	}
}

void Centralizado::RenderGame()
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::GameProcess)
	{
		RenderSellItem();
	}
	else if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{
		if(gProtect.m_MainInfo.SelectCharS13 == 1)
		{
			gCSCharacterS13.SelectChar();
		}
	}

	gCentral.RenderCursor();
}


bool Centralizado::EventPushCursor(int x, int y, int w, int h)
{
	if ( pCheckMouseOver(x, y, w, h) )
	{
		if( *(BYTE*)0x8793386 )
		{
			if (GetTickCount() >= this->TimerPush + 200) 
			{
				this->TimerPush = GetTickCount();
				return true;
			}
		}
	}
	return false;
}

void EventPanelOption()
{
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	x = (double)*(signed int *)(This + 16);
	y = (double)*(signed int *)(This + 20);

	if ( gCentral.EventPushCursor(x + 140, y + 37, 15, 15) )
	{
		HPMonster = !HPMonster;

		if(HPMonster != 0)
			WritePrivateProfileStringA("Setting","HPMonster","1","./Settings.ini");
		else
			WritePrivateProfileStringA("Setting","HPMonster","0","./Settings.ini");
	}
	//--
	if ( gCentral.EventPushCursor(x + 140, y + 57, 15, 15) )
	{
		TimerBar = !TimerBar;

		if(TimerBar != 0)
			WritePrivateProfileStringA("Setting","TimerBar","1","./Settings.ini");
		else
			WritePrivateProfileStringA("Setting","TimerBar","0","./Settings.ini");
	}
	//--
	if ( gCentral.EventPushCursor(x + 140, y + 77, 15, 15) )
	{
		MiniMap = !MiniMap;

		if(MiniMap != 0)
			WritePrivateProfileStringA("Setting","MiniMap","1","./Settings.ini");
		else
			WritePrivateProfileStringA("Setting","MiniMap","0","./Settings.ini");
	}
}

void RenderWindowsOption(int a1)
{
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	*(signed int *)(This + 16) = 320 - (230 / 2);
	x = (double)*(signed int *)(This + 16);
	y = (double)*(signed int *)(This + 20);

	gCentral.PrintDropBox(x, y, 230, 310, 0, 0);

	pSetFont(pTextThis(), (int)pFontBigBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen
	pDrawText(pTextThis(), x, y + 10, "Game Options", 230, 0, (LPINT) 3, 0);

	RenderBitmap(71520, x + 15, y + 30, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);
//--
	for ( int k = 0; k < 6; k++ )
	{
		gCentral.JCOption[ k ].mouseClicked( );
	}
	EventPanelOption();
//--
	sub_779410((char *)(This + 24), x + 85, y + 280, 60, 22);

	if( CheckButtonPressed( x + 85, y + 280, 60, 22))
	{
		RenderBitmap(71521, x + 85, y + 280, 60, 22, 0.01, 0.4499999583, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71521, x + 85, y + 280, 60, 22, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
	pSetFont(pTextThis(), (int) pFontNormal);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pDrawText(pTextThis(), x + 85, y + 286, pGetTextLine(pTextLineThis, 1108), 60, 0,(LPINT) 3, 0); //-- Closed
}

void RenderOptionText(int a1)
{
	int This; // [sp+74h] [bp-4h]@1
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1
	char buffer[255]; // ST08_4@1

	This = *(DWORD *)(GetInstance() + 160);
	
	x = (double)*(signed int *)(This + 16);
	y = (double)*(signed int *)(This + 20);

	pSetFont(pTextThis(), (int) pFontNormal);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	sub_4200F0_Addr(pTextThis(), 0);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

	pDrawText(pTextThis(), x + 45, y + 40, pGetTextLine(pTextLineThis, 386), 0, 0,(LPINT) 1, 0); //-- Attack Automatic

	pDrawText(pTextThis(), x + 45, y + 60, pGetTextLine(pTextLineThis, 387), 0, 0,(LPINT) 1, 0); //-- Beep Sound

	pDrawText(pTextThis(), x + 45, y + 80, pGetTextLine(pTextLineThis, 919), 0, 0,(LPINT) 1, 0); //-- Slide Help
	//--
	pDrawText(pTextThis(), x + 158, y + 40, "Show HP Monster", 0, 0,(LPINT) 1, 0); //-- HP Monster

	pDrawText(pTextThis(), x + 158, y + 60, "Show Time Bar", 0, 0,(LPINT) 1, 0); //-- Time Bar

	pDrawText(pTextThis(), x + 158, y + 80, "Show MiniMap", 0, 0,(LPINT) 1, 0); //-- Show MiniMap

	RenderBitmap(71520, x + 15, y + 98, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);
//-- Sound
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen
	pDrawText(pTextThis(), x , y + 108, pGetTextLine(pTextLineThis, 389), 230, 0, (LPINT)3, 0); //-- Volumen
//-- Divisor
	RenderBitmap(71520, x + 15, y + 150, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);
//-- Effect Limit
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu); //-- eGold
	pDrawText(pTextThis(), x , y + 155, pGetTextLine(pTextLineThis, 1840), 230, 0, (LPINT)3, 0); //-- Effect Limit
//-- Divisor
	RenderBitmap(71520, x + 15, y + 270, 200, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);
}

int OptionBuffer;

void RenderOptionPanel(int a1)
{
	int This; // [sp+74h] [bp-4h]@1
	float x; // [sp+2Ch] [bp-8h]@1
	float y; // ST34_4@1

	This = *(DWORD *)(GetInstance() + 160);
	
	x = (double)*(signed int *)(This + 16);
	y = (double)*(signed int *)(This + 20);
//--
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	pDrawButton(31593, x + 27, y + 37, 15, 15, 0, ( *(BYTE *)( This + 196) ) ? 0.0 : 15.0); //-- Attack Automatic

	pDrawButton(31593, x + 27, y + 57, 15, 15, 0, ( *(BYTE *)( This + 197) ) ? 0.0 : 15.0); //-- Beep Sound
	
	pDrawButton(31593, x + 27, y + 77, 15, 15, 0, ( *(BYTE *)( This + 198) ) ? 0.0 : 15.0); //-- Slide Show
//--
	pDrawButton(31593, x + 140, y + 37, 15, 15, 0.0, (HPMonster != 0) ? 0.0 : 15.0); //-- HP Monster

	pDrawButton(31593, x + 140, y + 57, 15, 15, 0.0, (TimerBar != 0) ? 0.0 : 15.0); //-- Time Bar

	pDrawButton(31593, x + 140, y + 77, 15, 15, 0.0, (MiniMap != 0) ? 0.0 : 15.0); //-- MiniMap
//-- Volumen
	pDrawButton(71523, x + 27, y + 124, 18, 15, 0, 0);

	pDrawGUI(31596, x + 45, y + 124, 124.0, 16.0);

	if ( *(DWORD *)(This + 200) > 0 )
	{
		pDrawGUI(31597, x + 45, y + 124, (double)*(signed int *)(This + 200) * 12.40000057220459, 16.0);

	//	*(BYTE *)0xE8C2A8 = *(DWORD *)(This + 200);
	}
//--
	int * SystemAntiLag[6] = {&DisableDynamicEffect, &DisableStaticEffect, &DisableSkillEffect, &DisableGlowEffect, &DisableShadow, &DisableObject};

	float JCRenderY = y + 170;
	float JCRenderX = x + 27;

	for ( int k = 0; k < 6; k++ )
	{
		gCentral.JCOption[ k ].SetLocation(JCRenderX, JCRenderY);
		*(int*)SystemAntiLag[ k ] = gCentral.JCOption[ k ].SetVisible( );

		JCRenderY+=20;

		if ( k == 4 )
		{
			JCRenderY = y + 170;
			JCRenderX = x + 140;
		}
	}

	if(OptionBuffer != DisableGlowEffect)
	{
		OptionBuffer = DisableGlowEffect;
		*(DWORD *)(This + 204) = ( DisableGlowEffect != 0) ? 1 : 5;
	}
	pGLSwitch();
	EnableAlphaTest(0);
}

bool CheckOptionMouseOver(int x, int y, int w, int h)
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	x = (double)*(signed int *)(This + 16) - 4;
	y = (double)*(signed int *)(This + 20) - 4;

	return pCheckMouseOver(x, y, 238, 302);
}

bool CheckAttackMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	y = (double)*(signed int *)(This + 20);
	x = (double)*(signed int *)(This + 16);

	return pCheckMouseOver(x + 27, y + 37, 15, 15);
}

bool CheckBeepMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	y = (double)*(signed int *)(This + 20);
	x = (double)*(signed int *)(This + 16);

	return pCheckMouseOver( x + 27, y + 57, 15, 15);
}

bool CheckSlideMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	y = (double)*(signed int *)(This + 20);
	x = (double)*(signed int *)(This + 16);

	return pCheckMouseOver(x + 27, y + 77, 15, 15);
}

bool CheckSoundMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = getWindowConfig_35((int)pWindowThis());

	y = *(DWORD *)(This + 20) + 124;

	return pCheckMouseOver(x, y, w, h);
}

bool CheckEffectMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	/*int This; // [sp+74h] [bp-4h]@1

	This = getWindowConfig_35((int)pWindowThis());

	y = *(DWORD *)(This + 20);*/

	return false;//pCheckMouseOver( x, y + 181, w, h);
}

void RenderPane(DWORD id, float x, float y, float w, float h)
{
	gCentral.PrintDropBox(x, y, w, h, 0, 0);
}

void RenderPane_none(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(31461, x, y, w, h);
}

void RenderPane_Esc(DWORD id, float x, float y, float w, float h)
{
	//char buffer[255]; // [sp+74h] [bp-4h]@1

	h = 250.0;
	w = 230.0;
	x = (MAX_WIN_WIDTH / 2) - (w / 2);
	y = (MAX_WIN_HEIGHT / 2) - (h / 2) - 45;

	gCentral.PrintDropBox(x, y, w, h, 0, 0);
	pSetFont(pTextThis(), (int)pFontBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen
	pDrawText(pTextThis(), x , y + 15, "Game System", 230, 0, (LPINT) 3, 0);

	pDrawGUI(71520, x + (w / 2) - (200 / 2), y + 40, 200, 1); //-- Divisor

	pDrawGUI(71520, x + (w / 2) - (200 / 2), y + 209.5, 200, 1); //-- Divisor
}

__declspec(naked) void RenderEsc_Button01()
{
	static DWORD Addr_JMP = 0x007A8678;

	_asm
	{
		PUSH 71524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0x4C                            ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button02()
{
	static DWORD Addr_JMP = 0x007A86D2;

	_asm
	{
		PUSH 71524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0xA0                            ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button03()
{
	static DWORD Addr_JMP = 0x007A872F;

	_asm
	{
		PUSH 71524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0xF4                            ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button04()
{
	static DWORD Addr_JMP = 0x007A878C;

	_asm
	{
		PUSH 71524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0x148                           ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button05()
{
	static DWORD Addr_JMP = 0x007A87E9;

	_asm
	{
		PUSH 71524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x19C                              ; |
		JMP[Addr_JMP]
	}
}

void RenderPane_OptionMix(DWORD id, float x, float y, float w, float h)
{
	gCentral.PrintDropBox(x, y, w, h, 0, 0);

	pDrawGUI(71520, x + (w / 2) - (200 / 2), y + 30, 200, 1); //-- Divisor
}

__declspec(naked) void RenderMix_Button03()
{
	static DWORD Addr_JMP = 0x007AA39C;

	_asm
	{
		PUSH 71524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x0F4                              ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderMix_Button02()
{
	static DWORD Addr_JMP = 0x007AA331;

	_asm
	{
		PUSH 71524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x0A0                              ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderMix_Button01()
{
	static DWORD Addr_JMP = 0x007AA2C9;

	_asm
	{
		PUSH 71524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x4C                               ; |
		JMP[Addr_JMP]
	}
}

bool InfoOverParty(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, 77, 30);
}

bool MouseBlockParty(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, 77, 43 * pPartyMemberCount);
}

__declspec(naked) void RemoveShadoW()
{
	static DWORD pShadow;
	static DWORD RenderI;
	static DWORD main_addr;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x14]
		MOV RenderI,ECX
		MOV EDX,DWORD PTR SS:[EBP-0x10]
		MOV pShadow,EDX
	}

	if( DisableShadow != 0 )
		pShadow = RenderI;

	main_addr = (RenderI < pShadow) ? 0x0054A325: 0x0054A31F;
	
	_asm
	{
		JMP[main_addr]
	}
}


void Centralizado::InitCentral()
{
	SetCompleteHook(0xE9, 0x0054A319, &RemoveShadoW);

	//--- Panel Option
	SetCompleteHook(0xE8, 0x008490F5, &CheckOptionMouseOver);

	SetCompleteHook(0xE9, 0x008494B0, &RenderWindowsOption);
	SetCompleteHook(0xE9, 0x00849730, &RenderOptionText);
	SetCompleteHook(0xE9, 0x008499E0, &RenderOptionPanel);

	SetCompleteHook(0xE8, 0x00848E5D, &CheckAttackMouseOver);
	SetCompleteHook(0xE8, 0x00848EB2, &CheckBeepMouseOver);
	SetCompleteHook(0xE8, 0x00848F07, &CheckSlideMouseOver);
	SetCompleteHook(0xE8, 0x00848F4B, &CheckSoundMouseOver);
	SetCompleteHook(0xE8, 0x00849087, &CheckEffectMouseOver);
//--
	SetCompleteHook(0xE9, 0x005BB0B0, &this->RenderGame);

	if( gProtect.m_MainInfo.CustomInterfaceType == 3 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		//-- Boton OptionMix
		SetCompleteHook(0xE9, 0x007AA38E, &RenderMix_Button03);
		SetCompleteHook(0xE9, 0x007AA323, &RenderMix_Button02);
		SetCompleteHook(0xE9, 0x007AA2BE, &RenderMix_Button01);
		//-- Ventana OptionMix
		SetCompleteHook(0xE8, 0x007AA4E8, &RenderPane_OptionMix);
		SetCompleteHook(0xE8, 0x007AA53E, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007AA5AA, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007AA5FD, &RenderPane_none);
		//-- Boton Esc
		SetCompleteHook(0xE9, 0x007A87DB, &RenderEsc_Button05);
		SetCompleteHook(0xE9, 0x007A877E, &RenderEsc_Button04);
		SetCompleteHook(0xE9, 0x007A8721, &RenderEsc_Button03);
		SetCompleteHook(0xE9, 0x007A86C4, &RenderEsc_Button02);
		SetCompleteHook(0xE9, 0x007A866D, &RenderEsc_Button01);
		//-- Ventana Esc
		SetCompleteHook(0xE8, 0x007A83A8, &RenderPane_Esc);
		SetCompleteHook(0xE8, 0x007A83FE, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007A846A, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007A84BD, &RenderPane_none);
		//--
		SetCompleteHook(0xE9, 0x005C6E80, &this->MoveRenderCameraDefault);
	}
	else
	{
		SetCompleteHook(0xE9, 0x005C6E80, &CameraGuiReset);
	}
}