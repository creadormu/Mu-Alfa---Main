#include "stdafx.h"
#include "AdvancedFPSManager.h"

const float CAdvancedFPSManager::BASE_FRAME_TIME = 40.0f; // 40ms = 25 FPS

CAdvancedFPSManager gAdvancedFPSManager;

CAdvancedFPSManager::CAdvancedFPSManager()
{
    m_TargetFPS = TARGET_FPS_60;
    m_TargetFrameTime = 0;
    m_LastFrameTime = 0;
    m_CurrentFrameTime = 0;
    m_DeltaTime = 0;
    m_DeltaTimeSeconds = 0.0f;
    m_FrameMultiplier = 1.0f;
    m_CurrentFPS = 0.0f;
    m_AccumulatedTime = 0.0f;
    m_FrameCount = 0;
    m_FPSUpdateTime = 0;
    m_VSyncEnabled = false;
    m_InterpolationAlpha = 0.0f;
    m_AccumulatorMS = 0;
    m_IsInitialized = false;
}

CAdvancedFPSManager::~CAdvancedFPSManager()
{
    // Destructor vacío
}

void CAdvancedFPSManager::Initialize(int targetFPS)
{
    SetTargetFPS(targetFPS);
    m_LastFrameTime = GetTickCount();
    m_FPSUpdateTime = m_LastFrameTime;
    m_IsInitialized = true;
}

void CAdvancedFPSManager::SetTargetFPS(int fps)
{
    m_TargetFPS = fps;

    if (fps == TARGET_FPS_UNLIMITED)
    {
        m_TargetFrameTime = 0;
    }
    else
    {
        m_TargetFrameTime = (DWORD)(1000.0f / fps);
    }
}

void CAdvancedFPSManager::Update()
{
    if (!m_IsInitialized) return;

    m_CurrentFrameTime = GetTickCount();
    m_DeltaTime = m_CurrentFrameTime - m_LastFrameTime;

    if (m_DeltaTime > 100)
    {
        m_DeltaTime = 100;
    }

    m_DeltaTimeSeconds = m_DeltaTime / 1000.0f;
    m_FrameMultiplier = m_DeltaTime / BASE_FRAME_TIME;

    m_AccumulatorMS += m_DeltaTime;
    if (m_AccumulatorMS >= (DWORD)BASE_FRAME_TIME)
    {
        m_AccumulatorMS -= (DWORD)BASE_FRAME_TIME;
    }
    m_InterpolationAlpha = m_AccumulatorMS / BASE_FRAME_TIME;

    m_FrameCount++;
    m_AccumulatedTime += m_DeltaTimeSeconds;

    if (m_CurrentFrameTime - m_FPSUpdateTime >= 1000)
    {
        m_CurrentFPS = m_FrameCount / m_AccumulatedTime;
        m_FrameCount = 0;
        m_AccumulatedTime = 0.0f;
        m_FPSUpdateTime = m_CurrentFrameTime;
    }

    m_LastFrameTime = m_CurrentFrameTime;
}

bool CAdvancedFPSManager::IsReady() const
{
    return m_IsInitialized;
}

void CAdvancedFPSManager::SetReady()
{
    m_IsInitialized = true;
}

float CAdvancedFPSManager::GetDeltaTime()
{
    return m_DeltaTimeSeconds;
}

DWORD CAdvancedFPSManager::GetDeltaTimeMS()
{
    return m_DeltaTime;
}

float CAdvancedFPSManager::GetCurrentFPS()
{
    return m_CurrentFPS;
}

float CAdvancedFPSManager::GetFrameMultiplier()
{
    return m_FrameMultiplier;
}

DWORD CAdvancedFPSManager::GetTargetFrameTime()
{
    return m_TargetFrameTime;
}

bool CAdvancedFPSManager::ShouldRenderFrame()
{
    if (m_TargetFPS == TARGET_FPS_UNLIMITED)
    {
        return true;
    }

    DWORD elapsedTime = GetTickCount() - m_LastFrameTime;
    return elapsedTime >= m_TargetFrameTime;
}

void CAdvancedFPSManager::WaitForNextFrame()
{
    if (m_TargetFPS == TARGET_FPS_UNLIMITED)
    {
        return;
    }

    DWORD currentTime = GetTickCount();
    DWORD elapsedTime = currentTime - m_LastFrameTime;

    if (elapsedTime < m_TargetFrameTime)
    {
        DWORD sleepTime = m_TargetFrameTime - elapsedTime;

        if (sleepTime > 1)
        {
            Sleep(sleepTime - 1);
        }

        while (GetTickCount() - m_LastFrameTime < m_TargetFrameTime)
        {
            // Busy wait
        }
    }
}

float CAdvancedFPSManager::GetInterpolationAlpha()
{
    return m_InterpolationAlpha;
}

void CAdvancedFPSManager::SetVSync(bool enable)
{
    m_VSyncEnabled = enable;

    typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC)(int interval);
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = NULL;

    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");

    if (wglSwapIntervalEXT != NULL)
    {
        wglSwapIntervalEXT(enable ? 1 : 0);
    }
}