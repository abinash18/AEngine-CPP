workspace "AEngine"
    architecture "x64"

    startproject "TestBox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
    IncludeDir = {}
    IncludeDir["GLFW"] = "AEngine/vendor/GLFW/include"
    IncludeDir["GLAD"] = "AEngine/vendor/GLAD/include"
    IncludeDir["IMGUI"] = "AEngine/vendor/IMGUI"
    group "Dependencies"
        include "AEngine/vendor/GLFW"
        include "AEngine/vendor/GLAD"
        include "AEngine/vendor/IMGUI"
    group ""

project "AEngine"
    location "AEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "aepch.h"
    pchsource "AEngine/src/aepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.IMGUI}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "IMGUI",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
            "AE_PLATFORM_WINDOWS",
            "AE_DEBUG",
            "AE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/TestBox/\"")
        }

        filter "configurations:Debug"
            defines "AE_DEBUG"
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            defines "AE_RELEASE"
            runtime "Release"
            optimize "On"

        filter "configurations:Dist"
            defines "AE_DIST"
            runtime "Release"
            optimize "On"

project "TestBox"
    location "TestBox"
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
        "AEngine/vendor/spdlog/include",
        "AEngine/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.IMGUI}"
    }

    links
    {
        "AEngine",
        "GLFW",
        "GLAD",
        "IMGUI",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
            "AE_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "AE_DEBUG"
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            defines "AE_Release"
            runtime "Release"
            optimize "On"

        filter "configurations:Dist"
            defines "AE_DIST"
            runtime "Release"
            optimize "On"