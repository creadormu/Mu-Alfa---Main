// Protect.cpp: implementation of the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Protect.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Util.h"

CProtect gProtect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProtect::CProtect() // OK
{

}

CProtect::~CProtect() // OK
{

}

bool CProtect::ReadPetEffectBMD(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name, &this->m_ReadBMDFileCRC, 1024) == 0) { return 0; }

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if(file == INVALID_HANDLE_VALUE) { return 0; }

	if(GetFileSize( file, 0 ) != sizeof( PETEFFECT_BMD ))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile( file, &this->m_ReadBMD, sizeof(PETEFFECT_BMD), &OutSize, 0 ) == 0)
	{
		CloseHandle( file );
		return 0;
	}

	for( int n = 0 ; n < sizeof( PETEFFECT_BMD ) ; n++ )
	{
		((BYTE*)&this->m_ReadBMD)[n] += (BYTE)(0x85^HIBYTE(n));
		((BYTE*)&this->m_ReadBMD)[n] ^= (BYTE)(0xFA^LOBYTE(n));
	}

	CloseHandle( file );
	return 1;
}
//--
bool CProtect::ReadTooltipTRSData(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name, &this->m_ReadTooltipTRSDataFileCRC, 1024) == 0) { return 0; }

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if(file == INVALID_HANDLE_VALUE) { return 0; }

	if(GetFileSize( file, 0 ) != sizeof( TOOLTIP_BMD ))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile( file, &this->m_ReadTooltipTRSData, sizeof(TOOLTIP_BMD), &OutSize, 0 ) == 0)
	{
		CloseHandle( file );
		return 0;
	}

	for( int n = 0 ; n < sizeof( TOOLTIP_BMD ) ; n++ )
	{
		((BYTE*)&this->m_ReadTooltipTRSData)[n] += (BYTE)(0x85^HIBYTE(n));
		((BYTE*)&this->m_ReadTooltipTRSData)[n] ^= (BYTE)(0xFA^LOBYTE(n));
	}

	CloseHandle( file );
	return 1;
}
//--
bool CProtect::ReadMakeViewTRSData(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name, &this->m_MakeViewTRSDataFileCRC, 1024) == 0) { return 0; }

	HANDLE file = CreateFile(name, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0);

	if(file == INVALID_HANDLE_VALUE) { return 0; }

	if(GetFileSize( file, 0 ) != sizeof( RENDER_MAKE_VIEW ))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile( file, &this->m_MakeViewTRSData, sizeof(RENDER_MAKE_VIEW), &OutSize, 0 ) == 0)
	{
		CloseHandle( file );
		return 0;
	}

	for( int n = 0 ; n < sizeof( RENDER_MAKE_VIEW ) ; n++ )
	{
		((BYTE*)&this->m_MakeViewTRSData)[n] += (BYTE)(0x85^HIBYTE(n));
		((BYTE*)&this->m_MakeViewTRSData)[n] ^= (BYTE)(0xFA^LOBYTE(n));
	}

	CloseHandle( file );
	return 1;
}
//--
bool CProtect::ReadMainFile(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name,&this->m_ClientFileCRC,1024) == 0)
	{
		return 0;
	}

	HANDLE file = CreateFile(name,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,0);

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	if(GetFileSize(file,0) != sizeof(MAIN_FILE_INFO))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile(file,&this->m_MainInfo,sizeof(MAIN_FILE_INFO),&OutSize,0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	for(int n=0;n < sizeof(MAIN_FILE_INFO);n++)
	{
		((BYTE*)&this->m_MainInfo)[n] += (BYTE)(0x95^HIBYTE(n));
		((BYTE*)&this->m_MainInfo)[n] ^= (BYTE)(0xDA^LOBYTE(n));
	}

	CloseHandle(file);
	return 1;
}
//--
void CProtect::CheckLauncher() // OK
{
	if((this->m_MainInfo.LauncherType & 1) == 0)
	{
		return;
	}

	if (FindWindow(0, gProtect.m_MainInfo.LauncherName) == 0)
	{
		ExitProcess(0);
	}
}
//--
void CProtect::CheckInstance() // OK
{
	if((this->m_MainInfo.LauncherType & 2) == 0)
	{
		return;
	}

	char buff[256];

	wsprintf(buff,"XTEAM_MAIN_10405_%s",this->m_MainInfo.IpAddress);

	if(OpenMutex(MUTEX_ALL_ACCESS,0,buff) == 0)
	{
		CreateMutex(0,0,buff);
	}
	else
	{
		ExitProcess(0);
	}
}
//--
void CProtect::CheckClientFile() // OK
{
	if(this->m_MainInfo.ClientCRC32 == 0)
	{
		return;
	}

	char name[MAX_PATH] = {0};

	if(GetModuleFileName(0,name,sizeof(name)) == 0)
	{
		ExitProcess(0);
	}

	if(_stricmp(ConvertModuleFileName(name),this->m_MainInfo.ClientName) != 0)
	{
		ExitProcess(0);
	}

	CCRC32 CRC32;

	DWORD ClientCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.ClientName,&ClientCRC32,1024) == 0)
	{
		MessageBox(0,"Main.exe CRC error!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.ClientCRC32 != ClientCRC32)
	{
		MessageBox(0,"Main.exe CRC error!","Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
}
//--
void CProtect::CheckHackFile() // OK
{
	
	if(this->m_MainInfo.HackCRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	char ErrorBuff[50];

	DWORD PluginCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.HackName,&PluginCRC32,1024) == 0)
	{
		sprintf(ErrorBuff, "AntiHack %s CRC error!", this->m_MainInfo.HackName);
		MessageBox(0,ErrorBuff,"Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.HackCRC32 != PluginCRC32)
	{
		sprintf(ErrorBuff, "AntiHack %s CRC error!", this->m_MainInfo.HackName);
		MessageBox(0,ErrorBuff,"Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.HackName);

	if(module == 0)
	{
		sprintf(ErrorBuff, "AntiHack %s CRC error!", this->m_MainInfo.HackName);
		MessageBox(0,ErrorBuff,"Error Antihack",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
//--
void CProtect::CheckPluginFile1() // OK
{
	if(this->m_MainInfo.Plugin1CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	char ErrorBuff[50];

	DWORD PluginCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName1,&PluginCRC32,1024) == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName1);
		MessageBox(0,ErrorBuff,"Error Plugin1",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin1CRC32 != PluginCRC32)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName1);
		MessageBox(0,ErrorBuff,"Error Plugin1",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName1);

	if(module == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName1);
		MessageBox(0,ErrorBuff,"Error Plugin1",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
//--
void CProtect::CheckPluginFile2() // OK
{
	if(this->m_MainInfo.Plugin2CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;
	char ErrorBuff[50];

	DWORD PluginCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName2,&PluginCRC32,1024) == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName2);
		MessageBox(0,ErrorBuff,"Error Plugin2",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin2CRC32 != PluginCRC32)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName2);
		MessageBox(0,ErrorBuff,"Error Plugin2",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName2);

	if(module == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName2);
		MessageBox(0,ErrorBuff,"Error Plugin2",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
//--
void CProtect::CheckPluginFile3() // OK
{
	if(this->m_MainInfo.Plugin3CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	char ErrorBuff[50];

	DWORD PluginCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName3,&PluginCRC32,1024) == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName3);
		MessageBox(0,ErrorBuff,"Error Plugin3",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin3CRC32 != PluginCRC32)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName3);
		MessageBox(0,ErrorBuff,"Error Plugin3",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName3);

	if(module == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName3);
		MessageBox(0,ErrorBuff,"Error Plugin3",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
//--
void CProtect::CheckPluginFile4() // OK
{
	if(this->m_MainInfo.Plugin4CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	char ErrorBuff[50];

	DWORD PluginCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName4,&PluginCRC32,1024) == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName4);
		MessageBox(0,ErrorBuff,"Error Plugin4",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin4CRC32 != PluginCRC32)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName4);
		MessageBox(0,ErrorBuff,"Error Plugin4",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName4);

	if(module == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName4);
		MessageBox(0,ErrorBuff,"Error Plugin4",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
//--
void CProtect::CheckPluginFile5() // OK
{
	if(this->m_MainInfo.Plugin5CRC32 == 0)
	{
		return;
	}

	char ErrorBuff[50];

	CCRC32 CRC32;

	DWORD PluginCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName5,&PluginCRC32,1024) == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName5);
		MessageBox(0,ErrorBuff,"Error Plugin5",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin5CRC32 != PluginCRC32)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName5);
		MessageBox(0,ErrorBuff,"Error Plugin5",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName5);

	if(module == 0)
	{
		sprintf(ErrorBuff, "%s CRC error!", this->m_MainInfo.PluginName5);
		MessageBox(0,ErrorBuff,"Error Plugin5",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
//--
void CProtect::CheckCameraFile() // OK
{
	if(this->m_MainInfo.CameraCRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD CameraCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.CameraName,&CameraCRC32,1024) == 0)
	{
		MessageBox(0,"Camera CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.CameraCRC32 != CameraCRC32)
	{
		MessageBox(0,"Camera CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.CameraName);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}