#pragma once

namespace Amapola
{
	class VertexBuffer
	{
	public:
		VertexBuffer(const void* data, unsigned int count);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
		//void Lock();
		//void Unlock();

	private:
		unsigned int m_RendererID;
	};
}
