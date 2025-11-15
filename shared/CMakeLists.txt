set(SHARED_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SHARED_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

file(GLOB_RECURSE SHARED_INC CONFIGURE_DEPENDS
  ${SHARED_INC_DIR}/*.h
  ${SHARED_INC_DIR}/*.hpp
)
file(GLOB_RECURSE SHARED_SRC CONFIGURE_DEPENDS
  ${SHARED_SRC_DIR}/*.c
  ${SHARED_SRC_DIR}/*.cpp
)

source_group(TREE ${SHARED_INC_DIR} PREFIX "Header Files" FILES ${SHARED_INC})
source_group(TREE ${SHARED_SRC_DIR} PREFIX "Source Files" FILES ${SHARED_SRC})

add_library(shared STATIC ${SHARED_INC} ${SHARED_SRC})
target_include_directories(shared PUBLIC ${SHARED_INC_DIR})

option(BUILD_TESTS "Build unit tests" OFF)

if(BUILD_TESTS)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  enable_testing()
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
  )

  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  set_target_properties(gtest gtest_main gmock gmock_main PROPERTIES
    FOLDER "Tests/GoogleTest"
  )

  add_subdirectory(tests)
endif()
