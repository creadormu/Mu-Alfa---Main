// Protect.h: interface for the CProtect class.
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomFog.h"
#include "CustomItem.h"
#include "CustomJewel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "ItemSmoke.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
//--
#include "CustomGloves.h"
#include "CustomBow.h"
#include "CustomPet.h"
#include "CustomCloak.h"
#include "ItemTRSData.h"
#include "CustomEffectRemake.h"
#include "ItemManager.h"
#include "CustomItemPrice.h"
#include "CustomMonsterGlow.h"
#include "ModelEffect.h"
#include "CustomPetEffect.h"
#include "SetEffect.h"
//--
#include "BuffIcon.h"
#include "cCPetRenderMesh.h"
#include "MultiSelect.h"
//--
#include "ItemTooltip.h"
#include "MonsterEffect.h"
#include "JCRendernoItemGlow.h"
#include "ItemGlow.h"
#include "LuckyWheels.h"
#include "CSmithItem.h"
#include "CustomNPC.h"

struct MAIN_FILE_INFO
{
	BYTE LauncherType; 
	char LauncherName[32];
	char CustomerName[32];
	char IpAddress[32];
	WORD IpAddressPort;
	char ClientVersion[8];
	char ClientSerial[17];
	char WindowName[32];
	char ScreenShotPath[50];
	char ClientName[32];
	char HackName[32];
	char PluginName5[32];
	char PluginName1[32];
	char PluginName2[32];
	char PluginName3[32];
	char PluginName4[32];
	char CameraName[32];
	char ServerNameA[32];
	char ServerNameB[32];
	char ServerNameC[32];
	char ServerNameD[32];
	DWORD ClientCRC32;
	DWORD HackCRC32;
	DWORD Plugin5CRC32;
	DWORD Plugin1CRC32;
	DWORD Plugin2CRC32;
	DWORD Plugin3CRC32;
	DWORD Plugin4CRC32;
	DWORD CameraCRC32;
	DWORD HelperActiveAlert;
	DWORD HelperActiveLevel;
	DWORD DWMaxAttackSpeed;
	DWORD DKMaxAttackSpeed;
	DWORD FEMaxAttackSpeed;
	DWORD MGMaxAttackSpeed;
	DWORD DLMaxAttackSpeed;
	DWORD SUMaxAttackSpeed;
	DWORD RFMaxAttackSpeed;
	DWORD ReconnectTime;
	DWORD ReduceMemory;
	DWORD RemoveClass;
	DWORD RankUserType;
	DWORD DisableTree; 
	DWORD CsSkill; 
	DWORD DisableReflectEffect;
	DWORD EnableVipShop;
	DWORD VipTypes;
	DWORD PrintLogo;
	DWORD CustomMenuSwitch;
	DWORD CustomMenuType;
	DWORD MenuButtons[10];
	DWORD EnableCoinStatus;
	DWORD EnableShopValueSystem;
	DWORD CustomStoreEnableJoB;
	DWORD CustomStoreEnableJoS;
	DWORD CustomStoreEnableJoC;
	DWORD CustomStoreEnableCoin1;
	DWORD CustomStoreEnableCoin2;
	DWORD CustomStoreEnableCoin3;
	DWORD CustomOffStoreEnable;
	DWORD CustomMonsterEnable;
	DWORD DisablePartyHpBar;
	DWORD RankUserShowOverHead;
	DWORD RankUserOnlyOnSafeZone;
	DWORD RankUserShowReset;
	DWORD RankUserShowMasterReset;
	DWORD RankUserNeedAltKey;
	//---
	DWORD CustomInterfaceType;
	DWORD CustomRemoveCoord;
	DWORD TIME_GMT;
	DWORD MonitorFPS;
	DWORD MonitorMS;
	DWORD LimitFPS;
	DWORD EffectPlus15;
	DWORD DisableGens;
	DWORD DisableTabMap;
	DWORD DisableHelper;
	DWORD DisableAdvance;
	DWORD DisableEffectRemake;
	DWORD DisableCustomClaws;
	DWORD DisableCustomBow;
	DWORD DisableCustomCloack;
	DWORD DisableCustomPosition;
	DWORD DisableCustomPet;
	DWORD DisableSocketInvetori;
	DWORD DisableRepeirInInventory;
	DWORD DisableButtonOpenStore;
	DWORD DisableButtonInventoryExt;
	DWORD DisableButtonQuestInStats;
	DWORD DisableButtonPetsInStats;
	DWORD DisableButtonSkillMaster;
	DWORD SelectCharAnimate;
	DWORD SelectCharS13;
	DWORD DisableAutoLogin;
	DWORD EnableLoading;
	DWORD EnableViewDetails;
	DWORD EnableFenrirSafeZone;
	DWORD EnableHorseSafeZone;
	DWORD EnableDinorantSafeZone;
	DWORD DisableEmojiSystem;
	DWORD InventoryUPGRADE;
	DWORD CameraZoom;
	//
		//--ElfSoldier
	DWORD CustomElfSoldier;
	DWORD CustomElfSoldierWings;
	DWORD CustomElfSoldierHelm;
	DWORD CustomElfSoldierArmor;
	DWORD CustomElfSoldierPants;
	DWORD CustomElfSoldierGloves;
	DWORD CustomElfSoldierBoots;
	DWORD CustomTypeElfSoldierWeapon1;
	DWORD CustomElfSoldierWeapon1;
	DWORD CustomTypeElfSoldierWeapon2;
	DWORD CustomElfSoldierWeapon2;
	DWORD CustomElfSoldierHelmLevel;
	DWORD CustomElfSoldierArmorLevel;
	DWORD CustomElfSoldierPantsLevel;
	DWORD CustomElfSoldierGlovesLevel;
	DWORD CustomElfSoldierBootsLevel;
	DWORD CustomElfSoldierWeaponFirstLevel;
	DWORD CustomElfSoldierWeaponSecondLevel;
	DWORD CustomElfSoldierHelmExcellent;
	DWORD CustomElfSoldierArmorExcellent;
	DWORD CustomElfSoldierPantsExcellent;
	DWORD CustomElfSoldierGlovesExcellent;
	DWORD CustomElfSoldierBootsExcellent;
	DWORD CustomElfSoldierWeaponFirstExcellent;
	DWORD CustomElfSoldierWeaponSecondExcellent;

