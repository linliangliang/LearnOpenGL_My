#pragma once
#include <string>

#include "glad/glad.h"

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat3x3.hpp"
#include "glm/mat4x4.hpp"

typedef GLint Uniform;
typedef GLint Attribute;

class glShader;
class glProgram
{
public:
	glProgram();
	glProgram(const glShader& vert, const glShader& fragment);
	glProgram(const glShader& vert, const glShader& fragment, const glShader& geometry);

	~glProgram();

	void attach(const glShader& vert, const glShader& fragment);
	void attach(const glShader& vert, const glShader& fragment, const glShader& geometry);

	void Use();
	void UnUse();

	Uniform GetUniform(const std::string& name);
	Attribute GetAttribute(const std::string& name);

	void SetUniform(const Uniform& uniform, int value);
	void SetUniform(const Uniform& uniform, float value);
	void SetUniform(const Uniform& uniform, const glm::vec2& value);
	void SetUniform(const Uniform& uniform, const glm::vec3& value);
	void SetUniform(const Uniform& uniform, const glm::vec4& value);
	void SetUniform(const Uniform& uniform, const float* values, GLuint count);
	void SetUniform(const Uniform& uniform, const glm::vec2* values, GLuint count);
	void SetUniform(const Uniform& uniform, const glm::vec3* values, GLuint count);
	void SetUniform(const Uniform& uniform, const glm::vec4* values, GLuint count);
	void SetUniform(const Uniform& uniform, const glm::mat3& value);
	void SetUniform(const Uniform& uniform, const glm::mat4& value);

	bool SetUniform(const std::string& uniform, int value);
	bool SetUniform(const std::string& uniform, float value);
	bool SetUniform(const std::string& uniform, const glm::vec2& value);
	bool SetUniform(const std::string& uniform, const glm::vec3& value);
	bool SetUniform(const std::string& uniform, const glm::vec4& value);
	bool SetUniform(const std::string& uniform, const float* values, GLuint count);
	bool SetUniform(const std::string& uniform, const glm::vec2* values, GLuint count);
	bool SetUniform(const std::string& uniform, const glm::vec3* values, GLuint count);
	bool SetUniform(const std::string& uniform, const glm::vec4* values, GLuint count);
	bool SetUniform(const std::string& uniform, const glm::mat3& value);
	bool SetUniform(const std::string& uniform, const glm::mat4& value);
protected:
	GLuint program = 0;
};

