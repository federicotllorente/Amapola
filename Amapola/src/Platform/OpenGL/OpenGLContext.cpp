#include "amplpch.h"
#include "OpenGLContext.h"
#include "Amapola/Application.h"
#include "Amapola/Log.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Amapola
{
	OpenGLContext::OpenGLContext(GLFWwindow* window)
		: m_Window(window)
	{
		AMPL_CORE_ASSERT(window, "Window is null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AMPL_CORE_ASSERT(status, "Failed to initialize Glad");

		/*AMPL_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		AMPL_CORE_INFO("OpenGL version: {1}", glGetString(GL_VERSION));*/
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
}
