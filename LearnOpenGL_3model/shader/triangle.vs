#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;

out vec3 out_color;

void main()
{
	out_color = color;
	gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}