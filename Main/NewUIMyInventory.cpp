#include "StdAfx.h"
#include "Util.h"
#include "Protocol.h"
#include "CustomPet.h"
#include "NewUIButton.h"
#include "UIControl.h"
#include "Pet.h"
#include "NewUIMyInventory.h"
#include "SEASON3B.h"
#include "Central.h"
#include "WindowsStruct.h"
#include "Interface.h"

CNewUIMyInventory g_MuunSystem;

int SlotPickBackup = -1;
int ItemOverTooltip = -1;
int SlotOverSelect = -1;
int var_file[20] = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4 };
int var_colum[20] = { 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3 };

CNewUIMyInventory::CNewUIMyInventory()
{
	this->InventoryCTRLStatus = 0;
	this->PageID = 0;
}

CNewUIMyInventory::~CNewUIMyInventory()
{
}

void CNewUIMyInventory::CRenderBitmap(int Texture, float x, float y, float Width, float Height, float u, float v, float uWidth, float vHeight, bool Scale, bool StartScale, float Alpha)
{
	RBitmaps(Texture, x, y, Width, Height, u, v, uWidth, vHeight, Scale, StartScale, Alpha);
}

void g_DeleteBug(OBJECT *Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];
		if (o->Live)
		{
			if (o->Owner == Owner && o->Type == Index)
			{
				o->Live = false;
				break;
			}
		}
	}
}

void g_DeleteMuunBug(OBJECT *Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];
		int type = gCustomPet2.GetInfoPetType(o->Type - 1171);

		if (o->Owner == Owner &&
			(o->Type != Index &&
			o->Type != MODEL_FENRIR_BLACK &&
			o->Type != MODEL_FENRIR_RED &&
			o->Type != MODEL_FENRIR_BLUE &&
			o->Type != MODEL_FENRIR_GOLD &&
			o->Type != MODEL_DARK_HORSE &&
			o->Type != MODEL_PEGASUS &&
			o->Type != MODEL_UNICON &&
			o->Type != MODEL_BUTTERFLY01 &&
			(type == 8 && type > -1)))
		{
			o->Live = false;
		}
	}
}

bool g_CheckBugLive(OBJECT *Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];

		if (o->Owner == Owner && o->Type == Index)
		{
			if (o->Live)
			{
				return true;
			}
		}
	}
	return false;
}

void CNewUIMyInventory::UnEquipMuun(int EQUIPMENT_SLOT, ITEM* MuunPet)
{
	if (EQUIPMENT_SLOT != EQUIPMENT_MAIN_INDEX)
	{
		return;
	}

	OBJECT* pHeroObject = &*(OBJECT*)(Hero + 776);

	g_DeleteBug(pHeroObject, MuunPet->Type + 1171);
}

void CNewUIMyInventory::EquipMuun(ITEM* pTempItem, int EQUIPMENT_SLOT)
{
	if (NULL == pTempItem || EQUIPMENT_SLOT != EQUIPMENT_MAIN_INDEX)
	{
		return;
	}

	OBJECT* pHeroObject = &*(OBJECT*)(Hero + 776);

	g_DeleteMuunBug(pHeroObject, *(WORD*)(Hero + 556));

	CreateBug(pTempItem->Type + 1171, pHeroObject->Position, pHeroObject, 0, 0);
}

void CNewUIMyInventory::AddInventoryCtrl(ITEM* pNewItem, int dwKey)
{
	if (dwKey < 0 || dwKey > MUUN_INVENTORY_SIZE)
		return;

	std::map<int, ITEM*>::iterator nodeHandler = this->m_vecItem.find(dwKey);

	if (nodeHandler != g_MuunSystem.m_vecItem.end())
	{
		this->m_vecItem.erase(nodeHandler);
	}

	g_MuunSystem.m_vecItem.insert(std::pair<int, ITEM*>(dwKey, pNewItem));
	g_MuunSystem.m_pdwItemCheckBox[dwKey] = pNewItem->Key;

	g_MuunSystem.EquipMuun(pNewItem, dwKey);
}

void CNewUIMyInventory::DelInventoryCTRL(int dwKey)
{
	if (dwKey >= 0 && dwKey < MUUN_INVENTORY_SIZE)
	{
		std::map<int, ITEM*>::iterator nodeHandler = g_MuunSystem.m_vecItem.find(dwKey);
		if (nodeHandler != g_MuunSystem.m_vecItem.end())
		{
			if (dwKey == EQUIPMENT_MAIN_INDEX)
			{
				g_MuunSystem.UnEquipMuun(dwKey, nodeHandler->second);
			}
			g_MuunSystem.m_pdwItemCheckBox[dwKey] = NULL;
			g_MuunSystem.m_vecItem.erase(nodeHandler);
		}
	}
}

ITEM* CNewUIMyInventory::FindItemBySlot(DWORD dwKey)
{
	if (dwKey < 0 || dwKey > MUUN_INVENTORY_SIZE)
		return NULL;

	type_vec_item::iterator li = this->m_vecItem.find(dwKey);

	if (li != this->m_vecItem.end())
	{
		return li->second;
	}
	return NULL;
}

void CNewUIMyInventory::ItemGetRecv(PMSG_MUUN_ITEM_GET_RECV *lpMsg)
{
	if (lpMsg->result != 0xFF)
	{
		ITEM* pNewItem = CreateItemConvertByte(*(DWORD *)(g_pNewUISystem() + 36), lpMsg->ItemInfo);

		if (pNewItem)
		{
			BPlaySound(29, 0, 0);
			g_MuunSystem.AddInventoryCtrl(pNewItem, lpMsg->result);
		}
	}
	*(DWORD*)0xE61FC8 = -1;
}

