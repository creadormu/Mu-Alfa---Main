#include "stdafx.h"
#include "CustomGloves.h"
#include "Defines.h"
#include "Util.h"

cCustomGloves gCustomBattleGloves;

cCustomGloves::cCustomGloves() // OK
{
	this->m_CustomGlovesInfo.clear();
}

cCustomGloves::~cCustomGloves() // OK
{

}

//----- (0050DA90) --------------------------------------------------------
void GlovesAssoc(char *This)
{
	sub_50D810((int)(This + 92), 1203, 610, 611);
	void* v2 = sub_512D50(This + 92);
	char* v3 = sub_513C60(This, v2, (int)(This + 92));
	sub_5135F0((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60();
	// ----
	sub_50D810((int)(This + 92), 1204, 612, 613);
	v2 = sub_512D50(This + 92);
	v3 = sub_513C60(This, v2, (int)(This + 92));
	sub_5135F0((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60();
	// ----
	sub_50D810((int)(This + 92), 1205, 614, 615);
	v2 = sub_512D50(This + 92);
	v3 = sub_513C60(This, v2, (int)(This + 92));
	sub_5135F0((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60();
	// ----
	sub_50D810((int)(This + 92), 1206, 616, 617);
	v2 = sub_512D50(This + 92);
	v3 = sub_513C60(This, v2, (int)(This + 92));
	sub_5135F0((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60();
	// ----
	sub_50D810((int)(This + 92), 1211, 610, 611);
	v2 = sub_512D50(This + 92);
	v3 = sub_513C60(This, v2, (int)(This + 92));
	sub_5135F0((DWORD *)This + 15, (int)This, (int)v3);
	sub_512D60();
	// ----
	for(std::map<int, CUSTOM_RF_GLOVES>::iterator it = gCustomBattleGloves.m_CustomGlovesInfo.begin(); it != gCustomBattleGloves.m_CustomGlovesInfo.end(); it++)
	{
		sub_50D810((int)(This + 92), it->second.ItemIndex + 1171, it->second.TextureLeftIndex + 1171, it->second.TextureRightIndex + 1171);
		void* v2 = sub_512D50(This + 92);
		char* v3 = sub_513C60(This, v2, (int)(This + 92));
		sub_5135F0((DWORD *)This + 15, (int)This, (int)v3);
		sub_512D60();
	}
}

static BOOL bBattleGlovesGlow_Switcher;

#pragma optimize("t",on)
void __declspec(naked) BattleGloveGlow()
{
	static DWORD dwBattleGlovesGlow_Pointer;
	static DWORD dwBattleGlovesGlow_Buffer;
	static DWORD dwBattleGlovesNewGlow_Buffer;
	static DWORD dwBattleGlovesGlow_Jump = 0x005F94E8;
	static bool item = false;
	// ----
	bBattleGlovesGlow_Switcher = FALSE;
	// ----
	_asm {
		MOV dwBattleGlovesGlow_Pointer, EAX
	}
	// ----
	item = gCustomBattleGloves.CheckGloves(dwBattleGlovesGlow_Pointer - 1171);

	if (dwBattleGlovesGlow_Pointer == ITEM2(0,35))
	{
		bBattleGlovesGlow_Switcher = TRUE;
	}
	//--
	else if (item == true)
	{
		bBattleGlovesGlow_Switcher = FALSE;
		// ----
		_asm {
			MOV DWORD PTR SS:[EBP-0x4], 0x2C
			JMP dwBattleGlovesGlow_Jump
		}
	}
	// ----
	if ( bBattleGlovesGlow_Switcher == TRUE ) {
		_asm {
			MOV dwBattleGlovesGlow_Buffer, 0x005F91C9
			JMP dwBattleGlovesGlow_Buffer
		}
	}
	else {
		_asm {
			MOV dwBattleGlovesGlow_Buffer, 0x005F91D5
			JMP dwBattleGlovesGlow_Buffer
		}
	}
}
#pragma optimize("t",off)

bool validacionGeneral(DWORD dwBattleGlovesGlow_Pointer)
{
	if(gCustomBattleGloves.CheckGloves(dwBattleGlovesGlow_Pointer) || (dwBattleGlovesGlow_Pointer >= 32 && dwBattleGlovesGlow_Pointer <= 35) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

#pragma optimize("t",on)
void __declspec(naked) RenderBattleGlove()
{
	static DWORD buffer_posicion = 0x005D01DA;
	static DWORD buffer_Next_posicion = 0x005D01FA;
	static DWORD RenderClaws = 0;
	static DWORD t;
	
	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP + 0x18]
		MOV RenderClaws, ECX
	}

	if(validacionGeneral(RenderClaws) == true)
	{
		_asm
		{
			JMP [buffer_posicion]
		}
	}
	else
	{
		_asm
		{
			JMP [buffer_Next_posicion]
		}
	}
}
#pragma optimize("t",off)


bool validacionPosicion(DWORD dwBattleGlovesGlow_Pointer)
{
	if( gCustomBattleGloves.CheckGloves(dwBattleGlovesGlow_Pointer) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

#pragma optimize("t",on)
void __declspec(naked) BattleGloveRotate()
{
	static DWORD Addr1 = 0x005CD452;
	static DWORD GlovesRF = 0;
	static float Rotation = 90.0;
	static float X = 0.004999999888241291f;
	static float Y = 0.01499999966472387f;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP + 0x8]
		MOV GlovesRF, ECX
	}

	if(GlovesRF == 0x4B6)
	{
		_asm
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[0xD27CA8]	//-- DS:[00D27CA8]= 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[0xD254B8]	//-- DS:[00D254B8]= 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			FLDZ
			FSTP DWORD PTR DS:[0x82C6320]
			FLDZ
			FSTP DWORD PTR DS:[0x82C6324]
			FLDZ
			FSTP DWORD PTR DS:[0x82C6328]
			JMP [Addr1]
		}
	}
	else if(validacionPosicion(GlovesRF -1171) == true)
	{
		_asm
		{
			FLD DWORD PTR SS:[EBP-0x4C]
			FSUB QWORD PTR DS:[X]                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4C]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[Y]                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			FLD DWORD PTR DS:[0xD2AF58]                      //FLOAT 270.0000
			FSTP DWORD PTR DS:[0x82C6320]
			FLDZ
			FSTP DWORD PTR DS:[0x82C6324]                    //FLOAT 0.0000
			FLDZ
			FSTP DWORD PTR DS:[0x82C6328]                    //FLOAT 0.0000
			JMP [Addr1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr1]
		}
	}
}

void __declspec(naked) BattleGloveScale()
{
	static DWORD Addr1 = 0x005CEFF0;
	static DWORD Addr2 = 0x005CEFF9;
	static DWORD GlovesRF = 0;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP + 0x8]
		MOV GlovesRF, ECX
	}

	if( GlovesRF == 0x4B6 )
	{
		_asm
		{
			FLD DWORD PTR DS : [ 0xD2C618 ]	//0.003f;
			FSTP DWORD PTR SS : [ EBP - 0x2C ]
			JMP [Addr2]
		}
	}
	else if( validacionPosicion(GlovesRF -1171) == true )
	{
		_asm
		{
			FLD DWORD PTR DS : [ 0xD2C624 ]	//0.0035000001f;
			FSTP DWORD PTR SS  :[ EBP - 0x2C ]
			JMP [Addr2]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2]
		}
	}
}

#pragma optimize("t",off)
void cCustomGloves::Load(CUSTOM_RF_GLOVES* info) // OK
{
	for (int n = 0; n < MAX_CUSTOM_GLOVES; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= MAX_CUSTOM_GLOVES)
		{
			return;
		}

		this->m_CustomGlovesInfo.insert(std::pair<int, CUSTOM_RF_GLOVES>(info[n].ItemIndex,info[n]));
	}
}

int cCustomGloves::GetItemIndex(int ItemIndex)
{
	std::map<int, CUSTOM_RF_GLOVES>::iterator it = this->m_CustomGlovesInfo.find(ItemIndex);

	if(it != this->m_CustomGlovesInfo.end())
	{
		return it->second.ItemIndex;
	}
	return -1;
}

bool cCustomGloves::CheckGloves(int ItemIndex)
{
	std::map<int, CUSTOM_RF_GLOVES>::iterator it = this->m_CustomGlovesInfo.find(ItemIndex);

	if(it != this->m_CustomGlovesInfo.end())
	{
		return true;
	}
	return false;
}

void cCustomGloves::Init() // OK
{
	//--posicion en el inventario
	//SetCompleteHook(0xE9,0x005CD419,&BattleGloveRotate);
	//-- Tamaño en el inventario
	//SetCompleteHook(0xE9,0x005CEFE7,&BattleGloveScale);
	//-- Posicion Original
	SetCompleteHook(0xE9,0x005D01D0, &RenderBattleGlove);
	//-- asociacion de glove
	SetCompleteHook(0xE8,0x0050D905,&GlovesAssoc);
	//-- Encender Glow
	SetCompleteHook(0xE9,0x005F91C2,&BattleGloveGlow);
}