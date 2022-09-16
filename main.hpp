#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <exception>

class Context final {
public:

	Context();

	~Context();
};

class Window {
public:

	Window();

	~Window();

	bool should_close();

	void swap_buffers();

private:
	GLFWwindow* window;
};
