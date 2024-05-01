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
IncludeDir["spdlog"] = "Amapola/vendor/spdlog/include"
IncludeDir["GLFW"] = "Amapola/vendor/GLFW/include"
IncludeDir["Glad"] = "Amapola/vendor/Glad/include"
IncludeDir["ImGui"] = "Amapola/vendor/imgui"
IncludeDir["glm"] = "Amapola/vendor/glm"

include "Amapola/vendor/GLFW"
include "Amapola/vendor/Glad"
include "Amapola/vendor/imgui"

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
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"AMPL_PLATFORM_WINDOWS",
			"AMPL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
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
		"Amapola/vendor/Glad/include",
		"Amapola/vendor/imgui",
		"Amapola/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Amapola"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
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