	//--Marlon
	DWORD CustomMarlon;
	DWORD CustomMarlonWings;
	DWORD CustomMarlonHelm;
	DWORD CustomMarlonArmor;
	DWORD CustomMarlonPants;
	DWORD CustomMarlonGloves;
	DWORD CustomMarlonBoots;
	DWORD CustomMarlonWeapon1;
	DWORD CustomTypeMarlonWeapon1;
	DWORD CustomMarlonWeapon2;
	DWORD CustomTypeMarlonWeapon2;
	DWORD CustomMarlonHelmLevel;
	DWORD CustomMarlonArmorLevel;
	DWORD CustomMarlonPantsLevel;
	DWORD CustomMarlonGlovesLevel;
	DWORD CustomMarlonBootsLevel;
	DWORD CustomMarlonWeaponFirstLevel;
	DWORD CustomMarlonWeaponSecondLevel;
	DWORD CustomMarlonHelmExcellent;
	DWORD CustomMarlonArmorExcellent;
	DWORD CustomMarlonPantsExcellent;
	DWORD CustomMarlonGlovesExcellent;
	DWORD CustomMarlonBootsExcellent;
	DWORD CustomMarlonWeaponFirstExcellent;
	DWORD CustomMarlonWeaponSecondExcellent;

	//--ChaosCardMaster
	DWORD CustomChaosCard;
	DWORD CustomChaosCardWings;
	DWORD CustomChaosCardHelm;
	DWORD CustomChaosCardArmor;
	DWORD CustomChaosCardPants;
	DWORD CustomChaosCardGloves;
	DWORD CustomChaosCardBoots;
	DWORD CustomChaosCardWeapon1;
	DWORD CustomTypeChaosCardWeapon1;
	DWORD CustomChaosCardWeapon2;
	DWORD CustomTypeChaosCardWeapon2;
	DWORD CustomChaosCardHelmLevel;
	DWORD CustomChaosCardArmorLevel;
	DWORD CustomChaosCardPantsLevel;
	DWORD CustomChaosCardGlovesLevel;
	DWORD CustomChaosCardBootsLevel;
	DWORD CustomChaosCardWeaponFirstLevel;
	DWORD CustomChaosCardWeaponSecondLevel;
	DWORD CustomChaosCardHelmExcellent;
	DWORD CustomChaosCardArmorExcellent;
	DWORD CustomChaosCardPantsExcellent;
	DWORD CustomChaosCardGlovesExcellent;
	DWORD CustomChaosCardBootsExcellent;
	DWORD CustomChaosCardWeaponFirstExcellent;
	DWORD CustomChaosCardWeaponSecondExcellent;

