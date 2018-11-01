#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const GLchar* vsPath, const GLchar* fsPath);

	GLuint ID;

	void use();
	void setBool(const std::string &name, bool value);
	void setInt(const std::string &name, int value);
	void setFloat(const std::string &name, float value);
	void setMat4(const std::string &name, glm::mat4 value);
	void setVec3(const std::string &name, glm::vec3 value);
};

Shader::Shader(const GLchar* vsPath, const GLchar* fsPath)
{
	std::string vsCode, fsCode;
	std::ifstream vsFile, fsFile;

	vsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fsFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try{
		vsFile.open(vsPath);
		fsFile.open(fsPath);

		std::stringstream vsString, fsString;
		vsString << vsFile.rdbuf();
		fsString << fsFile.rdbuf();

		vsFile.close();
		fsFile.close();

		vsCode = vsString.str();
		fsCode = fsString.str();
	}
	catch(std::ifstream::failure e) {
		std::cout << "shader file read failed!" << std::endl;
	}

	// std::cout << vsCode << std::endl;
	// std::cout << fsCode << std::endl;

	const char* vShaderCode = vsCode.c_str();
	const char* fShaderCode = fsCode.c_str();

	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vShaderCode, NULL);
	glCompileShader(vertexShader);

	int success;
	char info[128];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 128, NULL, info);
		std::cout << "compile vertex shader error!" << info << std::endl;
	}

	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 128, NULL, info);
		std::cout << "compile fragment shader error!" << info << std::endl;
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	// glBindAttribLocation(program, 0, "aPos");

	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(ID, 128, NULL, info);
		std::cout << "link shader failed!" << info << std::endl;
	}

	glDetachShader(ID, vertexShader);
	glDetachShader(ID, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string &name, bool value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value)
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec3(const std::string &name, glm::vec3 value)
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
}

void Shader::setMat4(const std::string &name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

#endif