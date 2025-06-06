#include "stdafx.h"
#include "MonsterGlow.h"
#include "TMemory.h"
#include "Defines.h"
#include "import.h"
#include "Util.h"
#include "Object.h"
#include "CustomMonsterGlow.h"
#include "zzzmathlib.h"
#include "CustomMonster.h"
#include "MonsterEffect.h"

char RenderMonsterObjectMesh(int a1, int a2)
{
	LPVOID v397; // [sp+8E4h] [bp-4Ch]@2
	float v526; // [sp+870h] [bp-C0h]@125
	int v531; // [sp+884h] [bp-ACh]@125
	int v554; // [sp+8E4h] [bp-4Ch]@2
	int v5 = 0; // ST58_4@2
	char result; // al@2

	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;

	result = sub_8CA230(a1, a2);//008CA230

	if(gCustomMonsterGlow.CheckCustomByMonster(ModelID(*(DWORD *)(a1 + 48))) == true)
	{
		BeginRender(1.0);
		v5 = 1;
		for(int j = 0; j < 8; j++)
		{
			RenderMesh(a2, j, 2, *(float *)(a1 + 152), *(DWORD *)(a1 + 68), *(float *)(a1 + 100), *(float *)(a1 + 104), *(float *)(a1 + 108), -1);
		}
	}

	for(std::vector<CUSTOM_MONSTERGLOW_INFO>::iterator it = gCustomMonsterGlow.m_CustomGlowInfo.begin(); it != gCustomMonsterGlow.m_CustomGlowInfo.end(); it++)
	{
		if(ModelID(it->MonsterID) == *(DWORD *)(a1 + 48))
		{
			*(float *)(a2 + 72) = (float)(it->ColorR / 255.0f);
			*(float *)(a2 + 76) = (float)(it->ColorG / 255.0f);
			*(float *)(a2 + 80) = (float)(it->ColorB / 255.0f);
			*(float *)(a2 + 100) = (float)(it->ColorR / 255.0f);
			*(float *)(a2 + 104) = (float)(it->ColorG / 255.0f);
			*(float *)(a2 + 108) = (float)(it->ColorB / 255.0f);

			RenderMesh(a2, it->EffectIndex, it->EffectType, *(float *)(a1 + 152), *(float *)(a1 + 68), *(float *)(a1 + 100), *(float *)(a1 + 104), *(float *)(a1 + 108), -1);
			*(BYTE *)(a2 + 136) = -1;
		}
	}

	if(v5 != 0)
	{
		EndRender();
		result = 1;
	}

	return result;
}

