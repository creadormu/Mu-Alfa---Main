// FrameRateFix.cpp: Implementation of Frame Rate and Movement Speed Correction
#include "stdafx.h"
#include "FrameRateFix.h"
#include "Protect.h"
#include "Util.h"

CFrameRateFix gFrameRateFix;

CFrameRateFix::CFrameRateFix()
{
    m_LimitFPS = 40;  // Default
    m_LastFrameTime = 0;
    m_CurrentFrameTime = 0;
    m_DeltaTime = 0.0f;
    m_MovementMultiplier = 1.0f;
    m_TargetFrameTime = 40; // 40ms = ~25 FPS
}

CFrameRateFix::~CFrameRateFix()
{
}

void CFrameRateFix::Initialize()
{
    m_LimitFPS = gProtect.m_MainInfo.LimitFPS;
    m_TargetFrameTime = m_LimitFPS;
    m_LastFrameTime = GetTickCount();
    CalculateMultipliers();
}

void CFrameRateFix::SetFPSMode(DWORD limitFPS)
{
    m_LimitFPS = limitFPS;
    m_TargetFrameTime = limitFPS;
    gProtect.m_MainInfo.LimitFPS = limitFPS;
    CalculateMultipliers();
}

void CFrameRateFix::CalculateMultipliers()
{
    // Calculate movement speed multiplier based on FPS
    // Base: 40ms per frame (~25 FPS)
    // Higher FPS = faster frames = need to slow down movement
    
    float baseFPS = 1000.0f / 40.0f;  // ~25 FPS (original)
    float currentFPS = 1000.0f / (float)m_LimitFPS;
    
    // Movement multiplier: inversely proportional to FPS increase
    m_MovementMultiplier = baseFPS / currentFPS;
    
    // Clamp multiplier to reasonable values
    if (m_MovementMultiplier < 0.2f) m_MovementMultiplier = 0.2f;
    if (m_MovementMultiplier > 2.0f) m_MovementMultiplier = 2.0f;
}

void CFrameRateFix::UpdateFrameTime()
{
    m_CurrentFrameTime = GetTickCount();
    
    if (m_LastFrameTime > 0)
    {
        DWORD elapsed = m_CurrentFrameTime - m_LastFrameTime;
        m_DeltaTime = (float)elapsed / 1000.0f; // Convert to seconds
        
        // Clamp delta time to prevent huge jumps
        if (m_DeltaTime > 0.1f) m_DeltaTime = 0.1f;
        if (m_DeltaTime < 0.001f) m_DeltaTime = 0.001f;
    }
    
    m_LastFrameTime = m_CurrentFrameTime;
}

float CFrameRateFix::GetDeltaTime()
{
    return m_DeltaTime;
}

float CFrameRateFix::GetMovementSpeedMultiplier()
{
    return m_MovementMultiplier;
}
