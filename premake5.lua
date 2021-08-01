workspace "AEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AEngine"
    location "AEngine"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AE_PLATFORM_WINDOWS",
            "AE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/TestBox")
        }

        filter "configurations:Debug"
            defines "AE_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "AE_Release"
            optimize "On"

        filter "configurations:Dist"
            defines "AE_DIST"
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
            symbols "On"

        filter "configurations:Release"
            defines "AE_Release"
            optimize "On"

        filter "configurations:Dist"
            defines "AE_DIST"
            optimize "On"