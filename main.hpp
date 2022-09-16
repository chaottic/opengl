#pragma once

#include "quad.hpp"
#include <GLFW/glfw3.h>

#include <exception>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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

	void center();
};
