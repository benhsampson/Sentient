workspace "Sentient"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sentient"
	location "Sentient"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SNT_PLATFORM_WINDOWS",
			"SNT_BUILD_DLL"
		}
	
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SNT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SNT_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "SNT_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("int/" .. outputdir .. "/%{prj.name}")
	
	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Sentient/vendor/spdlog/include",
		"Sentient/src"
	}

	links {
		"Sentient"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SNT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SNT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SNT_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "SNT_DIST"
		symbols "On"
