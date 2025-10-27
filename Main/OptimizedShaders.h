#pragma once

// Optimized Shader System for High FPS Gaming
// These shaders are optimized for performance while maintaining visual quality

class COptimizedShaders
{
public:
	COptimizedShaders();
	virtual ~COptimizedShaders();

	// Initialize shader system
	bool Initialize();
	
	// Load and compile shaders
	bool LoadShaders();
	
	// Use shader program
	void UseShader();
	
	// Disable shader
	void DisableShader();
	
	// Check if shaders are supported
	bool IsShadersSupported();
	
	// Get shader program ID
	GLuint GetShaderProgram();

private:
	GLuint m_VertexShader;
	GLuint m_FragmentShader;
	GLuint m_ShaderProgram;
	bool m_ShadersEnabled;
	bool m_ShadersSupported;
	
	// Shader source code
	const char* GetVertexShaderSource();
	const char* GetFragmentShaderSource();
	
	// Compile shader
	GLuint CompileShader(GLenum type, const char* source);
	
	// Link shader program
	bool LinkShaderProgram();
	
	// Check shader compile errors
	bool CheckShaderCompileErrors(GLuint shader);
	
	// Check program link errors
	bool CheckProgramLinkErrors();
};

extern COptimizedShaders gOptimizedShaders;
