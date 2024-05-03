#include "amplpch.h"
#include "VertexBuffer.h"
#include "Renderer.h"
#include "Amapola/Log.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

// TODO Merge files with IndexBuffer into Buffer.cpp
namespace Amapola
{
	VertexBuffer::~VertexBuffer()
	{
	}

	VertexBuffer* VertexBuffer::Create(const void* data, unsigned int count)
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
			return new OpenGLVertexBuffer(data, count);
		}
		default:
		{
			AMPL_CORE_ASSERT(false, "Unknown Renderer API");
			return nullptr;
		}
		}
	}
}
