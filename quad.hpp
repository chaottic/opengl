#pragma once

#define GLEW_STATIC
#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>

std::string read(const std::string& path);

GLuint createShaderProgram(GLenum type, const std::string& source);

class Quad final {
public:
	Quad();

	void draw();

private:
	GLuint vao;
	GLuint vbo;
	GLuint ebo;

	GLuint pipeline;
	GLuint fragment;
	GLuint vertex;
};
