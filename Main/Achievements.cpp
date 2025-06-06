#include "stdafx.h"
#include "Achievements.h"
#include "Interface.h"
#include "HealthBar.h"
#include "Util.h"
#include "defines.h"

CAchievements  gAchievements;

CAchievements::CAchievements()
{
	this->Init();
}

CAchievements::~CAchievements()
{
}

void CAchievements::Init()
{
	for (int i = 0; i < ACHIEVEMENTS_COUNT; i++)
	{
		this->m_SettingsData[i].counter = 0;
		this->m_UserCount[i] = 0;
	}

	this->m_Damage = 0;
	this->m_DamageMax = 0;
	this->m_Defence = 0;
	this->m_DefenceMax = 0;
	this->m_Life = 0;
	this->m_LifeMax = 0;
	this->m_ExellentDamage = 0;
	this->m_ExellentDamageMax = 0;
	this->m_CriticalDamage = 0;
	this->m_CriticalDamageMax = 0;
}

void CAchievements::Load()
{
	this->Init();
}

void CAchievements::LoadImages()
{
	pLoadImage("Custom\\Interface\\Achievements\\arch_bg.tga", ImgID_ACHIEVEMENTS_MAIN, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\HP_BG.jpg", ImgID_ACHIEVEMENTS_PROGRESS_BG, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\SD.jpg", ImgID_ACHIEVEMENTS_PROGRESS_LINE, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\mission_images.jpg", ImgID_ACHIEVEMENTS_MISSIONS, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\ach_add2\\ach_panel.tga", ImgID_ACHIEVEMENTS_PANEL, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\ach_add2\\ach_dmg.tga", ImgID_ACHIEVEMENTS_DAMAGE, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\ach_add2\\ach_def.tga", ImgID_ACHIEVEMENTS_DEFENSE, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\ach_add2\\ach_hp.tga", ImgID_ACHIEVEMENTS_LIFE, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\ach_add2\\ach_exl.tga", ImgID_ACHIEVEMENTS_EXCELLENT, GL_LINEAR, GL_CLAMP, 1, 0);
	pLoadImage("Custom\\Interface\\Achievements\\ach_add2\\ach_crit.tga", ImgID_ACHIEVEMENTS_CRITICAL, GL_LINEAR, GL_CLAMP, 1, 0);
}

void CAchievements::BindImages()
{
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_MAIN, ImgID_ACHIEVEMENTS_MAIN, 640, 480, -1, -1);
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_PROGRESS_BG, ImgID_ACHIEVEMENTS_PROGRESS_BG, 80, 6, -1, -1);
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_CLOSE, 0x7EC5, 36, 29, -1, -1);
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_MISSIONS, ImgID_ACHIEVEMENTS_MISSIONS, 32, 32, -1, -1);

	gInterface.BindObject(OBJECT_ACHIEVEMENTS_PANEL, ImgID_ACHIEVEMENTS_PANEL, 260, 360, -1, -1);	//310	500
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_DAMAGE, ImgID_ACHIEVEMENTS_DAMAGE, 43, 42, -1, -1);
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_DEFENSE, ImgID_ACHIEVEMENTS_DEFENSE, 43, 42, -1, -1);
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_LIFE, ImgID_ACHIEVEMENTS_LIFE, 43, 42, -1, -1);
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_EXCELLENT, ImgID_ACHIEVEMENTS_EXCELLENT, 43, 42, -1, -1);
	gInterface.BindObject(OBJECT_ACHIEVEMENTS_CRITICAL, ImgID_ACHIEVEMENTS_CRITICAL, 43, 42, -1, -1);
}

