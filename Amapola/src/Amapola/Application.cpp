#include "amplpch.h"
#include "Application.h"
#include "Log.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

namespace Amapola
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		AMPL_CORE_ASSERT(!s_Instance, "Application instance already exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent)); // this BIND_EVENT_FN will call OnEvent directly with `this` as the event param

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

		// Create vertex array
		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		// Create vertex buffer
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

		float vertices[8 * 3] = {
			-1.0f, 1.0f, 0.0f,
			0.0f, 1.0f, -0.5f,
			1.0f, 1.0f, 0.0f,
			-0.5f, 0.0f, 0.0f,
			0.5f, 0.0f, 0.0f,
			-1.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		
		// Create index buffer
		glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		unsigned int indices[4 * 3] = {
			0, 5, 3,
			3, 1, 6,
			6, 1, 4,
			4, 2, 7
		};
		
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		std::string vsSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Pos;

			uniform mat4 u_MVP;

			void main()
			{
				gl_Position = u_MVP * vec4(a_Pos, 1.0);
			}
		)";

		std::string fsSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			uniform vec4 u_Color;

			void main()
			{
				color = u_Color;
			}
		)";

		//m_Shader = std::make_unique<Shader>(vsSrc, fsSrc);
		m_Shader.reset(new Shader(vsSrc, fsSrc));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			//glClearColor(0.28f, 0.09f, 0.47f, 1.0f);
			glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			m_Shader->SetUniform4f("u_Color", m_Color[0], m_Color[1], m_Color[2], 1.0f);

			modelMatrix = glm::rotate(modelMatrix, glm::radians(m_AngleX), glm::vec3(1.0f, 0.0f, 0.0f));
			modelMatrix = glm::rotate(modelMatrix, glm::radians(m_AngleZ), glm::vec3(0.0f, 0.0f, 1.0f));

			m_Shader->SetUniformMat4f("u_MVP", modelMatrix);
			
			glBindVertexArray(vertexArray);
			glDrawElements(GL_TRIANGLES, 4 * 3, GL_UNSIGNED_INT, nullptr);
			
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	/* Events */
	
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		
		for (auto i = m_LayerStack.end(); i != m_LayerStack.begin();)
		{
			(*--i)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}

	/* Layers */

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
}
