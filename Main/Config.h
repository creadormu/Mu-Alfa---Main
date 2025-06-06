#ifndef _Config_H
#define _Config_H


class cConfig
{
public:
	void Load();
	//===================================================
	char TextVN_DanhHieu[120][120];
	char TextVN_QuanHam[120][120];
	char TextVN_TuLuyen[210][210];
	char TextVN_MuaVip[120][120];
	char TextVN_DoiGioiTinh[120][120];
	char MenuTuChan_TextNVT[120][120];

	int TuChan[20];
	char TuChanText[40][120];
#endif
	//===================================================
};
//===================================================
#define TEXTVN_FILE "./Data/Custom/TextVN.dat"
#define TUCHAN_FILE "./Data/Custom/TuChan.ini"

//===================================================
extern cConfig Config;

