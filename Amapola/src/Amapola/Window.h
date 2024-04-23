#pragma once

#include "amplpch.h"
#include "Core.h"
#include "Events/Event.h"

namespace Amapola
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			const std::string& title = "Amapola Engine",
			unsigned int width = 1280,
			unsigned int height = 720
		)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	/*
	* 
	* Interface representing a desktop system based Window
	* 
	* This is intended to be platform-independent, that's why all these methods are virtual,
	* they need to be implemented for each platform
	* 
	*/
	class AMAPOLA_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		// This will return the corresponding window for each API implementation
		// For example for GLFW this will return the GLFWwindow, and so on...
		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
