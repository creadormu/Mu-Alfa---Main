#pragma once

#define MAX_WORLD_SETTINGS 1
#define MAX_WORLD_SELECT_CHAR 5

#define World				*(int*)0x0E61E18
//#define sub_9CF1C0			((DWORD(__cdecl*)(DWORD, DWORD, DWORD)) 0x009CF1C0)
#define sub_586DA0			((int(__cdecl*)(int a4, int a5, char a6, float a7, float a8, float a9)) 0x00586DA0)
#define sub_587380			((DWORD(__cdecl*)(char)) 0x587380)
#define ClearCharacters			((int(__cdecl*)(int a1)) 0x0057D620)
//----- (0057FD90) --------------------------------------------------------
#define sub_57FD90					((void(__cdecl*)(signed int a4, int a5, int a6, int a7)) 0x0057FD90)

//SelectPJCord01
#define sub_63CB40			((int(*)(void)) 0x0063CB40)
#define sub_4D5130			((DWORD(__cdecl*)(char a1)) 0x004D5130)
#define sub_9CF1C0			((char *(__cdecl*)(char *a1, const void *a2, unsigned int a3)) 0x009CF1C0)
#define dword_87935A4		*(int*)0x87935A4
#define sub_861110			((int(__cdecl*)()) 0x00861110)
#define sub_861A80			((int(__thiscall*)(DWORD)) 0x00861A80)
#define sub_856BD0			((DWORD(__thiscall*)(char a1)) 0x00856BD0)
#define dword_E8CB30		*(int*)0xE8CB30
#define sub_57D760			((void(__cdecl*)(int a4)) 0x0057D760)
#define sub_668520			((int(__thiscall*)(char *a1)) 0x00668520)
#define sub_4057B0			((int(__thiscall*)(char *a1)) 0x004057B0)
#define sub_402AD0			((int(__thiscall*)(char *a1)) 0x00402AD0)
#define sub_484A10			((int(__thiscall*)(int This, int a2, char *a3)) 0x00484A10)
//SelectPJCord02
#define sub_586DA0			((int(__cdecl*)(int a1, int a2, char a3, float x, float y, float z)) 0x586DA0)
#define sub_63D130			((DWORD(__cdecl*)(int a1)) 0x63D130)
#define sub_5977E0          ((int(*)(void)) 0x005977E0)
#define sub_482B70          ((int(*)()) 0x00482B70)
#define sub_4849A0			((int(__thiscall*)(DWORD)) 0x004849A0)
#define sub_5BB0B0          ((int(*)()) 0x005BB0B0)
#define sub_4D5C60          ((int(*)()) 0x004D5C60)
#define byte_7BD0483		*(BYTE*)0x7BD0483
#define byte_7BD0484		*(BYTE*)0x7BD0484

struct ButtonRenderChar
{
	DWORD ID;
	float x;
	float y;
	float w;
	float h;
	bool Event;
};

struct Coord
{
	float CoordX;
	float CoordY;
	float Rotate;
};

struct Personaje
{
	int Index;
	Coord Coordenada1;
	Coord Coordenada2;
	ButtonRenderChar BT;
};

struct SelectChar
{
	int Index;
	int MapChar;
	float ModelScale;
	float flt_87933D0;
	float flt_87933D4;
	float flt_87933D8;
	float flt_87933DC;
	float flt_87933E0;
	float flt_87933E4;
	Personaje PJ[MAX_WORLD_SELECT_CHAR];
};

class MultiSelect
{
public:
	//MultiSelect();
	//virtual ~MultiSelect();
	void LoadMultiChar(SelectChar * info);
	void InitMultiChar();
public:
	SelectChar RenderSelect;
};
extern MultiSelect gSelectCharRamdon;