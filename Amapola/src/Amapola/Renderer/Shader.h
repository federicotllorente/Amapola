#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

namespace Amapola
{
	class Shader
	{
	public:
		virtual ~Shader();

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		
		// Set uniforms
		virtual void SetUniform1i(const std::string& name, int value) = 0;
		virtual void SetUniform1f(const std::string& name, float value) = 0;
		virtual void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) = 0;
		virtual void SetUniformMat4f(const std::string& name, const glm::mat4& matrix) = 0;
	};
}
