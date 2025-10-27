#pragma once

// Advanced FPS Manager with Delta Time Support
// Decouples rendering FPS from game logic timing
// Allows 60, 120, or unlimited FPS while maintaining game stability

#define TARGET_FPS_25		25
#define TARGET_FPS_30		30
#define TARGET_FPS_60		60
#define TARGET_FPS_120		120
#define TARGET_FPS_144		144
#define TARGET_FPS_240		240
#define TARGET_FPS_UNLIMITED 0

class CAdvancedFPSManager
{
public:
	CAdvancedFPSManager();
	virtual ~CAdvancedFPSManager();

	// Initialize the FPS manager with target FPS
	void Initialize(int targetFPS = TARGET_FPS_60);
	
	// Update timing - call this every frame
	void Update();
	
	// Get delta time for frame-rate independent logic
	float GetDeltaTime();
	
	// Get raw delta time in milliseconds
	DWORD GetDeltaTimeMS();
	
	// Get current FPS
	float GetCurrentFPS();
	
	// Get frame time multiplier (for scaling animations/movement)
	float GetFrameMultiplier();
	
	// Set target FPS dynamically
	void SetTargetFPS(int fps);
	
	// Get target frame time in milliseconds
	DWORD GetTargetFrameTime();
	
	// Check if we should render this frame (for frame limiting)
	bool ShouldRenderFrame();
	
	// Wait for next frame (if frame limiting is enabled)
	void WaitForNextFrame();
	
	// Get interpolation alpha for smooth movement
	float GetInterpolationAlpha();

	// Enable/Disable VSync
	void SetVSync(bool enable);

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
	
	// For smooth interpolation
	float m_InterpolationAlpha;
	DWORD m_AccumulatorMS;
	
	// Base timing reference (25 FPS = original game logic speed)
	static const float BASE_FRAME_TIME;
	static const int BASE_FPS = 25;
};

extern CAdvancedFPSManager gAdvancedFPSManager;
