#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <glfw3.h>

#include <iostream>

using namespace std;
//using namespace glm;

void progressInput(GLFWwindow*);
void frameBuffer_size_callBack(GLFWwindow*, int, int);

int
main()
{
    GLFWwindow* wnd;

    if (!glfwInit()) {
        fprintf(stderr, "Failed to init GLFW!\n");
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    wnd = glfwCreateWindow(800, 480, "My First Window", NULL, NULL);

    if (NULL	 == wnd) {
        fprintf(stderr, "Failed to create window!\n");
        getchar(); // ????
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(wnd);
    glewExperimental = true;

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to init GLEW!\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    glfwSetInputMode(wnd, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    // frameBuffer_size_callBack(wnd, 800, 600);
    glfwSetFramebufferSizeCallback(wnd, frameBuffer_size_callBack);

    GLuint VAOId;
    glGenVertexArrays(1, &VAOId);
    glBindVertexArray(VAOId);

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
    };

    GLuint VBOId;
    glGenBuffers(1, &VBOId);
    glBindBuffer(GL_ARRAY_BUFFER, VBOId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(wnd)) {

        glClear( GL_COLOR_BUFFER_BIT );

        progressInput(wnd);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBOId);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);

        glfwSwapBuffers(wnd);
        glfwPollEvents();
    }

    glDeleteBuffers(1, &VBOId);
    glDeleteVertexArrays(1, &VAOId);

    glfwTerminate();
}

void frameBuffer_size_callBack(GLFWwindow* wnd, int width, int height)
{
	cout << __PRETTY_FUNCTION__ << endl;

	glViewport(0, 0, width, height);	
}	

void progressInput(GLFWwindow* wnd)
{
	cout << __PRETTY_FUNCTION__ << endl;

	if (glfwGetKey(wnd, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(wnd, 	true);
}

