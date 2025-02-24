#version 330 core
out vec4 colors;

uniform vec4 uniform_color;
in vec3 out_color;

void main()
{
	colors = vec4(out_color.x, out_color.y, out_color.z, uniform_color.y);
	//colors = vec4(1.0f, 0.0f, 0.0f, 0.5f);
}