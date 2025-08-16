#ifndef RENDER_H
#define RENDER_H

#include "models.h"

SDL_Window* init_window();
SDL_Renderer* init_renderer(SDL_Window* window);
void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer);
void render_game(SDL_Renderer* renderer, Gamestate* state, PieceTextures *textures);
void print_board(int pos[8][8]); // This is a utility function, but fits here for debugging rendering


#endif
