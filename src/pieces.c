
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
// #include <stdio.h>
#include "pieces.h"
#include "game.h"
#include "render.h"


void load_piece_textures(SDL_Renderer* renderer, PieceTextures* textures) {
	const char* pieces_file_prefix = "./wad/pieces/";
    textures->white[0] = IMG_LoadTexture(renderer,give_file_path_with_prefix(pieces_file_prefix, "wP")); // Pawn

    textures->white[1] = IMG_LoadTexture(renderer,give_file_path_with_prefix(pieces_file_prefix, "wN")); // Knight 
    textures->white[2] = IMG_LoadTexture(renderer, give_file_path_with_prefix(pieces_file_prefix, "wB")); // Bishop 
    textures->white[3] = IMG_LoadTexture(renderer, give_file_path_with_prefix(pieces_file_prefix, "wR")); // Rook 
    textures->white[4] = IMG_LoadTexture(renderer, give_file_path_with_prefix(pieces_file_prefix, "wQ")); // Queen 
    textures->white[5] = IMG_LoadTexture(renderer, give_file_path_with_prefix(pieces_file_prefix, "wK")); // King 

    textures->black[0] = IMG_LoadTexture(renderer, give_file_path_with_prefix(pieces_file_prefix, "bP"));
    textures->black[1] = IMG_LoadTexture(renderer,  give_file_path_with_prefix(pieces_file_prefix, "bN"));
    textures->black[2] = IMG_LoadTexture(renderer, give_file_path_with_prefix(pieces_file_prefix, "bB"));
    textures->black[3] = IMG_LoadTexture(renderer,  give_file_path_with_prefix(pieces_file_prefix, "bR"));
    textures->black[4] = IMG_LoadTexture(renderer,  give_file_path_with_prefix(pieces_file_prefix, "bQ"));
    textures->black[5] = IMG_LoadTexture(renderer,  give_file_path_with_prefix(pieces_file_prefix, "bK"));
  
}


char* give_file_path_with_prefix(const char* prefix, const char piece_char[]) {
	static char file_path[256];
	snprintf(file_path, sizeof(file_path), "%s%s.png", prefix, piece_char);
	return file_path;
}