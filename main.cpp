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

		auto aspectRatio = window.get_aspect_ratio();

		auto projection = glm::perspective(1.047, aspectRatio, 0.01, 1000.0);

		auto modelView = glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, -10.0));

		quad.draw(projection, modelView);

		window.swap_buffers();

		glfwPollEvents();
	}
}