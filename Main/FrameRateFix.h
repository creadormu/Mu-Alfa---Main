// FrameRateFix.h: Frame Rate and Movement Speed Correction
#pragma once

#include <windows.h>

class CFrameRateFix
{
public:
    CFrameRateFix();
    virtual ~CFrameRateFix();
    
    void Initialize();
    void SetFPSMode(DWORD limitFPS);
    float GetDeltaTime();
    float GetMovementSpeedMultiplier();
    void UpdateFrameTime();
    
private:
    DWORD m_LimitFPS;
    DWORD m_LastFrameTime;
    DWORD m_CurrentFrameTime;
    float m_DeltaTime;
    float m_MovementMultiplier;
    DWORD m_TargetFrameTime;
    
    void CalculateMultipliers();
};

extern CFrameRateFix gFrameRateFix;
