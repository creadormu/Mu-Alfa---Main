// Fragment Shader (GLSL 1.20)
#version 120
uniform sampler2D tex0;
varying vec2 TexCoord;
varying vec4 Col;

void main() {
    vec4 vertexColors = texture2D(tex0, TexCoord);
    vec4 lightColor   = Col;

    // clamp como en el shader 330
    float maxIntensity = 1.0;
    lightColor.rgb = min(lightColor.rgb, vec3(maxIntensity));

    gl_FragColor = vertexColors * lightColor;
}
