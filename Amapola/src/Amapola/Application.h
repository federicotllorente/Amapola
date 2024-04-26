#pragma once

#include "Core.h"
#include "Window.h"
#include "Layers/LayerStack.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

#include "ImGui/ImGuiLayer.h"

#include <glm/glm.hpp>

// TEMPORARY
#include "Amapola/Renderer/Shader.h"

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

		unsigned int vertexBuffer, indexBuffer, vertexArray;
		std::unique_ptr<Shader> m_Shader;

		float bgColor[3] = { 0.28f, 0.09f, 0.47f };
		float m_Color[3] = { 0.38f, 0.19f, 0.57f };

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		/*glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;*/

		float m_AngleX = 0.0f;
		float m_AngleZ = 0.0f;
		
	public:
		inline float& GetBgColor() { return *bgColor; }
		inline float& GetColor() { return *m_Color; }
		inline glm::mat4& GetModelMatrix() { return modelMatrix; }
		inline float& GetAngleX() { return m_AngleX; }
		inline float& GetAngleZ() { return m_AngleZ; }
	};

	/* To be defined in client */
	Application* CreateApplication();
}
