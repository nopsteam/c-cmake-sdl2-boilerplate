# Include Unity test framework.
add_subdirectory(unity)

# Configure an example test binary.
add_executable(
    example_test
    example_test.c
)

target_link_libraries(
    example_test
    unity
    example
)

target_include_directories(
    example_test PUBLIC
    ${PROJECT_SOURCE_DIR}/test/unity
)

set_target_properties(
    example_test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_PATH}"
)

add_test(example_test "${TEST_OUTPUT_PATH}/example_test")
