#include "window.hpp"

Window::Window() {
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_FLUSH);

	if (!(window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Stuff", nullptr, nullptr))) {
		throw std::exception("Failde to create a new GLFW Window.");
	}
	width = 0;
	height = 0;

	auto monitor = glfwGetPrimaryMonitor();
	auto videoMode = glfwGetVideoMode(monitor);

	if (videoMode) {
		struct final {
			int x;
			int y;
			int width;
			int height;

		} workArea{};

		glfwGetWindowSize(window, &width, &height);
		glfwGetMonitorWorkarea(monitor, &workArea.x, &workArea.y, &workArea.width, &workArea.height);

		glfwSetWindowMonitor(window, nullptr, (workArea.width - width) / 2, (workArea.height - height) / 2, width, height, videoMode->refreshRate);
	}

	glfwMakeContextCurrent(window);
}

Window::~Window() {
	glfwDestroyWindow(window);
}

bool Window::should_close() {
	return glfwWindowShouldClose(window);
}

void Window::swap_buffers() {
	glfwSwapBuffers(window);
}

double Window::get_aspect_ratio() {
	return static_cast<double>(width) / static_cast<double>(height);
}

Context::Context() {
	if (!glfwInit()) {
		throw std::exception("Failed to initialize GLFW.");
	}
}

Context::~Context() {
	glfwTerminate();
}