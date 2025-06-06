#include "stdafx.h"
#include "CChatEx.h"
#include "TMemory.h"
#include "Util.h"
#include "Offset.h"
#include "Object.h"
#include "ChatExpanded.h"
#include "WindowsStruct.h"

CChatEx gCChatEx;

static DWORD chatReader = 0;

#define sub_7889B0		((char (__thiscall*)(MUChat* This)) 0x007889B0)

CChatEx::CChatEx()
{
}

CChatEx::~CChatEx()
{
}


//-- (00787BA0) //-- ChatInput
double sub_787BA0()
{
	return 2.199999809;
}

//-- (0078B0F0) ChatDialog
double sub_78B0F0()
{
	return 2.0999999;
}

//-- (00812120) Interfaz Principal
double sub_812120()
{
	return 2.6;
}

//----- (007D2E50) MuHELPER
double sub_7D2E50()
{
	return 0.3000002;
}

//----- (007E0E90) Pet
char sub_7E0E90()
{
	return 1.0;
}

//----- (0084C870) Party
double sub_84C870()
{
	return 5.4000001;
}

//----- (00857DC0) Baul
double sub_857DC0()
{
	return 3.6;
}

int GetFrameChat(int This)
{
  return *(DWORD *)(This + 16);
}

void cChatFrame_I5( int a1 )
{
	float y; // ST08_4@1
	float x; // ST04_4@1
	float nWidth; // ST08_8@1
	float nHeight; // ST04_8@1
	float v16; // [sp+3Ch] [bp-8h]@2
	float v7; // [sp+40h] [bp-4h]@2
	int This; // [sp+28h] [bp-24h]@1
	int Frame_I3; // [sp+1Ch] [bp-Ch]@1
	

	This = *(DWORD *)(GetInstance() + 12);

	*(signed int *)(This + 20) = 16;
	*(signed int *)(This + 24) = 362;

	y = (double)*(signed int *)(This + 24) + 10;
	x = (double)*(signed int *)(This + 20);

	nWidth = TransForX( 27.7 );
	nHeight = TransForY( 15.625 );

	RenderBitmap(61549, TransForX( x ), TransForY( y - 10), TransForX( 281.0 ), TransForY( 47.0 ), 0.0, 0.0, 0.8765000105, 0.5805000067, 0, 0, 0);
	//-- TextBox Wisper
	SetBoundInputField(*(DWORD *)(This + 40), Return2X(TransForX( x + 5 )), *(DWORD *)(This + 24) + 32);
	//-- TextBox Chat
	SetBoundInputField(*(DWORD *)(This + 36), Return2X(TransForX( x + 72 )), *(DWORD *)(This + 24) + 32);

	Frame_I3 = GetFrameChat(*(DWORD *)(GetInstance() + 12));

	v16 = (double)(*(DWORD *)(Frame_I3 + 296) - *(DWORD *)(Frame_I3 + 312));

	if ( *(BYTE *)(Frame_I3 + 344) )
	{
		RenderBitmap(61551, TransForX( 3 ), TransForY( v16 + 2 ), TransForX( 7.0 ), TransForY( 3.0 ), 0.2650000155, 0.0, 0.2080000043, 0.6999999881, 0, 0, 0);

		for (int i = 0; i < *(DWORD *)(Frame_I3 + 316); ++i )
		{
			v7 = v16 + 2.0 + (double)(15 * i + 3);
			RenderBitmap(61551, TransForX( 3 ), TransForY( v7 ), TransForX( 7.0 ), TransForY( 15.0 ), 0.5309999585, 0.03999999911, 0.2080000043, 0.6701001358, 0, 0, 0);
		}

		RenderBitmap(61551, TransForX( 3 ), TransForY( (double)(*(DWORD *)(Frame_I3 + 296) - 5) ), TransForX( 7.0 ), TransForY( 3.0 ), 0.0, 0.2190000117, 0.2080000043, 0.5001001358, 0, 0, 0);

		RenderBitmap(61548, TransForX( 1 ), TransForY( (double)*(signed int *)(Frame_I3 + 304) ), TransForX( 10 ), TransForY( 30 ), ( *(DWORD *)(Frame_I3 + 340) == 2 ) ? 0.4765000641 : 0.5819999576, 0.5299999714, 0.02870237641, 0.3249999881, 0, 0, 0);
	}
}

