cmake_minimum_required(VERSION 3.6)

# set(CMAKE_TOOLCHAIN_FILE toolchain/TC_Windows.cmake)
project(AEngine VERSION 0.1.0 LANGUAGES C CXX)

# Dependecies: ########################################################
find_package(Git QUIET)

# https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)

    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/AEngine/vendor/glfw/CMakeLists.txt")
    message(FATAL_ERROR "GLFW CMakeLists file not found.")
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/AEngine/vendor/imgui/CMakeLists.txt")
    message(FATAL_ERROR "imgui CMakeLists file not found.")
endif()

# ############################################################################
# Define AE_SOURCES to be a list of all the source files for my game
file(GLOB_RECURSE AE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/AEngine/src/*.cpp")

# include_directories(${PROJECT_SOURCE_DIR}/AEngine)
add_library(AEngine STATIC ${AE_SOURCES})
target_include_directories(AEngine PUBLIC AEngine/src/)
target_precompile_headers(AEngine PUBLIC AEngine/src/aepch.h)

add_subdirectory(AEngine/vendor/GLFW)
include_directories(AEngine/vendor/GLFW/include)

add_subdirectory(AEngine/vendor/IMGUI)
include_directories(AEngine/vendor/IMGUI)
include_directories(AEngine/vendor/IMGUI/backends)

add_subdirectory(AEngine/vendor/GLAD)
include_directories(AEngine/vendor/GLAD/include/)

# add_subdirectory(AEngine/vendor/spdlog)
include_directories(AEngine/vendor/spdlog/include/)

add_subdirectory(AEngine/vendor/GLM)
include_directories(AEngine/vendor/GLM)

# since we use glad we have to stop glfw from loading system gl.
add_compile_definitions(GLFW_INCLUDE_NONE)
add_compile_definitions(AE_PLATFORM_WINDOWS)
target_link_libraries(AEngine PUBLIC GLAD)
target_link_libraries(AEngine PUBLIC IMGUI)
target_link_libraries(AEngine PUBLIC GLFW)
target_link_libraries(AEngine PUBLIC GLM)

# target_link_libraries(AEngine PUBLIC spdlog)

# target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_BUILD_WIN32)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(AEngine PUBLIC "/ZI")
    target_link_options(AEngine PUBLIC "/INCREMENTAL")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

    # set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

file(GLOB_RECURSE TEST_SOURCES "TestBox/src/*.cpp")

add_executable(TEST ${TEST_SOURCES})
target_include_directories(TEST PUBLIC TestBox/src)
target_link_libraries(TEST PUBLIC AEngine)

# target_compile_definitions(glfw PUBLIC GLFW_BUILD_WIN32)
# if(NOT WIN32)
# target_link_libraries(ecocar-telemetry-interface PUBLIC SERIAL_COM)
# endif()

# target_link_libraries(ecocar-telemetry-interface PUBLIC X11)

# ok cmake is officially bad ass.