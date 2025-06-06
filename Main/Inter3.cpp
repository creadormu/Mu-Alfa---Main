#include "stdafx.h"
#include "Inter3.h"
#include "Defines.h"
#include "Interface.h"
#include "TMemory.h"
#include "User.h"
#include "Offset.h"
#include "Import.h"
#include "Util.h"
#include "Protect.h"
#include "postInterface.h"
#include "InterEx.h"
#include "SItemOption.h"
#include "WindowsStruct.h"
#include "Common.h"
#include "OffTrade.h"
#include "NPCRuud.h"

__declspec(naked) void DrawAGPosition()
{
	static float AGPositionW = 14.0f;
	static float AGPositionH = 36.0f;
	static float AGPositionX = 551.5f;
	static float AGPositionY = 435.7f;
	static DWORD AGPosition_buff = 0x008102AD;

	_asm
	{	
		FLD DWORD PTR DS:[AGPositionW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[AGPositionH]
		FSTP DWORD PTR SS:[EBP-0x14]
		FLD DWORD PTR DS:[AGPositionX]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[AGPositionY]
		FSTP DWORD PTR SS:[EBP-0x0C]
		jmp [AGPosition_buff]
	}
}

__declspec(naked) void DrawSDPosition()
{
	static float SDPositionW = 14.0f;
	static float SDPositionH = 36.0f;
	static float SDPositionX = 73.0f;
	static float SDPositionY = 435.7f;
	static DWORD SDPosition_buff = 0x0081057D;

	_asm
	{	
		FLD DWORD PTR DS:[SDPositionW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SDPositionH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		FLD DWORD PTR DS:[SDPositionX]
		FSTP DWORD PTR SS:[EBP-0x10]
		FLD DWORD PTR DS:[SDPositionY]
		FSTP DWORD PTR SS:[EBP-0x0C] 
		jmp [SDPosition_buff]
	}
}
//--------------------------------------------
__declspec(naked) void DrawMANAPosition()
{
	static float MANAPositionW = 52.0f;
	static float MANAPositionX = 488.7f;
	static float MANAPositionH = 51.0f;
	static float MANAPositionY = 429.0f;
	static DWORD MANAPosition_buff = 0x0080FFD0;

	_asm
	{	
		FLD DWORD PTR DS:[MANAPositionW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[MANAPositionX]
		FSTP DWORD PTR SS:[EBP-0x0C]
		FLD DWORD PTR DS:[MANAPositionH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		FLD DWORD PTR DS:[MANAPositionY]
		FSTP DWORD PTR SS:[EBP-0x8]
		jmp [MANAPosition_buff]
	}
}
//--------------------------------------------
__declspec(naked) void DrawHPPosition()
{
	static float HPPositionW = 52.0f;
	static float HPPositionH = 51.0f;
	static float HPPositionX = 98.0f;
	static float HPPositionY = 429.0f;
	static DWORD HPPosition_buff = 0x0080FD7C;

	_asm
	{             
		FLD DWORD PTR DS:[HPPositionW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[HPPositionX]
		FSTP DWORD PTR SS:[EBP-0x0C]
		FLD DWORD PTR DS:[HPPositionH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		FLD DWORD PTR DS:[HPPositionY]
		FSTP DWORD PTR SS:[EBP-0x8]
		jmp [HPPosition_buff]
	}
}
//--------------------------------------------
__declspec(naked) void DrawUsingSkillPosition()
{
	static float UsingSkillPositionX = 310.0f;
	static float UsingSkillPositionY = 447.0f;
	static float UsingSkillPositionW = 20.0f;
	static float UsingSkillPositionH = 28.0f;
	static DWORD UsingSkillPosition_buff = 0x00813900;

	_asm
	{
		FLD DWORD PTR DS:[UsingSkillPositionX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[UsingSkillPositionY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[UsingSkillPositionW]
		FSTP DWORD PTR SS:[EBP-0x18]
		FLD DWORD PTR DS:[UsingSkillPositionH]
		FSTP DWORD PTR SS:[EBP-0x14]
		jmp [UsingSkillPosition_buff]
	}
}

__declspec(naked) void DrawSkillBarDrawPosition()
{
	static float SkillBarDrawPositionX = 222.0f;
	static float SkillBarDrawPositionY = 480.0f;
	static float SkillBarDrawPositionW = 160.0f;
	static float SkillBarDrawPositionH = 38.0f;
	static DWORD SkillBarDrawPosition_buff = 0x00812968;

	_asm
	{	
		FLD DWORD PTR DS:[SkillBarDrawPositionX]
		FSTP DWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR DS:[SkillBarDrawPositionY]
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR DS:[SkillBarDrawPositionW]
		FSTP DWORD PTR SS:[EBP-0x20]
		FLD DWORD PTR DS:[SkillBarDrawPositionH]
		FSTP DWORD PTR SS:[EBP-0x1C]
		jmp [SkillBarDrawPosition_buff]
	}
}

__declspec(naked) void DrawHPNumberPosition()
{
	static float HPNumberPositionX = 45.0f;
	static DWORD HPNumberPosition_buff = 0x0080FF1E;
	_asm
	{
	FADD DWORD PTR DS:[HPNumberPositionX]
	FSTP DWORD PTR SS:[EBP-0x19C]
	FLD DWORD PTR SS:[EBP-0x19C]
	jmp [HPNumberPosition_buff]
	}
}

__declspec(naked) void DrawMasterButton()
{
	static DWORD MasterButtonAddress1 = 0x0077ED20;
	_asm
	{
		jmp [MasterButtonAddress1]
	}
}

__declspec(naked) void DrawHelperAll()
{
	static DWORD HelperStopAddress1 = 0x007D28B4;
	_asm
	{
		jmp [HelperStopAddress1]
	}
}

__declspec(naked) void ItemSlot()
{
	static float Alpha = 1.0000000; // Power color (0.6000000)
	static float ColorR = 0.0000000; // Color R (0.5000000)
	static float ColorG = 0.0000000; // Color G (0.5000000)
	static float ColorB = 0.0000000; // Color B (0.3000000)
	static DWORD m_ReturnChadowColor = 0x007DB338;

	_asm
	{
		FLD DWORD PTR DS:[Alpha]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[ColorB]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[ColorG]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[ColorR]
		JMP[m_ReturnChadowColor]
	}
}

__declspec(naked) void ItemSlotRepair_1()
{
	static float Alpha = 1.0000000; // Power color (0.60000002)
	static float ColorR = 0.0000000; // Color R (1.0)
	static float ColorG = 0.0000000; // Color G (1.0)
	static float ColorB = 0.0000000; // Color B (0.3000000)
	static DWORD m_ReturnChadowColor = 0x007DB36B;

	_asm
	{
		FLD DWORD PTR DS:[Alpha]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLDZ
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD1
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD1
		JMP[m_ReturnChadowColor]
	}
}

__declspec(naked) void ItemSlotRepair_2()
{
	static float Alpha = 1.0000000; // Power color (0.40000001)
	static float ColorR = 0.0000000; // Color R (1.0)
	static float ColorG = 0.0000000; // Color G (0.66000003)
	static float ColorB = 0.0000000; // Color B (0.0)
	static DWORD m_ReturnChadowColor = 0x007DB3A2;

	_asm
	{
		FLD DWORD PTR DS:[Alpha]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLDZ
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[ColorG]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD1
		JMP[m_ReturnChadowColor]
	}
}

__declspec(naked) void ItemSlotRepair_3()
{
	static float Alpha = 1.0000000f; // Power color (0.40000001)
	static float ColorR = 0.8800000f; // Color R (1.0)
	static float ColorG = 0.01100001f; // Color G (0.33000001)
	static float ColorB = 0.0000000f; // Color B (0.0000000)
	static DWORD m_ReturnChadowColor = 0x007DB3D9;

	_asm
	{
		FLD DWORD PTR DS:[Alpha]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLDZ
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[ColorG]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD1
		JMP[m_ReturnChadowColor]
	}
}
//---------------------------------------------
//EXP
__declspec(naked) void DrawEXP1()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP1_buff = 0x00811408;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR SS:[EBP-0x1B0]
	FMUL QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXP1_buff]
	}
}

__declspec(naked) void DrawEXP2()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP2_buff = 0x00811552;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR SS:[EBP-0x1C4]
	FMUL QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXP2_buff]
	}
}

__declspec(naked) void DrawEXP3()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP3_buff = 0x00811719;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR SS:[EBP-0x1B0]
	FMUL QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXP3_buff]
	}
}

