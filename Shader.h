#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>

class Shader {
private:
	std::string vertexShaderSource;
	std::string fragmentShaderSource;
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint shaderProgramID;
	const char* vertexSourceFile;
	const char* fragmentSourceFile;

public:
	Shader(const char* vertexSourceFile, const char* fragmentSourceFile);
	~Shader();
	std::string getShaderSource(const char* fileName) const;
	void useProgram() const;
	void deleteProgram();
	GLuint getShaderProgramID() const;
	void setInt(const char* name, int value) const;
	void setVec3(const char* name, const glm::vec3& value) const;
	void setMat4(const char* name, const glm::mat4& value) const;
};