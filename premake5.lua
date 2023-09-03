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
    IncludeDir["GLM"] = "AEngine/vendor/GLM"
    group "Dependencies"
        include "AEngine/vendor/GLFW"
        include "AEngine/vendor/GLAD"
        include "AEngine/vendor/IMGUI"
    group ""

project "AEngine"
    location "AEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "aepch.h"
    pchsource "AEngine/src/aepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }


    defines 
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLM}",
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
            symbols "on"

        filter "configurations:Release"
            defines "AE_RELEASE"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "AE_DIST"
            runtime "Release"
            optimize "on"

project "TestBox"
    location "TestBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

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
        "AEngine/vendor",
        "%{IncludeDir.GLM}"
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
        systemversion "latest"

        defines
        {
            "AE_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "AE_DEBUG"
            runtime "Debug"
            symbols "on"

        filter "configurations:Release"
            defines "AE_Release"
            runtime "Release"
            optimize "on"

        filter "configurations:Dist"
            defines "AE_DIST"
            runtime "Release"
            optimize "on"