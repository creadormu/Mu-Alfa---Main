#pragma once

#define EnableAlphaTest					((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
#define sub_5984D0						((int (__cdecl*)( char a3 )) 0x005984D0)
#define sub_5BCE80						((bool (__cdecl*)( )) 0x005BCE80)
#define sub_5BD3E0						((bool (__cdecl*)( int a4)) 0x005BD3E0)
#define sub_5BD400						((void *(__cdecl*)( int a4)) 0x005BD400)
#define sub_5BD420						((int (__cdecl*)( int a4)) 0x005BD420)
#define sub_5BD440						((signed int(__cdecl*)( int a4)) 0x005BD440)
#define sub_5D3030						((char(__cdecl*)( int a3)) 0x005D3030)
#define GensPrintLogo					((void(__thiscall*)( int a1, float a5, float a6, char a7, char a8, int a9, float a10)) 0x007C5C20)
#define sub_9D09B0						((int(__cdecl*)( BYTE *a1, BYTE *a2)) 0x009D09B0)
#define sub_8CB0E0						((char(*)( )) 0x008CB0E0)
#define sub_57FB20						((signed int(__cdecl*)(char a1)) 0x0057FB20)
#define sub_57FB70						((signed int(__cdecl*)(char a1)) 0x0057FB70)
#define GetMarkGuild					((void(__cdecl*)(int a4, char a5)) 0x005D30F0)

#define GetAngleCursorX					*(int*)0x879340C
#define GetAngleCursorY					*(int*)0x8793410


class GetBarPlayer
{
public:
	GetBarPlayer();
	~GetBarPlayer();
	void Load();
};

extern GetBarPlayer JumPlayer;