#include "Renderer2D.h"
#include "Core/Application.h"

namespace SouraEngine
{

	void Renderer2D::Awake()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void Renderer2D::Init()
	{

		//u_Window = Window::Create();
		//u_Window = std::make_unique<Window>("SouraEngine", 1280, 720);
		//glfwSetFramebufferSizeCallback(u_Window->GetNativeWindow(), Window::framebufferSizeCallback);

		glEnable(GL_DEPTH_TEST);

		s_Shader = Shader::Create("../Assets/Shaders/Camera.shader");
		m_LightShader = Shader::Create("../Assets/Shaders/Light.shader");
		m_CubeShader = Shader::Create("../Assets/Shaders/Texture.shader");
		m_LightCubeShader = Shader::Create("../Assets/Shaders/Color.shader");
		s_Texture2D = Texture2D::Create("D:/Work/Programming Projects/SouraEngine/SouraEngine/Assets/Textures/container.jpg");

		m_Command = RenderCommand::Create();
		m_Command->SetClearColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_LightCubeShader->Bind();
		m_LightShader->Bind();

		//s_Shader->Bind();
		//s_Shader->SetInt("texture1", 0);
		s_Camera = std::make_shared<Camera>(glm::vec3(0.0f, 0.0f, 3.0f));
		m_Transform = std::make_unique<Transform>(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(1.0f), glm::vec3(1.0f));
	}

	void Renderer2D::OnUpdate()
	{
		//s_Texture2D->Bind(GL_TEXTURE_2D);

		glm::mat4 projection = glm::perspective(glm::radians(-45.0f), (float)Application::Get().GetWindow().GetWidth() / (float)Application::Get().GetWindow().GetHeight(), 0.1f, 100.0f);

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
		DrawLightCube(m_Transform->GetPosition(), 0.5f);

		//DrawLightCube(m_Transform->GetPosition(), 1.0f);

		//DrawCube({ -0.5f, 0.5f,-0.5f }, 1.0f, false);


		//u_Window->OnUpdate();
	}

	void Renderer2D::Shutdown()
	{
		glfwTerminate();
	}

