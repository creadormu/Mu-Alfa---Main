#define MAX_EFFECT_MONSTER 1500

enum TYPE_EFFECT
{
	JCEffect_Dinamic = 1,
	JCEffect_Static = 2,
	JCEffect_Skill = 3,
};

struct xMonsterEffect
{
	int IndexMonster;
	int TypeEffect;
	int IDEffect;
	int EfectValue;
	float Join[3];
	float Color[3];
	float Scale;
};

class jCEffectMonster
{
public:
	jCEffectMonster();
	virtual ~jCEffectMonster();
	void Load(xMonsterEffect* info);
public:
	std::vector<xMonsterEffect> m_MonsterEffect;
};

extern jCEffectMonster JCEffectMonster;