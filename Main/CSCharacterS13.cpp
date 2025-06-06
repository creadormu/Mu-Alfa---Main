#include "stdafx.h"
#include "CSCharacterS13.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Offset.h"
#include "User.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "MultiSelect.h"
#include "SelectChar.h"

CSCharacterS13 gCSCharacterS13;

void CSCharacterS13::Load()
{
	gInterface.BindObject(CharacterSelect, 51522, 85, 150, 219, 178);

	gInterface.BindObject(CharacterSelect_Button1, 51519, 150, 35, -1, -1);

	gInterface.BindObject(CharacterSelect_Button2, 51519, 150, 35, -1, -1);
	
	gInterface.BindObject(CharacterSelect_Button3, 51519, 150, 35, -1, -1);

	gInterface.BindObject(CharacterSelect_Button4, 51519, 150, 35, -1, -1);

	gInterface.BindObject(CharacterSelect_Button5, 51519, 150, 35, -1, -1);
#if (UPDATE > 16)
	//--
	gInterface.BindObject(CharacterCreate_Button1, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterCreate_Button2, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterCreate_Button3, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterCreate_Button4, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterCreate_Button5, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterCreate_Button6, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterCreate_Button7, 51519, 150, 35, -1, -1);

	gInterface.BindObject(CharacterCreate_SEND, 51522, 80, 23, -1, -1);
	gInterface.BindObject(CharacterCreate_CANCEL, 51522, 80, 23, -1, -1);
#endif
	
	SetDword((PVOID)(0x004D752F+1), 51522);
	SetDword((PVOID)(0x004D7563+1), 51522);

	SetCompleteHook(0xE8, 0x004D6C3E,this->OpenCharacterSceneData);

	SetDouble((PVOID)(0xD25508), 1);
	SetDword((PVOID)(0x004D6C73), 0);
	SetByte((PVOID)(0x00402106), 0);
}


