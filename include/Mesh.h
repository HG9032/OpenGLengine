#pragma once
#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

enum class ColorMode
{
	Uniform,
	VertexBuffer
};


class Mesh {
private:
	GLuint VAO = 0;
	GLuint VBO = 0;
	GLuint EBO = 0;
	GLsizei indexCount = 0;

	GLuint colorVBO = 0;
	ColorMode colorMode = ColorMode::Uniform;
	glm::vec3 uniformColor = glm::vec3(1.0f);

public:
	Mesh(const std::vector<GLfloat>& vertices, const std::vector<GLuint>& indices);
	~Mesh();

	void draw() const;

	void setUniformColor(const glm::vec3& color);
	void setVertexColors(const std::vector<GLfloat>& colors);
};