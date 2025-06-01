#ifndef PIECES_H
#define PIECES_H

#include "game.h"
// #include "render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

typedef enum {
	NONE = 0,
	PAWN = 1,
	KNIGHT = 2,
	BISHOP = 3,
	ROOK = 4,
	QUEEN = 5,
	KING = 6,
	WHITE = 8,
	BLACK = 16,
	WHITE_PAWN = PAWN | WHITE,
	WHITE_KNIGHT = KNIGHT | WHITE,
	WHITE_BISHOP = BISHOP | WHITE,
	WHITE_ROOK = ROOK | WHITE,
	WHITE_QUEEN = QUEEN | WHITE,
	WHITE_KING = KING | WHITE,
	BLACK_PAWN = PAWN | BLACK,
	BLACK_KNIGHT = KNIGHT | BLACK,
	BLACK_BISHOP = BISHOP | BLACK,
	BLACK_ROOK = ROOK | BLACK,
	BLACK_QUEEN = QUEEN | BLACK,
	BLACK_KING = KING | BLACK
} Pieces;

int init_pieces( Gamestate* state);

void load_textures(SDL_Renderer* renderer, Gamestate* state);

#endif