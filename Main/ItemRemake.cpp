#include "stdafx.h"
#include "import.h"
#include "Defines.h"
#include "Object.h"
#include "zzzMathLib.h"
#include "LargeRand.h"
#include "ItemRemake.h"
#include "User.h"
#include "TMemory.h"
#include "Util.h"
#include "User.h"
#include "CustomEffectRemake.h"
#include "Central.h"

cCreateEffect gCreateEffect;

float sub_4EC46D(float a1, float a2)
{
	float v5;
	float v2 = a2 * 0.01745f;
	float v6 = (float)((int)(v2 * 1000.0f / a1 + timeGetTime()) % (int)(6283.185546875f / a1))* 0.001f * a1;

	if (v6 >= 3.14f)
	v5 = cosf(v6);
	else
	v5 = -cosf(v6);
	return (float)((v5 + 1.0f) * 0.5f);
}

double sub_639050(float a1)
{
	double result;

	if (a1 >= 0.0)
	result = a1;
	else
	result = -a1;
	return result;
}

double sub_4E7B95(float a1)
{
  return (float)sin(a1);
}

void CreateItemEffect(int lpModel, int ItemID, vec3_t Light, float Alpha, int ItemLevel, int NewOption, int a10, int a11, int RenderType)
{
	pSetItemEffect(lpModel, ItemID, Light, Alpha, ItemLevel, NewOption, a10, a11, RenderType);
	int v42; // eax@182

	LPVOID Model = pGetModel(pModelThis(), ItemID);
	vec3_t p;
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
	ZeroMemory(WorldPos, sizeof(WorldPos));
	ZeroMemory(Color, sizeof(Color));
	ZeroMemory(Bone, sizeof(Bone));
	ZeroMemory(p, sizeof(p));

	Vector(0.0f, 0.0f, 0.0f, p);
	Vector(WorldPos[0], WorldPos[1], WorldPos[2], WorldPos);
//-----------------------------------------------------------------------------
	REMAKE_EFFECT* lpInfo = gCustomRemake.GetInfoByItem(ItemID);
	if(lpInfo){
		switch(lpInfo->RemakeEffect){
			case 0:	//Blessed Divine Staff
//---------------------------------------------------------------------------------------------------------------------
{
	float v1158;
	float v1159;
	float v1700 = sub_4EC46D(-4.0, 0.0) + 0.5;
	Vector(v1700 * 1.0, v1700 * 0.8999999761581421, v1700 * 0.3499999940395355, Color);
	int JointID1[] = { 75,79,80,82,87,88,89 };
	for ( int l = 0; l < 7; ++l )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID1[l], 0.60000002, Color, lpModel);
		}
	for ( int m = 3; m < 18; ++m )
		{
		pQuickPlayStaticEffect(Model, 32002, m, 0.44999999, Color, lpModel);
		}
	for ( int n = 18; n < 46; ++n )
		{
			if ( n != 23 && n != 24 && n != 37 && n != 38 )
				{	
				pQuickPlayStaticEffect(Model, 32002, n, 0.44999999, Color, lpModel);
			}
		}
	Vector(v1700 * 0.949999988079071, v1700 * 0.1000000014901161, v1700 * 1.0, Color);
	int JointID2[] = { 77,78,90,91 };
	for ( int ii = 0; ii < 4; ++ii )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID2[ii], 0.40000001, Color, lpModel);
		}
	int JointID3[] = { 73,74,81,84 };
	for ( int jj = 0; jj < 4; ++jj )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID3[jj], 0.40000001, Color, lpModel);
		}
	pQuickPlayStaticEffect(Model, 32002, 1, 1.2, Color, lpModel);
	int JointID4[] = { 2,48,49,50 };
	for ( int kk = 0; kk < 4; ++kk )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID4[kk], 0.40000001, Color, lpModel);
		}
	int JointID5[] = { 76,83,85,86 };
	for ( int ll = 0; ll < 4; ++ll )
		{
		Vector(v1700 * 0.2000000029802322, v1700 * 0.2000000029802322, v1700 * 1.0, Color);
		pQuickPlayStaticEffect(Model, 32002, JointID5[ll], 0.2, Color, lpModel);
		Vector(v1700 * 1.0, v1700 * 1.0, v1700 * 1.0, Color);
		pQuickPlayStaticEffect(Model, 32229, JointID5[ll], 0.2, Color, lpModel);
		}
	Vector(v1700 * 0.2000000029802322, v1700 * 0.2000000029802322, v1700 * 1.0, Color);
	int JointID6[] = { 90,78 };
	for ( int mm = 0; mm < 2; ++mm )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID6[mm], 0.80000001, Color, lpModel);
		}
	Vector(v1700 * 0.2000000029802322, v1700 * 0.699999988079071, v1700 * 1.0, Color);
	for ( int nn = 54; nn < 70; ++nn )
		{
		pQuickPlayStaticEffect(Model, 32002, nn, 0.40000001, Color, lpModel);
		}
	float v311 = ((int) *(float*)0x5EF5A1C % 15) / 37.5;
	v1700 = v311 + 0.5;
	Vector(v1700 * 0.0, v1700 * 0.1000000014901161, v1700 * 1.0, Color);
	pQuickPlayStaticEffect(Model, 32002, 51, 4.0, Color, lpModel);
	pQuickPlayStaticEffect(Model, 32002, 51, 3.5999999, Color, lpModel);
	Vector(1.0, 1.0, 1.0, Color);
	float v1711 = ((int) (*(float*)0x5EF5A1C * 0.09000000357627869) % 90) * 0.01745329238474369;
	float v312 = v1711 + 1.570796370506287;
	float v313 = sub_4E7B95(v312);
	float v1698 = sub_639050(v313);
	float v314 = sub_4E7B95(v1711);
	float v1712 = sub_639050(v314) * 0.800000011920929;
	float v1701 = v1698 * 0.75;
	float v1702 = v1698 * 0.4000000059604645;
	float v1703 = v1698 * 1.0;
	Vector((1.399999976158142 - v1712) * *(float *)&v1701, (1.399999976158142 - v1712) * v1702, (1.399999976158142 - v1712) * v1703, Color);
	if ( v1712 - 0.2000000029802322 <= 0.0 )
	  v1159 = 0.0;
	else
	  v1159 = v1712 - 0.2000000029802322;
	float v315 = v1159;
	pQuickPlayStaticEffect(Model, 32614, 51, v315, Color, lpModel);
	v1711 = ((int) (*(float*)0x5EF5A1C * 0.09000000357627869 + 30.0) % 90)
	      * 0.01745329238474369;
	float v316 = sub_4E7B95(v1711);
	v1712 = sub_639050(v316) * 0.800000011920929;
	v1701 = v1698 * 0.75;
	v1702 = v1698 * 0.4000000059604645;
	v1703 = v1698 * 1.0;
	Vector((1.399999976158142 - v1712) * *(float *)&v1701, (1.399999976158142 - v1712) * v1702, (1.399999976158142 - v1712) * v1703, Color);
	if ( v1712 - 0.2000000029802322 <= 0.0 )
	  v1158 = 0.0;
	else
	  v1158 = v1712 - 0.2000000029802322;
	float v317 = v1158;
	pQuickPlayStaticEffect(Model, 32614, 51, v317, Color, lpModel);
}
				break;
			case 1:		//Blessed Divine Sword
{
	float v234 = sub_4EC46D(-4.0, 0.0);
	float v1875 = v234 * 0.5 + 0.5;
	Vector(v1875 * 0.4000000059604645, v1875 * 0.550000011920929, v1875 * 0.1500000059604645, Color);
	for ( int i43 = 53; i43 < 129; ++i43 )
		{
			pQuickPlayStaticEffect(Model, 32002, i43, 0.64999998, Color, lpModel);
		}
	float v237 = ((int) *(float*)0x5EF5A1C % 15) / 37.5;
	float v1879 = v237 + 0.5;
	Vector(v1879, v1879, v1879, Color);
	for ( int i44 = 4; i44 < 23; ++i44 )
		{
			pQuickPlayStaticEffect(Model, 32229, i44, 0.30000001, Color, lpModel);
		}
	pQuickPlayStaticEffect(Model, 32229, 47, 0.30000001, Color, lpModel);
	pQuickPlayStaticEffect(Model, 32229, 23, 0.30000001, Color, lpModel);
	Vector(v1875 * 0.8500000238418579, v1875 * 0.1000000014901161, v1875 * 0.8999999761581421, Color);
	pQuickPlayStaticEffect(Model, 32229, 45, 0.80000001, Color, lpModel);
	pQuickPlayStaticEffect(Model, 32229, 46, 0.80000001, Color, lpModel);
	pQuickPlayStaticEffect(Model, 32229, 28, 0.80000001, Color, lpModel);
	pQuickPlayStaticEffect(Model, 32229, 30, 0.80000001, Color, lpModel);
	Vector(v1875 * 0.1500000059604645, v1875 * 0.1500000059604645, v1875 * 0.8999999761581421, Color);
	int JointID1[] = { 27,32,29,43,34,40,37,35,25,41,42,44 };
	int JointID2[] = { 34,40,36,38 };
	for ( int i45 = 0; i45 < 12; ++i45 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID1[i45], 0.60000002, Color, lpModel);
		}
	for ( int i46 = 0; i46 < 4; ++i46 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID2[i46], 0.30000001, Color, lpModel);
		}
	if ( sub_4EC46D(-4.0, 0.0) + 0.5 <= 1.0 )
		float v1163 = 1.0;
	else
		float v1163 = sub_4EC46D(-4.0, 0.0) + 0.5;
	Vector(v1875 * 0.2000000029802322, v1875 * 0.300000011920929, v1875 * 1.0, Color);
	pQuickPlayStaticEffect(Model, 32114, 1, 1.4, Color, lpModel);
	
	//if ( !sub_50C004(a7) && sub_46AD6B(&dword_A1EE820) != 5 ) <<<(Faltan esos offsets) S13 1.18.89
	float ColorR[3] = { (int) *(float*)0x5EF5A1C % 11 * 0.1000000014901161 * v1875 + 0.699999988079071, (int) *(float*)0x5EF5A1C % 11 * 0.1000000014901161 * v1875 + 0.699999988079071, (int) *(float*)0x5EF5A1C % 11 * 0.1000000014901161 * v1875 + 0.699999988079071 };
	ColorR[GetLargeRand() % 3] = 0.69999999f;
	ColorR[GetLargeRand() % 3] = 1.0f;
	pAllowPlayEffect(Model, Bone, lpModel, 27, 0);
	float v240 = ((int) *(float*)0x5EF5A1C % 1441) * 0.25;
	pPlayStaticEffect(32805, Bone, 1.0, Color, lpModel, v240, 0);
	pAllowPlayEffect(Model, Bone, lpModel, 32, 0);
	float v241 = (double)(1440 - ((int) *(float*)0x5EF5A1C % 1441) * 0.25);
	pPlayStaticEffect(32805, Bone, 1.0, ColorR, lpModel, v241, 0);
	pAllowPlayEffect(Model, Bone, lpModel, 1, 0);
	WorldPos[0] = Bone[0] - WorldPos[0];
	WorldPos[1] = Bone[1] - WorldPos[1];
	WorldPos[2] = Bone[2] - WorldPos[2];
	gCreateEffect.DynamicEffectEx(52379, Bone, WorldPos, ColorR, 6, 1.0f, &*(ObjectModel*)*(DWORD*)lpModel);
}
//---------------------------------------------------------------------------------------------------------------------
				break;
			case 2:		//Blessed Divine CrossBow
{
	float v1161;
	float v269 = ((int) *(float*)0x5EF5A1C % 15) / 37.5;
	float v1792 = v269 + 0.5;
	int JointID1[] = { 7,8,9,10,11,12,13 };
	int JointID2[] = { 18,19,20,36,43,42,35,29,59,48,49,50 };
	int JointID3[] = { 41,34,54,56,57,58,24,25,27,28,53,23 };
	Vector( v1792 * 0.2000000029802322, v1792 * 0.300000011920929, v1792 * 1.0, Color);
	for ( int i14 = 0; i14 < 7; ++i14 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID1[i14], 0.80000001, Color, lpModel);
		}
	for ( int i15 = 0; i15 < 12; ++i15 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID2[i15], 1.0, Color, lpModel);
		}
	for ( int i16 = 0; i16 < 12; ++i16 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID3[i16], 1.4000001, Color, lpModel);
		}
	pQuickPlayStaticEffect(Model, 32002, 62, 3.0, Color, lpModel);
	int JointID4[] = { 51,52,21,22 };
	int JointID5[] = { 26,55 };
	Vector( v1792 * 1.0, v1792 * 0.6499999761581421, v1792 * 0.2000000029802322, Color);
	for ( int i17 = 0; i17 < 4; ++i17 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID4[i17], 1.2, Color, lpModel);
		}
	for ( int i18 = 0; i18 < 2; ++i18 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID5[i18], 1.8000001, Color, lpModel);
		}
	int JointID6[] = { 63,64 };
	if ( sub_4EC46D(-4.0, 0.0) * 0.5 + 0.5 >= 1.0 )
	  v1161 = 1.0;
	else
	  v1161 = sub_4EC46D(-4.0, 0.0) * 0.5 + 0.5;
	float v1782 = v1161;
	Vector( v1782 * 1.0, v1782 * 1.0, v1782 * 1.0, Color);
	for ( int i19 = 0; i19 < 2; ++i19 )
		{
		pQuickPlayStaticEffect(Model, 32002, JointID6[i19], 0.5, Color, lpModel);
		}
	pAllowPlayEffect(Model, Bone, lpModel, 62, 0);
	WorldPos[0] = Bone[0] - WorldPos[0];
	WorldPos[1] = Bone[1] - WorldPos[1];
	WorldPos[2] = Bone[2] - WorldPos[2];
	gCreateEffect.DynamicEffectEx(52229, Bone, WorldPos, Color, 6, 0.25f, &*(ObjectModel*)*(DWORD*)lpModel);
	float v1781 = ((int) *(float*)0x5EF5A1C % 360) * 0.25 * 0.01745329238474369;
	float v1783 = ((int) *(float*)0x5EF5A1C % 720) * 0.25 * 0.01745329238474369;
	float v1802 = sub_4E7B95(v1781);
	float v1774 = sub_4E7B95(v1783);
	if ( v1774 < 0.0 )
	  v1774 = v1774 * -1.0;
	float v277 =  v1802 * 1.0 * 360.0;
	float v278 = v1774 * 1.0 * 360.0;
	Vector( 0.0, 0.1, v1774 * 1.0, Color);
	pPlayStaticEffect(32271, Bone, 0.73000002, Color, lpModel, v277, 0);
	Vector( v1802 * 1.0, 0.1, 0.0, Color);
	pPlayStaticEffect(32271, Bone, 0.73000002, Color, lpModel, v278, 0);
	Vector( 0.0, 0.1, v1774 * 1.0, Color);
	pPlayStaticEffect(32271, Bone, 0.73000002, Color, lpModel, v277, 0);
	Vector( v1802 * 1.0, 0.1, 0.0, Color);
	pPlayStaticEffect(32271, Bone, 0.73000002, Color, lpModel, v278, 0);
	Vector( 0.0, 0.1, v1774 * 1.0, Color);
	pPlayStaticEffect(32271, Bone, 0.73000002, Color, lpModel, v277, 0);
	Vector( v1802 * 1.0, 0.1, 0.0, Color);
	pPlayStaticEffect(32271, Bone, 0.73000002, Color, lpModel, v278, 0);
}
//---------------------------------------------------------------------------------------------------------------------
				break;
			case 3:		//Blessed Divine Scepter
{
	float v1160;
	float v1742 = sub_4EC46D(-4.0, 0.0) + 0.5;
	Vector( v1742 * 1.0, v1742 * 0.8999999761581421, v1742 * 0.3499999940395355, Color);
	for ( int i35 = 26; i35 < 72; ++i35 )
		{
		pQuickPlayStaticEffect(Model, 32002, i35, 0.2, Color, lpModel);
		}
	for ( int i36 = 4; i36 < 15; ++i36 )
		{
		pQuickPlayStaticEffect(Model, 32002, i36, 0.5, Color, lpModel);
		}
	Vector( v1742 * 0.300000011920929, v1742 * 0.1000000014901161, v1742 * 1.0, Color);
	pQuickPlayStaticEffect(Model, 32002, 16, 0.80000001, Color, lpModel);
	pQuickPlayStaticEffect(Model, 32002, 1.55, 0.2, Color, lpModel);
	Vector( v1742 * 0.2000000029802322, v1742 * 0.2000000029802322, v1742 * 1.0, Color);
	for ( int i37 = 20; i37 < 24; ++i37 )
		{
		float v1735 = 0.5;
		if ( i37 == 22 || i37 == 23 )
		  v1735 = 1.0;
		float v284 = v1735 + v1735;
		pQuickPlayStaticEffect(Model, 32002, i37, v284, Color, lpModel);
		}
	float v285 = ((int) *(float*)0x5EF5A1C % 15) / 37.5;
	v1742 = v285 + 0.5;
	Vector( v1742 * 0.0, v1742 * 0.1000000014901161, v1742 * 1.0, Color);
	pQuickPlayStaticEffect(Model, 32118, 24, 1.0, Color, lpModel);
	Vector( v1742 * 1.0, v1742 * 0.2000000029802322, v1742 * 0.699999988079071, Color);
	pQuickPlayStaticEffect(Model, 32002, 24, 4.3000002, Color, lpModel);
	Vector( v1742 * 0.4000000059604645, v1742 * 0.4000000059604645, v1742 * 1.0, Color);
	pQuickPlayStaticEffect(Model, 32002, 24, 3.3, Color, lpModel);
	
	float v287 = sub_4EC46D(-4.0, 0.0);
	if ( v287 + 0.5 <= 1.0 )
	{
	  v1160 = 1.0;
	}
	else
	{
	  float v290 = sub_4EC46D(-4.0, 0.0);
	  v1160 = v290 + 0.5;
	}
	pAllowPlayEffect(Model, Bone, lpModel, 24, 0);
	v1742 = v1160;
	int v292 = (int) *(float*)0x5EF5A1C % 11;
	float ColorR[3] = { ((int) *(float*)0x5EF5A1C % 11) * 0.1000000014901161 * v1742 + 0.699999988079071, ((int) *(float*)0x5EF5A1C % 11) * 0.1000000014901161 * v1742 + 0.699999988079071, ((int) *(float*)0x5EF5A1C % 11) * 0.1000000014901161 * v1742 + 0.699999988079071 };
	ColorR[GetLargeRand() % 3] = 0.69999999f;
	ColorR[GetLargeRand() % 3] = 1.0f;
	float v1746 = ((int) *(float*)0x5EF5A1C % 11) * 0.07000000029802322 + 0.1000000014901161;
	float v300 = v1746;
	pPlayDynamicEffect(32805, Bone, WorldPos, ColorR, 0, v300, lpModel);
	gCreateEffect.DynamicEffectEx(52379, Bone, WorldPos, ColorR, 6, 1.0f, &*(ObjectModel*)*(DWORD*)lpModel);
	Vector( 0.30000001, 0.25, 1.0, Color);
	for ( int i38 = 0; i38 < 3; ++i38 )
		{
		float v305 = v1746;
		pPlayDynamicEffect(32394, Bone, WorldPos, Color, 0, v305 + 0.25f, lpModel);
		float v308 = v1746;
		pPlayDynamicEffect(32394, Bone, WorldPos, Color, 1, v308 + 0.25f, lpModel);
		}
}
//---------------------------------------------------------------------------------------------------------------------
				break;
			case 4:		//Blessed Divine Stick
{
	float v1162;
	float v244 = ((int) *(float*)0x5EF5A1C % 15) / 37.5;
	float v1847 = v244 + 0.5;
	Vector( v1847 * 0.2000000029802322, v1847 * 0.6000000238418579, v1847 * 1.0, Color);
	for ( int i1 = 12; i1 < 19; ++i1 )
		{
		pQuickPlayStaticEffect(Model, 32002, i1, 1.6, Color, lpModel);
		}
	pQuickPlayStaticEffect(Model, 32002, 8, 0.60000002, Color, lpModel);
	float v1846 = sub_4EC46D(-4.0, 0.0) + 0.2000000029802322;
	int JointID1[] = { 3,6,7,21,22,23 };
	Vector( v1846 * 1.0, v1846 * 1.0, v1846 * 1.0, Color);
	for ( int i2 = 0; i2 < 6; ++i2 )
		{
		pQuickPlayStaticEffect(Model, 32431, JointID1[i2], 0.80000001, Color, lpModel);
		}
	int JointID2[] = { 1,2,4,5 };
	for ( int i3 = 0; i3 < 4; ++i3 )
		{
		pQuickPlayStaticEffect(Model, 32231, JointID2[i3], 0.5, Color, lpModel);
		}
	Vector( v1847 * 0.0, v1847 * 0.1000000014901161, v1847 * 1.0, Color);
	pAllowPlayEffect(Model, Bone, lpModel, 24, 0);
	pPlayStaticEffect(32002, Bone, 3.7, Color, lpModel, 0.0, 0);
	v1846 = ((int) *(float*)0x5EF5A1C % 30 + 70) * 0.004999999888241291;
	Vector( v1846 * 0.2000000029802322, v1846 * 0.2000000029802322, v1846 * 0.8999999761581421, Color);
	pPlayStaticEffect(32131, Bone, 3.0, Color, lpModel, 0.0, 0);
	pPlayStaticEffect(32131, Bone, 5.0, Color, lpModel, 0.0, 0);
	pPlayStaticEffect(32115, Bone, 2.0, Color, lpModel, 0.0, 0);
	float v246 = *(float*)0x5EF5A1C * 0.003000000026077032;
	v1846 = (sub_4E7B95(v246) + 1.0) * 0.009999999776482582 + 0.5;
	float v1842 = v1846 * 0.25;
	float v1843 = v1846 * 0.4000000059604645;
	float v1844 = v1846 * 1.0;
	Vector( v1842 * 2.0, v1843 * 2.0, v1844 * 2.0, Color);
	float v248 = ((int) *(float*)0x5EF5A1C % 360);
	float v249 = v1846 * 1.0;
	pPlayStaticEffect(32140, Bone, v249, Color, lpModel, v248, 0);
	float v1831 = ((int)( *(float*)0x5EF5A1C * 0.09000000357627869) % 90) * 0.01745329238474369;
	float v250 = v1831 + 1.570796370506287;
	float v251 = sub_4E7B95(v250);
	float v1833 = sub_639050(v251);
	float v252 = sub_4E7B95(v1831);
	float v1849 = sub_639050(v252) * 0.800000011920929;
	Vector( (1.399999976158142 - v1849) * v1842, (1.399999976158142 - v1849) * v1843, (1.399999976158142 - v1849) * v1844, Color);
	pPlayStaticEffect(32140, Bone, v1849, Color, lpModel, 0.0, 0);
	v1831 = ((int)( *(float*)0x5EF5A1C * 0.09000000357627869 + 30.0) % 90)
	      * 0.01745329238474369;
	float v253 = sub_4E7B95(v1831);
	v1849 = sub_639050(v253) * 0.800000011920929;
	Vector( (1.399999976158142 - v1849) * v1842, (1.399999976158142 - v1849) * v1843, (1.399999976158142 - v1849) * v1844, Color);
	pPlayStaticEffect(32140, Bone, v1849, Color, lpModel, 0.0, 0);
	float v1864 = ((int) *(float*)0x5EF5A1C % 60) / 20.0 - 1.5;
	float v1834 = ((int) *(float*)0x5EF5A1C % 15) / 20.0 + 1.5;
	pPlayStaticEffect(32114, Bone, v1834, Color, lpModel, 0.0, 0);
	float v255 = v1834 - 0.300000011920929;
	pPlayStaticEffect(32114, Bone, v255, Color, lpModel, 90.0, 0);
	v1842 = v1846 * 0.2000000029802322;
	v1843 = v1846 * 0.2000000029802322;
	v1844 = v1846 * 1.0;
	Vector( v1842 * 2.0, v1843 * 2.0, v1844 * 2.0, Color);
	float v256 = v1834 - 0.800000011920929;
	pPlayStaticEffect(32501, Bone, v256, Color, lpModel, 0.0, 0);
	Vector( 0.1, 0.30000001, 1.0, Color);
	pPlayStaticEffect(32115, Bone, 1.3, Color, lpModel, 0.0, 0);
	
	if ( !((int) *(float*)0x5EF5A1C % 2) )
	{
		v1842 = v1846 * 0.699999988079071;
	    v1843 = v1846 * 0.800000011920929;
	    v1844 = v1846 * 1.0;
		Vector( v1842 * 2.0, v1843 * 2.0, v1844 * 2.0, Color);
		if ( v1846 + 0.0 >= 0.5 )
	      v1162 = 0.5;
	    else
	      v1162 = v1846 + 0.0;
	    float v267 = v1162;
		pPlayDynamicEffect(32113, Bone, WorldPos, Color, 7, v267, lpModel);
		}
	Vector( 0.0, 0.0, 1.0, Color);
	pPlayStaticEffect(32614, Bone, 0.5, Color, lpModel, 0.0, 0);
}
//---------------------------------------------------------------------------------------------------------------------
				break;
		}
	}
}

