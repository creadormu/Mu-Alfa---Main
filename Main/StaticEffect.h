// CustomWingEffect.h: interface for the CCustomWingEffect class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

struct CUSTOM_WING_EFFECT_INFO
{
	int Index;
	int ItemIndex;
	int EffectIndex;
	int EffectValue;
	int EffectLevel;
	float ColorR;
	float ColorG;
	float ColorB;
	float ColorSize;
	float ColorMain;
	float ColorSide;
};

class CCustomWingEffect
{
public:
	CCustomWingEffect();

	virtual ~CCustomWingEffect();
	void Load(CUSTOM_WING_EFFECT_INFO* info);
	BOOL SetWingEffect(int ItemIndex,DWORD a,DWORD b,DWORD c,DWORD d);
	static void SetWingEffectStart(float a4, float a5, float a6, lpViewObj Object, float a8, DWORD ModelID, int a10, char a11, char a12, char a13, signed int a14, char a15); // OK

public:
	std::map<int,CUSTOM_WING_EFFECT_INFO> m_CustomWingEffectInfo;
};

extern CCustomWingEffect gCustomWingEffect;
