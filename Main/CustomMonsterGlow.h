#pragma once

#define MAX_CUSTOM_MONSTERGLOW 100

struct CUSTOM_MONSTERGLOW_INFO
{
	int Index;
	int MonsterID;
	int EffectIndex;
	int EffectType;
	float ColorR;
	float ColorG;
	float ColorB;
};

struct CUSTOM_GLOW_INFO
{
	int Index;
	int MonsterID;
	int Golden;
	int brightness;
};

class cCustomGlow
{
public:
	cCustomGlow();
	virtual ~cCustomGlow();
	void Init();
	void LoadGlow(CUSTOM_MONSTERGLOW_INFO* info);
	void LoadBrightness(CUSTOM_GLOW_INFO* info);
	bool CheckCustomByMonster(int MonsterID);
	int CheckCustomByMonsterGolden(int MonsterID);
	int CheckCustomByMonsterbrightness(int MonsterID);
public:
	std::vector<CUSTOM_MONSTERGLOW_INFO> m_CustomGlowInfo;
	std::vector<CUSTOM_GLOW_INFO> m_CustombrightnessInfo;
};

extern cCustomGlow gCustomMonsterGlow;