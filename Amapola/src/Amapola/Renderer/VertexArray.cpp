#include "amplpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Amapola/Log.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Amapola
{
	VertexArray::~VertexArray()
	{
	}

	VertexArray* VertexArray::Create()
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
				return new OpenGLVertexArray();
			}
			default:
			{
				AMPL_CORE_ASSERT(false, "Unknown Renderer API");
				return nullptr;
			}
		}
	}
}
