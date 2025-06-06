#define ModelID(x)					(x + 644)
#define MonsterID(x)				(x - 644)

#define sub_8CA230					((char(__cdecl*)(int a4, int a5)) 0x008CA230)
#define sub_56F210					((void(__cdecl*)(int a1, int a2, int a3)) 0x0056F210)
#define JointMonster(x)				((0x30 * x) + 0x7BC10B0)
#define pPlayStaticEffect1			((int(__cdecl*)(int ModelID, vec3_t Bone1, float size, vec3_t Color, int ObjPos, float, int)) 0x771310)
#define pCreateEffect2				((int(__cdecl*)(int a4, vec3_t Bone1, int a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)

#define pCreatEffectMonsterSkill	((char(__cdecl*)(int a4, int a5)) 0x009058F0)
#define sub_7293F0					((char*(__cdecl*)(int a1, int a2, int a3, int a4, int a5, char a6, int a7)) 0x7293F0)
#define sub_72D1B0					((void(__cdecl*)(int a1, vec3_t Bone, int a3, vec3_t color, int a5, int a6, float a7, __int16 a8, __int16 a9, char a10, int a11, int a12, __int16 a13)) 0x72D1B0)

#define sub_51A220					((int(__cdecl*)(int This, int a2)) 0x0051A220)
#define sub_542050					((__int16(__cdecl*)(int This, int a2)) 0x00542050)
#define sub_541CF0					((__int16(__cdecl*)(int This, int a2)) 0x00541CF0)
#define sub_4DB0C0					((double(__cdecl*)(float a1)) 0x004DB0C0)
//--
void RenderMonsterEffectMesh(int a1, int a2, int a3);
void InitloadGlow();