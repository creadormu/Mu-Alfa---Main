#include "stdafx.h"
#include "Import.h"
#include "Offset.h"
#include "Util.h"

//----- (00648B30) --------------------------------------------------------
/*signed int sub_648B30(int a4, int a5, int a6)
{
	BYTE *v6; // eax@2
	BYTE *v7; // eax@2
	signed int result; // eax@2
	signed int v9; // ST30_4@3
	int v10; // eax@3
	double v11; // ST50_8@54
	double v12; // ST44_8@54
	signed int v13; // ST30_4@55
	int v14; // eax@55
	int v15; // eax@61
	signed int v16; // ST30_4@70
	int v17; // eax@70
	signed int v18; // eax@73
	int v19; // [sp+1Ch] [bp-9C4h]@92
	int v20; // [sp+20h] [bp-9C0h]@84
	int v21; // [sp+24h] [bp-9BCh]@76
	int v22; // [sp+48h] [bp-998h]@70
	signed int v23; // [sp+4Ch] [bp-994h]@72
	signed int v24; // [sp+50h] [bp-990h]@68
	signed int k; // [sp+54h] [bp-98Ch]@65
	int v26; // [sp+58h] [bp-988h]@65
	char v27; // [sp+5Ch] [bp-984h]@65
	int v28; // [sp+8Ch] [bp-954h]@73
	int v29; // [sp+98h] [bp-948h]@65
	float v30; // [sp+9Ch] [bp-944h]@65
	float v31; // [sp+A0h] [bp-940h]@65
	float v32; // [sp+A4h] [bp-93Ch]@65
	float v33; // [sp+A8h] [bp-938h]@65
	float v34; // [sp+ACh] [bp-934h]@65
	float v35; // [sp+B0h] [bp-930h]@65
	float v36; // [sp+B4h] [bp-92Ch]@65
	float v37; // [sp+B8h] [bp-928h]@65
	int v38; // [sp+BCh] [bp-924h]@65
	float v39; // [sp+C0h] [bp-920h]@65
	float v40; // [sp+C4h] [bp-91Ch]@65
	int v41; // [sp+C8h] [bp-918h]@61
	int v42; // [sp+CCh] [bp-914h]@59
	int v43; // [sp+D0h] [bp-910h]@59
	char v44; // [sp+D4h] [bp-90Ch]@59
	__int16 v45; // [sp+104h] [bp-8DCh]@59
	int v46; // [sp+108h] [bp-8D8h]@59
	float v47; // [sp+10Ch] [bp-8D4h]@59
	float v48; // [sp+110h] [bp-8D0h]@59
	float v49; // [sp+114h] [bp-8CCh]@59
	float v50; // [sp+118h] [bp-8C8h]@59
	float v51; // [sp+11Ch] [bp-8C4h]@59
	float v52; // [sp+120h] [bp-8C0h]@59
	float v53; // [sp+124h] [bp-8BCh]@59
	float v54; // [sp+128h] [bp-8B8h]@59
	int v55; // [sp+12Ch] [bp-8B4h]@59
	float v56; // [sp+130h] [bp-8B0h]@59
	float v57; // [sp+134h] [bp-8ACh]@59
	float v58; // [sp+138h] [bp-8A8h]@57
	float v59; // [sp+13Ch] [bp-8A4h]@57
	float v60; // [sp+140h] [bp-8A0h]@57
	int j; // [sp+144h] [bp-89Ch]@52
	int i; // [sp+148h] [bp-898h]@49
	int v63; // [sp+14Ch] [bp-894h]@49
	char v64; // [sp+150h] [bp-890h]@49
	int v65; // [sp+180h] [bp-860h]@55
	int v66; // [sp+184h] [bp-85Ch]@49
	float v67; // [sp+188h] [bp-858h]@49
	float v68; // [sp+18Ch] [bp-854h]@49
	float v69; // [sp+190h] [bp-850h]@49
	float v70; // [sp+194h] [bp-84Ch]@49
	float v71; // [sp+198h] [bp-848h]@49
	float v72; // [sp+19Ch] [bp-844h]@49
	float v73; // [sp+1A0h] [bp-840h]@49
	float v74; // [sp+1A4h] [bp-83Ch]@49
	int v75; // [sp+1A8h] [bp-838h]@49
	float v76; // [sp+1ACh] [bp-834h]@49
	float v77; // [sp+1B0h] [bp-830h]@49
	char v78; // [sp+1B4h] [bp-82Ch]@2
	int v79; // [sp+9C0h] [bp-20h]@3
	unsigned __int16 v80; // [sp+9C4h] [bp-1Ch]@3
	int v81; // [sp+9C8h] [bp-18h]@3
	int v82; // [sp+9CCh] [bp-14h]@5
	int v83; // [sp+9D0h] [bp-10h]@3
	int v84; // [sp+9DCh] [bp-4h]@2

	if ( a6 )
	{
		v79 = a4;
		v83 = *(BYTE *)(a4 + 6) + (*(BYTE *)(a4 + 5) << 8);
		v80 = *(BYTE *)(a4 + 4) + (*(BYTE *)(a4 + 3) << 8);
		v9 = sub_57D9A0(v83);
		v10 = sub_402BC0();
		v81 = sub_96A4C0(v10, v9);
		if ( v81 )
		{
			v82 = v81 + 776;
			*(WORD *)(v81 + 38) = v80;
			*(float *)(v82 + 272) = (double)*(BYTE *)(v79 + 9) / 255.0 * 360.0;
			if ( *(DWORD *)(v82 + 48) == 1163 )
			{
				if ( v81 != *(DWORD *)0x7BC4F04 )
				{
					if ( (signed int)v80 > 270 )
					{
						switch ( v80 )
						{
							case 0x2Bu:
							case 0x150u:
							case 0x153u:
							case 0x156u:
								pActionPlayerSend(v82, 71, 1);
								break;
						}
					}
				}
			}
		}
	}
						case 0x19Eu:
						case 0x1A2u:
LABEL_11:
				PlayerAnimationOneHit(v81);
				break;
				case 0x183u:
				case 0x187u:
LABEL_13:
				PlayerAnimationMonturaSkill(v81);
				break;
				case 0x1A0u:
LABEL_14:
				PlayerAnimationOneHit(v81);
				break;
				case 0x184u:
LABEL_16:
				pActionPlayerSend(v82, 154, 1);
				break;
				case 0x17Du:
				case 0x1E6u:
LABEL_17:
				pActionPlayerSend(v82, 153, 1);
				break;
				case 0x14Au:
				case 0x14Cu:
				case 0x1E1u:
LABEL_18:
				pActionPlayerSend(v82, 65, 1);
				break;
				case 0x206u:
				case 0x208u:
LABEL_19:
				if ( *(WORD *)(v81 + 556) == 7864 )
				{
					pActionPlayerSend(v82, 92, 1);
				}
				else if ( (signed int)*(WORD *)(v81 + 556) < 7829 || (signed int)*(WORD *)(v81 + 556) > 7831 )
				{
					pActionPlayerSend(v82, 80, 1);
				}
				else
				{
					pActionPlayerSend(v82, 82, 1);
				}
				PlayBuffer(736, 0, 0);
				break;
				case 0x207u:
LABEL_26:
				if ( *(WORD *)(v81 + 556) == 7864 )
					pActionPlayerSend(v82, 95, 1);
				else
					pActionPlayerSend(v82, 152, 1);
				break;
				case 0x1FEu:
				case 0x200u:
				case 0x204u:
LABEL_30:
				pActionPlayerSend(v82, 87, 1);
				PlayBuffer(462, 0, 0);
				break;
				case 0x14Bu:
				case 0x14Du:
LABEL_31:
				pActionPlayerSend(v82, 66, 1);
				break;
				case 0x151u:
LABEL_32:
				pActionPlayerSend(v82, 176, 1);
				break;
				case 0x1EAu:
LABEL_37:
				pActionPlayerSend(v82, 65, 1);
				break;
				case 0x1E2u:
LABEL_38:
				pActionPlayerSend(v82, 145, 1);
				break;
				case 0x150u:
LABEL_39:
				pActionPlayerSend(v82, 71, 1);
				break;
				case 0x20Bu:
LABEL_43:
				if ( *(WORD *)(v81 + 556) == 7864 )
				{
					pActionPlayerSend(v81 + 776, 92, 1);
				}
				else if ( (signed int)*(WORD *)(v81 + 556) < 7829 || (signed int)*(WORD *)(v81 + 556) > 7831 )
				{
					pActionPlayerSend(v81 + 776, 80, 1);
				}
				else
				{
					pActionPlayerSend(v81 + 776, 82, 1);
				}
				v63 = v82;
				v72 = 0.0;
				v73 = 0.0;
				v74 = 0.0;
				sub_959CE0(v82 + 264, (int)&v64);
				sub_95A1E0((int)&v72, (int)&v64, (int)&v69);
				*(float *)&v66 = v69 + *(float *)(v63 + 252);
				v67 = v70 + *(float *)(v63 + 256);
				v68 = v71 + *(float *)(v63 + 260);
				*(float *)&v75 = 0.5;
				v76 = 0.5;
				v77 = 0.5;
				for ( i = 0; i < 5; ++i )
					pSkillRenderEffect(32119, (int)&v66, v63 + 264, (int)&v75, 3, v63, -1, 0, 0, 0, 0.5, -1);
				v66 = *(int *)(v63 + 252);
				v67 = *(float *)(v63 + 256);
				v68 = *(float *)(v63 + 260);
				for ( j = 0; j < 8; ++j )
				{
					v11 = *(float *)(v63 + 252) - 119.0;
					*(float *)&v66 = (double)((signed int)sub_9CFB8D() % 240) + v11;
					v12 = *(float *)(v63 + 260) + 49.0;
					v68 = (double)((signed int)sub_9CFB8D() % 60) + v12;
					sub_72D1B0(
					32405,
					(int)&v66,
					v63 + 252,
					v63 + 264,
					0,
					v63,
					20.0,
					*(WORD *)(v63 + 44),
					0,
					*(BYTE *)(v63 + 34),
					-1,
					0,
					-1);
				}
				v13 = *(DWORD *)0xE61730;
				v14 = sub_402BC0();
				v65 = sub_96A4C0(v14, v13);
				if ( v81 == *(DWORD *)0x7BC4F04 && v65 )
				{
					v58 = *(float *)(v65 + 1028);
					v59 = *(float *)(v65 + 1032);
					v60 = *(float *)(v65 + 1036);
					sub_6EFF10(a1, a2, (int)&v58, 1, 0);
				}
				PlayBuffer(843, 0, 0);
				break;
				case 0x1CAu:
LABEL_84:
				v20 = *(WORD *)(v81 + 556);
				switch ( v20 )
				{
					case 7829:
					pActionPlayerSend(v82, 169, 1);
					break;
					case 7830:
					pActionPlayerSend(v82, 170, 1);
					break;
					case 7864:
					pActionPlayerSend(v82, 171, 1);
					break;
					default:
					pActionPlayerSend(v82, 168, 1);
					break;
				}
				break;
				case 0x1C8u:
LABEL_103:
				pActionPlayerSend(v82, 185, 1);
				break;
				case 0x230u:
LABEL_104:
				if ( v81 != *(DWORD *)0x7BC4F04 )
					sub_511360((int)&unk_EBCD98, a1, a2, (int)a3, v82, v80);
				sub_50ECD0(v80, v82);
						break;
						default:
LABEL_108:
						PlayerAnimationMonturaSkill(v81);
						break;
					}
			}
			else if ( v80 == 270 )
			{
			sub_50ECD0(v80, v82);
			}
			else
			{
			switch ( v80 )
			{
				case 0x18u:
				goto LABEL_11;
				case 0x36u:
				PlayerAnimationOneHit(v81);
				goto LABEL_109;
				case 0x26u:
				case 0x27u:
				goto LABEL_13;
				case 0x34u:
				goto LABEL_14;
				case 0xCu:
				pActionPlayerSend(v82, 152, 1);
				goto LABEL_109;
				case 0xAu:
				goto LABEL_16;
				case 0xEu:
				goto LABEL_17;
				case 0x29u:
				goto LABEL_18;
				case 0x4Eu:
				goto LABEL_19;
				case 0x41u:
				goto LABEL_26;
				case 0x3Eu:
				goto LABEL_30;
				case 0x2Au:
				goto LABEL_31;
				case 0xE8u:
				goto LABEL_32;
				case 0x2Fu:
				if ( *(WORD *)(v81 + 556) == 7864 )
					pActionPlayerSend(v82, 99, 1);
				else
					pActionPlayerSend(v82, 70, 1);
				goto LABEL_109;
				case 0x37u:
				goto LABEL_37;
				case 0x38u:
				goto LABEL_38;
				case 0x2Bu:
				goto LABEL_39;
				case 0x43u:
				pActionPlayerSend(v82, 67, 1);
				goto LABEL_109;
				case 0x46u:
				pActionPlayerSend(v82, 67, 1);
				goto LABEL_109;
				case 0x4Cu:
				sub_541960(v81, v82);
				goto LABEL_109;
				case 0xEEu:
				goto LABEL_43;
				case 0xEBu:
				sub_6456D0(v81);
				v43 = v82;
				v52 = 0.0;
				v53 = 20.0;
				v54 = 0.0;
				sub_959CE0(v82 + 264, (int)&v44);
				sub_95A1E0((int)&v52, (int)&v44, (int)&v49);
				*(float *)&v46 = v49 + *(float *)(v43 + 252);
				v47 = v50 + *(float *)(v43 + 256);
				v48 = v51 + *(float *)(v43 + 260);
				*(float *)&v55 = 0.80000001;
				v56 = 0.89999998;
				v57 = 1.6;
				pSkillRenderEffect(9547, (int)&v46, v43 + 264, (float*)&v55, 0, 0, -1, 0, 0, 0, 0.0, -1);
				pSkillRenderEffect(9547, (int)&v46, v43 + 264, (float*)&v55, 0, 0, -1, 0, 0, 0, 0.0, -1);
				v52 = 0.0;
				v53 = 0.0;
				v54 = 0.0;
				sub_959CE0(v43 + 264, (int)&v44);
				sub_95A1E0((int)&v52, (int)&v44, (float*)&v49);
				*(float *)&v46 = v49 + *(float *)(v43 + 252);
				v47 = v50 + *(float *)(v43 + 256);
				v48 = v51 + *(float *)(v43 + 260);
				pSkillRenderEffect(9545, (int)&v46, v43 + 264, (float*)&v55, 0, 0, -1, 0, 0, 0, 0.0, -1);
				pSkillRenderEffect(9545, (int)&v46, v43 + 264, (float*)&v55, 0, 0, -1, 0, 0, 0, 0.0, -1);
				pSkillRenderEffect(9545, (int)&v46, v43 + 264, (float*)&v55, 0, 0, -1, 0, 0, 0, 0.0, -1);
				v52 = 0.0;
				v53 = 20.0;
				v54 = 0.0;
				sub_959CE0(v43 + 264, (int)&v44);
				sub_95A1E0((int)&v52, (int)&v44, (float*)&v49);
				*(float *)&v46 = v49 + *(float *)(v43 + 252);
				v47 = v50 + *(float *)(v43 + 256);
				v48 = v51 + *(float *)(v43 + 260);
				pSkillRenderEffect(9546, (int)&v46, v43 + 264, (float*)&v55, 0, 0, -1, 0, 0, 0, 0.0, -1);
				pSkillRenderEffect(9546, (int)&v46, v43 + 264, (float*)&v55, 0, 0, -1, 0, 0, 0, 0.0, -1);
				v52 = 0.0;
				v53 = -120.0;
				v54 = 145.0;
				sub_959CE0(v43 + 264, (int)&v44);
				sub_95A1E0((int)&v52, (int)&v44, (float*)&v49);
				*(float *)&v46 = v49 + *(float *)(v43 + 252);
				v47 = v50 + *(float *)(v43 + 256);
				v48 = v51 + *(float *)(v43 + 260);
				v45 = -1;
				v42 = 0;
				while ( 2 )
				{
					if ( v42 < 400 )
					{
					v15 = sub_402BC0();
					v41 = sub_96A4C0(v15, v42);
					if ( v41 != v81 )
					{
						++v42;
						continue;
					}
					v45 = v42;
					}
					break;
				}
				pSkillRenderEffect(402, (int)&v46, v43 + 264, (float*)&v55, 1, v43, v45, 0, 0, 0, 0.0, -1);
				goto LABEL_109;
				case 0xEAu:
				v26 = v82;
				*(float *)&v38 = 0.40000001;
				v39 = 0.60000002;
				v40 = 1.0;
				v35 = 0.0;
				v36 = 0.0;
				v37 = 0.0;
				sub_959CE0(v82 + 264, (int)&v27);
				sub_95A1E0((int)&v35, (int)&v27, (int)&v32);
				*(float *)&v29 = v32 + *(float *)(v26 + 252);
				v30 = v33 + *(float *)(v26 + 256);
				v31 = v34 + *(float *)(v26 + 260);
				v31 = v31 + 130.0;
				v29 = *(int *)(v26 + 252);
				v30 = *(float *)(v26 + 256);
				v31 = *(float *)(v26 + 260);
				for ( k = 0; k < 19; ++k )
					sub_72D1B0(a1, a2, (int)a3, 32131, (int)&v29, (int)&v29, v26 + 264, 47, v26, 40.0, 2, 0, 0, -1, 0, -1);
				*(float *)&v38 = 0.30000001;
				v39 = 0.2;
				v40 = 0.1;
				pSkillRenderEffect(405, (int)&v29, v26 + 264, (int)&v38, 0, 0, -1, 0, 0, 0, 0.0, -1);
				pSkillRenderEffect(32404, (int)&v29, v26 + 264, (int)&v38, 0, 0, -1, 0, 0, 0, 0.0, -1);
				pSkillRenderEffect(32404, (int)&v29, v26 + 264, (int)&v38, 1, 0, -1, 0, 0, 0, 0.0, -1);
				pSkillRenderEffect(32404, (int)&v29, v26 + 264, (int)&v38, 2, 0, -1, 0, 0, 0, 0.0, -1);
				v24 = 0;
				break;
				case 0xD8u:
				v21 = *(WORD *)(v81 + 556);
				switch ( v21 )
				{
					case 7829:
					pActionPlayerSend(v82, 165, 1);
					break;
					case 7830:
					pActionPlayerSend(v82, 166, 1);
					break;
					case 7864:
					pActionPlayerSend(v82, 167, 1);
					break;
					default:
					pActionPlayerSend(v82, 164, 1);
					break;
				}
				goto LABEL_109;
				case 0xD6u:
				goto LABEL_84;
				case 0xDDu:
				case 0xDEu:
				v19 = *(WORD *)(v81 + 556);
				switch ( v19 )
				{
					case 7829:
					pActionPlayerSend(v82, 157, 1);
					break;
					case 7830:
					pActionPlayerSend(v82, 158, 1);
					break;
					case 7864:
					pActionPlayerSend(v82, 159, 1);
					break;
					default:
					pActionPlayerSend(v82, 156, 1);
					break;
				}
				goto LABEL_109;
				case 0xDFu:
				case 0xE0u:
				case 0xE1u:
				sub_534C00(a1, a2, (int)a3, v80, v81, v82, *(BYTE *)(v79 + 7), *(BYTE *)(v79 + 8));
				goto LABEL_109;
				case 0xECu:
				pActionPlayerSend(v82, 184, 1);
				goto LABEL_109;
				case 0xEDu:
				pActionPlayerSend(v82, 183, 1);
				goto LABEL_109;
				case 0xE6u:
				goto LABEL_103;
				case 0x108u:
				goto LABEL_104;
				default:
				goto LABEL_108;
			}
			while ( v24 < 2 )
			{
				v16 = *(DWORD *)(v26 + 48);
				v17 = sub_4CDA10();
				v22 = sub_969C50(v17, v16);
				if ( !v22 )
				return 0;
				v23 = *(WORD *)(v22 + 34);
				if ( v23 > 0 )
				{
				v18 = sub_9CFB8D();
				sub_544E60(v22, (int)&v28, v26, v18 % v23, 0);
				pSkillRenderEffect(32131, (int)&v28, v26 + 264, (int)&v38, 3, 0, -1, 0, 0, 0, 0.0, -1);
				}
				++v24;
						}
						PlayBuffer(842, 0, 0);
					}
LABEL_109:
					*(float *)(v82 + 140) = 0.0;
				}
			}
			else
			{
			PlayerAnimationOneHit(v81);
			*(float *)(v82 + 140) = 0.0;
			}
			*(BYTE *)(v81 + 34) = 1;
			*(WORD *)(v81 + 128) = -1;
			*(BYTE *)(v81 + 33) = 0;
			*(BYTE *)(v81 + 47) = *(BYTE *)(v79 + 7);
			*(BYTE *)(v81 + 48) = *(BYTE *)(v79 + 8);
			result = 1;
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		sub_404B40(&v78);
		v84 = 0;
		sub_404B90(&v78, -63, -15);
		v6 = sub_4050D0(&v78, 3);
		v7 = sub_4050D0(v6, 0);
		sub_4050D0(v7, 30);
		sub_404D70((int)&v78, 1, 0);
		v84 = -1;
		sub_404B60();
		result = 0;
	}
result = 1;
	return result;
}*/
// E61730: using guessed type int *(DWORD *)0xE61730;
// 7BC4F04: using guessed type int *(DWORD *)0x7BC4F04;

void InitMasterSkillEffect()
{
	//SetCompleteHook(0xE9, 0x00819EB4, &skillmaster);
}