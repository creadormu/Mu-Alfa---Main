#include "stdafx.h"
#include "MultiSelect.h"
#include "Import.h"
#include "Util.h"
#include "TMemory.h"
#include "Defines.h"
#include "Pet.h"
#include "CustomPet.h"
#include "Protect.h"

MultiSelect gSelectCharRamdon;

void MultiSelect::LoadMultiChar(SelectChar * info)
{
	for(int n = 0 ; n < MAX_WORLD_SETTINGS; n ++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_WORLD_SETTINGS)
		{
			return;
		}
		gSelectCharRamdon.RenderSelect = info[n];
	}
}

void CameraChar(int a1, DWORD *a2)
{
	if ( pPlayerState == 4) //Select Character
	{
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38f);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38f);
		*(float*)0xE61E3C = 20000.0f;
		//--
		*(float*)0x87933D0 = gSelectCharRamdon.RenderSelect.flt_87933D0;
		*(float*)0x87933D4 = gSelectCharRamdon.RenderSelect.flt_87933D4;
		*(float*)0x87933D8 = gSelectCharRamdon.RenderSelect.flt_87933D8;
		*(float*)0x87933DC = gSelectCharRamdon.RenderSelect.flt_87933DC;
		*(float*)0x87933E0 = gSelectCharRamdon.RenderSelect.flt_87933E0;
		*(float*)0x87933E4 = gSelectCharRamdon.RenderSelect.flt_87933E4;
		//--
		*(float*)0xE61E40 = 35.0f;
	}
}

int __cdecl RenderModelScale(int a1)
{
	int result; // eax@1
	float RenderSize; // eax@2
	float RenderMonk; // eax@3

	result = a1;

	if ( !*(BYTE *)(a1 + 15) )
	{
		if ( *(WORD *)(a1 + 268) != 4755
			&& *(WORD *)(a1 + 268) != 4757
			&& *(WORD *)(a1 + 268) != 4818
			&& *(WORD *)(a1 + 268) != 4823
			&& *(WORD *)(a1 + 268) != 4820
			&& *(WORD *)(a1 + 268) != 4825
			&& ((signed int)*(WORD *)(a1 + 268) < 4765 || (signed int)*(WORD *)(a1 + 268) > 4768) )
		{
			*(WORD *)(a1 + 232) = -1;
		}
		else
		{
			*(WORD *)(a1 + 232) = (unsigned __int8) sub_587500(*(BYTE *)(a1 + 19)) + 9389;
		}
		if ( pPlayerState == 4 )
		{
			RenderSize = ( gSelectCharRamdon.RenderSelect.ModelScale > 0 ) ? ((double)(( 1.2f / 100 ) * gSelectCharRamdon.RenderSelect.ModelScale)) : 1.2f;
			RenderMonk = ( gSelectCharRamdon.RenderSelect.ModelScale > 0 ) ? ((double)(( 1.35f / 100 ) * gSelectCharRamdon.RenderSelect.ModelScale)) : 1.35f;

			if ( *(BYTE *)(a1 + 20) )
			{
				result = sub_405230(*(BYTE *)(a1 + 19));
				switch ( result )
				{
					case CLASS_WIZARD:
						result = a1;
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_KNIGHT:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_ELF:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_MAGUMSA:
						result = a1;
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_DARKLORD:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_SUMMONER:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_MONK:
						result = a1;
						*(float *)(a1 + 872) = RenderMonk;
					break;
					default:
					return result;
				}
			}
			else
			{
				result = sub_405230(*(BYTE *)(a1 + 19));
				switch ( result )
				{
					case CLASS_WIZARD:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_KNIGHT:
						result = a1;
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_ELF:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_MAGUMSA:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_DARKLORD:
						result = a1;
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_SUMMONER:
						*(float *)(a1 + 872) = RenderSize;
					break;
					case CLASS_MONK:
						*(float *)(a1 + 872) = RenderMonk;
					break;
					default:
					return result;
				}
			}
		}
		else if ( *(BYTE *)(a1 + 20) )
		{
			result = sub_405230(*(BYTE *)(a1 + 19));
			switch ( result )
			{
				case 0:
					*(float *)(a1 + 872) = 0.93000001;
					break;
				case 1:
					*(float *)(a1 + 872) = 0.93000001;
					break;
				case 2:
					result = a1;
					*(float *)(a1 + 872) = 0.86000001;
					break;
				case 3:
					*(float *)(a1 + 872) = 0.94999999;
					break;
				case 4:
					*(float *)(a1 + 872) = 0.92000002;
					break;
				case 5:
					result = a1;
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 6:
					*(float *)(a1 + 872) = 1.03;
					break;
				default:
					return result;
			}
		}
		else
		{
			result = sub_405230(*(BYTE *)(a1 + 19));
			switch ( result )
			{
				case 0:
					result = a1;
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 1:
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 2:
					*(float *)(a1 + 872) = 0.88;
					break;
				case 3:
					result = a1;
					*(float *)(a1 + 872) = 0.94999999;
					break;
				case 4:
					*(float *)(a1 + 872) = 0.92000002;
					break;
				case 5:
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 6:
					result = a1;
					*(float *)(a1 + 872) = 1.03;
					break;
				default:
					return result;
			}
		}
	}
	return result;
}

