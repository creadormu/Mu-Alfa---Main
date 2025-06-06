#include "stdafx.h"
#include "MonsterEffect.h"

jCEffectMonster JCEffectMonster;

jCEffectMonster::jCEffectMonster()
{
	this->m_MonsterEffect.clear();
}

jCEffectMonster::~jCEffectMonster()
{

}

void jCEffectMonster::Load(xMonsterEffect* info)
{
	for ( int k = 0; k < MAX_EFFECT_MONSTER ; ++k )
	{
		if ( info[k].IndexMonster < 0 )
		{
			return;
		}
		this->m_MonsterEffect.push_back(info[k]);
	}
}