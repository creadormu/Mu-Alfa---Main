#include "stdafx.h"
#include "CustomRankUser.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Protect.h"
#include "Import.h"
#include "Common.h" // Para HpMonsterBar

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

// ... (ClearNewHealthBar, InsertNewHealthBar, GetNewHealthBar SIN CAMBIOS respecto a tu última versión) ...
void ClearNewHealthBar() 
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
		gNewHealthBar[n].rate2 = 0;
	}
}

void InsertNewHealthBar(WORD index,BYTE type,BYTE rate,BYTE rate2) 
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = index;
			gNewHealthBar[n].type = type;
			gNewHealthBar[n].rate = rate;
			gNewHealthBar[n].rate2 = rate2;
			return;
		}
	}
}

NEW_HEALTH_BAR* GetNewHealthBar(WORD index,BYTE type) 
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index != 0xFFFF)
		{
			// En tu código original, comparabas el 'type' del gNewHealthBar con el 'type' pasado.
			// Este 'type' pasado es el viewportObjectType.
			// Si el type en gNewHealthBar (que viene del server) es diferente al del viewport, no se encontrará.
			// Por ahora, mantendremos esta lógica.
			if(gNewHealthBar[n].index == index && gNewHealthBar[n].type == type) 
			{
				return &gNewHealthBar[n];
			}
		}
	}
	return 0;
}


