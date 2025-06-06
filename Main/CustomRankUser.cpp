#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "HealthBar.h"
#include "Import.h"
#include "Object.h"
#include "PrintPlayer.h"
#include "WindowsStruct.h"
#include "CustomRankUser.h"
#include "Config.h"
#include "DanhHieu.h"

CCustomRankUser gCustomRankUser;


int ImgTagEx5 = 10500; //Rank Dynamic
int ImgTagEx6 = 10600; //Rank Dynamic
int ImgTagEx7 = 10700; //Rank Dynamic
int ImgTagEx8 = 10800; //Rank Dynamic
int ImgTagEx9 = 10900; //Rank Dynamic
int ImgTagEx10 = 11000; //Rank Dynamic
int ImgTagEx11 = 11100; //Rank Dynamic
int ImgTagEx12 = 11200; //Rank Dynamic
int ImgTagEx13 = 11300; //Rank Dynamic
int ImgTagEx14 = 11400; //Rank Dynamic
int ImgTagEx15 = 11500; //Rank Dynamic
int ImgTagEx16 = 11600; //Rank Dynamic
int ImgTagEx40 = 60040; //Rank Dynamic
int TuchanFlash = 50041; //Rank Dynamic


CCustomRankUser::CCustomRankUser()
{
}

void CCustomRankUser::RenderShowLogRank(DWORD ViewPortAddr, int index, int PosX, int PosY)
{
	if(*(BYTE*)(ViewPortAddr + 0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
	{
		return; //continue;
	}

	if((((pMapNumber)<18)?0:((pMapNumber)>23)?(((pMapNumber)==53)?1:0):1) == 1) //Disable in Chaos Castle
	{
		return; //continue;
	}

	if (gProtect.m_MainInfo.RankUserShowOverHead != 0 || *(int*)0x0E609E8 == 4)
	{
		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);
		RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX+24, (float)PosY -68, Return2X(TransForX(60)), 60, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}

	if ( ViewPortAddr == *(DWORD *)0x7BC4F04 && (pCursorX >= PosX) && ((float)pCursorX <= (float)PosX + 50) && (pCursorY >= PosY + 20) && (pCursorY < PosY + 85))
	{
		this->LoadInfoUser(index, PosX, PosY, (char*)(ViewPortAddr + 0x38));
	}


		pSetBlend(true);
		glColor3f(1.0, 1.0, 1.0);
		//RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank + 1].ModelID, (float)PosX+24, (float)PosY -68, Return2X(TransForX(60)), 60, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);

			int TitleTuchan = this->m_Data[index].m_Lvtuchan;	
			int ShowTuChan =  GetPrivateProfileInt("TUCHAN", "OnOff", 1, ".\\Settings.ini" );
			//int ShowDanhhieu =  GetPrivateProfileInt("DANHHIEU", "OnOff", 1, ".\\Settings.ini" );

//== Danh Hieu
	if (ShowTuChan > 0)
	{
		switch (this->m_Data[index].m_RankTitle1)
		//switch (5)
		{
		case 0:
			//gInterface.DrawToolTip((float)PosX - 130, (float)PosY + 200, "no info ...");
			break;
		case 1:
			RenderBitmap(10100, (float)PosX - 42.0f, (float)PosY - 35.0f, 200, 50, 0, 0, 1, 1, 1, 1, 0.0);
			break;
		case 2:
			RenderBitmap(10200, (float)PosX - 21.0f, (float)PosY - 35.0f, 145, 50, 0, 0, 1, 1, 1, 1, 0.0);
			break;
		case 3:
			RenderBitmap(10300, (float)PosX - 42.0f, (float)PosY - 35.0f, 200, 50, 0, 0, 1, 1, 1, 1, 0.0);
			break;
		case 4:
			RenderBitmap(10400, (float)PosX - 21.0f, (float)PosY - 35.0f, 145, 60, 0, 0, 1, 1, 1, 1, 0.0);
			break;
		case 5:

			if (ImgTagEx5 >= 10500)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx5, (float)PosX - 36.0f, (float)PosY - 35.0f, 180, 70, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx5++;
				if (ImgTagEx5 == 10539)
				{
					ImgTagEx5 = 10500;
				}
			}
			break;
		case 6:
			if (ImgTagEx6 >= 10600)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx6, (float)PosX - 33.0f, (float)PosY - 67.0f, 180, 70, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx6++;
				if (ImgTagEx6 == 10639)
				{
					ImgTagEx6 = 10600;
				}
			}
			break;
		case 7:
			if (ImgTagEx7 >= 10700)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx7, (float)PosX - 33.0f, (float)PosY - 67.0f, 180, 70, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx7++;
				if (ImgTagEx7 == 10739)
				{
					ImgTagEx7 = 10700;
				}
			}
			break;
		case 8:
			if (ImgTagEx8 >= 10800)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx8, (float)PosX - 33.0f, (float)PosY - 67.0f, 180, 70, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx8++;
				if (ImgTagEx8 == 10839)
				{
					ImgTagEx8 = 10800;
				}
			}
			break;
		case 9:
			if (ImgTagEx9 >= 10900)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx9, (float)PosX - 22.0f, (float)PosY - 67.0f, 150, 70, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx9++;
				if (ImgTagEx9 == 10939)
				{
					ImgTagEx9 = 10900;
				}
			}
			break;
		case 10:
			if (ImgTagEx10 >= 11000)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx10, (float)PosX - 12.0f, (float)PosY - 67.0f, 120, 70, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx10++;
				if (ImgTagEx10 == 11039)
				{
					ImgTagEx10 = 11000;
				}
			}
			break;
		case 11:
			if (ImgTagEx11 >= 11100)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx11, (float)PosX - 14.0f, (float)PosY - 67.0f, 130, 80, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx11++;
				if (ImgTagEx11 == 11139)
				{
					ImgTagEx11 = 11100;
				}
			}
			break;
		case 12:
			if (ImgTagEx12 >= 11200)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx12, (float)PosX - 33.0f, (float)PosY - 67.0f, 180, 70, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx12++;
				if (ImgTagEx12 == 11239)
				{
					ImgTagEx12 = 11200;
				}
			}
			break;
		case 13:
			if (ImgTagEx13 >= 11300)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx13, (float)PosX - 5.0f, (float)PosY - 67.0f, 110, 90, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx13++;
				if (ImgTagEx13 == 11339)
				{
					ImgTagEx13 = 11300;
				}
			}
			break;
		case 14:
			if (ImgTagEx14 >= 11400)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx14, (float)PosX - 5.0f, (float)PosY - 67.0f, 110, 90, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx14++;
				if (ImgTagEx14 == 11439)
				{
					ImgTagEx14 = 11400;
				}
			}
			break;
		case 15:
			if (ImgTagEx15 >= 11500)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx15, (float)PosX - 5.0f, (float)PosY - 67.0f, 110, 90, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx15++;
				if (ImgTagEx15 == 11539)
				{
					ImgTagEx15 = 11500;
				}
			}
			break;
		case 16:
			if (ImgTagEx16 >= 11600)
			{                                                                //  215,77
				RenderBitmap(ImgTagEx16, (float)PosX - 5.0f, (float)PosY - 67.0f, 110, 90, 0, 0, 1, 1, 1, 1, 0.0);
				ImgTagEx16++;
				if (ImgTagEx16 == 11639)
				{
					ImgTagEx16 = 11600;
				}
			}
			break;
		}
	}


			if (gProtect.m_MainInfo.EnableRankVIP != 0  )
			{
				if (gProtect.m_MainInfo.EnableRankTuChan == 0  || TitleTuchan <= 0)
				{
				 if (ShowTuChan > 0)
				 {
					switch (this->m_Data[index].m_RankTitle4)
					{
						case 0:
							//gInterface.DrawToolTip((float)PosX - 130, (float)PosY + 200, "no info ...");
							break;
						case 1://102
							RenderBitmap(32891, (float)PosX + 23.0f, (float)PosY - 77.0f, 40, 40,  0, 0, 1, 1, 1, 1, 0.0);
							break;
						case 2:
							RenderBitmap(32892, (float)PosX + 23.0f, (float)PosY - 77.0f, 40, 40, 0, 0, 1, 1, 1, 1, 0.0);
							break;
						case 3:
							RenderBitmap(32893, (float)PosX + 23.0f, (float)PosY - 77.0f, 40, 40, 0, 0, 1, 1, 1, 1, 0.0);
							break;
						case 4:
							RenderBitmap(32894, (float)PosX + 23.0f, (float)PosY - 77.0f, 40, 40, 0, 0, 1, 1, 1, 1, 0.0);
							break;
					}
				 }
				}
				else
				{
				 if (ShowTuChan > 0) // CAMBIAR POSICION DEL VIP
				 {
					switch (this->m_Data[index].m_RankTitle4)
					{
						case 0:
							//gInterface.DrawToolTip((float)PosX - 130, (float)PosY + 200, "no info ...");
							break;
						case 1://102
							RenderBitmap(32891, (float)PosX + 23.0f, (float)PosY - 105, 40, 40, 0, 0, 1, 1, 1, 1, 0.0);
							break;
						case 2:
							RenderBitmap(32892, (float)PosX + 23.0f, (float)PosY - 105, 40, 40, 0, 0, 1, 1, 1, 1, 0.0);
							break;
						case 3:
							RenderBitmap(32893, (float)PosX + 23.0f, (float)PosY - 105, 40, 40, 0, 0, 1, 1, 1, 1, 0.0);
							break;
						case 4:
							RenderBitmap(32894, (float)PosX + 23.0f, (float)PosY - 105, 40, 40, 0, 0, 1, 1, 1, 1, 0.0);
							break;
					}
				 }
				}
			}

			if (gProtect.m_MainInfo.EnableRankTuChan != 0)
			{
		 
				if (ShowTuChan > 0){

					if(TitleTuchan == 1){ pDrawImage(50000,(float)PosX-15, (float)PosY -80, 130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}
					else if(TitleTuchan == 2){ pDrawImage(50001,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 3){ pDrawImage(50002,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 4){ pDrawImage(50003,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 5){ pDrawImage(50004,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 6){ pDrawImage(50005,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 7){ pDrawImage(50006,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 8){ pDrawImage(50007,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 9){ pDrawImage(50008,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 10){pDrawImage(50009,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 11){pDrawImage(50010,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 12){pDrawImage(50011,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 13){pDrawImage(50012,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 14){pDrawImage(50013,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 15){pDrawImage(50014,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 16){pDrawImage(50015,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 17){pDrawImage(50016,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 18){pDrawImage(50017,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 19){pDrawImage(50018,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 20){pDrawImage(50019,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 21){pDrawImage(50020,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 22){pDrawImage(50021,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 23){pDrawImage(50022,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 24){pDrawImage(50023,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 25){pDrawImage(50024,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 26){pDrawImage(50025,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 27){pDrawImage(50026,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 28){pDrawImage(50027,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 29){pDrawImage(50028,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 30){pDrawImage(50029,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 31){pDrawImage(50030,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 32){pDrawImage(50031,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 33){pDrawImage(50032,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 34){pDrawImage(50033,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 35){pDrawImage(50034,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 36){pDrawImage(50035,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 37){pDrawImage(50036,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 38){pDrawImage(50037,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 39){pDrawImage(50038,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 40){
						//pDrawImage(50039,(float)PosX-25, (float)PosY -60, 150, 65,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
						if(TuchanFlash >= 50041)
						{
					
							pDrawImage(TuchanFlash,(float)PosX-15, (float)PosY -65, 130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							TuchanFlash++;
							if(TuchanFlash == 50068)
							{
								TuchanFlash = 50041;
							}
						}
					}
				}
			}
/*			if (gProtect.m_MainInfo.EnableRankTuChan != 0)
			{
		 
				if (ShowTuChan > 0){

					if(TitleTuchan == 1){ pDrawImage(50000,(float)PosX-15, (float)PosY -70,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}
					else if(TitleTuchan == 2){ pDrawImage(50001,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 3){ pDrawImage(50002,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 4){ pDrawImage(50003,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 5){ pDrawImage(50004,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 6){ pDrawImage(50005,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 7){ pDrawImage(50006,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 8){ pDrawImage(50007,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 9){ pDrawImage(50008,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 10){pDrawImage(50009,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 11){pDrawImage(50010,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 12){pDrawImage(50011,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 13){pDrawImage(50012,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 14){pDrawImage(50013,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 15){pDrawImage(50014,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 16){pDrawImage(50015,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 17){pDrawImage(50016,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 18){pDrawImage(50017,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 19){pDrawImage(50018,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 20){pDrawImage(50019,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 21){pDrawImage(50020,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 22){pDrawImage(50021,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 23){pDrawImage(50022,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 24){pDrawImage(50023,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 25){pDrawImage(50024,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 26){pDrawImage(50025,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 27){pDrawImage(50026,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 28){pDrawImage(50027,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 29){pDrawImage(50028,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 30){pDrawImage(50029,(float)PosX-15, (float)PosY -85,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 31){pDrawImage(50030,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 32){pDrawImage(50031,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 33){pDrawImage(50032,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 34){pDrawImage(50033,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 35){pDrawImage(50034,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 36){pDrawImage(50035,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 37){pDrawImage(50036,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 38){pDrawImage(50037,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 39){pDrawImage(50038,(float)PosX-15, (float)PosY -80,  130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);}
					else if(TitleTuchan == 40){
						//pDrawImage(50039,(float)PosX-25, (float)PosY -60, 150, 65,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
						if(TuchanFlash >= 50041)
						{
					
							pDrawImage(TuchanFlash,(float)PosX-15, (float)PosY -85, 130, 57, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							TuchanFlash++;
							if(TuchanFlash == 50068)
							{
								TuchanFlash = 50041;
							}
						}
					}
				}
			}
*/

if (gInterface.Data[eTUCHAN_MAIN].OnShow)
{			
	float MainWidth			= 230.0;
	float MainHeight		= 150.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);

	//gInterface.DrawGUI(eDHbuff, 203, 40);
	gInterface.DrawToolTip(	StartX + MainWidth + 15, 195 - 60, Config.MenuTuChan_TextNVT[0],this->m_Data[index].m_Lvtuchan);
	gInterface.DrawToolTip( StartX + MainWidth + 15, 207 - 60, Config.MenuTuChan_TextNVT[1],this->m_Data[index].m_rcrit);
	gInterface.DrawToolTip( StartX + MainWidth + 15, 219 - 60, Config.MenuTuChan_TextNVT[2],this->m_Data[index].m_rexc);
	gInterface.DrawToolTip( StartX + MainWidth + 15, 231 - 60, Config.MenuTuChan_TextNVT[3],this->m_Data[index].m_rdmg);
	gInterface.DrawToolTip( StartX + MainWidth + 15, 243 - 60, Config.MenuTuChan_TextNVT[4],this->m_Data[index].m_rdouble);

}
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

}

void CCustomRankUser::DrawInfo()
{
	
	VAngle Angle;

	int PosX, PosY;

	DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(), pViewAttackTargetID);

	if(!ViewportAddress || *(BYTE*)(ViewportAddress+0x320) != 1)
	{
		return; //continue;
	}

	int index = *(WORD*)(ViewportAddress+0x7E);

	char* name = (char*)(ViewportAddress+0x38);

	if(this->m_Data[index].m_Enabled == false)
	{
		return; //continue;
	}

	if(*(BYTE*)(ViewportAddress+0xE) == 0 && gProtect.m_MainInfo.RankUserOnlyOnSafeZone != 0)
	{
		return; //continue;
	}

	if((((pMapNumber)<18)?0:((pMapNumber)>23)?(((pMapNumber)==53)?1:0):1) == 1) //Disable in Chaos Castle
	{
		return; //continue;
	}

	Angle.X = *(float*)(ViewportAddress+0x404);

	Angle.Y = *(float*)(ViewportAddress+0x408);

	Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

	pGetPosFromAngle(&Angle, &PosX, &PosY);

	PosX -= 42;

	this->LoadInfoUser(index, PosX, PosY, name);
}

void CCustomRankUser::LoadInfoUser(int index, int PosX, int PosY, char* name)
{
	if((!gInterface.Data[eMenu_MAIN].OnShow && 
	!gInterface.Data[eMenu_MAINTWO].OnShow && 
	!gInterface.Data[eVip_MAIN].OnShow && 
	!gInterface.Data[eEventTimePANEL_MAIN].OnShow &&
	!gInterface.Data[eCommand_MAIN].OnShow &&
	!gInterface.Data[eRankPANEL_MAIN].OnShow&&
	!gInterface.Data[ePARTYSETTINGS_MAIN].OnShow&&
	!gInterface.Data[ePARTYSEARCH_MAIN].OnShow&&
	!gInterface.Data[eVAULT_MAIN].OnShow&&
	!gInterface.Data[eCHANGINGCLASS_MAIN].OnShow&&
	!gInterface.Data[eCHANGE_RESET_MAIN].OnShow&&
	!gInterface.Data[eLuckyWheelMain].OnShow&&	
	!gInterface.Data[eSMITH_MAIN].OnShow&&
	!gInterface.Data[eJEWELBANK_MAIN].OnShow&&
	!gInterface.Data[EXBEXO_DANH_HIEU_MAIN].OnShow&&
	!gInterface.Data[eTUCHAN_MAIN].OnShow&&
	!gInterface.Data[OBJECT_WIN_QUEST_MAIN].OnShow&&
	!gInterface.Data[EXBEXO_MUA_VIP_MAIN].OnShow)&&
	!gInterface.CheckWindow(35) )
	{
		if (gProtect.m_MainInfo.RankUserType != 4 && gProtect.m_MainInfo.RankUserShowOverHead != 0)
		{
			pSetBlend(true);
			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX + 2), (float)(PosY - 76), 75, 10, 0.0f, 0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);

			this->DrawFormat(eGold, PosX+7, PosY -75, 70, 3, "%s", this->m_Data[index].szTitleRank);
		}

		if( gProtect.m_MainInfo.RankUserNeedAltKey != 0 && !(GetKeyState(VK_MENU) & 0x8000) )
		{
			return; //continue;
		}

		pSetBlend(true);

		char classename[20] = {0};

		switch(this->m_Data[index].m_Classe)
		{
			case 1:
				sprintf(classename, "Soul Master");
				break;
			case 2:
				sprintf(classename, "Grand Master");
				break;
			case 16:
				sprintf(classename, "Dark Knight");
				break;
			case 17:
				sprintf(classename, "Blade Knight");
				break;
			case 18:
				sprintf(classename, "Blade Master");
				break;
			case 32:
				sprintf(classename, "Fairy Elf");
				break;
			case 33:
				sprintf(classename, "Muse Elf");
				break;
			case 34:
				sprintf(classename, "High Elf");
				break;
			case 48:
				sprintf(classename, "Magic Gladiator");
				break;
			case 50:
				sprintf(classename, "Duel Master");
				break;
			case 64:
				sprintf(classename, "Dark Lord");
				break;
			case 66:
				sprintf(classename, "Lord Emperor");
				break;
			case 80:
				sprintf(classename, "Summoner");
				break;
			case 81:
				sprintf(classename, "Bloody Summoner");
				break;
			case 82:
				sprintf(classename, "Dimension Master");
				break;
			case 96:
				sprintf(classename, "Rage Fighter");
				break;
			case 98:
				sprintf(classename, "Fist Master");
				break;
			default:
				sprintf(classename, "Dark Wizard");
				break;
		}

		if (gProtect.m_MainInfo.RankUserType == 2)
		{
			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 135, 80, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eRed2, PosX + 60, PosY - 4, 90, 3, "Lugar: %s", this->m_Data[index].szTitleRank);
		
			this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

			this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
			this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
			this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
			this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
			this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
				this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
			this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

		}
		else if (gProtect.m_MainInfo.RankUserType == 1)
		{

			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 120.0f, 80.0f, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eWhite,  PosX + 50, PosY - 2, 15, 1, "Lvl:");

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 8, 25, 1,  "Resets:");
				this->DrawFormat(eGold,  PosX + 87, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 87, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Deaths:");

			this->DrawFormat(eGold,  PosX + 87, PosY - 2, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 50, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", classename);

			this->DrawFormat(eGold, PosX + 100, PosY -5, 70, 3, "%s", this->m_Data[index].szTitleRank);
			this->DrawFormat(eGold, PosX + 100, PosY + 59, 70, 3, "%s", name);
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX + 110, (float)PosY + 9, 78.0, 78.0,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}
		else if (gProtect.m_MainInfo.RankUserType == 3)
		{

			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 5), 80, 85, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eSocket, PosX + 40, PosY - 4, 80, 3, "INFO");

			this->DrawFormat(eWhite,  PosX + 50, PosY +8, 15, 1, "Lvl:");

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 18, 25, 1, "Resets:");
				this->DrawFormat(eGold,  PosX + 87, PosY + 18, 37, 1, "%d", this->m_Data[index].m_Resets);
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 50, PosY + 28 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 87, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 50, PosY + 38 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 50, PosY + 48 + posM, 25, 1, "Deaths:");

			this->DrawFormat(eGold,  PosX + 87, PosY + 8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 87, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 87, PosY + 48 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 50, PosY + 58 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 50, PosY + 68 + posM, 60, 1, "%s", classename);
		}
		else if (gProtect.m_MainInfo.RankUserType == 4)
		{

			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			pDrawBarForm((float)(PosX+2), (float)(PosY - 76), 75, 10, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eGold, PosX+7, PosY -75, 70, 3, "%s", this->m_Data[index].szTitleRank);
		}
		else 
		{
			glColor4f(0.0, 0.0, 0.0, 0.8);
			pDrawBarForm((float)(PosX+40), (float)(PosY - 8), 185, 80, 0.0f, 0);
			pGLSwitchBlend();

			this->DrawFormat(eRed2,		 PosX + 60, PosY - 6, 105, 3, "Character Status:");
		
			this->DrawFormat(eWhite,  PosX + 60, PosY + 8, 15, 1, "Lvl:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 18, 15, 1, "Str:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 28, 15, 1, "Agi:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 38, 15, 1, "Vit:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 48, 15, 1, "Ene:");
			this->DrawFormat(eWhite,  PosX + 60, PosY + 58, 15, 1, "Com:");

			this->DrawFormat(eGold,  PosX + 80, PosY +  8, 45, 1, "%d ", this->m_Data[index].m_Level);
			this->DrawFormat(eGold,  PosX + 80, PosY + 18, 45, 1, "%d ", this->m_Data[index].m_For);
			this->DrawFormat(eGold,  PosX + 80, PosY + 28, 45, 1, "%d ", this->m_Data[index].m_Agi);
			this->DrawFormat(eGold,  PosX + 80, PosY + 38, 45, 1, "%d ", this->m_Data[index].m_Vit);
			this->DrawFormat(eGold,  PosX + 80, PosY + 48, 45, 1, "%d ", this->m_Data[index].m_Ene);
			this->DrawFormat(eGold,  PosX + 80, PosY + 58, 45, 1, "%d ", this->m_Data[index].m_Com);

			int posM = 0;

			if(gProtect.m_MainInfo.RankUserShowReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 8, 25, 1,  "Resets:");
				this->DrawFormat(eGold,  PosX + 147, PosY + 8, 37, 1,  "%d", this->m_Data[index].m_Resets);	
			}
			else
			{
				posM -= 10;
			}

			if(gProtect.m_MainInfo.RankUserShowMasterReset != 0)
			{
				this->DrawFormat(eWhite,  PosX + 120, PosY + 18 + posM, 25, 1, gCustomMessage.GetMessage(68));
				this->DrawFormat(eGold,  PosX + 147, PosY + 18 + posM, 37, 1, "%d", this->m_Data[index].m_MResets);
			}
			else
			{
				posM -= 10;
			}

			this->DrawFormat(eWhite,  PosX + 120, PosY + 28 + posM, 25, 1, "Kills:");
			this->DrawFormat(eWhite,  PosX + 120, PosY + 38 + posM, 25, 1, "Deaths:");
			this->DrawFormat(eGold,  PosX + 147, PosY + 28 + posM, 37, 1, "%d", this->m_Data[index].m_Kills);
			this->DrawFormat(eGold,  PosX + 147, PosY + 38 + posM, 37, 1, "%d", this->m_Data[index].m_Deads);

			this->DrawFormat(eAncient,  PosX + 120, PosY + 48 + posM, 60, 1, "%s", this->m_Data[index].m_Vip);
			this->DrawFormat(eOrange,  PosX + 120, PosY + 58 + posM, 60, 1, "%s", classename);

			this->DrawFormat(eGold, PosX + 133, PosY -5, 126, 3, "%s", this->m_Data[index].szTitleRank);
			this->DrawFormat(eGold, PosX + 133, PosY + 59, 126, 3, "%s", name);
			pSetBlend(true);
			glColor3f(1.0, 1.0, 1.0);
			RenderBitmap(gInterface.Data[this->m_Data[index].m_Rank+1].ModelID, (float)PosX + 170, (float)PosY + 5, Return2X(TransForX(78)), 78,0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);
		}
	}

	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
}

int CCustomRankUser::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048] = {0};
	// ---
	int BuffLen = sizeof(Buff)-1;
	// ---
	ZeroMemory(Buff, BuffLen);
	// ---
	va_list args;
	// ---
	va_start(args, Text);
	// ---
	int Len = vsprintf_s(Buff, BuffLen, Text, args);
	// ---
	va_end(args);
	// ---
	int LineCount = 0;
	// ---
	char * Line = strtok(Buff, "\n");
	// ---
	while(Line != NULL)
	{
		pDrawColorText(Line, PosX, PosY, Width, 5, Color, 9, Align);
		// ---
		PosY += 10;
		// ---
		Line = strtok(NULL, "\n");
	}
	// ---
	return PosY;
}

void CCustomRankUser::GCReqRankLevelUser(PMSG_CUSTOM_RANKUSER * aRecv)
{
	if(aRecv == NULL)
	{
		return;
	}
	// ---
	this->m_Data[aRecv->iIndex].m_Enabled = true;
	this->m_Data[aRecv->iIndex].m_Level = aRecv->iLevel;
	this->m_Data[aRecv->iIndex].m_Resets = aRecv->iReset;
	this->m_Data[aRecv->iIndex].m_MResets = aRecv->iMReset;
	this->m_Data[aRecv->iIndex].m_Kills = aRecv->iKills;
	this->m_Data[aRecv->iIndex].m_Deads = aRecv->iDeads;
	this->m_Data[aRecv->iIndex].m_For = aRecv->iFor;
	this->m_Data[aRecv->iIndex].m_Agi = aRecv->iAgi;	
	this->m_Data[aRecv->iIndex].m_Ene = aRecv->iEne;
	this->m_Data[aRecv->iIndex].m_Vit = aRecv->iVit;
	this->m_Data[aRecv->iIndex].m_Com = aRecv->iCom;
	this->m_Data[aRecv->iIndex].m_Classe = aRecv->iClasse;
	this->m_Data[aRecv->iIndex].m_Rank = aRecv->iRank;
	this->m_Data[aRecv->iIndex].m_RankTitle1 = aRecv->m_RankTitle1;
	this->m_Data[aRecv->iIndex].m_RankTitle4 = aRecv->m_RankTitle4;
	this->m_Data[aRecv->iIndex].m_Lvtuchan = aRecv->iLvtuchan;
	this->m_Data[aRecv->iIndex].m_rcrit = aRecv->ircrit;
	this->m_Data[aRecv->iIndex].m_rexc = aRecv->irexc;
	this->m_Data[aRecv->iIndex].m_rdmg = aRecv->irdmg;
	this->m_Data[aRecv->iIndex].m_rdouble = aRecv->irdouble;
	// ---
	memcpy(this->m_Data[aRecv->iIndex].szTitleRank, aRecv->szName, sizeof(this->m_Data[aRecv->iIndex].szTitleRank));
	memcpy(this->m_Data[aRecv->iIndex].m_Vip, aRecv->iVip, sizeof(this->m_Data[aRecv->iIndex].m_Vip));
}

bool CPreviewManager::ObjCheck(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	if(!CS_GET_STRUCT(index, pThis))
	{
		return false;
	}
	// ---
	return true;
}

bool CPreviewManager::ObjSelect(int index, int pThis)
{
	if(pThis == NULL)
	{
		return false;
	}
	// ---
	this->Index = *(WORD*)(CS_GET_STRUCT(index, pThis) + 86);
	this->Live = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 616);
	this->Type = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 634);
	this->IsSafeZone = *(BYTE*)(CS_GET_STRUCT(index, pThis) + 14);
	// ---
	this->Angle.X = *(float*)(CS_GET_STRUCT(index, pThis) + 864);
	this->Angle.Y = *(float*)(CS_GET_STRUCT(index, pThis) + 868);
	this->Angle.Z = *(float*)(CS_GET_STRUCT(index, pThis) + 872) + *(float*)(CS_GET_STRUCT(index, pThis) + 836) + 100.0f;
	// ---
	return true;
}