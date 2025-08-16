#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include "../include/game.h"
#include "../include/pieces.h"
#include "../include/constants.h"
#include "../include/models.h"


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

void init_game(Gamestate *state){

    init_fen(state);

    state->turn = WHITE;

    printf("Game initialized with FEN: %s\n", state->fen);

    return;
}

void update_game(Gamestate* state){
    // checks the fen and loads the 
    // will rewrite the fen string 
	
	return;
}

void init_fen(Gamestate *state) {

    state->fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    // state->fen = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq - 1 2";

    // state->moves = NULL; // Initialize moves array to NULL
}


// void load_fen_to_piece_positions_map(Gamestate* state ){
//     char* fen = state->fen;
// }

