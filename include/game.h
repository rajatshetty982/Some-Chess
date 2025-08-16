#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "models.h"

void init_game(Gamestate *state);
void init_sdl();
void update_game(Gamestate* state);
void init_fen(Gamestate *state);

#endif
