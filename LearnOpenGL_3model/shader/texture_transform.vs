#version 330 core
layout (location = 0) in vec3 pos;
///layout (location = 1) in vec3 color;
layout (location = 1) in vec2 texCoord;

out vec2 out_texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	out_texCoord = texCoord;
	gl_Position = proj * view * model * vec4(pos.x, pos.y, pos.z, 1.0);
}