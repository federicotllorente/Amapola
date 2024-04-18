workspace "Amapola"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to the root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Amapola/vendor/GLFW/include"

include "Amapola/vendor/GLFW"

project "Amapola"
	location "Amapola"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "amplpch.h"
	pchsource "Amapola/src/amplpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AMPL_PLATFORM_WINDOWS",
			"AMPL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AMPL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AMPL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AMPL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Amapola/vendor/spdlog/include",
		"Amapola/src"
	}

	links
	{
		"Amapola"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AMPL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AMPL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AMPL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AMPL_DIST"
		optimize "On"