void CSCharacterS13::OpenCharacterSceneData()
{
	LoadBitmapA("Interface\\GFx\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);
	LoadBitmapA("Interface\\GFx\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
//
	((void(__cdecl*)())0x006312E0)();
}

void CharacterSelect360()
{
	for (int i = 0; i < 5; i++)
	{	
		int v5 = pGetPreviewStruct(pPreviewThis(), i);
		
		int v8 = v5 + 776;

		if (gInterface.IsWorkZone(CharacterSelect))
		{	
			*(float *)(v8 + 272) = *(float *)(v8 + 272) + 5.0;
		}
		else
		{
			*(float *)(v8 + 272) = 90;
		}
	}
}

void CharacterCharacteristics(int a1, float a2)
{
	char* Name;
	char* Status;
	int Class;
	char Level[256];
	float X = 471;
	float Y = 51;
	int This = (int)sub_482B70() + 36744;
	int Hero00 = This;
	Hero00 = *(DWORD *)(This + 4) + 368 * a1;
//
	Name = strcpy((char *)Hero00 + 176, (const char *)(*((DWORD *)Hero00 + 42) + 56));
	Status = (char *)Hero00 + 240;
	Class = sub_587620(*(BYTE *)(*(DWORD *)(Hero00 + 168) + 19));
	gInterface.DrawFormat(eGold, X + 35, Y + 20 + a2, 190, 2, (const char *)Name);
	gInterface.DrawFormat(eWhite180, X + 11, Y + 7 + a2, 190, 0, (const char *)Class);
	gInterface.DrawFormat(eWhite180, X - 50, Y + 7 + a2, 190, 4, (const char *)Status);
	wsprintf(Level, "Level: %d", *(WORD *)(*(DWORD *)(Hero00 + 168) + 130));
	pSetTextColor(pTextThis(), 255, 189, 25, 0xFF);
	pDrawText(pTextThis(), X - 50, Y + 20 + a2, Level, 190, 0, (LPINT)4, 0);
}

void CharacterTeleport(int a1,float a2,float a3,float a4)
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{	
		int v5 = pGetPreviewStruct(pPreviewThis(),a1);
		int v8 = v5 + 776;
		if ( v5 )
		{
			*(float *)(v8 + 156) = 0.30000001;	
			*(float *)(v8 + 160) = 0.30000001;
			*(float *)(v8 + 164) = 0.30000001;
			*(float *)(v8 + 252) = a2;
			*(float *)(v8 + 256) = a3;
			*(float *)(v8 + 272) = a4;
		}
	}
}
#if (UPDATE > 16)	
int escenaCharacter;

void InfoClass(int Class)
{
	//--
	int TextoY;
	int Stadisticas0 = 210;
	int Stadisticas1 = 210;
	int Stadisticas2 = 210;
	int Stadisticas3 = 210;
	EnableAlphaTest(1);
	glColor4f(0.0, 0.0, 0.0, 0.75555);
	pDrawBarForm(10, 40, 180, 250, 0.0, 0);
	pGLSupremo();

	//--
	Stadisticas2 = gInterface.DrawFormat(eExcellentS15, 20, Stadisticas2, 170, 3, "Información Atributos") + 10;
	//--
	Stadisticas0 = Stadisticas2;
	Stadisticas1 = Stadisticas2;
	Stadisticas3 = Stadisticas2;
	//-- Informacion 1
	Stadisticas2 = gInterface.DrawFormat(eGold, 20, Stadisticas2, 50, 1, "Fuerza:");
	Stadisticas2 = gInterface.DrawFormat(eGold, 20, Stadisticas2, 50, 1, "Agilidad:");
	Stadisticas2 = gInterface.DrawFormat(eGold, 20, Stadisticas2, 50, 1, "Vitalidad:");
	Stadisticas2 = gInterface.DrawFormat(eGold, 20, Stadisticas2, 50, 1, "Energia:");
	//-- Informacion 2
	Stadisticas0 = gInterface.DrawFormat(eGold, 110, Stadisticas0, 60, 1, "Básico:");
	Stadisticas0 = gInterface.DrawFormat(eGold, 110, Stadisticas0, 60, 1, "Vida:");
	Stadisticas0 = gInterface.DrawFormat(eGold, 110, Stadisticas0, 60, 1, "Mana:");
	Stadisticas0 = gInterface.DrawFormat(eGold, 110, Stadisticas0, 60, 1, "Vida x level:");
	Stadisticas0 = gInterface.DrawFormat(eGold, 110, Stadisticas0, 60, 1, "Mana x leve:");

	if(Class == CLASS_WIZARD)
	{
		TextoY = gInterface.DrawFormat(eGold, 10, 40 + 10, 180, 3, "Dark Wizard") + 10;
		//--
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "18");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "18");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "15");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "30");
		//--
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "81");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "60");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "60");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "2");
	}
	if(Class == CLASS_KNIGHT)
	{
		TextoY = gInterface.DrawFormat(eGold, 10, 40 + 10, 180, 3, "Dark Knight") + 10;

		//--
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "28");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "20");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "25");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "10");
		//--
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "83");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "110");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "20");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "2");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "0.5");
	}
	if(Class == CLASS_ELF)
	{
		TextoY = gInterface.DrawFormat(eGold, 10, 40 + 10, 180, 3, "Fairy Elf") + 10;
		//--
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "22");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "25");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "20");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "15");
		//--
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "82");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "80");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "30");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1.5");
	}
	if(Class == CLASS_MAGUMSA)
	{
		TextoY = gInterface.DrawFormat(eGold, 10, 40 + 10, 180, 3, "Magic Gladiator") + 10;
		//--
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "26");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "26");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "26");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "26");
		//--
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "114");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "110");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "60");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1");
	}
	if(Class == CLASS_DARKLORD)
	{
		TextoY = gInterface.DrawFormat(eGold, 10, 40 + 10, 180, 3, "Dark Lord") + 10;
		//--
		Stadisticas2 = gInterface.DrawFormat(eGold, 20, Stadisticas2, 50, 1, "Comando:");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "26");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "20");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "20");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "15");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "25");
		//--
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "25");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "90");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "40");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1.5");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1");
	}
	if(Class == CLASS_SUMMONER)
	{
		TextoY = gInterface.DrawFormat(eGold, 10, 40 + 10, 180, 3, "Summoner") + 10;
		//--
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "21");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "21");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "18");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "23");
		//--
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "83");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "70");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "20");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1.5");
	}
	if(Class == CLASS_MONK)
	{
		TextoY = gInterface.DrawFormat(eGold, 10, 40 + 10, 180, 3, "Rage Fighter") + 10;
		//--
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "32");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "27");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "25");
		Stadisticas3 = gInterface.DrawFormat(eSocket, 20, Stadisticas3, 60, 4, "20");
		//--
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "104");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "100");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "40");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1.3");
		Stadisticas1 = gInterface.DrawFormat(eShinyGreen, 140, Stadisticas1, 40, 4, "1");
	}

	TextoY = gInterface.DrawFormat(eWhite, 20, TextoY, 170, 1, "Dark Knight es un personaje para pelea a\ncorta distancia.");
	TextoY = gInterface.DrawFormat(eWhite, 20, TextoY, 170, 1, "Tienen gran poder de pelea física y usan\npoderosas armas.");
	TextoY = gInterface.DrawFormat(eWhite, 20, TextoY, 170, 1, "Empezaron su aventura en este continente\npara salvarlo de la oscuridad del Kundun.");
	TextoY = gInterface.DrawFormat(eWhite, 20, TextoY, 170, 1, "Dark Knight es la mejor alternativa si te\ngusta la acción cuerpo a cuerpo para");
	TextoY = gInterface.DrawFormat(eWhite, 20, TextoY, 170, 1, "derrotar monstruos y cortar en dos a nuestros\nenemigos.");
	
}

