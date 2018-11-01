#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "shader.h"

#include <iostream>
#include <stdio.h>
#include <math.h>

void frameBuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

const char* vertex_shader_simple = "shaders/vertex_shader_simple.vs";
const char* fragment_shader_simple = "shaders/fragment_shader_simple.fs";
const char* green_fragment_shader_simple = "shaders/green_fragment_shader_simple.fs";

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

	Shader simpleShader(vertex_shader_simple, fragment_shader_simple);
	Shader greenShader(vertex_shader_simple, green_fragment_shader_simple);

	float first_vertices[] = {
		-1.f, -1.f, 0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, -1.f, 0.0f, 0.0f, 0.0f, 1.0f,
		-1.f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	unsigned int first_indices[] = {
		0, 1, 2,
		0, 1, 3
	};

	float second_vertices[] = {
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		1.0f, -1.0f, 0.0f
	};

	unsigned int second_incices[] = {
		0, 1, 2,
		0, 1, 3
	};

	GLuint VAO[2], VBO[2], EBO[2];
	glGenVertexArrays(2, VAO);
	glGenBuffers(2, VBO);
	glGenBuffers(2, EBO);

	// first vertex array.
	glBindVertexArray(VAO[0]);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(first_vertices), first_vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(first_indices), first_indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	// second vertex array.
	glBindVertexArray(VAO[1]);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(second_vertices), second_vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(second_incices), second_incices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

 	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //GL_LINE GL_FILL

	while (!glfwWindowShouldClose(window)) {
		process_input(window);
		// Draw
		glClearColor(0.2f, 0.3f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		simpleShader.use();
		simpleShader.setFloat("offsetY", 0.2);
		glBindVertexArray(VAO[0]);
		// glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		greenShader.use();

		// float time = glfwGetTime();
		// float redValue = sin(time) / 2.0f + 0.5;
		// unsigned int colorLocation = glGetUniformLocation(greenShader.ID, "fragColor");
		// if (-1 == colorLocation) {
		// 	std::cout << "uniform location get failed!" << std::endl;
		// }
		// glUniform4f(colorLocation, redValue, 0.0f, 1.0f, 1.0f);

		glBindVertexArray(VAO[1]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();		
	}

	glDeleteBuffers(2, VBO);
	glDeleteBuffers(2, EBO);
	glDeleteVertexArrays(2, VAO);

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