#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
// #include "pieces.h"

typedef int move_t[]; // Array of integers representing a move, e.g., needs a buffer size
// This should not be an int, it should maybe should the algebraic notation of the move, or a struct with more information



typedef enum {
	WHITE_SIDE = 0,
	BLACK_SIDE = 1
} Side;



typedef struct {
	char* fen; // FEN string representing the current game state
	move_t* moves; // Array of moves made in the game
	int move_count; // Number of moves made. Can be used to state the maximum number of moves
	int current_move; // Index of the current move being played
	Side turn; // Current player's turn

}Gamestate;

Gamestate init_game();
SDL_Window* init_window();
void init_sdl();
void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer);

void update_game(Gamestate* state);




#endif
