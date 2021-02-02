add_executable(
  example_app
  example_app.c
)

target_link_libraries(
  example_app
  example
)

add_dependencies(
  example_app
  resources
)

target_link_libraries(
  example_app
  ${SDL2_LIBRARIES}
  ${SDL2_IMAGE_LIBRARIES}
)
