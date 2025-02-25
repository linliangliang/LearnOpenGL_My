#pragma once

#include <GLFW/glfw3.h>
#include <functional>

class glCallbackHandle {
public:
	glCallbackHandle(GLFWwindow* window) : window_(window) {
		// ���ûص�Ϊ��ľ�̬��Ա����
		glfwSetFramebufferSizeCallback(window_, glCallbackHandle::framebuffer_size_callback); // �����¼�
		glfwSetCursorPosCallback(window_, glCallbackHandle::mouse_callback); // ����¼�
	}

	void handle_framebuffer_resize(int width, int height) {
		// ʵ�ʴ����ӿڴ�С�������߼�
		glViewport(0, 0, width, height);
		std::cout << "width,height = "<< width  << "," << height << std::endl;
	}

	// �����¼�
	//void procsssInput(GLFWwindow* window, std::function<void(GLFWwindow*)> callback)
	//{
	//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	//	{
	//		glfwSetWindowShouldClose(window, true);
	//	} else 
	//	{
	//		if (callback)
	//		{
	//			callback(window);
	//		}
	//	}
	//}
	// ����¼�
	void set_mouse_callback(std::function<void(GLFWwindow*, double, double)> callback)
	{
		mouse_input = callback;
	}

	// �������ص�
	std::function<void(GLFWwindow*, double, double)> mouse_input = nullptr;
private:
	GLFWwindow* window_;

	// ��̬��Ա������Ϊ�ص� size
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		// ��ȡ���ڶ�Ӧ��glCallbackHandleʵ��
		glCallbackHandle* handler = static_cast<glCallbackHandle*>(glfwGetWindowUserPointer(window));
		if (handler) {
			handler->handle_framebuffer_resize(width, height);
		}
	}

	static void mouse_callback(GLFWwindow* window, double x, double y)
	{
		glCallbackHandle* handler = static_cast<glCallbackHandle*>(glfwGetWindowUserPointer(window));
		if (handler && handler->mouse_input)
		{
			handler->mouse_input(window,x, y);
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