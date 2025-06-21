#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "render.h"


SDL_Renderer* init_renderer(SDL_Window* window){

    SDL_Renderer* renderer = NULL;

   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    }


    return renderer;
}

void render_game(SDL_Renderer* renderer, Gamestate* state, PieceTextures *textures){
	
	
	// const int TILE_SIZE = SCREEN_HEIGHT / 8;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	for (int row = 0; row < 8; row++) {
		for (int colm = 0; colm < 8; colm++) {
			SDL_Rect tile = {
				colm * TILE_SIZE,
				row * TILE_SIZE,
				TILE_SIZE,
				TILE_SIZE
			};

			if ((row + colm) % 2 == 0) {
				SDL_SetRenderDrawColor(renderer, (LIGHT_COLOR >> 16) & 0xFF, (LIGHT_COLOR >> 8) & 0xFF, LIGHT_COLOR & 0xFF, 255);
			} else {
				SDL_SetRenderDrawColor(renderer, (DARK_COLOR >> 16) & 0xFF, (DARK_COLOR >> 8) & 0xFF, DARK_COLOR & 0xFF, 255);
			}

			SDL_RenderFillRect(renderer, &tile);
		}
	}
    render_pieces(renderer, textures, state->fen);


	// Render pieces here using state data
	// ...

	SDL_RenderPresent(renderer);

	return;
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






void render_pieces(SDL_Renderer* renderer, PieceTextures* textures, char* fen) {

    int rank = 0, file = 0;
    for (int i = 0; fen[i] && fen[i] != ' '; i++) {
        char f = fen[i];
        if (f == '/') {
            rank++;
            file = 0;
        } else if (f >= '1' && f <= '8') {
            file += f - '0';
        } else {
            SDL_Texture* tex = NULL;
            int type = -1;
            if (f == 'P' || f == 'p') type = 0;
            else if (f == 'N' || f == 'n') type = 1;
            else if (f == 'B' || f == 'b') type = 2;
            else if (f == 'R' || f == 'r') type = 3;
            else if (f == 'Q' || f == 'q') type = 4;
            else if (f == 'K' || f == 'k') type = 5;

            if (type != -1) {
                if (f >= 'A' && f <= 'Z')
                    tex = textures->white[type];
                else
                    tex = textures->black[type];

                SDL_Rect dest = { file * TILE_SIZE, rank * TILE_SIZE, TILE_SIZE, TILE_SIZE };
                SDL_RenderCopy(renderer, tex, NULL, &dest);

            }
            file++;
        }
    }

    // SDL_RenderPresent(renderer);
}



int sync_current_piece_positions(Gamestate* state) {
    char* fen = state->fen;
	for (int i = 0;i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			state->pos[i][j] = NONE; // Initialize all positions to 0
		}
	}

	int rank = 0, file = 0;
	for (int i = 0; fen[i] && fen[i] != ' '; i++) {
		char f = fen[i];

		if (f == '/') {
			rank++;
            file = 0;
		} else if (f >= '1' && f <= '8'){
			file += f - '0';
		} else {
			int piece = NONE;
			switch(f){
				case 'P': piece = WHITE_PAWN; break;
                case 'N': piece = WHITE_KNIGHT; break;
                case 'B': piece = WHITE_BISHOP; break;
                case 'R': piece = WHITE_ROOK; break;
                case 'Q': piece = WHITE_QUEEN; break;
                case 'K': piece = WHITE_KING; break;
                case 'p': piece = BLACK_PAWN; break;
                case 'n': piece = BLACK_KNIGHT; break;
                case 'b': piece = BLACK_BISHOP; break;
                case 'r': piece = BLACK_ROOK; break;
                case 'q': piece = BLACK_QUEEN; break;
                case 'k': piece = BLACK_KING; break;
            }
			state->pos[rank][file] = piece;
			file++;
		}
	}
	return 0;
}


