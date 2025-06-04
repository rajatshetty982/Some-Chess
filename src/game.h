#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

typedef int move_t[]; // Array of integers representing a move, e.g., needs a buffer size
// This should not be an int, it should maybe should the algebraic notation of the move, or a struct with more information



typedef enum {
	WHITE_SIDE = 0,
	BLACK_SIDE = 1
} Side;


#define PIECE_TYPE_COUNT 6 // 6 types of pieces for each color

typedef struct {
    SDL_Texture* white[PIECE_TYPE_COUNT];
    SDL_Texture* black[PIECE_TYPE_COUNT];
} PieceTextures;




typedef struct {
	char* fen; // FEN string representing the current game state
	move_t* moves; // Array of moves made in the game
	int move_count; // Number of moves made. Can be used to state the maximum number of moves
	int current_move; // Index of the current move being played
	Side turn; // Current player's turn
	// PieceTextures textures;

}Gamestate;

Gamestate init_game();
SDL_Window* init_window();
void init_sdl();
void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer);

void update_game(Gamestate* state);




#endif
