#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "../include/game.h"
#include "../include/pieces.h"
#include "../include/render.h"
#include "../include/move.h"
#include "../include/logic.h"
#include "../include/constants.h"
#include "../include/models.h"
#include "../include/utils.h"




void handle_input(Gamestate* state, int* running){


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
		// understand the click position
		int x = event->x; // X coordinate of the click
		int y = event->y; // Y coordinate of the click

		// file and rank start with 0 from top left corner, 
		//I'm do this because renderer start with 1 too,
		// And I am not sure if it matters right now.
		int file = x / TILE_SIZE;
		int rank = y / TILE_SIZE;
		printf("File: %d,  Rank: %d\n", file, rank);
		handle_click(state, file,rank);
		break;
	case SDL_BUTTON_RIGHT:
		break;

	case SDL_BUTTON_MIDDLE:
		break;

	default:
		break;
	}
	

	// once we get the file and rank, we need to know what piece is there
	// and then we need to know if the piece can be moved to the clicked position
	// and then we need to update the game state accordingly
}



void handle_key_event(Gamestate* state, SDL_Event* event, int* running) {
    printf("Key events are not yet supported\n\n");
    return;
}

void handle_click(Gamestate *state, int file, int rank) {
    // Convert file and rank to a single square index (0-63)
    int clicked_square_index = rank * 8 + file;

    // First click: No piece is currently selected.
    if (state->selected_square == -1) {
        // Check if the clicked square contains a piece of the current player's color
        if (is_valid_first_click(state, file, rank)) {
            state->selected_square = clicked_square_index;
            generate_legal_moves(state); 
            // Now render_game() should highlight the squares in state->legal_moves
        }
    } 
    // Second click: A piece is already selected.
    else {
        // The clicked square is the destination for the move.
        // Check if this is a legal move.
        if (is_legal_move(state, clicked_square_index)) {
            make_move(state, state->selected_square, clicked_square_index);
            state->selected_square = -1; // Reset for the next turn
        } 
        // A piece was already selected, and we clicked on another piece of the same color.
        else if (is_valid_first_click(state, file, rank)) {
            // Deselect the old piece and select the new one.
            state->selected_square = clicked_square_index;
            generate_legal_moves(state);
        }
        // A piece was selected, and we clicked on an invalid square.
        else {
            // Deselect the piece and wait for a new valid first click.
            state->selected_square = -1;
            // The UI will now stop highlighting the previously selected piece.
        }
    }
}
