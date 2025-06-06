#include "stdafx.h"
#include "CustomMonsterGlow.h"

cCustomGlow gCustomMonsterGlow;


cCustomGlow::cCustomGlow() // OK
{
	this->Init();
}

cCustomGlow::~cCustomGlow() // OK
{

}

void cCustomGlow::Init() // OK
{
	this->m_CustomGlowInfo.clear();
	this->m_CustombrightnessInfo.clear();
}

void cCustomGlow::LoadGlow(CUSTOM_MONSTERGLOW_INFO* info) // OK
{
	for (int n = 0; n < MAX_CUSTOM_MONSTERGLOW; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= MAX_CUSTOM_MONSTERGLOW)
		{
			return;
		}

		this->m_CustomGlowInfo.push_back(info[n]);
	}
}

void cCustomGlow::LoadBrightness(CUSTOM_GLOW_INFO* info) // OK
{
	for (int n = 0; n < MAX_CUSTOM_MONSTERGLOW; n++)
	{
		if (info[n].Index < 0 || info[n].Index >= MAX_CUSTOM_MONSTERGLOW)
		{
			return;
		}

		this->m_CustombrightnessInfo.push_back(info[n]);
	}
}

bool cCustomGlow::CheckCustomByMonster(int MonsterID) // OK
{
	for(std::vector<CUSTOM_MONSTERGLOW_INFO>::iterator it = this->m_CustomGlowInfo.begin(); it != this->m_CustomGlowInfo.end(); it++)
	{
		if(it->MonsterID == MonsterID)
		{
			return true;
		}
	}
	return false;
}

int cCustomGlow::CheckCustomByMonsterGolden(int MonsterID) // OK
{
	for(std::vector<CUSTOM_GLOW_INFO>::iterator it = this->m_CustombrightnessInfo.begin(); it != this->m_CustombrightnessInfo.end(); it++)
	{
		if(it->MonsterID == MonsterID && it->Golden == 1)
		{
			return 1;
		}
	}
	return 0;
}

int cCustomGlow::CheckCustomByMonsterbrightness(int MonsterID) // OK
{
	for(std::vector<CUSTOM_GLOW_INFO>::iterator it = this->m_CustombrightnessInfo.begin(); it != this->m_CustombrightnessInfo.end(); it++)
	{
		if(it->MonsterID == MonsterID && ( it->Golden == 1 || it->brightness == 1 ))
		{
			return 1;
		}
	}
	return 0;
}