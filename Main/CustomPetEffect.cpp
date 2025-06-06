#include "StdAfx.h"
#include "CustomPetEffect.h"
#include "Import.h"
#include "zzzmathlib.h"
#include "Defines.h"
#include "Util.h"
#include "cCPetRenderMesh.h"
#include "MonsterGlow.h"
#include "CustomPet.h"

cCEffectPet gCustomCEffectPet;

cCEffectPet::cCEffectPet()
{
	this->m_PetCEffect.clear();
}
cCEffectPet::~cCEffectPet()
{
}

void cCEffectPet::Load(PET_EFFECT_CUSTOM * info)
{
	for( int n = 0; n < max_ceffect; n++)
	{
		if(info[n].Index < 0 || info[n].Index >= max_ceffect)
		{
			return;
		}
		this->m_PetCEffect.push_back(info[n]);
	}
}

void cCEffectPet::addEffect(int a1, int a2, int a3, int a4) // OK
{
	Draw_RenderObjectR(a1, a2, a3, a4);
	int v42; // eax@182
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
	//
	int ModelE;
	LPVOID v397 = pGetModel(pModelThis(), *(DWORD *)(a1 + 48));
	ModelE = (int)v397;

	if ( !v397 )
	{
		return;
	}

	if ( !0x81C03BC && (0x81C03BC || *(DWORD *)(a1 + 60) == -2) )
	{
		return;
	}

	if ( v397 )
	{
		if ( gCustomPet2.CheckCustomPetByItem(*(DWORD *)(a1 + 48) - 1171) )
		{
			//-- Sombra
			if ( pMapNumber != 10 && !pCheckMap(pMapNumber) )
			{
				v42 = sub_4DB250();
				if ( !sub_4E44A0(v42 + 132) )
				{
					EnableAlphaTest( 1 );
					if ( pMapNumber == 7 )
						glColor4f(0.0, 0.0, 0.0, 0.2);
					else
						glColor4f(0.0, 0.0, 0.0, 0.69558);
					//sub_54A270(v401, *(_DWORD *)(a1 + 68), v399, -1, -1);
					ShadowMaster(ModelE, -1, 5, -1, -1);
					pGLSwitch();
					EnableAlphaTest(0);
				}
			}
			/*if( pViewAttackTargetID != -1 )
			{
				if( *(WORD *)(a1 + 18) == 1 )
				{
					Vector(1.0, 1.0, 1.0, Color);//<<Color
					Vector( 0.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint

					TransformPosition((int)v397, Joint( 1 ), WorldPos, Bone, 0);

					if ( *(float *)(a1 + 140) < 2.0 )
						*(DWORD *)(a1 + 64) = 100;
					if ( *(DWORD *)(a1 + 64) == 100 && *(float *)(a1 + 140) > 5.0 )
					{
						*(DWORD *)(a1 + 64) = 101;
						Vector(1.0, 1.0, 1.0, Color);
						Vector( 0, 0, 0, WorldPos);
						pCreateEffect2(347, Bone, a1 + 264, Color, 1, 0, -1, 0, 0, 0, 0.0, -1);
					}

					//	sub_6D8980(32226, a1, 0);
					//CreateEffect(297,(int) Bone, a1 + 264, Color, 0, a1, -1, 0, 0, 0, 0.0, -1);

					//sub_6D6C20(133, a1, 0);

					//sub_4C8AB0(a1 + 484, 58);
				}
			}*/
		}

		for(std::vector<PET_EFFECT_CUSTOM>::iterator it = gCustomCEffectPet.m_PetCEffect.begin();it != gCustomCEffectPet.m_PetCEffect.end();it++)
		{
			if(it->ItemIndex == (*(DWORD *)(a1 + 48) - 1171))
			{
				Vector(
					it->ColorR,
					it->ColorG,
					it->ColorB,
					Color);//<<Color
				Vector( 0.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint

				TransformPosition((int)v397, Joint(it->Join), WorldPos, Bone, 0);

				int v25 = timeGetTime() % 0x50;

				if(it->TypeEffect == 1)
				{
					CreateParticle2(it->EffectCode,
					Bone, a1 + 264, Color, 0.0,
					it->EffectSize, 1);//<<Dinamico
				}
				else if(it->TypeEffect == 2)
				{
					CreateSprite(it->EffectCode,
					Bone, it->EffectSize,
					Color, a1, 0.0, 0);//<<Estatico
				}
				else if(it->TypeEffect == 3)
				{
					if ( v25 >= 0 && v25 < it->LargeRand )//<<Cantidad de particulas en Efecto Skill
					{
						CreateEffect(it->EffectCode,(int) Bone, a1 + 264, Color, 3, a1, -1, 0, 0, 0, 0.0, -1);//<<Efecto Skill
					}
				}
			}
		}

		for(std::vector<RENDER_MESH>::iterator it = cRender.m_RenderMeshPet.begin();it != cRender.m_RenderMeshPet.end();it++)
		{
			if(it->ItemIndex== (*(DWORD *)(a1 + 48) - 1171))
			{
				//glColor3fv((GLfloat*)(ModelE+72));

				*(float *)(ModelE + 72) = (float)(it->ColorR / 255.0f);
				*(float *)(ModelE + 76) = (float)(it->ColorG / 255.0f);
				*(float *)(ModelE + 80) = (float)(it->ColorB / 255.0f);
				*(float *)(ModelE + 100) = (float)(it->ColorR / 255.0f);
				*(float *)(ModelE + 104) = (float)(it->ColorG / 255.0f);
				*(float *)(ModelE + 108) = (float)(it->ColorB / 255.0f);
				//*(DWORD *)(a1 + 60) = -2;

				RenderMesh(ModelE,
					it->EffectIndex,
					it->EffectType,
					*(float *)(a1 + 152),
					*(float *)(a1 + 68),
					*(float *)(a1 + 100),
					*(float *)(a1 + 104),
					*(float *)(a1 + 108),
					-1);
			}
		}
	}
}

void cCEffectPet::Init() // OK
{
	//--
	SetCompleteHook(0xE8, 0x0056F476, &this->addEffect);
	SetCompleteHook(0xE8, 0x005EBBE6, &this->addEffect);
}