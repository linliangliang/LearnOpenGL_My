#version 330 core
out vec4 colors;

in vec3 out_color;
in vec2 out_texCoord;

uniform vec4 uniform_color;
uniform sampler2D ourTexture1;
uniform sampler2D outTexture2;

void main()
{
	colors = texture(ourTexture1, out_texCoord) * texture(outTexture2, out_texCoord) * vec4(out_color.x, out_color.y, out_color.z, uniform_color.y);
	//colors = texture(ourTexture1, out_texCoord) * vec4(out_color.x, out_color.y, out_color.z, uniform_color.y);
	//colors = vec4(out_color.x, out_color.y, out_color.z, uniform_color.y);
	//colors = vec4(1.0f, 0.0f, 0.0f, 0.5f);
}