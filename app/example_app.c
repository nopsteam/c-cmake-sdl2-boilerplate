#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "example.h"

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
      "SDL2Test",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      640,
      480,
      0
      );

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

  // render four pixels
  SDL_RenderDrawPoint(renderer, 320, 240);
  SDL_RenderDrawPoint(renderer, 320+1, 240+1);
  SDL_RenderDrawPoint(renderer, 320, 240+1);
  SDL_RenderDrawPoint(renderer, 320+1, 240);

  // triggers the double buffers for multiple rendering
  SDL_RenderPresent(renderer);

  SDL_Delay(3000);

  SDL_DestroyWindow(window);
  SDL_Quit();

  printf("Hello, example!\n");

  example_t *example = example_new_with_cstr("test_key", "test_value");
  example_print_cstr(example);
  example_free(example);

  return EXIT_SUCCESS;
}