DWORD VKEventKEY;
DWORD VKConfig;

//----- (007877B0)
char cChatButton_I3( int a1 )
{
	char result; // al@7
	float y; // ST08_4@1
	float x; // ST04_4@1
	float nWidth; // ST08_8@1
	float nHeight; // ST04_8@1
	int This; // [sp+24h] [bp-4h]@1
	char ButtonText[254];

	This = *(DWORD *)(GetInstance() + 12);

	y = (double)*(signed int *)(This + 24) + 10;
	x = (double)*(signed int *)(This + 20);

	nWidth = TransForX( 27.7 );
	nHeight = TransForY( 15.625 );

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	if( CheckButtonPressed(0, y, Return2X(TransForX( 15.625 )), ReturnY(TransForY( 15.625 ))))
	{
		PlayBuffer(25, 0, 0);
		RenderBitmap(61548, 0, TransForY( y ), TransForX( 15.625 ), TransForY( 15.625 ), 0.2399999946, 0.4151100218, 0.05600007623, 0.2180000395, 0, 0, 0);
		
		if( GetTickCount() >= VKEventKEY + 200 )
		{
			VKConfig = (VKConfig == 1) ? 0 : 1;
			VKEventKEY = GetTickCount();
		}
	}
	else
	{
		RenderBitmap(61548, 0, TransForY( y ), TransForX( 15.625 ), TransForY( 15.625 ), 0.1799999923, 0.4151100218, 0.05600007623, 0.2180000395, 0, 0, 0);
	}

	/*if ( VKConfig == 1 )
	{
		return 0;
	}*/

	for ( int i = 0 ; i < 4 ; i++ )
	{
		RenderBitmap(61548, TransForX(32 * i + *(DWORD *)(This + 20)), TransForY( y ), nWidth, nHeight,( i != *(DWORD*)(DWORD *)(This + 104) ) ? 0.1249999925 : 0.2170000076, 0.0, 0.0850000754, 0.2000000179, 0, 0, 0);
		
		ZeroMemory(ButtonText, sizeof(ButtonText));
		switch ( i )
		{
		case 0:
		wsprintf(ButtonText, pGetTextLine(pTextLineThis, 45));
			break;
		case 1:
		wsprintf(ButtonText, pGetTextLine(pTextLineThis, 944));
			break;
		case 2:
		wsprintf(ButtonText, pGetTextLine(pTextLineThis, 946));
			break;
		case 3:
		wsprintf(ButtonText, pGetTextLine(pTextLineThis, 3091));
			break;
		}
		pDrawText(pTextThis(), Return2X(TransForX(32 * i + *(DWORD *)(This + 20))), y + 3, ButtonText, Return2X(nWidth), 0, (LPINT)3, 0);
	}
	//-- newui_chat_whisper_on
	RenderBitmap(61548, TransForX( x + 128 ), TransForY( y ), nWidth, nHeight, (*(BYTE *)(This + 108)) ? 0.2170000076 : 0.1249999925, 0.0, 0.0850000754, 0.2000000179, 0, 0, 0);
	
	ZeroMemory(ButtonText, sizeof(ButtonText));
	wsprintf(ButtonText, pGetTextLine(pTextLineThis, 945));
	pDrawText(pTextThis(), Return2X(TransForX( x + 128 )), y + 3, ButtonText, Return2X(nWidth), 0, (LPINT)3, 0);

	//-- newui_chat_system_on
	RenderBitmap(61548, TransForX( x + 160), TransForY( y ), nWidth, nHeight, (*(BYTE *)(This + 109)) ? 0.2170000076 : 0.1249999925, 0.0, 0.0850000754, 0.2000000179, 0, 0, 0);
	
	ZeroMemory(ButtonText, sizeof(ButtonText));
	wsprintf(ButtonText, pGetTextLine(pTextLineThis, 3407));
	pDrawText(pTextThis(), Return2X(TransForX( x + 160 )), y + 3, ButtonText, Return2X(nWidth), 0, (LPINT)3, 0);

	//-- newui_chat_chat_on
	RenderBitmap(61548, TransForX( x + 192), TransForY( y ), nWidth, nHeight, (*(BYTE *)(This + 110)) ? 0.2170000076 : 0.1249999925, 0.0, 0.0850000754, 0.2000000179, 0, 0, 0);

	ZeroMemory(ButtonText, sizeof(ButtonText));
	wsprintf(ButtonText, pGetTextLine(pTextLineThis, 3408));
	pDrawText(pTextThis(), Return2X(TransForX( x + 192 )), y + 3, ButtonText, Return2X(nWidth), 0, (LPINT)3, 0);

	nWidth = TransForX( 13.75 );
	nHeight = TransForY( 14.375 );

	result = *(BYTE *)(*(DWORD *)(This + 16) + 344);

	RenderBitmap(61548, TransForX( x + 225 ), TransForY( y ), nWidth, nHeight, ( result ) ? 0.3100000024 : 0.3600000143, 0.0, 0.04800000414, 0.1829999983, 0, 0, 0);

	ChangeButtonInfo((char *)(This + 120), Return2X(TransForX( x + 244 )), y, Return2X(nWidth), ReturnY(nHeight));

	if( CheckButtonPressed(Return2X(TransForX( x + 244 )), y, Return2X(nWidth), ReturnY(nHeight)) &&  result)
	{
		RenderBitmap(61548, TransForX( x + 244 ), TransForY( y ), nWidth, nHeight, 0.4600000978, 0.0, 0.04800000414, 0.1829999983, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61548, TransForX( x + 244 ), TransForY( y ), nWidth, nHeight, ( result ) ? 0.410000056 : 0.4600000978, 0.0, 0.04800000414, 0.1829999983, 0, 0, 0);
	}

	ChangeButtonInfo((char *)(This + 292), Return2X(TransForX( x + 263 )), y, Return2X(nWidth), ReturnY(nHeight));

	if( CheckButtonPressed( Return2X(TransForX( x + 263 )), y, Return2X(nWidth), ReturnY(nHeight))  &&  result)
	{
		RenderBitmap(61548, TransForX( x + 263 ), TransForY( y ), nWidth, nHeight, 0.5100001097, 0.0, 0.04800000414, 0.1829999983, 0, 0, 0);
	}
	else
	{
		RenderBitmap(61548, TransForX( x + 263 ), TransForY( y ), nWidth, nHeight, ( result ) ?  0.5600001216 :  0.5100001097, 0.0, 0.04800000414, 0.1829999983, 0, 0, 0);
	}

	if ( result ) //-- newui_chat_frame_on
	{
		sub_7798F0(This + 120, 0);
		result = sub_7798F0(This + 292, 0);
	}

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C588);
	return result;
}

