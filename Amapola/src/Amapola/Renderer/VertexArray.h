#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Amapola
{
	class VertexArray
	{
	public:
		virtual ~VertexArray();

		static VertexArray* Create();

		virtual void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) = 0;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
	};
}
