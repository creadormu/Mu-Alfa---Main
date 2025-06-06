#include "stdafx.h"
#include "Interface.h"
#include "WindowsStruct.h"
#include "Import.h"
#include "Util.h"
#include "TMemory.h"
#include "Offset.h"
#include "Object.h"
#include "Defines.h"
#include "PrintPlayer.h"
#include "User.h"
#include "SItemOption.h"
#include "Common.h"
#include "Central.h"
#include "StatsAdvance.h"
#include "postInterface.h"
#include "OffTrade.h"
#include "InfoLog.h"
#include "NPCRuud.h"

int MinimizarPet;

//-- Ingresar Dato en resolución 800 x 600

int RetangleInventory(int num)
{
	float Test = 0;

	if( pWinWidthReal <= 1.6 )
	{
		return num;
	}
	else
	{
		Test = num * pWinHeightReal;
		num = Test / pWinWidthReal;
		return num;
	}
}


float TransForX(float num)
{
	return (float) ( pWinWidthReal <= 1.25 ) ? num * pWinWidthReal : num * pWinHeightReal;
}

float TransForY(float num)
{
	return (float) num * pWinHeightReal;
}

float TransFor2X(float num)
{
	return (float) num * pWinWidthReal;
}

float ReturnX(float num)
{
	return (float) ( pWinWidthReal <= 1.25 ) ? num / pWinWidthReal : num / pWinHeightReal;
}

float Return2X(float num)
{
	return (float) num / pWinWidthReal;
}

float ReturnY(float num)
{
	return (float) num / pWinHeightReal;
}

void LoadWindows(DWORD id, float x, float y, float w, float h)
{
	x = TransFor2X( x );
	w = TransFor2X( w );
	y = TransForY( y );
	h = TransForY( h );
	
	RenderBitmap(61526, x, y, w, h, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);
}

void LoadWindowsNone(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(51522, x, y, w, h);
}

bool CheckButtonPressed(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, w, h) && *(BYTE*)0x8793386;
}

void PetMuunHP(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9)
{
	y +=5;
	if( MinimizarPet == 0 )
	{
		RenderBitmap(61545, 2, y + 22, Return2X(TransForX( 74 )), ReturnY(TransForY( 24 )), 0.0, 0.1731800437, 0.75, 0.2378999293,1, 1, 0); //-- Fondo
		
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 5, y + 27, (LPCTSTR)nameIndex, 0, 0, (LPINT)1, 0);

		int v15 = (double)hp / (double)hpmax * 69.0;
		pSetBlend(1);

		if( *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) >= ITEM2(13,200) && *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) <= ITEM2(14, 0) )
		{
			glColor4f(0.811f, 0.4627f, 0.1019, 0.798);
		}
		else
		{
			glColor4f(0.4274, 0.0313, 0.1254, 0.798);
		}
		pDrawBarForm(4, y + 38, Return2X(TransForX( v15 )), ReturnY(TransForY( 4 )), 0, 0);
		pGLSwitch();
		pSetBlend(0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
	}
}

void PetSpiritHP(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9)
{
	y += ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 ) ? 8 : 5;

	if( MinimizarPet == 0 )
	{
		RenderBitmap(61545, 2, y + 22, Return2X(TransForX( 74 )), ReturnY(TransForY( 24 )), 0.0, 0.1731800437, 0.75, 0.2378999293,1, 1, 0); //-- Fondo

		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pDrawText(pTextThis(), 5, y + 27, (LPCTSTR)nameIndex, 0, 0, (LPINT) 1, 0);

		int v15 = (double)hp / (double)hpmax * 69.0;

		pSetBlend(1);
		glColor4f(0.4274, 0.0313, 0.1254, 0.798);

		pDrawBarForm(4, y + 38, Return2X(TransForX( v15 )), 4, 0, 0);
		pGLSwitch();
		pSetBlend(0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
	}
}

signed int __cdecl ColorMoney(unsigned int a1)
{
	signed int color1 = eWhite; // eax@2

	if(a1 >= 1000 && a1 < 1000000)
	{
		color1 = eShinyGreen;
	}
	else if(a1 >= 1000000 && a1 < 10000000)
	{
		color1 = eGold;
	}
	else if(a1 >= 1000000 && a1 < 100000000)
	{
		color1 = eOrange;
	}
	else if(a1 >= 100000000)
	{
		color1 = eRed;
	}
	return color1;
}

__declspec (naked) void RemoveButtonStore1()  //-- ok
{
	static DWORD Addrs = 0x0083BB67;
	
	_asm
	{
		JMP [Addrs]
	}
}

__declspec (naked) void RemoveButtonStore2()  //-- ok
{
	static DWORD Addrs = 0x0083BC07;
	
	_asm
	{
		JMP [Addrs]
	}
}

signed int __cdecl sub_5C1130(unsigned int a1)
{
	signed int result; // eax@2

	if ( a1 < 0x989680 )
	{
		if ( a1 < 0xF4240 )
		{
			if ( a1 < 0x186A0 )
				result = -6890241;
			else
				result = -15152896;
		}
		else
		{
			result = -16738561;
		}
	}
	else
	{
		result = -16776961;
	}
	return result;
}

void RenderWindowsGensBattle(int a1)	//-- incompleto
{
	float y; // ST08_4@1
	float x; // ST04_4@1

	y = (double)*(signed int *)(a1 + 20);
	x = (double)*(signed int *)(a1 + 16);
	pDrawGUI(61526, x, y, 190.0, 429.0);
}

void EventMuOffhelper(DWORD Event)
{
	if((GetTickCount() - gInterface.Data[ButtonStartAttack].EventTick) < 1000)
	{
		return;
	}

	if( gInterface.IsWorkZone(ButtonStartAttack) )
	{
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[ButtonStartAttack].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[ButtonStartAttack].OnClick = false;
		
		// ----
		gInterface.Data[ButtonStartAttack].EventTick = GetTickCount();
		// ----
	}
}

void RenedrBarFormat(float x, float y, float w, float h, float R, float G, float B, float Alpha)
{
	pSetBlend(true);
	glColor4f(R, G, B, Alpha);
	pDrawBarForm(x, y, w, h, 0, 0); //central
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	//gInterface.DrawFormat(eBlue, x + w - 10, y + 2, 10, 1, "-");
}

void RebuildInformationRate(int Info, int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0)
		wsprintf(v10, "%d%%", Info);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

void RebuildInformationRate(int Info, int Info2, int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0 || Info2 > 0)
		wsprintf(v10, "%d%% - %d%%", Info, Info2);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

void RebuildInformation(int Info, int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0)
		wsprintf(v10, "%d", Info);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

void RebuildInformation(int Info, int Info2,int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0 || Info2 > 0)
		wsprintf(v10, "%d - %d", Info, Info2);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

void SetPrintf(char * DrawText, int x, int y, int nCount, int Aling)
{
	pDrawText(pTextThis(), x, y, DrawText, nCount, 0, (LPINT)Aling, 0);
}

