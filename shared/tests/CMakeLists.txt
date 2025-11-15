add_executable(shared_tests
  shared_test.cpp
)

target_link_libraries(shared_tests
  PRIVATE
    shared
    GTest::gtest_main
)

set_target_properties(shared_tests PROPERTIES
  FOLDER "Tests"
)

include(GoogleTest)
gtest_discover_tests(shared_tests)
