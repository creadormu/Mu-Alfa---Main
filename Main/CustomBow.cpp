#include "stdafx.h"
#include "CustomBow.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "TMemory.h"
#include "zzzmathlib.h"
#include "Object.h"
#include "User.h"

CCustomBow gCustomBow;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomBow::CCustomBow() // OK
{
	this->m_CustomBowInfo.clear();
}

CCustomBow::~CCustomBow() // OK
{

}

DWORD SkillBow(DWORD BowItem)
{
	return gCustomBow.GetCustomSkill(BowItem);
}

void __declspec(naked) cBowAddPlayerDimension()
{
	static DWORD BowAddPlayerDimension_Offset = 0x0056623F;
	static DWORD BowAddPlayerNextDimension_Offset = 0x00566185;
	static DWORD RenderBOW = 0;
	
	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP + 0x1C]
		MOV RenderBOW, ECX
	}

	if(gCustomBow.CheckCustomBow(RenderBOW - 1171) == true || RenderBOW >= 3219 && RenderBOW <= 3225 || RenderBOW >= 3239 && RenderBOW <= 3243 || RenderBOW == 3246 || RenderBOW == 3236)
	{
		_asm
		{
			JMP [BowAddPlayerDimension_Offset]
		}
	}
	else
	{
		_asm
		{
			JMP [BowAddPlayerNextDimension_Offset]
		}
	}
}

void __declspec(naked) cCrossBowAddPlayerDimension()
{
	static DWORD Address1 = 0x00565994;
	static DWORD Address2 = 0x005659E7;
	static DWORD IsCrossItem;

	_asm
	{
		Mov Ecx, Dword ptr ss : [ebp + 0x1C]
		Mov Dword ptr ss : [ebp + 0x1C],Ecx
		Mov IsCrossItem, Ecx
	}

	if(IsCrossItem >= ITEM2(4,8) && IsCrossItem <= ITEM2(4,14)
		||IsCrossItem == ITEM2(4,16)
		||IsCrossItem == ITEM2(4,18)
		||IsCrossItem == ITEM2(4,19) 
		|| gCustomBow.CheckCustomCross(IsCrossItem - 1171)) // Devil Crossbow
	{
		_asm{jmp Address1}
	}
	else
	{
		_asm{jmp Address2}
	}
}

signed int __cdecl FixBowArrow(WORD *a1)
{
	signed int result; // eax@8
	if ((int)(*a1/512) != 4 || *a1 == 2055 || *a1 == 2063)
	{
		return 0;
	}
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(*a1);
	if (ItemInfo == 0 || (*a1/512) != 4)
	{
		return 0;
	}
	if (ItemInfo->Slot == 0)
	{
		return 2;
	}
	if (ItemInfo->Slot == 1)
	{
		return 1;
	}
	return 0;
}

