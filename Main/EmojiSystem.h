#pragma once

#pragma comment(lib, "MUEmoji.lib")

#define pLoadImage ((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)

namespace myheart
{
	namespace MUEmoji
	{
		void Init(int t1, int t2, int t3, float cs, float hs, int sc, int sh);
		void SetTokenInfo(void* lpInfo, int Count);
		void AddTexture(int Index, int Max);
		BOOL GetMouseFocus();
	}
}

enum eEmojiTextures
{
	TEXTURE_START_INDEX = 100000,
	TEXTURE_EMOJI_LIST1,
	TEXTURE_EMOJI_LIST2,
	TEXTURE_EMOJI_LIST3,
	TEXTURE_EMOJI_LIST_BTN,
	TEXTURE_EMOJI_LIST_ON,
	TEXTURE_EMOJI_LIST_ARROW,
};

class CEmojis
{
public:

	CEmojis();

	~CEmojis();

	void LoadImages();

	void AddTextures();
};

extern CEmojis gEmojis;