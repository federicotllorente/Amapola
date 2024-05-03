#pragma once

#include "Amapola/Renderer/VertexArray.h"

namespace Amapola
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		virtual void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) override;
		virtual void Bind() const override;
		virtual void Unbind() const override;

	private:
		unsigned int m_Renderer_ID;
	};
}
