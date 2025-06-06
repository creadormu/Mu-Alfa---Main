#include "stdafx.h"
#include "Offset.h"
#include "Import.h"
#include "Defines.h"
#include "Interface.h"
#include "TMemory.h"
#include "CustomNPC.h"
#include "Object.h"
#include "Protect.h"
#include "Pet.h"

NPC gNPC;


void NPC::Load() {
	if(gProtect.m_MainInfo.CustomElfSoldier == 1){
        SetRange((LPVOID)0x0057FCCF, 5, ASM::NOP);
        SetOp((LPVOID)0x0057FCCF, (LPVOID) this->ElfSoldier, ASM::JMP);
	}
	if(gProtect.m_MainInfo.CustomMarlon == 1){
        SetRange((LPVOID)0x005842B1, 5, ASM::NOP);
        SetOp((LPVOID)0x005842B1, (LPVOID) this->Marlon, ASM::JMP);
	}
	if(gProtect.m_MainInfo.CustomChaosCard == 1){
        SetRange((LPVOID)0x005852E4, 5, ASM::NOP);
        SetOp((LPVOID)0x005852E4, (LPVOID) this->ChaosCardMaster, ASM::JMP);
	}
	if(gProtect.m_MainInfo.CustomGuard1 == 1){
        SetRange((LPVOID)0x00584A4E, 5, ASM::NOP);
        SetOp((LPVOID)0x00584A4E, (LPVOID) this->Guard1, ASM::JMP);
	}
	if(gProtect.m_MainInfo.CustomGuard2 == 1){
        SetRange((LPVOID)0x00584B82, 5, ASM::NOP);
        SetOp((LPVOID)0x00584B82, (LPVOID) this->Guard2, ASM::JMP);
	}
	if(gProtect.m_MainInfo.CustomCursedWizard == 1){
		SetRange((LPVOID)0x00582FE6, 5, ASM::NOP);
	    SetOp((LPVOID)0x00582FE6, (LPVOID) this->CursedWizard, ASM::JMP);
	}
	if(gProtect.m_MainInfo.CustomLeoHelper == 1){
	SetRange((LPVOID)0x005851D8, 5, ASM::NOP);
	SetOp((LPVOID)0x005851D8, (LPVOID) this->LuckLeoTheHelper, ASM::JMP);
	}
}
// ----------------------------------------------------------------------------------------------

