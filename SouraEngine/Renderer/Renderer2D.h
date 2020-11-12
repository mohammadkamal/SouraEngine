#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Window.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Camera.h"

class Renderer2D
{
public:
	Renderer2D();

	void Init();
	void OnUpdate();
	void Shutdown();

	//Utilites
	void LoadShader(const std::string& filepath);

	//Triangles
	void DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3); //colorless
	void DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3); //colored
	void DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3, glm::vec2 texCoord1, glm::vec2 texCoord2, glm::vec2 texCoord3); //textured

	//Quads
	void DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec3 color);
	void DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec3 color, float rotation);
	void DrawQuad(glm::vec3 position, glm::vec2 size, glm::vec3 color);

	//Cubes
	void DrawCube(glm::vec3 position, float length);

private:
	unsigned int vertexBufferObject, vertexArrayObject, elementBufferObject;
	static std::shared_ptr<Shader> shader;

	GLFWwindow* m_Window;
	Shader m_Shader;
	Texture2D m_Texture2D;
	Camera m_Camera;
};