int SelectClass = CLASS_WIZARD;

void CreateChar()
{
	EnableAlphaTest(1);
	glColor4f(0.0, 0.0, 0.0, 0.75555);
	pDrawBarForm(230, 380, 180, 20, 0.0, 0);
	pGLSupremo();
	gInterface.DrawFormat(eWhite, 240, 385, 60, 1, "Nombre:");
	gInterface.DrawFormat(eGray100, 280, 385, 80, 1, "Ingrese Nombre!!");

	float X = 471;
	float Y = 51;
	if (gInterface.IsWorkZone(CharacterCreate_Button1))
	{
		if (gInterface.Data[CharacterCreate_Button1].OnClick)
		{
			gInterface.DrawButton(CharacterCreate_Button1, 471, 51, 0, 70);
			SelectClass = CLASS_WIZARD;
			PlayBuffer(25, 0, 0);
		}
		if(SelectClass == CLASS_WIZARD)
		{
			gInterface.DrawButton(CharacterCreate_Button1, 471, 51, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button1, 471, 51, 0, 35);
		}
	}
	else
	{
		if(SelectClass == CLASS_WIZARD)
		{
			gInterface.DrawButton(CharacterCreate_Button1, 471, 51, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button1, 471, 51, 0, 0);
		}
	}

	gInterface.DrawFormat(eWhite180, X-29, Y + 13, 210, 3, "Dark Wizard");

//-- Dark Knight

	if (gInterface.IsWorkZone(CharacterCreate_Button2))
	{
		if (gInterface.Data[CharacterCreate_Button2].OnClick)
		{
			gInterface.DrawButton(CharacterCreate_Button2, 471, 88, 0, 70);
			SelectClass = CLASS_KNIGHT;
			PlayBuffer(25, 0, 0);
		}
		if(SelectClass == CLASS_KNIGHT)
		{
			gInterface.DrawButton(CharacterCreate_Button2, 471, 88, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button2, 471, 88, 0, 35);
		}
	}
	else
	{
		if(SelectClass == CLASS_KNIGHT)
		{
			gInterface.DrawButton(CharacterCreate_Button2, 471, 88, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button2, 471, 88, 0, 0);
		}
	}

	gInterface.DrawFormat(eWhite180, X-29, 88 + 13, 210, 3, "Dark Knight");

//-- Fairy Elf
	if (gInterface.IsWorkZone(CharacterCreate_Button3))
	{
		if (gInterface.Data[CharacterCreate_Button3].OnClick)
		{
			gInterface.DrawButton(CharacterCreate_Button3, 471, 125, 0, 70);
			SelectClass = CLASS_ELF;
			PlayBuffer(25, 0, 0);
		}
		if(SelectClass == CLASS_ELF)
		{
			gInterface.DrawButton(CharacterCreate_Button3, 471, 125, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button3, 471, 125, 0, 35);
		}
	}
	else
	{
		if(SelectClass == CLASS_ELF)
		{
			gInterface.DrawButton(CharacterCreate_Button3, 471, 125, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button3, 471, 125, 0, 0);
		}
	}

	gInterface.DrawFormat(eWhite180, X-29, 125 + 13, 210, 3, "Fairy Elf");

//-- Magic Gladiator
	if (gInterface.IsWorkZone(CharacterCreate_Button4))
	{
		if (gInterface.Data[CharacterCreate_Button4].OnClick)
		{
			gInterface.DrawButton(CharacterCreate_Button4, 471, 162, 0, 70);
			SelectClass = CLASS_MAGUMSA;
			PlayBuffer(25, 0, 0);
		}
		if(SelectClass == CLASS_MAGUMSA)
		{
			gInterface.DrawButton(CharacterCreate_Button4, 471, 162, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button4, 471, 162, 0, 35);
		}
	}
	else
	{
		if(SelectClass == CLASS_MAGUMSA)
		{
			gInterface.DrawButton(CharacterCreate_Button4, 471, 162, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button4, 471, 162, 0, 0);
		}
		
	}

	gInterface.DrawFormat(eWhite180, X-29, 162 +13, 210, 3, "Magic Gladiator");

//-- Dark Lord
	if (gInterface.IsWorkZone(CharacterCreate_Button5))
	{
		if (gInterface.Data[CharacterCreate_Button5].OnClick)
		{
			gInterface.DrawButton(CharacterCreate_Button5, 471, 199, 0, 70);
			SelectClass = CLASS_DARKLORD;
			PlayBuffer(25, 0, 0);
		}
		if(SelectClass == CLASS_DARKLORD)
		{
			gInterface.DrawButton(CharacterCreate_Button5, 471, 199, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button5, 471, 199, 0, 35);
		}
	}
	else
	{
		if(SelectClass == CLASS_DARKLORD)
		{
			gInterface.DrawButton(CharacterCreate_Button5, 471, 199, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button5, 471, 199, 0, 0);
		}
	}

	gInterface.DrawFormat(eWhite180, X-29, 199 + 13, 210, 3, "Dark Lord");

//-- Summoner
	if (gInterface.IsWorkZone(CharacterCreate_Button6))
	{
		if (gInterface.Data[CharacterCreate_Button6].OnClick)
		{
			gInterface.DrawButton(CharacterCreate_Button6, 471, 236, 0, 70);

			SelectClass = CLASS_SUMMONER;
			PlayBuffer(25, 0, 0);
		}
		if(SelectClass == CLASS_SUMMONER)
		{
			gInterface.DrawButton(CharacterCreate_Button6, 471, 236, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button6, 471, 236, 0, 35);
		}
	}
	else
	{
		if(SelectClass == CLASS_SUMMONER)
		{
			gInterface.DrawButton(CharacterCreate_Button6, 471, 236, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button6, 471, 236, 0, 0);
		}
	}

	gInterface.DrawFormat(eWhite180, X-29, 236 + 13, 210, 3, "Summoner");

//-- Rage Fighter
	if (gInterface.IsWorkZone(CharacterCreate_Button7))
	{
		if (gInterface.Data[CharacterCreate_Button7].OnClick)
		{
			gInterface.DrawButton(CharacterCreate_Button7, 471, 273, 0, 70);
			SelectClass = CLASS_MONK;
			PlayBuffer(25, 0, 0);
		}
		if(SelectClass == CLASS_MONK)
		{
			gInterface.DrawButton(CharacterCreate_Button7, 471, 273, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button7, 471, 273, 0, 35);
		}
	}
	else
	{
		if(SelectClass == CLASS_MONK)
		{
			gInterface.DrawButton(CharacterCreate_Button7, 471, 273, 0, 70);
		}
		else
		{
			gInterface.DrawButton(CharacterCreate_Button7, 471, 273, 0, 0);
		}
	}

	gInterface.DrawFormat(eWhite180, X-29, 273 + 13, 210, 3, "Rage Fighter");

//-- boton crear
	gInterface.DrawButton(CharacterCreate_SEND, 240, 410, 0, 0);

	if (gInterface.IsWorkZone(CharacterCreate_SEND))
	{
		if (gInterface.Data[CharacterCreate_SEND].OnClick)
		{
			RenderBitmap(51519, 240, 410, 80, 23, 0.0, 0.5410000086, 0.5899999738, 0.2830000222, 1, 1, 0);
			
			PlayBuffer(25, 0, 0);

			PMSG_CHARACTER_CREATE_RECV pMsg;

			pMsg.header.set(0xF3, 0x01, sizeof(pMsg));
			
			pMsg.Class = SelectClass;

			sprintf(pMsg.name, "takum");

			DataSend((BYTE*)&pMsg,pMsg.header.size);

			escenaCharacter = 0;

			((int(__cdecl*)(int Num)) 0x0057D620)(-1);
			*(BYTE*)0xE8CB4E = 0;
			*(DWORD*)(MAIN_SCREEN_STATE) = SwitchCharacter;
			*(DWORD*)0x87935A4 = 51;

			gInterface.Data[CharacterCreate_SEND].OnClick = false;

			return;
		}
		else
		{
			RenderBitmap(51519, 240, 410, 80, 23, 0.0, 0.5410000086, 0.5899999738, 0.2830000222, 1, 1, 0);
		}
	}
	else
	{
		RenderBitmap(51519, 240, 410, 80, 23, 0.0, 0.5410000086, 0.5899999738, 0.2830000222, 1, 1, 0);
	}

//-- boton CANCELAR
	gInterface.DrawButton(CharacterCreate_CANCEL, 325, 410, 0, 0);

	if (gInterface.IsWorkZone(CharacterCreate_CANCEL))
	{
		if (gInterface.Data[CharacterCreate_CANCEL].OnClick)
		{
			RenderBitmap(51519, 325, 410, 80, 23, 0.0, 0.5410000086, 0.5899999738, 0.2830000222, 1, 1, 0);
			escenaCharacter = 0;
			PlayBuffer(25, 0, 0);
			gInterface.Data[CharacterCreate_CANCEL].OnClick = false;
			return;
		}
		else
		{
			RenderBitmap(51519, 325, 410, 80, 23, 0.0, 0.2700000107, 0.5899999738, 0.2830000222, 1, 1, 0);
		}
	}
	else
	{
		RenderBitmap(51519, 325, 410, 80, 23, 0.0, 0.0, 0.5899999738, 0.2830000222, 1, 1, 0);
	}

	gInterface.DrawFormat(eWhite180, 325, 410 + 5, 80, 3, "CANCEL");

	gInterface.DrawFormat(eWhite180, 240, 410 + 5, 80, 3, "CREAR");

	CharacterSelect360();

	if(SelectClass != -1)
	{
		*(DWORD*)0xE61E18 = 74;
		//(unsigned __int8)byte_7BD0483, byte_7BD0484
		sub_586DA0(*(BYTE *)0x18DF0D, SelectClass, *(BYTE*)0x7BD0484,
			gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX,
			gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY,
			gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
		*(DWORD*)0x87935A4 = 53;
		InfoClass(SelectClass);
	}
}

void CSCharacterS13::SelectChar()
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::SwitchCharacter)
	{
		escenaCharacter = 0;
	}

	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{
		if(escenaCharacter == 1)
		{
			CreateChar();
			((void(__cdecl*)())0x005BB0B0)();
			return;
		}
		//--
		float X = 471;
		float Y = 51;
//
		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
		{
//Create Select
//-- 0
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button1))
				{
					if (gInterface.Data[CharacterSelect_Button1].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 70);
						escenaCharacter = 1;
						PlayBuffer(25, 0, 0);
						gInterface.Data[CharacterSelect_Button1].OnClick = false;
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						
						//sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, Y + 13, 210, 3, "Empty Character Slot");
			}
