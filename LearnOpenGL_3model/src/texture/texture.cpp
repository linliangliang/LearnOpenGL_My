
#include "texture/texture.h"

#include "glshader.h"

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
//�������
#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TexureDemo::TexureDemo()
{
	char path[MAX_PATH];
	if (GetCurrentDirectoryA(sizeof(path), path)) {
		std::cout << "Current directory: " << path << std::endl;
	}
	else {
		std::cerr << "Error getting current directory." << std::endl;
	}
	mCurrentPath = std::string(path);


	 // ��������
	 glGenVertexArrays(1, &VAO);
	 glGenBuffers(1, &VBO);
	 glGenBuffers(1, &EBO);

	 glBindVertexArray(VAO);
	 {
		 // 2. �Ѷ������鸴�Ƶ������й�OpenGLʹ��
		 glBindBuffer(GL_ARRAY_BUFFER, VBO);
		 glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		 // ����
		 glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		 glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		 // λ������
		 glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		 glEnableVertexAttribArray(0);
		 // ��ɫ����
		 glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		 glEnableVertexAttribArray(1);
		 // ��������
		 glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		 glEnableVertexAttribArray(2);

		 glBindBuffer(GL_ARRAY_BUFFER, 0);
	 }
	glBindVertexArray(0);

}

TexureDemo::~TexureDemo()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	if (program !=nullptr)
	{
		delete program;
		program = nullptr;
	}
}

void TexureDemo::loadTexture() {

	std::string wallPath = mCurrentPath + "/../source/wall.jpg";
	std::string awesomeface = mCurrentPath + "/../source/awesomeface.png";


	// ����,���������Ʒ�ʽ
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// ��������
	stbi_set_flip_vertically_on_load(true); // Y�ᷭת
	int width, height, nrChannels;
	unsigned char* data = stbi_load(wallPath.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	// ����,���������Ʒ�ʽ
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// ��������
	int width2, height2, nrChannels2;
	unsigned char* data2 = stbi_load(awesomeface.c_str(), &width2, &height2, &nrChannels2, 0);
	if (data2)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width2, height2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data2);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void TexureDemo::loadShaderProgram() {
	// ����shader
	program = new glProgram();
	{
		std::string vsPath = mCurrentPath + "/../shader/texture.vs";
		std::string fsPath = mCurrentPath + "/../shader/texture.fs";
		glShader vsShader = glShader(shader_t::Vertex_Shader);
		glShader fsShader = glShader(shader_t::Fragment_Shader);
		vsShader.readFromFile(vsPath.c_str());
		fsShader.readFromFile(fsPath.c_str());
		program->attach(vsShader, fsShader);
	}
}

void TexureDemo::Draw() {
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//�߿�ģʽ(Wireframe Mode)

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);

	//glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawElements(GL_LINE_STRIP, 6, GL_UNSIGNED_INT, 0);
}