char RenderPetScale(int a4, char a5)
{
	float RenderSize;

	if(*(BYTE*)(a4 + 4))
	{
		char v8 = 0;

		if(a5)
		{
			v8 = 1;
		}
		else
		{
			float v5 = *(float*)(a4 + 256) * 0.009999999776482582;
			float v6 = *(float*)(a4 + 252) * 0.009999999776482582;
			v8 = sub_5DBA10(v6, v5, -20.0);
		}

		*(BYTE*)(a4 + 12) = v8;

		if(*(BYTE*)(a4 + 12))
		{
			DWORD dwItemNumber = *(DWORD*)(a4 + 48);

			if(*(DWORD *)(*(DWORD*)(a4 + 472) + 48) != 1163 && *(DWORD*)(a4 + 48) != 7827)
			{
				return 1;
			}

			if(a5)
			{
				*(float*)(a4 + 96) = *(float*)(a4 + 96);
			}
			else if(pPlayerState == 4)
			{
				#if UPDATE >= 15
				RenderSize = (gSelectCharRamdon.RenderSelect.ModelScale > 0)?(double)((1.2f / 100) * gSelectCharRamdon.RenderSelect.ModelScale):1.2f;
				*(float*)(a4 + 96) = RenderSize;
				#else
				*(float*)(a4 + 96) = 1.2f;
				#endif
			}
			else if(dwItemNumber != 384 && dwItemNumber != 386 && dwItemNumber != 385 && dwItemNumber != 387)
			{
				*(float*)(a4 + 96) = 1.0;
			}	

			if(gCustomPet2.CheckCustomPetByItem(dwItemNumber - 1171))
			{
				if(pPlayerState != 4)
				{
					*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171);
				}
				else
				{
					#if UPDATE >= 15
					RenderSize = (gSelectCharRamdon.RenderSelect.ModelScale > 0)?(double)(((gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.3) / 100) * gSelectCharRamdon.RenderSelect.ModelScale):gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.3;
					*(float*)(a4 + 96) = RenderSize;
					#else
					*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.3;
					#endif
					
				}
			}

			int v9 = 0;

			if(pCheckEffectPlayer((LPVOID)(*(DWORD*)(a4 + 472) + 484), 18))
			{
				v9 = 10;
			}
			
			pObjectMaxBug(a4, 0, 0, v9);
	
			float v10 = (double)((signed int)sub_9CFB8D() % 30 + 70) * 0.009999999776482582;

			if( dwItemNumber == 7827 )
			{
				float Color[3];

				Color[0] = v10 * 0.5;
				Color[1] = v10 * 0.800000011920929;
				Color[2] = v10 * 0.6000000238418579;

				pPlayStaticEffect(32002, (DWORD*)(a4 + 252), 1.0, Color, a4, 0.0, 0);
			}
		}
	}
	return 1;
}
//----- (0063D130)
DWORD SelectCharacterCord(int a4)
{
	int v4; // ST1C_4@11
	char v5; // ST14_1@12
	void *v6; // eax@12
	int v7; // eax@12
	DWORD result; // eax@12
	int v9; // [sp+14h] [bp-20h]@5
	int v10; // [sp+18h] [bp-1Ch]@5
	float v11; // [sp+1Ch] [bp-18h]@5
	float v12; // [sp+20h] [bp-14h]@0
	float v13; // [sp+24h] [bp-10h]@0
	signed int i; // [sp+28h] [bp-Ch]@3
	signed int v15; // [sp+30h] [bp-4h]@3

	sub_63CB40();
	sub_4D5130(*(BYTE *)(a4 + 4));

	if ( pPlayerState == 4 )
		World = gSelectCharRamdon.RenderSelect.MapChar;
	v15 = 8;

	for ( i = 0; i < *(BYTE *)(a4 + 6); ++i )
	{
		v9 = v15 + a4;
		v10 = (unsigned __int8)sub_587380(*(BYTE *)(v15 + a4 + 15));
		v11 = 0.0;

		switch ( *(BYTE *)(v15 + a4) )
		{
			case 0:
				v12 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX;// 8008.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY;// 18885.0;
				v11 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate;// 115.0;
			break;
			case 1:
				v12 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX;// 7986.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY;// 19145.0;
				v11 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate;// 90.0;
			break;
			case 2:
				v12 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX;// 8046.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY;// 19400.0;
				v11 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate;// 75.0;
			break;
			case 3:
				v12 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX;// 8133.000;
				v13 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY;// 19645.0;
				v11 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate;// 60.0;
			break;
			case 4:
				v12 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX;// 8282.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY;// 19845.0;
				v11 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate;// 35.0;
			break;
			default:
			break;
		}
		//gInfoLog.Output(LOG_CHAT,"[%d] [%d]",v9,v10);
		v4 = sub_586DA0(*(BYTE *)v9, v10, 0, v12, v13, v11);//-- Agrega Personaje con Coordenada

		*(WORD *)(v4 + 130) = *(WORD *)(v9 + 12);

		*(BYTE *)(v4 + 21) = *(BYTE *)(v9 + 14);

		sub_9CF1C0((char *)(v4 + 56), (const void *)(v9 + 1), 0xAu);

		*(BYTE *)(v4 + 66) = 0;

		gCustomPet.PreviewCharSet(*(BYTE *)v9, (BYTE *)( v9 + 16), 0, 0);//-- Mostrar Equipamiento

		*(BYTE *)(v4 + 24) = *(BYTE *)(v9 + 33);

		v15 += 34;
	}

	*(DWORD*)0x87935A4 = 51;

	pWarehouseExSet(pWarehouseExThis(pWindowThis()), *(BYTE *)(a4 + 7));

	result = GetTickCount();
	*(DWORD*)0xE8CB30 = result;
	return result;
}

