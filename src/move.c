#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "game.h"



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

	int even = 0; // Example variable to toggle some behavior

	if (keysym->sym == SDLK_RETURN) {
		// Handle Enter key press
		even = !even; // Toggle even state
	}

	if (keysym->sym == SDLK_ESCAPE) {
		// Handle Escape key press
		*running = 0; // Exit the game
	}

	if (event.key.keysym.sym > 96 && event.key.keysym.sym < 105) {

		if (even)


			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					// want a modal dialog to confirm exit
					// give me the code for that, copilot
					*running = 0; // Exit the game
					break;

				case SDL_KeyCode
					// Handle other key events here
					default:
					break;
			}

	}

	void handle_mouse_event(Gamestate* state, SDL_MouseButtonEvent* event, int* running) {

		if (event->button == SDL_BUTTON_RIGHT) {
			// Handle right mouse button click
			return;
		}

		if (event->button == SDL_BUTTON_MIDDLE) {
			// Handle middle mouse button click
			return;
		}
		switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				// Handle left mouse button click
				break;
			case SDL_BUTTON_RIGHT:
				// Handle right mouse button click
				break;
			default:
				break;
		}
	}
