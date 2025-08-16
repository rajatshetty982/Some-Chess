#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>

#include "../include/game.h"
#include "../include/move.h"
#include "../include/render.h"
#include "../include/pieces.h"
#include "../include/board.h"
#include "../include/constants.h"
#include "../include/models.h"

int main()
{
    init_sdl();
    SDL_Window *window = init_window();
    SDL_Renderer *renderer = init_renderer(window);

    Gamestate *state = calloc(1, sizeof(Gamestate));
    init_game(state);
    PieceTextures *textures = malloc(sizeof(PieceTextures));
    if (!textures){
        printf("Fatal: malloc failed. aborting game\n");
        exit(-1);
    }
    load_piece_textures(renderer, textures);
    init_piece_positions(state);


    int running = 1;
    while (running)
    {
        handle_input(state, &running);
        // update_game(state);
        render_game(renderer, state, textures);
        SDL_Delay(16); // ~60 FPS NOTE: use SDL_GetPerformanceCounter() her instead
    }
    free_piece_textures(textures);
    cleanup_sdl(window, renderer);
    free(textures);
    free(state);

    return 0;
}
