#pragma pack(push, 1)
#define pQuickPlayStaticEffect	((int(__cdecl*)(LPVOID Model, int ModelID, int Joint, float size, vec3_t Color, int ObjModel)) 0x565560)
#define pAllowPlayEffect	((void(__thiscall*)(LPVOID This, vec3_t Bone1, int lpModel, signed int joint, int a5)) 0x544E60)
#define pPlayStaticEffect		((int(__cdecl*)(int ModelID, vec3_t Bone1, float size, vec3_t Color, int ObjPos, float, int)) 0x771310)
#define pPlayDynamicEffect		((int(__cdecl*)(int ModelID, vec3_t VecPos, vec3_t WorlPos, vec3_t color, int effectID, float size, int)) 0x74CD30)
#define pSetItemEffect	((void(__cdecl*)(int lpModel, int ItemID, vec3_t Light, float Alpha, int ItemLevel, int NewOption, int a10, int a11, int RenderType)) 0x00609E70)



#define EqualItemModelType		((int(__thiscall*)(int *This, signed int a2)) 0x0050E750)
#define pClawEffect ((void(__cdecl*)(int a1)) 0x00610590)

#define RenderLinkObject		((void(__cdecl*)(float a1, float a2, float a3, int a4, int a5, int a6, int a7, int a8, char a9, char a10, int a11, char a12)) 0x005655C0)


struct DYNAMIC_EFFECT_INFO //(size: 132)
{
/*+0*/ bool Enable; //int
BYTE gap1[3];
/*+4*/ DWORD EffectID;
/*+8*/ DWORD TextureID;
/*+12*/ int SubEffectID;
/*+16*/ float Scale;
/*+20*/ VAngle VecPos;
/*+32*/ VAngle WorldPos;
/*+44*/ VAngle Color;
/*+56*/ float Unknown56; //Alpha
/*+60*/ DWORD Unknown60;
/*+64*/ ObjectModel * m_Owner;
/*+68*/ float Unknown68; //
/*+72*/ DWORD Unknown72;
/*+76*/ BYTE Unknown76; //int
BYTE Gap01[3];
/*+80*/ float Unknown80;
/*+84*/ VAngle Unknown84;
/*+96*/ VAngle Color2;
/*+108*/ VAngle VecPos2;
BYTE Gap02[12];
};

class cCreateEffect
{
public:
	void Load();
	int DynamicEffectEx(DWORD ModelID, vec3_t VecPos, vec3_t WorldPos, vec3_t Color, int SubEffectID, float Scale, ObjectModel* lpModel);
};
extern cCreateEffect gCreateEffect;