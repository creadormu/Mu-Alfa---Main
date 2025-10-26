// Vertex Shader (GLSL 1.20)
#version 120
attribute vec3 aPos;
attribute vec2 aTex;
attribute vec4 aCol;

varying vec2 TexCoord;
varying vec4 Col;

void main() {
    gl_Position = gl_ModelViewProjectionMatrix * vec4(aPos, 1.0);
    TexCoord = aTex;
    Col = aCol;
}
