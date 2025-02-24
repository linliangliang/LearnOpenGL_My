// LearnOpenGL_My.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <sstream>

#include <Windows.h>
#include <iostream>
#include "glshader.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

#include "LearnOpenGL_base.h"
#include "texture/texture.h"
#include "glCallbackHandle.h"


#ifdef hello_texture
int main()
#else
int main_hello_triangle()
#endif
{
	// 初始化GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// 创建窗口
	GLFWwindow* window = glfwCreateWindow(800, 600, "MyOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout<< "创建窗口失败" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window); //通知GLFW将我们窗口的上下文设置为当前线程的主上下文

	// 初始化GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 指定视口大小
	glViewport(0,0,800, 600);

	// 设置回调
	glCallbackHandle handler(window);
	glfwSetWindowUserPointer(window, &handler); // 设置用户指针
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// 创建三角形
	TexureDemo texureDemo; // vao vbo初始化
	texureDemo.loadTexture(); // texture 初始化


	// 加载shader
	glProgram* program = new glProgram();
	{
		//初始化shader
		char path[MAX_PATH];
		if (GetCurrentDirectoryA(sizeof(path), path)) {
			std::cout << "Current directory: " << path << std::endl;
		}
		else {
			std::cerr << "Error getting current directory." << std::endl;
		}

		std::string local_path = std::string(path);
		std::string vsPath = local_path + "/../shader/texture.vs";
		std::string fsPath = local_path + "/../shader/texture.fs";
		glShader vsShader = glShader(shader_t::Vertex_Shader);
		glShader fsShader = glShader(shader_t::Fragment_Shader);
		vsShader.readFromFile(vsPath.c_str());
		fsShader.readFromFile(fsPath.c_str());
		program->attach(vsShader, fsShader);
	}
	

	// 设置透明度生效
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//program->Use();
	//// 设置uniform 参数
	//
	//program->SetUniform("ourTexture1", 0);
	//program->SetUniform("ourTexture2", 1);
	//program->UnUse();

	while (!glfwWindowShouldClose(window))
	{
		handler.procsssInput(window);

		// 渲染
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		program->Use();

		// 设置uniform 参数
		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		program->SetUniform("uniform_color",glm::vec4(1, greenValue,0,1));
		program->SetUniform("ourTexture1",0);
		program->SetUniform("ourTexture2",1);

		texureDemo.Draw();
		program->UnUse();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}