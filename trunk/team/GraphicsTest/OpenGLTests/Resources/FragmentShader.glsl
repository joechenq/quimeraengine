#version 430 core

layout(row_major) uniform;

in vec4 colorFromVS;
in vec3 normal;
in vec2 textCoord0;
in vec2 textCoord1;
out vec4 color;

uniform sampler2D sampler1;
uniform sampler2D sampler2;

void main()
{
    color = colorFromVS * mix(texture(sampler1, textCoord1), texture(sampler2, textCoord0 + vec2(0.2, 0.2)), 1.0 - texture(sampler1, textCoord1).a);
}