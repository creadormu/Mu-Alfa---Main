#include "stdafx.h"
#include "SetEffect.h"
#include "Import.h"
#include "Defines.h"
#include "zzzmathlib.h"
#include "Util.h"

cCSetEffect gSeteffect;

cCSetEffect::cCSetEffect()
{
}

cCSetEffect::~cCSetEffect()
{
}

void cCSetEffect::Load(SET_EFFECT_CUSTOM * info)
{
	for( int n = 0; n < maximu_ceffect; n++)
	{
		if(info[n].Index < 0 || info[n].Index >= maximu_ceffect)
		{
			return;
		}
		this->m_SetCEffect.push_back(info[n]);
	}
}

void cCSetEffect::RenderPartObjectBody(int a1, int a2, int a3, float a4, int a5)
{
	float v186; // STAC_4@797
	float v187; // ST30_4@798
	float v188; // STA4_4@798
	float v189; // STA0_4@798
	float v190; // ST9C_4@798
	float v191; // ST30_4@799
	float v192; // ST94_4@799
	float v193; // ST90_4@799
	float v194; // ST8C_4@799
	float v227; // [sp+3BCh] [bp-1440h]@797

	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
	
	for(std::vector<SET_EFFECT_CUSTOM>::iterator it = gSeteffect.m_SetCEffect.begin();it != gSeteffect.m_SetCEffect.end();it++)
	{
		if ( a3 == it->ItemIndex)
		{
			int v759 = GetBoneTransform(a2, it->EffectValue);

			if ( v759 )
			{
				Vector(it->ColorR, it->ColorG, it->ColorB, Color);
				Vector( it->JoinY, it->JoinZ, it->JoinX, WorldPos);
				TransformPosition(a1, v759, WorldPos, Bone, 1);
				if (it->EffectIndex == 0)
				{
					CreateSprite(it->EffectCode, Bone, it->EffectSize, Color, a2, it->EffectSide, 0);
				}
				else if (it->EffectIndex == 1)
				{
					CreateParticle2(it->EffectCode, Bone, a2 + 264, Color, it->EffectType, it->EffectSize, 0);
				}
				else if(it->EffectIndex == 2)
				{
					CreateEffect(it->EffectCode, a2 + 252, a2 + 264, Color, 3, a2, -1, 0, 0, 0, 0.0, -1);//<<Efecto Skill
				}
			}
		}
	}
	
	RenderPartObjectBodyR(a1, a2, a3, a4, a5);
}

void cCSetEffect::Init()
{
	//--
	SetCompleteHook(0xE8, 0x0060D9C9,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DB79,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DBEA,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DC5B,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DD1D,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DD8E,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DDFF,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DE70,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DEBA,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060DF78,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E045,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E124,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E211,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E2E6,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E394,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E408,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E47C,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E516,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E5BC,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E662,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E745,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E828,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060E93C,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060EA50,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060EB63,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060EC77,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060ED50,&this->RenderPartObjectBody);
	SetCompleteHook(0xE8, 0x0060ED94,&this->RenderPartObjectBody);
}