	//--Guard1
	DWORD CustomGuard1;
	DWORD CustomGuard1Wings;
	DWORD CustomGuard1Helm;
	DWORD CustomGuard1Armor;
	DWORD CustomGuard1Pants;
	DWORD CustomGuard1Gloves;
	DWORD CustomGuard1Boots;
	DWORD CustomGuard1Weapon1;
	DWORD CustomTypeGuard1Weapon1;
	DWORD CustomGuard1Weapon2;
	DWORD CustomTypeGuard1Weapon2;
	DWORD CustomGuard1HelmLevel;
	DWORD CustomGuard1ArmorLevel;
	DWORD CustomGuard1PantsLevel;
	DWORD CustomGuard1GlovesLevel;
	DWORD CustomGuard1BootsLevel;
	DWORD CustomGuard1WeaponFirstLevel;
	DWORD CustomGuard1WeaponSecondLevel;
	DWORD CustomGuard1HelmExcellent;
	DWORD CustomGuard1ArmorExcellent;
	DWORD CustomGuard1PantsExcellent;
	DWORD CustomGuard1GlovesExcellent;
	DWORD CustomGuard1BootsExcellent;
	DWORD CustomGuard1WeaponFirstExcellent;
	DWORD CustomGuard1WeaponSecondExcellent;

	//--Guard2
	DWORD CustomGuard2;
	DWORD CustomGuard2Wings;
	DWORD CustomGuard2Helm;
	DWORD CustomGuard2Armor;
	DWORD CustomGuard2Pants;
	DWORD CustomGuard2Gloves;
	DWORD CustomGuard2Boots;
	DWORD CustomGuard2Weapon1;
	DWORD CustomTypeGuard2Weapon1;
	DWORD CustomGuard2Weapon2;
	DWORD CustomTypeGuard2Weapon2;
	DWORD CustomGuard2HelmLevel;
	DWORD CustomGuard2ArmorLevel;
	DWORD CustomGuard2PantsLevel;
	DWORD CustomGuard2GlovesLevel;
	DWORD CustomGuard2BootsLevel;
	DWORD CustomGuard2WeaponFirstLevel;
	DWORD CustomGuard2WeaponSecondLevel;
	DWORD CustomGuard2HelmExcellent;
	DWORD CustomGuard2ArmorExcellent;
	DWORD CustomGuard2PantsExcellent;
	DWORD CustomGuard2GlovesExcellent;
	DWORD CustomGuard2BootsExcellent;
	DWORD CustomGuard2WeaponFirstExcellent;
	DWORD CustomGuard2WeaponSecondExcellent;

	//--CursedWizard
	DWORD CustomCursedWizard;
	DWORD CustomCursedWizardWings;
	DWORD CustomCursedWizardHelm;
	DWORD CustomCursedWizardArmor;
	DWORD CustomCursedWizardPants;
	DWORD CustomCursedWizardGloves;
	DWORD CustomCursedWizardBoots;
	DWORD CustomCursedWizardWeapon1;
	DWORD CustomTypeCursedWizardWeapon1;
	DWORD CustomCursedWizardWeapon2;
	DWORD CustomTypeCursedWizardWeapon2;
	DWORD CustomCursedWizardHelmLevel;
	DWORD CustomCursedWizardArmorLevel;
	DWORD CustomCursedWizardPantsLevel;
	DWORD CustomCursedWizardGlovesLevel;
	DWORD CustomCursedWizardBootsLevel;
	DWORD CustomCursedWizardWeaponFirstLevel;
	DWORD CustomCursedWizardWeaponSecondLevel;
	DWORD CustomCursedWizardHelmExcellent;
	DWORD CustomCursedWizardArmorExcellent;
	DWORD CustomCursedWizardPantsExcellent;
	DWORD CustomCursedWizardGlovesExcellent;
	DWORD CustomCursedWizardBootsExcellent;
	DWORD CustomCursedWizardWeaponFirstExcellent;
	DWORD CustomCursedWizardWeaponSecondExcellent;