signed int SelectCreateCharCoord(int a4)
{
	double v1; // ST14_4@8
	float v4; // ST14_4@8
	int v5; // eax@8
	void *v6; // ST24_4@10
	signed int result; // eax@10
	void *v8; // eax@12
	void *v9; // eax@14
	float v10; // [sp+1Ch] [bp-14h]@2
	DWORD v11; // [sp+20h] [bp-10h]@8
	float v12; // [sp+24h] [bp-Ch]@0
	float v13; // [sp+28h] [bp-8h]@0

	if ( *(BYTE *)(a4 + 4) == 1 )
	{
		v10 = 0.0;
		switch ( *(BYTE *)(a4 + 15) )
		{
			case 0:
				v12 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada2.CoordX;// 8282.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada2.CoordY;// 19845.0;
				v10 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada2.Rotate;// 35.0;
			break;
			case 1:
				v12 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada2.CoordX;// 8282.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada2.CoordY;// 19845.0;
				v10 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada2.Rotate;// 35.0;
			break;
			case 2:
				v12 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada2.CoordX;// 8282.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada2.CoordY;// 19845.0;
				v10 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada2.Rotate;// 35.0;
			break;
			case 3:
				v12 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada2.CoordX;// 8282.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada2.CoordY;// 19845.0;
				v10 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada2.Rotate;// 35.0;
			break;
			case 4:
				v12 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada2.CoordX;// 8282.0;
				v13 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada2.CoordY;// 19845.0;
				v10 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada2.Rotate;// 35.0;
			break;
			default:
			break;
		}
		sub_57D760(*(BYTE *)(a4 + 15));
		sub_586DA0(*(BYTE *)(a4 + 15), (unsigned __int8)*(BYTE*)0x7BD0483, *(BYTE*)0x7BD0484, v12, v13, v10);
		//v1 = *(BYTE *)(a4 + 15);
		v11 = pGetPreviewStruct(pPreviewThis(), *(BYTE *)(a4 + 15));
		if ( v11 )
		{
			*(WORD *)(v11 + 130) = *(WORD *)(a4 + 16);
			*(BYTE *)(v11 + 19) = sub_587380(*(BYTE *)(a4 + 18));
			sub_9CF1C0((char *)(v11 + 56), (const void *)(a4 + 5), 0xAu);
			*(BYTE *)(v11 + 66) = 0;
		}
		*(DWORD*)0x87935A4 = 53;
		v6 = (char *)sub_482B70();
		sub_668520((char *)sub_482B70());
		sub_4057B0((char *)sub_482B70() + 32632);
		result = sub_402AD0((char *)sub_482B70() + 36744);
	}
	else
	{
		result = *(BYTE *)(a4 + 4);
		if ( *(BYTE *)(a4 + 4) )
		{
			if ( *(BYTE *)(a4 + 4) == 2 )
			{
				result = sub_484A10(sub_482B70(), 55, 0);
			}
		}
		else
		{
			result = sub_484A10(sub_482B70(), 54, 0);
		}
	}
	return result;
}


