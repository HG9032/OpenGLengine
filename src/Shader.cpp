#include "Shader.h"
#include <stdexcept>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char* vertexSourceFile, const char* fragmentSourceFile) :
	vertexSourceFile(vertexSourceFile), fragmentSourceFile(fragmentSourceFile)
{
	vertexShaderSource = getShaderSource(vertexSourceFile);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexSource = vertexShaderSource.c_str();
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLint success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);

		throw std::runtime_error(infoLog);
	}



	fragmentShaderSource = getShaderSource(fragmentSourceFile);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentSource = fragmentShaderSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);


	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);

		throw std::runtime_error(infoLog);
	}



	shaderProgramID = glCreateProgram();

	glAttachShader(shaderProgramID, vertexShader);
	glAttachShader(shaderProgramID, fragmentShader);
	glLinkProgram(shaderProgramID);

	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);

	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(shaderProgramID, 512, nullptr, infoLog);

		throw std::runtime_error(infoLog);
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
	deleteProgram();
}

std::string Shader::getShaderSource(const char* fileName) const
{
	std::ifstream file(fileName, std::ifstream::in);
	if (!file.is_open())
	{
		throw std::runtime_error(
			std::string("Failed to open shader file: ") + fileName );
	}

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

void Shader::useProgram() const
{
	glUseProgram(shaderProgramID);
}

void Shader::deleteProgram()
{
	glDeleteProgram(shaderProgramID);
}

GLuint Shader::getShaderProgramID() const
{
	return shaderProgramID;
}

void Shader::setInt(const char* name, int value) const
{
	glUniform1i(glGetUniformLocation(shaderProgramID, name), value);
}

void Shader::setVec3(const char* name, const glm::vec3& value) const
{
	glUniform3f(glGetUniformLocation(shaderProgramID, name), value.x, value.y, value.z);
}

void Shader::setMat4(const char* name, const glm::mat4& value) const
{
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, name), 1, GL_FALSE, glm::value_ptr(value));
}