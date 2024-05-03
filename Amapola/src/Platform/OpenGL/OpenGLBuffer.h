#pragma once

#include "Amapola/Renderer/VertexBuffer.h"
#include "Amapola/Renderer/IndexBuffer.h"

namespace Amapola
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(const void* data, unsigned int count);
		~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		//virtual void Lock() const override;
		//virtual void Unlock() const override;

	private:
		unsigned int m_RendererID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(const unsigned int* data, unsigned int count);
		~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual inline unsigned int GetCount() const override { return m_Count; }

	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	};
}
