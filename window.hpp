#pragma once

#include <GLFW/glfw3.h>
#include <exception>

constexpr int WIDTH = 1280;
constexpr int HEIGHT = 720;

class Window final {
public:

	Window();

	~Window();

	bool should_close();

	void swap_buffers();

	double get_aspect_ratio();

private:
	GLFWwindow* window;
	int width;
	int height;
};

class Context final {
public:

	Context();

	~Context();
};