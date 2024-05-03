#pragma once

// TODO Merge files with VertexBuffer into Buffer.h
namespace Amapola
{
	class IndexBuffer
	{
	public:
		~IndexBuffer();

		static IndexBuffer* Create(const unsigned int* data, unsigned int count);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned int GetCount() const = 0;
	};
}
