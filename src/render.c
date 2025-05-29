#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "render.h"


SDL_Renderer* init_renderer(SDL_Window* window){

    SDL_Renderer* renderer = NULL;

   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    }


    return renderer;
}

void load_textures(SDL_Renderer* renderer, Gamestate* gamestate){

	// is this function for loading the pieces and stuff?

    return;
}


void render_game(SDL_Renderer* renderer, Gamestate* state){
	
	
	// const int TILE_SIZE = SCREEN_HEIGHT / 8;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	for (int row = 0; row < 8; row++) {
		for (int colm = 0; colm < 8; colm++) {
			SDL_Rect tile = {
				colm * TILE_SIZE,
				row * TILE_SIZE,
				TILE_SIZE,
				TILE_SIZE
			};

			if ((row + colm) % 2 == 0) {
				SDL_SetRenderDrawColor(renderer, (LIGHT_COLOR >> 16) & 0xFF, (LIGHT_COLOR >> 8) & 0xFF, LIGHT_COLOR & 0xFF, 255);
			} else {
				SDL_SetRenderDrawColor(renderer, (DARK_COLOR >> 16) & 0xFF, (DARK_COLOR >> 8) & 0xFF, DARK_COLOR & 0xFF, 255);
			}

			SDL_RenderFillRect(renderer, &tile);
		}
	}

	// Render pieces here using state data
	// ...

	SDL_RenderPresent(renderer);

	return;
}