bool CheckButtonAllChat(int x, int y, int Width, int Height)
{
	int nY; // ST08_4@1
	int nX; // ST04_4@1
	float nWidth; // ST08_8@1
	float nHeight; // ST04_8@1
	int This; // [sp+24h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 12);

	nWidth = Return2X(TransForX( 27.7 ));
	nHeight = ReturnY(TransForY( 15.625 ));

	nY = (double)*(signed int *)(This + 24) + 10;
	nX = (double)(*(DWORD *)(This + 20));

	if( x < nX + 114 )
	{
		for ( int i = 0 ; i < 4 ; i++ )
		{
			if( x == 27 * i + *(DWORD *)(This + 20) )
			{
				x = Return2X(TransForX(32 * i + *(DWORD *)(This + 20)));
				break;
			}
		}
	}
	else if( x == nX + 114 )
	{
		x = Return2X(TransForX( nX + 128 ));
	}
	else if( x == nX + 141 )
	{
		x = Return2X(TransForX( nX + 160));
	}
	else if( x == nX + 168 )
	{
		x = Return2X(TransForX( nX + 192));
	}
	//-- Button Open Init
	else if( x == nX + 200 || x == nX + 201 )
	{
		nWidth = Return2X(TransForX( 13.75 ));
		nHeight = ReturnY(TransForY( 14.375 ));

		x = Return2X(TransForX( nX + 225 ));
	}
	else if( x == nX + 227 ||  x == nX + 228 )
	{
		nWidth = Return2X(TransForX( 13.75 ));
		nHeight = ReturnY(TransForY( 14.375 ));

		x = Return2X(TransForX( nX + 244 ));
	}
	else if( x == nX + 254 ||  x == nX + 255 )
	{
		nWidth = Return2X(TransForX( 13.75 ));
		nHeight = ReturnY(TransForY( 14.375 ));

		x = Return2X(TransForX( nX + 263 ));
	}

	return /*( VKConfig == 1 ) ? false : */pCheckMouseOver(x, nY, nWidth, nHeight);
}

