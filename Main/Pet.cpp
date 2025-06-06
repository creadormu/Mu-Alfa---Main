#include "stdafx.h"
#include "Pet.h"
#include "Import.h"
#include "User.h"
#include "PetProtocol.h"
#include "TMemory.h"
#include "Protect.h"
#include "Interface.h"
#include "Util.h"
#include "Inter3.h"
#include "WindowsStruct.h"

CustomPet gCustomPet;

CustomPet::CustomPet() //OK
{
	this->PetTickCount = 0;
}

CustomPet::~CustomPet()
{

}

char CustomPet::PetHPBar(int a1, int a2)
{
	lpViewObj Object = &*(ObjectPreview*)oUserPreviewStruct;

	char result;
	char PetName[255];
	int PetHP;

	if ((Object->PetSlot < 7827 || Object->PetSlot > 7831)
		&& Object->PetSlot != 7891
		&& Object->PetSlot != 7892
		&& Object->PetSlot != 7894
		&& Object->PetSlot != 7907
		&& Object->PetSlot != 7933
		&& Object->PetSlot != 7950
		&& Object->PetSlot != 7864
		&& (Object->PetSlot < ITEM2(13, 200) || Object->PetSlot > ITEM2(13, 512)))
	{
		result = 0;
	}
	else
	{
		memset(&PetHP, 0, 255);
		PetName[0] = 0;
		switch (Object->PetSlot)
		{
		case 7827:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 353));
			break;
		case 7828:
			wsprintf(PetName, (char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		case 7829:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 355));
			break;
		case 7830:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 354));
			break;
		case 7831:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 1187));
			break;
		case 7864:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 1916));
			break;
		case 7891:
			wsprintf(PetName, (char *)(oUserTextObject + 564480));
			break;
		case 7892:
			wsprintf(PetName, (char *)(oUserTextObject + 564564));
			break;
		case 7894:
			wsprintf(PetName, (char *)(oUserTextObject + 564732));
			break;
		case 7907:
			wsprintf(PetName, (char *)(oUserTextObject + 565824));
			break;
		case 7933:
			wsprintf(PetName, (char *)(oUserTextObject + 568008));
			break;
		case 7950:
			wsprintf(PetName, (char *)(oUserTextObject + 569436));
			break;
		default:
			wsprintf(PetName, (char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		}

		PetHP = *(BYTE*)(oUserObjectStruct_ + 5550);

		if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
		{
			PetMuunHP(1, gInterface.PetY, (int)&PetName, PetHP, 255, 0);
		}
		else if( gProtect.m_MainInfo.CustomInterfaceType != 1 && gProtect.m_MainInfo.CustomInterfaceType != 2 )
		{
			sub_7DFA60(1, gInterface.PetY, (int)&PetName, PetHP, 255, 0);
		}
		else
		{
			PetHPBarRemake(1, gInterface.PetY, (int)&PetName, PetHP, 255, 0);
		}

		result = 1;
	}

	return result;
}

bool IsCharacterMove(int a1)
{

	if ((*(WORD *)(*(DWORD *)(a1 + 472) + 18) >= 15
		&& *(WORD *)(*(DWORD *)(a1 + 472) + 18) <= 37)
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 74
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 75
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 259
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 260)
	{
		return true;
	}
	return false;
}