Naked(NPC::ElfSoldier) {
   static ObjectPreview * gPreview;
   //----
   _asm {
      MOV ECX, DWORD PTR SS : [EBP + 0x08]
      MOV gPreview, ECX
   }
   // ----
   gPreview->HelmSlot = ITEM2(7, gProtect.m_MainInfo.CustomElfSoldierHelm);
   gPreview->ArmorSlot = ITEM2(8, gProtect.m_MainInfo.CustomElfSoldierArmor);
   gPreview->PantsSlot = ITEM2(9, gProtect.m_MainInfo.CustomElfSoldierPants);
   gPreview->GlovesSlot = ITEM2(10, gProtect.m_MainInfo.CustomElfSoldierGloves);
   gPreview->BootsSlot = ITEM2(11, gProtect.m_MainInfo.CustomElfSoldierBoots);
   gPreview->WeaponFirstSlot = ITEM2(gProtect.m_MainInfo.CustomTypeElfSoldierWeapon1, gProtect.m_MainInfo.CustomElfSoldierWeapon1);
   gPreview->WeaponSecondSlot = ITEM2(gProtect.m_MainInfo.CustomTypeElfSoldierWeapon2, gProtect.m_MainInfo.CustomElfSoldierWeapon2);
   gPreview->WingsSlot = ITEM2(12, gProtect.m_MainInfo.CustomElfSoldierWings);

   // ----
   gPreview->HelmLevel = gProtect.m_MainInfo.CustomElfSoldierHelmLevel;
   gPreview->ArmorLevel = gProtect.m_MainInfo.CustomElfSoldierArmorLevel;
   gPreview->PantsLevel = gProtect.m_MainInfo.CustomElfSoldierPantsLevel;
   gPreview->GlovesLevel = gProtect.m_MainInfo.CustomElfSoldierGlovesLevel;
   gPreview->BootsLevel = gProtect.m_MainInfo.CustomElfSoldierBootsLevel;
   gPreview->WeaponFirstLevel = gProtect.m_MainInfo.CustomElfSoldierWeaponFirstLevel;
   gPreview->WeaponSecondLevel = gProtect.m_MainInfo.CustomElfSoldierWeaponSecondLevel;
   // ----
   gPreview->HelmExcellent = gProtect.m_MainInfo.CustomElfSoldierHelmExcellent;
   gPreview->ArmorExcellent = gProtect.m_MainInfo.CustomElfSoldierArmorExcellent;
   gPreview->PantsExcellent = gProtect.m_MainInfo.CustomElfSoldierPantsExcellent;
   gPreview->GlovesExcellent = gProtect.m_MainInfo.CustomElfSoldierGlovesExcellent;
   gPreview->BootsExcellent = gProtect.m_MainInfo.CustomElfSoldierBootsExcellent;
   gPreview->WeaponFirstExcellent = gProtect.m_MainInfo.CustomElfSoldierWeaponFirstExcellent;
   gPreview->WeaponSecondExcellent = gProtect.m_MainInfo.CustomElfSoldierWeaponSecondExcellent;
   // ----
   _asm {
      MOV ECX, 0x0057FD5B
      JMP ECX
   }
}
// ----------------------------------------------------------------------------------------------

Naked(NPC::Marlon) {
   static ObjectPreview * gPreview;
   //----
   _asm {
      MOV ECX, DWORD PTR SS : [EBP - 0x14]
      MOV gPreview, ECX
   }
   // ----
   gPreview->HelmSlot = ITEM2(7, gProtect.m_MainInfo.CustomMarlonHelm);
   gPreview->ArmorSlot = ITEM2(8, gProtect.m_MainInfo.CustomMarlonArmor);
   gPreview->PantsSlot = ITEM2(9, gProtect.m_MainInfo.CustomMarlonPants);
   gPreview->GlovesSlot = ITEM2(10, gProtect.m_MainInfo.CustomMarlonGloves);
   gPreview->BootsSlot = ITEM2(11, gProtect.m_MainInfo.CustomMarlonBoots);
   gPreview->WeaponFirstSlot = ITEM2(gProtect.m_MainInfo.CustomTypeMarlonWeapon1, gProtect.m_MainInfo.CustomMarlonWeapon1);
   gPreview->WeaponSecondSlot = ITEM2(gProtect.m_MainInfo.CustomTypeMarlonWeapon2, gProtect.m_MainInfo.CustomMarlonWeapon2);
   gPreview->WingsSlot = ITEM2(12, gProtect.m_MainInfo.CustomMarlonWings);
   // ----
   gPreview->HelmLevel = gProtect.m_MainInfo.CustomMarlonHelmLevel;
   gPreview->ArmorLevel = gProtect.m_MainInfo.CustomMarlonArmorLevel;
   gPreview->PantsLevel = gProtect.m_MainInfo.CustomMarlonPantsLevel;
   gPreview->GlovesLevel = gProtect.m_MainInfo.CustomMarlonGlovesLevel;
   gPreview->BootsLevel = gProtect.m_MainInfo.CustomMarlonBootsLevel;
   gPreview->WeaponFirstLevel = gProtect.m_MainInfo.CustomMarlonWeaponFirstLevel;
   gPreview->WeaponSecondLevel = gProtect.m_MainInfo.CustomMarlonWeaponSecondLevel;
   // ----
   gPreview->HelmExcellent = gProtect.m_MainInfo.CustomMarlonHelmExcellent;
   gPreview->ArmorExcellent = gProtect.m_MainInfo.CustomMarlonArmorExcellent;
   gPreview->PantsExcellent = gProtect.m_MainInfo.CustomMarlonPantsExcellent;
   gPreview->GlovesExcellent = gProtect.m_MainInfo.CustomMarlonGlovesExcellent;
   gPreview->BootsExcellent = gProtect.m_MainInfo.CustomMarlonBootsExcellent;
   gPreview->WeaponFirstExcellent = gProtect.m_MainInfo.CustomMarlonWeaponFirstExcellent;
   gPreview->WeaponSecondExcellent = gProtect.m_MainInfo.CustomMarlonWeaponSecondExcellent;
   // ----
   _asm {
      MOV ECX, 0x00584354
      JMP ECX
   }
}
// ----------------------------------------------------------------------------------------------

