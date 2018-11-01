#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "shader.h"

#include <iostream>
#include <stdio.h>
#include <math.h>

// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void frameBuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

const char* vertex_shader_trans = "shaders/vertex_shader_trans.vs";
const char* fragment_shader_trans = "shaders/fragment_shader_trans.fs";

int
main(int argc, char const *argv[])
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Js", NULL, NULL);

	if (NULL == window) {
		std::cout << "create window failed!" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, frameBuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "initialise glad failed!" << std::endl;
		return -1;
	}

	Shader simpleShader(vertex_shader_trans, fragment_shader_trans);

	float first_vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f
	};

	unsigned int first_indices[] = {
		0, 1, 2,
		1, 2, 3
	};

	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// first vertex array.
	glBindVertexArray(VAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(first_vertices), first_vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(first_indices), first_indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

 	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //GL_LINE GL_FILL




	while (!glfwWindowShouldClose(window)) {
		process_input(window);
		// Draw
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glm::mat4 trans = glm::mat4(1.0f);
		trans = glm::translate(trans, glm::vec3(0.5f, 0.5f, 0.0f));
		trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 1.0f));

		simpleShader.use();

		GLuint transformLoc = glGetUniformLocation(simpleShader.ID, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		glBindVertexArray(VAO);
		// glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		std::cout << "time: " << glfwGetTime() << std::endl;

		glm::mat4 trans2 = glm::mat4(1.0f);
		trans2 = glm::translate(trans2, glm::vec3(-0.5f, -0.5f, 0.0f));
		// trans2 = glm::rotate(trans2, glm::radians(90.f), glm::vec3(0.0f, 0.0f, 1.0f));
		float ratio = sin(glfwGetTime());
		trans2 = glm::scale(trans2, glm::vec3(ratio, ratio, 1.0f));
		GLuint transformLoc2 = glGetUniformLocation(simpleShader.ID, "transform");
		glUniformMatrix4fv(transformLoc2, 1, GL_FALSE, glm::value_ptr(trans2));

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// float time = glfwGetTime();
		// float redValue = sin(time) / 2.0f + 0.5;
		// unsigned int colorLocation = glGetUniformLocation(greenShader.ID, "fragColor");
		// if (-1 == colorLocation) {
		// 	std::cout << "uniform location get failed!" << std::endl;
		// }
		// glUniform4f(colorLocation, redValue, 0.0f, 1.0f, 1.0f);

		glfwSwapBuffers(window);
		glfwPollEvents();		
	}

	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);

	glfwTerminate();

	return 0;
}

void frameBuffer_size_callback(GLFWwindow* window, int width, int height)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}