void CNewUIMyInventory::ItemListRecv(PMSG_MUUN_ITEM_LIST_RECV* lpMsg)
{
	g_MuunSystem.m_vecItem.clear();

	memset(g_MuunSystem.m_pdwItemCheckBox, 0, sizeof(g_MuunSystem.m_pdwItemCheckBox));

	for (int n = 0; n < lpMsg->count; n++)
	{
		PMSG_MUUN_ITEM_LIST * lpInfo = (PMSG_MUUN_ITEM_LIST*)(((BYTE*)lpMsg) + sizeof(PMSG_MUUN_ITEM_LIST_RECV)+(sizeof(PMSG_MUUN_ITEM_LIST)* n));

		ITEM* pNewItem = CreateItemConvertByte(*(DWORD *)(g_pNewUISystem() + 36), lpInfo->ItemInfo);

		if (pNewItem)
		{
			g_MuunSystem.AddInventoryCtrl(pNewItem, lpInfo->slot);
		}
	}
}

void CNewUIMyInventory::ItemSetDur(PMSG_MUUN_ITEM_DUR_RECV* lpMsg)
{
	if (lpMsg->slot != 0xFF)
	{
		ITEM* pNewItem = g_MuunSystem.FindItemBySlot(lpMsg->slot);

		if (pNewItem != NULL)
		{
			pNewItem->Durability = lpMsg->dur;
		}
	}
}

void CNewUIMyInventory::ItemModifyRecv(PMSG_MUUN_ITEM_MODIFY_RECV *lpMsg)
{
	if (lpMsg->slot != 0xFF)
	{
		ITEM* pNewItem = CreateItemConvertByte(*(DWORD *)(g_pNewUISystem() + 36), lpMsg->ItemInfo);

		if (pNewItem)
		{
			g_MuunSystem.AddInventoryCtrl(pNewItem, lpMsg->slot);
		}
	}
}

void CNewUIMyInventory::ItemDropRecv(PMSG_MUUN_ITEM_DROP_RECV *lpMsg)
{
	if (lpMsg->result == 1)
	{
		if (SlotPickBackup == lpMsg->slot && ms_pPickedItem)
		{
			DeletePickedItem();
			SlotPickBackup = -1;
			return;
		}
		g_MuunSystem.DelInventoryCTRL(lpMsg->slot);
	}
}

void CNewUIMyInventory::ItemSellRecv(PMSG_MUUN_ITEM_SELL_RECV *lpMsg)
{
	//if (lpMsg->result == 1)
	//{
	//	if (SlotPickBackup == lpMsg->slot && ms_pPickedItem)
	//	{
	//		DeletePickedItem();
	//		SlotPickBackup = -1;
	//		return;
	//	}
	//	g_MuunSystem.DelInventoryCTRL(lpMsg->slot);
	//}
}

void CNewUIMyInventory::ItemDeleteRecv(PMSG_MUUN_ITEM_DELETE_RECV *lpMsg)
{
	if (lpMsg->flag == 1)
	{
		if (SlotPickBackup == lpMsg->slot && ms_pPickedItem)
		{
			DeletePickedItem();
			SlotPickBackup = -1;
			return;
		}
		g_MuunSystem.DelInventoryCTRL(lpMsg->slot);
	}
}

void CNewUIMyInventory::ItemChangeRecv(PMSG_MUUN_ITEM_CHANGE_RECV *lpMsg)
{
	int TempEquip; // [sp+1Dh] [bp-3h]@2
	int IndexUser;
	int g_HeroPlayer;

	IndexUser = FindCharacterIndex(lpMsg->index[1] + (lpMsg->index[0] << 8));

	g_HeroPlayer = CharactersClient(CList(), IndexUser);

	if (g_HeroPlayer)
	{
		OBJECT* pHeroObject = &*(OBJECT*)(g_HeroPlayer + 776);

		TempEquip = sub_58AA80((DWORD)lpMsg->ItemInfo);
		switch ((signed int)lpMsg->ItemInfo[1] >> 4)
		{
		
		case EQUIPMENT_MAIN_INDEX:
			if (TempEquip == 0x1FFF)
			{
				g_DeleteMuunBug(pHeroObject, *(WORD*)(g_HeroPlayer + 556));
			}
			else
			{
				if (!g_CheckBugLive(pHeroObject, TempEquip + 1171))
				{
					CreateBug(TempEquip + 1171, pHeroObject->Position, pHeroObject, 0, 0);
				}
			}
			break;
		}
	}
}

void  CNewUIMyInventory::DelectPetBug(OBJECT * Owner)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];

		int type = gCustomPet2.GetInfoPetType(o->Type - 1171);

		if (o->Owner == Owner)
		{
			if (type == 8 && type > -1)
				continue;
			else
				o->Live = false;
		}
	}
}

void CNewUIMyInventory::LoadImages()
{
	((void(__cdecl*)())0x0080EEF0)();
	//--
	LoadBitmapA("Custom\\MuunPet\\PetInventoryFrame_I3.tga", IMAGE_FRAME_I3, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\MuunPet\\Menu_Button03.tga", IMAGE_MENU_BUTTON03, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Custom\\MuunPet\\Menu_Button04.tga", IMAGE_MENU_BUTTON04, GL_LINEAR, GL_CLAMP, 1, 0);
}

