
#include "stdafx.h"
#include "Util.h"
#include "ItemGlow.h"
#include "Import.h"

JCRenderMesh JCRender;

JCRenderMesh::JCRenderMesh()
{
	this->m_JCRenderMesh.clear();
}

JCRenderMesh::~JCRenderMesh()
{
}

void JCRenderMesh::Load(ITEM_RENDER_MESH * info)
{
	for ( int n = 0; n < MAX_JCRENDER_MESH; n++ )
	{
		if ( info[n].ItemIndex < 0 )
		{
			return;
		}

		//gInfoLog.Output(LOG_CHAT, "Entrando: [ %d ] Texture: [ %d ]",info[n].ItemIndex, info[n].IndexTexture);
		this->m_JCRenderMesh.push_back(info[n]);
	}
}

int JCRenderMesh::JCSearch( int JCItemID, int JCModelObject, int JCModelEffect, int JCRegistro )
{
	int num = -1;

	int Item = JCItemID - 1171;

	std::vector<ITEM_RENDER_MESH>::iterator it;

	for( it = this->m_JCRenderMesh.begin(); it != this->m_JCRenderMesh.end(); it++)
	{
		if( it->ItemIndex == Item )
		{
			pCustomEffGet2(
				JCModelEffect,
				JCRegistro,
				*(float *)(JCModelObject + 152),
				1,
				*(float *)(JCModelObject + 100),
				*(float *)(JCModelObject + 104),
				*(float *)(JCModelObject + 108),
				-1,
				-1);

				*(float *)(JCModelEffect + 72) = it->ColorR;
				*(float *)(JCModelEffect + 76) = it->ColorG;
				*(float *)(JCModelEffect + 80) = it->ColorB;

				pCustomEffGet2(
					JCModelEffect,
					68,
					*(float *)(JCModelObject + 152),
					*(DWORD *)(JCModelObject + 68),
					*(float *)(JCModelObject + 100),
					*(float *)(JCModelObject + 104),
					*(float *)(JCModelObject + 108),
					*(DWORD *)(JCModelObject + 60),
					32042);

				pCustomEffGet2(
					JCModelEffect,
					72,
					*(float *)(JCModelObject + 152),
					*(DWORD *)(JCModelObject + 68),
					*(float *)(JCModelObject + 100),
					*(float *)(JCModelObject + 104),
					*(float *)(JCModelObject + 108),
					*(DWORD *)(JCModelObject + 60),
					32113);

			num = JCItemID;
		}
	}

	return num;
}

int JCRenderSearch( int JCItemID, int JCModelObject, int JCModelEffect, int JCRegistro )
{
	int num = -1;
	
	num = JCRender.JCSearch( JCItemID, JCModelObject, JCModelEffect, JCRegistro );

	return num;
}

__declspec(naked) void JCGetPartObject()
{
	static DWORD JCRenderItemID;
	static DWORD JCItemID;
	static DWORD JCModelObject;
	static DWORD JCModelEffect;
	static DWORD JCRegistro;
	static DWORD main_addr;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x10]
		MOV JCItemID,EDX
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		MOV JCModelObject,ECX
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		MOV JCModelEffect,ECX
		MOV EDX,DWORD PTR SS:[EBP+0x18]
		MOV JCRegistro, EDX
	}

	JCRenderItemID = JCRenderSearch(JCItemID, JCModelObject, JCModelEffect, JCRegistro);
	
	if( JCItemID == JCRenderItemID )
	{
		main_addr = 0x00608175;
	}
	else if ( JCItemID < 8870 || JCItemID > 8878 )
	{
		main_addr = 0x005FB72B;
	}
	else
	{
		main_addr = 0x005FB66E;
	}
	_asm
	{
		JMP[main_addr]
	}
}

void JCRenderMesh::Init()
{
#if UPDATE > 15
	SetCompleteHook(0xE9, 0x005FB64E, &JCGetPartObject); //-- glow a item del inventario
#endif
}
