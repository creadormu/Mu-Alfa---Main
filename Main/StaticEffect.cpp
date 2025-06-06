// CustomWingEffect.cpp: implementation of the CCustomWingEffect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Import.h"
#include "Object.h"
#include "StaticEffect.h"
#include "CustomWing.h"
#include "DynamicEffect.h"
#include "zzzmathlib.h"

CCustomWingEffect gCustomWingEffect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomWingEffect::CCustomWingEffect() // OK
{
	this->m_CustomWingEffectInfo.clear();
}

CCustomWingEffect::~CCustomWingEffect() // OK
{

}

void CCustomWingEffect::Load(CUSTOM_WING_EFFECT_INFO* info) // OK
{
	for(int n=0;n < MAX_DYNAMIC_WING_EFFECT;n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_DYNAMIC_WING_EFFECT)
		{
			return;
		}

		this->m_CustomWingEffectInfo.insert(std::pair<int,CUSTOM_WING_EFFECT_INFO>(info[n].Index,info[n]));
	}
}

BOOL CCustomWingEffect::SetWingEffect(int ItemIndex,DWORD a,DWORD b,DWORD c,DWORD d) // OK
{
	float ItemColor1[3];
	float ItemColor2[3];
	int active = 0;

	for(std::map<int, DYNAMIC_WING_EFFECT_INFO>::iterator it =  gDynamicWingEffect.m_DynamicWingEffectInfo.begin(); it !=  gDynamicWingEffect.m_DynamicWingEffectInfo.end(); it ++)
	{
		if(it->second.ItemIndex == ItemIndex)
		{
			ItemColor1[0] = it->second.ColorR;

			ItemColor1[1] = it->second.ColorG;

			ItemColor1[2] = it->second.ColorB;

			pAllowStaticEffect((void*)a,&b,c,it->second.EffectValue,it->second.EffectLevel);
			pPlayDynamicEffect(it->second.EffectIndex,&b,c,ItemColor1,it->second.Effect1,it->second.Effect,it->second.Effect2);
			active = 1;
		}
			
	}

	for(std::map<int, CUSTOM_WING_EFFECT_INFO>::iterator it2 =  this->m_CustomWingEffectInfo.begin(); it2 !=  this->m_CustomWingEffectInfo.end(); it2 ++)
	{
		if(it2->second.ItemIndex == ItemIndex)
		{
			ItemColor2[0] = it2->second.ColorR;

			ItemColor2[1] = it2->second.ColorG;

			ItemColor2[2] = it2->second.ColorB;

			pAllowStaticEffect((void*)a,&b,c,it2->second.EffectValue,it2->second.EffectLevel);
			pPlayStaticEffect(it2->second.EffectIndex,&b,it2->second.ColorSize,ItemColor2,d,it2->second.ColorMain,(DWORD)it2->second.ColorSide);
			active = 1;
		}
	}

	return active;
}