void CreateCTRL(int x, int y, int nColumn, int nRow)
{
	g_MuunSystem.m_vecItem.clear();
	memset(g_MuunSystem.m_pdwItemCheckBox, 0, sizeof(g_MuunSystem.m_pdwItemCheckBox));

	g_MuunSystem.back.Construct();
	g_MuunSystem.next.Construct();

	g_MuunSystem.back.ChangeButtonImgState(true, IMAGE_MENU_BUTTON03, true);
	g_MuunSystem.next.ChangeButtonImgState(true, IMAGE_MENU_BUTTON04, true);
}

bool __thiscall CNewUIMyInventory::CreateInventoryUICTRL(int thisa, int a5, int a6, int a7, int x, int y, int col, int fil)
{
	CreateCTRL(x, y, 4, 5);
	return CreateInventoryCTRL(thisa, a5, a6, a7, x, y, col, fil);
}

void CNewUIMyInventory::SetPos(int x, int y)
{
	this->m_Pos.x = x;
	this->m_Pos.y = y;

	g_MuunSystem.back.CButtonInfo(x + 68, y + 380, 12, 12);
	g_MuunSystem.next.CButtonInfo(x + 130, y + 380, 12, 12);
}

bool CNewUIMyInventory::UpdateKeyEvent()
{
	if (IsPress('L'))
	{
		
		if (!IsVisible(g_pNewUISystem(), 33))
		{
			g_MuunSystem.InventoryCTRLStatus = !g_MuunSystem.InventoryCTRLStatus;
		}
	}
	if (IsPress(VK_ESCAPE))
	{
		if (g_MuunSystem.InventoryCTRLStatus == 1)
		{
			g_MuunSystem.InventoryCTRLStatus = 0;
		}
	}
	return 1;
}

bool __thiscall CNewUIMyInventory::CRenderInterfaceRight(int thisa)
{
	bool var_addr;
	float X = (640/2)-(208/2);
	if (pCheckWindow(pWindowThis(), Inventory))
	{
		X = 640 - (200 + 208);
	}
	if (pCheckWindow(pWindowThis(), Inventory) && pCheckWindow(pWindowThis(), ExpandInventory))
	{
		X = 640 - (200 + (208) + 190);
	}
	if (g_MuunSystem.InventoryCTRLStatus == 1)
	{
		g_MuunSystem.SetPos(X, 0);
	}

	var_addr = RenderRight(thisa);

	g_MuunSystem.RenderFrame();

	g_MuunSystem.CheckTooltipMuun();

	return var_addr;
}

bool CNewUIMyInventory::CheckMuunInventoryOver()
{
	if (gInterface.Data[eCONFIRM_MUUN].OnShow)
	{
		pSetCursorFocus = true;
		return 0;
	}
	return pCheckInMouse(this->m_Pos.x, this->m_Pos.y, 208, 408);
}

void CNewUIMyInventory::CheckTooltipMuun()
{

	if (this->InventoryCTRLStatus != 0 && this->CheckMuunInventoryOver())
	{
		int v4; // eax@2
		ITEM * iTemp; // eax@2

		if (!GetPickedItem() || (v4 = GetPickedItem(), (iTemp = GetMouseItem(v4)) == 0))
		{
			if (ItemOverTooltip != -1)
			{
				ITEM* pItem = this->FindItemBySlot(ItemOverTooltip);

				POINT dir;
				int slotmin = this->PageID * 20;

				if (ItemOverTooltip == 0)
				{
					dir.x = this->m_Pos.x + 41;
					dir.y = this->m_Pos.y + 75;
				}
				else if (ItemOverTooltip == 1)
				{
					dir.x = this->m_Pos.x + 125;
					dir.y = this->m_Pos.y + 75.f;
				}
				else
				{
					int Slot = ItemOverTooltip - 2;

					Slot -= slotmin;

					dir.x = (float)(this->m_Pos.x + 20.f + var_colum[Slot] * 42) + 27;
					dir.y = (float)(this->m_Pos.y + 152.f + var_file[Slot] * 44.f) - 80;
				}
				this->g_pdwItemTooltip = pItem->Type;
				RenderItemInfo(GetUI3D(g_pNewUISystem()), dir.x, dir.y, pItem, false, 0, false);

			}
			else
			{
				this->g_pdwItemTooltip = -1;
			}
		}
		else
		{
			this->g_pdwItemTooltip = -1;
		}
	}
	else
	{
		this->g_pdwItemTooltip = -1;
	}
}

void CNewUIMyInventory::RenderFrame()
{
	if (this->InventoryCTRLStatus == 0)
	{
		if (SlotPickBackup != -1)
		{
			if (ms_pPickedItem)
			{
				ITEM* iTemp = CreateItemPick(GetMouseItem(GetPickedItem()));

				if (NULL != iTemp)
				{
					g_MuunSystem.AddInventoryCtrl(iTemp, SlotPickBackup);
					DeletePickedItem();

					SlotPickBackup = -1;
					return;
				}
			}
			SlotPickBackup = -1;
		}
		return;
	}

	EnableAlphaTest(true);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	this->RenderWindows();
	ItemOverTooltip = -1;
	SlotOverSelect = -1;
	this->RenderEquippedItem();
	//this->RenderDetails();
	this->RenderInventoryCtrl();
	this->InventoryCtrlRender3D();
	//-- active button
	EnableAlphaTest(true);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	g_MuunSystem.back.Render();
	g_MuunSystem.next.Render();
	g_MuunSystem.DrawConfirmBox();
	DisableAlphaBlend();
}

