#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include "../include/pieces.h"

#include "../include/constants.h"
#include "../include/models.h"

void load_piece_textures(SDL_Renderer* renderer, PieceTextures* textures) {
	const char* pieces_file_prefix = "./wad/pieces/";
    char buff[250];
    const char *white_names[] = {"wP", "wN", "wB", "wR", "wQ", "wK"};
    const char *black_names[] = {"bP", "bN", "bB", "bR", "bQ", "bK"};
    for (int i = 0; i < 6; i++)
    {
        sprintf(buff, "%s%s.png", pieces_file_prefix, white_names[i]);
        textures->white[i] = IMG_LoadTexture(renderer, buff);
        if (!textures->white[i])
        {
            fprintf(stderr, "Failed to load %s: %s\n", buff, IMG_GetError());
            exit(1);
        }
        sprintf(buff, "%s%s.png", pieces_file_prefix, black_names[i]);
        textures->black[i] = IMG_LoadTexture(renderer, buff);
        if (!textures->black[i])
        {
            fprintf(stderr, "Failed to load %s: %s\n", buff, IMG_GetError());
            exit(1);
        }
    }
  
}




void free_piece_textures(PieceTextures *textures) {
    for (int i = 0; i < 6; i++) {
        if (textures->white[i]) SDL_DestroyTexture(textures->white[i]);
        if (textures->black[i]) SDL_DestroyTexture(textures->black[i]);
    }
}
