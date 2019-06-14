cmake_minimum_required(VERSION 3.14)

project(testglfw LANGUAGES C)

find_package(GLFW
             NAMES
             glfw3
             CONFIG
             REQUIRED)

if(APPLE)
  set(basePoint @loader_path)
else()
  set(basePoint $ORIGIN)
endif()

get_property(loc TARGET glfw PROPERTY LOCATION)
get_filename_component(dir ${loc} DIRECTORY)

set(CMAKE_INSTALL_RPATH ${dir})

add_executable(main main.c)

target_link_libraries(main PRIVATE glfw)

install(TARGETS main RUNTIME)
