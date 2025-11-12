set(TASK_NAME tasktracker)
set(TASK_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(TASK_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

file(GLOB_RECURSE TASK_SRC CONFIGURE_DEPENDS ${TASK_SRC_DIR}/*.cpp)
file(GLOB_RECURSE TASK_INC CONFIGURE_DEPENDS ${TASK_INC_DIR}/*.hpp)

source_group(TREE ${TASK_SRC_DIR} PREFIX "Source Files" FILES ${TASK_SRC})
source_group(TREE ${TASK_INC_DIR} PREFIX "Header Files" FILES ${TASK_INC})

add_executable(${TASK_NAME} ${TASK_SRC} ${TASK_INC})

target_include_directories(${TASK_NAME} PRIVATE ${TASK_INC_DIR})
target_link_libraries(${TASK_NAME} PRIVATE shared)

add_custom_command(TARGET ${TASK_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:${TASK_NAME}>
        ${CMAKE_SOURCE_DIR}/installer/src/tasktracker.exe
)