	void Renderer2D::DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3)
	{
		float verticesAlt[] =
		{
			point1.x, point1.y, 0.0f,
			point2.x, point2.y, 0.0f,
			point3.x, point3.y, 0.0f
		};

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		m_VertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Renderer2D::DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3)
	{
		float verticesAlt[] =
		{   //Points                  //Colors
			point1.x, point1.y, 0.0f, color1.x, color1.y, color1.z,
			point2.x, point2.y, 0.0f, color2.x, color2.y, color2.z,
			point3.x, point3.y, 0.0f, color3.x, color3.y, color3.z
		};

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		m_VertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Renderer2D::DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3, glm::vec3 color1, glm::vec3 color2, glm::vec3 color3, glm::vec2 texCoord1, glm::vec2 texCoord2, glm::vec2 texCoord3)
	{
		float verticesAlt[] =
		{   //Points                  //Colors                      //Textures
			point1.x, point1.y, 0.0f, color1.x, color1.y, color1.z, texCoord1.x, texCoord1.y,
			point2.x, point2.y, 0.0f, color2.x, color2.y, color2.z, texCoord2.x, texCoord2.y,
			point3.x, point3.y, 0.0f, color3.x, color3.y, color3.z, texCoord3.x, texCoord3.y
		};

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));

		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		m_VertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Renderer2D::DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec3 color)
	{

		float verticesAlt[] =
		{   //Points                      //Colors             //TexCoords
			position.x, position.y, 0.0f, color.x, 0.0f, 0.0f, 1.0f, 1.0f,
			position.x, position.y - size.y, 0.0f, 0.0f, color.y, 0.0f, 1.0f, 0.0f,
			position.x - size.x, position.y - size.y, 0.0f, 0.0f, 0.0f, color.z, 0.0f, 0.0f,
			position.x - size.x, position.y, 0.0f, color.x, color.y, 0.0f, 0.0f, 1.0f
		};

		uint32_t indicesAlt[] = { 0, 1, 3, 1, 2, 3 };

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));
		m_IndexBuffer = IndexBuffer::Create(indicesAlt, sizeof(indicesAlt));

		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		m_VertexArray->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}

	void Renderer2D::DrawQuad(glm::vec2 position, glm::vec2 size, glm::vec3 color, float rotation)
	{
		DrawQuad(position, size, color);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(position.x, position.y, 0.0f));
		transform = glm::rotate(transform, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void Renderer2D::DrawQuad(glm::vec3 position, glm::vec2 size, glm::vec3 color)
	{
		float verticesAlt[] =
		{   //Points                            //Colors            //TexCoords
			position.x, position.y, position.z, color.x, 0.0f, 0.0f, 1.0f, 1.0f,
			position.x, position.y - size.y, position.z, 0.0f, color.y, 0.0f, 1.0f, 0.0f,
			position.x - size.x, position.y - size.y, position.z, 0.0f, 0.0f, color.z, 0.0f, 0.0f,
			position.x - size.x, position.y, position.z, color.x, color.y, 0.0f, 0.0f, 1.0f
		};

		uint32_t indices[] = { 0, 1, 3, 1, 2, 3 };

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));
		m_IndexBuffer = IndexBuffer::Create(indices, sizeof(indices));

		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// texture coord attribute
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);

		m_VertexArray->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	void Renderer2D::DrawCube(glm::vec3 position, float length)
	{
		float verticesAlt[] =
		{
			//front
			position.x + length, position.y, position.z, 1.0f, 1.0f,
			position.x + length, position.y - length, position.z, 1.0f, 0.0f,
			position.x, position.y, position.z, 0.0f, 1.0f,
			position.x + length, position.y - length, position.z, 1.0f, 0.0f,
			position.x, position.y - length, position.z, 0.0f, 0.0f,
			position.x, position.y, position.z, 0.0f, 1.0f,

			//left
			position.x, position.y, position.z, 1.0f, 1.0f,
			position.x, position.y - length, position.z, 1.0f, 0.0f,
			position.x, position.y, position.z - length, 0.0f, 1.0f,
			position.x, position.y - length, position.z, 1.0f, 0.0f,
			position.x, position.y - length, position.z - length, 0.0f, 0.0f,
			position.x, position.y, position.z - length, 0.0f, 1.0f,

			//top
			position.x + length, position.y, position.z - length, 1.0f, 1.0f,
			position.x + length, position.y, position.z, 1.0f, 0.0f,
			position.x, position.y, position.z - length, 0.0f, 1.0f,
			position.x + length, position.y, position.z, 1.0f, 0.0f,
			position.x, position.y, position.z, 0.0f, 0.0f,
			position.x, position.y, position.z - length, 0.0f, 1.0f,

			//right
			position.x + length, position.y, position.z - length, 1.0f, 1.0f,
			position.x + length, position.y - length, position.z - length, 1.0f, 0.0f,
			position.x + length, position.y, position.z, 0.0f, 1.0f,
			position.x + length, position.y - length, position.z - length, 1.0f, 0.0f,
			position.x + length, position.y - length, position.z, 0.0f, 0.0f,
			position.x + length, position.y, position.z, 0.0f, 1.0f,

			//back
			position.x + length, position.y, position.z - length, 1.0f, 1.0f,
			position.x + length, position.y - length, position.z - length, 1.0f, 0.0f,
			position.x, position.y, position.z - length, 0.0f, 1.0f,
			position.x + length, position.y - length, position.z - length, 1.0f, 0.0f,
			position.x, position.y - length, position.z - length, 0.0f, 0.0f,
			position.x, position.y, position.z - length, 0.0f, 1.0f,

			//bottom
			position.x + length, position.y - length, position.z - length, 1.0f, 1.0f,
			position.x + length, position.y - length, position.z, 1.0f, 0.0f,
			position.x, position.y - length, position.z - length, 0.0f, 1.0f,
			position.x + length, position.y - length, position.z, 1.0f, 0.0f,
			position.x, position.y - length, position.z, 0.0f, 0.0f,
			position.x, position.y - length, position.z - length, 0.0f, 1.0f
		};

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));

		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		m_VertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	void Renderer2D::DrawCube(glm::vec3 position, float length, bool texture)
	{
		float verticesAlt[] =
		{
			//front
			position.x + length, position.y, position.z,
			position.x + length, position.y - length, position.z,
			position.x, position.y, position.z,
			position.x + length, position.y - length, position.z,
			position.x, position.y - length, position.z,
			position.x, position.y, position.z,

			//left
			position.x, position.y, position.z,
			position.x, position.y - length, position.z,
			position.x, position.y, position.z - length,
			position.x, position.y - length, position.z,
			position.x, position.y - length, position.z - length,
			position.x, position.y, position.z - length,

			//top
			position.x + length, position.y, position.z - length,
			position.x + length, position.y, position.z,
			position.x, position.y, position.z - length,
			position.x + length, position.y, position.z,
			position.x, position.y, position.z,
			position.x, position.y, position.z - length,

			//right
			position.x + length, position.y, position.z - length,
			position.x + length, position.y - length, position.z - length,
			position.x + length, position.y, position.z,
			position.x + length, position.y - length, position.z - length,
			position.x + length, position.y - length, position.z,
			position.x + length, position.y, position.z,

			//back
			position.x + length, position.y, position.z - length,
			position.x + length, position.y - length, position.z - length,
			position.x, position.y, position.z - length,
			position.x + length, position.y - length, position.z - length,
			position.x, position.y - length, position.z - length,
			position.x, position.y, position.z - length,

			//bottom
			position.x + length, position.y - length, position.z - length,
			position.x + length, position.y - length, position.z,
			position.x, position.y - length, position.z - length,
			position.x + length, position.y - length, position.z,
			position.x, position.y - length, position.z,
			position.x, position.y - length, position.z - length,
		};

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));

		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		m_VertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	void Renderer2D::DrawLightCube(glm::vec3 position, float length)
	{
		float verticesAlt[] =
		{
			//front
			position.x + length, position.y, position.z, 0.0f,  0.0f, -1.0f,
			position.x + length, position.y - length, position.z, 0.0f,  0.0f, -1.0f,
			position.x, position.y, position.z, 0.0f,  0.0f, -1.0f,
			position.x + length, position.y - length, position.z, 0.0f,  0.0f, -1.0f,
			position.x, position.y - length, position.z, 0.0f,  0.0f, -1.0f,
			position.x, position.y, position.z, 0.0f,  0.0f, -1.0f,

			//left
			position.x, position.y, position.z, 0.0f,  0.0f,  1.0f,
			position.x, position.y - length, position.z, 0.0f,  0.0f,  1.0f,
			position.x, position.y, position.z - length, 0.0f,  0.0f,  1.0f,
			position.x, position.y - length, position.z, 0.0f,  0.0f,  1.0f,
			position.x, position.y - length, position.z - length, 0.0f,  0.0f,  1.0f,
			position.x, position.y, position.z - length, 0.0f,  0.0f,  1.0f,

			//top
			position.x + length, position.y, position.z - length, -1.0f,  0.0f,  0.0f,
			position.x + length, position.y, position.z, -1.0f,  0.0f,  0.0f,
			position.x, position.y, position.z - length, -1.0f,  0.0f,  0.0f,
			position.x + length, position.y, position.z, -1.0f,  0.0f,  0.0f,
			position.x, position.y, position.z, -1.0f,  0.0f,  0.0f,
			position.x, position.y, position.z - length, -1.0f,  0.0f,  0.0f,

			//right
			position.x + length, position.y, position.z - length, 1.0f,  0.0f,  0.0f,
			position.x + length, position.y - length, position.z - length, 1.0f,  0.0f,  0.0f,
			position.x + length, position.y, position.z, 1.0f,  0.0f,  0.0f,
			position.x + length, position.y - length, position.z - length, 1.0f,  0.0f,  0.0f,
			position.x + length, position.y - length, position.z, 1.0f,  0.0f,  0.0f,
			position.x + length, position.y, position.z, 1.0f,  0.0f,  0.0f,

			//back
			position.x + length, position.y, position.z - length, 0.0f, -1.0f,  0.0f,
			position.x + length, position.y - length, position.z - length, 0.0f, -1.0f,  0.0f,
			position.x, position.y, position.z - length, 0.0f, -1.0f,  0.0f,
			position.x + length, position.y - length, position.z - length, 0.0f, -1.0f,  0.0f,
			position.x, position.y - length, position.z - length, 0.0f, -1.0f,  0.0f,
			position.x, position.y, position.z - length, 0.0f, -1.0f,  0.0f,

			//bottom
			position.x + length, position.y - length, position.z - length, 0.0f,  1.0f,  0.0f,
			position.x + length, position.y - length, position.z, 0.0f,  1.0f,  0.0f,
			position.x, position.y - length, position.z - length, 0.0f,  1.0f,  0.0f,
			position.x + length, position.y - length, position.z, 0.0f,  1.0f,  0.0f,
			position.x, position.y - length, position.z, 0.0f,  1.0f,  0.0f,
			position.x, position.y - length, position.z - length, 0.0f,  1.0f,  0.0f,
		};

		m_VertexArray = VertexArray::Create();
		m_VertexBuffer = VertexBuffer::Create(verticesAlt, sizeof(verticesAlt));

		m_VertexArray->Bind();

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		m_VertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}