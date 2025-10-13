cmake_minimum_required(VERSION 3.10)

project(TaskTrackerInstaller)

set(CMAKE_CXX_STANDARD 17)

set(TASK_NAME TaskTracker)
set(INSTALL_NAME Installer)

set(TASK_SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(TASK_INC_DIR "${CMAKE_SOURCE_DIR}/inc")

file(GLOB_RECURSE TASK_SRC CONFIGURE_DEPENDS ${TASK_SRC_DIR}/tasktracker.cpp)
source_group(TREE ${TASK_SRC_DIR} PREFIX "Source Files" FILES ${TASK_SRC})

add_executable(${TASK_NAME} ${TASK_SRC})
target_include_directories(${TASK_NAME} PRIVATE ${TASK_INC_DIR})

file(GLOB_RECURSE INSTALL_SRC CONFIGURE_DEPENDS 
  ${TASK_SRC_DIR}/installer.cpp 
  ${TASK_SRC_DIR}/tasktracker.rc
)
source_group(TREE ${TASK_SRC_DIR} PREFIX "Source Files" FILES ${INSTALL_SRC})

add_executable(${INSTALL_NAME} ${INSTALL_SRC})
target_include_directories(${INSTALL_NAME} PRIVATE ${TASK_INC_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

SET_TARGET_PROPERTIES(${INSTALL_NAME} PROPERTIES 
  LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\" /SUBSYSTEM:CONSOLE"
)

add_dependencies(${INSTALL_NAME} ${TASK_NAME})

add_custom_command(TARGET ${TASK_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:${TASK_NAME}>
        ${TASK_SRC_DIR}/tasktracker.exe
)
