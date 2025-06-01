#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "game.h"
#include "render.h"



void handle_input(Gamestate* state, int* running){

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			*running = 0;

		} else if (event.type == SDL_KEYDOWN) {
			handle_key_event(state, &event.key, running);

		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			// Handle mouse button events here
			handle_mouse_event(state, &event.button, running);

		}
	}
}

void handle_key_event(Gamestate* state, SDL_Keysym* keysym, int* running) {

	// int even = 0; // Example variable to toggle some behavior

	// if (keysym->sym == SDLK_RETURN) {
	// 	// Handle Enter key press
	// 	even = !even; // Toggle even state
	// }

	// if (keysym->sym == SDLK_ESCAPE) {
	// 	// Handle Escape key press
	// 	*running = 0; // Exit the game
	// }

	// if (event.key.keysym.sym > 96 && event.key.keysym.sym < 105) {

	// 	if (even)


	// 		switch (event.key.keysym.sym) {
	// 			case SDLK_ESCAPE:
	// 				// want a modal dialog to confirm exit
	// 				// give me the code for that, copilot
	// 				*running = 0; // Exit the game
	// 				break;

	// 			case SDL_KeyCode
	// 				// Handle other key events here
	// 				default:
	// 				break;
	// 		}

	// }

	// void handle_mouse_event(Gamestate* state, SDL_MouseButtonEvent* event, int* running) {

	// 	if (event->button == SDL_BUTTON_RIGHT) {
	// 		// Handle right mouse button click
	// 		return;
	// 	}

	// 	if (event->button == SDL_BUTTON_MIDDLE) {
	// 		// Handle middle mouse button click
	// 		return;
	// 	}
	// 	switch (event.button.button) {
	// 		case SDL_BUTTON_LEFT:
	// 			// Handle left mouse button click
	// 			break;
	// 		case SDL_BUTTON_RIGHT:
	// 			// Handle right mouse button click
	// 			break;
	// 		default:
	// 			break;
	// 	}
	// }
return;
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
}