#pragma once

#include <GLFW/glfw3.h>

class glCallbackHandle {
public:
	glCallbackHandle(GLFWwindow* window) : window_(window) {
		// ���ûص�Ϊ��ľ�̬��Ա����
		glfwSetFramebufferSizeCallback(window_, glCallbackHandle::framebuffer_size_callback);
	}

	void handle_framebuffer_resize(int width, int height) {
		// ʵ�ʴ����ӿڴ�С�������߼�
		glViewport(0, 0, width, height);
		std::cout << "width,height = "<< width  << "," << height << std::endl;
	}

	// �����¼�
	void procsssInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}

private:
	GLFWwindow* window_;

	// ��̬��Ա������Ϊ�ص�
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		// ��ȡ���ڶ�Ӧ��glCallbackHandleʵ��
		glCallbackHandle* handler = static_cast<glCallbackHandle*>(glfwGetWindowUserPointer(window));
		if (handler) {
			handler->handle_framebuffer_resize(width, height);
		}
	}

	// ��̬��Ա������Ϊ�ص�
	//static void procsssInput(GLFWwindow* window) {
	//	// ��ȡ���ڶ�Ӧ��glCallbackHandleʵ��
	//	glCallbackHandle* handler = static_cast<glCallbackHandle*>(glfwGetWindowUserPointer(window));
	//	if (handler) {
	//		handler->handle_procsssInput(window);
	//	}
	//}
};