__declspec(naked) void DrawEXP4()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXP4_buff = 0x0081181F;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	FLD QWORD PTR SS:[EBP-0x20]
	jmp [EXP4_buff]
	}
}

//EXP MASTER
__declspec(naked) void DrawEXPMASTER1()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AltoTex = 5.8f;
	static double AnchoTex = 198.0f;
	static DWORD EXPMASTER1_buff = 0x00810B6E;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR SS:[EBP-0x58]
	FMUL QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER1_buff]
	}
}

__declspec(naked) void DrawEXPMASTER2()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXPMASTER2_buff = 0x00810CB5;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR SS:[EBP-0x88]
	FMUL QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER2_buff]
	}
}

__declspec(naked) void DrawEXPMASTER3()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXPMASTER3_buff = 0x00810E79;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR SS:[EBP-0x58]
	FMUL QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER3_buff]
	}
}

__declspec(naked) void DrawEXPMASTER4()
{
	static double Ancho = 221.0f;
	static double Alto = 435.0f;
	static double AnchoTex = 198.0f;
	static double AltoTex = 5.8f;
	static DWORD EXPMASTER4_buff = 0x00810F73;
	_asm
	{
	FLD QWORD PTR DS:[Ancho]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[Alto]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR DS:[AnchoTex]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[AltoTex]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER4_buff]
	}
}
//---------------------------------------------
//Character
int CClassicUICharacterInfoWindow(int a1)
{
  int v42; // ST24_4@1
  float green; // ST08_4@1
  float red; // ST04_4@1

  v42 = a1;
  green = (double)*(signed int *)(a1 + 20);
  red =   (double)*(signed int *)(a1 + 16);
  pDrawGUI(31352, red, green, 190.0, 433.0);
//
  int DL = pGetCharClass(*(BYTE *)(oUserPreviewStruct + 19));
  if ( DL == 4 )
  {
	  green = (double)*(signed int *)(a1 + 20);
	  red = (double)*(signed int *)(a1 + 16);
	  pDrawGUI(51291, red, green, 190.0, 433.0);
  }

  int Class = pGetCharClass(*(BYTE *)(oUserPreviewStruct + 19));
  if ( Class == 3 || Class == 5 || Class == 6)
  {
	  green = (double)*(signed int *)(a1 + 20);
	  red = (double)*(signed int *)(a1 + 16);
	  pDrawGUI(51292, red, green, 190.0, 433.0);
  }
//
  return a1;
}

