add_executable(
  example_app
  example_app.c
)

target_link_libraries(
  example_app
  example
)

target_link_libraries(
  example_app
  ${SDL2_LIBRARIES}
)