void WisperBarForm(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	pDrawBarForm(PosX, PosY, Return2X(TransForX( Width )), Height, Arg5, Arg6);
}

//----- (007889B0)
int ChatFrame_I2( int a1 )
{
	float alpha; // ST14_4@2
	float nHeight; // ST0C_4@2
	float nWidth; // ST08_4@2
	int Frame_I2; // [sp+1Ch] [bp-Ch]@1

	Frame_I2 = GetFrameChat(*(DWORD *)(GetInstance() + 12));

	*(DWORD *)(Frame_I2 + 296) = /*(pCheckWindow(pWindowThis(), 33)) ?*/ 371; //: 401; //-- Y
	*(signed int *)(Frame_I2 + 308) = Return2X(TransForX( 281.0 )); //-- W
	*(signed int *)(Frame_I2 + 292) = 0; //-- X

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	alpha = (*(float *)(Frame_I2 + 336) > 0.8) ? 1.0f: *(float *)(Frame_I2 + 336);

	if ( *(BYTE *)(Frame_I2 + 344) )
	{
		*(signed int *)(Frame_I2 + 292) = 6; //-- X
		nHeight = (double)TransForY( *(signed int *)(Frame_I2 + 312));
		nWidth = TransForX( 297 );
		RenderBitmap(61534, TransForX( (double)*(signed int *)(Frame_I2 + 292) - 6 ), TransForY( (double)(*(DWORD *)(Frame_I2 + 296) - *(DWORD *)(Frame_I2 + 312)) ), nWidth, nHeight, 0.004999999888, 0.0, 0.9, 0.8899998665, 0, 0, alpha);
	}
	else if( VKConfig == 1 )
	{
		nHeight = (double)TransForY( *(signed int *)(Frame_I2 + 312));
		nWidth = TransForX( 297 );
		RenderBitmap(61534, TransForX( (double)*(signed int *)(Frame_I2 + 292) - 6 ), TransForY( (double)(*(DWORD *)(Frame_I2 + 296) - *(DWORD *)(Frame_I2 + 312)) ), nWidth, nHeight, 0.004999999888, 0.0, 0.9, 0.8899998665, 0, 0, alpha);
	}

	pGLSwitch();
	EnableAlphaTest(0);

	return 1;
}

