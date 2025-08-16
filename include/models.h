#ifndef MODELS_H
#define MODELS_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "constants.h"


typedef struct MOVE{
    int from_square;
    int to_square;
    int promotion_piece; // e.g., PAWN, KNIGHT, etc.
    int flags;           // A bitmask for special move types like castling
} move_t;

typedef struct PIECE_POSITIONS_MAP{
    int white_pawns[8];
    int black_pawns[8];
    // fill this for the rest of the pieces later, to make move genration read from this vec, to make it fast
} piece_positions_map_t;

typedef enum PieceType
{
	NONE,
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
} piece_t;

typedef enum PieceColour
{
	WHITE = 8,
	BLACK = 16
} piece_colour_t;

typedef struct {
    SDL_Texture* white[PIECE_TYPE_COUNT];
    SDL_Texture* black[PIECE_TYPE_COUNT];
} PieceTextures;

typedef struct
{
	char *fen; // FEN string just for saving/loading
	int board[8][8];
	piece_colour_t turn;				  //  is an enum of 8 and 16
	int selected_square;			  // The index of the selected square (or -1 if none)
	int legal_moves[MAX_LEGAL_MOVES]; // An array of indices for legal moves
	int num_legal_moves;			  // The number of legal moves in the array
	int castling_rights;			  // Bitmask for castling rights
	int en_passant_square;			  // The en passant square index
	int halfmove_clock;				  // Halfmove clock for the 50-move rule // not gonna care about this for now
	int fullmove_number;			  // The fullmove number

	// For move history and undo/redo functionality
	// This will be in a linked list.
	move_t history[MAX_HISTORY_MOVES];
    int history_count;
} Gamestate;



#endif