#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_image.h"
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

  // creates a surface to load an image into the main memory
  SDL_Surface* surface;

  // please provide a path for your image
  surface = IMG_Load("resources/ul.png");

  // loads image to our graphics hardware memory.
  SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);

  // clears main-memory
  SDL_FreeSurface(surface);

  // let us control our image position
  // so that we can move it with our keyboard.
  SDL_Rect dest;

  // connects our texture with dest to control position
  SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

  // adjust height and width of our image box.
  dest.w /= 2;
  dest.h /= 2;

  // sets initial x-position of object
  dest.x = (640 - dest.w) / 2;

  // sets initial y-position of object
  dest.y = (480 - dest.h) / 2;

  // renders the texture at dest coords
  SDL_RenderCopy(renderer, tex, NULL, &dest);

  // triggers the double buffers for multiple rendering
  SDL_RenderPresent(renderer);

  SDL_Delay(3000);

  // destroy texture, window and close
  SDL_DestroyTexture(tex); 
  SDL_DestroyWindow(window);
  SDL_Quit();

  // example of using libs
  printf("Hello, example!\n");
  example_t *example = example_new_with_cstr("test_key", "test_value");
  example_print_cstr(example);
  example_free(example);

  return EXIT_SUCCESS;
}
