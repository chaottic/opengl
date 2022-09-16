#include "main.hpp"

int main() {
	Context context;
	Window window;

	if (glewInit() != GLEW_OK) {
		throw std::exception("Failed to initialize GLEW");
	}

	Quad quad;

	while (!window.should_close()) {
		glClear(GL_COLOR_BUFFER_BIT);

		auto aspectRatio = static_cast<double>(window.get_width()) / static_cast<double>(window.get_height());

		auto projection = glm::perspective(1.047, aspectRatio, 0.01, 1000.0);

		auto modelView = glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, -10.0));

		quad.draw(projection, modelView);

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

	glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_FLUSH);

	if (!(window = glfwCreateWindow(1280, 720, "OpenGL", nullptr, nullptr))) {
		throw std::exception("Failed to create a GLFW Window");
	}

	center();

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

int Window::get_width() {
	return width;
}

int Window::get_height() {
	return height;
}

void Window::center() {
	auto monitor = glfwGetPrimaryMonitor();
	auto videoMode = glfwGetVideoMode(monitor);

	if (videoMode) {
		int width;
		int height;

		struct final {
			int x;
			int y;
			int width;
			int height;
		} workarea;

		glfwGetWindowSize(window, &width, &height);
		glfwGetMonitorWorkarea(monitor, &workarea.x, &workarea.y, &workarea.width, &workarea.height);

		this->width = width;
		this->height = height;

		glfwSetWindowMonitor(window, nullptr, 
			(workarea.width - width) / 2, 
			(workarea.height - height) / 2, width, height, videoMode->refreshRate);
	}
}