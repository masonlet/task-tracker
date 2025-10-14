set(TASK_NAME TaskTracker)
set(TASK_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TASK_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

file(GLOB_RECURSE TASK_SRC CONFIGURE_DEPENDS ${TASK_SRC_DIR}/*.cpp)
source_group(TREE ${TASK_SRC_DIR} PREFIX "Source Files" FILES ${TASK_SRC})

add_executable(${TASK_NAME} ${TASK_SRC})

target_include_directories(${TASK_NAME} PRIVATE ${TASK_INC_DIR})
target_link_libraries(${TASK_NAME} PRIVATE Shared)

add_custom_command(TARGET ${TASK_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:${TASK_NAME}>
        ${CMAKE_SOURCE_DIR}/installer/src/tasktracker.exe
)
