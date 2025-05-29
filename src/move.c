#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include "game.h"



void handle_input(Gamestate* state, int* running){
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			*running = 0;
		} else if (event.type == SDL_KEYDOWN) {

			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					// want a modal dialog to confirm exit
					// give me the code for that, copilot
					*running = 0; // Exit the game



					break;
				// Handle other key events here
				default:
					break;
			}
		} else if (event.type == SDL_MOUSEBUTTONDOWN) {
			// Handle mouse button events here

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
	}
}