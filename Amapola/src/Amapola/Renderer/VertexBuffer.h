#pragma once

// TODO Merge files with IndexBuffer into Buffer.h
namespace Amapola
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer();
		
		static VertexBuffer* Create(const void* data, unsigned int count);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		//virtual void Lock() const = 0;
		//virtual void Unlock() const = 0;
	};
}
