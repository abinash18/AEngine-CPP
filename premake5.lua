workspace "AEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
	
	startproject "TestBox"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
    IncludeDir = {}
    IncludeDir["GLFW"] = "AEngine/vendor/GLFW/include"
    IncludeDir["GLAD"] = "AEngine/vendor/GLAD/include"
    
    include "AEngine/vendor/GLFW"
    include "AEngine/vendor/GLAD"

project "AEngine"
    location "AEngine"
    kind "SharedLib"
    language "C++"

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
        "%{IncludeDir.GLAD}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AE_PLATFORM_WINDOWS",
            "AE_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/TestBox")
        }

        filter "configurations:Debug"
            defines "AE_DEBUG"
            buildoptions "/MDd"
            symbols "On"

        filter "configurations:Release"
            defines "AE_RELEASE"
            buildoptions "/MD"
            optimize "On"

        filter "configurations:Dist"
            defines "AE_DIST"
            buildoptions "/MD"
            optimize "On"

project "TestBox"
    location "TestBox"
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
        "AEngine/vendor/spdlog/include",
        "AEngine/src"
    }

    links
    {
        "AEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AE_PLATFORM_WINDOWS"
        }

        filter "configurations:Debug"
            defines "AE_DEBUG"
            buildoptions "/MDd"
            symbols "On"

        filter "configurations:Release"
            defines "AE_Release"
            buildoptions "/MD"
            optimize "On"

        filter "configurations:Dist"
            defines "AE_DIST"
            buildoptions "/MD"
            optimize "On"