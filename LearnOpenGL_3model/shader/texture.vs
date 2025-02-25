#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 out_color;
out vec2 out_texCoord;

void main()
{
	out_color = color;
	out_texCoord = texCoord;
	gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}