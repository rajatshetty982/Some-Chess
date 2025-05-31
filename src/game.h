#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "board.h"

typedef int move_t[]; // Array of integers representing a move, e.g., needs a buffer size



typedef struct {
	char* fen; // FEN string representing the game state
	move_t* moves; // Array of moves made in the game
	int move_count; // Number of moves made
	int current_move; // Index of the current move being played
	Side turn; // Current player's turn

}Gamestate;

Gamestate init_game();
SDL_Window* init_window();
void init_sdl();
void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer);

void update_game(Gamestate* state);




#endif
