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
#include "glCallbackHandle.h"
#include "LearnOpenGL_base.h"

#include "texture_transform/texture_transform.h"
#include "camera.h"

namespace texture_transform {
	int viewWidth = 800;
	int viewHeight = 600;
	// 透明的参数
	static float alpha = 0.5f;

	static float deltaTime = 0.0f; // 当前帧与上一帧的时间差
	static float lastFrame = 0.0f; // 上一帧的时间

	Camera camera;

	// 相机移动半径,旋转角度
	//static float camera_R = 20.0f;
	//static float camera_Angle = 0;
	float cameraSpeed = 0.05f; // adjust accordingly
	static glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	static glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	static glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	// 键盘输入
	void keyInput(GLFWwindow* window) {

		cameraSpeed  = 2.5f * deltaTime;
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			alpha += 0.01;
			if (alpha > 1.0f)
			{
				alpha = 1.0f;
			}
			cameraPos += cameraSpeed * cameraFront;

			camera.ProcessKeyboard(FORWARD, deltaTime);
		}
		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			alpha -= 0.01;
			if (alpha < 0.0f)
			{
				alpha = 0.0f;
			}
			cameraPos -= cameraSpeed * cameraFront;
			camera.ProcessKeyboard(BACKWARD, deltaTime);
		}
		else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			camera.ProcessKeyboard(LEFT, deltaTime);
		}
		else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			camera.ProcessKeyboard(RIGHT, deltaTime);
		}
	}

	float yaw = -90.0f, pitch = 0.0f, roll = 0.0f;
	double lastXPos = 400, lastYPos = 300;
	float sensitivity = 0.05;// 鼠标灵敏度
	bool firstMouse = true;
	// 鼠标事件
	void mouseInput(GLFWwindow* window, double x, double y) 
	{
		//if (firstMouse)
		//{
		//	lastXPos = x;
		//	lastYPos = y;
		//	firstMouse = false;
		//}
		//
		//float xoffset = x - lastXPos;
		//float yoffset = lastYPos - y;
		//lastXPos = x;
		//lastYPos = y;
		//
		//xoffset *= sensitivity;
		//yoffset *= sensitivity;
		//
		//
		//yaw += xoffset;
		//pitch += yoffset;
		//
		//if (pitch > 89.0f)
		//	pitch = 89.0f;
		//if (pitch < -89.0f)
		//	pitch = -89.0f;
		//
		//
		//glm::vec3 front;
		//front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		//front.y = sin(glm::radians(pitch));
		//front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		//cameraFront = glm::normalize(front);

		float xoffset = x - lastXPos;
		float yoffset = lastYPos - y;
		lastXPos = x;
		lastYPos = y;
		camera.ProcessMouseMovement(xoffset, yoffset);
		//std::string ttt = typeid(Camera).name();
		//size_t ddd= typeid(Camera).hash_code();
		//int a;
	}
}

#ifdef hello_texture_transform
int main()
#else
int main_hello_texture_transform()
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
	handler.set_mouse_callback(texture_transform::mouseInput);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);// 隐藏鼠标

	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	// 创建三角形
	TexureTransformDemo texureTransformDemo; // vao vbo初始化
	texureTransformDemo.loadTexture(); // texture 初始化
	texureTransformDemo.loadShaderProgram(); // attach shader Program


	// 设置透明度生效
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// 启用深度测试
	glEnable(GL_DEPTH_TEST);


	// glm::mat4 trans = glm::mat4(1.0f);
	// trans = glm::translate(trans, glm::vec3(0.3f, 0.3f, 0.0f));
	// trans = glm::scale(trans, glm::vec3(0.3f, 0.3f, 0.0f));
	// trans = glm::rotate(trans, 45.0f, glm::vec3(1.0f, 1.0f, 0.0f));

	//glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);
	{
		// 创建MVP矩阵
		//model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		// 注意，我们将矩阵向我们要进行移动场景的反方向移动。
		{
			//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
			//view = glm::lookAt(texture_transform::cameraPos, texture_transform::cameraPos + texture_transform::cameraFront, texture_transform::cameraUp);
			view = texture_transform::camera.GetViewMatrix();
		}
		proj = glm::perspective(glm::radians(45.0f), (float)texture_transform::viewWidth / (float)texture_transform::viewHeight, 0.1f, 100.0f);
		//model = proj * view * model;
	}

	glm::vec3 cubePositions[10] = {
	  glm::vec3(0.0f,  0.0f,  0.0f),
	  glm::vec3(2.0f,  5.0f, -15.0f),
	  glm::vec3(-1.5f, -2.2f, -2.5f),
	  glm::vec3(-3.8f, -2.0f, -12.3f),
	  glm::vec3(2.4f, -0.4f, -3.5f),
	  glm::vec3(-1.7f,  3.0f, -7.5f),
	  glm::vec3(1.3f, -2.0f, -2.5f),
	  glm::vec3(1.5f,  2.0f, -2.5f),
	  glm::vec3(1.5f,  0.2f, -1.5f),
	  glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		texture_transform::deltaTime = currentFrame - texture_transform::lastFrame;
		texture_transform::lastFrame = currentFrame;

		texture_transform::keyInput(window);

		// 渲染
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //颜色缓冲和深度缓冲

		texureTransformDemo.program->Use();


		// 设置uniform 参数
		float timeValue = glfwGetTime();
		float _timeValue = (sin(timeValue) / 2.0f) + 0.5f;
		// 顶点着色器
		//glm::mat4 trans = glm::mat4(1.0f);
		//trans = glm::scale(trans, glm::vec3(_timeValue, _timeValue, 0.0f));
			// 片段着色器
		texureTransformDemo.program->SetUniform("uniform_alpha", texture_transform::alpha);
		texureTransformDemo.program->SetUniform("texture1", 0);
		texureTransformDemo.program->SetUniform("texture2", 1);
		int size = sizeof(cubePositions) / sizeof(cubePositions[0]);
		for (int i = 0; i< size;i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			model = glm::rotate(model, ((float)glfwGetTime() +i) * glm::radians(-55.0f), glm::vec3(1.0f, 1.0f, 0.0f));

			// 计算view  通过相机的视角计算view矩阵 ，相机视角只需要（相机位置，相机观察点，up向量）
			{
				/// view = glm::mat4(1.0f);
				/// float R_X = sin(texture_transform::camera_Angle) * texture_transform::camera_R;
				/// float R_Z = cos(texture_transform::camera_Angle) * texture_transform::camera_R;
				/// 
				/// view = glm::lookAt(glm::vec3(R_X, 0.0f, R_Z),
				/// 	glm::vec3(0.0f, 0.0f, 0.0f),
				/// 	glm::vec3(0.0f, 1.0f, 0.0f));
				/// 
				/// 
				//view = glm::lookAt(texture_transform::cameraPos, texture_transform::cameraPos + texture_transform::cameraFront, texture_transform::cameraUp);
				view = texture_transform::camera.GetViewMatrix();
			}

			texureTransformDemo.program->SetUniform("model", model);
			texureTransformDemo.program->SetUniform("view", view);
			texureTransformDemo.program->SetUniform("proj", proj);
			texureTransformDemo.Draw();
		}

		texureTransformDemo.program->UnUse();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}