//-- 1
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button2))
				{
					if (gInterface.Data[CharacterSelect_Button2].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 70);
						escenaCharacter = 1;
						PlayBuffer(25, 0, 0);
						gInterface.Data[CharacterSelect_Button2].OnClick = false;
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						
						
						//sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 88 + 13, 210, 3, "Empty Character Slot");
			}
//-- 2
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button3))
				{
					if (gInterface.Data[CharacterSelect_Button3].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 70);
						escenaCharacter = 1;
						PlayBuffer(25, 0, 0);
						gInterface.Data[CharacterSelect_Button3].OnClick = false;
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						
						
						//sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 125 + 13, 210, 3, "Empty Character Slot");
			}
//-- 3
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button4))
				{
					if (gInterface.Data[CharacterSelect_Button4].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 70);
						escenaCharacter = 1;
						PlayBuffer(25, 0, 0);
						gInterface.Data[CharacterSelect_Button4].OnClick = false;
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						
						
						//sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 162 +13, 210, 3, "Empty Character Slot");
			}
//-- 4
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 70);
						escenaCharacter = 1;
						PlayBuffer(25, 0, 0);
						gInterface.Data[CharacterSelect_Button5].OnClick = false;
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						//sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 199 + 13, 210, 3, "Empty Character Slot");
			}