Naked(NPC::ChaosCardMaster) {
   static ObjectPreview * gPreview;
   //----
   _asm {
      MOV ECX, DWORD PTR SS : [EBP - 0x14]
      MOV gPreview, ECX
   }
   // ----
   gPreview->HelmSlot = ITEM2(7, gProtect.m_MainInfo.CustomChaosCardHelm);
   gPreview->ArmorSlot = ITEM2(8, gProtect.m_MainInfo.CustomChaosCardArmor);
   gPreview->PantsSlot = ITEM2(9, gProtect.m_MainInfo.CustomChaosCardPants);
   gPreview->GlovesSlot = ITEM2(10, gProtect.m_MainInfo.CustomChaosCardGloves);
   gPreview->BootsSlot = ITEM2(11, gProtect.m_MainInfo.CustomChaosCardBoots);
   gPreview->WeaponFirstSlot = ITEM2(gProtect.m_MainInfo.CustomTypeChaosCardWeapon1, gProtect.m_MainInfo.CustomChaosCardWeapon1);
   gPreview->WeaponSecondSlot = ITEM2(gProtect.m_MainInfo.CustomTypeChaosCardWeapon2, gProtect.m_MainInfo.CustomChaosCardWeapon2);
   gPreview->WingsSlot = ITEM2(12, gProtect.m_MainInfo.CustomChaosCardWings);
   // ----
   gPreview->HelmLevel = gProtect.m_MainInfo.CustomChaosCardHelmLevel;
   gPreview->ArmorLevel = gProtect.m_MainInfo.CustomChaosCardArmorLevel;
   gPreview->PantsLevel = gProtect.m_MainInfo.CustomChaosCardPantsLevel;
   gPreview->GlovesLevel = gProtect.m_MainInfo.CustomChaosCardGlovesLevel;
   gPreview->BootsLevel = gProtect.m_MainInfo.CustomChaosCardBootsLevel;
   gPreview->WeaponFirstLevel = gProtect.m_MainInfo.CustomChaosCardWeaponFirstLevel;
   gPreview->WeaponSecondLevel = gProtect.m_MainInfo.CustomChaosCardWeaponSecondLevel;
   // ----
   gPreview->HelmExcellent = gProtect.m_MainInfo.CustomChaosCardHelmExcellent;
   gPreview->ArmorExcellent = gProtect.m_MainInfo.CustomChaosCardArmorExcellent;
   gPreview->PantsExcellent = gProtect.m_MainInfo.CustomChaosCardPantsExcellent;
   gPreview->GlovesExcellent = gProtect.m_MainInfo.CustomChaosCardGlovesExcellent;
   gPreview->BootsExcellent = gProtect.m_MainInfo.CustomChaosCardBootsExcellent;
   gPreview->WeaponFirstExcellent = gProtect.m_MainInfo.CustomChaosCardWeaponFirstExcellent;
   gPreview->WeaponSecondExcellent = gProtect.m_MainInfo.CustomChaosCardWeaponSecondExcellent;
   // ----
   _asm {
      MOV ECX, 0x00585390
      JMP ECX
   }
}
// ----------------------------------------------------------------------------------------------