DYNAMIC_EFFECT_INFO *m_DynamicEffectInfo = (DYNAMIC_EFFECT_INFO*)0x8907508;

int cCreateEffect::DynamicEffectEx(DWORD ModelID, vec3_t VecPos, vec3_t WorldPos, vec3_t Color, int SubEffectID, float Scale, ObjectModel* lpModel)
{
	DYNAMIC_EFFECT_INFO *lpEffect;

	for (int i = 0; i < 3000; ++i)
	{
		lpEffect = &m_DynamicEffectInfo[i];
		if (!lpEffect->Enable)
			break;
	}

	if (!lpEffect)
	{
		return 0;
	}

	lpEffect->Enable = 1;
	lpEffect->EffectID = ModelID;
	lpEffect->TextureID = ModelID;
	lpEffect->SubEffectID = SubEffectID;
	lpEffect->VecPos.X = VecPos[0];
	lpEffect->VecPos.Y = VecPos[1];
	lpEffect->VecPos.Z = VecPos[2];
	lpEffect->VecPos2.X = VecPos[0];
	lpEffect->VecPos2.Y = VecPos[1];
	lpEffect->VecPos2.Z = VecPos[2];
	lpEffect->Color.X = Color[0];
	lpEffect->Color.Y = Color[1];
	lpEffect->Color.Z = Color[2];
	lpEffect->Scale = Scale;
	lpEffect->Unknown80 = 0.0;
	lpEffect->Unknown60 = 2;
	lpEffect->Unknown72 = 0;
	lpEffect->m_Owner = lpModel;
	lpEffect->Unknown68 = 0.0;
	lpEffect->Unknown76 = 1;
	
	lpEffect->WorldPos.X = WorldPos[0];
	lpEffect->WorldPos.Y = WorldPos[1];
	lpEffect->WorldPos.Z = WorldPos[2];
	lpEffect->Unknown84.X = 0.0;
	lpEffect->Unknown84.Y = 0.0;
	lpEffect->Unknown84.Z = 0.0;

	switch (lpEffect->EffectID)
	{
		case 32587: //shiny06
			if (lpEffect->SubEffectID)
			{
				if (lpEffect->SubEffectID > 0 && lpEffect->SubEffectID <= 3)
				{
					lpEffect->Unknown60 = GetLargeRand() % 11 + 20;
					lpEffect->Unknown56 = 0.0;
					lpEffect->Unknown68 = (float)(GetLargeRand() % 180);
					lpEffect->Scale = Scale - (float)(GetLargeRand() % 6) * (Scale / 10.0f);

					switch (lpEffect->SubEffectID)
					{
						case 1:
							lpEffect->VecPos.X = (float)(GetLargeRand() % 31) - 15.0f + lpEffect->VecPos.X;
							lpEffect->VecPos.Y = (float)(GetLargeRand() % 31) - 15.0f + lpEffect->VecPos.Y;
							lpEffect->VecPos.Z = (float)(GetLargeRand() % 21) + 12.0f + lpEffect->VecPos.Z;
							break;
						case 2:
							lpEffect->VecPos.X = (float)(GetLargeRand() % 31) / 30.0f * 40.0f - 20.0f + lpEffect->VecPos.X;
							lpEffect->VecPos.Y = (float)(GetLargeRand() % 31) / 30.0f * 40.0f - 20.0f + lpEffect->VecPos.Y;
							lpEffect->VecPos.Z = (float)(GetLargeRand() % 24) + 14.0f + lpEffect->VecPos.Z;
							break;
						case 3:
							lpEffect->VecPos.X = (float)(GetLargeRand() % 31) / 30.0f * 70.0f - 35.0f + lpEffect->VecPos.X;
							lpEffect->VecPos.Y = (float)(GetLargeRand() % 31) / 30.0f * 70.0f - 35.0f + lpEffect->VecPos.Y;
							lpEffect->VecPos.Z = (float)(GetLargeRand() % 30) + 20.0f + lpEffect->VecPos.Z;
							break;
					}
				} else
				{
					switch (lpEffect->SubEffectID)
					{
						case 4:
							break;
						case 6:
							lpEffect->Unknown60 = 15;
							lpEffect->Unknown68 = (float)(GetLargeRand() % 360);
							lpEffect->Unknown84.X = (float)-(GetLargeRand() % 2 - 1);
							lpEffect->Unknown84.Y = (float)-(GetLargeRand() % 4);
							lpEffect->Unknown84.Z = (float)-(GetLargeRand() % 4);
							break;
						case 7:
							lpEffect->Scale = 0.1;
							lpEffect->VecPos2.X = Scale;
							lpEffect->Unknown60 = GetLargeRand() % 10 + 20;
							lpEffect->VecPos.X = (float)(GetLargeRand() % 50 - 25) + lpEffect->VecPos.X;
							lpEffect->VecPos.Y = (float)(GetLargeRand() % 50 - 25) + lpEffect->VecPos.Y;
							lpEffect->VecPos.Z = (float)(GetLargeRand() % 50 - 25) + lpEffect->VecPos.Z;
							lpEffect->Unknown80 = 1.0;
							lpEffect->WorldPos.X = (float)(GetLargeRand() % 360);
							lpEffect->WorldPos.Y = (float)(GetLargeRand() % 360);
							lpEffect->WorldPos.Z = (float)(GetLargeRand() % 360);
							lpEffect->Unknown68 = (float)(GetLargeRand() % 20 - 10);
							break;
					}
				}
			}
			else
			{
				lpEffect->Unknown60 = 18;
				lpEffect->WorldPos.X = 45.0;
			}
			break;

		case 52379: //hikorora Custom
			if (lpEffect->SubEffectID)
			{
				switch (lpEffect->SubEffectID)
				{
					case 1:
					case 2:
						lpEffect->Unknown60 = 15;
						lpEffect->Scale = 0.2;
						break;
					case 3:
						lpEffect->Scale = 0.0;
						lpEffect->Unknown60 = 35;
						break;
					case 4:
						lpEffect->Unknown68 = (float)(GetLargeRand() % 360);
						lpEffect->Unknown60 = 5;
						lpEffect->Scale = 1.2;
						break;
					case 5:
					case 6:
						lpEffect->Unknown60 = 6;
						lpEffect->Unknown68 = (int) (*(float*)0x5EF5A1C * 0.75f) % 360;
						lpEffect->Unknown72 = 2;
						lpEffect->Scale = Scale - (float)(GetLargeRand() % 6) * (Scale / 10.0f) + 0.3;
						break;
				}
			}
			else
			{
				lpEffect->Unknown60 = 100;
				lpEffect->Scale = 0.2;
			}
			break;

		case 52229: //flareBlue Custom
			if (lpEffect->SubEffectID)
			{
				switch (lpEffect->SubEffectID)
				{
					case 6:
					lpEffect->Unknown56 = 1.0;
					lpEffect->Unknown84.X = (float)(GetLargeRand() % 8) + -4.0;
					lpEffect->Unknown84.Y = (float)(GetLargeRand() % 4);
					lpEffect->Unknown84.Z = (float)(GetLargeRand() % 8) + -4.0;
					lpEffect->Unknown60 = 12;
					lpEffect->Scale = Scale - (float)(GetLargeRand() % 4) * (Scale / 10.0f);
					break;
				}
			}
			break;
		case 52230: //flareBlue Custom
			if (lpEffect->SubEffectID)
			{
				switch (lpEffect->SubEffectID)
				{
					case 6:
					lpEffect->Unknown56 = 1.0;
					lpEffect->Unknown84.X = (float)(GetLargeRand() % 8) + -4.0;
					lpEffect->Unknown84.Y = (float)(GetLargeRand() % 4);
					lpEffect->Unknown84.Z = (float)(GetLargeRand() % 8) + -4.0;
					lpEffect->Unknown60 = 12;
					lpEffect->Scale = Scale - (float)(GetLargeRand() % 4) * (Scale / 10.0f);
					break;
				}
			}
			break;
	}
	return 0;
}

