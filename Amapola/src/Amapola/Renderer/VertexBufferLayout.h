#pragma once

#include "Amapola/Core.h"
#include "Amapola/Log.h"

#include <vector>
#include <glad/glad.h>

namespace Amapola
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned int isNormalized;

		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT:
				return sizeof(GLfloat);
			case GL_UNSIGNED_INT:
				return sizeof(GLuint);
			case GL_UNSIGNED_BYTE:
				return sizeof(GLbyte);
			}

			AMPL_CORE_ASSERT(type);
			AMPL_CORE_ERROR("Vertex buffer element type not supported: {0}", type);
			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout()
			: m_Stride(0) {}

		void Push(unsigned int type, unsigned int count);
		inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
		inline unsigned int GetStride() const { return m_Stride; }

	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;
	};
}
