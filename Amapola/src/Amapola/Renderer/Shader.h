#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

namespace Amapola
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;

		// Set uniforms
		void SetUniform1i(const std::string& name, int value);
		void SetUniform1f(const std::string& name, float value);
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

	private:
		uint32_t m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;

		int GetUniformLocation(const std::string& name);
	};
}