/*
//----- (00610590) --------------------------------------------------------
void __usercall sub_610590(FARPROC (__stdcall *a1)(HMODULE hModule, LPCSTR lpProcName)@<ebx>, unsigned __int8 *a2@<edi>, DWORD *a3@<esi>, int a4)
{
  float v4; // [sp+38h] [bp-24h]@5
  signed int i; // [sp+54h] [bp-8h]@1
  int v6; // [sp+58h] [bp-4h]@3

  for ( i = 0; i < 2; ++i )
  {
    v6 = a4 + 36 * i + 448;
    if ( sub_50E750((int)&unk_EBCD98, (int)a1, (int)a2, (int)a3, *(WORD *)v6) == 1206 )
    {
      if ( i )
        v4 = 100.0;
      else
        v4 = 80.0;
      *(BYTE *)(v6 + 5) = 28;
      sub_5655C0(a1, a2, a3, v4, 10.0, -75.0, a4, v6, 618, 0, 0, 1, 1, 0, 1);
    }
  }
}

void ModelLinkObject(int a1)
{
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
	float v165;
	int v276 = a1 + 776;
	
	if ( a1 != -776 )
	{
		int v2 = *(DWORD *)(v276 + 48);
		pModelThis();
		LPVOID v6 = pGetModel(pModelThis(), v2);
		if ( v6 )
		{
			int v278;
			for ( int i = 0; i < 2; ++i )
			{
				v278 = a1 + 36 * i + 448;
				if ( EqualItemModelType((int*)0xEBCD98,*(WORD *)v278) == ITEM2(0,61) ) //Blessed Claw
				{
					int v154;
					if ( i )
						v154 = GetBoneTransform(v276, 38);
					else
						v154 = GetBoneTransform(v276, 29);
					int v184 = v154;
					if ( v154 )
					{
						int v122 = v276;
						float v92 = (double)(rand() % 15) / 37.5;
						float v183 = v92 + 0.5;

						Vector(v183 * 1.0, v183 * 1.0, v183 * 1.0, Color);

						Vector( -14.0, -8.0, 0.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32229, Bone, 0.60000002, Color, v122, 0.0, 0);

						Vector( -4.0, 6.0, -14.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32229, Bone, 0.40000001, Color, v122, 0.0, 0);

						CreateSprite(42134, Bone, 1.0, Color, v122, 0.0, 0);
						Vector( -9.0, 2.0, 15.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32229, Bone, 0.40000001, Color, v122, 0.0, 0);

						Vector( 2.0, 10.0, 0.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32229, Bone, 0.60000002, Color, v122, 0.0, 0);

						Vector(v183 * 0.25, v183 * 0.34999999, v183 * 0.75, Color);

						Vector( -44.0, 12.0, -4.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32309, Bone, 2.0, Color, v122, 0.0, 0);

						Vector( -62.0, 26.0, -7.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32309, Bone, 0.60000002, Color, v122, 0.0, 0);

						Vector( -49.0, 30.0, -22.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32309, Bone, 1.1, Color, v122, 0.0, 0);

						Vector( -52.0, 24.0, 15.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32309, Bone, 1.1, Color, v122, 0.0, 0);

						Vector( -34.0, 18.0, -22.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32309, Bone, 0.80000001, Color, v122, 0.0, 0);

						Vector( -41.0, 15.0, 15.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32309, Bone, 0.80000001, Color, v122, 0.0, 0);

						Vector( 0.0, -2.0, 2.0, WorldPos);
						TransformPosition(v6, v184, WorldPos, Bone, 1);
						CreateSprite(32309, Bone, 2.5999999, Color, v122, 0.0, 0);

						Vector(v183 * 0.69999999, v183 * 0.5, v183 * 0.15000001, Color);

						float v149 = ((int)*(float*)0x5EF5A1C % 360) * 0.05000000074505806;
						CreateSprite(32309, Bone, 0.23, Color, v122, v149, 0);
					}
				}
			}
		}
	}

	pClawEffect(a1);
}*/

void cCreateEffect::Load()
{
	//SetCompleteHook(0xE8,0x005765BF,&ModelLinkObject);
	//MemorySet(0x005765B4, 0x90, 0x04);
	//SetByte((PVOID)(0x0057657E+6), 0x1);

	SetCompleteHook(0xE8, 0x0061041C, &CreateItemEffect);
	SetCompleteHook(0xE8, 0x005666C1, &CreateItemEffect);
}