void RenderMonsterEffectMesh(int a1, int a2, int a3)
{
	LPVOID v397; // [sp+8E4h] [bp-4Ch]@2
	float v526; // [sp+870h] [bp-C0h]@125
	int v531; // [sp+884h] [bp-ACh]@125
	int v554; // [sp+8E4h] [bp-4Ch]@2
	float v13; // STE4_4@60
	float v14; // STE0_4@60
	float v15; // STDC_4@60
	float v16; // STD8_4@60
	float v95; // [sp+1E0h] [bp-44h]@38

	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;

	v397 = pGetModel(pModelThis(), *(DWORD *)(a2 + 48));
	v554 = (int)v397;

	if ( v397 )
	{
		//-- HelMain
		/*if ( *(WORD *)(a1 + 132) == 904 )
		{
			v526 = *(float *)(a2 + 96) * 0.800000023841858;
			Vector((double)((signed int)pRenderRand() % 8) / 10.0 + 0.6000000238418579, 0.0, 0.0, Color);
			Vector( 0.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint
			//-- Effect Statico
			v531 = GetBoneTransform(a2, 25);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 0.30000001, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 50);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 0.30000001, Color, a2, 0.0, 0);
			}
			//--
			Vector((double)((signed int)pRenderRand() % 8) / 10.0 + 0.6000000238418579, 0.0, 0.0, Color);

			v531 = GetBoneTransform(a2, 25);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 1.0, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 50);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32003, Bone, 1.0, Color, a2, 0.0, 0);
			}
			Vector(-10.0, 0.0, 0.0, WorldPos);//<<Posicion a partir del Joint
			//-- Effect Dinamico
			v531 = GetBoneTransform(a2, 25);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				CreateParticle2(32283, Bone, a2 + 254, Color, 6, 2.0999999, 0);
			}
			Vector(15.0, 10.0, 0.0, WorldPos);//<<Posicion a partir del Joint
			v531 = GetBoneTransform(a2, 50);
			if ( v531 )
			{
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				CreateParticle2(32283, Bone, a2 + 254, Color, 6, 2.0999999, 0);
			}
		}*/
		//-- Kundun
		if ( *(WORD *)(a1 + 132) == 905 )
		{
			v531 = GetBoneTransform(a2, 8);
			if ( v531 )
			{
				Vector(1.0, 0.0, 0.0, Color);
				Vector( 0, 0, 0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32054, Bone, 0.40000001, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 9);
			if ( v531 )
			{
				Vector(1.0, 0.0, 0.0, Color);
				Vector( 0, 0, 0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(v554, v531, WorldPos, Bone, 1);
				pPlayStaticEffect1(32054, Bone, 0.40000001, Color, a2, 0.0, 0);
			}

			v531 = GetBoneTransform(a2, 100);

			if ( v531 )
			{
				Vector(1.0, 1.0, 1.0, Color);
				Vector( 0, 0, 0, WorldPos);
				TransformPosition(v554, v531, WorldPos, Bone, 1);

				v95 = 1.0f;
				
				if ( *(WORD *)(a2 + 18) == 5 )
				{
					if ( *(float *)(a2 + 140) <= 10.0 || (signed int)*(WORD *)(a2 + 44) <= 10 )
					{
						if ( *(float *)(a2 + 140) <= 4.0 )
							*(WORD *)(a2 + 44) = 10;
						else
							++*(WORD *)(a2 + 44);
					}
					else
					{
						--*(WORD *)(a2 + 44);
					}
					v95 = (double)*(WORD *)(a2 + 44) * 0.1500000059604645;

					if(*(float *)(a2 + 140) <= 4.0 || *(float *)(a2 + 140) >= 6.0 )
					{
						if ( *(float *)(a2 + 140) <= 8.0 || *(float *)(a2 + 140) >= 10.0 )
						{
							*(WORD *)(a2 + 26) = 0;
						}
						else
						{
							if ( *(float *)(a2 + 140) >= 9.0 )
							{
							if ( (signed int)*(WORD *)(a2 + 26) > 3 )
								*(WORD *)(a2 + 26) -= 3;
							}
							else
							{
							*(WORD *)(a2 + 26) += 3;
							}
							v95 = (double)*(WORD *)(a2 + 26) * 0.1500000059604645 + v95;
						}
					}
					else
					{
						if ( *(float *)(a2 + 140) >= 5.0 )
						{
							if ( (signed int)*(WORD *)(a2 + 26) > 3 )
							*(WORD *)(a2 + 26) -= 3;
						}
						else
						{
							*(WORD *)(a2 + 26) += 3;
						}
						v95 = (double)*(WORD *)(a2 + 26) * 0.1500000059604645 + v95;
					}
				}
				v13 = sinf(*(float*)0x5EF5A1C * 0.001000000047497451);
				v14 = v13 * 0.300000011920929 + 1.200000047683716;
				pPlayStaticEffect1(32229, Bone, v14, Color, a2, 0.0, 0);
				v15 = sinf(*(float*)0x5EF5A1C * 0.001000000047497451);
				v16 = (v15 * 0.300000011920929 + 1.200000047683716) * v95;
				pPlayStaticEffect1(32231, Bone, v16, Color, a2, 0.0, 0);
			}
		}
		else
		{
			for(std::vector<xMonsterEffect>::iterator it = JCEffectMonster.m_MonsterEffect.begin() ; it != JCEffectMonster.m_MonsterEffect.end(); it++)
			{
				if(it->IndexMonster == *(WORD *)(a1 + 132))
				{
					v531 = GetBoneTransform(a2, it->EfectValue);

					if ( v531 )
					{
						Vector(it->Color[0], it->Color[1], it->Color[2], Color);
						Vector(it->Join[1], it->Join[2], it->Join[0], WorldPos);//<<Posicion a partir del Joint
						
						if( it->TypeEffect == JCEffect_Dinamic )
						{
							TransformPosition(v554, v531, WorldPos, Bone, 1);
							CreateParticle2(it->IDEffect, Bone, a2 + 254, Color, 6, it->Scale, 0);
						}
						else if( it->TypeEffect == JCEffect_Static )
						{
							TransformPosition(v554, v531, WorldPos, Bone, 1);
							pPlayStaticEffect1(it->IDEffect, Bone, it->Scale, Color, a2, 0.0, 0);
						}
					}
				}
			}
		}
	}
}

void __declspec(naked) GoldenMonster()
{
	DWORD dwItem;
	static DWORD MonsterID;
	static DWORD Addr1_JMP = 0x005704EE;
	static DWORD Addr2_JMP = 0x0056FCF7;
	static int MonsterGolden;

	_asm
	{
		Mov edx, [EBP + 0x8]
		Movsx eax, word ptr[edx + 0x84]
		Mov MonsterID, eax
	}

	MonsterGolden = gCustomMonsterGlow.CheckCustomByMonsterGolden(MonsterID);

	if ( MonsterID == 38
		|| MonsterID == 43
		|| MonsterID == 44
		|| MonsterID == 52
		|| MonsterID == 59
		|| MonsterID == 67
		|| MonsterID >= 78 && MonsterID <= 83
		|| MonsterID >= 493 && MonsterID <= 502
		|| MonsterGolden != 0 ) 
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
}

void __declspec(naked) GoldenMonster2()
{
	static DWORD MonsterID;
	static DWORD Address1 = 0x005703A1;
	static DWORD Address2 = 0x0056FD73;
	static int MonsterGolden;

	_asm
	{
		Mov edx, [EBP + 0x8]
		Movsx eax, word ptr[edx + 0x84]
		Mov MonsterID, eax
	}

	MonsterGolden = gCustomMonsterGlow.CheckCustomByMonsterbrightness(MonsterID);

	if ( MonsterID == 43 || MonsterID == 44
		|| MonsterID >= 78 && MonsterID<=83
		|| MonsterID >= 493 && MonsterID <= 502
		|| MonsterGolden != 0 ) 
	{
		_asm
		{
			JMP Address2
		}
	}
	else
	{
		_asm
		{
			JMP Address1
		}
	}
}

char RenderEffectMonsterSkill(int Model, int a5)
{
	double v6; // ST50_8@22
	float v7; // ST44_4@65
	float v8; // ST68_4@65
	float v9; // ST40_4@70
	float v10; // ST3C_4@75
	float v11; // ST60_4@75
	float v12; // ST38_4@76
	float v13; // ST34_4@80
	float v14; // [sp+44h] [bp-50h]@80
	float v15; // [sp+4Ch] [bp-48h]@70
	int v16; // [sp+54h] [bp-40h]@22
	float v17; // [sp+58h] [bp-3Ch]@22
	float v18; // [sp+5Ch] [bp-38h]@22
	int i; // [sp+60h] [bp-34h]@20
	int v20; // [sp+64h] [bp-30h]@20
	int v21; // [sp+68h] [bp-2Ch]@20
	float v22; // [sp+6Ch] [bp-28h]@20
	float v23; // [sp+70h] [bp-24h]@20
	int v24; // [sp+74h] [bp-20h]@14
	int v25; // [sp+80h] [bp-14h]@12
	float v26; // [sp+84h] [bp-10h]@12
	float v27; // [sp+88h] [bp-Ch]@12
	float v28; // [sp+8Ch] [bp-8h]@12
	char v29; // [sp+93h] [bp-1h]@1
	float v50; // [sp+B4h] [bp-E8h]@68
	float v95;

	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;

	v29 = pCreatEffectMonsterSkill(Model, a5);

	if ( MonsterID(*(DWORD *)(Model + 48)) == 904 )
	{
		
			if(*(WORD *)(Model + 18) == 4 && *(float *)(Model + 140) >= 9.0 && *(float *)(Model + 140) <= 10.0)
			{
				Vector(1.0, 0.8499999761581421, 0.3499999940395355, Color);
				*(float*)0x8787D48 = (double)((signed int)pRenderRand() % 8 - 8) * 0.1000000014901161;
				v25 = GetBoneTransform(Model, 4);
				if ( v25 )
				{
					Vector( 0, 0, 0, WorldPos);//<<Posicion a partir del Joint
					TransformPosition(a5, v25, WorldPos, Bone, 1);
					pCreateEffect2(32089, Bone, Model + 264, Color, 1, 0, -1, 0, 0, 0, 0.0, -1);
				}
			}
			else if(*(WORD *)(Model + 18) == 3)
			{
				Vector(1.0, 0.8499999761581421, 0.3499999940395355, Color);
				*(float*)0x8787D48 = (double)((signed int)pRenderRand() % 8 - 8) * 0.1000000014901161;
				v25 = GetBoneTransform(Model, 4);
				if ( v25 )
				{
					//-- Efecto mil meteoritos
					Vector( 0.0, -153.0, -135.0, WorldPos);//<<Posicion a partir del Joint
					TransformPosition(a5, v25, WorldPos, Bone, 1);
					pCreateEffect2(347, Bone, Model + 264, Color, 5, Model, -130, 2, 0, 0, 0.0, -1);
				}
			}
			else if(*(WORD *)(Model + 18) == 6)
			{
				Vector(1.0, 0.8499999761581421, 0.3499999940395355, Color);
				*(float*)0x8787D48 = (double)((signed int)pRenderRand() % 8 - 8) * 0.1000000014901161;
				v25 = GetBoneTransform(Model, 4);
				if ( v25 )
				{
					//-- Burbujas
					Vector( -53.0, -24.5, -4.5, WorldPos);//<<Posicion a partir del Joint
					TransformPosition(a5, v25, WorldPos, Bone, 1);
					pCreateEffect2(340, Bone, Model + 264, Color, 3, Model, -130, 2, 0, 0, 0.0, -1);
				}
			}
		if ( *(WORD *)(Model + 18) != 2 && *(WORD *)(Model + 18) != 10 )
		{
			switch ( *(WORD *)(Model + 18) )
			{
				case 3:
					*(DWORD *)(Model + 52) = 1;
					PlayBuffer(607, 0, 0);
					break;
				case 4:
					*(DWORD *)(Model + 52) = 1;
					PlayBuffer(606, 0, 0);
					break;
				case 8:
					*(DWORD *)(Model + 52) = 1;
					PlayBuffer(605, 0, 0);
					break;
				default:
					if ( *(WORD *)(Model + 18) == 6)
					{
						*(DWORD *)(Model + 52) = 1;
						PlayBuffer(608, 0, 0);
					}
					break;
			}
		}
		else if ( !((signed int)pRenderRand() % 15) )
		{
			v17 = (signed int)pRenderRand() % 2;
			PlayBuffer(v17 + 603, 0, 0);
		}
	}
	//-- kundun
	if ( MonsterID(*(DWORD *)(Model + 48)) == 905 )
	{
		if ( *(WORD *)(Model + 18) != 6 )
		{
			if ( *(DWORD *)(Model + 64) >= 90 )
			{
				*(float *)(Model + 152) = 1.0;
				pCustomEffGet2(
					a5,
					2,
					*(float *)(Model + 152),
					*(DWORD *)(Model + 68),
					*(float *)(Model + 100),
					*(float *)(Model + 104),
					*(float *)(Model + 108),
					*(DWORD *)(Model + 60),
					-1);
				*(float *)(a5 + 72) = 0.40000001;
				*(float *)(a5 + 76) = 0.40000001;
				*(float *)(a5 + 80) = 0.30000001;
				RenderMesh(
					a5,
					1,
					68,
					*(float *)(Model + 152),
					*(DWORD *)(Model + 68),
					*(float *)(Model + 100),
					*(float *)(Model + 104),
					*(float *)(Model + 108),
					*(DWORD *)(Model + 60));
				RenderMesh(
					a5,
					2,
					68,
					*(float *)(Model + 152),
					*(DWORD *)(Model + 68),
					*(float *)(Model + 100),
					*(float *)(Model + 104),
					*(float *)(Model + 108),
					*(DWORD *)(Model + 60));
				RenderMesh(
					a5,
					3,
					68,
					*(float *)(Model + 152),
					*(DWORD *)(Model + 68),
					*(float *)(Model + 100),
					*(float *)(Model + 104),
					*(float *)(Model + 108),
					*(DWORD *)(Model + 60));
				RenderMesh(
					a5,
					4,
					68,
					*(float *)(Model + 152),
					*(DWORD *)(Model + 68),
					*(float *)(Model + 100),
					*(float *)(Model + 104),
					*(float *)(Model + 108),
					*(DWORD *)(Model + 60));
				RenderMesh(
					a5,
					5,
					68,
					*(float *)(Model + 152),
					*(DWORD *)(Model + 68),
					*(float *)(Model + 100),
					*(float *)(Model + 104),
					*(float *)(Model + 108),
					*(DWORD *)(Model + 60));
				RenderMesh(
					a5,
					6,
					68,
					*(float *)(Model + 152),
					*(DWORD *)(Model + 68),
					*(float *)(Model + 100),
					*(float *)(Model + 104),
					*(float *)(Model + 108),
					*(DWORD *)(Model + 60));

				if ( *(WORD  *)(Model + 18) == 5 )
				{
					RenderMesh(
						a5,
						1,
						66,
						*(float *)(Model + 152),
						*(DWORD *)(Model + 68),
						*(float *)(Model + 100),
						*(float *)(Model + 104),
						*(float *)(Model + 108),
						*(DWORD *)(Model + 60));
					RenderMesh(
						a5,
						2,
						66,
						*(float *)(Model + 152),
						*(DWORD *)(Model + 68),
						*(float *)(Model + 100),
						*(float *)(Model + 104),
						*(float *)(Model + 108),
						*(DWORD *)(Model + 60));
					RenderMesh(
						a5,
						3,
						66,
						*(float *)(Model + 152),
						*(DWORD *)(Model + 68),
						*(float *)(Model + 100),
						*(float *)(Model + 104),
						*(float *)(Model + 108),
						*(DWORD *)(Model + 60));
					RenderMesh(
						a5,
						5,
						66,
						*(float *)(Model + 152),
						*(DWORD *)(Model + 68),
						*(float *)(Model + 100),
						*(float *)(Model + 104),
						*(float *)(Model + 108),
						*(DWORD *)(Model + 60));
				}
			}
			//------------------------------------
			if ( *(WORD *)(Model + 18) == 3 )
			{
				if ( *(float *)(Model + 140) < 2.0 )
					*(DWORD *)(Model + 64) = 100;
				if ( *(DWORD *)(Model + 64) == 100 && *(float *)(Model + 140) > 3.0 )
				{
					*(DWORD *)(Model + 64) = 101;
					v25 = GetBoneTransform(Model, 49);
					if ( v25 )
					{
						Vector(1.0, 1.0, 1.0, Color);
						Vector( 0, 0, 0, WorldPos);
						TransformPosition(a5, v25, WorldPos, Bone, 1);
						pCreateEffect2(347, Bone, Model + 264, Color, 0, 0, -1, 0, 0, 0, 0.0, -1);
					}
				}
			}
			//--
			if ( *(WORD *)(Model + 18) == 4 )
			{
				if ( *(float *)(Model + 140) < 2.0 )
					*(DWORD *)(Model + 64) = 100;
				if ( *(DWORD *)(Model + 64) == 100 && *(float *)(Model + 140) > 5.0 )
				{
					*(DWORD *)(Model + 64) = 101;
					v25 = GetBoneTransform(Model, 49);
					if ( v25 )
					{
						Vector(1.0, 1.0, 1.0, Color);
						Vector( 0, 0, 0, WorldPos);
						TransformPosition(a5, v25, WorldPos, Bone, 1);
						pCreateEffect2(347, Bone, Model + 264, Color, 1, 0, -1, 0, 0, 0, 0.0, -1);
					}
				}
			}
			if ( *(DWORD *)(Model + 64) == 101 && *(float *)(Model + 140) > 6.0 )
			{
				*(DWORD *)(Model + 64) = 102;

				v25 = GetBoneTransform(Model, 49);
				if ( v25 )
				{
					Vector(1.0, 1.0, 1.0, Color);
					Vector( 0, 0, 0, WorldPos);
					TransformPosition(a5, v25, WorldPos, Bone, 1);
					for (int j = 0; j < 24; ++j )
					{
						sub_72D1B0(32285, Bone, Model + 264, Color, 14, 0, 100.0, 0, 0, 0, -1, 0, -1);
					}
				}
			}
		}
		else
		{
			if ( *(DWORD *)(Model + 64) != 10 )
				PlayBuffer(477, 0, 0);
			*(DWORD *)(Model + 64) = 10;

			RenderMesh(
			a5,
			0,
			2,
			*(float *)(Model + 152),
			*(DWORD *)(Model + 68),
			*(float *)(Model + 100),
			*(float *)(Model + 104),
			*(float *)(Model + 108),
			*(DWORD *)(Model + 60));

			Vector(1.0, 0.8499999761581421, 0.3499999940395355, Color);
			
			*(float*)0x8787D48 = (double)((signed int)pRenderRand() % 8 - 8) * 0.1000000014901161;

			v25 = GetBoneTransform(Model, 4);

			if ( v25 )
			{
				Vector( -0.5, -7.5, 39.0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(343, Bone, Model + 264, Color, 3, Model, -130, 3, 0, 0, 0.0, -1);
				//--
				Vector( 32.5, -7.5, 24.0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(336, Bone, Model + 264, Color, 3, Model, -130, 4, 0, 0, 0.0, -1);
				//--
				Vector( -32.5, -8.5, 24.0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(337, Bone, Model + 264, Color, 3, Model, -130, 5, 0, 0, 0.0, -1);
				//--
				Vector( 0.5, 4.0, -0.5, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(338, Bone, Model + 264, Color, 2, Model, -130, 6, 0, 0, 0.0, -1);
				//-- Agua Simulada
				Vector( 54.0, -22.0, -2.5, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(339, Bone, Model + 264, Color, 3, Model, -130, 1, 0, 0, 0.0, -1);
				//-- Burbujas
				Vector( -53.0, -24.5, -4.5, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(340, Bone, Model + 264, Color, 3, Model, -130, 2, 0, 0, 0.0, -1);
				//-- Fantasmas Negros
				Vector( 0.0, -153.0, -136.0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(341, Bone, Model + 264, Color, 4, Model, -10, 2, 0, 0, 0.0, -1);
				//-- Efecto mil meteoritos
				Vector( 0.0, -153.0, -135.0, WorldPos);//<<Posicion a partir del Joint
				TransformPosition(a5, v25, WorldPos, Bone, 1);
				pCreateEffect2(347, Bone, Model + 264, Color, 5, Model, -130, 2, 0, 0, 0.0, -1);
				pCreateEffect2(347, Bone, Model + 264, Color, 2, 0, -1, 0, 0, 0, 0.0, -1);
			}
		}
		v29 = 1;
	}
	return v29;
}

void InitloadGlow()
{
	//--
	SetCompleteHook(0xE8, 0x00900DE9, &RenderEffectMonsterSkill);
	//--
	/*SetCompleteHook(0xE8, 0x0040487D, &RenderMonsterEffectMesh);
	SetCompleteHook(0xE8, 0x0048E56C, &RenderMonsterEffectMesh);
	SetCompleteHook(0xE8, 0x0057D4FF, &RenderMonsterEffectMesh);
	SetCompleteHook(0xE8, 0x0057D513, &RenderMonsterEffectMesh);*/
	//--
	SetCompleteHook(0xE8, 0x008C5BB5,&RenderMonsterObjectMesh);
	//--
	SetRange((PVOID)0x0056FC5E, 10, ASM::NOP);
	SetOp((PVOID)0x0056FC5E, (LPVOID)GoldenMonster, ASM::JMP); // enable golden monster 7
	//--
	SetRange((PVOID)0x0056FD1A, 10, ASM::NOP);
	SetOp((PVOID)0x0056FD1A, (LPVOID)GoldenMonster2, ASM::JMP); // more bright 9
}