//----- (005B9260) --------------------------------------------------------
#define sub_5B9260		((void(__cdecl*)(float a1, float a2, float a3, float a4, float a5, char a6, char a7)) 0x005B9260)

//----- (007DFA60) --------------------------------------------------------
void PetHPBarRemake(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9)
{	
	float v15; // ST30_4@4
	float v16; // ST10_4@4

	float reposicionX = 59.0f;
	int a3 = 0;

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
		a3 = 380;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			a3 = 380;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				a3 = 380;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					a3 = 380;
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
						a3 = 190;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								a3 = 380;
							}
							else
							{
								a3 = 190;
							}	
						}
						else
						{
							a3 = 0;
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
			a3 = 640;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			a3 = 640;
	}
	
	if (pPartyMemberCount > 0)
	{
		reposicionX = 59.0f + 80.0f;
	}

	x =  640.0f - reposicionX - a3;
	y = 20;

	pSetBlend(1);

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 200);
	pDrawText(pTextThis(), x + 28, y + 5,  (LPCTSTR)nameIndex, 0, 0, (LPINT)8, 0);

	v15 = (double)hp / (double)hpmax * 50.0;
	v16 = (float)(y + 16);

	sub_5B9260((float)x, v16, 50.0, 4.0, v15, 0, 1);
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
}

//----- (007DFA60) --------------------------------------------------------
void PetSpiritHPBarRemake(signed int x, signed int y, int nameIndex, signed int hp, signed int hpmax, char a9)
{
	
	float v15; // ST30_4@4
	float v16; // ST10_4@4

	float reposicionX = 59.0f;
	int a3 = 0;

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
		a3 = 380;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			a3 = 380;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				a3 = 380;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					a3 = 380;
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
						a3 = 190;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								a3 = 380;
							}
							else
							{
								a3 = 190;
							}	
						}
						else
						{
							a3 = 0;
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
			a3 = 640;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			a3 = 640;
	}

	if(a3 > 190){
		return;
	}

	if (pPartyMemberCount > 0)
	{
		reposicionX = 59.0f + 80.0f;
	}

	
	x =  640.0f - reposicionX - gInterface.PetX -a3;

	y = 20;

	pSetBlend(1);

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 200);
	pDrawText(pTextThis(), x + 28, y + 5,  (LPCTSTR)nameIndex, 0, 0, (LPINT)8, 0);

	v15 = (double)hp / (double)hpmax * 50.0;
	v16 = (float)(y + 16);

	sub_5B9260((float)x, v16, 50.0, 4.0, v15, 0, 1);
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
}

__declspec(naked) void SlideShow()
{
	static DWORD Addr = 0x00425489;
	static DWORD CallMe = 0x00417EC0;
	_asm
	{
		PUSH 429                                   ; /Arg2 = 00000000
		PUSH 0                                   ; |Arg1 = 00000000
		MOV ECX,DWORD PTR SS:[EBP - 0x4]             ; |
		ADD ECX,0x4                                ; |
		CALL CallMe                      ; \main1.00417EC0
		PUSH 429                                   ; /Arg2 = 00000000
		PUSH 0                                   ; |Arg1 = 00000000
		MOV ECX,DWORD PTR SS:[EBP - 0x4]             ; |
		ADD ECX, 0x8EC                              ; |
		CALL CallMe                      ; \main1.00417EC0
		JMP [Addr]                                   ; /Timerproc = NULL
	}
}

