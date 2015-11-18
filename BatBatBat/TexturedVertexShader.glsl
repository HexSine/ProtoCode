#version 330 core


layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec4 vertexColor;
layout(location = 2) in vec2 vertexUV;

//Output UV's for Fragment Shader
out vec2 UV;
out vec4 Color;

//Transform/Viewport Matrix
uniform mat4 MVP;

void main()
{
    //
    gl_Position = MVP * vec4(vertexPosition_modelspace,1);

    // Pass Vertex UV to frament shader
    UV = vertexUV;
}
