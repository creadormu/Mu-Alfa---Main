#include "StdAfx.h"
#include "GetBarPlayer.h"
#include "Util.h"
#include "Import.h"
#include "Protect.h"

GetBarPlayer JumPlayer;

GetBarPlayer::GetBarPlayer()
{
}


GetBarPlayer::~GetBarPlayer()
{
}

signed int sub_9CEBF0(double a1)
{
	return (signed int)a1;
}

//----- (005985F0) --------------------------------------------------------
void GetBitBarname(signed int a4, signed int a5, int a6)
{
	float v26; // ST18_4@38
	char v34; // ST10_1@39
	char v35; // ST0C_1@39
	int v48; // ST18_4@48
	int v50; // ST18_4@48
	char v109; // ST10_1@95
	char v110; // ST0C_1@95
	char v122; // [sp+28h] [bp-38h]@35
	signed int v123; // [sp+30h] [bp-30h]@35
	int v124; // [sp+34h] [bp-2Ch]@27
	int v125; // [sp+3Ch] [bp-24h]@26
	int v126; // [sp+40h] [bp-20h]@26
	char v127; // [sp+47h] [bp-19h]@40
	int v128; // [sp+48h] [bp-18h]@26
	int v129; // [sp+4Ch] [bp-14h]@26
	int v130; // [sp+50h] [bp-10h]@26
	int v131; // [sp+54h] [bp-Ch]@84
	int v132; // [sp+58h] [bp-8h]@84
	unsigned __int8 v133; // [sp+5Ch] [bp-4h]@77
	unsigned __int8 v134; // [sp+5Dh] [bp-3h]@77
	int guild = 1;

	if ((((pMapNumber)<18) ? 0 : ((pMapNumber)>23) ? (((pMapNumber) == 53) ? 1 : 0) : 1) == 1) //Disable in Chaos Castle
	{
		return;
	}

	if (*(BYTE *)(*(DWORD *)(a6 + 668) + 24) == 255)
	{
		guild = 0;
	}
	if (pCheckEffectPlayer((DWORD *)(*(DWORD *)(a6 + 668) + 1260), 27))
		return;
	if (*(DWORD *)(a6 + 668) != dword_7BC4F04 && sub_8CB0E0() == 1
		&& pCheckEffectPlayer((DWORD *)(*(DWORD *)(a6 + 668) + 1260), 18))
	{
		if (*(BYTE *)(dword_7BC4F04 + 23) != 9 && *(BYTE *)(dword_7BC4F04 + 23) != 6)
		{
			if (*(BYTE *)(dword_7BC4F04 + 23) != 10 && *(BYTE *)(dword_7BC4F04 + 23) != 7)
			{
				if (*(BYTE *)(dword_7BC4F04 + 23) != 11 && *(BYTE *)(dword_7BC4F04 + 23) != 8)
				{
					if ((*(BYTE *)(dword_7BC4F04 + 23) == 13 || *(BYTE *)(dword_7BC4F04 + 23) == 12)
						&& *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 13
						&& *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 12)
					{
						return;
					}
				}
				else if (*(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 11 && *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 8)
				{
					return;
				}
			}
			else if (*(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 10 && *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 7)
			{
				return;
			}
		}
		else if (*(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 9 && *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 6)
		{
			return;
		}
	}
	EnableAlphaTest(1);
	glColor3f(1.0, 1.0, 1.0);
	if (*(DWORD *)0x81C0380 > 32)
		dword_81C0380 = 32;
	v128 = a4;
	v129 = a5;
	v125 = *(DWORD *)(a6 + 680);
	v126 = *(DWORD *)(a6 + 684);
	v130 = sub_9CEBF0((double)dword_81C0380 / *(float*)0xE7C3D8);
	//-- InfoPlayer[Store]
	if (sub_5BD3E0(*(DWORD*)(a6 + 668)))
	{
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);

		sub_4200F0_Addr(pTextThis(), sub_5BD440(*(DWORD *)(a6 + 668)));
		SetTextColorByHDC(pTextThis(), (int)sub_5BD400(*(DWORD *)(a6 + 668)));
		pDrawText(pTextThis(), v128, v129, pGetTextLine(pTextLineThis, 1104), 0, v130, (LPINT)1, (int)&v124);

		v128 += v124;

		SetTextColorByHDC(pTextThis(), sub_5BD420(*(DWORD *)(a6 + 668)));
		pDrawText(pTextThis(), v128, v129, (char *)(a6 + 124), v125 - v124, v130, (LPINT)1, (int)&v124);

		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C588);
		v128 = a4;
		v129 += v130;
	}
	else if (sub_5D3030(*(DWORD*)0xE61E18)
		&& *(BYTE *)(dword_7BC4F04 + 31) != *(BYTE *)(*(DWORD *)(a6 + 668) + 31)
		&& !sub_5BCE80()
		&& *(BYTE *)(*(DWORD *)(a6 + 668) + 800) == 1)
	{
		if (!*(DWORD *)(*(DWORD *)(a6 + 668) + 1428))
			return;
		if (*(BYTE *)(*(DWORD *)(a6 + 668) + 800) == 1 && *(DWORD *)(*(DWORD *)(a6 + 668) + 824) == 1163)
		{
			v123 = sub_9CEBF0((double)*(signed int *)(a6 + 672) + (double)*(signed int *)(a6 + 680) * 0.5 + 20.0);
			v122 = *(BYTE *)(*(DWORD *)(a6 + 668) + 31);

			v34 = *(BYTE *)(*(DWORD *)(a6 + 668) + 1424);
			v35 = *(BYTE *)(*(DWORD *)(a6 + 668) + 31);

			if (v122 == 1)
			{
				GensPrintLogo(*(DWORD *)(GetInstance() + 288), (double)v123, (double)a5, v35, v34, 1, (double)v129);
				return;
			}
			if (v122 == 2)
			{
				GensPrintLogo(*(DWORD *)(GetInstance() + 288), (double)v123, (double)a5, v35, v34, 1, (double)v129);
				return;
			}
		}
	}
	v127 = 0;
	//-- InfoPlayer[GM]
	if (pCheckEffectPlayer((DWORD *)(*(DWORD *)(a6 + 668) + 1260), 28)
		|| *(BYTE *)(*(DWORD *)(a6 + 668) + 21) == 32
		|| *(BYTE *)(*(DWORD *)(a6 + 668) + 21) == 8)
	{
		v127 = 1;
		pSetBackgroundTextColor(pTextThis(), 0x1Eu, 0x1Eu, 0x1Eu, 0xC8u);
		pSetTextColor(pTextThis(), 0xC8u, 0xFFu, 0xFFu, 0xFFu);
	}
	//-- InfoPlayer[PJ]
	if (*(DWORD *)(a6 + 668) == dword_7BC4F04)
	{
		pSetBackgroundTextColor(pTextThis(), 0x3Cu, 0x64u, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xC8u, 0xFFu, 0, 0xFFu);
	}
	//-- InfoPlayer[OtherPlayer]
	else if (*(WORD *)(*(DWORD *)(a6 + 668) + 124) == *(WORD *)(dword_7BC4F04 + 124))
	{
		sub_4200F0_Addr(pTextThis(), sub_57FB70(1));
		SetTextColorByHDC(pTextThis(), sub_57FB20(1));
	}
	else
	{
		v48 = sub_57FB70(*(BYTE *)(*(DWORD *)(a6 + 668) + 26));
		sub_4200F0_Addr(pTextThis(), v48);
		v50 = sub_57FB20(*(BYTE *)(*(DWORD *)(a6 + 668) + 26));
		SetTextColorByHDC(pTextThis(), v50);
	}

	if (a6 != -64 && *(BYTE *)(a6 + 64))
	{
		pDrawText(pTextThis(), v128, v129, (char *)(a6 + 64), v125, v130, (LPINT)1, 0);
		v129 += v130;
	}
	//-- InfoPlayer[Guild]
	if (a6 != -94 && *(BYTE *)(a6 + 94))
	{
		pDrawText(pTextThis(), v128, v129, (char *)(a6 + 94), v125, v130, (LPINT)1, 0);
		v129 += v130;
	}
	if (v127)
	{
		pSetTextColor(pTextThis(), 0x64u, 0xFAu, 0xFAu, 0xFFu);
	}
	else
	{
		sub_5984D0(*(BYTE *)(a6 + 140));
	}
	if (*(DWORD *)(a6 + 672) <= GetAngleCursorX
		&& GetAngleCursorX < (signed int)(*(DWORD *)(a6 + 672) + 640 * *(DWORD *)(a6 + 680) / (unsigned int)*(QWORD*)0xE61E58)
		&& *(DWORD *)(a6 + 676) <= GetAngleCursorY
		&& GetAngleCursorY < (signed int)(*(DWORD *)(a6 + 676)
		+ 480 * *(DWORD *)(a6 + 684) / (unsigned int)*(QWORD *)0xE61E5C)
		&& *(BYTE *)0xE61744
		&& *(BYTE *)(dword_7BC4F04 + 14)
		&& sub_9D09B0((BYTE *)a6, (BYTE *)(dword_7BC4F04 + 56))
		&& (unsigned int)(signed __int64)*(float*)0x5EF5A1C % 0x18 < 0xC)
	{
		sub_4200F0_Addr(pTextThis(), sub_41FFE0_Addr(pTextThis()));

		SetTextColorByHDC(pTextThis(), sub_420010_Addr(pTextThis()));
	}
	//-- InfoPlayer[name]
	if (v127)
	{
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
		pDrawText(pTextThis(), v128, v129, (char *)a6, v125, v130, (LPINT)1, 0);
		v129 += v130;
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C588);
	}
	else
	{
		pDrawText(pTextThis(), v128, v129, (char *)a6, v125, v130, (LPINT)1, 0);
		v129 += v130;
	}
	if (*(BYTE *)(a6 + 141))
	{
		if (*(BYTE *)(a6 + 141) == 1)
		{
			pSetBackgroundTextColor(pTextThis(), 0x1Eu, 0x32u, 0, 0x96u);
		}
		else if (v127)
		{
			pSetBackgroundTextColor(pTextThis(), 0x1Eu, 0x1Eu, 0x1Eu, 0xC8u);
		}
		else
		{
			pSetBackgroundTextColor(pTextThis(), 0x32u, 0, 0, 0x96u);
		}
	}
	else
	{
		pSetBackgroundTextColor(pTextThis(), 0xAu, 0x1Eu, 0x32u, 0x96u);
	}

	v133 = 0xFF;
	v134 = 0xFF;
	if (*(DWORD *)(a6 + 660) > 0 && *(DWORD *)(a6 + 660) < 10)
		v133 = 0x80;
	if (*(DWORD *)(a6 + 664) > 0 && *(DWORD *)(a6 + 664) < 10)
		v134 = 0x80;
	if (v127)
	{
		v131 = pMakeColor(0xFAu, 0xC8u, 0x32u, v133);
		v132 = pMakeColor(0xFAu, 0xC8u, 0x32u, v134);
	}
	else
	{
		v131 = pMakeColor(0xE6u, 0xDCu, 0xC8u, v133);
		v132 = pMakeColor(0xE6u, 0xDCu, 0xC8u, v134);
	}
	//-- InfoPlayer[ Dialog ]
	if (*(DWORD *)(a6 + 664) <= 0)
	{
		if (*(DWORD *)(a6 + 660) > 0)
		{
			SetTextColorByHDC(pTextThis(), v131);
			pDrawText(pTextThis(), v128, v129, (char *)(a6 + 148), v125, v130, (LPINT)1, 0);
		}
	}
	else
	{
		SetTextColorByHDC(pTextThis(), v132);
		pDrawText(pTextThis(), v128, v129, (char *)(a6 + 404), v125, v130, (LPINT)1, 0);
		v129 += v130;

		SetTextColorByHDC(pTextThis(), v131);
		pDrawText(pTextThis(), v128, v129, (char *)(a6 + 148), v125, v130, (LPINT)1, 0);
	}

	//-- InfoPlayer[ Gens Logo ]
	if (*(BYTE *)(*(DWORD *)(a6 + 668) + 800) == 1 && *(DWORD *)(*(DWORD *)(a6 + 668) + 824) == 1163)
	{
		//-- revisa si tiene guild
		if (guild == 0)
		{
			v26 = 0.0;
		}
		else
		{
			v26 = 20.0;
			GetMarkGuild(*(WORD *)(*(DWORD *)(a6 + 668) + 124), 1);
			RenderBitmap(31740, (double)a4 - v26, (double)a5, 18.0, 18.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		}
		if (*(DWORD *)(a6 + 664) > 0)
			v129 -= v130;

		if (*(BYTE *)(*(DWORD *)(a6 + 668) + 31) == 1 || *(BYTE *)(*(DWORD *)(a6 + 668) + 31) == 2)
		{
			v109 = *(BYTE *)(*(DWORD *)(a6 + 668) + 1424);
			v110 = *(BYTE *)(*(DWORD *)(a6 + 668) + 31);
			GensPrintLogo(*(DWORD *)(GetInstance() + 288), (double)a4 - v26, (double)a5, v110, v109, 1, (double)v129);
		}
	}
}
// E61744: using guessed type char byte_E61744;
// E61E18: using guessed type int dword_E61E18;
// E7C3D8: using guessed type float flt_E7C3D8;
// 5EF5A1C: using guessed type float flt_5EF5A1C;
// 7BC4F04: using guessed type int dword_7BC4F04;
// 81C0380: using guessed type int dword_81C0380;
// 879340C: using guessed type int dword_879340C;
// 8793410: using guessed type int dword_8793410;

__declspec(naked) void PlayerInfoCheckDelect()
{
	static DWORD Addr_JMP = 0x00842869;
	_asm
	{
		JMP[Addr_JMP]
	}
}

void GetBarPlayer::Load()
{
		SetCompleteHook(0xE8, 0x005BAFAB, &GetBitBarname);
	
}