void CNewUIMyInventory::RenderWindows()
{
	int i = 0;
	float cy = this->m_Pos.y + 152;

	this->CRenderBitmap(IMAGE_FRAME_I3, this->m_Pos.x, this->m_Pos.y, 208.f, 408.f, 0.0, 0.0, 325.f / 512.f, 638.f / 1024.f);
	//-- cerrar
	this->CRenderBitmap(IMAGE_FRAME_I3, this->m_Pos.x + 174.f, this->m_Pos.y + 26.f, 12.f, 12.f, 472.f / 512.f, 186.f / 1024.f, 21.f / 512.f, 21.f / 1024.f);
	g_pRenderText2.SetFont(g_hFontBold);
	g_pRenderText2.SetBgColor(0);
	g_pRenderText2.SetTextColor(CLRDW_BR_YELLOW);
	g_pRenderText2.RenderText(this->m_Pos.x, this->m_Pos.y + 27, "Muun Inventory", 208, 0, RT3_SORT_CENTER);

	g_pRenderText2.SetFont(g_hFont);
	g_pRenderText2.SetTextColor(CLRDW_WHITE);
	char texting[50];
	sprintf_s(texting, "%d / %d", this->PageID + 1, 3);
	g_pRenderText2.RenderText(this->m_Pos.x + 90, this->m_Pos.y + 380, texting, 30, 0, RT3_SORT_CENTER);
}

void CNewUIMyInventory::RenderEquippedItem()
{
	POINT SlotBox[2] = { this->m_Pos.x + 41, this->m_Pos.y + 75, this->m_Pos.x + 125, this->m_Pos.y + 75 };

	for (int m = 0; m < 2; m++)
	{
		this->CRenderBitmap(IMAGE_FRAME_I3, SlotBox[m].x + 3.5f, SlotBox[m].y + 3.5f, 34.5f, 35.75f, 356.f / 512.f, 186.f / 1024.f, 54.f / 512.f, 56.f / 1024.f);

		if (pCheckInMouse(SlotBox[m].x, SlotBox[m].y, 42, 43))
		{
			SlotOverSelect = m;

			if (GetPickedItem())
			{
				if (g_MuunSystem.m_pdwItemCheckBox[m] != NULL)
				{
					this->CRenderBitmap(IMAGE_FRAME_I3, SlotBox[m].x + 3.5f, SlotBox[m].y + 3.5f, 34.5f, 35.75f, 443.f / 512.f, 0.0, 27.f / 512.f, 27.f / 1024.f);
				}
				else
				{
					this->CRenderBitmap(IMAGE_FRAME_I3, SlotBox[m].x + 3.5f, SlotBox[m].y + 3.5f, 34.5f, 35.75f, 335.f / 512.f, 0.0, 27.f / 512.f, 27.f / 1024.f);
				}
				goto LABEL_117;
			}
			else if (g_MuunSystem.m_pdwItemCheckBox[m] != NULL)
			{
				ItemOverTooltip = m;
			}
		}

		if (g_MuunSystem.m_pdwItemCheckBox[m] != NULL)
		{
			this->CRenderBitmap(IMAGE_FRAME_I3, SlotBox[m].x + 3.5f, SlotBox[m].y + 3.5f, 34.5f, 35.75f, 443.f / 512.f, 31.f / 1024.f, 27.f / 512.f, 27.f / 1024.f);
		}
	LABEL_117:
		this->CRenderBitmap(IMAGE_FRAME_I3, SlotBox[m].x, SlotBox[m].y, 42.f, 43.5f, 353.f / 512.f, 113.f / 1024.f, 66.f / 512.f, 68.f / 1024.f);
	}
}

void CNewUIMyInventory::RenderInventoryCtrl()
{
	float dx, dy;
	int slotmin, dwKey;
	float cy = this->m_Pos.y + 152.f;

	slotmin = g_MuunSystem.PageID * 20;
	dwKey = 2 + slotmin;

	for (int j = 0; j < 5; j++)
	{
		dy = cy + j * 43;
		for (int k = 0; k < 4; k++)
		{
			dx = this->m_Pos.x + 20.f + k * 42;

			if (pCheckInMouse((int)(dx + 3.f), (int)(dy + 3.f), 42, 43))
			{
				SlotOverSelect = dwKey;
				if (g_MuunSystem.m_pdwItemCheckBox[dwKey] != NULL)
					ItemOverTooltip = dwKey;
				else
					ItemOverTooltip = -1;
			}

			this->CRenderBitmap(IMAGE_FRAME_I3, dx + 3.5f, dy + 3.5f, 34.5f, 35.75f, 356.f / 512.f, 186.f / 1024.f, 54.f / 512.f, 56.f / 1024.f);

			if (ms_pPickedItem)
			{
				bool pickitemvisible = (*(bool(__thiscall **)(int))(*(DWORD *)ms_pPickedItem + 4))(ms_pPickedItem);

				if (pCheckInMouse((int)(dx + 3.f), (int)(dy + 3.f), 42, 43) && pickitemvisible)
				{
					ITEM * iTemp = GetMouseItem(GetPickedItem());

					if ((iTemp->Type == ITEMDEF(14, 16) || iTemp->Type == ITEMDEF(13, 211)) && this->m_pdwItemCheckBox[dwKey] != NULL)
					{
						this->CRenderBitmap(IMAGE_FRAME_I3, dx + 6.f, dy + 3.5f, 34.5f, 35.75f, 416.f / 512.f, 0.0, 27.f / 512.f, 27.f / 1024.f);
					}

					else if (this->m_pdwItemCheckBox[dwKey] != NULL)
					{
						this->CRenderBitmap(IMAGE_FRAME_I3, dx + 6.f, dy + 3.5f, 34.5f, 35.75f, 443.f / 512.f, 0.0, 27.f / 512.f, 27.f / 1024.f);
					}
					else
					{
						if (gCustomPet2.GetInfoPetType(iTemp->Type) == 8)
							this->CRenderBitmap(IMAGE_FRAME_I3, dx + 3.5f, dy + 3.5f, 34.5f, 35.75f, 335.f / 512.f, 0.0, 27.f / 512.f, 27.f / 1024.f);
						else
							this->CRenderBitmap(IMAGE_FRAME_I3, dx + 3.5f, dy + 3.5f, 34.5f, 35.75f, 443.f / 512.f, 0.0, 27.f / 512.f, 27.f / 1024.f);
					}
					goto LABEL_125;
				}
			}

			if (g_MuunSystem.m_pdwItemCheckBox[dwKey] != NULL)
			{
				this->CRenderBitmap(IMAGE_FRAME_I3, dx + 3.5f, dy + 3.5f, 34.5f, 35.75f, 443.f / 512.f, 31.f / 1024.f, 27.f / 512.f, 27.f / 1024.f);
			}
		LABEL_125:
			this->CRenderBitmap(IMAGE_FRAME_I3, dx, dy, 42.f, 43.5f, 427.f / 512.f, 113.f / 1024.f, 66.f / 512.f, 68.f / 1024.f);

			dwKey++;
		}
	}
}

