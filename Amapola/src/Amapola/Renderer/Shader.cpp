#include "amplpch.h"
#include "Shader.h"
#include "Renderer.h"
#include "Amapola/Log.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Amapola
{
	Shader::~Shader()
	{
	}

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:
			{
				AMPL_CORE_ASSERT(false, "Renderer API cannot be NONE");
				return nullptr;
			}
			case RendererAPI::OpenGL:
			{
				return new OpenGLShader(vertexSrc, fragmentSrc);
			}
			default:
			{
				AMPL_CORE_ASSERT(false, "Unknown Renderer API");
				return nullptr;
			}
		}
	}
}
