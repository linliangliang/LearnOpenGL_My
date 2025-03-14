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
	float vertices[24] = {
		0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  // 右上角
		0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // 右下角
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // 左下角
		-0.5f, 0.5f, 0.0f,   0.5f, 0.5f, 0.5f // 左上角
	};
	//float vertices[18] = {
	//	// 位置              // 颜色
	//	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
	//	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
	//	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
	//};

	GLuint indices[6] = {
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形	
	};

	GLuint VAO;
	GLuint VBO;

	GLuint EBO;
};
