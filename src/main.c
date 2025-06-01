#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "game.h"
#include "move.h"
#include "render.h"
#include "pieces.h"

int main()
{

    init_sdl();
    Gamestate state = init_game();
    SDL_Window *window = init_window();
    SDL_Renderer *renderer = init_renderer(window);
    int error = init_pieces(&state);
    if (error < 0)
    {
        cleanup_sdl(window, renderer);
        return -1;
    }

    int running = 1;

    while (running)
    {
        handle_input(&state, &running);
        update_game(&state);
        render_game(renderer, &state);
        SDL_Delay(16); // ~60 FPS
    }

    cleanup_sdl(window, renderer);

    return 0;
}