//----- (00789110)
int ChatFrame_I3( int a1 )
{
	float y; // ST30_4@5
	float x; // [sp+40h] [bp-4h]@2
	float nHeight; // [sp+3Ch] [bp-8h]@2
	float alpha; // ST14_4@2
	int Frame_I3; // [sp+34h] [bp-10h]@1

	Frame_I3 = GetFrameChat(*(DWORD *)(GetInstance() + 12));

	*(signed int *)(Frame_I3 + 308) = Return2X(TransForX( 281.0 )); //-- W

	if ( *(BYTE *)(Frame_I3 + 344) )
	{
		alpha = (*(float *)(Frame_I3 + 336) > 0.8) ? 1.0f: *(float *)(Frame_I3 + 336);

		*(DWORD *)(Frame_I3 + 300) = *(signed int *)(Frame_I3 + 292) - 1;
		x = (double)*(signed int *)(Frame_I3 + 292);
		nHeight = (double)(*(DWORD *)(Frame_I3 + 296) - *(DWORD *)(Frame_I3 + 312));

		pSetBlend(1);

		if ( *(DWORD *)(Frame_I3 + 340) == 4 )
			glColor4f(0.69999999, 0.69999999, 0.69999999, alpha);
		else
			glColor4f(1.0, 1.0, 1.0, alpha);
		EnableAlphaTest(1);
		y = nHeight - 16.0f;

		RenderBitmap(61550, TransForX( x - 6), TransForY( y ), TransForX( 297 ), TransForY( 15.0f ), 0.003999999724, 0.0, 0.9909999967, 0.9399999976, 0, 0, 0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		pGLSupremo();
		pSetBlend(0);
	}
	return 1;
}

bool CheckDrawSyetemChat(int x, int y, int Width, int Height)
{
	return pCheckMouseOver(Return2X(TransForX( x )), y - 6, Return2X(TransForX( Width )), 15);
}

void SetColorChat(int ChatType)
{
	if ( ChatType == 1 )
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xCDu, 0xDCu, 0xEFu, 0xFFu);
	}
	else if ( ChatType == 2 )
	{
		pSetBackgroundTextColor(pTextThis(), 0xFFu, 0xC8u, 0x32u, 0x96u);
		pSetTextColor(pTextThis(), 0, 0, 0, 0xFFu);
	}
	else if ( ChatType == 3 )
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else if ( ChatType == 4 )
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xFFu, 0x1Eu, 0, 0xFFu);
	}
	else if ( ChatType == 5 ) //-- Party
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0x99u, 0xCCu, 0xFFu, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if ( ChatType == 6 ) //-- Guild
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xFFu, 0xCCu, 0x99u, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if ( ChatType == 7 ) //-- Guild Alianza
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if ( ChatType == 8 ) //-- Chat Game Master
	{
		pSetBackgroundTextColor(pTextThis(), 0x1Eu, 0x1Eu, 0x1Eu, 0xC8u);
		pSetTextColor(pTextThis(), 0xFAu, 0xC8u, 0x32u, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
	else if ( ChatType == 9 ) //-- Chat Gens
	{
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x96u);
		pSetTextColor(pTextThis(), 0x99, 0xCCu, 0, 0xFFu);
		pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	}
}

__declspec (naked) void ChatTextColor()
{
	static DWORD main1_Addr = 0x00788F29;
	static DWORD main2_Addr = 0x00788F25;
	static DWORD main1_Call = 0x0078C050;
	static DWORD main_This;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x2C]
		CALL main1_Call
		MOV main_This, EAX
	}

	if( main_This == 1 || main_This == 2
		|| main_This == 3 || main_This == 4
		|| main_This == 5 || main_This == 6
		|| main_This == 7 || main_This == 8
		|| main_This == 9 )
	{
		SetColorChat( main_This );

		_asm
		{
			JMP [main1_Addr]
		}
	}
	else
	{
		_asm
		{
			JMP [main2_Addr]
		}
	}
}

