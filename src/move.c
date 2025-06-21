#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "game.h"
#include "render.h"



void handle_input(Gamestate* state, int* running){

    sync_current_piece_positions(state);// I believe this should be somewhere else

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			printf("Qutting the app!");
			*running = 0;

		} else if (event.type == SDL_KEYDOWN) {
			handle_key_event(state, &event.key, running);

		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			// Handle mouse button events here
			handle_mouse_event(state, &event.button, running);

		}
	}

}

void handle_mouse_event(Gamestate* state, SDL_MouseButtonEvent* event, int* running) {

	switch (event->button)
	{
	case SDL_BUTTON_LEFT:
		// Handle left mouse button click
		// all actions will be here!!


		// understand the click position
		int x = event->x; // X coordinate of the click
		int y = event->y; // Y coordinate of the click

		// file and rank start with 0 from top left corner, 
		//I'm do this because renderer start with 1 too,
		// And I am not sure if it matters right now.
		int file = x / TILE_SIZE;
		int rank = y / TILE_SIZE;
		printf("File: %d,  Rank: %d\n", file, rank);
		
		break;
	case SDL_BUTTON_RIGHT:
		// Handle right mouse button click
		break;

	case SDL_BUTTON_MIDDLE:
		// Handle middle mouse button click

		// This could be used for a special action, like showing a context menu
		break;
	default:
		break;
	}
	

	// once we get the file and rank, we need to know what piece is there
	// and then we need to know if the piece can be moved to the clicked position
	// and then we need to update the game state accordingly
}

void print_board(int pos[8][8]) {
    printf("Current board:\n");
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            printf("%2d \t", pos[rank][file]);
        }
        printf("\n");
    }
}

void handle_key_event(Gamestate* state, SDL_Event* event, int* running) {
    printf("Key events are not yet supported\n\n");
    print_board(state->pos);
    return;
}