void SkillEffect(ObjectPreview* a4, Object * a5, Object * a6, __int16 a7, __int16 a8, unsigned __int16 SkillID)
{
	int v10 = 0;
	int FirstIndex = a4->WeaponFirstSlot;
	int SecondIndex = a4->WeaponSecondSlot;

	lpCharObj Character = &*(ObjectCharacter*) * (int*)(0x8128AC4);

	if ( a4 == gObjUser.lpViewPlayer)
	{
		FirstIndex = Character->pEquipment[0].ItemID;
		SecondIndex = Character->pEquipment[1].ItemID;

		if (FirstIndex != -1)
			FirstIndex += 1171;
		if (SecondIndex != -1)
			SecondIndex += 1171;
	}
	
	if (SkillID == 52 || SkillID == 416)
	{
		v10 = 2;
		sub_6D6C20_Addr(85, a5, 0);
	}

	*(DWORD*)0x8793730 = SkillID;

	if (SkillID == 51 || SkillID == 424)
	{
		sub_6D6C20_Addr(130, a5, 0);
	}

	if (a8 == 2)
	{
		v10 = 99;
	}

	if (SkillID == 46)
	{
		sub_6D9070_Addr(365, a5->Position, a5->Angle, a5->Light, 0, a6, a5->Unknown44, a7, a8, 0, 0, -1);
	}
	else
	{
		int FirstIndex2 = FirstIndex - 1171;

		switch (FirstIndex)
		{
			case ITEM2(4, 8):
				sub_6D9070_Addr(267, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 9):
				sub_6D9070_Addr(267, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 10):
				sub_6D9070_Addr(271, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 11):
				sub_6D9070_Addr(269, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 12):
				sub_6D9070_Addr(268, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 13):
				sub_6D9070_Addr(274, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 14):
				sub_6D9070_Addr(273, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 16):
				sub_6D9070_Addr(294, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 18):
				sub_6D9070_Addr(321, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			case ITEM2(4, 19):
				sub_6D9070_Addr(324, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				break;
			default:
				if( gCustomBow.CheckCustomCross(FirstIndex2) == true ) // Devil Crossbow
				{
					sub_6D9070_Addr(gCustomBow.GetCustomSkill(FirstIndex2), a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
				}
				break;
		}

		switch (SecondIndex)
		{
		case ITEM2(4, 0):
			sub_6D9070_Addr(266, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 1):
			sub_6D9070_Addr(266, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 2):
			sub_6D9070_Addr(270, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 3):
			sub_6D9070_Addr(266, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 4):
			sub_6D9070_Addr(266, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 5):
			sub_6D9070_Addr(266, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 6):
			sub_6D9070_Addr(272, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 17):
			sub_6D9070_Addr(295, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 20):
			sub_6D9070_Addr(335, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 21):
			sub_6D9070_Addr(296, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 22):
			sub_6D9070_Addr(297, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 23):
			sub_6D9070_Addr(298, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 24):
			sub_6D9070_Addr(509, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		case ITEM2(4, 27):
			sub_6D9070_Addr(266, a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			break;
		default:
			if( gCustomBow.CheckCustomBow(SecondIndex - 1171) == true ) // Devil Crossbow
			{
				sub_6D9070_Addr(gCustomBow.GetCustomSkill(SecondIndex - 1171), a5->Position, a5->Angle, a5->Light, v10, a5, a5->Unknown44, a7, a8, 0, 0, -1);
			}
			break;
		}
	}
}

void CCustomBow::Init() // OK
{
	//-- FIX recarga de flechas
	SetCompleteHook(0xE8,0x5913D0+0xDB ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5913D0+0xF7 ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5A05C0+0x92 ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5A05C0+0x1B5,&FixBowArrow);
	SetCompleteHook(0xE8,0x5B5FC0+0xD34,&FixBowArrow);
	SetCompleteHook(0xE8,0x7E04B0+0xF8 ,&FixBowArrow);
	//-- Effect Skill
	SetCompleteHook(0xE8, 0x6F1100 + 0x1CDC, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x53, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x121, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x15C, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x197, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x1D2, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x20D, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x267, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x2A2, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x2DD, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x318, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x395, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x3D0, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x40B, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x446, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x488, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x4C3, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x4FE, &SkillEffect);
	SetCompleteHook(0xE8, 0x74A670 + 0x53D, &SkillEffect);
	//--
	SetRange((LPVOID)0x00566178, 7, ASM::NOP);
	SetJmp((LPVOID)0x00566178, cBowAddPlayerDimension);
	//--
	SetRange((LPVOID)0x0056595E, 6, ASM::NOP);
	SetJmp((LPVOID)0x0056595E, cCrossBowAddPlayerDimension);

}

void CCustomBow::Load(CUSTOM_BOW_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_BOW;n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_CUSTOM_BOW)
		{
			return;
		}
		this->m_CustomBowInfo.insert(std::pair<int,CUSTOM_BOW_INFO>(info[n].ItemIndex,info[n]));
	}
}

CUSTOM_BOW_INFO* CCustomBow::GetInfoByItem(int ItemIndex) // OK
{
	CUSTOM_BOW_INFO* value;

	std::map<int,CUSTOM_BOW_INFO>::iterator it = this->m_CustomBowInfo.find(ItemIndex);

	if(it != this->m_CustomBowInfo.end())
	{
		(*value) = it->second;

		return value;
	}

	return 0;
}

bool CCustomBow::CheckCustomBow(int ItemIndex) // OK
{
	std::map<int,CUSTOM_BOW_INFO>::iterator it = this->m_CustomBowInfo.find(ItemIndex);
	
	if(it != this->m_CustomBowInfo.end())
	{
		return it->second.ItemType == 0;
	}

	return false;
}

bool CCustomBow::CheckCustomCross(int ItemIndex) // OK
{
	std::map<int,CUSTOM_BOW_INFO>::iterator it = this->m_CustomBowInfo.find(ItemIndex);
	
	if(it != this->m_CustomBowInfo.end())
	{
		return it->second.ItemType == 1;
	}

	return false;
}

int CCustomBow::GetCustomSkill(int ItemIndex) // OK
{
	std::map<int, CUSTOM_BOW_INFO>::iterator it = this->m_CustomBowInfo.find(ItemIndex);
	
	if(it != this->m_CustomBowInfo.end())
	{
		return it->second.SkillShot;
	}
	return -1;
}
