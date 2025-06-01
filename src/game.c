#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include "game.h"
#include "render.h"


void init_sdl() {
    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        printf("sdl init failed, Error -> %s", SDL_GetError());
        exit(-1);
    }
    atexit(SDL_Quit);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image init failed: %s\n", IMG_GetError());
        exit(1);
    }
    atexit(IMG_Quit);
}

Gamestate init_game(){
    // return all the position and data
    Gamestate gamestate;

    init_fen(&gamestate);


    printf("Game initialized with FEN: %s\n", gamestate.fen);

    return gamestate;
}

void update_game(Gamestate* state){
	// Update game logic here
	// This function can be used to handle game state updates, such as piece movements, checks, etc.
	
	return;
}

void init_fen(Gamestate* state) {

    state->fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

    state->moves = NULL; // Initialize moves array to NULL
}