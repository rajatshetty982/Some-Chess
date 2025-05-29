#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>


typedef struct {


}Gamestate;

Gamestate init_game();
SDL_Window* init_window();
void init_sdl();
void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer);

// update_game(Gamestate* state);
// cleanup(Gamestate* state);




#endif