void DrawNewHealthBar() 
{
	int PosX, PosY, LifeProgress, ShieldProgress;
	VAngle Angle;

	const float OriginalLifeBarWidth = 80.0f;
	const float OriginalSegmentWidth = 8.0f; 
	const float ReductionFactor = 0.50f; // Objetivo de reducción

	const float ReducedLifeBarWidth = OriginalLifeBarWidth * ReductionFactor; 
	const float ReducedSegmentWidth = OriginalSegmentWidth * ReductionFactor; 

	// Lógica de barra de Party (como estaba)
	if (gProtect.m_MainInfo.DisablePartyHpBar == 1) { /* ... tu código ... */ }
	else if (gProtect.m_MainInfo.DisablePartyHpBar == 2) { /* ... tu código ... */ }
	else { ((void(*)())0x005BA770)(); }
	
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		gObjUser.m_Logo[n].Active = 0; 
		
		if(!ViewportAddress || *(BYTE*)(ViewportAddress+0x30C) == 0) 
		{
			continue;
		}

		Angle.X = *(float*)(ViewportAddress+0x404);
		Angle.Y = *(float*)(ViewportAddress+0x408);
		Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;
		
		pGetPosFromAngle(&Angle, &PosX, &PosY);
	 
		BYTE viewportObjectType = *(BYTE*)(ViewportAddress+0x320); 
		WORD objectIndex = *(WORD*)(ViewportAddress+0x7E); // Índice del objeto en el viewport

		if (viewportObjectType == 0) // Asumiendo 0 = Player 
        {
          gCustomRankUser.RenderShowLogRank(ViewportAddress, objectIndex, PosX - 42,PosY);
			gObjUser.m_Logo[n].Active = 1;
			gObjUser.m_Logo[n].X = PosX;
			gObjUser.m_Logo[n].Y = PosY;
        }

		// Usar el viewportObjectType para buscar en gNewHealthBar, ya que este es el tipo que el cliente "ve"
		NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(objectIndex, viewportObjectType); 
		
		// --- INICIO DEBUG VISUAL ---
//		if (lpNewHealthBar != 0) // Si se encontró una entrada en gNewHealthBar
//		{
//			char szDebugInfo[128];
//			sprintf_s(szDebugInfo, sizeof(szDebugInfo), "ObjIdx:%d ViewT:%d BarT:%d HP:%d%%", 
//                      objectIndex, viewportObjectType, lpNewHealthBar->type, lpNewHealthBar->rate);
//			
//			int debugPosX = PosX - 30; 
//			int debugPosY = PosY - 35; 
//
//            pSetBackgroundTextColor(pTextThis(),0,0,0,0); // Fondo transparente para texto
//			pSetTextColor(pTextThis(), 255, 255, 0, 255); // Amarillo
//			pDrawText(pTextThis(), debugPosX, debugPosY, szDebugInfo, 0, 0, (LPINT)3, 0); 
//		} else if (viewportObjectType != 0) { // Si no es jugador y no se encontró barra
//            char szDebugInfo[64];
//            sprintf_s(szDebugInfo, sizeof(szDebugInfo), "ObjIdx:%d ViewT:%d NoBar", objectIndex, viewportObjectType);
//            int debugPosX = PosX - 30;
//            int debugPosY = PosY - 35;
//            pSetBackgroundTextColor(pTextThis(),0,0,0,0);
//            pSetTextColor(pTextThis(), 255, 100, 100, 255); // Rojo claro si no hay barra
//            pDrawText(pTextThis(), debugPosX, debugPosY, szDebugInfo, 0, 0, (LPINT)3, 0);
//        }
		// --- FIN DEBUG VISUAL ---
		
		if(lpNewHealthBar == 0)
		{
			continue; // Si no hay datos de barra para este objeto, no dibujar nada más.
		}

		// Condición del Settings.ini
		if (viewportObjectType == 1 && HpMonsterBar == 0) // Si es monstruo Y la barra de monstruos está desactivada
		{
			continue; 
		}

		float currentLifeBarWidthToUse;
		float currentSegmentWidthToUse;

		// Aplicar reducción SOLO A MONSTRUOS (basado en viewportObjectType)
		// ¡¡¡ASEGÚRATE QUE '1' ES EL TIPO CORRECTO PARA MONSTRUOS EN TU CLIENTE!!!
		if (viewportObjectType == 2) // Es un Monstruo
		{
			currentLifeBarWidthToUse = ReducedLifeBarWidth;
			currentSegmentWidthToUse = ReducedSegmentWidth;
		}
		else // Jugadores (type 0), NPCs (type 2+), etc.
		{
			currentLifeBarWidthToUse = OriginalLifeBarWidth;
			currentSegmentWidthToUse = OriginalSegmentWidth;
		}

		int finalPosX = PosX - (int)floor(currentLifeBarWidthToUse / 2.0);
		int finalPosY = PosY - 16; 

		int LifePercent = lpNewHealthBar->rate/10;
		int ShieldPercent = lpNewHealthBar->rate2/10;

		// El resto del código de dibujo de barras (contenedor de escudo, barra de vida, barra de escudo)
		// se mantiene igual que en la respuesta anterior, usando currentLifeBarWidthToUse y currentSegmentWidthToUse.
		// ... (código de dibujo de barras aquí, idéntico al de mi respuesta anterior) ...
		if (viewportObjectType == 0 && ShieldPercent > 0) 
		{
			pSetBlend(true);
			glColor4f(0.0f, 0.0f, 0.0f, 0.5f); 
			pDrawBarForm((float)(finalPosX - 3), (float)(finalPosY), currentLifeBarWidthToUse + 6.0f, 10.0f, 0.0f, 0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0); 
			pSetBlend(false);
		}
		
		pSetBlend(true); 

		glColor3f(0.2f, 0.0f, 0.0f);
		pDrawBarForm((float)finalPosX, (float)(finalPosY + 2), currentLifeBarWidthToUse, 2.0f, 0.0f, 0);

		if(LifePercent > 10) LifeProgress = 10; else LifeProgress = LifePercent;
		
		glColor3f(0.98039216f, 0.039215688f, 0.0f); 
		for(int i = 0; i < LifeProgress; i++)
		{
			float segmentDrawWidth = currentSegmentWidthToUse;
			if ( ( (i + 1) * currentSegmentWidthToUse ) > currentLifeBarWidthToUse && i == LifeProgress -1 ) {
				 segmentDrawWidth = currentLifeBarWidthToUse - (i * currentSegmentWidthToUse);
			}
			if (segmentDrawWidth < 0.001f) continue; 

			pDrawBarForm((float)(i * currentSegmentWidthToUse + finalPosX), (float)(finalPosY + 2), segmentDrawWidth, 2.0f, 0.0f, 0);
		}
											
		if (viewportObjectType == 0 && ShieldPercent > 0) 
		{
			glColor3f(0.22039216f, 0.239215688f, 0.0f); 
			pDrawBarForm((float)finalPosX, (float)(finalPosY + 6), currentLifeBarWidthToUse, 2.0f, 0.0f, 0);

			if(ShieldPercent > 10) ShieldProgress = 10; else ShieldProgress = ShieldPercent;
			
			glColor3f(0.98f, 0.8f, 0.0f); 
			for(int i = 0; i < ShieldProgress; i++)
			{
				float segmentDrawWidth = currentSegmentWidthToUse;
                if ( ( (i + 1) * currentSegmentWidthToUse ) > currentLifeBarWidthToUse && i == ShieldProgress -1 ) {
                     segmentDrawWidth = currentLifeBarWidthToUse - (i * currentSegmentWidthToUse);
                }
                if (segmentDrawWidth < 0.001f) continue;

				pDrawBarForm((float)(i * currentSegmentWidthToUse + finalPosX), (float)(finalPosY + 6), segmentDrawWidth, 2.0f, 0.0f, 0);
			}
		}
		pGLSwitch(); 
	}

	gCustomRankUser.DrawInfo(); 
	glColor3f(1.0, 1.0, 1.0); 
}