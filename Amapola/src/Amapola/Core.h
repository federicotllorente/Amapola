#pragma once

#ifdef AMPL_PLATFORM_WINDOWS
	#ifdef AMPL_BUILD_DLL
		#define AMAPOLA_API __declspec(dllexport)
	#else
		#define AMAPOLA_API __declspec(dllimport)
	#endif
#else
	#error Amapola only supports Windows
#endif

#ifdef AMPL_ENABLE_ASSERTS
	#define AMPL_ASSERT(x, ...) { if(!(x)) { AMPL_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define AMPL_CORE_ASSERT(x, ...) { if(!(x)) { AMPL_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define AMPL_ASSERT(x, ...)
	#define AMPL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