//Character Select
			CharacterSelect360();
//-- 0
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button1))
				{
					
					if (gInterface.Data[CharacterSelect_Button1].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 0;
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
					}
					else
					{
						if(SelectedHero == 0)
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 35);
						}
					}

						SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 0)
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 0);
					}
				}
				CharacterCharacteristics(0,0);
			}
//-- 1
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button2))
				{
					
					if (gInterface.Data[CharacterSelect_Button2].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 1;
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						gInterface.DrawButton(CharacterSelect_Button2, 471,  Y+37, 0, 70);
					}
					else
					{
						if(SelectedHero == 1)
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 35);
						}
					}
					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 1)
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 0);
					}
				}
				CharacterCharacteristics(1,37);
			}
//-- 2
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button3))
				{
					
					if (gInterface.Data[CharacterSelect_Button3].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 2;
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
					}
					else
					{
						if(SelectedHero == 2)
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 2)
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 0);
					}
				}
				CharacterCharacteristics(2,74);
			}
//-- 3
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button4))
				{
					
					if (gInterface.Data[CharacterSelect_Button4].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 3;
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
					}
					else
					{
						if(SelectedHero == 3)
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 35);
						}
					}
					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 3)
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 0);
					}
				}

				CharacterCharacteristics(3,111);
			}