Naked(NPC::Guard1) {
   static ObjectPreview * gPreview;
   //----
   _asm {
      MOV ECX, DWORD PTR SS : [EBP - 0x14]
      MOV gPreview, ECX
   }
   // ----
   gPreview->HelmSlot = ITEM2(7, gProtect.m_MainInfo.CustomGuard1Helm);
   gPreview->ArmorSlot = ITEM2(8, gProtect.m_MainInfo.CustomGuard1Armor);
   gPreview->PantsSlot = ITEM2(9, gProtect.m_MainInfo.CustomGuard1Pants);
   gPreview->GlovesSlot = ITEM2(10, gProtect.m_MainInfo.CustomGuard1Gloves);
   gPreview->BootsSlot = ITEM2(11, gProtect.m_MainInfo.CustomGuard1Boots);
   gPreview->WeaponFirstSlot = ITEM2(gProtect.m_MainInfo.CustomTypeGuard1Weapon1, gProtect.m_MainInfo.CustomGuard1Weapon1);
   gPreview->WeaponSecondSlot = ITEM2(gProtect.m_MainInfo.CustomTypeGuard1Weapon2, gProtect.m_MainInfo.CustomGuard1Weapon2);
   gPreview->WingsSlot = ITEM2(12, gProtect.m_MainInfo.CustomGuard1Wings);
   // ----
   gPreview->HelmLevel = gProtect.m_MainInfo.CustomGuard1HelmLevel;
   gPreview->ArmorLevel = gProtect.m_MainInfo.CustomGuard1ArmorLevel;
   gPreview->PantsLevel = gProtect.m_MainInfo.CustomGuard1PantsLevel;
   gPreview->GlovesLevel = gProtect.m_MainInfo.CustomGuard1GlovesLevel;
   gPreview->BootsLevel = gProtect.m_MainInfo.CustomGuard1BootsLevel;
   gPreview->WeaponFirstLevel = gProtect.m_MainInfo.CustomGuard1WeaponFirstLevel;
   gPreview->WeaponSecondLevel = gProtect.m_MainInfo.CustomGuard1WeaponSecondLevel;
   // ----
   gPreview->HelmExcellent = gProtect.m_MainInfo.CustomGuard1HelmExcellent;
   gPreview->ArmorExcellent = gProtect.m_MainInfo.CustomGuard1ArmorExcellent;
   gPreview->PantsExcellent = gProtect.m_MainInfo.CustomGuard1PantsExcellent;
   gPreview->GlovesExcellent = gProtect.m_MainInfo.CustomGuard1GlovesExcellent;
   gPreview->BootsExcellent = gProtect.m_MainInfo.CustomGuard1BootsExcellent;
   gPreview->WeaponFirstExcellent = gProtect.m_MainInfo.CustomGuard1WeaponFirstExcellent;
   gPreview->WeaponSecondExcellent = gProtect.m_MainInfo.CustomGuard1WeaponSecondExcellent;
   gPreview->Class = SoulMaster;
   // ----
   _asm {
      MOV ECX, 0x00584AB7
      JMP ECX
   }
}
// ----------------------------------------------------------------------------------------------

