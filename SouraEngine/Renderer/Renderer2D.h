#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <array>

#include "Window.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Camera.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace SouraEngine
{

	class Renderer2D
	{
	public:

		static void Init();
		static void OnUpdate();
		static void Shutdown();

		//Utilites
		void LoadShader(const std::string& filepath);

		//Triangles
		void DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3); //colorless
		void DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3); //colored
		static void DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3, glm::vec2 texCoord1, glm::vec2 texCoord2, glm::vec2 texCoord3); //textured

		//Quads
		static void DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec3 color);
		void DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec3 color, float rotation);
		void DrawQuad(glm::vec3 position, glm::vec2 size, glm::vec3 color);

		//Cubes
		void DrawCube(glm::vec3 position, float length);

	private:
		//static unsigned int vertexBufferObject, vertexArrayObject, elementBufferObject;
		//static std::array<float, 32> m_Vertices;
		//static std::array<unsigned int, 6> m_Indices;

		//To public
		//static GLFWwindow* m_Window;
		//static std::shared_ptr<Shader> s_Shader;
		//static std::shared_ptr<Texture2D> s_Texture2D;
		//static std::shared_ptr<Camera> s_Camera;

		//Shader m_Shader;	
		//Texture2D m_Texture2D;
		//Camera m_Camera;

		//std::shared_ptr<VertexArray> m_VertexArray;
		//std::shared_ptr<VertexBuffer> m_VertexBuffer;
		//std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};

}