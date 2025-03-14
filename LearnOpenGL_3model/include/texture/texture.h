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
		0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f,  1.0f, 1.0f, // 右上角
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  1.0f, 0.0f, // 右下角
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,// 左下角
		-0.5f, 0.5f, 0.0f,   0.5f, 0.5f, 0.5f,  0.0f, 1.0f // 左上角
		//0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 0.0f,  0.55f, 0.55f, // 右上角
		//0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  0.55f, 0.45f, // 右下角
		//-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.45f, 0.45f,// 左下角
		//-0.5f, 0.5f, 0.0f,   0.5f, 0.5f, 0.5f,  0.45f, 0.55f // 左上角
	};

	GLuint indices[6] = {
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形	
	};

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;

private:
	std::string mCurrentPath;
};