Naked(NPC::Guard2) {
   static ObjectPreview * gPreview;
   //----
   _asm {
      MOV ECX, DWORD PTR SS : [EBP - 0x14]
      MOV gPreview, ECX
   }
   // ----
   gPreview->HelmSlot = ITEM2(7, gProtect.m_MainInfo.CustomGuard2Helm);
   gPreview->ArmorSlot = ITEM2(8, gProtect.m_MainInfo.CustomGuard2Armor);
   gPreview->PantsSlot = ITEM2(9, gProtect.m_MainInfo.CustomGuard2Pants);
   gPreview->GlovesSlot = ITEM2(10, gProtect.m_MainInfo.CustomGuard2Gloves);
   gPreview->BootsSlot = ITEM2(11, gProtect.m_MainInfo.CustomGuard2Boots);
   gPreview->WeaponFirstSlot = ITEM2(gProtect.m_MainInfo.CustomTypeGuard2Weapon1, gProtect.m_MainInfo.CustomGuard2Weapon1);
   gPreview->WeaponSecondSlot = ITEM2(gProtect.m_MainInfo.CustomTypeGuard2Weapon2, gProtect.m_MainInfo.CustomGuard2Weapon2);
   gPreview->WingsSlot = ITEM2(12, gProtect.m_MainInfo.CustomGuard2Wings);
   // ----
   gPreview->HelmLevel = gProtect.m_MainInfo.CustomGuard2HelmLevel;
   gPreview->ArmorLevel = gProtect.m_MainInfo.CustomGuard2ArmorLevel;
   gPreview->PantsLevel = gProtect.m_MainInfo.CustomGuard2PantsLevel;
   gPreview->GlovesLevel = gProtect.m_MainInfo.CustomGuard2GlovesLevel;
   gPreview->BootsLevel = gProtect.m_MainInfo.CustomGuard2BootsLevel;
   gPreview->WeaponFirstLevel = gProtect.m_MainInfo.CustomGuard2WeaponFirstLevel;
   gPreview->WeaponSecondLevel = gProtect.m_MainInfo.CustomGuard2WeaponSecondLevel;
   // ----
   gPreview->HelmExcellent = gProtect.m_MainInfo.CustomGuard2HelmExcellent;
   gPreview->ArmorExcellent = gProtect.m_MainInfo.CustomGuard2ArmorExcellent;
   gPreview->PantsExcellent = gProtect.m_MainInfo.CustomGuard2PantsExcellent;
   gPreview->GlovesExcellent = gProtect.m_MainInfo.CustomGuard2GlovesExcellent;
   gPreview->BootsExcellent = gProtect.m_MainInfo.CustomGuard2BootsExcellent;
   gPreview->WeaponFirstExcellent = gProtect.m_MainInfo.CustomGuard2WeaponFirstExcellent;
   gPreview->WeaponSecondExcellent = gProtect.m_MainInfo.CustomGuard2WeaponSecondExcellent;
   gPreview->Class = BladeMaster;
   // ----
   _asm {
      MOV ECX, 0x00584BDC
      JMP ECX
   }
}
// ----------------------------------------------------------------------------------------------

