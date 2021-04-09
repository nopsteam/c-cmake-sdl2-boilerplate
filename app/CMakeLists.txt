add_executable(
  sample_app
  sample_app.c
)

target_link_libraries(
  sample_app
  sample
)

add_dependencies(
  sample_app
  resources
)

target_link_libraries(
  sample_app
  SDL2
  SDL2_image
)
