#pragma once

#define maximu_ceffect					3000
#define CreateEffect				((int(__cdecl*)(int a4, int a5, int a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)
#define CreateParticle2				((int(__cdecl*)(int a1, vec3_t Bone1, int a3, vec3_t color, int a5, float size, int a7)) 0x0074CD30)
#define TransformPosition			((int(__thiscall*)(int This, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x00545030)
#define CreateSprite				((int(__cdecl*)(int a1, vec3_t Bone1, float size, vec3_t color, int ObjPos, float, int)) 0x00771310)
#define BoneTransform			*(int*)0x7BC09C0
#define Draw_RenderObjectR			((void(__cdecl*)(int a1, int a2, int a3, int a4)) 0x005DE260)
#define Joint(x)					((0x30 * x) + 0x7BC08A0)

#define RenderPartObjectBodyR		((void(__cdecl*)(int a1, int a2, int a3, float a4, int a5)) 0x005FA710)

struct SET_EFFECT_CUSTOM
{
	int Index;
	int ItemIndex;
	int EffectIndex;
	int EffectCode;
	int EffectValue;
	float JoinX;
	float JoinY;
	float JoinZ;
	float ColorR;
	float ColorG;
	float ColorB;
	float EffectSize;
	int EffectType;
	float EffectSide;
};

class cCSetEffect
{
public:
	cCSetEffect();
	virtual ~cCSetEffect();
	void Init();
	void Load(SET_EFFECT_CUSTOM* info);
	void static RenderPartObjectBody(int a1, int Model, int ItemIndex, float a4, int a5); // OK
public:
	std::vector<SET_EFFECT_CUSTOM> m_SetCEffect;

}; extern cCSetEffect gSeteffect;