#pragma once

#include "glad/glad.h"
#include "glm/glm.hpp"


enum shader_t : GLenum
{
	Vertex_Shader = GL_VERTEX_SHADER,
	Geometry_Shader = GL_GEOMETRY_SHADER,
	Fragment_Shader = GL_FRAGMENT_SHADER
};

class glProgram;

class glShader
{
	friend class glProgram;
public:
	glShader(shader_t type);
	glShader(GLuint type);
	~glShader();
	void SetData(const char* const data);
	void readFromFile(const char* const filename);
protected:
	GLuint shader;
};