//-- 4
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 4;
						CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
						CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
						CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate);
						CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate);
						CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate);
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
					}
					else
					{
						if(SelectedHero == 4)
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 4)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 0);
					}
				}

				CharacterCharacteristics(4,148);
			}
		}
	}
	((void(__cdecl*)())0x005BB0B0)();
}
#else
void CSCharacterS13::SelectChar()
{

		float X = 471;
		float Y = 51;
//
		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
		{
//Create Select
//-- 0
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button1))
				{
					if (gInterface.Data[CharacterSelect_Button1].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, Y + 13, 210, 3, "Empty Character Slot");
			}
//-- 1
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button2))
				{
					if (gInterface.Data[CharacterSelect_Button2].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 88 + 13, 210, 3, "Empty Character Slot");
			}
//-- 2
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button3))
				{
					if (gInterface.Data[CharacterSelect_Button3].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 125 + 13, 210, 3, "Empty Character Slot");
			}
//-- 3
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button4))
				{
					if (gInterface.Data[CharacterSelect_Button4].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 162 +13, 210, 3, "Empty Character Slot");
			}
//-- 4
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 199 + 13, 210, 3, "Empty Character Slot");
			}

//Character Select
			CharacterSelect360();
//-- 0
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button1))
				{
					
					if (gInterface.Data[CharacterSelect_Button1].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 0;
						for(int m = 0; m < 5; m++)
						{
							if(m == SelectedHero)
							{
						CharacterTeleport(SelectedHero, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							}
							else
							{
						CharacterTeleport(m, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
							}
						}
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
					}
					else
					{
						if(SelectedHero == 0)
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 35);
						}
					}

						SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 0)
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 0);
					}
				}
				CharacterCharacteristics(0,0);
			}
