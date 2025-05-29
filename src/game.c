#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include "game.h"
#include "render.h"


void init_sdl() {
    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        printf("sdl init failed, Error -> %s", SDL_GetError());
        exit(-1);
    }
    atexit(SDL_Quit);

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image init failed: %s\n", IMG_GetError());
        exit(1);
    }
    atexit(IMG_Quit);
}

Gamestate init_game(){
    // return all the position and data
    Gamestate gamestate;

    return gamestate;
}

SDL_Window* init_window(){

    SDL_Window* window = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        printf("sdl init failed, Error -> %s", SDL_GetError());
        exit(-1);
    }
    atexit(SDL_Quit);


    window = SDL_CreateWindow("Chess By Rajat", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if ( window == NULL ) {
        fprintf(stderr, "Couldn't set 640x480x8 video mode: %s\n",
                SDL_GetError());
        exit(1);
    }

    return window;
}


void cleanup_sdl(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}