void CustomPet::PetFollowCharacter(int a1, float MaxPos)
{
	float v22;
	vec3_t MUFLOAT;
	vec3_t PetPos;
	vec3_t OwnerPos;
	vec3_t CurrentPos;
	int LootPosition = 1000;

	OwnerPos[0] = *(float *)(*(DWORD *)(a1 + 472) + 252);
	OwnerPos[1] = *(float *)(*(DWORD *)(a1 + 472) + 256);
	OwnerPos[2] = *(float *)(*(DWORD *)(a1 + 472) + 260);

	PetPos[0] = OwnerPos[0] - *(float *)(a1 + 252);
	PetPos[1] = OwnerPos[1] - *(float *)(a1 + 256);
	PetPos[2] = OwnerPos[2] - *(float *)(a1 + 260);

	CurrentPos[0] = *(float *)(a1 + 252);
	CurrentPos[1] = *(float *)(a1 + 256);
	CurrentPos[2] = *(float *)(a1 + 260);

	float PetMapPos = PetPos[0] * PetPos[0] + PetPos[1] * PetPos[1];

	float diff1 = ((OwnerPos[0] > CurrentPos[0]) ? OwnerPos[0] - CurrentPos[0] : CurrentPos[0] - OwnerPos[0]);
	float diff2 = ((OwnerPos[1] > CurrentPos[1]) ? OwnerPos[1] - CurrentPos[1] : CurrentPos[1] - OwnerPos[1]);

	float angle = atan(diff2 / diff1) * 180 / PI;
	float angle2 = atan2(diff1, diff2) * 180 / PI; //

	if (PetMapPos >= MaxPos * MaxPos)
	{
		float speed;
		if (PetMapPos >= (MaxPos * 2) * (MaxPos * 2))
		{
			speed = 14.0f;
			speed += 1.0f;
			*(float *)(a1 + 120) = 0.89000002f;
		}
		else if (PetMapPos >= (MaxPos + (MaxPos / 2)) * (MaxPos + (MaxPos / 2)))
		{
			speed = 13.0f;
			*(float *)(a1 + 120) = 0.69000002f;
		}
		else
		{
			speed = 10.0f;
			*(float *)(a1 + 120) = 0.40000001f;
		}

		double MoveX = speed *(cos(angle * PI / 180));
		double MoveY = speed *(sin(angle * PI / 180));

		if (CurrentPos[0] < OwnerPos[0] && CurrentPos[1] < OwnerPos[1])
		{
			*(float *)(a1 + 252) += (float)MoveX;
			*(float *)(a1 + 256) += (float)MoveY;
			*(float *)(a1 + 272) = 180;
			*(float *)(a1 + 272) -= angle2;
		}
		else if (CurrentPos[0] < OwnerPos[0] && CurrentPos[1] > OwnerPos[1])
		{
			*(float *)(a1 + 252) += (float)MoveX;
			*(float *)(a1 + 256) -= (float)MoveY;
			*(float *)(a1 + 272) = angle2;
		}
		else if (CurrentPos[0] > OwnerPos[0] && CurrentPos[1] > OwnerPos[1])
		{
			*(float *)(a1 + 252) -= (float)MoveX;
			*(float *)(a1 + 256) -= (float)MoveY;
			*(float *)(a1 + 272) = 360;
			*(float *)(a1 + 272) -= angle2;
		}
		else if (CurrentPos[0] > OwnerPos[0] && CurrentPos[1] < OwnerPos[1])
		{
			*(float *)(a1 + 252) -= (float)MoveX;
			*(float *)(a1 + 256) += (float)MoveY;
			*(float *)(a1 + 272) = 180;
			*(float *)(a1 + 272) += angle2;
		}
		*(WORD*)(a1 + 18) = 2;
	}
	else if (PetMapPos < 70 * 70)
	{
		if ((*(WORD *)(*(DWORD *)(a1 + 472) + 18) < 15 || *(WORD *)(*(DWORD *)(a1 + 472) + 18) > 37))
		{
			*(WORD*)(a1 + 18) = 2;
			sub_959CE0(a1 + 264, a1 + 372);
			sub_95A1E0(a1 + 168, a1 + 372, MUFLOAT);
			*(float *)(a1 + 252) = *(float *)(a1 + 252) + MUFLOAT[0];
			*(float *)(a1 + 256) = *(float *)(a1 + 256) + MUFLOAT[1];
		}
	}
	else
	{
		if( pViewAttackTargetID != -1 )
		{
			if (GetTickCount() <= gCustomPet.PetTickCount + 10000)
			{
				*(WORD*)(a1 + 18) = 1;
			}
			else
			{
				*(WORD*)(a1 + 18) = 0;
				gCustomPet.PetTickCount = GetTickCount();
			}
		}
		/*else if (GetTickCount() <= gCustomPet.PetTickCount + 800)
		{
			*(WORD*)(a1 + 18) = 1;
		}*/
		else if ( GetTickCount() <= gCustomPet.PetTickCount + 800 )
		{
			*(WORD*)(a1 + 18) = 0;
		}
		else
		{
			gCustomPet.PetTickCount = GetTickCount();
		}
	}

	if (PetMapPos >= LootPosition * LootPosition)
	{
		if (*(float *)(a1 + 252) < *(float *)(*(DWORD *)(a1 + 472) + 252))
		{
			*(float *)(a1 + 252) = *(float *)(a1 + 252) + PetPos[0] + rand() % 360;
		}
		if (*(float *)(a1 + 252) > *(float *)(*(DWORD *)(a1 + 472) + 252))
		{
			*(float *)(a1 + 252) = *(float *)(a1 + 252) + PetPos[0] - rand() % 360;
		}
		if (*(float *)(a1 + 256) < *(float *)(*(DWORD *)(a1 + 472) + 256))
		{
			*(float *)(a1 + 256) = *(float *)(a1 + 256) + PetPos[1] + rand() % 360;
		}
		if (*(float *)(a1 + 256) > *(float *)(*(DWORD *)(a1 + 472) + 256))
		{
			*(float *)(a1 + 256) = *(float *)(a1 + 256) + PetPos[1] - rand() % 360;
		}
	}

	*(float *)(a1 + 260) = *(float *)(*(DWORD *)(a1 + 472) + 260);

	if (!(rand() % 100))
	{
		if (PetMapPos < MaxPos * MaxPos)
		{
			v22 = -(float)(rand() % 64 + 16) * 0.1000000014901161f;
			*(float *)(a1 + 272) = (float)(rand() % 360);
		}
		else
		{
			v22 = -(float)(rand() % 64 + 128) * 0.1000000014901161f;
		}
		*(float *)(a1 + 168) = 0.0f;
		*(float *)(a1 + 172) = v22;
		*(float *)(a1 + 176) = (float)(rand() % 64 - 32) * 0.1000000014901161f;
	}

	if (*(float *)(a1 + 260) < *(float *)(*(DWORD *)(a1 + 472) + 260) + 100.0f)
		*(float *)(a1 + 176) = *(float *)(a1 + 176) + 1.5f;
	if (*(float *)(a1 + 260) > *(float *)(*(DWORD *)(a1 + 472) + 260) + 200.0f)
		*(float *)(a1 + 176) = *(float *)(a1 + 176) - 1.5f;
}

