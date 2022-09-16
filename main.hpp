#pragma once

#include "quad.hpp"
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

	int get_width();

	int get_height();

private:
	GLFWwindow* window;

	int width;
	int height;

	void center();
};
