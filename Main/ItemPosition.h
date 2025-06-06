#pragma once

#include "Object.h"
//----- (009CEBF0) --------------------------------------------------------
#define sub_9CEBF0		((signed int(__thiscall*)(float a1)) 0x009CEBF0)
//----- (00790B10) --------------------------------------------------------
#define sub_790B10		((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
//----- (00860A60) --------------------------------------------------------
#define sub_860A60		((bool(__thiscall*)(int *This)) 0x00860A60)
//----- (00943AB0) --------------------------------------------------------
#define sub_943AB0		((int(__thiscall*)(int This, __int16 a2, float a3, float a4)) 0x00943AB0)
//----- (00861840) --------------------------------------------------------
#define sub_861840		((int(__thiscall*)(int This)) 0x00861840)
//----- (005D4840) --------------------------------------------------------
#define sub_5D4840		((char(__thiscall*)(int This)) 0x005D4840)
//----- (00943BA0) --------------------------------------------------------
#define sub_943BA0		((int(__thiscall*)(int This, int a2)) 0x00943BA0)
//----- (005D6600) --------------------------------------------------------
#define sub_5D6600		((int(__thiscall*)(int This, int a2)) 0x005D6600)
//----- (005D6630) --------------------------------------------------------
#define sub_5D6630		((int(__thiscall*)(int This, int a2)) 0x005D6630)
//----- (005CF310) --------------------------------------------------------
#define sub_5CF310		((void(__cdecl*)( float a4, float a5, float a6, float a7, int a8, int a9, int a10, int a11, char a12)) 0x005CF310)

#define sub_5CA0D0			((void(__cdecl*)(signed int a1, signed int a2, int a3, int a4, VAngle *a5, int a6, char a7)) 0x5CA0D0)

class cItemPosition
{
public:
	void Load();
	
	//static void CustomPosition(signed int a1, signed int a2, int a3, int a4, VAngle *a5, int a6, char a7);
	//static void CustomPosition2( float a4, float a5, float a6, float a7, int a8, int a9, int a10, int a11, char a12);

}; extern cItemPosition gItemPosition;