void sub_5985F0(signed int a4, signed int a5, int a6)
{
	int v125; // [sp+3Ch] [bp-24h]@26
	int v126; // [sp+40h] [bp-20h]@26
	int v128; // [sp+48h] [bp-18h]@26
	int v129; // [sp+4Ch] [bp-14h]@26
	int v130; // [sp+50h] [bp-10h]@26

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)(a6 + 668) + 1260), 27) )
		return;
	if ( *(DWORD *)(a6 + 668) != *(DWORD *)0x7BC4F04
	&& *(BYTE *)0x9867233 == 1
	&& pCheckEffectPlayer((DWORD *)(*(DWORD *)(a6 + 668) + 1260), 18) )
	{
		if ( *(BYTE *)(*(DWORD *)0x7BC4F04 + 23) != 9 && *(BYTE *)(*(DWORD *)0x7BC4F04 + 23) != 6 )
		{
			if ( *(BYTE *)(*(DWORD *)0x7BC4F04 + 23) != 10 && *(BYTE *)(*(DWORD *)0x7BC4F04 + 23) != 7 )
			{
				if ( *(BYTE *)(*(DWORD *)0x7BC4F04 + 23) != 11 && *(BYTE *)(*(DWORD *)0x7BC4F04 + 23) != 8 )
				{
					if ( (*(BYTE *)(*(DWORD *)0x7BC4F04 + 23) == 13 || *(BYTE *)(*(DWORD *)0x7BC4F04 + 23) == 12)
					&& *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 13
					&& *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 12 )
					{
					return;
					}
				}
				else if ( *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 11 && *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 8 )
				{
					return;
				}
			}
			else if ( *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 10 && *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 7 )
			{
				return;
			}
		}
		else if ( *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 9 && *(BYTE *)(*(DWORD *)(a6 + 668) + 23) != 6 )
		{
			return;
		}
	}

	pSetBlend(1);
	glColor3f(1.0, 1.0, 1.0);
	if ( *(DWORD *)0x81C0380 > 32 )
		*(DWORD *)0x81C0380 = 32;
	v128 = a4;
	v129 = a5;
	v125 = *(DWORD *)(a6 + 680);
	v126 = *(DWORD *)(a6 + 684);
	v130 = (double)*(DWORD *)0x81C0380 / *(float *)0xE7C3D8;
	//-- STORE
	/*if ( sub_5BD3E0(*(DWORD *)(a6 + 668)) )
	{
	}*/
}

//----- (00886D00) MiniMap
double sub_886D00()
{
	return 1.6;
}

void CChatEx::Load()
{
	//SetCompleteHook(0xE9, 0x00788C59, &sub_5985F0); //-- TEST
	MemorySet(0x00785B44, 0x90, 0x5);
	//SetCompleteHook(0xE9, 0x00788C59, &ChatTextColor); //-- Text
	SetCompleteHook(0xE8, 0x0078ADCC, &CheckDrawSyetemChat); //-- Interface
	SetCompleteHook(0xE8, 0x0078AE15, &CheckDrawSyetemChat); //-- Interface
	SetCompleteHook(0xE8, 0x0078AE5E, &CheckDrawSyetemChat); //-- Interface

	SetCompleteHook(0xE8, 0x0078B09A, &ChatFrame_I2); //-- Interface
	SetCompleteHook(0xE8, 0x0078B0CF, &ChatFrame_I3); //-- Interface
	SetCompleteHook(0xE8, 0x00787620, &cChatFrame_I5);

	SetCompleteHook(0xE8, 0x00787748, &WisperBarForm);

	SetCompleteHook(0xE8, 0x00787628, &cChatButton_I3);
	SetCompleteHook(0xE8, 0x007864B3, &CheckButtonAllChat); //-- Chat On
	SetCompleteHook(0xE8, 0x0078641E, &CheckButtonAllChat); //-- Chat On
	SetCompleteHook(0xE8, 0x007863A8, &CheckButtonAllChat); //-- System
	SetCompleteHook(0xE8, 0x00786347, &CheckButtonAllChat); //-- Wisper
	SetCompleteHook(0xE8, 0x007862E2, &CheckButtonAllChat); //-- Basico
	SetCompleteHook(0xE8, 0x0078628E, &CheckButtonAllChat); //-- ToolTip

	SetCompleteHook(0xE9, 0x00857DC0, &sub_857DC0); //-- Interface
	//SetCompleteHook(0xE9, 0x007E0E90, &sub_7E0E90); //-- Interface Pet
	SetCompleteHook(0xE9, 0x007D2E50, &sub_7D2E50); //-- Interface MUHELPER
	SetCompleteHook(0xE9, 0x00812120, &sub_812120); //-- Interface Principal
	SetCompleteHook(0xE9, 0x0078B0F0, &sub_78B0F0); //-- ChatDialog
	SetCompleteHook(0xE9, 0x00787BA0, &sub_787BA0); //-- ChatInput
}