#include "stdafx.h"
#include "Util.h"
#include "Import.h"
#include "Object.h"
#include "Defines.h"
#include "JCRendernoItemGlow.h"
#include "InfoLog.h"

JCRemoveGLow JCRemoveGlow;

JCRemoveGLow::JCRemoveGLow() // OK
{
	this->m_JCRemoveGlow.clear();
}

JCRemoveGLow::~JCRemoveGLow() // OK
{

}

void JCRemoveGLow::Load(JCItemnoGlow* info) // OK
{
	for (int n = 0; n < MAX_NOGLOW; n++)
	{
		if ( info[n].ItemIndex < 0 )
		{
			return;
		}

		//gInfoLog.Output(LOG_CHAT, "Entrando: [ %d ] Texture: [ %d ]",info[n].ItemIndex, info[n].IndexTexture);
		this->m_JCRemoveGlow.push_back(info[n]);
	}
}

int JCRemoveGLow::JCANALYZE( int JCThis, int JCItemID, int JCModel, int JCStructEffect )
{
	int num = -1;
	int Item = JCItemID - 1171;

	for(std::vector<JCItemnoGlow>::iterator it = this->m_JCRemoveGlow.begin();it != this->m_JCRemoveGlow.end();it++)
	{
		if( it->ItemIndex == Item )
		{
			pTexEffect(
				JCThis,
				it->IndexTexture,
				JCModel,
				*(float *)(JCStructEffect + 152),
				*(DWORD *)(JCStructEffect + 68),
				*(float *)(JCStructEffect + 100),
				*(float *)(JCStructEffect + 104),
				*(float *)(JCStructEffect + 108),
				-1);
			num = JCItemID;
		}
	}

	return num;
}

int JCRemoveGLow::JCANALYZEOPT( int JCThis, int JCItemID, int JCModel, int JCStructEffect )
{
	int num = -1;
	int Item = JCItemID - 1171;

	for(std::vector<JCItemnoGlow>::iterator it = this->m_JCRemoveGlow.begin();it != this->m_JCRemoveGlow.end();it++)
	{
		if( it->ItemIndex == Item )
		{
			pTexEffect(
				JCThis,
				it->IndexTexture,
				66,
				JCModel,
				*(DWORD *)(JCStructEffect + 68),
				*(float *)(JCStructEffect + 100),
				*(float *)(JCStructEffect + 104),
				*(float *)(JCStructEffect + 108),
				-1);
			num = JCItemID;
		}
	}

	return num;
}

int JCANALYZER( int JCThis, int JCItemID, int JCModel, int JCStructEffect, int Type)
{
	int num = -1;
	
	if( Type == 1 )
	{
		num = JCRemoveGlow.JCANALYZE(JCThis, JCItemID, JCModel, JCStructEffect);
	}
	else
	{
		num = JCRemoveGlow.JCANALYZEOPT(JCThis, JCItemID, JCModel, JCStructEffect);
	}

	return num;
}

__declspec(naked) void JCGetPartGlowObject_1()
{
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;

	_asm
	{
		//--
		MOV EAX, DWORD PTR SS:[EBP+0x10]
		MOV JCItemID, EAX
		//--
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV JCThis, EDX
		//--
		MOV EAX,DWORD PTR SS:[EBP+0x18]
		MOV JCModel, EAX
		//--
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		MOV JCStructEffect, ECX
	}

	JCANALYZER_ITEM = JCANALYZER(JCThis, JCItemID, JCModel, JCStructEffect, 1);

	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00608CB5;
	}
	else if( JCANALYZER_ITEM == JCItemID )
	{
		main_addr = 0x00608F8F;
	}
	else
	{
		main_addr = 0x00608CFC;
	}
	_asm
	{
		JMP[ main_addr ]
	}
}

__declspec(naked) void JCGetPartBrightnessObject_2()
{
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;

	_asm
	{
		//--
		MOV EAX, DWORD PTR SS:[EBP+0x10]
		MOV JCItemID, EAX
		//--
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV JCThis, EDX
		//--
		MOV EAX,DWORD PTR SS:[EBP+0x18]
		MOV JCModel, EAX
		//--
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		MOV JCStructEffect, ECX
	}

	JCANALYZER_ITEM = JCANALYZER(JCThis, JCItemID, JCModel, JCStructEffect, 1);
	
	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00609556;
	}
	else if( JCANALYZER_ITEM == JCItemID )
	{
		main_addr = 0x006097AC;
	}
	else
	{
		main_addr = 0x0060959D;
	}

	_asm
	{
		JMP[ main_addr ]
	}
}

__declspec(naked) void JCGetPartOptionObject_3()
{
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0xC]
		MOV JCItemID,EDX
		//--
		MOV ECX,DWORD PTR SS:[EBP - 0x8]
		MOV JCThis,ECX
		//--
		MOV ECX,DWORD PTR SS:[EBP + 0x14]
		MOV JCModel,ECX
		//--
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOV JCStructEffect,EAX
	}

	JCANALYZER_ITEM = JCANALYZER(JCThis, JCItemID, JCModel, JCStructEffect, 2);
	
	if ( JCItemID == 0x12E6 )
	{
		main_addr = 0x0060F055;
	}
	else if( JCANALYZER_ITEM == JCItemID )
	{
		main_addr = 0x0060F320;
	}
	else
	{
		main_addr = 0x0060F094;
	}

	_asm
	{
		JMP[ main_addr ]
	}
}

void JCRemoveGLow::Init( ) // OK
{
	SetRange(0x00608CAC , 7, 0x90);
	SetOp(0x00608CAC, (LPVOID)JCGetPartGlowObject_1, 0xE9);

	SetRange(0x0060954D , 7, 0x90);
	SetOp(0x0060954D, (LPVOID)JCGetPartBrightnessObject_2, 0xE9);

	SetRange(0x0060F04C , 7, 0x90);
	SetOp(0x0060F04C, (LPVOID)JCGetPartOptionObject_3, 0xE9);
}