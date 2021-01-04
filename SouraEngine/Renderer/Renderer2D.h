#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

#include "Core/Window.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Camera.h"
#include "PerspectiveCamera.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Components/Transform.h"
#include "RenderCommand.h"

namespace SouraEngine
{

	class Renderer2D
	{
	public:
		//Renderer2D();
		Renderer2D() = default;

		void Awake();
		void Init();
		void OnUpdate();
		void Shutdown();

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
		void DrawCube(glm::vec3 position, float length, bool texture);

		//LightCube
		void DrawLightCube(glm::vec3 position, float length);

		
		static Renderer2D& get()
		{
			static Renderer2D g_Renderer2D;
			return g_Renderer2D;
		}

	private:

		std::unique_ptr<Window> u_Window;
		std::shared_ptr<Shader> s_Shader;
		std::shared_ptr<Shader> m_LightShader;
		std::shared_ptr<Texture2D> s_Texture2D;
		std::shared_ptr<Camera> s_Camera;
		std::shared_ptr<PerspectiveCamera> m_PerCamera;

		std::unique_ptr<Transform> m_Transform;
		std::shared_ptr<Shader> m_CubeShader;
		std::shared_ptr<Shader> m_LightCubeShader;

		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

		std::shared_ptr<RenderCommand> m_Command;
	};

}