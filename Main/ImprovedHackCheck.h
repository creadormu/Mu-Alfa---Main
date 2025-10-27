#pragma once

// Improved HackCheck with configurable FPS
// This version allows higher FPS while maintaining security

void DecryptData(BYTE* lpMsg, int size);
void EncryptData(BYTE* lpMsg, int size);
bool CheckSocketPort(SOCKET s);
int WINAPI MyRecv(SOCKET s, char* buf, int len, int flags);
int WINAPI MySend(SOCKET s, char* buf, int len, int flags);

// Modified tick count checks that support higher FPS
void CheckTickCount1_Improved();
void CheckTickCount2_Improved();

// Initialize improved hack check
void InitImprovedHackCheck();

// Set dynamic FPS limit (25, 30, 60, 120, 144, 240, or 0 for unlimited)
void SetDynamicFPSLimit(int targetFPS);

// Get current FPS limit
int GetCurrentFPSLimit();
