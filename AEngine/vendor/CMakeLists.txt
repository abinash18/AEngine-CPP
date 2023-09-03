cmake_minimum_required(VERSION 3.6)

add_library(
    IMGUI STATIC
    imconfig.h
    imgui.h
    imgui.cpp
    imgui_draw.cpp
    imgui_internal.h
    imgui_widgets.cpp
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
    imgui_demo.cpp
    imgui_tables.cpp
    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_glfw.h
    backends/imgui_impl_opengl3.cpp
    backends/imgui_impl_opengl3.h
)

target_include_directories(IMGUI PUBLIC backends ${CMAKE_CURRENT_SOURCE_DIR})