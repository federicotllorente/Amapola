#pragma once

#include "Amapola/Renderer/RendererContext.h"

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

class GLFWwindow;

namespace Amapola
{
	class OpenGLContext : public RendererContext
	{
	public:
		OpenGLContext(GLFWwindow* window);

		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* m_Window;
	};
}