void PrintAdvanceStatus(int x, int y)
{
	int v5; // al@1
	int v6; // al@1
	int Width; // al@1
	char v10[50]; // ST08_4@6
	
	v6 = 11;
	Width = 115;
	gInterface.DrawFormat(eShinyGreen, x + 8, 56, 170, 1, "ADVANCED STATUS");

	pSetFont(pTextThis(), (int)pFontBold);
	sub_4200F0_Addr(pTextThis(), 0);
	//-- Lado Izquierdo
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	v5 = y + 80; //-- 1
	SetPrintf("· Total Dmg Reflect", x, v5, Width, 1);
	v5+= v6; //-- 2
	SetPrintf("· Full Dmg Reflect Rate", x, v5, Width, 1);
	v5+= v6; //-- 3
	SetPrintf("· Crit Dmg Rate", x, v5, Width, 1);
	v5+= v6; //-- 4
	SetPrintf("· Crit Dmg (PVM)", x, v5, Width, 1);
	v5+= v6; //-- 5
	SetPrintf("· Crit Dmg (PVP)", x, v5, Width, 1);
	v5+= v6; //-- 6
	SetPrintf("· Exellent Dmg Rate", x, v5, Width, 1);
	v5+= v6; //-- 7
	pDrawText(pTextThis(), x, v5, "· Exellent Dmg (PVM)", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 8
	pDrawText(pTextThis(), x, v5, "· Exellent Dmg (PVP)", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 9
	pDrawText(pTextThis(), x, v5, "· Double Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 10
	pDrawText(pTextThis(), x, v5, "· Triple Dmg Rate:", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 11
	pDrawText(pTextThis(), x, v5, "· Dmg Reduction Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 12
	pDrawText(pTextThis(), x, v5, "· Shield Skill Dmg Redc Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 13
	pDrawText(pTextThis(), x, v5, "· SD Dmg Reduction Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 14
	pDrawText(pTextThis(), x, v5, "· SD Decrease Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 15
	pDrawText(pTextThis(), x, v5, "· Ignore Def Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 16
	pDrawText(pTextThis(), x, v5, "· Ignore SD Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 17
	pDrawText(pTextThis(), x, v5, "· Inc Dmg PvP", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 18
	pDrawText(pTextThis(), x, v5, "· Inc Def PvP", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 19
	pDrawText(pTextThis(), x, v5, "· Resist Double Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 20
	pDrawText(pTextThis(), x, v5, "· Resist Ignore Def Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 21
	pDrawText(pTextThis(), x, v5, "· Resist Ignore SD Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 22
	pDrawText(pTextThis(), x, v5, "· Resist Crit Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 23
	pDrawText(pTextThis(), x, v5, "· Resist Exellent Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 24
	pDrawText(pTextThis(), x, v5, "· Resist Stum Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 25
	pDrawText(pTextThis(), x, v5, "· Ice Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 26
	pDrawText(pTextThis(), x, v5, "· Poison Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 27
	pDrawText(pTextThis(), x, v5, "· Lighting Ince / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 28
	pDrawText(pTextThis(), x, v5, "· Fire Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 29
	pDrawText(pTextThis(), x, v5, "· Earth Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	/*v5+= v6; //-- 30
	pDrawText(pTextThis(), x, v5, "· Wind Inc / Resist Rate", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 31
	pDrawText(pTextThis(), x, v5, "· Water Inc / Resist Rate", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 32
	pDrawText(pTextThis(), x, v5, "· HP Restore Rate (Def, Att)", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 33
	pDrawText(pTextThis(), x, v5, "· MP Rest Rate (Def, Att)", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 34
	pDrawText(pTextThis(), x, v5, "· SD Rest Rate (Def, Att)", 100, 0, (LPINT)1, 0);*/
	
	//-- Lado Derecho
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	v5 = y + 80; //-- 1
	int xN = x + 120;
	RebuildInformationRate(g_StatsAdvance.m_Data.TotalDamageReflect, xN, v5);
	v5+= v6; //-- 2
	RebuildInformationRate(g_StatsAdvance.m_Data.FullDamageReflectRate, xN, v5);
	v5+= v6; //-- 3
	RebuildInformationRate(g_StatsAdvance.m_Data.CriticalDamageRate, xN, v5);
	v5+= v6; //-- 4
	RebuildInformation(g_StatsAdvance.m_Data.CriticalDamagePVM, xN, v5);
	v5+= v6; //-- 5
	RebuildInformation(g_StatsAdvance.m_Data.CriticalDamagePVP, xN, v5);
	v5+= v6; //-- 6
	RebuildInformationRate(g_StatsAdvance.m_Data.ExellentDamageRate, xN, v5);
	v5+= v6; //-- 7
	RebuildInformation(g_StatsAdvance.m_Data.ExellentDamagePVM, xN, v5);
	v5+= v6; //-- 8
	RebuildInformation(g_StatsAdvance.m_Data.ExellentDamagePVP, xN, v5);
	v5+= v6; //-- 9
	RebuildInformationRate(g_StatsAdvance.m_Data.DoubleDamageRate, xN, v5);
	v5+= v6; //-- 10
	RebuildInformationRate(g_StatsAdvance.m_Data.TripleDamageRate, xN, v5);
	v5+= v6; //-- 11
	RebuildInformationRate(g_StatsAdvance.m_Data.DamageReductionRate, xN, v5);
	v5+= v6; //-- 12
	RebuildInformationRate(g_StatsAdvance.m_Data.ShieldSkillDamageReductionRate, xN, v5);
	v5+= v6; //-- 13
	RebuildInformationRate(g_StatsAdvance.m_Data.SDDamageReductionRate, xN, v5);
	v5+= v6; //-- 14
	RebuildInformationRate(g_StatsAdvance.m_Data.SDDecreaseDamageRate, xN, v5);
	v5+= v6; //-- 15
	RebuildInformationRate(g_StatsAdvance.m_Data.IgnoreDefenceRate, xN, v5);
	v5+= v6; //-- 16
	RebuildInformationRate(g_StatsAdvance.m_Data.IgnoreSDRate, xN, v5);
	v5+= v6; //-- 17
	RebuildInformation(g_StatsAdvance.m_Data.IncreaseDamagePvP, xN, v5);
	v5+= v6; //-- 18
	RebuildInformation(g_StatsAdvance.m_Data.IncreaseDefencePvP, xN, v5);
	v5+= v6; //-- 19
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistDoubleDamageRate, xN, v5);
	v5+= v6; //-- 20
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistIgnoreDefenceRate, xN, v5);
	v5+= v6; //-- 21
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistIgnoreSDRate, xN, v5);
	v5+= v6; //-- 22
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistCriticalDamageRate, xN, v5);
	v5+= v6; //-- 23
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistExellentDamageRate, xN, v5);
	v5+= v6; //-- 24
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistStumRate, xN, v5);
	v5+= v6; //-- 25
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseIce, g_StatsAdvance.m_Data.ResistIce, xN, v5);
	v5+= v6; //-- 26
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreasePoison, g_StatsAdvance.m_Data.ResistPoison, xN, v5);
	v5+= v6; //-- 27
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseLighting, g_StatsAdvance.m_Data.ResistLighting, xN, v5);
	v5+= v6; //-- 28
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseFire, g_StatsAdvance.m_Data.ResistFire, xN, v5);
	v5+= v6; //-- 29
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseEarth, g_StatsAdvance.m_Data.ResistEarth, xN, v5);
	/*
	this->DrawLine(flDrawX, flDrawY, flWidth, "Wind Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseWind, this->m_Data.ResistWind);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Water Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseWater, this->m_Data.ResistWater);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full HP Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullHPRestoreRateDef, this->m_Data.FullHPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full MP Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullMPRestoreRateDef, this->m_Data.FullMPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full SD Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullSDRestoreRateDef, this->m_Data.FullSDRestoreRate);*/
}

//----- (0077F1D0) 
void CharacterInfoWindow(int a1)
{
	float y; // ST0C_4@1
	float RenderY; // ST0C_4@1
	float x; // ST08_4@1
	int This; // [sp+8Ch] [bp-10h]@1
	HGDIOBJ v4; // ST18_4@1
	int v5; // al@1
	char v10[256]; // ST08_4@6
	int v56; // [sp+8h] [bp-23Ch]@18
	int v65; // [sp+240h] [bp-4h]@16
	char v587; // [sp+3E2h] [bp-5D6h]@6
	int v602; // [sp+458h] [bp-560h]@6
	int v607; // [sp+56Ch] [bp-44Ch]@6
	int v614; // [sp+6A4h] [bp-314h]@6
	char v626; // [sp+82Fh] [bp-189h]@6
	int v639; // [sp+984h] [bp-34h]@46
	int v640; // [sp+988h] [bp-30h]@157
	char *v644; // [sp+998h] [bp-20h]@6
	int v650; // [sp+9B0h] [bp-8h]@6
	float v16; // ST34_4@1
	unsigned __int8 v17; // ST18_1@1
	unsigned __int8 v22; // ST18_1@1
	float v35; // [sp+338h] [bp-4h]@1
	
	This = getCharacterInfo((int)pWindowThis());
	
	*(signed int *)(This + 16) = 1;

	x = (double)*(signed int *)(This + 16);
	y = (double)*(signed int *)(This + 20);
	int widht;

	if( g_StatsAdvance.m_Enable )
	{
		if( CheckButtonPressed(x + 410, y + 206, 15, 10) )
		{
			g_StatsAdvance.m_Enable = false;
		}
	}
	else
	{
		if( CheckButtonPressed(x + 210, y + 206, 15, 10) )
		{
			g_StatsAdvance.m_Enable = true;
		}
	}

	if( g_StatsAdvance.m_Enable )
	{
		widht = 423;
		pDrawGUI(61538, x, y, 426.0f, 422.0f);
		PrintAdvanceStatus(x + 222, y);
	}
	else
	{
		widht = 213;
		pDrawGUI(61532, x, y, 225, 422.0);
	}

	pSetFont(pTextThis(), (int)pFontBold);
	sub_4200F0_Addr(pTextThis(), 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 45));
	pDrawText(pTextThis(), x + 15, y + 60, v10, 50, 0, (LPINT)3, 0);


	v16 = *(float*)0x5EF5A1C * 0.001000000047497451;
	v35 = Convert(v16) + 1.0;
	v17 = (signed int)((2.0 - v35) * 127.0);

	//-- TitleName 1
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, v17);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s", (const char *)(*(DWORD*)0x8128AC8));
	pDrawText(pTextThis(), x, y + 27, v10, widht, 0, (LPINT)3, 0);
	//-- TitleName 2
	v22 = (signed int)(v35 * 127.0);
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, v22);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10,  pGetTextLine(pTextLineThis, 126));
	pDrawText(pTextThis(), x, y + 27, v10, widht, 0, (LPINT)3, 0);

	//-- Button Pet
	sub_779410((char *)(This + 1228), x + 85, y + 53, 43, 17);
	if( CheckButtonPressed(x + 85, y + 53, 43, 17) || pCheckWindow(pWindowThis(), PetInfo))
	{
		RenderBitmap(61535, x + 85, y + 53, 43, 17, 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, x + 85, y + 53, 43, 17, 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}//-- over 0.4460069239
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1217));// Pet
	pDrawText(pTextThis(), x + 85, y + 56, v10, 43, 0, (LPINT)3, 0);

	//-- Button MasterSkill
	sub_779410((char *)(This + 1400), x + 135, y + 53, 43, 17);
	if( CheckButtonPressed(x + 135, y + 53, 43, 17) )
	{
		RenderBitmap(61535, x + 135, y + 53, 43, 17, 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, x + 135, y + 53, 43, 17, 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}//-- Click 0.2235384732
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1300));
	pDrawText(pTextThis(), x + 135, y + 56, v10, 43, 0, (LPINT)3, 0);

	//-- Class
	RenderY = y + 80;
	v5 = sub_587620(*(BYTE *)(*(DWORD*)0x8128AC8 + 11));
	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1973));
	pDrawText(pTextThis(), x + 20, RenderY, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s", (const char *) v5);
	pDrawText(pTextThis(), x + 100, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Reset
	RenderY += 11;
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pDrawText(pTextThis(), x + 20, RenderY, "Reset", 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d", ViewReset);
	pDrawText(pTextThis(), x + 100, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Level
	RenderY += 11;
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 368));
	pDrawText(pTextThis(), x + 20, RenderY, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d", *(WORD *)(*(DWORD*)0x8128AC8 + 14));
	pDrawText(pTextThis(), x + 100, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Server Name
	RenderY += 11;
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1022));
	pDrawText(pTextThis(), x + 20, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Divisor
	pSetBlend(1);
	RenderBitmap(71520, x + 8, y + 127, 195, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);
	glEnable(0xDE1u);
	pGLSwitch();

	//-- Point Stats
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 682));
	pDrawText(pTextThis(), x + 20, y + 132, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d", ViewPoint);
	pDrawText(pTextThis(), x + 100, y + 132, v10, 90, 0, (LPINT)1, 0);
	//-- Fruit Create
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s %s", pGetTextLine(pTextLineThis, 1901), pGetTextLine(pTextLineThis, 1412));
	pDrawText(pTextThis(), x + 20, y + 143, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d/%d", *(WORD *)(*(DWORD*)0x8128AC8 + 76), *(WORD *)(*(DWORD*)0x8128AC8 + 78));
	pDrawText(pTextThis(), x + 100, y + 143, v10, 90, 0, (LPINT)1, 0);

	if ( (signed int)*(WORD *)(*(DWORD*)0x8128AC8 + 76) > 10 )
	{
		v56 = 0;
		if ( *(WORD *)(*(DWORD*)0x8128AC8 + 78) )
			v56 = 100 * *(WORD *)(*(DWORD*)0x8128AC8 + 76) / *(WORD *)(*(DWORD*)0x8128AC8 + 78);
		if ( v56 > 10 )
		{
			if ( v56 <= 10 || v56 > 30 )
			{
				if ( v56 <= 30 || v56 > 50 )
				{
					if ( v56 > 50 )
					v65 = 40;
				}
				else
				{
					v65 = 50;
				}
			}
			else
			{
				v65 = 60;
			}
		}
		else
		{
			v65 = 70;
		}
	}
	else
	{
		v65 = 100;
	}
	pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "(%d%%)", v65);
	pDrawText(pTextThis(), x + 157, y + 143, v10, 35, 0, (LPINT)4, 0);
	//-- Fruis Decrease
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s %s", pGetTextLine(pTextLineThis, 1901), pGetTextLine(pTextLineThis, 1903));
	pDrawText(pTextThis(), x + 20, y + 154, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d/%d", *(WORD *)(*(DWORD*)0x8128AC8 + 80), *(WORD *)(*(DWORD*)0x8128AC8 + 82));
	pDrawText(pTextThis(), x + 100, y + 154, v10, 90, 0, (LPINT)1, 0);
	
	if ( (signed int)*(WORD *)(*(DWORD*)0x8128AC8 + 80) > 10 )
	{
		v56 = 0;
		if ( *(WORD *)(*(DWORD*)0x8128AC8 + 82) )
			v56 = 100 * *(WORD *)(*(DWORD*)0x8128AC8 + 80) / *(WORD *)(*(DWORD*)0x8128AC8 + 82);
		if ( v56 > 10 )
		{
			if ( v56 <= 10 || v56 > 30 )
			{
				if ( v56 <= 30 || v56 > 50 )
				{
					if ( v56 > 50 )
					v65 = 40;
				}
				else
				{
					v65 = 50;
				}
			}
			else
			{
				v65 = 60;
			}
		}
		else
		{
			v65 = 70;
		}
	}
	else
	{
		v65 = 100;
	}
	pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "(%d%%)", v65);
	pDrawText(pTextThis(), x + 157, y + 154, v10, 35, 0, (LPINT)4, 0);

	v639 = pGetCharClass(*(BYTE *)(*(DWORD*)0x7BC4F04 + 19));
	v640 =  x + 90;
int v6400 = x + 23;
//-- STR
	RenedrBarFormat(v6400, y + 185 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 24), v640, y + 185, 10, 10);
	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 185, 10, 10) )
		{
			RenderBitmap(61533, v640, y + 185, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61533, v640, y + 185, 10, 10, 0, 0.0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- AGI
	RenedrBarFormat(v6400, y + 230 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 196), v640, y + 230, 10, 10);
	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 230, 10, 10) )
		{
			RenderBitmap(61533, v640, y + 230, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61533, v640, y + 230, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- Tercer TomO VIT
	RenedrBarFormat(v6400, y + 290 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 368), v640, y + 290, 10, 10);
	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 290, 10, 10) )
		{
			RenderBitmap(61533, v640, y + 290, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61533, v640, y + 290, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- CUARTO TomO ENE
	RenedrBarFormat(v6400, y + 335 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 540), v640, y + 335, 10, 10);

	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 335, 10, 10) )
		{
			RenderBitmap(61533, v640, y + 335, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61533, v640, y + 335, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- QUINTO TomO COMMAND
	if ( v639 == 4 )
	{
		RenedrBarFormat(v6400, y + 380 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
		//-- Botton Subir Punto
		sub_779410((char *)(This + 712), v640, y + 380, 10, 10);
		if ( ViewPoint > 0 )
		{
			if( CheckButtonPressed( v640, y + 380, 10, 10) )
			{
				RenderBitmap(61533, v640, y + 380, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
			}
			else
			{
				RenderBitmap(61533, v640, y + 380, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
			}
		}
	}
}

__declspec(naked) void InformationSTR1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00780210;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0xA6                                 ; /Arg1 = 000000A6
		MOV ECX,0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 185 //--Y
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX, 29 //--X
		PUSH ECX
		CALL Addr_Call
		MOV ECX, EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationSTR2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00780245;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 50) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 50) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 56
		LEA EDX,DWORD PTR SS:[EBP-0x334]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 185 //--Y
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX, 105 //--X
		PUSH ECX
		CALL Addr_Call
		MOV ECX, EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationSTR3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0078178A;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x138]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,200 //--Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25 //--X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX 
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationSTR4()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00781833;

	_asm
	{
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x138]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 213
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00781947;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0x6A6                                 ; /Arg1 = 000006A6
		MOV ECX, 0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,230 //-- Y
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX,29 //-- X
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX  
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0078197E;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 51) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 52) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA ECX,DWORD PTR SS:[EBP-0x5D0]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 230 //-- Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 105 //-- X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782882;

	_asm
	{
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x290]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 246 //-- Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25
		PUSH EDX
		CALL Addr_Call //-- X
		MOV ECX,EAX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI4()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782A60;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x290]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 259 //--Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25 //--X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX 
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI5()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_Call2 = 0x00420150;
	static DWORD Addr_JMP = 0x00782BC5;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x290]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 272 //-- Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25 //-- X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                          ; |
		CALL Addr_Call2                      ; \main1.00420150
		MOV EAX,DWORD PTR DS:[0xE8C58C]
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                          ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00782D4F;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0xA9                                 ; /Arg1 = 000000A9
		MOV ECX, 0x08128ADC                   ; |
		CALL Addr_STR                            ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 290 //-- Y
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX, 29 //-- X
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX    
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782D87;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 52) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 130)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 155) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 54) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA EDX,DWORD PTR SS:[EBP-0x558]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX, 290 //-- Y
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX, 105 //-- X
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782F99;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x558]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 305
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT4()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0078300F;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x558]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 318
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationENE1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00783129;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0xA8                                 ; /Arg1 = 000000A8
		MOV ECX,0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX, 335
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX, 29
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationENE2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00783160;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 53) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 56) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA ECX,DWORD PTR SS:[EBP-0x438]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,335
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 105
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationENE3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00783305;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x438]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 350
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoMagicDMG1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00784043;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,363
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25
		PUSH EDX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoMagicDMG2()
{
	static DWORD Addr_JMP = 0x00784847;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,376
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25
		PUSH EDX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG1()
{
	static DWORD Addr_JMP = 0x007848BF;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 363
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG2()
{
	static DWORD Addr_JMP = 0x0078491E;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,376
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG3()
{
	static DWORD Addr_JMP = 0x0078498D;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,363
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG4()
{
	static DWORD Addr_JMP = 0x007849FE;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,363
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG5()
{
	static DWORD Addr_JMP = 0x00784A7E;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,376
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25
		PUSH EDX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationCMD1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00784BA7;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0x76C                                 ; /Arg1 = 0000076C
		MOV ECX, 0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECx+0X14]
		ADD EDX,380
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationCMD2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00784BDF;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 54) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 62) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA EDX,DWORD PTR SS:[EBP-0x8A0]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,380
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX,105
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; 
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationServer1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0077F8FF;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InformationServer2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0077FA51;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InformationServer3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0077FAD7;

	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 4
		PUSH 0
		PUSH 130
		LEA EDX,DWORD PTR SS:[EBP-0x108]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x31C]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX, 113
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x31C]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX, 62
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP[Addr_JMP]
	}
}

