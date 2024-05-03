#include "amplpch.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Amapola/Log.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

// TODO Merge files with VertexBuffer into Buffer.cpp
namespace Amapola
{
	IndexBuffer::~IndexBuffer()
	{
	}
	
	IndexBuffer* IndexBuffer::Create(const unsigned int* data, unsigned int count)
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
				return new OpenGLIndexBuffer(data, count);
			}
			default:
			{
				AMPL_CORE_ASSERT(false, "Unknown Renderer API");
				return nullptr;
			}
		}
	}
}
