#include "stdafx.h"
#include "ItemInfoEx.h"
#include "TMemory.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "Object.h"
#include "ItemManager.h"

cItemInfoEx gItemInfoEx;

cItemInfoEx::cItemInfoEx() 
{
}

cItemInfoEx::~cItemInfoEx()
{

}

__declspec(naked) void SetOptionMagic()
{
	static DWORD main_addr = 0x007E61A3;
	static DWORD lpItem; // ST10_4@12
	static DWORD ItemMagic; // ST10_4@12
	static DWORD MagicPower; // ST10_4@16

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x1C]
		MOV lpItem,EDX
	}

	MagicPower = ((ObjectItemRender *) lpItem)->MagicPower;

	_asm
	{
		PUSH MagicPower
		MOV ECX,DWORD PTR SS:[EBP+0XC]
		PUSH ECX
		LEA EDX,DWORD PTR SS:[EBP-0X12C]
		PUSH EDX
		JMP[ main_addr ]
	}
}

bool sub_58B8D0(signed int a1)
{
	return a1 >= 1032 && a1 <= 1039 || a1 == 1041 || a1 == 1042 || a1 == 1045;
}

void SetNewOption(ObjectItemRender * lpItem, BYTE Option, BYTE Special, BYTE Value) 
{
	pSetItemOption(lpItem, Option, Special, Value);

	if(lpItem->ItemID >= 6144)
	{
		return;
	}

	char v12; // [sp+3Ch] [bp-40h]@73
	int v16; // [sp+54h] [bp-28h]@1
	signed int v17; // [sp+58h] [bp-24h]@22
	signed int v18; // [sp+5Ch] [bp-20h]@1
	char v22; // [sp+6Fh] [bp-Dh]@1
	int v24; // [sp+74h] [bp-8h]@1

	std::map<int,ITEM_INFO>::iterator it = gItemManager.m_ItemInfo.find(lpItem->ItemID);

	if(it != gItemManager.m_ItemInfo.end())
	{
		DWORD v6 = 0;
		DWORD v7 = 0;
		DWORD v8 = 0;
		DWORD v9 = 0;
		DWORD v10 = 0;
		DWORD v13 = 0;
		DWORD v14 = 0;

		v24 = (Option >> 3) & 0xF;
		v16 = Special & 0x3F;
		v18 = 0;
		v22 = 0;

		if (lpItem->ItemID >= 6147 && lpItem->ItemID <= 6150
			|| lpItem->ItemID >= 6180 && lpItem->ItemID <= 6184
			|| lpItem->ItemID >= 6186 && lpItem->ItemID <= 6187
			|| lpItem->ItemID == 19
			|| lpItem->ItemID == 2066
			|| lpItem->ItemID == 2570
			|| lpItem->ItemID == 1037
			|| lpItem->ItemID == 6686
			|| lpItem->ItemID >= 6274 && lpItem->ItemID <= 6278
			|| lpItem->ItemID >= 6193 && lpItem->ItemID <= 6194
			|| lpItem->ItemID == 6279
			|| lpItem->ItemID == 2596)
		{
			v16 = 0;
		}

		if (Value % 4 == 1 || Value % 4 == 2)
		{
			v16 = 1;
			v22 = 1;
		}

		DWORD MagicPoweBin;

		lpItem->DamageMin = it->second.DamageMin;
		lpItem->DamageMax = it->second.DamageMax;
		lpItem->Defense = it->second.Defense;
		lpItem->MagicDefense = it->second.MagicDefense;
		MagicPoweBin = it->second.MagicDamageRate;
		v17 = *(WORD *)pGetItemAtt(lpItem->ItemID, 32) + 30;

		switch (lpItem->ItemID)
		{
		case 0x406:
			v18 = 15;
			break;
		case 0x806:
			v18 = 30;
			break;
		case 0xA07:
			v18 = 25;
			break;
		}

		if (it->second.DamageMin > 0)
		{
			if (v16 > 0 && *(WORD *)pGetItemAtt(lpItem->ItemID, 32))
			{
				if (v18)
					lpItem->DamageMin += v18;
				else
					lpItem->DamageMin += (25 * it->second.DamageMin / *(WORD *)pGetItemAtt(lpItem->ItemID, 32)) + 5;
			}
			if (v22)
				lpItem->DamageMin += v17 / 40 + 5;
			if (v24 <= 9)
				v14 = (Option >> 3) & 0xF;
			else
				v14 = 9;
			lpItem->DamageMin += 3 * v14;
			switch (v24)
			{
			case 15:
				lpItem->DamageMin += 9;
			case 14:
				lpItem->DamageMin += 8;
			case 13:
				lpItem->DamageMin += 7;
			case 12:
				lpItem->DamageMin += 6;
			case 11:
				lpItem->DamageMin += 5;
			case 10:
				lpItem->DamageMin += 4;
				break;
			default:
				break;
			}
		}
		if (it->second.DamageMax > 0)
		{
			if (v16 > 0 && *(WORD *)pGetItemAtt(lpItem->ItemID, 32))
			{
				if (v18)
					lpItem->DamageMax += v18;
				else
					lpItem->DamageMax += (25 * it->second.DamageMax / *(WORD *)pGetItemAtt(lpItem->ItemID, 32)) + 5;
			}
			if (v22)
				lpItem->DamageMax += v17 / 40 + 5;
			if (v24 <= 9)
				v13 = (Option >> 3) & 0xF;
			else
				v13 = 9;
			lpItem->DamageMax += 3 * v13;
			switch (v24)
			{
			case 15:
				lpItem->DamageMax += 9;
			case 14:
				lpItem->DamageMax += 8;
			case 13:
				lpItem->DamageMax += 7;
			case 12:
				lpItem->DamageMax += 6;
			case 11:
				lpItem->DamageMax += 5;
			case 10:
				lpItem->DamageMax += 4;
				break;
			default:
				break;
			}
		}
		//-- SET DEFENSE
		if (lpItem->ItemID == 6686) //???
		{
			lpItem->Defense = 15;
		}

		if (it->second.Defense > 0)
		{
			if (lpItem->ItemID < 3072 || lpItem->ItemID >= 3584)
			{
				if (v16 > 0 && *(WORD *)pGetItemAtt(lpItem->ItemID, 32))
					lpItem->Defense += 12 * it->second.Defense / *(WORD *)pGetItemAtt(lpItem->ItemID, 32) + *(WORD *)pGetItemAtt(lpItem->ItemID, 32) / 5 + 4;
				if (v22)
					lpItem->Defense += 3 * lpItem->Defense / v17 + v17 / 30 + 2;
				if ((lpItem->ItemID < 6147 || lpItem->ItemID > 6150) && lpItem->ItemID != 6186)
				{
					if (lpItem->ItemID != 6686 && lpItem->ItemID != 6193)
					{
						if ((lpItem->ItemID < 6180 || lpItem->ItemID > 6184)
							&& lpItem->ItemID != 6187
							&& lpItem->ItemID != 6194)
						{
							if (v24 <= 9)
								v7 = (Option >> 3) & 0xF;
							else
								v7 = 9;
							lpItem->Defense += 3 * v7;
						}
						else
						{
							if (v24 <= 9)
								v8 = (Option >> 3) & 0xF;
							else
								v8 = 9;
							lpItem->Defense += 4 * v8;
						}
					}
					else
					{
						if (v24 <= 9)
							v9 = (Option >> 3) & 0xF;
						else
							v9 = 9;
						lpItem->Defense += 2 * v9;
					}
				}
				else
				{
					if (v24 <= 9)
						v10 = (Option >> 3) & 0xF;
					else
						v10 = 9;
					lpItem->Defense += 2 * v10;
				}
				if ((lpItem->ItemID < 6180 || lpItem->ItemID > 6184)
					&& lpItem->ItemID != 6187
					&& lpItem->ItemID != 6194)
				{
					switch (v24)
					{
					case 15:
						lpItem->Defense += 9;
					case 14:
						lpItem->Defense += 8;
					case 13:
						lpItem->Defense += 7;
					case 12:
						lpItem->Defense += 6;
					case 11:
						lpItem->Defense += 5;
					case 10:
						lpItem->Defense += 4;
						break;
					default:
						break;
					}
				}
				else
				{
					switch (v24)
					{
					case 15:
						lpItem->Defense += 10;
					case 14:
						lpItem->Defense += 9;
					case 13:
						lpItem->Defense += 8;
					case 12:
						lpItem->Defense += 7;
					case 11:
						lpItem->Defense += 6;
					case 10:
						lpItem->Defense += 5;
						break;
					default:
						break;
					}
				}
			}
			else
			{
				lpItem->Defense += v24;
				if (v22)
					lpItem->Defense += (unsigned int)(20 * lpItem->Defense / v17) + 2;
			}
		}
		if (it->second.MagicDefense > 0)
		{
			if (v24 <= 9)
				v6 = (Option >> 3) & 0xF;
			else
				v6 = 9;
			lpItem->MagicDefense += 3 * v6;
			switch (v24)
			{
			case 15:
				lpItem->MagicDefense += 9;
			case 14:
				lpItem->MagicDefense += 8;
			case 13:
				lpItem->MagicDefense += 7;
			case 12:
				lpItem->MagicDefense += 6;
			case 11:
				lpItem->MagicDefense += 5;
			case 10:
				lpItem->MagicDefense += 4;
				break;
			default:
				break;
			}
		}

		if ( it->second.MagicDamageRate > 0 )
		{
			if ( v16 > 0 && it->second.Level )
			{
				if ( v18 )
					MagicPoweBin += v18;
				else
					MagicPoweBin += (25 * it->second.MagicDamageRate / it->second.Level) + 5;
			}
			if ( v22 )
				MagicPoweBin += v17 / 60 + 2;
			if ( v24 <= 9 )
				v12 = (Option >> 3) & 0xF;
			else
				v12 = 9;

			MagicPoweBin += 3 * v12;

			switch ( v24 )
			{
				case 15:
					MagicPoweBin += 9;
				case 14:
					MagicPoweBin += 8;
				case 13:
					MagicPoweBin += 7;
				case 12:
					MagicPoweBin += 6;
				case 11:
					MagicPoweBin += 5;
				case 10:
					MagicPoweBin += 4;
				break;
				default:
				break;
			}
			MagicPoweBin = MagicPoweBin >> 1;

			if ( !sub_58B8D0(lpItem->ItemID) )
			{
				MagicPoweBin += 2 * v24;
			}
			lpItem->MagicPower = MagicPoweBin;
		}
	}
}

void cItemInfoEx::Load() {
	//--
	SetCompleteHook(0xE9, 0x007E6190, &SetOptionMagic);
	//--
	SetOp((LPVOID)0x58B77E, SetNewOption, ASM::CALL);
	SetOp((LPVOID)0x5C7833, SetNewOption, ASM::CALL);
	SetOp((LPVOID)0x5C7D71, SetNewOption, ASM::CALL);
	SetOp((LPVOID)0x5C7F1B, SetNewOption, ASM::CALL);
	SetOp((LPVOID)0x5C80BE, SetNewOption, ASM::CALL);
	SetOp((LPVOID)0x7E22BA, SetNewOption, ASM::CALL);
}