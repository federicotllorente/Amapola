#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Amapola
{
	class AMAPOLA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

/* Core log macros */
#define AMPL_CORE_TRACE(...) ::Amapola::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AMPL_CORE_INFO(...) ::Amapola::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AMPL_CORE_WARN(...) ::Amapola::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AMPL_CORE_ERROR(...) ::Amapola::Log::GetCoreLogger()->error(__VA_ARGS__)

/* Client log macros */
#define AMPL_TRACE(...) ::Amapola::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AMPL_INFO(...) ::Amapola::Log::GetClientLogger()->info(__VA_ARGS__)
#define AMPL_WARN(...) ::Amapola::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AMPL_ERROR(...) ::Amapola::Log::GetClientLogger()->error(__VA_ARGS__)
