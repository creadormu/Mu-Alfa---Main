#include "stdafx.h"
#include "Protect.h"
#include "PetHook.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "TMemory.h"
#include "Pet.h"
#include "cape.h"

ObjCreateBug gObjCreateBug = (ObjCreateBug)0x00501700;
ObjCreatePet gObjCreatePet = (ObjCreatePet)0x00835E40;

void gObjCreatePetEx(int ItemId)
{
	int ItemSwitch = *(WORD*)ItemId;
	int PetPreview = LODWORD(pPreviewPetThis) + 776;
	int PetHP;
	PetHP = *(BYTE*)(oUserObjectStruct_ + 5550);

	if (ItemSwitch >= ITEM(13, 147) && ItemSwitch <= ITEM(13, 512))
	{
		if( PetHP > 0 )
		{
			gObjCreateBug(ItemSwitch + 1171, PetPreview + 252, PetPreview, 0, 0);
		}
	}
	
	if (gCloak.isCloak(ItemSwitch))
	{
		pRefreshViewport(oUserPreviewStruct, oUserPreviewStruct + 776, 0);
	}
	gObjCreatePet(ItemId);
}

//----- (00501330) --------------------------------------------------------
bool ResetPetPreviewEx(WORD *a1)
{
  bool result; // al@2

  if ( a1 )
  {
    result = *a1 == 6656 
	|| *a1 == 6657 
	|| *a1 == 6658 
	|| *a1 == 6659 
	|| *a1 == 6660 
	|| *a1 == 6661 
	|| *a1 == 6693 
	|| (*a1 >= ITEM(13, 200) && *a1 <= ITEM(13, 512) 
	|| gCloak.isCloak(*a1));
  }
  else
  {
    result = 0;
  }
  return result;
}

void gObjCreatePetExHook()
{
	SetOp((LPVOID)0x00836481, (LPVOID)ResetPetPreviewEx, ASM::CALL);
	SetOp((LPVOID)0x007DD304, (LPVOID)gObjCreatePetEx, ASM::CALL);
	SetOp((LPVOID)0x00833B08, (LPVOID)gObjCreatePetEx, ASM::CALL);
}