//===========================
//-- Slot [Q],[W],[E],[R]
//===========================
__declspec(naked) void RenderSlotDwongradeQ()
{
	static DWORD Addr_JMP = 0x00895A73;
	static float RenderPotionY = 453.0f;
	static float RenderPotionX = 210.0f;
	static float RenderNumberY = 445.0f;
	static float RenderNumberX = 227.0f;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[RenderNumberY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg3
		FLD DWORD PTR DS:[RenderNumberX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg2
		FLD DWORD PTR DS:[RenderPotionY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg1
		FLD DWORD PTR DS:[RenderPotionX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x18]          ; |
		JMP [Addr_JMP]                           ; \main1.008977D0
	}
}

__declspec(naked) void RenderSlotDwongradeW()
{
	static DWORD Addr_JMP = 0x00895AE8;
	static float RenderPotionY = 453.0f;
	static float RenderPotionX = 240.0f;
	static float RenderNumberY = 445.0f;
	static float RenderNumberX = 257.0f;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[RenderNumberY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg3
		FLD DWORD PTR DS:[RenderNumberX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg2
		FLD DWORD PTR DS:[RenderPotionY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg1
		FLD DWORD PTR DS:[RenderPotionX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x20]          ; |
		JMP [Addr_JMP]                           ; \main1.00897BD0
	}
}

__declspec(naked) void RenderSlotDwongradeE()
{
	static DWORD Addr_JMP = 0x00895B5D;
	static float RenderPotionY = 453.0f;
	static float RenderPotionX = 270.0f;
	static float RenderNumberY = 445.0f;
	static float RenderNumberX = 287.0f;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[RenderNumberY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg3
		FLD DWORD PTR DS:[RenderNumberX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg2
		FLD DWORD PTR DS:[RenderPotionY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg1
		FLD DWORD PTR DS:[RenderPotionX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x28]          ; |
		JMP [Addr_JMP]                           ; \main1.00895760
	}
}

__declspec(naked) void DrawNopRShortKey()
{
	static DWORD RButtonAddress = 0x00895C0C;
	_asm{jmp RButtonAddress}
}

__declspec(naked) void DrawInterfaceS2DisableR()
{
	static DWORD RButtonAddress = 0x00895C0C;
	_asm{jmp RButtonAddress}
}

//===========================
//-- SkillRenderizado
//===========================
bool Render_SkillFullMouser(DWORD a1)
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
			//-- skill en uso
			v82 = 310.0;
			v87 = 445.0f;
			v70 = 25.0f;
			v75 = 32.0f;
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
								v83 = 330.0;
								v88 = 480.0f;
								v71 = 100.0;
								v76 = 20.0;
								if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
								{
									if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) )
									{
										if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 != 1 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
										{
										//-- DrawSkill Bar Slot 5
											v84 = 315.0;
											v89 = 480.0f;
											v72 = 20.0;
											v68 = 0;
											v67 = *(BYTE *)(v62 + 20) != 1 ? 1 : 6;
											while ( v68 < 5 )
											{
												v84 = v84 + v72;
												if ( v67 == 10 )
													v67 = 0;
												if ( pCheckMouseOver(v84, v89, v72, (float)32.0) == 1 )
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
												if ( *(BYTE *)0x8793384 || pCheckMouseOver((float)330.0, (float)480.0f, (float)100.0, (float)32.0))
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
												v90 = 390.0;//-- y
												v73 = 32.0;//-- w
												v77 = 38.0;//-- h
												v79 = 302.0;//-- x
												v81 = *(DWORD *)(v62 + 80);
												for ( i = 0; i < 150; ++i )
												{
													v69 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);
													if ( v69 && ((signed int)v69 < 67 || (signed int)v69 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v69 + 55) != 3 )
													{
														if ( v80 == 11 )
															v90 = v90 - v77;
														if ( v80 >= 11 )
														{
															if ( v80 < 11 || v80 > 21 )
																v85 = v79 - v73 * 11.0 + (double)(v80 - 21) * v73;
															else
																v85 = v79 - v73 * 6.0 + (double)(v80 - 10) * v73;
														}
														else
														{
															v64 = v80 / 2;
															if ( v80 % 2 )
																v85 = v79 - (double)(v64 + 1) * v73;
															else
																v85 = (double)v64 * v73 + v79;
														}
														++v80;
														if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
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
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
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
														v91 = 350.0;
														v74 = 32.0;
														for ( j = 150; j < 154; ++j )
														{
															if ( pCheckMouseOver(v86, v91, v74, (float)38.0) == 1 )
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

void RenderSkill_Raven(DWORD *a1)
{
	float v4; // ST18_4@7
	float v5; // ST14_4@7
	int v6; // [sp+18h] [bp-18h]@1
	signed int i; // [sp+1Ch] [bp-14h]@2
	float v8; // [sp+20h] [bp-10h]@2
	float v9; // [sp+24h] [bp-Ch]@2
	float v10; // [sp+28h] [bp-8h]@2
	float v11; // [sp+2Ch] [bp-4h]@2

	v6 = *(DWORD *)a1;
	if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
	{
		v10 = 270.0;//X
		v11 = 350.0;//Y
		v8 = 32.0;
		v9 = 38.0;
		for ( i = 150; i < 154; ++i )
		{
			if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )
				pDrawGUI(31313, v10, v11, v8, v9);
			else
				pDrawGUI(31312, v10, v11, v8, v9);
			v4 = v11 + 6.0;
			v5 = v10 + 6.0;
			RenderShowSkill(a1, i, v5, v4, 20.0, 28.0);
			v10 = v10 + v8;
		}
	}
}

void Render_Funcion_772EA0(int ThisR)
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

char Render_SkillBarSwitch(int This)
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

	v7 = This;

	if ( (signed int)*(BYTE *)(*(DWORD *)0x8128AC8 + 118) > 0 && *(BYTE *)(v7 + 64) == 1 )
	{
		v17 = 390.0;//Y
		v13 = 32.0;
		v14 = 38.0;
		v10 = 302.0;//X
		v11 = 0;

		for ( i = 0; i < 150; ++i )
		{
			v12 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);

			if ( *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120) && (v12 < 67 || v12 > 72) )
			{
				v9 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v12 + 55);
				if ( v9 != 1 && v9 != 3 )
				{
					if ( v11 == 11 )
					{
						v17 = v17 - v14;
					}
					if ( v11 >= 11 )
					{
						if ( v11 < 11 || v11 > 21 )
						{
							v16 = v10 - v13 * 11.0 + (double)(v11 - 21) * v13;
						}
						else
						{
							v16 = v10 - v13 * 6 + (double)(v11 - 10) * v13;
						}
					}
					else
					{
						v8 = v11 / 2;
						if ( v11 % 2 )
						{
							v16 = v10 - (double)(v8 + 1) * v13;
						}
						else
						{
							v16 = (double)v8 * v13 + v10;
						}
					}
					
					++v11;

					if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )//-- Seleccionado
					{
						pDrawGUI(31313, v16, v17, v13, v14);
					}
					else
					{
						pDrawGUI(31312, v16, v17, v13, v14);
					}
					v4 = v17 + 6.0;
					v5 = v16 + 6.0;
					RenderShowSkill((DWORD *)This, i, v5, v4, 20.0, 28.0);
				}
			}
		}
		RenderSkill_Raven((DWORD *)This);
	}

	if ( *(BYTE *)(This + 65) == 1 && *(DWORD *)(This + 16) )
	{
		Render_Funcion_772EA0(This);
		*(BYTE *)(This + 65) = 0;
	}
	return 1;
}

void RenderSkillTooltip(int x, int y, int nCount, int witd, int height,int type, int Align)
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

//----- (0080F270) --------------------------------------------------------
void sub_80F270(int This)
{
	//pDrawPuntero(This + 460, 1, 61529, 0, 0, 0);
	//ChangeButtonInfo((char *)(This + 56), 489, 429, 30, 41);//-- CashShop
	pDrawPuntero(This + 228, 1, 31461, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 228), 378.5f, 451, 25, 25);//-- Character

	pDrawPuntero(This + 400, 1, 31461, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 400), 409.0f, 451, 25, 25);//-- Inventory

	pDrawPuntero(This + 572, 1, 31461, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 572), 581.0f, 433, 52, 18);//-- Friend

	pDrawPuntero(This + 744, 1, 31461, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 744), 6.0f, 433, 53, 19);//-- Friend
}

