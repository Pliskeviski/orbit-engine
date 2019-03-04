workspace "Orbit-Engine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Orbit-Engine/deps/GLFW/include"
IncludeDir["Glad"] = "Orbit-Engine/deps/Glad/include"
IncludeDir["ImGui"] = "Orbit-Engine/deps/imgui"
IncludeDir["glm"] = "Orbit-Engine/deps/glm"
IncludeDir["Converter"] = "Orbit-Engine/deps/meshconverter"


include "Orbit-Engine/deps/GLFW"
include "Orbit-Engine/deps/Glad"
include "Orbit-Engine/deps/imgui"
include "Orbit-Engine/deps/meshconverter"

project "Orbit-Engine"
	location "Orbit-Engine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "obtpch.h"
	pchsource "Orbit-Engine/src/obtpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/deps/glm/glm/**.hpp",
		"%{prj.name}/deps/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/deps/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Converter}",
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"Converter",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"OBT_PLATFORM_WINDOWS",
            "OBT_BUILD_DLL",
            "OBT_ENABLE_ASSERTS",
            "GLFW_INCLUDE_NONE",
            "_CRT_SECURE_NO_WARNINGS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "OBT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "OBT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "OBT_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Orbit-Engine/deps/spdlog/include",
		"Orbit-Engine/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Orbit-Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"OBT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OBT_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "OBT_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "OBT_DIST"
		runtime "Release"
		optimize "On"