void CNewUIMyInventory::InventoryCtrlRender3D()
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	glViewport2(0, 0, *(GLsizei*)g_WindowWidth, *(GLsizei*)g_WindowHeight);
	float v2 = *(float*)g_WindowWidth / *(float*)g_WindowHeight;
	gluPerspective_2(1.f, v2, CameraViewNear, CameraViewFar);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	GetOpenGLMatrixF(CameraMatrixF);
	EnableDepthTestF();
	EnableDepthMaskF();
	glClear(0x100u);

	float sx, sy;
	int slotx, sloty;
	int slotmin = g_MuunSystem.PageID * 20;
	int slotmax = slotmin + 20;

	for (auto iter = this->m_vecItem.begin(); iter != this->m_vecItem.end(); ++iter)
	{
		ITEM* iTemp = iter->second;

		if (iter->first == 0)
		{
			sx = this->m_Pos.x + 41;
			sy = this->m_Pos.y + 75;
			RenderItem3D(sx, sy, 42.f, 43.f, iTemp->Type, 0, 0, 0, 0);
		}
		else if (iter->first == 1)
		{
			sx = this->m_Pos.x + 125;
			sy = this->m_Pos.y + 75;
			RenderItem3D(sx, sy, 42.f, 43.f, iTemp->Type, 0, 0, 0, 0);
		}
		else
		{
			int Slot = iter->first - 2;

			if (Slot >= slotmin && Slot < slotmax)
			{
				Slot -= slotmin;
				slotx = var_colum[Slot];
				sloty = var_file[Slot];

				sx = (float)this->m_Pos.x + 20.f + slotx * 42.f;
				sy = (float)this->m_Pos.y + 148.f + sloty * 43.f;
				RenderItem3D(sx, sy, 42.f, 43.f, iTemp->Type, 0, 0, 0, 0);
			}
		}
	}

	EndBitmap();
	glColor4f(1.f, 1.f, 1.f, 1.f);
	EnableAlphaTest(true);
}

void CNewUIMyInventory::SendRequestSellItem(BYTE SlotPick)
{
	PMSG_MUUN_ITEM_SELL_SEND Send;

	Send.header.set(0x4E, 0x09, sizeof(Send));

	Send.slot = SlotPick;

	DataSend((LPBYTE)&Send, Send.header.size);
}
void CNewUIMyInventory::SendRequestDropItem(BYTE SlotPick, BYTE tx, BYTE ty)
{
	PMSG_MUUN_ITEM_DROP_SEND Send;

	Send.header.set(0x4E, 0x01, sizeof(Send));

	Send.slot = SlotPick;

	Send.x = tx;

	Send.y = ty;

	DataSend((LPBYTE)&Send, Send.header.size);
}

