#pragma once

#include "glProgram.h"

class TexureDemo
{
public:
	TexureDemo();
	~TexureDemo();
	void loadTexture();
	void loadShaderProgram();
	void Draw();
	GLuint texture1;
	GLuint texture2;
	glProgram* program = nullptr;
protected:
	float vertices[32] = {
		0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f,  1.0f, 1.0f, // ���Ͻ�
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // ���½�
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,// ���½�
		-0.5f, 0.5f, 0.0f,   0.5f, 0.5f, 0.5f,  0.0f, 1.0f // ���Ͻ�
		//0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f,  0.55f, 0.55f, // ���Ͻ�
		//0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  0.55f, 0.45f, // ���½�
		//-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.45f, 0.45f,// ���½�
		//-0.5f, 0.5f, 0.0f,   0.5f, 0.5f, 0.5f,  0.45f, 0.55f // ���Ͻ�
	};

	GLuint indices[6] = {
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������	
	};

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

private:
	std::string mCurrentPath;
};
