#version 330 core

in vec2 UV;
out vec4 color;

uniform sampler2D TextureSampler;

void main()
{
    color = texture(TextureSampler,UV).rgba;
}
