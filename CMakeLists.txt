cmake_minimum_required(VERSION 3.10)
project(tasktracker_installer)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(shared)
add_subdirectory(tasktracker)
add_subdirectory(installer)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT installer)
