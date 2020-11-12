#include "Renderer/Renderer2D.h"
#include "Window.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);

//const unsigned int SCREEN_WIDTH = 800;
//const unsigned int SCREEN_HEIGHT = 600;

/*
//Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;*/

int main()
{
	Renderer2D render2D = Renderer2D();
	render2D.Init();

	while (true)
	{
		render2D.OnUpdate();
	}
	render2D.Shutdown();

	//glfwTerminate();
	return 0;
}

/*void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}*/