void CNewUIMyInventory::SendRequestUsedItem(BYTE SourceSlot, BYTE TargetSlot, BYTE type)
{
	PMSG_MUUN_ITEM_USE_SEND Send;

	Send.header.set(0x4E, 0x08, sizeof(Send));

	Send.SourceSlot = SourceSlot;

	Send.TargetSlot = TargetSlot;

	Send.type = type;

	DataSend((LPBYTE)&Send, Send.header.size);
}
int TypeConfirmBox = 0;
int CONFIRMSlot = -1;
float CONFIRMSlotX = -1;
float CONFIRMSlotY = -1;
void CNewUIMyInventory::DrawConfirmBox()
{
	if (!gInterface.CheckWindow(Shop) && gInterface.Data[eCONFIRM_MUUN].OnShow == true)
	{
		gInterface.Data[eCONFIRM_MAIN].OnShow = false;
	}

	if ((GetTickCount() - gInterface.Data[eCONFIRM_MUUNBTN_OK].EventTick) < 100)
	{
		gInterface.Data[eCONFIRM_MUUN].OnShow = false;
	}

	if ((GetTickCount() - gInterface.Data[eCONFIRM_MUUNBTN_CANCEL].EventTick) < 100)
	{
		gInterface.Data[eCONFIRM_MUUN].OnShow = false;
	}

	if (!gInterface.Data[eCONFIRM_MUUN].OnShow || TypeConfirmBox == 0)
	{
		return;
	}

	float StartX;
	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		StartX = 205.0f;
	}
	else
	{
		StartX = 25.0f;
	}

	float MainWidth = 230.0;
	float MainHeight = 130.0;
	float StartBody = 90.0;
	float StartY = 90.0;

	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	gInterface.DrawFormat(eRed2, (int)StartX + 10, (int)StartBody + 10, 210, 3, "=== Owner ===");

	if (TypeConfirmBox == 1)
	{
		gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, "Are you sure, sell this Item owner ??");
	}
	 else
	 {
		 gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, "Are you sure, throw this Item master ??");
	 }


	gInterface.DrawButton(eCONFIRM_MUUNBTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, 0);

	if (gInterface.IsWorkZone(eCONFIRM_MUUNBTN_OK))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[eCONFIRM_MUUNBTN_OK].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawButton(eCONFIRM_MUUNBTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, ScaleY);
		if (GetKeyState(1) & 0x8000)
		{
			if (TypeConfirmBox == 1)
			{
				g_MuunSystem.SendRequestSellItem(CONFIRMSlot);
			} 
			if (TypeConfirmBox == 2)
			{
				g_MuunSystem.SendRequestDropItem(CONFIRMSlot, CONFIRMSlotX, CONFIRMSlotY);
				DeletePickedItem();
				MouseUpdateTime = 0;
				MouseUpdateTimeMax = 6;
				ResetMouseLButton();
			}
			//pDrawMessage("OK", 1);
			TypeConfirmBox = 0;
			gInterface.Data[eCONFIRM_MUUNBTN_OK].EventTick = GetTickCount();
			gInterface.Data[eCONFIRM_MUUN].OnShow = false;
			CONFIRMSlot = -1;
			CONFIRMSlotX = -1;
			CONFIRMSlotY = -1;
		}
	}

	gInterface.DrawButton(eCONFIRM_MUUNBTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, 0);

	if (gInterface.IsWorkZone(eCONFIRM_MUUNBTN_CANCEL))
	{
		int ScaleY = 30;
		// ----
		if (gInterface.Data[eCONFIRM_MUUNBTN_CANCEL].OnClick)
		{
			ScaleY = 60;
		}
		// ----
		gInterface.DrawButton(eCONFIRM_MUUNBTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, ScaleY);

		if (GetKeyState(1) & 0x8000)
		{
			//pDrawMessage("Canel", 1);
			TypeConfirmBox = 0;
			gInterface.Data[eCONFIRM_MUUNBTN_CANCEL].EventTick = GetTickCount();
			gInterface.Data[eCONFIRM_MUUN].OnShow = false;
			CONFIRMSlot = -1;
			CONFIRMSlotX = -1;
			CONFIRMSlotY = -1;
		}
	}
}

bool movemuuntomuun()
{
	int v4; // eax@2
	ITEM * iTemp; // eax@2

	if (g_MuunSystem.InventoryCTRLStatus == 1)
	{
		if (g_MuunSystem.back.UpdateMouseEvent() == 1)
		{
			if (g_MuunSystem.PageID > 0)
			{
				g_MuunSystem.PageID--;
			}
			return 1;
		}
		if (g_MuunSystem.next.UpdateMouseEvent() == 1)
		{
			if (g_MuunSystem.PageID < 2)
			{
				g_MuunSystem.PageID++;
			}
			return 1;
		}
		if (g_MuunSystem.CheckMuunInventoryOver())
		{
			if (gInterface.CheckWindow(ObjWindow::Shop) && IsPress(VK_RBUTTON))
			{
				if (ItemOverTooltip != -1)
				{
					//gInterface.DrawMessage(1, "Check Shop %d", ItemOverTooltip);
					CONFIRMSlot = ItemOverTooltip;
					TypeConfirmBox = 1;
					gInterface.Data[eCONFIRM_MUUN].OnShow = true;

					ItemOverTooltip = -1;
					
					return 1;
				}
			}
			if (IsPress(VK_LBUTTON))
			{
				if (!GetPickedItem() || (v4 = GetPickedItem(), (iTemp = GetMouseItem(v4)) == 0))
				{
					int MuunSlot = ItemOverTooltip;

					if (MuunSlot != -1)
					{
						if (SetPickItem(0, g_MuunSystem.FindItemBySlot(MuunSlot)))
						{
							SlotPickBackup = ItemOverTooltip;
							g_MuunSystem.DelInventoryCTRL(MuunSlot);
						}
					}
				}
				else
				{
					if (SlotOverSelect != -1 && SlotOverSelect == SlotPickBackup)
					{
						ITEM* iTemp = CreateItemPick(GetMouseItem(GetPickedItem()));

						if (NULL != iTemp)
						{
							g_MuunSystem.AddInventoryCtrl(iTemp, SlotPickBackup);
							DeletePickedItem();
							SlotPickBackup = -1;
							return 1;
						}
					}
					else if (SlotOverSelect != -1)
					{
						if (ms_pPickedItem)
						{
							ITEM* pickTemp = GetMouseItem(GetPickedItem());

							if (g_MuunSystem.FindItemBySlot(SlotOverSelect))
							{
								if (pickTemp->Type == ITEMDEF(13, 211))
								{
									g_MuunSystem.SendRequestUsedItem(SlotPickBackup, SlotOverSelect, 2);
								}
								else
								{
									g_MuunSystem.SendRequestUsedItem(SlotPickBackup, SlotOverSelect, 1);
								}
							}
							else
							{
								SendRequestEquipmentItem(22, SlotPickBackup, pickTemp, 22, SlotOverSelect);
							}
						}
					}
				}
				
			}
			/*else if (GetKeyInstance(VK_RBUTTON))
			{
			if (!GetPickedItem() || (v4 = GetPickedItem(), (iTemp = GetItem(v4)) == 0))
			{
			if( ItemOverTooltip != -1 )
			{
			SlotPickBackup = ItemOverTooltip;

			if (SlotPickBackup >= 2)
			{
			if (g_MuunSystem.g_SlotEquip(EQUIPMENT_MAIN_INDEX) == -1)
			{
			SendRequestEquipmentItem(22, SlotPickBackup, g_MuunSystem.FindItemBySlot(SlotPickBackup), 22, EQUIPMENT_MAIN_INDEX);
			//g_MuunSystem.DelMuunSlotInventoryCTRL(SlotPickBackup);
			}
			else if (g_MuunSystem.g_SlotEquip(EQUIPMENT_SUB_INDEX) == -1)
			{
			SendRequestEquipmentItem(22, SlotPickBackup, g_MuunSystem.FindItemBySlot(SlotPickBackup), 22, EQUIPMENT_SUB_INDEX);
			//g_MuunSystem.DelMuunSlotInventoryCTRL(SlotPickBackup);
			}
			}
			else
			{
			int targetslot = g_MuunSystem.GetSourceSlotEmpty();

			if (targetslot >= 2)
			{
			SendRequestEquipmentItem(22, SlotPickBackup, g_MuunSystem.FindItemBySlot(SlotPickBackup), 22, targetslot);
			}
			}
			}
			}
			}*/
			return 1;
		}
		else
		{

			if (IsPress(VK_LBUTTON) && SlotPickBackup != -1)
			{
				RenderTerrain(true);
				if (RenderTerrainTile(SelectXF, SelectYF, (int)SelectXF, (int)SelectYF, 1.f, 1, true))
				{
					int tx = (int)(CollisionPosition_1 / TERRAIN_SCALE);
					int ty = (int)(CollisionPosition_2 / TERRAIN_SCALE);

					if (ms_pPickedItem)
					{
						ITEM* iTemp = CreateItemPick(GetMouseItem(GetPickedItem()));

						if (NULL != iTemp)
						{

							//CharToString(&strID_1, "");
							//CharToString(&strText_1, GlobalText(GlobalLine, 269));
							//ChatLogWindowAddText(g_pChatListBox(g_pNewUISystem()), &strID_1, &strText_1, 4, 0);
							//g_MuunSystem.SendRequestDropItem(SlotPickBackup, tx, ty);

							CONFIRMSlot = SlotPickBackup;
							CONFIRMSlotX = tx;
							CONFIRMSlotY = ty;
							TypeConfirmBox = 2;
							gInterface.Data[eCONFIRM_MUUN].OnShow = true;
							//g_MuunSystem.g_MuunAddInventoryCtrl(iTemp, SlotPickBackup);
							//DeletePickedItem();
							////pDrawMessage("Drop Muun", 1);
							////SlotPickBackup = -1;
							//
							//MouseUpdateTime = 0;
							//MouseUpdateTimeMax = 6;
							//
							//ResetMouseLButton();
							return 1;
						}
					}
					
				}		
				SlotPickBackup = -1;
				return 1;
			}
		}
	}
	return 0;
}

