#pragma once

#define GLEW_STATIC
#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

std::string read(const std::string& path);

GLuint createShaderProgram(GLenum type, const std::string& source);

class Quad final {
public:
	Quad();

	void draw(const glm::mat4& projection, const glm::mat4& modelView);

private:
	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	GLuint pipeline;
	GLuint fragment;
	GLuint vertex;

	GLuint projectionUniform;
	GLuint modelViewUniform;
};