//-- 1
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button2))
				{
					
					if (gInterface.Data[CharacterSelect_Button2].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 1;
						for(int m = 0; m < 5; m++)
						{
							if(m == SelectedHero)
							{
						CharacterTeleport(SelectedHero, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							}
							else
							{
						CharacterTeleport(m, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
							}
						}
						gInterface.DrawButton(CharacterSelect_Button2, 471,  Y+37, 0, 70);
					}
					else
					{
						if(SelectedHero == 1)
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 35);
						}
					}
					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 1)
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 0);
					}
				}
				CharacterCharacteristics(1,37);				
			}
//-- 2
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button3))
				{
					
					if (gInterface.Data[CharacterSelect_Button3].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 2;
						for(int m = 0; m < 5; m++)
						{
							if(m == SelectedHero)
							{
						CharacterTeleport(SelectedHero, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							}
							else
							{
						CharacterTeleport(m, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
							}
						}
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
					}
					else
					{
						if(SelectedHero == 2)
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 2)
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 0);
					}
				}
				CharacterCharacteristics(2,74);
			}
//-- 3
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button4))
				{
					
					if (gInterface.Data[CharacterSelect_Button4].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 3;
						for(int m = 0; m < 5; m++)
						{
							if(m == SelectedHero)
							{
						CharacterTeleport(SelectedHero, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							}
							else
							{
						CharacterTeleport(m, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
							}
						}
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
					}
					else
					{
						if(SelectedHero == 3)
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 35);
						}
					}
					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 3)
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 0);
					}
				}

				CharacterCharacteristics(3,111);
			}
//-- 4
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 4;
						for(int m = 0; m < 5; m++)
						{
							if(m == SelectedHero)
							{
						CharacterTeleport(SelectedHero, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							}
							else
							{
						CharacterTeleport(m, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate);
							}
						}
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
					}
					else
					{
						if(SelectedHero == 4)
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 4)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 0);
					}
				}

				CharacterCharacteristics(4,148);
			}
		}
}
#endif
void CSCharacterS13::SelectCharButton(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	// ----
	if(*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::SwitchCharacter)
	{
		#if (UPDATE > 16)	
		escenaCharacter = 0;
		#endif
		return;
	}
	#if (UPDATE > 16)	
	if(escenaCharacter != 1)
	{
	#endif	// ----
		if( gInterface.IsWorkZone(CharacterSelect_Button1) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button1].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterSelect_Button1].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button1].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button1].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterSelect_Button2) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button2].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterSelect_Button2].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button2].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button2].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterSelect_Button3) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button3].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterSelect_Button3].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button3].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button3].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterSelect_Button4) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button4].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterSelect_Button4].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button4].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button4].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterSelect_Button5) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button5].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterSelect_Button5].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button5].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterSelect_Button5].EventTick = GetTickCount();
			// ----
		}
		#if (UPDATE > 16)	
	}
	else
	{
	//--------------
		// ----
		if( gInterface.IsWorkZone(CharacterCreate_Button1) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_Button1].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_Button1].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button1].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button1].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterCreate_Button2) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_Button2].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_Button2].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button2].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button2].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterCreate_Button3) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_Button3].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_Button3].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button3].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button3].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterCreate_Button4) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_Button4].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_Button4].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button4].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button4].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterCreate_Button5) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_Button5].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_Button5].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button5].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button5].EventTick = GetTickCount();
			// ----
		}
		else if( gInterface.IsWorkZone(CharacterCreate_Button6) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_Button6].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_Button6].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button6].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button6].EventTick = GetTickCount();
			// ----
			}
		else if( gInterface.IsWorkZone(CharacterCreate_Button7) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_Button7].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_Button7].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button7].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_Button7].EventTick = GetTickCount();
			// ----
		}
		else if( gInterface.IsWorkZone(CharacterCreate_SEND) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_SEND].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_SEND].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_SEND].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_SEND].EventTick = GetTickCount();
			// ----
		}
		else if( gInterface.IsWorkZone(CharacterCreate_CANCEL) )
		{
			DWORD Delay	= (CurrentTick - gInterface.Data[CharacterCreate_CANCEL].EventTick);
			// ----
			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[CharacterCreate_CANCEL].OnClick = true;
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_CANCEL].OnClick = false;
			// ----
			if( Delay < 1000 )
			{
				return;
			}
			// ----
			gInterface.Data[CharacterCreate_CANCEL].EventTick = GetTickCount();
			// ----
		}
	}
#endif
}