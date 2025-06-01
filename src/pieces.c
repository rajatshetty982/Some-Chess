
// #include <SDL2/SDL.h>
// #include <SDL2/SDL_render.h>
// #include <stdio.h>
#include "pieces.h"
#include "game.h"

// init the pieces
int init_pieces(Gamestate* state) {
	// This function initializes the pieces and their textures.
	// It can load images, set up piece data, etc.


	// get the fen string and put match it with png of pieces
	if (state == NULL || state->fen == NULL) {
		printf("Invalid game state or FEN string.\n");
		return -1;
	}

	int error = fen_parser(state->fen);
	if (error < 0) {
		printf("Error parsing FEN string: %d\n", error);
		return -1;
	}

	
	printf("Pieces initialized.\n");
	
	return 0;
}


int fen_parser(const char* fen) {
	// This function parses the FEN string and initializes the pieces accordingly.

	if (fen == NULL) {
		return -1; // Error: FEN string is NULL
	}

	


	return 0; 
}
