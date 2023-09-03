cmake_minimum_required(VERSION 3.6)
add_library(GLAD STATIC
    src/glad.c
    include/glad/glad.h
    include/KHR/khrplatform.h
)
target_include_directories(GLAD PUBLIC include)