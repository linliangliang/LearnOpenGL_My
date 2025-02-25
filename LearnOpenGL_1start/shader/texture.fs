#version 330 core
out vec4 colors;

in vec3 out_color;
in vec2 out_texCoord;

uniform float uniform_alpha;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	vec2 texCoord_1 = vec2(1 - out_texCoord.x, out_texCoord.y);
	//colors = texture(texture1, texCoord_1);
	colors = mix(texture(texture1, out_texCoord), texture(texture2, texCoord_1), uniform_alpha);
	//colors = texture(texture1, out_texCoord) * texture(texture2, out_texCoord) * vec4(out_color.x, out_color.y, out_color.z, uniform_color.y);
	//colors = texture(ourTexture1, out_texCoord) * vec4(out_color.x, out_color.y, out_color.z, uniform_color.y);
	//colors = vec4(out_color.x, out_color.y, out_color.z, uniform_color.y);
	//colors = vec4(1.0f, 0.0f, 0.0f, 0.5f);
}