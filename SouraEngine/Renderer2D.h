#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.h"
#include "Texture2D.h"

class Renderer2D
{
public:
	void Init();
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

private:
	unsigned int vertexBufferObject, vertexArrayObject, elementBufferObject;
	static std::shared_ptr<Shader> shader;
};