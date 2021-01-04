#include "Editor.h"
#include "Renderer/Renderer2D.h"
#include <includes/glm/glm.hpp>
#include <includes/glm/gtc/matrix_transform.hpp>
#include <includes/glm/gtc/type_ptr.hpp>

namespace Moharrer
{
	Editor::Editor()
	{
		SouraEngine::Renderer2D::get().Init();
	}

	void Editor::OnUpdate()
	{
		//s_Texture2D->Bind(GL_TEXTURE_2D);

		glm::mat4 projection = glm::perspective(glm::radians(-45.0f), (float)u_Window->GetWidth() / (float)u_Window->GetHeight(), 0.1f, 100.0f);

		glm::mat4 view = s_Camera->GetViewMatrix();
		//s_Shader->UploadUniformMat4("projection", projection);
		m_LightCubeShader->UploadUniformMat4("projection", projection);
		//s_Shader->UploadUniformMat4("view", view);
		m_LightCubeShader->UploadUniformMat4("view", view);
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::rotate(model, glm::radians(-20.0f), glm::vec3(1.0f, 0.3f, 0.5f));
		//s_Shader->UploadUniformMat4("model", model);
		m_LightCubeShader->UploadUniformMat4("model", model);

		//DrawTriangle({ 0.5f, -0.5f }, { -0.5f, -0.5f }, { 0.0f,  0.5f }, { 1.0f,0.0f,0.0f }, { 0.0f,1.0f,0.0f }, { 0.0f,0.0f,1.0f }, { 0.0f,0.0f }, { 1.0f,0.0f }, { 0.5f,1.0f });

		//DrawQuad({ 0.5f, 0.5f }, { 1.0f,1.0f }, { 1.0f,1.0f,1.0f });
		//s_Shader->Bind();
		//DrawCube({ -0.5f, 0.5f,-0.5f }, 1.0f);
		//DrawCube(m_Transform->GetPosition(), 1.0f);

		//DrawCube({ 0.75f, 0.2f,-0.3f }, 0.5f, false);

		glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

		m_LightShader->Bind();
		m_LightShader->UploadUniformMat4("projection", projection);
		m_LightShader->UploadUniformMat4("view", view);
		m_LightShader->UploadUniformMat4("model", model);

		m_LightShader->SetFloat3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
		m_LightShader->SetFloat3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
		m_LightShader->SetFloat3("lightPos", lightPos);
		m_LightShader->SetFloat3("viewPos", s_Camera->Position);
		//DrawCube({ 0.75f, 0.2f,-0.3f }, 0.5f, false);
		SouraEngine::Renderer2D::get().DrawLightCube({ 0.75f, 0.2f,-0.3f }, 0.5f);

		m_LightCubeShader->Bind();
		SouraEngine::Renderer2D::get().DrawLightCube(m_Transform->GetPosition(), 0.5f);

		//DrawLightCube(m_Transform->GetPosition(), 1.0f);

		//DrawCube({ -0.5f, 0.5f,-0.5f }, 1.0f, false);


		//u_Window->OnUpdate();
	}

}