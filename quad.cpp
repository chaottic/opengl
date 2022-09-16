#include "quad.hpp"

std::string read(const std::string& path) {
	std::fstream file(path);

	std::stringstream sstream;
	std::string line;

	while (getline(file, line)) {
		sstream << line << '\n';
	}

	return sstream.str();
}

GLuint createShaderProgram(GLenum type, const std::string& source) {
	const char* cstring = source.c_str();

	return glCreateShaderProgramv(type, 1, &cstring);
}

Quad::Quad() {
	glCreateVertexArrays(1, &vao);
	glCreateBuffers(1, &vbo);
	glCreateBuffers(1, &ebo);

	glCreateProgramPipelines(1, &pipeline);
	fragment = createShaderProgram(GL_FRAGMENT_SHADER, read("quad_fragment.glsl"));
	vertex = createShaderProgram(GL_VERTEX_SHADER, read("quad_vertex.glsl"));

	glUseProgramStages(pipeline, GL_FRAGMENT_SHADER_BIT, fragment);
	glUseProgramStages(pipeline, GL_VERTEX_SHADER_BIT, vertex);
	glValidateProgramPipeline(pipeline);

	projectionUniform = glGetUniformLocation(vertex, "projection");
	modelViewUniform = glGetUniformLocation(vertex, "modelView");

	float vertices[] = {
		-0.5F, -0.5F, 0.0F, 1.0F,
		 0.5F, -0.5F, 0.0F, 1.0F,
		 0.5F,  0.5F, 0.0F, 1.0F,
		-0.5F,  0.5F, 0.0F, 1.0F
	};

	int elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	glNamedBufferStorage(vbo, 16 * sizeof(float), vertices, GL_MAP_READ_BIT);

	glNamedBufferStorage(ebo, 6 * sizeof(int), elements, GL_MAP_READ_BIT);

	glVertexArrayVertexBuffer(vao, 0, vbo, 0, 16);

	glVertexArrayAttribFormat(vao, 0, 4, GL_FLOAT, false, 0);
	glVertexArrayAttribBinding(vao, 0, 0);

	glVertexArrayElementBuffer(vao, ebo);
}

void Quad::draw(const glm::mat4& projection, const glm::mat4& modelView) {
	glBindProgramPipeline(pipeline);

	glProgramUniformMatrix4fv(vertex, projectionUniform, 1, false, &projection[0][0]);
	glProgramUniformMatrix4fv(vertex, modelViewUniform, 1, false, &modelView[0][0]);

	glBindVertexArray(vao);

	glEnableVertexArrayAttrib(vao, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glDisableVertexArrayAttrib(vao, 0);

	glBindVertexArray(0);

	glBindProgramPipeline(0);
}