void WindowsInfoInventory(int a1)
{
//-- NPC RUUD
//=============================
	jCRenderRuud.OpenRuud();
//=============================
	float x; // ST08_4@1
	float y; // ST04_4@1
	int This; // ST24_4@1
	char v10[255]; // ST24_4@1
	unsigned int v23; // [sp+128h] [bp-4h]@1
	char v22[260]; // [sp+24h] [bp-108h]@1
	int v15; // ST18_4@1
	int v639; // ST18_4@1

	This = GetInventory(GetInstance());
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	if ( pCheckWindow(pWindowThis(), Character) )
	{
		*(signed int *)(This + 36) = Return2X(TransFor2X(640) - Width);
	}
	else
	{
		*(signed int *)(This + 36) = Return2X(TransFor2X(640) - Width);
	}
	x = TransFor2X((double)*(signed int *)(This + 36));
	y = TransForY((double)*(signed int *)(This + 40));

	//--
	int ModelId = 61522;

	v639 = pGetCharClass(*(BYTE *)(*(DWORD*)0x7BC4F04 + 19));

	if ( v639 == 6 )
	{
		ModelId = 61524;
	}
	else if ( v639 == 3 )
	{
		ModelId = 61523;
	}

	RenderBitmap(ModelId, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 3425));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v10, Return2X(Width), 0, (LPINT)3, 0);
	//-- Cerrar
	ChangeButtonInfo((char *)(This + 460), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	if( CheckButtonPressed(Return2X(x + TransForX(158)), Return2X(y + TransForX(28)), Return2X(TransForX(11)), Return2X(TransForX(11))) )
	{
		RenderBitmap(61529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.0, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	//-- pet
	*(DWORD *)(This + 204) = Return2X(x + TransForX(19)); //-- X
	*(DWORD *)(This + 208) = ReturnY(y + TransForY(56));//-- Y
	*(DWORD *)(This + 212) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 216) = ReturnY(TransForY(40)); //-- H
	*(DWORD *)(This + 220) = 51522;//-- Texture
	//-- weapon(L)
	*(DWORD *)(This + 44) = Return2X(x + TransForX(19)); //-- X
	*(DWORD *)(This + 48) = ReturnY(y + TransForY(97)); //-- Y
	*(DWORD *)(This + 52) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 56) = ReturnY(TransForY(56)); //-- H
	*(DWORD *)(This + 60) = 51522;
	//-- Gloves
	*(DWORD *)(This + 144) = Return2X(x + TransForX(19)); //-- X
	*(DWORD *)(This + 148) = ReturnY(y + TransForY(154));
	*(DWORD *)(This + 152) = Return2X(TransForX(35));
	*(DWORD *)(This + 156) = ReturnY(TransForY(40));
	*(DWORD *)(This + 160) = 51522;
	//-- helm
	*(DWORD *)(This + 84) = Return2X(x + TransForX(79));
	*(DWORD *)(This + 88) = ReturnY(y + TransForY(56));
	*(DWORD *)(This + 92) = Return2X(TransForX(35));
	*(DWORD *)(This + 96) = ReturnY(TransForY(40));
	*(DWORD *)(This + 100) = 51522;
	//-- Armor
	*(DWORD *)(This + 104) = Return2X(x + TransForX(79));
	*(DWORD *)(This + 108) = ReturnY(y + TransForY(97)); //-- Y
	*(DWORD *)(This + 112) = Return2X(TransForX(35));
	*(DWORD *)(This + 116) = ReturnY(TransForY(56)); //-- H
	*(DWORD *)(This + 120) = 51522;
	//-- Pants
	*(DWORD *)(This + 124) = Return2X(x + TransForX(79));
	*(DWORD *)(This + 128) = ReturnY(y + TransForY(154));
	*(DWORD *)(This + 132) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 136) = ReturnY(TransForY(40)); //-- H
	*(DWORD *)(This + 140) = 51522;
	//-- wings
	*(DWORD *)(This + 184) = Return2X(x + TransForX(117));
	*(DWORD *)(This + 188) = ReturnY(y + TransForY(56));
	*(DWORD *)(This + 192) = Return2X(TransForX(56)); //-- W;
	*(DWORD *)(This + 196) = ReturnY(TransForY(40)); //-- H;
	*(DWORD *)(This + 200) = 51522;
	//-- weapon(R)
	*(DWORD *)(This + 64) = Return2X(x + TransForX(139));
	*(DWORD *)(This + 68) = ReturnY(y + TransForY(97));
	*(DWORD *)(This + 72) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 76) = ReturnY(TransForY(56)); //-- H
	*(DWORD *)(This + 80) = 51522;
	//-- Bootas
	*(DWORD *)(This + 164) = Return2X(x + TransForX(139));
	*(DWORD *)(This + 168) = ReturnY(TransForY(154)); //-- Y
	*(DWORD *)(This + 172) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 176) = ReturnY(TransForY(40)); //-- H
	*(DWORD *)(This + 180) = 51522;
	//-- pendiente
	*(DWORD *)(This + 224) = Return2X(x + TransForX(55));
	*(DWORD *)(This + 228) = ReturnY(TransForY(67)); //-- Y
	*(DWORD *)(This + 232) = Return2X(TransForX(24)); //-- W
	*(DWORD *)(This + 236) = ReturnY(TransForY(24)); //-- H
	*(DWORD *)(This + 240) = 51522;
	// anillo 1
	*(DWORD *)(This + 244) = Return2X(x + TransForX(55));
	*(DWORD *)(This + 248) = ReturnY(TransForY(165)); //-- Y
	*(DWORD *)(This + 252) = Return2X(TransForX(24)); //-- W
	*(DWORD *)(This + 256) = ReturnY(TransForY(24)); //-- H
	*(DWORD *)(This + 260) = 51522;
	//-- anillo 2
	*(DWORD *)(This + 264) = Return2X(x + TransForX(116));
	*(DWORD *)(This + 268) = ReturnY(TransForY(165)); //-- Y
	*(DWORD *)(This + 272) = Return2X(TransForX(24)); //-- W
	*(DWORD *)(This + 276) = ReturnY(TransForY(24)); //-- H
	*(DWORD *)(This + 280) = 51522;
	//-- Pentagrama
