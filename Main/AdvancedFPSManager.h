// AdvancedFPSManager.h
#pragma once
#include "stdafx.h"

#define TARGET_FPS_25        25
#define TARGET_FPS_30        30
#define TARGET_FPS_60        60
#define TARGET_FPS_120       120
#define TARGET_FPS_144       144
#define TARGET_FPS_240       240
#define TARGET_FPS_UNLIMITED 0

class CAdvancedFPSManager
{
private:
    int m_TargetFPS;
    DWORD m_TargetFrameTime;
    DWORD m_LastFrameTime;
    DWORD m_CurrentFrameTime;
    DWORD m_DeltaTime;
    float m_DeltaTimeSeconds;
    float m_FrameMultiplier;
    float m_CurrentFPS;
    float m_AccumulatedTime;
    int m_FrameCount;
    DWORD m_FPSUpdateTime;
    bool m_VSyncEnabled;
    float m_InterpolationAlpha;
    DWORD m_AccumulatorMS;
    bool m_IsInitialized;

public:
    static const float BASE_FRAME_TIME;

    CAdvancedFPSManager();
    ~CAdvancedFPSManager();  // SOLO AQUÍ

    void Initialize(int targetFPS = TARGET_FPS_60);
    void SetTargetFPS(int fps);
    void Update();

    float GetDeltaTime();
    DWORD GetDeltaTimeMS();
    float GetCurrentFPS();
    float GetFrameMultiplier();
    DWORD GetTargetFrameTime();
    bool ShouldRenderFrame();
    void WaitForNextFrame();
    float GetInterpolationAlpha();
    void SetVSync(bool enable);

    bool IsReady() const;
    void SetReady();
};

extern CAdvancedFPSManager gAdvancedFPSManager;