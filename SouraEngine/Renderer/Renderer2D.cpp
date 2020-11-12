#include "Renderer2D.h"

Renderer2D::Renderer2D()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Renderer2D::Init()
{
	m_Window = Window::Create("SouraEngine", 1280, 720);

	glEnable(GL_DEPTH_TEST);

	m_Shader = Shader("Assets/Shaders/Simple.shader");
	m_Texture2D = Texture2D("D:/Work/Programming Projects/SouraEngine/SouraEngine/Assets/Textures/container.jpg");

	glClear(GL_DEPTH_BUFFER_BIT);

	m_Shader.use();
	glUniform1i(glGetUniformLocation(m_Shader.ID, "texture1"), 0);
	m_Camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Renderer2D::OnUpdate()
{
	m_Texture2D.Bind(GL_TEXTURE_2D);

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
	glm::mat4 view = m_Camera.GetViewMatrix();
	m_Shader.UploadUniformMat4("projection", projection);
	m_Shader.UploadUniformMat4("view", view);
	glm::mat4 model = glm::mat4(1.0f);
	m_Shader.UploadUniformMat4("model", model);

	//DrawTriangle({ 0.5f, -0.5f }, { -0.5f, -0.5f }, { 0.0f,  0.5f }, { 1.0f,0.0f,0.0f }, { 0.0f,1.0f,0.0f }, { 0.0f,0.0f,1.0f }, { 0.0f,0.0f }, { 1.0f,0.0f }, { 0.5f,1.0f });

	//DrawQuad({ 0.5f, 0.5f }, { 1.0f,1.0f }, { 1.0f,1.0f,1.0f });
	DrawCube({ -0.5f, 0.5f,-0.5f }, 1.0f);


	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

void Renderer2D::Shutdown()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
	glDeleteBuffers(1, &vertexBufferObject);

	//glfwTerminate();

}

void Renderer2D::LoadShader(const std::string & filepath)
{
	
}

void Renderer2D::DrawTriangle(glm::vec2 point1, glm::vec2 point2, glm::vec2 point3)
{
	float verticesAlt[] =
	{
		point1.x, point1.y, 0.0f,
		point2.x, point2.y, 0.0f,
		point3.x, point3.y, 0.0f
	};

	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesAlt), verticesAlt, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(vertexArrayObject);
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

	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesAlt), verticesAlt, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(vertexArrayObject);
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

	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesAlt), verticesAlt, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(vertexArrayObject);
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

	unsigned int indices[] = { 0, 1, 3, 1, 2, 3 };

	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	glGenBuffers(1, &elementBufferObject);

	glBindVertexArray(vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesAlt), verticesAlt, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(vertexArrayObject);
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

	unsigned int indices[] = { 0, 1, 3, 1, 2, 3 };

	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	glGenBuffers(1, &elementBufferObject);

	glBindVertexArray(vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesAlt), verticesAlt, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(vertexArrayObject);
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

	glGenVertexArrays(1, &vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);

	glBindVertexArray(vertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesAlt), verticesAlt, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}