bool CNewUIMyInventory::UpdateMouseEvent()
{
	if (g_MuunSystem.PageID < 0)
	{
		g_MuunSystem.PageID = 0;
	}
	if (g_MuunSystem.PageID > 2)
	{
		g_MuunSystem.PageID = 2;
	}

	return movemuuntomuun();
}

int CNewUIMyInventory::MoveToInvetoryMuun(int Packet, int Engine)
{
	BYTE TargetFlag = *(BYTE *)(Packet + 3);
	BYTE dwKey = *(BYTE *)(Packet + 4);
	*(BYTE*)0x81F6BEF = 0;

	if (TargetFlag == 22)
	{
		ITEM* pTempItem = CreateItemConvertByte(*(DWORD *)(g_pNewUISystem() + 36), (void *)(Packet + 5));

		if (NULL != pTempItem)
		{
			if (dwKey != SlotPickBackup)
			{
				g_MuunSystem.DelInventoryCTRL(SlotPickBackup);
				SlotPickBackup = -1;
				DeletePickedItem();
				g_MuunSystem.AddInventoryCtrl(pTempItem, dwKey);
			}
			return 1;
		}
	}
	else if (TargetFlag == 0xFF) //-- no pudo mover el item
	{
		if (g_MuunSystem.InventoryCTRLStatus == 1 && g_MuunSystem.CheckMuunInventoryOver())
		{
			if (SlotPickBackup != -1)
			{
				if (ms_pPickedItem)
				{
					ITEM* iTemp = CreateItemPick(GetMouseItem(GetPickedItem()));

					if (NULL != iTemp)
					{
						g_MuunSystem.AddInventoryCtrl(iTemp, SlotPickBackup);
						DeletePickedItem();
						SlotPickBackup = -1;

						/*std::string strID;
						std::string strText;
						CharToString(&strID, "");
						CharToString(&strText, "error no puede equipar este item");
						ChatLogWindowAddText(g_pChatListBox(g_pNewUISystem()), &strID, &strText, TYPE_ERROR_MESSAGE, 0);*/
						return 1;
					}
				}
				SlotPickBackup = -1;
				return 1;
			}
		}
	}
	return MoveToFromRecv(Packet, Engine);
}

