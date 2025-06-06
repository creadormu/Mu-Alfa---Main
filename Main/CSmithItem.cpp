// CustomItem.cpp: implementation of the CCustomSmith class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CSmithItem.h"

CCustomSmith gCustomSmith;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCustomSmith::CCustomSmith() // OK
{
	this->Init();
}

CCustomSmith::~CCustomSmith() // OK
{

}

void CCustomSmith::Init() // OK
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->m_SmithSwordInfo[n].ItemIndex = -1;
		this->m_SmithAxeInfo[n].ItemIndex = -1;
		this->m_SmithMaceInfo[n].ItemIndex = -1;
		this->m_SmithSpearInfo[n].ItemIndex = -1;
		this->m_SmithBowInfo[n].ItemIndex = -1;
		this->m_SmithStaffInfo[n].ItemIndex = -1;
		this->m_SmithShieldInfo[n].ItemIndex = -1;
		this->m_SmithHelmInfo[n].ItemIndex = -1;
		this->m_SmithArmorInfo[n].ItemIndex = -1;
		this->m_SmithPantInfo[n].ItemIndex = -1;
		this->m_SmithGloveInfo[n].ItemIndex = -1;
		this->m_SmithBootInfo[n].ItemIndex = -1;
	}
}

void CCustomSmith::LoadSword(CUSTOM_SMITH_INFO* info) // Sword
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoSword(info[n]);
	}
}
void CCustomSmith::LoadAxe(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoAxe(info[n]);
	}
}
void CCustomSmith::LoadMace(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoMace(info[n]);
	}
}
void CCustomSmith::LoadSpear(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoSpear(info[n]);
	}
}
void CCustomSmith::LoadBow(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoBow(info[n]);
	}
}
void CCustomSmith::LoadStaff(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoStaff(info[n]);
	}
}
void CCustomSmith::LoadShield(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoShield(info[n]);
	}
}
void CCustomSmith::LoadHelm(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoHelm(info[n]);
	}
}
void CCustomSmith::LoadArmor(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoArmor(info[n]);
	}
}
void CCustomSmith::LoadPant(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoPant(info[n]);
	}
}
void CCustomSmith::LoadGlove(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoGlove(info[n]);
	}
}
void CCustomSmith::LoadBoot(CUSTOM_SMITH_INFO* info) //
{
	for(int n=0;n < MAX_SMITH_ITEM;n++)
	{
		this->SetInfoBoot(info[n]);
	}
}

void CCustomSmith::SetInfoSword(CUSTOM_SMITH_INFO info) // Sword
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithSwordInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoAxe(CUSTOM_SMITH_INFO info) // Axe
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithAxeInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoMace(CUSTOM_SMITH_INFO info) // Mace
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithMaceInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoSpear(CUSTOM_SMITH_INFO info) // Spear
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithSpearInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoBow(CUSTOM_SMITH_INFO info) // Bow
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithBowInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoStaff(CUSTOM_SMITH_INFO info) // Staff
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithStaffInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoShield(CUSTOM_SMITH_INFO info) // Shield
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithShieldInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoHelm(CUSTOM_SMITH_INFO info) // Helm
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithHelmInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoArmor(CUSTOM_SMITH_INFO info) // Armor
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithArmorInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoPant(CUSTOM_SMITH_INFO info) // Pant
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithPantInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoGlove(CUSTOM_SMITH_INFO info) // Glove
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithGloveInfo[info.ItemIndex] = info;
}
void CCustomSmith::SetInfoBoot(CUSTOM_SMITH_INFO info) // Boot
{
	if(info.ItemIndex < 0 || info.ItemIndex >= MAX_SMITH_ITEM)
	{
		return;
	}

	this->m_SmithBootInfo[info.ItemIndex] = info;
}
