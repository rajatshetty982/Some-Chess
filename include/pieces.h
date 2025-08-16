#ifndef PIECES_H
#define PIECES_H

#include <SDL2/SDL.h>
#include "models.h"

void load_piece_textures(SDL_Renderer* renderer, PieceTextures* textures);
void free_piece_textures(PieceTextures *textures);

#endif