#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer/Renderer2D.h"
#include "Renderer/Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

//Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SouraEngine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD";
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	Shader simpleShader("Assets/Shaders/Simple.shader");
	Texture2D texture("D:/Work/Programming Projects/SouraEngine/SouraEngine/Assets/Textures/container.jpg");

	Renderer2D ren2D;
	ren2D.Init();

	glClear(GL_DEPTH_BUFFER_BIT);

	simpleShader.use();
	glUniform1i(glGetUniformLocation(simpleShader.ID, "texture1"), 0);

	while (true)
	{
		texture.Bind(GL_TEXTURE_2D);

		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		simpleShader.UploadUniformMat4("projection", projection);
		simpleShader.UploadUniformMat4("view", view);
		glm::mat4 model = glm::mat4(1.0f);
		simpleShader.UploadUniformMat4("model", model);

		//ren2D.DrawTriangle({ 0.5f, -0.5f }, { -0.5f, -0.5f }, { 0.0f,  0.5f }, { 1.0f,0.0f,0.0f }, { 0.0f,1.0f,0.0f }, { 0.0f,0.0f,1.0f }, { 0.0f,0.0f }, { 1.0f,0.0f }, { 0.5f,1.0f });

		//ren2D.DrawQuad({ 0.5f, 0.5f }, { 1.0f,1.0f }, { 1.0f,1.0f,1.0f });
		ren2D.DrawCube({ -0.5f, 0.5f,-0.5f }, 1.0f);
		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	ren2D.Shutdown();

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}