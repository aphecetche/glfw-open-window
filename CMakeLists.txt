cmake_minimum_required(VERSION 3.14)

project(testglfw LANGUAGES C)

find_package(GLFW
             NAMES
             GLFW3
             CONFIG
             REQUIRED)

add_executable(main main.c)

target_link_libraries(main PRIVATE glfw)

install(TARGETS main RUNTIME)
