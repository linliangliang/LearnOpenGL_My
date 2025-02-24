#include "glShader.h"
#include <fstream>
#include <sstream>
#include "logger.hpp"

glShader::glShader(shader_t type)
{
	shader = glCreateShader(type);
}
glShader::glShader(GLuint type)
{
	shader = glCreateShader(type);
}

glShader::~glShader()
{
	glDeleteShader(shader);
}

void glShader::SetData(const char* const data)
{
	glShaderSource(shader, 1, &data, NULL);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	// check for shader compile errors
	if (!success)
	{
		char infoLog[1024];
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		glLOG("shader error:%s", infoLog);
	}
}

void glShader::readFromFile(const char* const filename)
{
	try
	{
		std::ifstream shaderFile;
		shaderFile.open(filename);
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		std::string code = shaderStream.str();
		SetData(code.c_str());
	}
	catch (...)
	{
		glLOG("shader error:%s", filename);
	}
}