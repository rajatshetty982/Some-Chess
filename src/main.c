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
    PieceTextures textures;
    load_piece_textures(renderer, &textures);

    int running = 1;

    while (running)
    {

        render_game(renderer, &state, &textures);
       
        handle_input(&state, &running);
        update_game(&state);
        SDL_Delay(16); // ~60 FPS
    }

    cleanup_sdl(window, renderer);

    return 0;
}
