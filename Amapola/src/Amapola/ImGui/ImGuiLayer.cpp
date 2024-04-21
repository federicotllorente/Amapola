#include "amplpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

#include "Amapola/Application.h"

#include <Amapola/Events/MouseEvent.h>
#include <Amapola/Events/KeyEvent.h>

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Amapola
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGui")
	{
	}
	
	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TODO - TEMPORARY - should eventually use Amapola key codes
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
	}
	
	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight()); // TODO Should we save and set this data on every window resize?

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventType type = event.GetEventType();

		switch (type)
		{
			case Amapola::EventType::WindowResized:
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<WindowResizedEvent>(
					[](WindowResizedEvent& e)
					{
						unsigned int w = e.GetWidth();
						unsigned int h = e.GetHeight();

						ImGuiIO& io = ImGui::GetIO();
						io.DisplaySize = ImVec2(w, h);
						io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
						glViewport(0, 0, w, h);

						return false;
					}
				);
				break;
			}
			case Amapola::EventType::KeyPressed:
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<KeyPressedEvent>(
					[](KeyPressedEvent& e)
					{
						int keycode = e.GetKeyCode();

						ImGuiIO& io = ImGui::GetIO();
						//io.AddKeyEvent(keycode, true); // TODO Transform our keycodes into ImGui's
						io.KeysDown[keycode] = true;

						/* Modifier keys */
						
						// KeyCtrl
						io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
						
						// KeyShift
						io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
						
						// KeyAlt
						io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
						
						// KeySuper (Cmd/Super/Windows)
						io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];

						return false;
					}
				);
				break;
			}
			case Amapola::EventType::KeyReleased:
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<KeyReleasedEvent>(
					[](KeyReleasedEvent& e)
					{
						int keycode = e.GetKeyCode();

						ImGuiIO& io = ImGui::GetIO();
						//io.AddKeyEvent(keycode, false); // TODO Transform our keycodes into ImGui's
						io.KeysDown[keycode] = false;

						/* Modifier keys */

						// KeyCtrl
						io.KeyCtrl = !(io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL]);

						// KeyShift
						io.KeyCtrl = !(io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT]);

						// KeyAlt
						io.KeyCtrl = !(io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT]);

						// KeySuper (Cmd/Super/Windows)
						io.KeyCtrl = !(io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER]);

						return false;
					}
				);
				break;
			}
			case Amapola::EventType::MouseButtonPressed:
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<MouseButtonPressedEvent>(
					[](MouseButtonPressedEvent& e)
					{
						int button = e.GetMouseButton();

						ImGuiIO& io = ImGui::GetIO();
						io.AddMouseButtonEvent(button, true);
					
						return false;
					}
				);
				break;
			}
			case Amapola::EventType::MouseButtonReleased:
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<MouseButtonReleasedEvent>(
					[](MouseButtonReleasedEvent& e)
					{
						int button = e.GetMouseButton();

						ImGuiIO& io = ImGui::GetIO();
						io.AddMouseButtonEvent(button, false);
					
						return false;
					}
				);
				break;
			}
			case Amapola::EventType::MouseMoved:
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<MouseMovedEvent>(
					[](MouseMovedEvent& e)
					{
						float x = e.GetX();
						float y = e.GetY();

						ImGuiIO& io = ImGui::GetIO();
						io.AddMousePosEvent(x, y);

						return false;
					}
				);
				break;
			}
			case Amapola::EventType::MouseScrolled:
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<MouseScrolledEvent>(
					[](MouseScrolledEvent& e)
					{
						float xOffset = e.GetXOffset();
						float yOffset = e.GetYOffset();

						ImGuiIO& io = ImGui::GetIO();
						io.AddMouseWheelEvent(xOffset, yOffset);

						return false;
					}
				);
				break;
			}
			default:
				break;
		}
	}
}