Naked(NPC::CursedWizard) {
	static ObjectPreview * gPreview;
	//----
	_asm {
		MOV ECX, DWORD PTR SS : [EBP - 0x14]
		MOV gPreview, ECX
	}
	// ----
   gPreview->HelmSlot = ITEM2(7, gProtect.m_MainInfo.CustomCursedWizardHelm);
   gPreview->ArmorSlot = ITEM2(8, gProtect.m_MainInfo.CustomCursedWizardArmor);
   gPreview->PantsSlot = ITEM2(9, gProtect.m_MainInfo.CustomCursedWizardPants);
   gPreview->GlovesSlot = ITEM2(10, gProtect.m_MainInfo.CustomCursedWizardGloves);
   gPreview->BootsSlot = ITEM2(11, gProtect.m_MainInfo.CustomCursedWizardBoots);
   gPreview->WeaponFirstSlot = ITEM2(gProtect.m_MainInfo.CustomTypeCursedWizardWeapon1, gProtect.m_MainInfo.CustomCursedWizardWeapon1);
   gPreview->WeaponSecondSlot = ITEM2(gProtect.m_MainInfo.CustomTypeCursedWizardWeapon2, gProtect.m_MainInfo.CustomCursedWizardWeapon2);
   gPreview->WingsSlot = ITEM2(12, gProtect.m_MainInfo.CustomCursedWizardWings);
   // ----
   gPreview->HelmLevel = gProtect.m_MainInfo.CustomCursedWizardHelmLevel;
   gPreview->ArmorLevel = gProtect.m_MainInfo.CustomCursedWizardArmorLevel;
   gPreview->PantsLevel = gProtect.m_MainInfo.CustomCursedWizardPantsLevel;
   gPreview->GlovesLevel = gProtect.m_MainInfo.CustomCursedWizardGlovesLevel;
   gPreview->BootsLevel = gProtect.m_MainInfo.CustomCursedWizardBootsLevel;
   gPreview->WeaponFirstLevel = gProtect.m_MainInfo.CustomCursedWizardWeaponFirstLevel;
   gPreview->WeaponSecondLevel = gProtect.m_MainInfo.CustomCursedWizardWeaponSecondLevel;
   // ----
   gPreview->HelmExcellent = gProtect.m_MainInfo.CustomCursedWizardHelmExcellent;
   gPreview->ArmorExcellent = gProtect.m_MainInfo.CustomCursedWizardArmorExcellent;
   gPreview->PantsExcellent = gProtect.m_MainInfo.CustomCursedWizardPantsExcellent;
   gPreview->GlovesExcellent = gProtect.m_MainInfo.CustomCursedWizardGlovesExcellent;
   gPreview->BootsExcellent = gProtect.m_MainInfo.CustomCursedWizardBootsExcellent;
   gPreview->WeaponFirstExcellent = gProtect.m_MainInfo.CustomCursedWizardWeaponFirstExcellent;
   gPreview->WeaponSecondExcellent = gProtect.m_MainInfo.CustomCursedWizardWeaponSecondExcellent;
	gPreview->Class = SoulMaster;
	// ----
	_asm {
		MOV ECX, 0x00583099
		JMP ECX
	}
}

// ----------------------------------------------------------------------------------------------
Naked(NPC::LuckLeoTheHelper) 
{
	static ObjectPreview * gPreview;
	//----
	_asm {
		MOV ECX, DWORD PTR SS : [EBP - 0x14]
		MOV gPreview, ECX
	}
	//
	gPreview->HelmSlot = ITEM2(7, gProtect.m_MainInfo.CustomLeoHelperHelm);
	gPreview->ArmorSlot	= ITEM2(8, gProtect.m_MainInfo.CustomLeoHelperArmor);
	gPreview->PantsSlot	= ITEM2(9, gProtect.m_MainInfo.CustomLeoHelperPants);
	gPreview->GlovesSlot = ITEM2(10, gProtect.m_MainInfo.CustomLeoHelperGloves);
	gPreview->BootsSlot	= ITEM2(11, gProtect.m_MainInfo.CustomLeoHelperBoots);
	gPreview->WingsSlot = ITEM2(12, gProtect.m_MainInfo.CustomLeoHelperWings);
	//
    gPreview->HelmLevel = gProtect.m_MainInfo.CustomLeoHelperHelmLevel;
    gPreview->ArmorLevel = gProtect.m_MainInfo.CustomLeoHelperArmorLevel;
    gPreview->PantsLevel = gProtect.m_MainInfo.CustomLeoHelperPantsLevel;
    gPreview->GlovesLevel = gProtect.m_MainInfo.CustomLeoHelperGlovesLevel;
    gPreview->BootsLevel = gProtect.m_MainInfo.CustomLeoHelperBootsLevel;

	//
    gPreview->HelmExcellent = gProtect.m_MainInfo.CustomLeoHelperHelmExcellent;
    gPreview->ArmorExcellent = gProtect.m_MainInfo.CustomLeoHelperArmorExcellent;
    gPreview->PantsExcellent = gProtect.m_MainInfo.CustomLeoHelperPantsExcellent;
    gPreview->GlovesExcellent = gProtect.m_MainInfo.CustomLeoHelperGlovesExcellent;
    gPreview->BootsExcellent = gProtect.m_MainInfo.CustomLeoHelperBootsExcellent;

	//
	gPreview->Class	= BladeKnight;
	//
	_asm {
		MOV ECX, 0x00585230
		JMP ECX
	}
}