void __declspec(naked) Player2ID()
{
	static DWORD Addr_JMP = 0x005DB532;

	_asm
	{
		CMP DWORD PTR DS:[0xE609E8],0x2
		je ReturnLoad
		CMP DWORD PTR DS:[0xE609E8],0x4
		je ReturnLoad
		//--
		ReturnLoad :
		JMP [Addr_JMP]
	}
}

__declspec(naked) void GameProcess2View()
{
	static float View = 7000.0;
	static DWORD Addr_JMP = 0x004D8808;
	_asm
	{
	FLD DWORD PTR DS:[View]
	FSTP DWORD PTR DS:[View]
	jmp [Addr_JMP]
	}
}

__declspec(naked) void SwitchCharacter2View()
{
	static float View = 7000.0;
	static DWORD Addr_JMP = 0x004D87D4;

	_asm
	{
		FLD DWORD PTR DS:[View]
		FSTP DWORD PTR DS:[View]
		jmp [Addr_JMP]
	}
}

void RenderSSCObjectVisual_1(int a1, int a2)
{
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
	//Select Character
	if (World == 76)
	{  
		switch ( *(DWORD *)(a1 + 48) )   
		{
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		{
			*(DWORD *)(a1 + 60) = -2;
		}
		break;

		case 24:
		case 25:
		case 26:
		{
			BeginRender(1.0);
			*(DWORD *)(a1 + 60) = -2;
			*(BYTE*)(a2 + 136) = 0;
			float v552 = 2000;
			float v551 = ((int)(v552 - timeGetTime()) % 2001) * 0.0005000000237487257f;
			RenderMesh(a2,
				0,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				v551,
				-1);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
		}
		break;
		case 31:
		{
			Vector( 0.0, 0.0, 0.0, WorldPos);
			TransformPosition(a2, (int)&BoneTransform, WorldPos, Bone, 0);
			Vector( 0.98000002f, 0.94f, 0.94f, Color);
			CreateSprite(32604, Bone, 1.0f, Color, a1, 0.0, 0);
			Vector( 0.77999997f, 0.44f, 0.75f, Color);
			TransformPosition(a2, (int)&BoneTransform + 0x30, WorldPos, Bone, 0);
			CreateSprite(32604, Bone, 1.2, Color, a1, 0.0, 0);	
			Vector( 0.57999998, 0.07, 0.56, Color);
			TransformPosition(a2, (int)&BoneTransform + 0x60, WorldPos, Bone, 0);
			CreateSprite(32604, Bone, 0.80000001f, Color, a1, 0.0, 0);
		}
		break;
		case 38:
		{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 6) )	
			{
			Vector( 0.02, 0.02, 0.050000001, Color);			
			CreateParticle(32146, a1 + 252, a1 + 264, Color, 20, *(float *)(a1 + 96), 0);
			}
		}
		break;
		case 39:
		{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 100) )	
			{
				Vector( 0.0, 0.0, 0.0, WorldPos);
				TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
				Vector( 0.02, 0.02, 0.050000001, Color);			
				CreateEffect2(700, Bone, a1 + 264, Color, 0, a1, -1, 0, 0, 0, 0.0, -1);
			}
		}
		break;
		case 40:
		{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 200) )	
			{
				Vector( 0.0, 0.0, 0.0, WorldPos);
				TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
				Vector( 0.02, 0.02, 0.050000001, Color);			
				CreateEffect2(701, Bone, a1 + 264, Color, 1, a1, -1, 0, 0, 0, 0.0, -1);
			}
		}
		break;

		case 54:
		{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 2) )	
			{
				Vector( 1.0, 1.0, 1.0, Color);			
				CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
			}
		}
		break;

		case 55:
		{
			*(DWORD *)(a1 + 60) = -2;
			Vector( 1.0, 1.0, 1.0, Color);			
			CreateParticle(32289, a1 + 252, a1 + 264, Color, 14, *(float *)(a1 + 96) + *(float *)(a1 + 96), 0);
		}
		break;

		case 56:
		{
			*(DWORD *)(a1 + 60) = -2;
			Vector( 1.0, 1.0, 1.0, Color);	
			if ( !(rand() % 3) )
			{		
				CreateParticle(32288, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
			}
		}
		break;

		case 73:
		{
			Vector( 0.0, 0.0, 0.0, WorldPos);
			TransformPosition(a2, Joint(1), WorldPos, Bone, 0);
			Vector( 0.5, 1.0, 0.98000002, Color);
			float v51 = ((int) timeGetTime() % 3600) * 0.1000000014901161;
			float v32 = -v51;
			float v50 = ((int) timeGetTime() % 30) / 90.0;
			float v33 = v50 + 1.200000047683716;
			CreateSprite(32114, Bone, v33, Color, a1, v32, 0);
			CreateSprite(32779, Bone, 0.20, Color, a1, 0.0, 0);
			if ( !((int) timeGetTime() % 3) )
			{
			Vector( 1.0, 1.0, 1.0, Color);
			v50 = *(float *)(a1 + 96) * 1.799999952316284;
			float v34 = v50;
			CreateParticle2(32284, Bone, a1 + 264, Color, 0, v34, 0);
			}
		}
		break;

		case 80:
		{
		*(DWORD *)(a1 + 60) = -2;
		Vector( 0.98000002, 0.89999998, 0.89999998, Color);	
		if ( !(rand() % 8) )
			{		
			CreateParticle(32101, a1 + 252, a1 + 264, Color, 69, *(float *)(a1 + 96), 0);
			}
		}
		break;
		}
	}
	CryingWolf2ndObjectVisual(a1, a2);
}


