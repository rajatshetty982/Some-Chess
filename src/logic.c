#include "../include/logic.h"

void generate_legal_moves(Gamestate *state)
{
}

int is_legal_move(Gamestate *state, int clicked_square_index)
{
}

void make_move(Gamestate *state, int current_square, int new_square)
{
	// if king moved turn castle rights flag to false
	// if en passant, set or clearn the square
	// increment halfmove clock
	// increment fullmove number if this was black's moved
	// check if move was castle and handle it
	// if en passant move it that way
	// if pawn and square is +7 rank from start -> promote (show option on a window)

	// state->board[]
	int curr_rank = new_square / 8;
	int curr_file = new_square % 8;

	int prev_rank = current_square / 8;
	int prev_file = current_square % 8;
	state->board[curr_rank][curr_file] = state->board[prev_rank][prev_file];
	state->board[prev_rank][prev_file] = 0;
	state->turn = state->turn ^ (WHITE | BLACK);
}