void CAchievements::Draw()
{
	if((GetTickCount() - gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].EventTick) < 1000 || gInterface.CheckWindow(ChatWindow))
	{
		gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].Close();
		return;
	}

	if (!gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	gInterface.DrawGUI(OBJECT_ACHIEVEMENTS_MAIN, 0, 0);
	gInterface.DrawText(eGold, MAX_WIN_WIDTH / 2, 23, 0, eCenter, "Sistema Recompensas");

	gInterface.DrawGUI(OBJECT_ACHIEVEMENTS_CLOSE, 630 + 15 - gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].Width, gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].Height + gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].Height - 55);
	// ----
	if (gInterface.IsWorkZone(OBJECT_ACHIEVEMENTS_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(OBJECT_ACHIEVEMENTS_CLOSE, gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].X, gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].X + 5, gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].Y + 25, "Cerrar");
	}

	float RightX = 22;
	float DownY = 66;

	int counter = 0;

	for (int i = 0; i < ACHIEVEMENTS_COUNT; i++)
	{
		this->DrawMission(/*eACHIEVEMENTS_MISSION_1+*/i, RightX, DownY, this->m_SettingsData[i].Name, this->m_UserCount[i], this->m_SettingsData[i].counter);
		RightX += 120;
		counter++;
		if (counter == 5)
		{
			RightX = 22;
			DownY += 35;
			counter = 0;
		}
	}

	RightX = 22;
	DownY = 66;

	counter = 0;

	for (int i = 0; i < ACHIEVEMENTS_COUNT; i++)
	{
		if (gInterface.IsWorkZone2(RightX, DownY, RightX + 32, DownY + 32))
		{
			int tooltipWidth = 80;
			int tooltipHeight = 50;

			if (DownY > 350)
			{
				DownY -= 35;
			}

			glColor4f(RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(0), RGBTOGLFLOAT(200));
			pDrawBarForm(RightX + (32 / 2) - tooltipWidth / 2, DownY + 35, tooltipWidth, tooltipHeight, 0.0f, 0);
			pGLSwitchBlend();
			pGLSwitch();

			glColor3f(1.0, 1.0, 1.0);

			int TooltipX = RightX + (32 / 2);
			int TooltipY = DownY + 35;

			gInterface.TextDraw(TooltipX, TooltipY, 0, 1, eGold, 0, 8, pFontBold, this->m_SettingsData[i].Name);

			gInterface.TextDraw(TooltipX, TooltipY + 11, 0, 1, eWhite, 0, 8, pFontNormal, "%d / %d", this->m_UserCount[i], this->m_SettingsData[i].counter);

			gInterface.TextDraw(TooltipX, TooltipY + 11 + 10, 0, 1, eWhite, 0, 8, pFontNormal, "Reward: %d %s", this->m_SettingsData[i].RewardValue, GetRewardTextByType(this->m_SettingsData[i].RewardType));
		}

		RightX += 120;
		counter++;
		if (counter == 5)
		{
			RightX = 22;
			DownY += 35;
			counter = 0;
		}
	}

	if (gInterface.IsWorkZone2(270, 13, 373, 38))
	{
		const int barStartX = 268;
		int barStartY = 38;
		const int barWidth = 105;
		const int barHeight = 80;
		gInterface.DrawBarForm(barStartX, barStartY, barWidth, barHeight, 0, 0, 0, 1.0);
		barStartY += 5;
		gInterface.TextDraw(barStartX + barWidth / 2, barStartY, 0, 1, eGold, 0, 8, pFontBold, "[Achievements Power]");

		barStartY += 15;
		gInterface.TextDraw(barStartX + barWidth / 2, barStartY, 0, 1, eWhite, 0, 8, pFontBold, "Damage: %d / %d", this->m_Damage, this->m_DamageMax);

		barStartY += 10;
		gInterface.TextDraw(barStartX + barWidth / 2, barStartY, 0, 1, eWhite, 0, 8, pFontBold, "Defense: %d / %d", this->m_Defence, this->m_DefenceMax);

		barStartY += 10;
		gInterface.TextDraw(barStartX + barWidth / 2, barStartY, 0, 1, eWhite, 0, 8, pFontBold, "Life: %d / %d", this->m_Life, this->m_LifeMax);

		barStartY += 10;
		gInterface.TextDraw(barStartX + barWidth / 2, barStartY, 0, 1, eWhite, 0, 8, pFontBold, "Excellent Damage: %d / %d", this->m_ExellentDamage, this->m_ExellentDamageMax);

		barStartY += 10;
		gInterface.TextDraw(barStartX + barWidth / 2, barStartY, 0, 1, eWhite, 0, 8, pFontBold, "Critical Damage: %d / %d", this->m_CriticalDamage, this->m_CriticalDamageMax);
	}
}

void CAchievements::DrawMission(int ObjectID, float X, float Y, char* Name, int iStart, int iNeed)
{
	if (iStart > iNeed)
	{
		iStart = iNeed;
	}

	int scaleX = int(ObjectID) % 10;
	int scaleY = ObjectID / 10;
	gInterface.DrawButton(OBJECT_ACHIEVEMENTS_MISSIONS, X, Y, scaleX * 32, scaleY * 32);

	float DrawX = X + 32 + 3;
	float DrawY = Y;

	gInterface.DrawText(eWhite, DrawX, DrawY, 100, 1, Name);

	DrawY += 13;
	gInterface.DrawText(eYellow, DrawX, DrawY, 100, 1, "%d / %d", iStart, iNeed);

	DrawX = X + 32 + 2;
	DrawY = Y + 26;
	gInterface.DrawGUI(OBJECT_ACHIEVEMENTS_PROGRESS_BG, DrawX, DrawY);

	DrawX += 2;
	DrawY = Y + 27.5;
	float LineStart = (iStart * 76.5) / iNeed;

	pDrawGUI(ImgID_ACHIEVEMENTS_PROGRESS_LINE, DrawX, DrawY, LineStart, 3.0);
}

