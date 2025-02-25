#include "glProgram.h"
#include "glShader.h"

#include "glm/gtc/type_ptr.hpp"
#include "glm/glm.hpp"

#include <iostream>


glProgram::glProgram()
{
}


glProgram::glProgram(const glShader& vert, const glShader& fragment)
{
	attach(vert, fragment);
}

glProgram::glProgram(const glShader& vert, const glShader& fragment, const glShader& geometry)
{
	attach(vert, fragment, geometry);
}

glProgram::~glProgram()
{
	if (0 != program)
	{
		glDeleteProgram(program);
	}
}

void glProgram::attach(const glShader& vert, const glShader& fragment)
{
	if (0 != program)
	{
		glDeleteProgram(program);
	}
	program = glCreateProgram();
	glAttachShader(program, vert.shader);
	glAttachShader(program, fragment.shader);
	glLinkProgram(program);

	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}

	glDeleteShader(vert.shader);
	glDeleteShader(fragment.shader);
}

void glProgram::attach(const glShader& vert, const glShader& fragment, const glShader& geometry)
{
	if (0 != program)
	{
		glDeleteProgram(program);
	}
	program = glCreateProgram();
	glAttachShader(program, vert.shader);
	glAttachShader(program, fragment.shader);
	glAttachShader(program, geometry.shader);
	glLinkProgram(program);

	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}
	glDeleteShader(vert.shader);
	glDeleteShader(fragment.shader);
}

void glProgram::Use()
{
	glUseProgram(program);
}

void glProgram::UnUse()
{
	glUseProgram(0);
}

Uniform glProgram::GetUniform(const std::string& name)
{
	return glGetUniformLocation(program, name.c_str());
}

Attribute glProgram::GetAttribute(const std::string& name)
{
	return glGetAttribLocation(program, name.c_str());
}

void glProgram::SetUniform(const Uniform& uniform, int value)
{
	glUniform1i(uniform, value);
}

void glProgram::SetUniform(const Uniform& uniform, float value)
{
	glUniform1f(uniform, value);
}

void glProgram::SetUniform(const Uniform& uniform, const glm::vec2& value)
{
	glUniform2f(uniform, value.x, value.y);
}

void glProgram::SetUniform(const Uniform& uniform, const glm::vec3& value)
{
	glUniform3f(uniform, value.x, value.y, value.z);
}

void glProgram::SetUniform(const Uniform& uniform, const glm::vec4& value)
{
	glUniform4f(uniform, value.x, value.y, value.z, value.w);
}

void glProgram::SetUniform(const Uniform& uniform, const float* values, GLuint count)
{
	glUniform1fv(uniform, count, values);
}

void glProgram::SetUniform(const Uniform& uniform, const glm::vec2* values, GLuint count)
{
	glUniform2fv(uniform, count, (float*)values);
}

void glProgram::SetUniform(const Uniform& uniform, const glm::vec3* values, GLuint count)
{
	glUniform3fv(uniform, count, (float*)values);
}

void glProgram::SetUniform(const Uniform& uniform, const glm::vec4* values, GLuint count)
{
	glUniform4fv(uniform, count, (float*)values);
}

void glProgram::SetUniform(const Uniform& uniform, const glm::mat3& value)
{
	
	glUniformMatrix3fv(uniform, 1, GL_FALSE, (float*)glm::value_ptr(value));
}

void glProgram::SetUniform(const Uniform& uniform, const glm::mat4& value)
{
	glUniformMatrix4fv(uniform, 1, GL_FALSE, (float*)glm::value_ptr(value));
}


bool glProgram::SetUniform(const std::string& uniform, int value)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform1i(location, value);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, float value)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform1f(location, value);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::vec2& value)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform2f(location, value.x, value.y);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::vec3& value)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform3f(location, value.x, value.y, value.z);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::vec4& value)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform4f(location, value.x, value.y, value.z, value.w);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const float* values, GLuint count)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform1fv(location, count, values);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::vec2* values, GLuint count)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform2fv(location, count, (float*)values);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::vec3* values, GLuint count)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform3fv(location, count, (float*)values);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::vec4* values, GLuint count)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniform4fv(location, count, (float*)values);
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::mat3& value)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	;

	glUniformMatrix3fv(location, 1, GL_FALSE, (float*)glm::value_ptr(value));
	return true;
}

bool glProgram::SetUniform(const std::string& uniform, const glm::mat4& value)
{
	Uniform location = GetUniform(uniform);
	if (location == -1)
	{
		return false;
	}
	glUniformMatrix4fv(location, 1, GL_FALSE, (float*)glm::value_ptr(value));
	return true;
}