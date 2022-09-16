#include "main.hpp"


int main() {
	Context context;
	Window window;

	if (glewInit() != GLEW_OK) {
		throw std::exception("Failed to initialize GLEW");
	}

	while (!window.should_close()) {
		glClear(GL_COLOR_BUFFER_BIT);

		window.swap_buffers();

		glfwPollEvents();
	}
}

Context::Context() {
	if (!glfwInit()) {
		throw std::exception("Failed to initialize GLFW");
	}
}

Context::~Context() {
	glfwTerminate();
}

Window::Window() {
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	if (!(window = glfwCreateWindow(1280, 720, "OpenGL", nullptr, nullptr))) {
		throw std::exception("Failed to create a GLFW Window");
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