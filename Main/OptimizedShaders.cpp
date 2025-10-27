#include "stdafx.h"
#include "OptimizedShaders.h"
#include <gl/GL.h>

// OpenGL extension function pointers
typedef GLuint (APIENTRY *PFNGLCREATESHADERPROC)(GLenum type);
typedef void (APIENTRY *PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar** string, const GLint* length);
typedef void (APIENTRY *PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void (APIENTRY *PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* params);
typedef void (APIENTRY *PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef GLuint (APIENTRY *PFNGLCREATEPROGRAMPROC)(void);
typedef void (APIENTRY *PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (APIENTRY *PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (APIENTRY *PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint* params);
typedef void (APIENTRY *PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog);
typedef void (APIENTRY *PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (APIENTRY *PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (APIENTRY *PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef GLint (APIENTRY *PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar* name);
typedef void (APIENTRY *PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (APIENTRY *PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);

static PFNGLCREATESHADERPROC glCreateShader = NULL;
static PFNGLSHADERSOURCEPROC glShaderSource = NULL;
static PFNGLCOMPILESHADERPROC glCompileShader = NULL;
static PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
static PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
static PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
static PFNGLATTACHSHADERPROC glAttachShader = NULL;
static PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
static PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
static PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
static PFNGLUSEPROGRAMPROC glUseProgram = NULL;
static PFNGLDELETESHADERPROC glDeleteShader = NULL;
static PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
static PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
static PFNGLUNIFORM1IPROC glUniform1i = NULL;
static PFNGLUNIFORM1FPROC glUniform1f = NULL;

COptimizedShaders gOptimizedShaders;

COptimizedShaders::COptimizedShaders()
{
	m_VertexShader = 0;
	m_FragmentShader = 0;
	m_ShaderProgram = 0;
	m_ShadersEnabled = false;
	m_ShadersSupported = false;
}

COptimizedShaders::~COptimizedShaders()
{
	if (m_VertexShader != 0)
	{
		if (glDeleteShader != NULL)
		{
			glDeleteShader(m_VertexShader);
		}
	}
	
	if (m_FragmentShader != 0)
	{
		if (glDeleteShader != NULL)
		{
			glDeleteShader(m_FragmentShader);
		}
	}
	
	if (m_ShaderProgram != 0)
	{
		if (glDeleteProgram != NULL)
		{
			glDeleteProgram(m_ShaderProgram);
		}
	}
}

bool COptimizedShaders::Initialize()
{
	// Load OpenGL shader function pointers
	glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
	glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
	glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
	glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
	glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
	
	// Check if all functions loaded successfully
	if (glCreateShader == NULL || glShaderSource == NULL || glCompileShader == NULL ||
		glCreateProgram == NULL || glAttachShader == NULL || glLinkProgram == NULL ||
		glUseProgram == NULL)
	{
		m_ShadersSupported = false;
		return false;
	}
	
	m_ShadersSupported = true;
	return LoadShaders();
}

bool COptimizedShaders::IsShadersSupported()
{
	return m_ShadersSupported;
}

const char* COptimizedShaders::GetVertexShaderSource()
{
	// Optimized Vertex Shader (GLSL 1.20)
	// Compatible with older OpenGL but with performance optimizations
	return R"(
#version 120
attribute vec3 aPos;
attribute vec2 aTex;
attribute vec4 aCol;

varying vec2 TexCoord;
varying vec4 Col;

void main()
{
    // Use built-in matrix for maximum performance
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPos, 1.0);
    TexCoord = aTex;
    Col = aCol;
}
)";
}

const char* COptimizedShaders::GetFragmentShaderSource()
{
	// Optimized Fragment Shader (GLSL 1.20)
	// Enhanced lighting with performance optimizations
	return R"(
#version 120
uniform sampler2D tex0;
varying vec2 TexCoord;
varying vec4 Col;

void main()
{
    vec4 texColor = texture2D(tex0, TexCoord);
    vec4 lightColor = Col;

    // Optimized light intensity clamping
    // Using min is faster than clamp for single-sided clamping
    float maxIntensity = 1.0;
    lightColor.rgb = min(lightColor.rgb, vec3(maxIntensity));

    // Final color calculation with optimized blending
    gl_FragColor = texColor * lightColor;
    
    // Early Z-culling optimization: discard fully transparent pixels
    if (gl_FragColor.a < 0.01)
        discard;
}
)";
}

GLuint COptimizedShaders::CompileShader(GLenum type, const char* source)
{
	if (glCreateShader == NULL || glShaderSource == NULL || glCompileShader == NULL)
	{
		return 0;
	}
	
	GLuint shader = glCreateShader(type);
	if (shader == 0)
	{
		return 0;
	}
	
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	
	if (!CheckShaderCompileErrors(shader))
	{
		if (glDeleteShader != NULL)
		{
			glDeleteShader(shader);
		}
		return 0;
	}
	
	return shader;
}

bool COptimizedShaders::CheckShaderCompileErrors(GLuint shader)
{
	if (glGetShaderiv == NULL || glGetShaderInfoLog == NULL)
	{
		return false;
	}
	
	GLint success;
	glGetShaderiv(shader, 0x8B81, &success); // GL_COMPILE_STATUS
	
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		// Could log the error here if logging system available
		return false;
	}
	
	return true;
}

bool COptimizedShaders::LinkShaderProgram()
{
	if (glLinkProgram == NULL || glGetProgramiv == NULL)
	{
		return false;
	}
	
	glLinkProgram(m_ShaderProgram);
	
	return CheckProgramLinkErrors();
}

bool COptimizedShaders::CheckProgramLinkErrors()
{
	if (glGetProgramiv == NULL || glGetProgramInfoLog == NULL)
	{
		return false;
	}
	
	GLint success;
	glGetProgramiv(m_ShaderProgram, 0x8B82, &success); // GL_LINK_STATUS
	
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infoLog);
		// Could log the error here if logging system available
		return false;
	}
	
	return true;
}

bool COptimizedShaders::LoadShaders()
{
	if (!m_ShadersSupported)
	{
		return false;
	}
	
	// Compile vertex shader
	m_VertexShader = CompileShader(0x8B31, GetVertexShaderSource()); // GL_VERTEX_SHADER
	if (m_VertexShader == 0)
	{
		return false;
	}
	
	// Compile fragment shader
	m_FragmentShader = CompileShader(0x8B30, GetFragmentShaderSource()); // GL_FRAGMENT_SHADER
	if (m_FragmentShader == 0)
	{
		return false;
	}
	
	// Create shader program
	if (glCreateProgram == NULL || glAttachShader == NULL)
	{
		return false;
	}
	
	m_ShaderProgram = glCreateProgram();
	if (m_ShaderProgram == 0)
	{
		return false;
	}
	
	glAttachShader(m_ShaderProgram, m_VertexShader);
	glAttachShader(m_ShaderProgram, m_FragmentShader);
	
	if (!LinkShaderProgram())
	{
		return false;
	}
	
	m_ShadersEnabled = true;
	return true;
}

void COptimizedShaders::UseShader()
{
	if (m_ShadersEnabled && m_ShaderProgram != 0 && glUseProgram != NULL)
	{
		glUseProgram(m_ShaderProgram);
		
		// Set texture unit
		if (glGetUniformLocation != NULL && glUniform1i != NULL)
		{
			GLint texLoc = glGetUniformLocation(m_ShaderProgram, "tex0");
			if (texLoc != -1)
			{
				glUniform1i(texLoc, 0);
			}
		}
	}
}

void COptimizedShaders::DisableShader()
{
	if (glUseProgram != NULL)
	{
		glUseProgram(0);
	}
}

GLuint COptimizedShaders::GetShaderProgram()
{
	return m_ShaderProgram;
}