void CustomPet::PetsMovement(int a1, char a2)
{
	int v86; // [sp+19Ch] [bp-Ch]@76
	float v87; // [sp+1A0h] [bp-8h]@76
	float v88; // [sp+1A4h] [bp-4h]@76

	if (*(BYTE *)(a1 + 4))
	{
		lpViewObj lpObj = &*(ObjectPreview*)*(DWORD*)0x07BC4F04;

		if (*(DWORD*)0xE609E8 == 5
			&& (*(DWORD*)0xE61E18 < 65 || *(DWORD*)0xE61E18 > 68)
			&& (!*(BYTE *)(*(DWORD *)(a1 + 472) + 4) || *(BYTE *)(*(DWORD *)(a1 + 472) + 24) != 1))
		{
			*(BYTE *)(a1 + 4) = 0;
			sub_501790(a1, a2);
			return;
		}

		DWORD SkinID = *(DWORD *)(a1 + 48);
		DWORD Model = sub_969C50(sub_4CDA10(), SLODWORD(SkinID));

		if (Model)
		{
			if ((SkinID >= ITEM2(13, 200) && SkinID <= ITEM2(13, 512)) && gCustomPet2.GetInfoPetType( SkinID - 1171 ) == 8)
			{
				gCustomPet.PetFollowCharacter(a1, 150);

				switch (SkinID)
				{
					case ITEM2(13, 226): //King
					case ITEM2(13, 281): //Prince
					case ITEM2(13, 388): //Prince =)) lazy
						*(float*)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 40.0f;
						break;
					case ITEM2(13, 214): //Hawk
					case ITEM2(13, 215): //Hawk Evo
					case ITEM2(13, 174): //CherryBlossom
					case ITEM2(13, 175): //CherryBlossom Evo
					case ITEM2(13, 178): //Chrysanthemum
					case ITEM2(13, 179): //Chrysanthemum Evo
					case ITEM2(13, 200): //Ghost
						*(float*)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 30.0f;
						break;
					case ITEM2(13, 201): //Ghost Evo
						*(DWORD *)(a1 + 68) = 1;
						*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 30.0f;
						break;
				}
			}
		}
	}

	((void(*)(int, char)) 0x501790)(a1, a2);
}