__declspec(naked) void DrawInterfaceButton()
{
	static DWORD Addr_JMP = 0x0080F73E;
	static DWORD This;

	_asm
	{
		MOV DWORD PTR SS:[EBP-28],ECX
		MOV EDX,DWORD PTR SS:[EBP-28]
		MOV This, EDX
	}
	
	sub_80F270(This);
	
	_asm
	{

		JMP[Addr_JMP]
	}
}
void DowngradeInventoryWindows(DWORD id, float x, float y, float w, float h)
{
	//-- NPC RUUD
//=============================
	jCRenderRuud.OpenRuud();
//=============================
	pDrawGUI(61522, x, y, w, h);
}

void DowngradeLoadWindows(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(61522, x, y, w, h);
}

void DowngradeStoreLoadWindows(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(61522, x, y, w, h);

	gOffTrade.DrawOffTradeWindow(x, y);
}

void DowngradeLoadWindowsNone(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(51522, x, y, w, h);
}

DWORD RenderSlot;
__declspec(naked) void ShadowColorCheck()
{
	static DWORD jmpBack = 0x007DB30F;

	__asm
	{
		mov     eax, [ebp - 0x1C]
		movzx   ecx, byte ptr[eax + 0x60]
		mov		RenderSlot, ecx
		jmp     [jmpBack]
	}
}

