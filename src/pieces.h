#ifndef PIECES_H
#define PIECES_H

#include "game.h"
// #include "render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

// #define PIECE_TYPE_COUNT 6 // 6 types of pieces for each color
// typedef struct {
//     SDL_Texture* white[PIECE_TYPE_COUNT];
//     SDL_Texture* black[PIECE_TYPE_COUNT];
// } PieceTextures;



void load_piece_textures(SDL_Renderer* renderer, PieceTextures* textures);
void render_pieces(SDL_Renderer* renderer, PieceTextures* textures, const char* fen);
char* give_file_path_with_prefix(const char* prefix, const char piece_char[]);

#endif