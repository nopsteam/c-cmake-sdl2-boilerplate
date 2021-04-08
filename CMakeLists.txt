# Setup
cmake_minimum_required(VERSION 3.17)
project(ExampleSDL2C)
include(CTest)
include(FetchContent)
set(FETCHCONTENT_QUIET 0)

# Cmake module directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/build/cmake/")

# Download / Include Unity Test Runner
FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        master)

FetchContent_Declare(
  sdl2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL
  GIT_TAG release-2.0.14)

FetchContent_MakeAvailable(unity sdl2)

FetchContent_Declare(
  sdl2_image
  GIT_REPOSITORY https://github.com/eliasdaler/SDL_image
  GIT_TAG main)

FetchContent_GetProperties(sdl2_image)
if(NOT sdl2_image_POPULATED)
  add_library(SDL2::SDL2 ALIAS SDL2)
  FetchContent_Populate(sdl2_image)
  add_subdirectory(${sdl2_image_SOURCE_DIR} ${sdl2_image_BINARY_DIR})
endif()

# Output directory structure configuration.
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/src")
set(TEST_OUTPUT_PATH "${EXECUTABLE_OUTPUT_PATH}/test")

# Add symbolic link to resources folder in build
add_custom_target(resources)
FILE(TO_NATIVE_PATH "${PROJECT_SOURCE_DIR}/resources" source)
FILE(TO_NATIVE_PATH "${PROJECT_BINARY_DIR}/resources" destination)
IF (WIN32)
  add_custom_command(
    TARGET resources POST_BUILD
    COMMAND mklink /D ${destination} ${source}
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}"
    )
ELSE()
  add_custom_command(
    TARGET resources POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}"
    )
ENDIF()

# Generates a compile_commands.json file containing the exact compiler calls
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
FILE(TO_NATIVE_PATH "${PROJECT_BINARY_DIR}/compile_commands.json" sourceJson)
FILE(TO_NATIVE_PATH "${PROJECT_SOURCE_DIR}/build/compile_commands.json" destinationJson)
add_custom_command(TARGET resources POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy 
  ${sourceJson} ${destinationJson}
  COMMENT "Copying compile_commands.json to build directory")

# Project-wide include directory configuration.
include_directories("${PROJECT_SOURCE_DIR}/src")

# Project library source lives in src/.
add_subdirectory(src)

# Project apps that may link to project libraries live in app/.
add_subdirectory(app)

# CTest sets BUILD_TESTING option to ON by default.
# Test-related configuration goes here.
if (BUILD_TESTING)
  enable_testing()
  add_subdirectory(test)

  # COVERAGE
  if (${CMAKE_BUILD_TYPE} MATCHES "Coverage")
    if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
      add_compile_options(--coverage)
      link_libraries(gcov)
    else ()
      message(FATAL_ERROR "Only GCC is supported for coverage")
    endif ()
  endif ()

  add_custom_target(coverage)
  add_custom_command(
    TARGET coverage
    COMMAND make test
    COMMAND lcov --capture --directory "${PROJECT_BINARY_DIR}/src/CMakeFiles"
    --output-file "${PROJECT_BINARY_DIR}/coverage.info" --rc lcov_branch_coverage=1 --rc lcov_excl_br_line='assert'
    COMMAND lcov --remove "${PROJECT_BINARY_DIR}/coverage.info" '/usr/*' '*test*'
    --output-file "${PROJECT_BINARY_DIR}/coverage.info" --rc lcov_branch_coverage=1 --rc lcov_excl_br_line='assert'
    COMMAND lcov --list "${PROJECT_BINARY_DIR}/coverage.info" --rc lcov_branch_coverage=1 --rc lcov_excl_br_line='assert'
    )
endif()
