#pragma once

#include <GLFW/glfw3.h>
#include <functional>

class glCallbackHandle {
public:
	glCallbackHandle(GLFWwindow* window) : window_(window) {
		// 设置回调为类的静态成员函数
		glfwSetFramebufferSizeCallback(window_, glCallbackHandle::framebuffer_size_callback); // 键盘事件
		glfwSetCursorPosCallback(window_, glCallbackHandle::mouse_callback); // 鼠标事件
	}

	void handle_framebuffer_resize(int width, int height) {
		// 实际处理视口大小调整的逻辑
		glViewport(0, 0, width, height);
		std::cout << "width,height = "<< width  << "," << height << std::endl;
	}

	// 按键事件
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
	// 鼠标事件
	void set_mouse_callback(std::function<void(GLFWwindow*, double, double)> callback)
	{
		mouse_input = callback;
	}

	// 鼠标操作回调
	std::function<void(GLFWwindow*, double, double)> mouse_input = nullptr;
private:
	GLFWwindow* window_;

	// 静态成员函数作为回调 size
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		// 获取窗口对应的glCallbackHandle实例
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

	// 静态成员函数作为回调
	//static void procsssInput(GLFWwindow* window) {
	//	// 获取窗口对应的glCallbackHandle实例
	//	glCallbackHandle* handler = static_cast<glCallbackHandle*>(glfwGetWindowUserPointer(window));
	//	if (handler) {
	//		handler->handle_procsssInput(window);
	//	}
	//}
};