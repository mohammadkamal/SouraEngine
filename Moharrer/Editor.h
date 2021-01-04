#pragma once
#include "Core/Window.h"
#include "Renderer/Shader.h"
#include "Renderer/Texture2D.h"
#include "Renderer/Camera.h"
#include "Renderer/PerspectiveCamera.h"
#include "Components/Transform.h"
#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/RenderCommand.h"

namespace Moharrer
{
	class Editor
	{
	public:
		Editor();
		~Editor() = default;

		void OnUpdate();

		static Editor& Get()
		{
			Editor g_Editor;
			return g_Editor;
		}

	private:
		std::unique_ptr<SouraEngine::Window> u_Window;
		std::shared_ptr<SouraEngine::Shader> s_Shader;
		std::shared_ptr<SouraEngine::Shader> m_LightShader;
		std::shared_ptr<SouraEngine::Texture2D> s_Texture2D;
		std::shared_ptr<SouraEngine::Camera> s_Camera;
		std::shared_ptr<SouraEngine::PerspectiveCamera> m_PerCamera;

		std::unique_ptr<SouraEngine::Transform> m_Transform;
		std::shared_ptr<SouraEngine::Shader> m_CubeShader;
		std::shared_ptr<SouraEngine::Shader> m_LightCubeShader;

		std::shared_ptr<SouraEngine::VertexArray> m_VertexArray;
		std::shared_ptr<SouraEngine::VertexBuffer> m_VertexBuffer;
		std::shared_ptr<SouraEngine::IndexBuffer> m_IndexBuffer;

		std::shared_ptr<SouraEngine::RenderCommand> m_Command;
	};
}