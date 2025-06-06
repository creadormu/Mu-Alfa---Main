#pragma once
#include "Interface.h"
#include "Defines.h"

#define LoadBitmapA			((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define RenderBitmap		((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)
#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)


class CChatEx
{
public:
	CChatEx();
	virtual ~CChatEx();
	void Load();
private:
	
};
extern CChatEx gCChatEx;