#pragma once

#include "glProgram.h"

class Triangle
{
public:
	Triangle();
	~Triangle();

	void Draw();
protected:
	//glProgram* program = nullptr;
	float vertices[12] = {
		0.5f, 0.5f, 0.0f,   // ���Ͻ�
		0.5f, -0.5f, 0.0f,  // ���½�
		-0.5f, -0.5f, 0.0f, // ���½�
		-0.5f, 0.5f, 0.0f   // ���Ͻ�
	};

	GLuint indices[6] = {
		0, 1, 3, // ��һ��������
	1, 2, 3  // �ڶ���������	
	};

	GLuint VAO;
	GLuint VBO;

	GLuint EBO;
};
