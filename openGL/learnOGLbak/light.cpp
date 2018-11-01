#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "shader.h"
#include "camera.h"




A
A
A
A

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static const char *simpleBoxVS = "shaders/light_simple_box.vs";
static const char *simpleBoxFS = "shaders/light_simple_box.fs";
static const char *lightVS = "shaders/light_lamp.vs";
static const char *lightFS = "shaders/light_lamp.fs";

void process_input(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
GLuint loadTexture(const char* path);

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = 400.0f;
float lastY = 300.0f;
bool firstMouse = true;

float deltaTime = 0.0f;
float lastTime = 0.0f;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int
main(int argc, char const *argv[])
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(800, 600, "light", NULL, NULL);

	if (NULL == window) {
		std::cout << "window create failed!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "glad initialise failed!" << std::endl;
		glfwTerminate();
		return -1;
	}

	Shader boxShader(simpleBoxVS, simpleBoxFS);
	Shader lampShader(lightVS, lightFS);

	float vertices[] = {
	    // positions          // normals           // texture coords
	    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
	     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
	     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
	    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
	    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

	    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
	     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
	     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
	    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
	    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

	    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
	     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
	     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
	     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
	     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

	    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
	     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
	     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
	    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
	    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

	    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
	     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
	     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
	    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
	    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	glm::vec3 cubePositions[] = {
	    glm::vec3( 0.0f,  0.0f,  0.0f),
	    glm::vec3( 2.0f,  5.0f, -15.0f),
	    glm::vec3(-1.5f, -2.2f, -2.5f),
	    glm::vec3(-3.8f, -2.0f, -12.3f),
	    glm::vec3( 2.4f, -0.4f, -3.5f),
	    glm::vec3(-1.7f,  3.0f, -7.5f),
	    glm::vec3( 1.3f, -2.0f, -2.5f),
	    glm::vec3( 1.5f,  2.0f, -2.5f),
	    glm::vec3( 1.5f,  0.2f, -1.5f),
	    glm::vec3(-1.3f,  1.0f, -1.5f)
	};

    glm::vec3 pointLightPositions[] = {
        glm::vec3( 0.7f,  0.2f,  2.0f),
        glm::vec3( 2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3( 0.0f,  0.0f, -3.0f)
    };

	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);

	GLuint diffUseMap = loadTexture("./container2.png");
	GLuint specularMap = loadTexture("./container2_specular.png");
	// GLuint emissionMap = loadTexture("./matrix.jpg");

	GLuint lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glEnable(GL_DEPTH_TEST);

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //GL_LINE GL_FILL

	while(!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

		process_input(window);

		glClearColor(0.2f, 0.2f, 0.2f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// lightPos.x = 2 * sin(glfwGetTime());
		// lightPos.y = 1.0f + cos(glfwGetTime())/2;

		boxShader.use();
		boxShader.setVec3("viewPos", camera.pos);

		boxShader.setInt("material.diffUse", 0);
		boxShader.setInt("material.specular", 1);
		boxShader.setInt("material.emission", 2);
		boxShader.setFloat("material.shininess", 32.0f);

		boxShader.setVec3("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
		boxShader.setVec3("dirLight.ambient", glm::vec3(0.05f));
		boxShader.setVec3("dirLight.diffUse", glm::vec3(0.4f));
		boxShader.setVec3("dirLight.specular", glm::vec3(0.5f));

		boxShader.setVec3("pointLight[0].position", pointLightPositions[0]);
		boxShader.setVec3("pointLight[0].ambient", glm::vec3(0.2f));
		boxShader.setVec3("pointLight[0].diffUse", glm::vec3(0.5f));
		boxShader.setVec3("pointLight[0].specular", glm::vec3(1.0f));
		boxShader.setFloat("pointLight[0].constant", 1.0f);
		boxShader.setFloat("pointLight[0].linear", 0.09f);
		boxShader.setFloat("pointLight[0].quadratic", 0.032f);

		boxShader.setVec3("pointLight[1].position", pointLightPositions[1]);
		boxShader.setVec3("pointLight[1].ambient", glm::vec3(0.2f));
		boxShader.setVec3("pointLight[1].diffUse", glm::vec3(0.5f));
		boxShader.setVec3("pointLight[1].specular", glm::vec3(1.0f));
		boxShader.setFloat("pointLight[1].constant", 1.0f);
		boxShader.setFloat("pointLight[1].linear", 0.09f);
		boxShader.setFloat("pointLight[1].quadratic", 0.032f);

		boxShader.setVec3("pointLight[2].position", pointLightPositions[2]);
		boxShader.setVec3("pointLight[2].ambient", glm::vec3(0.2f));
		boxShader.setVec3("pointLight[2].diffUse", glm::vec3(0.5f));
		boxShader.setVec3("pointLight[2].specular", glm::vec3(1.0f));
		boxShader.setFloat("pointLight[2].constant", 1.0f);
		boxShader.setFloat("pointLight[2].linear", 0.09f);
		boxShader.setFloat("pointLight[2].quadratic", 0.032f);

		boxShader.setVec3("pointLight[3].position", pointLightPositions[3]);
		boxShader.setVec3("pointLight[3].ambient", glm::vec3(0.2f));
		boxShader.setVec3("pointLight[3].diffUse", glm::vec3(0.5f));
		boxShader.setVec3("pointLight[3].specular", glm::vec3(1.0f));
		boxShader.setFloat("pointLight[3].constant", 1.0f);
		boxShader.setFloat("pointLight[3].linear", 0.09f);
		boxShader.setFloat("pointLight[3].quadratic", 0.032f);

		// spotlight
		boxShader.setVec3("spotLight.direction", camera.front);
		boxShader.setVec3("spotLight.position", camera.pos);
		boxShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
		boxShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)));
		boxShader.setVec3("spotLight.ambient", glm::vec3(0.0f));
		boxShader.setVec3("spotLight.diffUse", glm::vec3(0.5f));
		boxShader.setVec3("spotLight.specular", glm::vec3(1.0f));
		boxShader.setFloat("spotLight.constant", 1.0f);
		boxShader.setFloat("spotLight.linear", 0.09f);
		boxShader.setFloat("spotLight.quadratic", 0.032f);

		glm::mat4 model, view, projection;

		view = camera.getViewMatrix();
		projection = glm::perspective(glm::radians(camera.zoom), (float)800/600, 0.1f, 100.0f);

		boxShader.setMat4("projection", projection);
		boxShader.setMat4("view", view);
		boxShader.setMat4("model", model);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, diffUseMap);

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, specularMap);

        // glActiveTexture(GL_TEXTURE2);
        // glBindTexture(GL_TEXTURE_2D, emissionMap);

		glBindVertexArray(VAO);
		for (int i = 0; i != 10; ++i) {
			glm::mat4 model;
			model = glm::translate(model, cubePositions[i]);
			float angle = 20*i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			boxShader.setMat4("model", model);
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		lampShader.use();
		lampShader.setMat4("projection", projection);
		lampShader.setMat4("view", view);
		glBindVertexArray(lightVAO);

		for (int i = 0; i != 4; ++i) {
			model = glm::mat4();
			model = glm::translate(model, pointLightPositions[i]);
			model = glm::scale(model, glm::vec3(0.2f));
			lampShader.setMat4("model", model);
			
			glDrawArrays(GL_TRIANGLES, 0, 36);			
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &lightVAO);

	return 0;
}

void process_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyboard(RIGHT, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.processMouseScroll(yoffset);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.processMouseMovement(xoffset, yoffset);
}

GLuint loadTexture(const char* path)
{
	GLuint textureID;
	glGenTextures(1, &textureID);

	int width, height, channel;
	unsigned char* data = stbi_load(path, &width, &height, &channel, 0);

	if (data) {
		GLenum format;
		switch(channel) {
			case 1:
				format = GL_RED;
				break;
			case 3:
				format = GL_RGB;
				break;
			case 4:
				format = GL_RGBA;
				break;
			default:
				break;
		}

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);		
	}
	else {
		std::cout << "load texture failed!" << std::endl;
	}

	return textureID;
}
