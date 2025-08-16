#include "../include/utils.h"

int is_valid_first_click(Gamestate *state, int file, int rank) {

	int piece = state->board[rank][file];
	if (piece == NONE)
	{
		return 0;
	}	
		// mask first 3 bits and see which bit is 1 in 3rd and 4th place
		int piece_colour = piece & (WHITE | BLACK);

		if (piece_colour == state->turn) { // 
			return 1;
		}
		return 0;
}