#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "../include/render.h"
#include "../include/pieces.h"
#include "../include/game.h"

#include "../include/constants.h"
#include "../include/models.h"


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


void render_game(SDL_Renderer* renderer, Gamestate* state, PieceTextures *textures){

	/*
    ** Render the board here, hardcoded the colour for now
    ** Later we will make a dial to adjust the colours. Hopefully, 
    ** Depends if I find something even more interesting then this
    */ 
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
	render_pieces(renderer, textures, state);
	// Render pieces here using state data

	SDL_RenderPresent(renderer);

	return;
}



void render_pieces(SDL_Renderer* renderer, PieceTextures* textures, Gamestate *state) {

    // get the pieces from the  board[][] and render them

	int rank, file;
    for ( rank = 0; rank < 8; rank++){
        for (int file = 0; file < 8; file++) {
            int piece = state->board[rank][file];
            if (piece != NONE) {
               SDL_Texture* tex = NULL;
                int type = piece & 7;  // Get the piece type (PAWN, KNIGHT, etc.)
                int color = piece & 24; // Get the color (WHITE or BLACK)

                if (color == WHITE) {
                    tex = textures->white[type - 1]; // -1 because your enum starts at 1
                } else {
                    tex = textures->black[type - 1];
                }

                SDL_Rect dest = { file * TILE_SIZE, rank * TILE_SIZE, TILE_SIZE, TILE_SIZE };
                SDL_RenderCopy(renderer, tex, NULL, &dest);
            }
        }
    }
}

void print_board(int pos[8][8]) {
	for (int rank = 0; rank < 8; rank++) {
		for (int file = 0; file < 8; file++) {
			printf("%2d \t", pos[rank][file]);
		}
		printf("\n");
	}
}


SDL_Window* init_window(){

	SDL_Window* window = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) == -1){
		printf("sdl init failed, Error -> %s", SDL_GetError());
		exit(-1);
	}
	atexit(SDL_Quit);


	window = SDL_CreateWindow("Chess By Rajat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if ( window == NULL ) {
		fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
	  SDL_GetError());
		exit(1);
	}

	return window;
}


void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
