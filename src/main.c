#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include "game.h"
#include "move.h"
#include "render.h"

int main() {

    init_sdl();
    Gamestate state = init_game();
    SDL_Window* window = init_window();
    SDL_Renderer* renderer = init_renderer(window);
    load_textures(renderer, &state);

    int running = 1;

    while (running) {
        handle_input(&state, &running);
        update_game(&state);
        render_game(renderer, &state);
        SDL_Delay(16); // ~60 FPS
    }

    cleanup(window, renderer);

    return 0;
}






// int main_temp(int argc, char* argv[]) {
//     int row;
//     int colm;

//     SDL_Window* window = NULL;
//     SDL_Renderer* renderer = NULL;

//     if(SDL_Init(SDL_INIT_VIDEO) == -1){
//         printf("sdl init failed, Error -> %s", SDL_GetError());
//         exit(-1);
//     }
//     atexit(SDL_Quit);

//     if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
//         printf("SDL_image init failed: %s\n", IMG_GetError());
//         exit(1);
//     }
//     atexit(IMG_Quit);

//     window = SDL_CreateWindow("Chess By Rajat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//     if ( window == NULL ) {
//         fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
//                 SDL_GetError());
//         exit(1);
//     }

//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         printf("Renderer creation failed: %s\n", SDL_GetError());
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 1;
//     }

//     SDL_Event e;
//     int  running = 1;

//     while (running) 
//     {
//         while (SDL_PollEvent(&e)){ 
//             if (e.type == SDL_QUIT) {running = 0;}
//         }

//         SDL_RenderClear(renderer);
//         for ( row = 0; row < 8; row++){

//             for (colm = 0; colm < 8; colm++){

//                 SDL_Rect tile = {
//                     colm * TILE_SIZE,
//                     row * TILE_SIZE,
//                     TILE_SIZE,
//                     TILE_SIZE
//                 };

//                 int do_dark = (row+colm) % 2 == 0;
//                 if (do_dark) {
//                     SDL_SetRenderDrawColor(renderer, 118, 150, 86, 255);
//                 }
//                 else {
//                     SDL_SetRenderDrawColor(renderer, 248, 231, 187, 255);

//                 }
//                 SDL_RenderFillRect(renderer, &tile);
//             }
//         }

//         SDL_RenderPresent(renderer); // push buffer to screen
//         SDL_Delay(16); // ~60 FPS

//     }  

//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();
//     return 0;
// }