void CustomPet::PreviewCharSet(int ObjectIndex, BYTE * CharSet, lpViewObj Object, int Mode)
{
	pPreviewCharSet(ObjectIndex, CharSet, Object, Mode);

	lpViewObj lpObj;

	if (Object == 0)
	{
		lpObj = &*(lpViewObj)pGetPreviewStruct(pPreviewThis(), ObjectIndex);
	}
	else
	{
		lpObj = Object;
	}

	PMSG_NEW_CHARACTER_CHARSET_RECV* SelectCharSet = GetNewCharSetSelectCharacter(lpObj->Name);

	if (pPlayerState == 4)
	{
		if (SelectCharSet > 0)
		{
			BYTE sNewCharSet0 = SelectCharSet->PetCharSet[0] >> 1;
			BYTE sNewCharSet1 = SelectCharSet->PetCharSet[1] >> 1;
			BYTE sNewCharSet2 = SelectCharSet->PetCharSet[2] >> 1;
			BYTE sNewCharSet3 = SelectCharSet->PetCharSet[3] >> 1;

			if (sNewCharSet0 > 0 && sNewCharSet0 < 112)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 147) + (sNewCharSet0 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}

			if (sNewCharSet1 > 0 && sNewCharSet1 < 94)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 258) + (sNewCharSet1 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}

			if (sNewCharSet2 > 0 && sNewCharSet2 < 100)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 351) + (sNewCharSet2 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}

			if (sNewCharSet3 > 0 && sNewCharSet3 < 100)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 451) + (sNewCharSet3 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}
		}
	}

	NEW_PET_STRUCT* lpCharSet = GetNewPetCharSet(lpObj->aIndex);

	if (lpCharSet > 0)
	{
		BYTE NewCharSet0 = lpCharSet->PetCharSet[0] >> 1;
		BYTE NewCharSet1 = lpCharSet->PetCharSet[1] >> 1;
		BYTE NewCharSet2 = lpCharSet->PetCharSet[2] >> 1;
		BYTE NewCharSet3 = lpCharSet->PetCharSet[3] >> 1;

		if (NewCharSet0 > 0 && NewCharSet0 < 112)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 147) + (NewCharSet0 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

		if (NewCharSet1 > 0 && NewCharSet1 < 94)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 258) + (NewCharSet1 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

		if (NewCharSet2 > 0 && NewCharSet2 < 100)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 351) + (NewCharSet2 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

		if (NewCharSet3 > 0 && NewCharSet3 < 100)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 451) + (NewCharSet3 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

	}

	BYTE CustomPets = CharSet[15] >> 1;

	if (CharSet[11] & 1) // == 1 
	{
		lpObj->PetSlot = 7831;
		if (Mode)
			sub_5013B0(226, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
		else
			sub_501700(226, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
	}
}

void CustomPet::RefreshViewPortItem(int a1)
{
	signed int v1; // ST14_4@1
	int result; // eax@1
	int v6; // [sp+Ch] [bp-14h]@2
	int v7; // [sp+10h] [bp-10h]@1
	int v8; // [sp+14h] [bp-Ch]@2
	BYTE v9; // [sp+1Dh] [bp-3h]@2
	BYTE v10; // [sp+1Eh] [bp-2h]@2
	BYTE v11; // [sp+1Fh] [bp-1h]@2

	v1 = sub_57D9A0(*(BYTE *)(a1 + 4) + (*(BYTE *)(a1 + 3) << 8));
	result = sub_96A4C0(sub_402BC0(), v1);
	v7 = result;

	if ( result )
	{
		v6 = result + 776;
		v8 = sub_58AA80(a1 + 5);
		v11 = *(BYTE *)(a1 + 6) & 0xF;
		v10 = *(BYTE *)(a1 + 8) & 0x3F;
		v9 = *(BYTE *)(a1 + 9);
		switch ((signed int)*(BYTE *)(a1 + 6) >> 4)
		{
		case 7:
			if (v8 == 0x1FFF)
			{
				if (*(WORD*)(v7 + 520) == ITEM2(12,40)
					|| *(WORD*)(v7 + 520) == ITEM2(12,49)
					|| *(WORD*)(v7 + 520) == ITEM2(12,50)
					|| gCloak.isCloak((*(WORD*)(v7 + 520) - 1171)))
				{
					sub_558630(v7, v6, 0);
				}
				*(WORD *)(v7 + 520) = -1;
			}
			else
			{
				*(WORD *)(v7 + 520) = v8 + 1171;
				*(BYTE *)(v7 + 522) = 0;
				if (*(WORD*)(v7 + 520) == ITEM2(12, 40)
					|| *(WORD*)(v7 + 520) == ITEM2(12, 49)
					|| *(WORD*)(v7 + 520) == ITEM2(12, 50)
					|| gCloak.isCloak((*(WORD*)(v7 + 520) - 1171)))
				{
					sub_558630(v7, v6, 0);
				}
			}
			break;
		case 8:
			if (v8 == 0x1FFF)
			{
				*(WORD *)(v7 + 556) = -1;
				sub_5012D0(v6);
				sub_9253D0(sub_4DB230(), v7, -1);
			}
			else
			{
				*(WORD *)(v7 + 556) = v8 + 1171;
				*(BYTE *)(v7 + 558) = 0;
				if (v8 >= ITEM(13, 147) && v8 <= ITEM(13, 512))
				{
					sub_501700(v8 + 1171, v6 + 252, v6, 0, 0);
				}
			}
			break;
		default:
			break;
		}
	}
	((void(*)(int))0x6411A0)(a1);
}

void CustomPet::Load()
{
	//-- Follow Pet Character
	//
	//-- PetMuun
	SetOp((LPVOID)0x0048E17D, CustomPet::PetsMovement, ASM::CALL);
	SetOp((LPVOID)0x00503756, CustomPet::PetsMovement, ASM::CALL);

	SetOp((LPVOID)0x007DF8BB, CustomPet::PetHPBar, ASM::CALL);
	
	SetOp((LPVOID)0x48FB8C, CustomPet::PreviewCharSet, ASM::CALL);
	SetOp((LPVOID)0x63D2D8, CustomPet::PreviewCharSet, ASM::CALL);
	SetOp((LPVOID)0x641189, CustomPet::PreviewCharSet, ASM::CALL);
	SetOp((LPVOID)0x641F42, CustomPet::PreviewCharSet, ASM::CALL);
	SetOp((LPVOID)0x642598, CustomPet::PreviewCharSet, ASM::CALL);
	SetOp((LPVOID)0x65EA2D, CustomPet::PreviewCharSet, ASM::CALL);

	SetOp((LPVOID)0x664267, CustomPet::RefreshViewPortItem, ASM::CALL);
}