//	gPostInterface.DrawItemIMG(Return2X(x + TransForX(135)), ReturnY(TransForY(164)), Return2X(TransForX(35)), ReturnY(TransForY(40)), ITEM(14, 173), 0, 0, 0, 0);
	//--
	int MainSlot = *(DWORD *)(This + 24);
	//-- Inventory
	*(DWORD *)(MainSlot + 44) = 243;
	int t = *(DWORD *)(MainSlot + 56) * RetangleInventory( 17 );
	*(DWORD *)(MainSlot + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	
	if((signed int)(unsigned __int8)SetOption1((int) pUserStat()) <= 0 
		&& (signed int)(unsigned __int8)SetOption2((int) pUserStat()) <= 0 )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
		RenderBitmap(61535, Return2X(x + TransForX(18)), ReturnY(TransForY(194)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		RenderBitmap(61535, Return2X(x + TransForX(18)), ReturnY(TransForY(194)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 385)); //-- Ancestral
	pDrawText(pTextThis(), Return2X(x + TransForX(18)), ReturnY(y + TransForY(198)), v10, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	
	//-- socket
	if ( !sub_969000((void *)0x986C1B8) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
		RenderBitmap(61535, Return2X(x + TransForX(18)), ReturnY(y + TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		RenderBitmap(61535, Return2X(x + TransForX(18)), ReturnY(y + TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 2650)); //-- Socket
	pDrawText(pTextThis(), Return2X(x + TransForX(18)), ReturnY(y + TransForY(218)), v10, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	
	//-- Repair
	ChangeButtonInfo((char *)(This + 288), Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( *(WORD *)(*(DWORD*)0x8128AC8 + 14) >= 50 && !pCheckWindow(pWindowThis(), Warehouse) )
	{
		if( CheckButtonPressed(Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
		{
			RenderBitmap(61535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			if( CheckRepairInv(This) == 1 )
			{
				RenderBitmap(61535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			else
			{
				RenderBitmap(61535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
		}
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	}//-- over 0.4460069239
	else
	{
		RenderBitmap(61535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.6706154196, 0.5035384717, 0.2215384692, 1, 1, 0);
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1559));//
	pDrawText(pTextThis(), Return2X(x + TransForX(65)), ReturnY(TransForY(218)), v10, Return2X(TransForX(43)), 0, (LPINT)3, 0);

	//-- store
	ChangeButtonInfo((char *)(This + 632), Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( pCheckWindow(pWindowThis(), Trade)
		|| pCheckWindow(pWindowThis(), Warehouse)
		|| pCheckWindow(pWindowThis(), ChaosBox)
		|| pCheckWindow(pWindowThis(), Shop)
		|| pCheckWindow(pWindowThis(), OtherStore) )
	{
		RenderBitmap(61535, Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.6706154196, 0.5035384717, 0.2215384692, 1, 1, 0);
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
	}
	else
	{
		if( CheckButtonPressed(Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) || pCheckWindow(pWindowThis(), Store) )
		{
			RenderBitmap(61535, Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}//-- over 0.4460069239
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1640));
	pDrawText(pTextThis(), Return2X(x + TransForX(90)), ReturnY(TransForY(390)), v10, Return2X(TransForX(43)), 0, (LPINT)3, 0);

	//-- Inv Ext
	ChangeButtonInfo((char *)(This + 804), Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

	if( CheckButtonPressed(Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) || pCheckWindow(pWindowThis(), ExpandInventory) )
	{
		RenderBitmap(61535, Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}//-- over 0.4460069239
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 3425));
	pDrawText(pTextThis(), Return2X(x + TransForX(135)), ReturnY(TransForY(390)), v10, Return2X(TransForX(43)), 0, (LPINT)3, 0);

	//-- Zen
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	ZeroMemory(v22, sizeof(v22));
	pGetMoneyFormat(v23, v22, 0);
	v15 = ColorMoney(v23);
	SetTextColorByHDC(pTextThis(), v15);
	pDrawText(pTextThis(), Return2X(x + TransForX(27)), ReturnY(TransForY(385)), v22, Return2X(TransForX(60)), 0, (LPINT)4, 0);

	//-- Ruud Coin
	ZeroMemory(v22, sizeof(v22));
	pGetMoneyFormat(Ruud, v22, 0);
	v15 = ColorMoney(Ruud);
	SetTextColorByHDC(pTextThis(), v15);
	pDrawText(pTextThis(), Return2X(x + TransForX(27)), ReturnY(TransForY(399)), v22, Return2X(TransForX(60)), 0, (LPINT)4, 0);
}

bool CheckMouseAncestral(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	x = TransFor2X((double)*(signed int *)(This + 36));
	y = TransForY((double)*(signed int *)(This + 40));

	return pCheckMouseOver(Return2X(x + TransForX(18)), ReturnY(TransForY(198)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
}

bool CheckMouseSocket(int x, int y, int w, int h) 
{
	int This; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	x = TransFor2X((double)*(signed int *)(This + 36));
	y = TransForY((double)*(signed int *)(This + 40));

	return pCheckMouseOver( Return2X(x + TransForX(18)), ReturnY(y + TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
}

__declspec(naked) void RemoveTextAncestral()
{
	static DWORD Addr_JMP = 0x0083524C;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RemoveTextSocket()
{
	static DWORD Addr_JMP = 0x00835364;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InfoTooltipAncestral()
{
	static DWORD Addr_JMP = 0x00835C92;
	static DWORD This; // [sp+74h] [bp-4h]@1
	static DWORD RenderY; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	RenderY = *(signed int *)(This + 40) + 175;

	_asm
	{
		PUSH RenderY
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InfoTooltipSocket()
{
	static DWORD Addr_JMP = 0x00835CBD;
	static DWORD This; // [sp+74h] [bp-4h]@1
	static DWORD RenderY; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	RenderY = *(signed int *)(This + 40) + 195;

	_asm
	{
		PUSH RenderY
		JMP[Addr_JMP]
	}
}

unsigned int sub_83CBE0(int This)
{
	unsigned int result; // eax@2
	unsigned int v2; // [sp+4h] [bp-4h]@1

	v2 = CheckInventoryExt((int)This + 992);
	if ( v2 <= 3 )
		result = v2;
	else
		result = 0;
	return result;
}

void WindowsInfoInventoryExt(int a1)
{
	float x; // ST08_4@1
	float y; // ST04_4@1
	int This; // ST24_4@1
	char v10[255]; // ST24_4@1
	float v7; // ST08_4@3
	float v8; // ST04_4@3
	signed int v13; // [sp+4h] [bp-Ch]@1
	signed int result; // eax@1
	int Inventory; // [sp+0h] [bp-10h]@1

	This = GetInventoryExt(GetInstance());
	//*(signed int *)(This + 24) = 151;
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	if( pCheckWindow(pWindowThis(), Character) )
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}
	else
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));
	

	RenderBitmap(61526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 3323));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v10, Return2X(Width), 0, (LPINT)3, 0);
	//-- Cerrar
	pDrawPuntero(This + 52, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 52), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	
	if( CheckButtonPressed(Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11))) )
	{
		RenderBitmap(61529, Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)), 0.0, 0.0, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61529, Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 1, 1, 0);
	}

	Inventory = GetInventory(GetInstance());
	v13 = 1;
	int t;

	for( result = sub_83CBE0(Inventory); v13 < result; result = sub_83CBE0(Inventory) )
	{
		*(DWORD *)((*((DWORD *)Inventory + v13 + 6)) + 44) = ReturnY(y + TransForY(60 + ( (v13-1) * 105)));

		t = *(DWORD *)((*((DWORD *)Inventory + v13 + 6)) + 56) * RetangleInventory( 17 );

		*(DWORD *)((*((DWORD *)Inventory + v13 + 6)) + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
		v13++;
	}

	for ( int i = 0; i < 2; ++i )
	{
		*(DWORD *)(This + 8 * i + 32) = ReturnY(y + TransForY(60 + ( i * 105 ))); //-- Y
		*(DWORD *)(This + 8 * i + 28) = Return2X(x + TransForX( 17 )); //-- X
	}
}

void RenderInvExtSlot(DWORD id, float x, float y, float w, float h)
{
	pSetBlend(1);
	glColor4f(0.0, 0.0, 0.0, 0.55000002);
	pDrawBarForm(x, y, Return2X(TransForX(w)), h, 0.0, 0);
	glEnable(0xDE1u);
	pGLSwitch();
	pSetBlend(0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
}

void RenderInvExtNum(DWORD id, float x, float y, float w, float h)
{
	/*HDC hDC = GetDC(*(HWND*)(0x00E8C578));
	SIZE psizl; // [sp+90h] [bp-1Ch]@1

	SelectObject(hDC, pFontBold);
		
	GetTextExtentPoint32(hDC, "Empty Slot", strlen("Empty Slot"), &psizl);

	pDrawText(pTextThis(), x, y, "Empty Slot", psizl.cx, 0, (LPINT) 1, 0);*/

	RenderBitmap(61537, x, y, Return2X(TransForX(25)), ReturnY(TransForY(28)), 0.2875324488f, 0.0, 0.2875324488f, 0.2654999793f, 1, 1, 0);
}

DWORD main; // [sp+78h] [bp-B0h]@1

__declspec (naked) void RenderRect()
{
	static DWORD main_Addr = 0x007DB23F;

	_asm
	{
		MOV DWORD PTR SS:[EBP-0xB0],ECX
		MOV ECX, DWORD PTR SS:[EBP-0xB0]
		MOV main, ECX
	}

	*(DWORD *)(main + 48) = *(DWORD *)(main + 56) * RetangleInventory( 17 ); // W
	*(DWORD *)(main + 52) = (int)*(DWORD *)(main + 60) * 17; // H
	
	*(float *)(main + 88) = 0.32f;
	*(float *)(main + 92) = 0.201;
	*(float *)(main + 96) = 0.5f;

	_asm
	{
		JMP [main_Addr]
	}
}

void ItemSlotEmpty(DWORD id, float x, float y, float w, float h)
{
	float v5; // ST04_4@23
	float v6; // ST00_4@23
	int j; // [sp+120h] [bp-8h]@3
	int i; // [sp+124h] [bp-4h]@1

	i = (y - *(DWORD *)(main + 44)) / 20;
	j = (x - *(DWORD *)(main + 40)) / 20;

	v5 = (double)(17 * i + *(DWORD *)(main + 44));//-- y
	v6 = (double)(RetangleInventory( 17 ) * j + *(DWORD *)(main + 40));//-- x

	id = (id == 31339) ? 61527 : id;

	pDrawGUI(id, v6, v5, RetangleInventory( 17 ), 17);
}

void ItemSlotDurability(float x, float y, float w, float h, float Arg5, int Arg6)
{
	float v5; // ST04_4@23
	float v6; // ST00_4@23
	int j; // [sp+120h] [bp-8h]@3
	int i; // [sp+124h] [bp-4h]@1

	i = (y - *(DWORD *)(main + 44)) / 20;
	j = (x - *(DWORD *)(main + 40)) / 20;

	v5 = (double)(17 * i + *(DWORD *)(main + 44)); //-- Y
	v6 = (double)(RetangleInventory( 17 ) * j + *(DWORD *)(main + 40)); //-- X

	pDrawBarForm(v6, v5, RetangleInventory( 17 ), 17, Arg5, Arg6);
}

void WindowsInfoWareHouse(int a1)
{
	int This; // ST2C_4@1
	float y; // ST08_4@1
	float x; // ST04_4@1
	char v7[256]; // al@1
	int Color; // [sp+24h] [bp-88h]@1
	int Zen; // [sp+A8h] [bp-4h]@4
	signed __int64 v23; // ST28_8@4
	signed int v29; // [sp+10h] [bp-9Ch]@8
	int v30; // [sp+14h] [bp-98h]@5
	int v33; // [sp+A8h] [bp-4h]@4
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );
	
	This = GetUIBaul(GetInstance());
	
	*(signed int *)(This + 16) = 1;

	x = TransFor2X((double)*(signed int *)(This + 16));
	y = TransForY((double)*(signed int *)(This + 20));

	RenderBitmap(61539, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	if ( *(DWORD *)(This + 540) )
	{
		int t = ( 8 * 17 ) / 2;
		*(DWORD *)((*(DWORD *)(This + 540)) + 44) = 73;
		*(DWORD *)((*(DWORD *)(This + 540)) + 40) = x + Return2X(( Width / 2 ) - TransForX( t ));
	}

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	if ( *(BYTE *)(This + 548) )
	{
		pSetTextColor(pTextThis(), 0xF0u, 0x20u, 0x20u, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xD8u, 0xD8u, 0xD8u, 0xFFu);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, "%s (%s)",pGetTextLine(pTextLineThis, 234), pGetTextLine(pTextLineThis, (*(BYTE *)(This + 548) != 0) + 240)); //-- Socket
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v7, Return2X(Width), 0,(LPINT) 3, 0);
	//-- Zen
	Zen = *(DWORD *)(*(DWORD*)0x8128AC4 + 5960);
	pGetMoneyFormat(Zen, v7, 0);

	if(Zen > 0)
	{
		Color = ColorMoney(Zen);
	}
	SetTextColorByHDC(pTextThis(), Color);
	pDrawText(pTextThis(), Return2X(x + TransForX(158)), ReturnY(y + TransForY(353)), v7, 0, 0,(LPINT) 7, 0);
	//-- Storage Free
	pSetTextColor(pTextThis(), 0xF0u, 0x40u, 0x40u, 0xFFu);
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 224)); //-- Zen
	pDrawText(pTextThis(), Return2X(x + TransForX(35)), ReturnY(y + TransForY(353)), v7, 0, 0,(LPINT) 1, 0);
	
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 266)); //-- StorageFree
	pDrawText(pTextThis(), Return2X(x + TransForX(35)), ReturnY(y + TransForY(368)), v7, 0, 0,(LPINT) 1, 0);

	v23 = *(WORD *)0x87935D8 + *(WORD *)(*(DWORD *)0x8128AC8 + 14);
	v33 = (double)v23 * (double)v23 * 0.04;

	if ( *(BYTE *)(This + 548) )
		v30 = 2 * *(WORD *)(*(DWORD *)0x8128AC8 + 14);
	else
		v30 = 0;
	v33 += v30;
	if ( v33 >= 1 )
		v29 = v33;
	else
		v29 = 1;
	v33 = v29;
	if ( v29 < 1000 )
	{
		if ( v33 >= 100 )
			v33 = 10 * (v33 / 10);
	}
	else
	{
		v33 = 100 * (v33 / 100);
	}
	pGetMoneyFormat((double)v33, v7, 0);
	if(v33 > 0)
	{
		Color = ColorMoney(v33);
	}
	SetTextColorByHDC(pTextThis(), Color);
	pDrawText(pTextThis(), Return2X(x + TransForX(158)), ReturnY(y + TransForY(368)), v7, 0, 0,(LPINT) 7, 0);
	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	for (int i = 0; i < 3; ++i )
	{
		pDrawPuntero(This + 172 * i + 24, 1, 51522, 0, 0, 0);
		ChangeButtonInfo((char *)(This + 172 * i + 24), Return2X(x + TransForX(10 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
		if( CheckButtonPressed(Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
		{
			RenderBitmap(61535, Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, ( i == 0) ? 235 : ( i == 1) ? 236 : 451));
		pDrawText(pTextThis(), Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0, (LPINT)3, 0);
	}
	//-- Expaned WareHouse
	pDrawPuntero(This + 572, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 572), Return2X(x + TransForX(140)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( CheckButtonPressed(x + 153, y + 387, 43, 17) )
	{
		RenderBitmap(61535, Return2X(x + TransForX(140)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, Return2X(x + TransForX(140)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 234));
	pDrawText(pTextThis(), Return2X(x + TransForX(140)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0, (LPINT)3, 0);
}

void WindowsInfoWareHouseExt(int a1)
{
	int This; // ST24_4@1
	float x; // ST08_4@1
	float y; // ST04_4@1
	int v6; // eax@1
	char v7[256]; // al@4

	This = GetUIBaulExt(GetInstance());

	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	*(signed int *)(This + 16) = Return2X(TransForX( 190 ) );

	x = TransFor2X((double)*(signed int *)(This + 16));
	y = TransForY((double)*(signed int *)(This + 20));

	RenderBitmap(61540, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	v6 = GetUIBaul(GetInstance());

	if ( *(DWORD *)(v6 + 544) )
	{
		int t = ( 8 * 17 ) / 2;
		*(DWORD *)((*(DWORD *)(v6 + 544)) + 44) = 73;
		*(DWORD *)((*(DWORD *)(v6 + 544)) + 40) = Return2X(x + ( Width / 2 ) - TransForX( t ));
	}

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

	if ( *(BYTE *)(v6 + 548) )
	{
		pSetTextColor(pTextThis(), 0xF0u, 0x20u, 0x20u, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xD8u, 0xD8u, 0xD8u, 0xFFu);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, "%s (%s)",pGetTextLine(pTextLineThis, 3339), pGetTextLine(pTextLineThis, (*(BYTE *)(v6 + 548) != 0) + 240)); //-- Socket
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v7, Return2X(Width), 0, (LPINT)3, 0);

	//-- Cerrar
	pDrawPuntero(This + 24, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 24), x + 180, y + 28, 11, 11);
	if( CheckButtonPressed(x + 180, y + 28, 11, 11) )
	{
		RenderBitmap(61529, x + 178, y + 27, 11, 11, 0.0, 0.0, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61529, x + 178, y + 27, 11, 11, 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
}

void WindowsInfoShop(int a1)
{
	int This; // ST24_4@1
	float x; // ST08_4@1
	float y; // ST04_4@1
	int v6; // eax@1
	char v7[256]; // al@4
	int Color; // ST18_4@2

	This = GetWindowShop(GetInstance());
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	*(signed int *)(This + 20) = 1;

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));

	if ( *(BYTE *)(This + 36) )
	{
		RenderBitmap(61541, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61543, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);
	}

	if ( *(DWORD *)(This + 16) )
	{
		*(DWORD *)((*(DWORD *)(This + 16)) + 44) = ReturnY(y + TransForY(75));
		int t = *(DWORD *)((*(DWORD *)(This + 16)) + 56) * RetangleInventory( 17 );
		*(DWORD *)((*(DWORD *)(This + 16)) + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	}
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 230));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v7, Return2X(Width), 0, (LPINT)3, 0);
	//-- Tax Rate
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 1623), *(DWORD *)(This + 32));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(350)), v7, Return2X(Width), 0, (LPINT)3, 0);
	//--
	if ( *(BYTE *)(This + 36) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0xDCu, 0x96u, 0xFFu);
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, 239)); //-- Repair All
		pDrawText(pTextThis(), Return2X(x + TransForX(45)), ReturnY(y + TransForY(363)), v7, 0, 0,(LPINT) 1, 0);

		pGetMoneyFormat(*(DWORD *)0x81F6BC8, v7, 0);
		Color = ColorMoney(*(DWORD *)0x81F6BC8);
		SetTextColorByHDC(pTextThis(), Color);
		pDrawText(pTextThis(), Return2X(x + TransForX(140)), ReturnY(y + TransForY(363)), v7, 0, 0,(LPINT) 7, 0);
		//--
		pDrawPuntero(This + 40, 1, 51522, 0, 0, 0);
		ChangeButtonInfo((char *)(This + 40), Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

		if( CheckButtonPressed(Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) || CheckRepairShop(GetWindowShop((int)pWindowThis())) == 2 )
		{
			RenderBitmap(61542, Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61542, Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, 1559)); //-- Repair
		pDrawText(pTextThis(), Return2X(x + TransForX(31)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
		//--
		pDrawPuntero(This + 212, 1, 51522, 0, 0, 0);
		ChangeButtonInfo((char *)(This + 212), Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

		if( CheckButtonPressed(Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
		{
			RenderBitmap(61542, Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61542, Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, 239)); //-- Repair All
		pDrawText(pTextThis(), Return2X(x + TransForX(116)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	}
}

void WindowsChaosBox(int index, float x, float y, float w, float h)
{
	int This; // [sp+84h] [bp-25Ch]@1
	int v6; // eax@1
	char v7[256]; // al@4
	int Color; // ST18_4@2
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );
	This = GetChaosBox(GetInstance());

	if( pCheckWindow(pWindowThis(), 77) )
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 3));
	}
	else
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));

	RenderBitmap(61526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	if ( *(DWORD *)(This + 16) )
	{
		int MainSlot = *(DWORD *)(This + 16);
		//-- Inventory
		//*(DWORD *)(MainSlot + 44) = ReturnY(TransForY(242));
		int t = *(DWORD *)(MainSlot + 56) * RetangleInventory( 17 );
		*(DWORD *)(MainSlot + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	}

	//This + 276
	pDrawPuntero(This + 28, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 28), Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

	if( CheckButtonPressed(Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
	{
		RenderBitmap(61542, Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61542, Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
	}
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 591)); //-- Combining
	pDrawText(pTextThis(), Return2X(x + TransForX(74)), ReturnY(TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
}

int WindowsInfoStore(int a1)
{
	int This; // ST3C_4@1
	float y; // ST18_4@1
	float x; // ST14_4@1
	char v7[256]; // eax@1
	int Width;
	int Heigth;

	This = pWindowStore(GetInstance());
	Width = TransForX( 190 );
	Heigth = TransForY( 429 );

	if( pCheckWindow(pWindowThis(), ExpandInventory) )
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 3));
	}
	else
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));

	RenderBitmap(61544, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	if ( *(DWORD *)(This + 16) )
	{
		int t = *(DWORD *)((*(DWORD *)(This + 16)) + 56) * RetangleInventory( 17 );
		*(DWORD *)((*(DWORD *)(This + 16)) + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	}
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	//-- Abrir Store
	pDrawPuntero(*(DWORD *)(This + 40) + 172, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(*(DWORD *)(This + 40) + 172), Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( CheckButtonPressed(Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 1107));
	pDrawText(pTextThis(), Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	
	//-- Cerrar Store
	pDrawPuntero(*(DWORD *)(This + 40) + 344, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(*(DWORD *)(This + 40) + 344), Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( CheckButtonPressed(Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(61535, Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 1108)); //-- Repair All
	pDrawText(pTextThis(), Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	//-- Cerrar
	pDrawPuntero(*(DWORD *)(This + 40) + 0, 1, 51522, 0, 0, 0);
	
	ChangeButtonInfo((char *)(*(DWORD *)(This + 40) + 0), Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10)));
	
	if( CheckButtonPressed(Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10))) )
	{
		RenderBitmap(61529, Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10)), 0.0, 0.0, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61529, Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10)), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 1, 1, 0);
	}

	SetBoundInputField( *(DWORD *)(This + 44), Return2X(x + TransForX( 53 )), *(DWORD *)(This + 24) + 65 );

	gOffTrade.DrawOffTradeWindowEx700(x, y);

	return 1;
}

DWORD xMouser;

void UpdatexMouse()
{
	xMouser = RetangleInventory( 17 );
}

__declspec (naked) void RenderMouseRECT()
{
	static DWORD main_Addr = 0x007DC4F1;
	static DWORD renderx;
	static DWORD rendery;

	UpdatexMouse();

	renderx = ( xMouser != 0 ) ? xMouser : 0;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		SUB EAX,DWORD PTR SS:[EBP-0x10]
		CDQ
		MOV ECX, renderx
		IDIV ECX
		MOV EDX,DWORD PTR SS:[EBP+0x10]
		MOV DWORD PTR DS:[EDX],EAX
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		SUB EAX,DWORD PTR SS:[EBP-0xC]
		CDQ
		MOV ECX, 17
		IDIV ECX
		MOV EDX,DWORD PTR SS:[EBP+0x14]
		MOV DWORD PTR DS:[EDX],EAX
		MOV AL,1
		JMP [main_Addr]
	}
}
DWORD ObjectModelInfo; // [sp+50h] [bp-18h]@3
DWORD ObjectModelTRS; // [sp+5Ch] [bp-Ch]@3
DWORD vMain; // [sp+34h] [bp-34h]@1

__declspec (naked) void GetInfoModelSlot()
{
	static DWORD main_Addr = 0x007DD50A;

	_asm
	{
		MOV ECX,DWORD PTR DS:[EAX]
		MOV DWORD PTR SS:[EBP-0x18],ECX
		MOV EDX,DWORD PTR SS:[EBP-0x18]
		MOV ObjectModelInfo, EDX
		MOVSX EAX,WORD PTR DS:[EDX]
		IMUL EAX,EAX,0x54
		ADD EAX,DWORD PTR DS:[0x8128AC0]
		MOV DWORD PTR SS:[EBP-0xC],EAX
		MOV ObjectModelTRS, EAX
		MOV EAX, DWORD PTR SS:[EBP-0x34]
		MOV vMain, EAX
		JMP [main_Addr]
	}
}

void ObjectModelScaleSlot(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	if( vMain )
	{
		x = (double)(RetangleInventory( 17 ) * *(BYTE *)(ObjectModelInfo + 67) + *(DWORD *)(vMain + 40));
		y = (double)(17 * *(BYTE *)(ObjectModelInfo + 68) + *(DWORD *)(vMain + 44));

		Width = (double)(RetangleInventory( 17 ) * *(BYTE *)(ObjectModelTRS + 38));
		Height = (double)(17 * *(BYTE *)(ObjectModelTRS + 39));
	}
	pDrawItemModel(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
}

char WindowInfoCommand(int a1)
{
	int This; // [sp+2Ch] [bp-1Ch]@1
	char v10[255]; // ST24_4@1
	float y; // ST08_4@1
	float x; // ST04_4@1
	signed int i; // [sp+44h] [bp-4h]@1
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );
	int v33; // [sp+40h] [bp-8h]@8

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	This = *(DWORD *)(GetInstance() + 148);

	*(signed int *)(This + 16) = Return2X(TransFor2X(640) - Width);
	x = TransFor2X((double)*(signed int *)(This + 16));
	y = TransForY((double)*(signed int *)(This + 20));

	RenderBitmap(61526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 938));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v10, Return2X(Width), 0, (LPINT)3, 0);
	//-- Cerrar
	pDrawPuntero(This + 1916, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 1916), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	if( CheckButtonPressed(Return2X(x + TransForX(158)), Return2X(y + TransForX(28)), Return2X(TransForX(11)), Return2X(TransForX(11))) )
	{
		RenderBitmap(61529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.0, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	//--
	int Button;
	for ( i = 0; i < 11; ++i )
	{
		Button = This + 172 * i + 24;
		*(DWORD *)(Button + 116) = (int)pFontNormal;
		if ( *(DWORD *)(This + 2088) != -1 )
		{
			*(DWORD *)(Button + 116) = (int)pFontBold;
		}
		ChangeButtonInfo((char *)(Button), Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30)));
		if( CheckButtonPressed( Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30))) )
		{
			RenderBitmap(61535, Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(61535, Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		pDrawPuntero(Button, 1, 51522, 0, 0, 0);
		sub_7798F0(Button, 0);
	}
	if ( *(DWORD *)(This + 2092) == 9 && *(BYTE *)(This + 2096) == 1 )
	{
		v33 = pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);

		if ( v33 )
		{
			if ( *(BYTE *)(v33 + 800) == 1
				&& v33 != *(DWORD *)0x7BC4F04
				&& (*(DWORD *)(v33 + 824) == 1163 || *(BYTE *)(v33 + 15)) )
			{
				RenderBitmap(31599, Return2X(TransFor2X((double)*(DWORD *)0x879340C + 5.0)), ReturnY(TransForY((double)*(DWORD *)0x8793410 + 5.0)), Return2X(TransForX(128)), ReturnY(TransForY(32)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				pSetFont(pTextThis(), (int)pFontBigBold);
				if ( *(BYTE *)(This + 2097) )
				{
					pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				}
				else
				{
					pSetTextColor(pTextThis(), 0xFFu, 0, 0, 0xFFu);
				}
				pSetBackgroundTextColor(pTextThis(), 0x14u, 0x14u, 0x14u, 0);
				
				pDrawText(pTextThis(), Return2X(TransFor2X(*(DWORD *)0x879340C + 69)), ReturnY(TransForY((double)*(DWORD *)0x8793410 + 12)), (LPCTSTR)v33 + 56, 0, 0, (PINT)8, 0);
				pSetFont(pTextThis(), (int)pFontNormal);
			}
		}
	}
	pGLSwitch();
	return 1;
}

int WindowNPCJulia(int a1)
{
	int This; // ST2C_4@1
	float y; // ST10_4@1
	float x; // ST0C_4@1
	char v25[256]; // [sp+28h] [bp-108h]@1
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	EnableAlphaTest(1);
	This = *(DWORD *)(GetInstance() + 292);

	*(signed int *)(This + 24) = Return2X(TransFor2X(640) - Width);
	x = TransFor2X((double)*(signed int *)(This + 24));
	y = TransForY((double)*(signed int *)(This + 28));

	RenderBitmap(61526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//--Titulo
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v25, sizeof(v25));
	wsprintf(v25, pGetTextLine(pTextLineThis, 3000));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v25, Return2X(Width), 0, (LPINT)3, 0);
	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C588);
	//--
	if ( *(DWORD *)0xE61E18 == 79 )
	{
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3010));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(60)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3011));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(80)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3012));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(100)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3013));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(180)), v25, Return2X(Width), 0, (LPINT)3, 0);
	}
	else
	{
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3013));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(60)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3003));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(80)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3004));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(100)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3005));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(120)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3006));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(140)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3007));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(160)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3008));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(180)), v25, Return2X(Width), 0, (LPINT)3, 0);
	}

	if ( *(DWORD *)(This + 380) == 1 )
	{
		(*(void (__thiscall **)(int))(*(DWORD *)(This + 32) + 4))(This + 32);

		sub_779740(This + 32, 0, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
		sub_779740(This + 32, 1, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
		sub_779740(This + 32, 2, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
		//sub_7853D0(This + 32, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
	}
	else
	{
		(*(void (__thiscall **)(int))(*(DWORD *)(This + 32) + 8))(This + 32);

		sub_779740(This + 32, 0, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
		sub_779740(This + 32, 1, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
		sub_779740(This + 32, 2, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
		//sub_7853D0(v39 + 32, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
	}

	int Button = This + 204;
	pDrawPuntero(Button, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(Button), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	if( CheckButtonPressed(Return2X(x + TransForX(158)), Return2X(y + TransForX(28)), Return2X(TransForX(11)), Return2X(TransForX(11))) )
	{
		RenderBitmap(61529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.0, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	sub_7798F0(Button, 0);

	Button = This + 32;
	ChangeButtonInfo((char *)(Button), Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22)));
	if( CheckButtonPressed( Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22))) )
	{
		RenderBitmap(61535, Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(61535, Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	pDrawPuntero(Button, 1, 51522, 0, 0, 0);
	sub_7798F0(Button, 0);

	pGLSwitch();
	return 1;
}

void MuHelperInfo(DWORD id, float x, float y, float w, float h)
{
	int v170; // [sp+60h] [bp-2D8h]@1

	v170 = *(DWORD *)(GetInstance() + 312);
	w = TransForX( 190 );
	h = TransForY( 429 );

	*(signed int *)(v170 + 200) = Return2X(TransFor2X( 640 ) - w);

	x = TransFor2X((double)*(signed int *)(v170 + 200));
	y = TransForY((double)*(signed int *)(v170 + 204));

	RenderBitmap(61526, x, y, w, h, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);
}

void DropBox(float X, float Y, float W, float H, float arg5, float arg6)
{
	int v170; // [sp+60h] [bp-2D8h]@1
	float xWindow; // ST08_4@1
	int Width;

	glColor4f(0.0, 0.0, 0.0, 0.50000001);

	v170 = *(DWORD *)(GetInstance() + 312);

	xWindow = (double) *(signed int *)(v170 + 200);

	X = xWindow + Return2X(TransForX( X - xWindow ));

	Width = Return2X(TransForX( W ));

	pDrawBarForm(X, Y, Width, H, arg5, arg6);
}

void DropBoxCornet(int ModelId, float X, float Y, float W, float H)
{
	pDrawGUI(51522, X, Y, W, H);
}

void DropTextureHelper(int ModelId, float X, float Y, float W, float H)
{
	int v170; // [sp+60h] [bp-2D8h]@1
	float xWindow; // ST08_4@1
	int Width;

	v170 = *(DWORD *)(GetInstance() + 312);

	xWindow = (double)*(signed int *)(v170 + 200) + (X - 450);

	if( ModelId == 31759 )
	{
		xWindow = (double)*(signed int *)(v170 + 200) + ((double) X - *(signed int *)(v170 + 200));
	}

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	RenderBitmap(ModelId, TransFor2X( xWindow ), TransForY( Y ), TransForX( W ), TransForY( H ), 0.0, 0.0, 1.0, 0.5949999094, 0, 0, 0);

	pGLSwitch();
	EnableAlphaTest(0);
}

int ItemObjectClass;
int This_;

__declspec (naked) void RecvNumberStack()
{
	static DWORD main_addr = 0x007DC909;

	_asm
	{
		MOV ECX,DWORD PTR DS:[EAX]
		MOV DWORD PTR SS:[EBP-0x18],ECX
		MOV ItemObjectClass, ECX
		MOV EDX,DWORD PTR SS:[EBP-0x34]
		MOV This_, EDX
		JMP[main_addr]
	}
}

double JCRenderNumberEx(float a1, float a2, int a3, float a4, DWORD ModelID)
{
	double result; // st7@2
	float v5; // ST44_4@5
	float v6; // ST38_4@5
	signed int i; // [sp+38h] [bp-30h]@3
	float v8; // [sp+3Ch] [bp-2Ch]@3
	signed int v9; // [sp+44h] [bp-24h]@3
	char v10[32]; // [sp+48h] [bp-20h]@3
	float v11; // [sp+70h] [bp+8h]@3


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
	return result;
}


void JCNumberStack(float x, float y, int Number, float scale)
{
	float v23; // ST14_4@38
	float v24; // ST10_4@38
	float v29; // [sp+84h] [bp-1Ch]@3
	float v31; // [sp+8Ch] [bp-14h]@3
	float v32; // [sp+90h] [bp-10h]@3
	int v33; // [sp+94h] [bp-Ch]@3

	v33 = *(DWORD *)0x8128AC0 + 84 * *(WORD *)ItemObjectClass;
	v31 = (double)(RetangleInventory( 17 ) * *(BYTE *)(ItemObjectClass + 67) + *(DWORD *)(This_ + 40));
	v32 = (double)(17 * *(BYTE *)(ItemObjectClass + 68) + *(DWORD *)(This_ + 44));
	v29 = (double)(RetangleInventory( 17 ) * *(BYTE *)(v33 + 38));

	v23 = v32 + 1.0;
	v24 = v31 + v29 - Return2X(TransForX(6.0));
	JCRenderNumberEx(v24, v23, Number, ( pWinWidthReal <= 1.6 ) ? 1.0 : 0.90, 31337);
}

void InitSeason15()
{
	SetCompleteHook(0xE9, 0x007DC904, &RecvNumberStack); //-- Number Stack
	//--
	SetCompleteHook(0xE8, 0x007DC9E6, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCA78, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCB05, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCB96, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCC16, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCCA8, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCD35, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCDB4, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCE51, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCEE7, &JCNumberStack); //-- Number Stack

	MinimizarPet = 0;
	main = 0;

	/*SetRange((LPVOID)0x007F0CD1, 0x5, 0x90);

	SetCompleteHook(0xE8, 0x007F6AC8, &DropTextureHelper); //-- Skill Box and InputNumber
	SetCompleteHook(0xE8, 0x007F6BB6, &DropTextureHelper); //-- Numero 1
	SetCompleteHook(0xE8, 0x007F75DF, &DropTextureHelper); //-- Input String
	SetCompleteHook(0xE8, 0x007F76CD, &DropTextureHelper); //-- Numero 2
	//--
	SetCompleteHook(0xE8, 0x007F7DD9, &DropBox);
	SetCompleteHook(0xE8, 0x007F7E0D, &DropBoxCornet);
	SetCompleteHook(0xE8, 0x007F7E48, &DropBoxCornet);
	SetCompleteHook(0xE8, 0x007F7E83, &DropBoxCornet);
	SetCompleteHook(0xE8, 0x007F7ECB, &DropBoxCornet);
	SetCompleteHook(0xE8, 0x007F7F08, &DropBoxCornet);
	SetCompleteHook(0xE8, 0x007F7F53, &DropBoxCornet);
	SetCompleteHook(0xE8, 0x007F7F9D, &DropBoxCornet);
	SetCompleteHook(0xE8, 0x007F7FDB, &DropBoxCornet);
	*/
	//-- Click Slot
	SetCompleteHook(0xE9, 0x007DD4F3, &GetInfoModelSlot);
	SetCompleteHook(0xE8, 0x007DD5C0, &ObjectModelScaleSlot);
	SetCompleteHook(0xE9, 0x007DC4C9, &RenderMouseRECT);
	SetCompleteHook(0xE9, 0x007DB239, &RenderRect);
	//-- Windows NPC_Julia
	SetCompleteHook(0xE9, 0x008679D0, &WindowNPCJulia);
	
	//-- Windows Command
	SetCompleteHook(0xE9, 0x0078E390, &WindowInfoCommand);
	//-- Windows Store
	SetCompleteHook(0xE8, 0x00842460, &WindowsInfoStore);
	//-- Windows Store Other PJ
	SetCompleteHook(0xE8, 0x0084F406, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084F43A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F477, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F4C0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F4FF, &LoadWindowsNone);
	//-- Windows Trade
	SetCompleteHook(0xE8, 0x008643B6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008643EA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00864427, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00864470, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008644AF, &LoadWindowsNone);
//-- Windows Shop
	SetRange((LPVOID)0x00847046, 0x5, 0x90); //-- Zen
	SetRange((LPVOID)0x00847036, 0x5, 0x90); //-- Titulo
	SetCompleteHook(0xE8, 0x0084702E, &WindowsInfoShop);
//-- Windows Baul Ext.
	SetRange((LPVOID)0x00856776, 0x5, ASM::NOP); //-- Titulo
	SetCompleteHook(0xE8, 0x0085676E, &WindowsInfoWareHouseExt);
//-- Windows Baul
	SetRange((LPVOID)0x00858016, 0x5, 0x90); //-- Boton expaned
	SetRange((LPVOID)0x00857898, 0x5, 0x90); //-- Titulo
	SetCompleteHook(0xE8, 0x00857890, &WindowsInfoWareHouse);
//-- Test SlotInventory
	SetCompleteHook(0xE8, 0x007DB4D8, &ItemSlotDurability);//--
	SetCompleteHook(0xE8, 0x007DBD3D, &ItemSlotDurability);
	SetCompleteHook(0xE8, 0x007DC197, &ItemSlotDurability);
	//--
	SetCompleteHook(0xE8, 0x007DB5D0, &ItemSlotEmpty);//--
	SetCompleteHook(0xE8, 0x007DB63E, &ItemSlotEmpty);
	SetCompleteHook(0xE8, 0x007DB6D2, &ItemSlotEmpty);
	SetCompleteHook(0xE8, 0x007DB737, &ItemSlotEmpty);
	//RenderNumberStack
	/*SetByte((PVOID)(0x007DC922 + 2), 17);
	SetByte((PVOID)(0x007DC93D + 2), 17);
	SetByte((PVOID)(0x007DC958 + 2), 17);*/
	//--Test
	//-- Inventory Ext.
	SetCompleteHook(0xE8, 0x007D4F9E, &WindowsInfoInventoryExt);
	//-- Inventario
	SetCompleteHook(0xE8, 0x0083510E, &WindowsInfoInventory);
	//-- Character
	SetCompleteHook(0xE8, 0x0077F7EE, &CharacterInfoWindow);
	//--
//-- Windows Inventory Ext.
	SetRange((LPVOID)0x007D4FA6, 5, 0x90); //-- Titulo
	SetCompleteHook(0xE8, 0x007D582D, &LoadWindowsNone);//-- parte del inventario extend
	SetCompleteHook(0xE8, 0x007D587C, &RenderInvExtSlot);
	//SetCompleteHook(0xE8, 0x007D58CF, &RenderInvExtNum);
//-- Windows Inventory
	SetRange((LPVOID)0x00835116, 5, 0x90); //-- Titulo + ZEN
	SetRange((LPVOID)0x008337B0, 5, 0x90); //-- Equipamiento
	SetRange((LPVOID)0x0083443C, 5, 0x90); //-- Equipamiento
	SetRange((LPVOID)0x008337B8, 5, 0x90); //-- Button

	SetCompleteHook(0xE9, 0x00835CB1, &InfoTooltipSocket); //-- Posicion Mostrar Tooltip de Equipamiento
	SetCompleteHook(0xE9, 0x00835C86, &InfoTooltipAncestral); //-- Posicion Mostrar Tooltip de Equipamiento
	//--
	SetCompleteHook(0xE9, 0x0083516F, &RemoveTextAncestral); //-- Text Ancient
	SetCompleteHook(0xE9, 0x008352B1, &RemoveTextSocket); //-- Text Socket
	//--
	SetCompleteHook(0xE8, 0x0083538A, &CheckMouseSocket); //-- InfoOption Socket Equip
	SetCompleteHook(0xE8, 0x00834C8D, &CheckMouseAncestral); //-- InfoOption Ancient Equip

	SetCompleteHook(0xE8, 0x007DB7B0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB812, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB874, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB8E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB959, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB9A2, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DBA20, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DBA69, &LoadWindowsNone);
	SetCompleteHook(0xE9, 0x0083BAF4, &RemoveButtonStore1);
	SetCompleteHook(0xE9, 0x0083BB94, &RemoveButtonStore2);
//-- CharacterInfo
	SetRange((LPVOID)0x0077E906, 5, 0x90); //-- Evento Button
	//SetRange((LPVOID)0x0077F81A, 5, 0x90); //-- Titulo
	SetCompleteHook(0xE9, 0x0077F8CA, &InformationServer1); //-- Text
	SetCompleteHook(0xE9, 0x0077FA1C, &InformationServer2); //-- Text
	SetCompleteHook(0xE9, 0x0077FAA7, &InformationServer3); //-- Text
	SetRange((LPVOID)0x0077F822, 5, 0x90); //-- Información 1
	//-- Stadistica Str
	SetCompleteHook(0xE9, 0x007801D7, &InformationSTR1); //-- Text
	SetCompleteHook(0xE9, 0x00780215, &InformationSTR2); //-- Point
	SetCompleteHook(0xE9, 0x00781758, &InformationSTR3); //-- Dmg
	SetCompleteHook(0xE9, 0x00781805, &InformationSTR4); //-- Attack Rate
	//-- Stadistica Agi
	SetCompleteHook(0xE9, 0x0078190B, &InformationAGI1); //-- Text
	SetCompleteHook(0xE9, 0x0078194C, &InformationAGI2); //-- Point
	SetCompleteHook(0xE9, 0x00782854, &InformationAGI3); //-- Defense Rate
	SetCompleteHook(0xE9, 0x00782A30, &InformationAGI4); //-- AttackSpeed
	SetCompleteHook(0xE9, 0x00782B83, &InformationAGI5); //-- Defense
	//-- Stadistica Vit
	SetCompleteHook(0xE9, 0x00782D13, &InformationVIT1); //-- Text
	SetCompleteHook(0xE9, 0x00782D54, &InformationVIT2); //-- Point
	SetCompleteHook(0xE9, 0x00782F69, &InformationVIT3); //-- HP
	SetCompleteHook(0xE9, 0x00782FDF, &InformationVIT4); //-- Mele %
	//--Stadistica Ene
	SetCompleteHook(0xE9, 0x007830ED, &InformationENE1); //-- Text
	SetCompleteHook(0xE9, 0x0078312E, &InformationENE2); //-- Point
	SetCompleteHook(0xE9, 0x007832D5, &InformationENE3); //-- MANA
	SetCompleteHook(0xE9, 0x00784029, &InfoMagicDMG1); //-- magic
	SetCompleteHook(0xE9, 0x0078482D, &InfoMagicDMG2); //-- curse
	SetCompleteHook(0xE9, 0x007848A5, &InfoSkillDMG1); //-- Skill Dmg BK
	SetCompleteHook(0xE9, 0x00784904, &InfoSkillDMG2); //-- Skill Dmg MG
	SetCompleteHook(0xE9, 0x00784973, &InfoSkillDMG3); //-- Skill Dmg DL
	SetCompleteHook(0xE9, 0x007849E4, &InfoSkillDMG4); //-- Skill Dmg DL
	SetCompleteHook(0xE9, 0x00784A64, &InfoSkillDMG5); //-- Skill Dmg DL
	//--Stadistica Cmd
	SetCompleteHook(0xE9, 0x00784B6B, &InformationCMD1); //-- Text
	SetCompleteHook(0xE9, 0x00784BAC, &InformationCMD2); //-- Point
	
	//-- Window 1
	SetCompleteHook(0xE8, 0x007C1872, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C18AC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C18F5, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C1950, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C199B, &LoadWindowsNone);
	//-- Window 2
	SetCompleteHook(0xE8, 0x007C2676, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C26AA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C26EA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C273C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C2782, &LoadWindowsNone);
	//-- Window 3
	SetCompleteHook(0xE8, 0x007C46E6, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C471A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C4757, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C47A0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C47DF, &LoadWindowsNone);
	//-- Window 4
	SetCompleteHook(0xE8, 0x007C6BCC, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C6C06, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6C49, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6C98, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6CDD, &LoadWindowsNone);
	//-- Window 5
	SetCompleteHook(0xE8, 0x007C7D0C, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C7D46, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7D89, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7DD8, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7E1D, &LoadWindowsNone);
	//-- Window 6 Guild User
	SetCompleteHook(0xE8, 0x007CB6F6, &LoadWindows);
	SetCompleteHook(0xE8, 0x007CB72A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB767, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB7B0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB7EF, &LoadWindowsNone);
	//-- Window 7 Guild Maker
	SetCompleteHook(0xE8, 0x007D1786, &LoadWindows);
	SetCompleteHook(0xE8, 0x007D17BA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D17F7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D1840, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D187F, &LoadWindowsNone);
	//-- Window 8 Store
	//-- Window 9 MuHelper
	SetCompleteHook(0xE8, 0x007F65A6, &LoadWindows);
	SetCompleteHook(0xE8, 0x007F65E6, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F6638, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F66A2, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F66FA, &LoadWindowsNone);
	//-- Window 10 Config Helper
	SetCompleteHook(0xE8, 0x0080C848, &LoadWindows);
	SetCompleteHook(0xE8, 0x0080C87C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C8BC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C90E, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C954, &LoadWindowsNone);
	//-- Window 11 ChaosMachine
	SetCompleteHook(0xE8, 0x0082CA22, &WindowsChaosBox);
	SetCompleteHook(0xE8, 0x0082CB4B, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CB00, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CAA5, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CA5C, &LoadWindowsNone);
	//-- Window 12
	SetCompleteHook(0xE8, 0x00836EF6, &LoadWindows);
	SetCompleteHook(0xE8, 0x00836F2A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836F67, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836FB0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836FEF, &LoadWindowsNone);
	//-- Window 13 Quest (T)
	SetCompleteHook(0xE8, 0x0083EA46, &LoadWindows);
	SetCompleteHook(0xE8, 0x0083EA7A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EAB7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EB00, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EB3F, &LoadWindowsNone);
	//-- Window 14
	SetCompleteHook(0xE8, 0x00841E49, &LoadWindows);
	SetCompleteHook(0xE8, 0x00841E7D, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841EBA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841F03, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841F42, &LoadWindowsNone);
	//-- Window 15 Gens-Quest
	SetCompleteHook(0xE8, 0x00843826, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084385A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00843897, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008438E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084391F, &LoadWindowsNone);
	//-- Window 16
	SetCompleteHook(0xE8, 0x00845956, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084598A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008459C7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00845A10, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00845A4F, &LoadWindowsNone);
	//-- Window 17
	SetCompleteHook(0xE8, 0x008470A6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008470DA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00847117, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00847160, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084719F, &LoadWindowsNone);
	//-- Window 18




	//-- Window 1
	SetCompleteHook(0xE8, 0x0077F209, &LoadWindows);
	SetCompleteHook(0xE8, 0x0077F23D, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0077F27A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0077F2C3, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0077F302, &LoadWindowsNone);
	//-- Window 1
	SetCompleteHook(0xE8, 0x00894226, &LoadWindows);
	SetCompleteHook(0xE8, 0x0089425A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00894297, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008942E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0089431F, &LoadWindowsNone);
	//-- Window 4
	SetCompleteHook(0xE8, 0x00850966, &LoadWindows);
	SetCompleteHook(0xE8, 0x0085099A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008509D7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00850A20, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00850A5F, &LoadWindowsNone);
	//-- Window 5
	SetCompleteHook(0xE8, 0x00852476, &LoadWindows);
	SetCompleteHook(0xE8, 0x008524AA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008524E7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00852530, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0085256F, &LoadWindowsNone);
	//-- Window 6
	SetCompleteHook(0xE8, 0x008540B6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008540EA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00854127, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00854170, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008541AF, &LoadWindowsNone);
	//-- Window 8
	SetCompleteHook(0xE8, 0x0087F886, &LoadWindows);
	SetCompleteHook(0xE8, 0x0087F8BA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F8F7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F940, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F97F, &LoadWindowsNone);
	//-- Window 9 NPC CASTLE SIEGE
	SetCompleteHook(0xE8, 0x00882F52, &LoadWindows);
	SetCompleteHook(0xE8, 0x00882F8C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00882FD5, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00883030, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0088307B, &LoadWindowsNone);
	//-- Windows NPC Lugar
	SetCompleteHook(0xE8, 0x00893102, &LoadWindows);
	SetCompleteHook(0xE8, 0x0089313C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00893185, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008931E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0089322B, &LoadWindowsNone);
	//-- Windows Guard NPC
	SetCompleteHook(0xE8, 0x008812A2, &LoadWindows);
	SetCompleteHook(0xE8, 0x008812DC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00881325, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00881380, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008813CB, &LoadWindowsNone);
	//-- Windows NPC Senior
	SetCompleteHook(0xE8, 0x00879EE2, &LoadWindows);
	SetCompleteHook(0xE8, 0x00879F1C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00879F65, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00879FC0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087A00B, &LoadWindowsNone);
	//-- Windows BloodCastle
	SetCompleteHook(0xE8, 0x008747B6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008747F0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087483C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008748A0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008748F2, &LoadWindowsNone);
	//-- Windows DevilSquare
	SetCompleteHook(0xE8, 0x008781BC, &LoadWindows);
	SetCompleteHook(0xE8, 0x008781F0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00878230, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00878282, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008782C8, &LoadWindowsNone);
	//-- Windows Pet
	SetCompleteHook(0xE8, 0x0084D01A, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084D05A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D0AC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D116, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D16E, &LoadWindowsNone);
	//-- Windows Party
	SetCompleteHook(0xE8, 0x0084A546, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084A57A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A5BA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A60C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A652, &LoadWindowsNone);
	//--
	SetCompleteHook(0xE8, 0x007E020C, &PetSpiritHP); //-- PAJARRACO
	SetCompleteHook(0xE8, 0x007E0298, &PetSpiritHP); //-- PAJARRACO

	/*SetRange((LPVOID)0x00864B12, 5, ASM::NOP);
	SetRange((LPVOID)0x00864B92, 5, ASM::NOP);
	SetRange((LPVOID)0x008647F8, 5, ASM::NOP);
	SetCompleteHook(0xE9, 0x00864A6E, &RenderText2Trade);
	SetCompleteHook(0xE9, 0x00864A36, &RenderText1Trade);
	SetCompleteHook(0xE9, 0x0086497C, &RenderTextTrade);
	SetCompleteHook(0xE9, 0x00864386, &RenderTrade);

	SetCompleteHook(0xE9, 0x0084D189, &SetTittlePet);
	SetCompleteHook(0xE8, 0x0084D01A, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084D05A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D0AC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D116, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D16E, &LoadWindowsNone);

	SetCompleteHook(0xE9, 0x0084A0E9, &SetCloseParty);
	SetCompleteHook(0xE9, 0x0084A67A, &SetTittleParty);
	SetCompleteHook(0xE8, 0x0084A546, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084A57A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A5BA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A60C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A652, &LoadWindowsNone);

	SetRange((LPVOID)0x0083E6A0, 5, ASM::NOP);
	SetCompleteHook(0xE9, 0x0083ED80, &RenderInfoQuest1);
	SetCompleteHook(0xE9, 0x0083EDDE, &RenderInfoQuest2);
	SetCompleteHook(0xE9, 0x0083F760, &RenderText9Quest);
	SetCompleteHook(0xE9, 0x0083F9E8, &RenderText8Quest);
	SetCompleteHook(0xE9, 0x0083F9B0, &RenderText7Quest);
	SetCompleteHook(0xE9, 0x0083F958, &RenderText6Quest);
	SetCompleteHook(0xE9, 0x0083F8A4, &RenderText5Quest);
	SetCompleteHook(0xE9, 0x0083F86C, &RenderText4Quest);
	SetCompleteHook(0xE9, 0x0083F814, &RenderText3Quest);
	SetCompleteHook(0xE9, 0x0083F728, &RenderText2Quest);
	SetCompleteHook(0xE9, 0x0083F6D0, &RenderText1Quest);
	SetCompleteHook(0xE9, 0x0083F4E7, &RenderQuestTabPane1);
	SetCompleteHook(0xE9, 0x0083F516, &RenderQuestTabPane2);
	SetCompleteHook(0xE9, 0x0083F54C, &RenderQuestTabPane3);
	SetCompleteHook(0xE9, 0x0083F582, &RenderQuestTabPane4);
	SetCompleteHook(0xE8, 0x0083F618, &RenderButtonQuestTb);
	SetCompleteHook(0xE8, 0x0083F690, &RenderButtonQuestTb);
	SetCompleteHook(0xE8, 0x0083F7D4, &RenderButtonQuestTb);
	SetCompleteHook(0xE8, 0x0083F918, &RenderButtonQuestTb);
	SetCompleteHook(0xE9, 0x0083EA16, &RenderWindowsQuest);

	//SetRange((LPVOID)0x007F6753, 5, ASM::NOP);

	//SetCompleteHook(0xE9, 0x007F6577, &RenderWindowsMuHelper);
	//--
	SetCompleteHook(0xE9, 0x00843B87, &RenderGensPointInfo);
	SetCompleteHook(0xE9, 0x00843D9D, &RenderGensPointText);
	SetCompleteHook(0xE8, 0x00843D4F, &RenderGensPointTexture);
	SetCompleteHook(0xE8, 0x0084371E, &RenderWindowsGensBattle);
	SetCompleteHook(0xE9, 0x00843B09, &RenderTittleQuestGlobal);
	//--
	SetCompleteHook(0xE9, 0x00841E26, &RenderWindowsStore);
	SetCompleteHook(0xE9, 0x0078E497, &RenderTittleCommand);
	SetCompleteHook(0xE9, 0x0078E6A6, &RenderWindowsComand);
	//--
	SetRange((LPVOID)0x00858016, 5, ASM::NOP);
	SetRange((LPVOID)0x00857898, 5, ASM::NOP);
	SetCompleteHook(0xE9, 0x00857923, &RenderWindowsBaul);
	SetCompleteHook(0xE9, 0x007D1763, &RenderWindowsGuildMaker);
	//-- WINDOWS SHOP
	SetCompleteHook(0xE9, 0x00847076, &WindowsShop);
	SetRange((LPVOID)0x00847036, 5, ASM::NOP);
	SetRange((LPVOID)0x00847046, 5, ASM::NOP);
	//-- WINDOWS INVENTORY EXT.
	SetCompleteHook(0xE8, 0x007D5576, &RenderWindowsExt);
	SetRange((LPVOID)0x007D4FA6, 5, ASM::NOP);
	SetCompleteHook(0xE9, 0x0083C5CF, &RenderMoveSlotExt);*/
}