void RenderItemBox(DWORD ID, float x, float y, float w, float h)
{
	RenderBitmap(31072, x, y, w, h, 0, 0, 1.0, 1.0, 1, 1, 0.0);

	switch (RenderSlot)
	{
		case 0:
		break;
		case 1:
			glColor4f(1.0, 1.0, 0.0, 0.30000001);//glColor4f(1.0, 1.0, 0.0, 0.60000001);
		break;
		case 2:
			glColor4f(1.0, 0.66000003, 0.0, 0.30000001);//glColor4f(1.0, 0.66000003, 0.0, 0.60000001);
		break;
		case 3:
			glColor4f(0.89000001, 0.10900001, 0.10900001, 0.30000001);//glColor4f(1.0, 0.33000001, 0.0, 0.60000001);
		break;
		case 4:
			glColor4f(1.0, 0.0, 0.0, 0.40000001);
		break;
		case 5:
			glColor4f(1.0, 0.2, 0.1, 0.40000001);
		break;
		default:
			RenderBitmap(31071, x, y, w, h, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		break;
	}

	if(RenderSlot >= 1 && RenderSlot <= 5)
	{
		pSetBlend(true);
		pDrawBarForm(x, y, w, h, 0.0, 0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
	}

	RenderSlot = -1;
}

void InitInter3()
{
//--------------------------------
// Nuevo Código Interface Downgrade
//--------------------------------
	RenderSlot = -1;
	SetCompleteHook(0xE9, 0x007DB308, &ShadowColorCheck); //Get Slot Type
	SetCompleteHook(0xE8, 0x007DB5D0, &RenderItemBox);

	//--
	//-- Windows Command
	SetCompleteHook(0xE8, 0x0078E6D6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0078E70A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0078E74A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0078E79C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0078E7E2, &DowngradeLoadWindowsNone);

	//-- Windows Helper
	SetCompleteHook(0xE8, 0x007F65A6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x007F65E6, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F6638, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F66A2, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F66FA, &DowngradeLoadWindowsNone);
	//-- Windows MuHelper2
	SetCompleteHook(0xE8, 0x0080C848, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0080C87C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C8BC, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C90E, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C954, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido1
	SetCompleteHook(0xE8, 0x00845956, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0084598A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008459C7, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00845A10, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00845A4F, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido2
	SetCompleteHook(0xE8, 0x007C6BCC, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x007C6C06, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6C49, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6C98, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6CDD, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido3
	SetCompleteHook(0xE8, 0x007C7D0C, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x007C7D46, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7D89, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7DD8, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7E1D, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido4
	SetCompleteHook(0xE8, 0x00850966, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0085099A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008509D7, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00850A20, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00850A5F, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido5
	SetCompleteHook(0xE8, 0x00852476, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x008524AA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008524E7, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00852530, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0085256F, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido6
	SetCompleteHook(0xE8, 0x008540B6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x008540EA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00854127, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00854170, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008541AF, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido7
	SetCompleteHook(0xE8, 0x00868052, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0086808C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008680D5, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00868130, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0086817B, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido8
	SetCompleteHook(0xE8, 0x0087F886, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0087F8BA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F8F7, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F940, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F97F, &DowngradeLoadWindowsNone);
	//-- Windows Desconocido9 NPC CASTLE SIEGE
	SetCompleteHook(0xE8, 0x00882F52, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x00882F8C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00882FD5, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00883030, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0088307B, &DowngradeLoadWindowsNone);
	//-- Windows NPC Lugar
	SetCompleteHook(0xE8, 0x00893102, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0089313C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00893185, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008931E0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0089322B, &DowngradeLoadWindowsNone);
	//-- Windows Guard NPC
	SetCompleteHook(0xE8, 0x008812A2, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x008812DC, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00881325, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00881380, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008813CB, &DowngradeLoadWindowsNone);
	//-- Windows NPC Senior
	SetCompleteHook(0xE8, 0x00879EE2, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x00879F1C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00879F65, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00879FC0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087A00B, &DowngradeLoadWindowsNone);
	//-- Windows BloodCastle
	SetCompleteHook(0xE8, 0x008747B6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x008747F0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087483C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008748A0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008748F2, &DowngradeLoadWindowsNone);
	//-- Windows DevilSquare
	SetCompleteHook(0xE8, 0x008781BC, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x008781F0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00878230, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00878282, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008782C8, &DowngradeLoadWindowsNone);
	//-- Windows Pet
	SetCompleteHook(0xE8, 0x0084D01A, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0084D05A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D0AC, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D116, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D16E, &DowngradeLoadWindowsNone);
	//-- Windows Party
	SetCompleteHook(0xE8, 0x0084A546, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0084A57A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A5BA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A60C, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A652, &DowngradeLoadWindowsNone);
	//-- Windows ChaosMachine
	SetCompleteHook(0xE8, 0x0082CA22, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0082CB4B, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CB00, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CAA5, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CA5C, &DowngradeLoadWindowsNone);
	//-- Windows Store
	SetCompleteHook(0xE8, 0x00841E49, &DowngradeStoreLoadWindows);
	SetCompleteHook(0xE8, 0x00841E7D, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841EBA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841F03, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841F42, &DowngradeLoadWindowsNone);
	//-- Windows Store Other PJ
	SetCompleteHook(0xE8, 0x0084F406, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0084F43A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F477, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F4C0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F4FF, &DowngradeLoadWindowsNone);
	//-- Windows Baul
	SetCompleteHook(0xE8, 0x00857946, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0085797A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008579B7, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00857A00, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00857A3F, &DowngradeLoadWindowsNone);
	//-- Windows Baul Ext.
	SetCompleteHook(0xE8, 0x008567E6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0085681A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00856857, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008568A0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008568DF, &DowngradeLoadWindowsNone);
	//-- Windows Inventory
	SetCompleteHook(0xE8, 0x00836EF6, &DowngradeInventoryWindows);
	SetCompleteHook(0xE8, 0x00836F2A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836F67, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836FB0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836FEF, &DowngradeLoadWindowsNone);
	//-- Windows Inventory Ext.
	SetCompleteHook(0xE8, 0x007D55A6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x007D55DA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D5617, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D5660, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D569F, &DowngradeLoadWindowsNone);
	//-- Windows Shop.
	SetCompleteHook(0xE8, 0x008470A6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x008470DA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00847117, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00847160, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084719F, &DowngradeLoadWindowsNone);
	//-- Windows GuildMarker
	SetCompleteHook(0xE8, 0x007D1786, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x007D17BA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D17F7, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D1840, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D187F, &DowngradeLoadWindowsNone);
	//-- Windows Guild User
	SetCompleteHook(0xE8, 0x007CB6F6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x007CB72A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB767, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB7B0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB7EF, &DowngradeLoadWindowsNone);
	
	//-- Windows Gens-Quest
	SetCompleteHook(0xE8, 0x00843826, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0084385A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00843897, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008438E0, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084391F, &DowngradeLoadWindowsNone);
	//-- Windows Quest (T)
	SetCompleteHook(0xE8, 0x0083EA46, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x0083EA7A, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EAB7, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EB00, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EB3F, &DowngradeLoadWindowsNone);
	//-- Windows Trade
	SetCompleteHook(0xE8, 0x008643B6, &DowngradeLoadWindows);
	SetCompleteHook(0xE8, 0x008643EA, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00864427, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x00864470, &DowngradeLoadWindowsNone);
	SetCompleteHook(0xE8, 0x008644AF, &DowngradeLoadWindowsNone);
	//--
	//SetCompleteHook(0xE9, 0x0080F276, &DrawInterfaceButton);
	SetRange((LPVOID)0x0080F270, 0x4D1, ASM::NOP);//-> Interface -> Draw Button
	//--
	SetCompleteHook(0xE9, 0x00895A48, &RenderSlotDwongradeQ);
	SetCompleteHook(0xE9, 0x00895ABD, &RenderSlotDwongradeW);
	SetCompleteHook(0xE9, 0x00895B32, &RenderSlotDwongradeE);
	MemorySet(0x00895B8D,0x90,0x7E);
	SetCompleteHook(0xE9,0x00895B8D,&DrawInterfaceS2DisableR);
	//--
	SetCompleteHook(0xE8, 0x004F9477, &RenderSkillTooltip);//-- Tooltip Skill Raven
	SetCompleteHook(0xE8, 0x005C6680, &RenderSkillTooltip);//-- Tooltip Skill
	//--
	SetCompleteHook(0xE9, 0x008126C0, &Render_SkillFullMouser);
	SetCompleteHook(0xE9, 0x00813970, &Render_SkillBarSwitch);
	//--
	SetRange((LPVOID)0x008138DF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x008138DF, (LPVOID)DrawUsingSkillPosition, ASM::JMP);
	SetRange((LPVOID)0x00812947, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00812947, (LPVOID)DrawSkillBarDrawPosition, ASM::JMP);
//==================================
	MemorySet(0x0087500F,0x90,0x5);		//Blood Text
	SetByte((PVOID)(0x008743FC+3),7);	//Blood Button Master
	SetByte((PVOID)(0x00874D54+6),7);	//Blood Button Master

	SetByte((PVOID)(0x00877EDC+3),6);	//Remover DevilScare Master
	MemorySet(0x00878B5F,0x90,0x5);		//Remover DevilScare Master

	SetCompleteHook(0xE9,0x007E4CA4,0x007E4D16);	//Remover ChaosCastle Master
	SetByte((PVOID)(0x007E4CB9+1),0);	//Cambia el número del chaos

	SetCompleteHook(0xE9, 0x00425468, &SlideShow);

	SetDword((PVOID)(0x007D0EF6+1),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART1
	SetDword((PVOID)(0x007D0F5D+1),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART1
	SetByte((PVOID)(0x007D0F05+2),43); //POSIÇÃO X GUILD MASTER BUTTONS PART1
	SetByte((PVOID)(0x007D0F6C+2),88); //POSIÇÃO X GUILD MASTER BUTTONS PART1
	SetDword((PVOID)(0x007D11DE+2),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART2
	SetDword((PVOID)(0x007D1249+2),350); //POSIÇÃO Y GUILD MASTER BUTTONS PART2
	SetByte((PVOID)(0x007D11EE+2),43); //POSIÇÃO X GUILD MASTER BUTTONS PART2
	SetByte((PVOID)(0x007D1259+2),88); //POSIÇÃO X GUILD MASTER BUTTONS PART2
	//-- Change SkillBox MUHELPER
	SetDword(0x007F31C1+1, 0x700003);
	SetDword(0x007F3201+1, 0x700003);
	SetDword(0x007F3241+1, 0x700003);
	SetDword(0x007F3280+1, 0x700003);
	SetDword(0x007F32C0+1, 0x700003);
	SetDword(0x007F3300+1, 0x700003);

	//--remove buttom 380
	MemorySet(0x007AA3BA,0x90,0x5);
	MemorySet(0x007AA39C,0x90,0x5);
	MemorySet(0x007AA9B3,0x90,0x5);
	//-- remove buttom menu & credit
	MemorySet(0x0040A7EF,0x90,0x5);
	MemorySet(0x0040A87E,0x90,0x5);
	//-- remove efect clic
	SetRange((LPVOID)0x006E899D, 5, ASM::NOP);
	SetRange((LPVOID)0x007126FA, 5, ASM::NOP);
	SetRange((LPVOID)0x005B768F, 5, ASM::NOP);
	SetRange((LPVOID)0x005B770C, 5, ASM::NOP);
	//-- MENU ESC TRANSPARENTE
	MemorySet(0x007A8330,0x90,0x198);

	//party bar en Y
	SetByte(0x0085AF21, 25);	//<-
	SetCompleteHook(0xE8, 0x007E00B1, &PetHPBarRemake);
	SetCompleteHook(0xE8, 0x007E020C, &PetSpiritHPBarRemake);
	SetCompleteHook(0xE8, 0x007E0298, &PetSpiritHPBarRemake);
	//-
	SetByte((PVOID)(0x008137AF + 3), 0);
	SetByte((PVOID)(0x008119A7), 0xEB);
	SetRange((LPVOID)0x00811AC0, 0xAC, ASM::NOP);
	//-
	SetRange((LPVOID)0x0081028C, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0081028C, (LPVOID)DrawAGPosition, ASM::JMP);
	//-
	if(gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		SetRange((LPVOID)0x0081055C, 0x24, ASM::NOP);
		SetOp((LPVOID)0x0081055C, (LPVOID)DrawSDPosition, ASM::JMP);
	}
	if(gProtect.m_MainInfo.CustomInterfaceType == 1)
	{
		SetRange((LPVOID)0x0081057D, 0x24, ASM::NOP);//-- RemoverSD
	}
	//-
	SetRange((LPVOID)0x0080FFAF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0080FFAF, (LPVOID)DrawMANAPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0080FD5B, 0x24, ASM::NOP);
	SetOp((LPVOID)0x0080FD5B, (LPVOID)DrawHPPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0080FF12, 0x12, ASM::NOP);
	SetOp((LPVOID)0x0080FF12, (LPVOID)DrawHPNumberPosition, ASM::JMP);
	//-
	SetRange((LPVOID)0x0077EC97, 0x88, ASM::NOP);
	SetOp((LPVOID)0x0077EC97, (LPVOID)DrawMasterButton, ASM::JMP);
	//-
	//EXP
	SetRange((LPVOID)0x008113DE, 5, ASM::NOP);
	SetOp((LPVOID)0x008113DE, (LPVOID)DrawEXP1, ASM::JMP);
	SetRange((LPVOID)0x00811528, 5, ASM::NOP);
	SetOp((LPVOID)0x00811528, (LPVOID)DrawEXP2, ASM::JMP);
	SetRange((LPVOID)0x008116EF, 5, ASM::NOP);
	SetOp((LPVOID)0x008116EF, (LPVOID)DrawEXP3, ASM::JMP);
	SetRange((LPVOID)0x008117F8, 5, ASM::NOP);
	SetOp((LPVOID)0x008117F8, (LPVOID)DrawEXP4, ASM::JMP);
	//------------------------------------------------------------------------------
	//EXPMASTER
	SetRange((LPVOID)0x00810B47, 5, ASM::NOP);
	SetOp((LPVOID)0x00810B47, (LPVOID)DrawEXPMASTER1, ASM::JMP);
	SetRange((LPVOID)0x00810C8B, 5, ASM::NOP);
	SetOp((LPVOID)0x00810C8B, (LPVOID)DrawEXPMASTER2, ASM::JMP);
	SetRange((LPVOID)0x00810E52, 5, ASM::NOP);
	SetOp((LPVOID)0x00810E52, (LPVOID)DrawEXPMASTER3, ASM::JMP);
	SetRange((LPVOID)0x00810F4F, 5, ASM::NOP);
	SetOp((LPVOID)0x00810F4F, (LPVOID)DrawEXPMASTER4, ASM::JMP);
	SetRange((LPVOID)0x00810B7F, 5, ASM::NOP);
	//------------------------------------------------------------------------------
	SetDouble(0x00D461C8, 198);				//-> Experience Bar Max Size
	SetDouble(0x00D461C0, 425);				//-> Exp Number Position X
	SetDouble(0x00D461B8, 431.5);			//-> Exp Number Position Y
	
	SetDword(0x004D9746 + 3,480);		//deshabilita el background
	//---------------
	//=====================================================================
	//Stats
	SetCompleteHook(0xE8, 0x0077F7EE, &CClassicUICharacterInfoWindow);
	SetDword((PVOID)(0x0077E935 + 1), 51290);
	SetByte((PVOID)(0x0077E94A + 1), 24);
	SetByte((PVOID)(0x0077E94C + 1), 24);
	SetByte((PVOID)(0x0077E957 + 2), 117);
	SetByte((PVOID)(0x0077E964 + 1), 130);
	SetDword((PVOID)(0x0077E97E + 1), 51290);
	SetByte((PVOID)(0x0077E996 + 1), 24);
	SetByte((PVOID)(0x0077E998 + 1), 24);
	SetByte((PVOID)(0x0077E9A3 + 2), 172);
	SetByte((PVOID)(0x0077E9B3 + 2), 130);
	SetDword((PVOID)(0x0077E9D1 + 1), 51290);
	SetByte((PVOID)(0x0077E9E9 + 1), 24);
	SetByte((PVOID)(0x0077E9EB + 1), 24);
	SetByte((PVOID)(0x0077E9F6 + 1), 237);
	SetByte((PVOID)(0x0077EA05 + 2), 130);
	SetDword((PVOID)(0x0077EA23 + 1), 51290);
	SetByte((PVOID)(0x0077EA3B + 1), 24);
	SetByte((PVOID)(0x0077EA3D + 1), 24);
	SetByte((PVOID)(0x0077EA48 + 2), 292);
	SetByte((PVOID)(0x0077EA58 + 1), 130);
	SetDword((PVOID)(0x0077EA75 + 1), 51290);
	SetByte((PVOID)(0x0077EA8D + 1), 24);
	SetByte((PVOID)(0x0077EA8F + 1), 24);
	SetByte((PVOID)(0x0077EA9A + 2), 347);
	SetByte((PVOID)(0x0077EAAA + 2), 130);
	SetByte((PVOID)(0x007801D9 + 1), 4);
	SetByte((PVOID)(0x007801DD + 1), 42);
	SetByte((PVOID)(0x00780217 + 1), 2);
	SetByte((PVOID)(0x0078023A + 2), 56);
	SetByte((PVOID)(0x0078190D + 1), 4);
	SetByte((PVOID)(0x00781911 + 1), 42);
	SetByte((PVOID)(0x0078194E + 1), 2);
	SetByte((PVOID)(0x00781973 + 2), 56);
	SetByte((PVOID)(0x007830EF + 1), 4);
	SetByte((PVOID)(0x007830F3 + 1), 42);
	SetByte((PVOID)(0x00783130 + 1), 2);
	SetByte((PVOID)(0x00783155 + 2), 56);
	SetByte((PVOID)(0x00782D15 + 1), 4);
	SetByte((PVOID)(0x00782D19 + 1), 42);
	SetByte((PVOID)(0x00782D56 + 1), 2);
	SetByte((PVOID)(0x00782D7C + 2), 56);
	SetByte((PVOID)(0x00782D15 + 1), 4);
	SetByte((PVOID)(0x00782D19 + 1), 42);
	SetByte((PVOID)(0x00782D56 + 1), 2);
	SetByte((PVOID)(0x00782D7C + 2), 56);
	SetByte((PVOID)(0x00784B6D + 1), 4);
	SetByte((PVOID)(0x00784B71 + 1), 42);
	SetByte((PVOID)(0x00784BAE + 1), 2);
	SetByte((PVOID)(0x00784BD4 + 2), 56);
	
}

__declspec(naked) void PositionAncientY() 
{
	static float PositionYAncient = 67.00000000000000;
	static DWORD m_ReturnAncient = 0x0083523A;

	_asm {
		FADD DWORD PTR DS:[PositionYAncient]
		JMP[m_ReturnAncient]
	}

}

void RemoveSocket()
{
	SetRange((LPVOID)0x00D46C8C, 5, ASM::NOP);
	SetCompleteHook(0xE9, 0x00835234, &PositionAncientY);
}
