#include "stdafx.h"
#include "Util.h"
#include "FloatCharInfo.h"

#define sub_416C40_Addr			((void(__thiscall*)(int a1)) 0x416C40)
#define sub_416640_Addr			((int(__fastcall*)(int a1, int a2, signed int a3, signed int a4, char a5)) 0x416640)
#define sub_416640_Addr			((int(__fastcall*)(int a1, int a2, signed int a3, signed int a4, char a5)) 0x416640)

int __fastcall sub_416640(int a1, int a2, signed int a3, signed int a4, char a5)
{
	static int Mov = 0;
	static bool type = 0;
	a4+=Mov;
	if (type == 0)
	{
		Mov--;
	}
	else
	{
		Mov++;
	}
	if(Mov==-100)
	{
		type = 1;
	}
	if (Mov==0)
	{
		type = 0;
	}
	return sub_416640_Addr(a1,a2,a3,a4,a5);
}

void CharInfoMov()
{
	SetCompleteHook(0xE8,0x401DA0+0xA9,&sub_416640); //MOV
}
