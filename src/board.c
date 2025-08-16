#include "../include/game.h"
#include "../include/pieces.h"

void init_piece_positions(Gamestate* state) {
	char* fen = state->fen;
	for (int i = 0;i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			state->board[i][j] = NONE; // Initialize all positions to 0
		}
	}

	int rank = 0, file = 0;
	for (int i = 0; fen[i] && fen[i] != ' '; i++) {
		char f = fen[i];

		if (f == '/') {
			rank++;
			file = 0;
		} else if (f >= '1' && f <= '8'){
			file += f - '0';
		} else {
			int piece = NONE;
			switch(f){
				case 'P': piece  = WHITE | PAWN; break;
				case 'N': piece  = WHITE | KNIGHT; break;
				case 'B': piece  = WHITE | BISHOP; break;
				case 'R': piece  = WHITE | ROOK ; break;
				case 'Q': piece  = WHITE | QUEEN; break;
				case 'K': piece  = WHITE | KING ; break;
				case 'p': piece  = BLACK | PAWN ; break;
				case 'n': piece  = BLACK | KNIGHT; break;
				case 'b': piece  = BLACK | BISHOP; break;
				case 'r': piece  = BLACK | ROOK ; break;
				case 'q': piece  = BLACK | QUEEN; break;
				case 'k': piece  = BLACK | KING ; break;
			}
			state->board[rank][file] = piece;
			file++;
		}
	}
	return;
}


