#include "stdafx.h"
#include "GuildLogo.h"
#include "Util.h"

#define CreateGuildMark ((void(__cdecl*)(int nMarkIndex, bool blend)) 0x005D30F0)
#define RenderBitmap ((void(__cdecl*)(int Texture, float x, float y, float Width, float Height, float u, float v, float uWidth, float vHeight, bool Scale, bool StartScale, float Alpha)) 0x00637C60)
#define RenderBoolean ((void(__cdecl*)(int x, int y, DWORD c)) 0x005985F0)

void InitGuildIcon()
{
	SetCompleteHook(0xE8, 0x005BAFAB, &DrawLogo);
}

void DrawLogo(int x, int y, DWORD c)
{
	DWORD character = *(DWORD*)(c + 668); //Get Character Struct

	if (*(BYTE*)(character + 800) == 1) //Check Character Type
	{
		if (*(short*)(character + 124) != -1) //Check Character Guild
		{
			float posX = (float)x - 21.0f;

			if (*(BYTE*)(character + 31) != 0) //Check Character Gens
			{
				posX -= 30.0f;
			}

			CreateGuildMark(*(WORD*)(character + 124), true); //CreateGuildMark

			RenderBitmap(31740, posX, (float)y, 16.0f, 16.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1, 1, 0); //RenderBitmap
		}
	}

	RenderBoolean(x, y, c); //RenderBoolean
}