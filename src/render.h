#ifndef RENDER_H
#define RENDER_H


//Screen dimension constants
#define SCREEN_WIDTH  800 
#define SCREEN_HEIGHT  800

//const int TILE_SIZE = SCREEN_HEIGHT/8;
#define TILE_SIZE  (SCREEN_HEIGHT/8)

// const int DARK_COLOR = 0xeeeed2; // rgb: 118,150,86
// const int LIGHT_COLOR = 0x769656; // 238,238,210
#define L_RGB_RED = 118
#define L_RGB_GREEN = 150
#define L_RGB_BLUE = 86

#define D_RGB_RED = 238
#define D_RGB_GREEN = 238
#define D_RGB_BLUE = 210

//#define TILE_SIZE 80
#define DARK_COLOR 0xEEEED2
#define LIGHT_COLOR 0x769656


SDL_Window* init_window();

void render_game(SDL_Renderer* renderer, Gamestate state, PieceTextures *textures);

SDL_Renderer* init_renderer(SDL_Window* window);


void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer);


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

#endif
