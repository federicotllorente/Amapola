#pragma once

#include "Core.h"
#include "Log.h"
#include "Window.h"
#include "Layers/LayerStack.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

#include "ImGui/ImGuiLayer.h"

#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"

// TEMPORARY
#include "Renderer/Shader.h"
//#include "Platform/OpenGL/OpenGLShader.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/VertexArray.h"

namespace Amapola
{
	class AMAPOLA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		// Layer wrappers
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		static Application* s_Instance; // For now this will be a singleton - TODO Revise later

		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		VertexBuffer* vertexBuffer = nullptr;
		IndexBuffer* indexBuffer = nullptr;
		VertexArray* vertexArray = nullptr;

		std::unique_ptr<Shader> m_Shader;

		float bgColor[3] = { 0.28f, 0.09f, 0.47f };
		float m_Color[3] = { 0.38f, 0.19f, 0.57f };

		glm::vec4 projectionPosition = glm::vec4(-1, 1, -1, 1);
		float m_Near = -1.0f;
		float m_Far = 1.0f;
		glm::vec3 viewCoords = glm::vec3(0, 0, 0);

		float m_AngleX = 0.0f;
		float m_AngleZ = 0.0f;
		
	public:
		inline float& GetBgColor() { return *bgColor; }
		inline float& GetColor() { return *m_Color; }
		inline glm::vec4& GetProjectionPosition() { return projectionPosition; }
		inline glm::vec3& GetViewCoords() { return viewCoords; }
		inline float& GetNear() { return m_Near; }
		inline float& GetFar() { return m_Far; }
		inline float& GetAngleX() { return m_AngleX; }
		inline float& GetAngleZ() { return m_AngleZ; }
	};

	/* To be defined in client */
	Application* CreateApplication();
}
