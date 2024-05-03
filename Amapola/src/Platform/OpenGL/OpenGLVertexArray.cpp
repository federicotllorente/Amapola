#include "amplpch.h"
#include "OpenGLVertexArray.h"

namespace Amapola
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &m_Renderer_ID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_Renderer_ID);
	}

	void OpenGLVertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
	{
		Bind();
		vb.Bind();

		const auto& elements = layout.GetElements();
		unsigned int offset = 0;

		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];

			glEnableVertexAttribArray(i);
			glVertexAttribPointer(
				i,
				element.count,
				element.type,
				element.isNormalized,
				layout.GetStride(),
				(const void*)offset
			);

			offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
		}
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_Renderer_ID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}