bool __thiscall CNewUIMyInventory::InventoryProcess(int thisa)
{
	if (GetPickedItem())
	{
		
		ITEM* pickTemp = GetMouseItem(GetPickedItem());

		if (pickTemp)
		{
			if (pickTemp->Type == 7184)
			{
				if (g_MuunSystem.InventoryCTRLStatus == 1 && g_MuunSystem.CheckMuunInventoryOver())
				{
					int TargetSlot = ItemOverTooltip;

					if (IsPress(VK_LBUTTON) && TargetSlot != -1 && TargetSlot >= 1)
					{
						if (g_MuunSystem.FindItemBySlot(TargetSlot))
						{
							g_MuunSystem.SendRequestUsedItem(GetSourceLinealPos(GetPickedItem()) + 12, TargetSlot, 3);
							return true;
						}
					}
				}
			}
			else if (gCustomPet2.GetInfoPetType(pickTemp->Type) == 8)
			{
				return movemuuntomuun();
			}
		}
		
	}

	return CInventoryProcess(thisa);
}

BYTE CNewUIMyInventory::RenderEquipedMuunLife(int iX, int iY, int Slot)
{
	BYTE t = 0;
	ITEM* pNewItem = g_MuunSystem.FindItemBySlot(Slot);

	if (pNewItem != NULL)
	{
		ITEM_ATTRIBUTE Attribute = *(ITEM_ATTRIBUTE*)(pItem_Attribute + 84 * pNewItem->Type);

		PetMuunHP(1, iY, (int)&Attribute.Name, pNewItem->Durability, 255, 0);
		t = 1;
	}

	return t;
}

BYTE CNewUIMyInventory::PetEquipedHPBar(int iX, int iY)
{
	char result;
	
	int PetHP;

	int PetSlot = *(WORD*)(Hero + 556);
	int type = gCustomPet2.GetInfoPetType(PetSlot - 1171);

	if ((PetSlot < 7827 || PetSlot > 7831)
		&& PetSlot != 7891
		&& PetSlot != 7892
		&& PetSlot != 7894
		&& PetSlot != 7907
		&& PetSlot != 7933
		&& PetSlot != 7950
		&& PetSlot != 7864
		&& (type == 8 || type == -1))
	{
		result = 0;
	}
	else
	{
		ITEM_ATTRIBUTE Attribute = *(ITEM_ATTRIBUTE*)(pItem_Attribute + 84 * (*(WORD *)(Hero + 556) - 1171));
		char PetName[255] = { 0, };
		switch (PetSlot)
		{
		case 7827:
			wsprintf(PetName, GlobalText(GlobalLine, 353));
			break;
		case 7828:
			wsprintf(PetName, Attribute.Name);//(char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		case 7829:
			wsprintf(PetName, GlobalText(GlobalLine, 355));
			break;
		case 7830:
			wsprintf(PetName, GlobalText(GlobalLine, 354));
			break;
		case 7831:
			wsprintf(PetName, GlobalText(GlobalLine, 1187));
			break;
		case 7864:
			wsprintf(PetName, GlobalText(GlobalLine, 1916));
			break;
		case 7891:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7892:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7894:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7907:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7933:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7950:
			wsprintf(PetName, Attribute.Name);
			break;
		default:
			wsprintf(PetName, Attribute.Name);
			break;
		}

		PetHP = *(BYTE*)(oUserObjectStruct_ + 5550);
		PetMuunHP(1, iY, (int)&PetName, PetHP, 255, 0);

		result = 1;
	}

	return result;
}




void __thiscall CNewUIMyInventory::CRenderInterfaceLeft(int thisa)
{
	POINT g_dir; // eax@9

	g_dir.x = *(DWORD *)(thisa + 16);
	g_dir.y = *(DWORD *)(thisa + 20);

	if (Defineclass(*(BYTE *)(Hero + 19)) == 2 && RenderNumArrow(thisa, g_dir.x, g_dir.y))
	{
		g_dir.y += 11;
	}
	if (g_MuunSystem.PetEquipedHPBar(g_dir.x, g_dir.y))
	{
		g_dir.y += 24;
	}
	if (Defineclass(*(BYTE *)(Hero + 19)) == 4 && RenderEquipedPetLife(thisa, g_dir.x, g_dir.y))
	{
		g_dir.y += 24;
	}
	if (g_MuunSystem.RenderEquipedMuunLife(g_dir.x, g_dir.y, 0))
	{
		g_dir.y += 24;
	}
	if (g_MuunSystem.RenderEquipedMuunLife(g_dir.x, g_dir.y, 1))
	{
		g_dir.y += 24;
	}
	if (Defineclass(*(BYTE *)(Hero + 19)) == 2)
	{
		if (RenderSummonMonsterLife(thisa, g_dir.x, g_dir.y))
			g_dir.y += 24;
	};
}


void CNewUIMyInventory::Init()
{


	SetCompleteHook(0xE9, 0x005012D0, &CNewUIMyInventory::DelectPetBug);
	//--
	SetCompleteHook(0xE8, 0x0080F250, &CNewUIMyInventory::LoadImages);
	SetCompleteHook(0xE9, 0x007DF740, &CNewUIMyInventory::UpdateKeyEvent); //-- Controll KeyPress
	SetCompleteHook(0xE8, 0x007DF34C, &CNewUIMyInventory::UpdateMouseEvent); //-- Controll MouseEvnt
	SetCompleteHook(0xE8, 0x0066424B, &CNewUIMyInventory::MoveToInvetoryMuun); //-- visualizar slot Recv
	SetCompleteHook(0xE8, 0x00833731, &CNewUIMyInventory::CreateInventoryUICTRL);
	//--
	SetCompleteHook(0xE8, 0x007DF846, &CNewUIMyInventory::CRenderInterfaceRight);
	SetCompleteHook(0xE8, 0x007DF83E, &CNewUIMyInventory::CRenderInterfaceLeft);
	//--
	SetCompleteHook(0xE8, 0x0083469C, &CNewUIMyInventory::InventoryProcess); //-- recoverylife
}