	//--LeoHelper
	DWORD CustomLeoHelper;
	DWORD CustomLeoHelperWings;
	DWORD CustomLeoHelperHelm;
	DWORD CustomLeoHelperArmor;
	DWORD CustomLeoHelperPants;
	DWORD CustomLeoHelperGloves;
	DWORD CustomLeoHelperBoots;
	DWORD CustomLeoHelperHelmLevel;
	DWORD CustomLeoHelperArmorLevel;
	DWORD CustomLeoHelperPantsLevel;
	DWORD CustomLeoHelperGlovesLevel;
	DWORD CustomLeoHelperBootsLevel;
	DWORD CustomLeoHelperHelmExcellent;
	DWORD CustomLeoHelperArmorExcellent;
	DWORD CustomLeoHelperPantsExcellent;
	DWORD CustomLeoHelperGlovesExcellent;
	DWORD CustomLeoHelperBootsExcellent;
	DWORD EnableRankVIP;
	DWORD EnableRankTuChan;
	//--
	CUSTOM_MESSAGE_INFO EngCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO PorCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO SpnCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_JEWEL_INFO CustomJewelInfo[MAX_CUSTOM_JEWEL];
	CUSTOM_WING_INFO CustomWingInfo[MAX_CUSTOM_WING];
	CUSTOM_ITEM_INFO CustomItemInfo[MAX_CUSTOM_ITEM];
	CUSTOM_BUYVIP_INFO CustomBuyVipInfo[MAX_CUSTOM_BUYVIP];
	CUSTOM_COMMAND_INFO CustomCommandInfo[MAX_CUSTOM_COMMAND];
	CUSTOM_EVENT_INFO CustomEventInfo[MAX_EVENTTIME];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];
	CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTER];
	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	//--
	CUSTOM_BOW_INFO CustomBowInfo[MAX_CUSTOM_BOW];
	CUSTOM_RF_GLOVES CustomGloves[MAX_CUSTOM_GLOVES];
	CUSTOM_PET_INFO CustomPetInfo[MAX_PET_ITEM];
	CUSTOMCLOAK_DATA m_CustomCloak[MAX_CUSTOMCLOAK];
	CUSTOM_POSITION_INFO CustomPosition[MAX_POSITION_ITEM];
	REMAKE_EFFECT CustomRemake[MAX_REMAKE_EFFECT];
	//--
	ITEM_INFO m_ItemInfoEx[MAX_ITEM2];
	CUSTOM_MODEL_EFFECT_INFO m_CustomModelInfo[MAX_MODEL_EFFECT];
	LUCKYWHEEL_INFO CustomLuckyWheel[MAX_LUCKYWHEEL_ITEM];
	//
	CUSTOM_SMITH_INFO SmithSwordInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithAxeInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithMaceInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithSpearInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithBowInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithStaffInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithShieldInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithHelmInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithArmorInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithPantInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithGloveInfo[MAX_SMITH_ITEM];
	CUSTOM_SMITH_INFO SmithBootInfo[MAX_SMITH_ITEM];
};

struct PETEFFECT_BMD
{
	PET_EFFECT_CUSTOM m_PetCEffectBMD[max_ceffect];
	CUSTOM_WING_EFFECT_INFO CustomWingEffectInfo[MAX_CUSTOM_WING_EFFECT];
	DYNAMIC_WING_EFFECT_INFO DynamicWingEffectInfo[MAX_DYNAMIC_WING_EFFECT];
	RENDER_MESH RenderMeshPet[MAX_RENDER_MESH];
	CUSTOM_MONSTERGLOW_INFO m_CustomMonsterGlow[MAX_CUSTOM_MONSTERGLOW];
	CUSTOM_GLOW_INFO m_CustomMonsterbrightness[MAX_CUSTOM_MONSTERGLOW];
	//--
	xMonsterEffect m_CustomMonsterEffect[MAX_EFFECT_MONSTER];
	//--
	JCItemnoGlow m_JCWRemoveGlow[ MAX_NOGLOW ];
	//--
#if UPDATE > 15
	ITEM_RENDER_MESH m_JCWRenderMesh[ MAX_JCRENDER_MESH ];
#endif
};

struct TOOLTIP_BMD
{
	RenderTooltipBuff m_TooltipTRSDataEng[256];
	RenderTooltipBuff m_TooltipTRSDataSpn[256];
	RenderTooltipBuff m_TooltipTRSDataPor[256];

	nInformation m_TRSTooltipData[MaxLine];
	nText m_TRSTooltipText[MaxLine];
};

struct RENDER_MAKE_VIEW
{
	#if UPDATE >= 15
	SelectChar m_RenderSelect[MAX_WORLD_SETTINGS];
	DWORD TooltipS15;
	#endif
};


class CProtect
{
public:
	CProtect();
	virtual ~CProtect();
	bool ReadMainFile(char* name);
	bool ReadPetEffectBMD(char* name);
	bool ReadTooltipTRSData(char* name);
	bool ReadMakeViewTRSData(char* name);
	void CheckLauncher();
	void CheckInstance();
	void CheckClientFile();
	void CheckHackFile();
	void CheckPluginFile1();
	void CheckPluginFile2();
	void CheckPluginFile3();
	void CheckPluginFile4();
	void CheckPluginFile5();
	void CheckCameraFile();
public:
	//--
	MAIN_FILE_INFO m_MainInfo;
	PETEFFECT_BMD m_ReadBMD;
	TOOLTIP_BMD m_ReadTooltipTRSData;
	RENDER_MAKE_VIEW m_MakeViewTRSData;
	//-- CRC
	DWORD m_ClientFileCRC;
	DWORD m_ReadBMDFileCRC;
	DWORD m_ReadTooltipTRSDataFileCRC;
	DWORD m_MakeViewTRSDataFileCRC;
};

extern CProtect gProtect;
