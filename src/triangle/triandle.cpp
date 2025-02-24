
#include "triangle/triangle.h"

#include "glshader.h"

#include <Windows.h>
#include <iostream>


Triangle::Triangle()
{
	//program = new glProgram();

	//char path[MAX_PATH];
	//if (GetCurrentDirectoryA(sizeof(path), path)) {
	//	std::cout << "Current directory: " << path << std::endl;
	//}
	//else {
	//	std::cerr << "Error getting current directory." << std::endl;
	//}

	//std::string local_path = std::string(path);

	//std::string vsPath = local_path + "/../shader/triangle.vs";
	//std::string fsPath = local_path + "/../shader/triangle.fs";

	//glShader vsShader = glShader(shader_t::Vertex_Shader);
	//glShader fsShader = glShader(shader_t::Fragment_Shader);

	//vsShader.readFromFile(vsPath.c_str());
	//fsShader.readFromFile(fsPath.c_str());
	//program->attach(vsShader, fsShader);

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
		 glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		 glEnableVertexAttribArray(0);
		 // ��ɫ����
		 glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		 glEnableVertexAttribArray(1);


		 glBindBuffer(GL_ARRAY_BUFFER, 0);
	 }
	glBindVertexArray(0);
}

Triangle::~Triangle()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	//delete program;
	//program = nullptr;
}

void Triangle::Draw() {

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//�߿�ģʽ(Wireframe Mode)

	glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawElements(GL_LINE_STRIP, 6, GL_UNSIGNED_INT, 0);
}