void MultiSelect::InitMultiChar()
{
	

#if ( UPDATE >= 15 )
	SetDword((LPVOID)0x004D6C2C, gSelectCharRamdon.RenderSelect.MapChar);//Change MAPA
	SetCompleteHook(0xE8, 0x004D712A, &CameraChar);//Render Camera SelectChar
	SetCompleteHook(0xE9, 0x0057F020, &RenderModelScale);//Render Scale Model PJ
	SetCompleteHook(0xE9, 0x0063D130, &SelectCharacterCord);//Coord1 PJ
	SetCompleteHook(0xE9, 0x0063D3D0, &SelectCreateCharCoord);
#endif
	if(gProtect.m_MainInfo.SelectCharS13 == 1)
	{
		SetOp((LPVOID)0x004D87C8, (LPVOID)SwitchCharacter2View, ASM::JMP);
		SetOp((LPVOID)0x004D87FC, (LPVOID)GameProcess2View, ASM::JMP);
		SetOp((LPVOID)0x005DB52B, (LPVOID)Player2ID, ASM::JMP);
		SetCompleteHook(0xE8, 0x005EDDA9,&RenderSSCObjectVisual_1);
	}
	SetCompleteHook(0xE8, 0x0048E504, &RenderPetScale);
	SetCompleteHook(0xE8, 0x00503986, &RenderPetScale);
}