void CAchievements::Button(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].OnShow || !gInterface.IsWorkZone(OBJECT_ACHIEVEMENTS_CLOSE))
	{
		return;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].OnClick = true;
		return;
	}
	// ----
	gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return;
	}
	// ----
	gInterface.Data[OBJECT_ACHIEVEMENTS_CLOSE].EventTick = GetTickCount();
	gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].Close();
	// ----
	return;
}

void CAchievements::GCConfigData(PMSG_GC_ACH_SETTINGS_DATA* aRecv)
{
	memcpy(&this->m_SettingsData, &aRecv->Data, sizeof(this->m_SettingsData));
}

void CAchievements::GCPlayerData(PMSG_GC_ACH_PLAYER_DATA* aRecv)
{
	memcpy(&this->m_UserCount, &aRecv->counter, sizeof(this->m_UserCount));

	if (!aRecv->bWinOpen)
	{
		return;
	}

	if (!gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].OnShow)
	{
		this->SwitchStatsWindowState();
	}
}

void CAchievements::CGWindowOpen()
{
	if (!gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].OnShow)
	{
		this->SwitchStatsWindowState();
		return;
	}

	PMSG_CG_ACH_WINOPEN pMsg;
	pMsg.h.set(0xF2, 0x0C, sizeof(pMsg));
	DataSend((LPBYTE)&pMsg, pMsg.h.size);
}

void CAchievements::DrawPanel()
{
	if (!gInterface.Data[OBJECT_ACHIEVEMENTS_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float StartX = 190;
	float StartY = 50;
	float LineStart = 0;

	int iStart = 100;
	int iNeed = 100;

	gInterface.DrawGUI(OBJECT_ACHIEVEMENTS_PANEL, StartX, StartY);
	gInterface.DrawText(eGold, StartX + 80, StartY + 19, 100, 3, "Achievements Power");

	StartX += 50;
	StartY += 60;
	this->DrawPower(OBJECT_ACHIEVEMENTS_DAMAGE, StartX, StartY, "Damage", this->m_Damage, this->m_DamageMax);

	StartY += 50;
	this->DrawPower(OBJECT_ACHIEVEMENTS_DEFENSE, StartX, StartY, "Defense", this->m_Defence, this->m_DefenceMax);

	StartY += 50;
	this->DrawPower(OBJECT_ACHIEVEMENTS_LIFE, StartX, StartY, "Life", this->m_Life, this->m_LifeMax);

	StartY += 50;
	this->DrawPower(OBJECT_ACHIEVEMENTS_EXCELLENT, StartX, StartY, "Excellent Damage", this->m_ExellentDamage, this->m_ExellentDamageMax);

	StartY += 50;
	this->DrawPower(OBJECT_ACHIEVEMENTS_CRITICAL, StartX, StartY, "Critical Damage", this->m_CriticalDamage, this->m_CriticalDamageMax);

	StartY += 52;
	gInterface.DrawText(eGold, StartX + 95, StartY + 19, 100, 3, "Ok");
}

void CAchievements::DrawPower(int ObjectID, float X, float Y, char* Name, int iStart, int iNeed)
{
	if (iStart > iNeed)
	{
		iStart = iNeed;
	}

	float StartX = X;
	float StartY = Y;
	float LineStart = (iStart * 76.5) / iNeed;

	gInterface.DrawText(eWhite, StartX + 60, StartY + 5 - 1, 100, 3, Name);
	gInterface.DrawText(eYellow, StartX + 60, StartY + 20 - 1, 100, 3, "%d / %d", iStart, iNeed);
	gInterface.DrawGUI(ObjectID, StartX, StartY);
	gInterface.DrawGUI(OBJECT_ACHIEVEMENTS_PROGRESS_BG, StartX + 70 - 1, StartY + 35);
	pDrawGUI(ImgID_ACHIEVEMENTS_PROGRESS_LINE, StartX + 72 - 1, StartY + 36.5, LineStart, 3.0);
}

void CAchievements::GCCalculatorPower(PMSG_GC_ACH_POWER* aRecv)
{
	this->m_Damage = aRecv->iDamage;
	this->m_DamageMax = aRecv->iDamageMax;
	this->m_Defence = aRecv->iDefence;
	this->m_DefenceMax = aRecv->iDefenceMax;
	this->m_Life = aRecv->iLife;
	this->m_LifeMax = aRecv->iLifeMax;
	this->m_ExellentDamage = aRecv->iExellentDamage;
	this->m_ExellentDamageMax = aRecv->iExellentDamageMax;
	this->m_CriticalDamage = aRecv->iCriticalDamage;
	this->m_CriticalDamageMax = aRecv->iCriticalDamageMax;
}