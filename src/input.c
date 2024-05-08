#include "../headers/input.h"

void handleInput(void) {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				GameRunning = false;
				break;
			case SDL_KEYDOWN:
				handleKeyDown(event.key.keysym.sym);
				break;
			case SDL_KEYUP:
				handleKeyUp(event.key.keysym.sym);
				break;
		}
	}

	// Add rain toggling logic
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_SPACE])
		isRaining = !isRaining; // Toggle rain on/off with spacebar
}

void handleKeyDown(SDL_Keycode key) {
	switch (key) {
		case SDLK_ESCAPE:
			GameRunning = false;
			break;
		case SDLK_UP:
			player.walkDirection = +1;
			break;
		case SDLK_DOWN:
			player.walkDirection = -1;
			break;
		case SDLK_RIGHT:
			player.turnDirection = +1;
			break;
		case SDLK_LEFT:
			player.turnDirection = -1;
			break;
		case SDLK_w:
			player.walkDirection = +1;
			break;
		case SDLK_s:
			player.walkDirection = -1;
			break;
		case SDLK_a:
			player.turnDirection = -1;
			break;
		case SDLK_d:
			player.turnDirection = +1;
			break;
	}
}

void handleKeyUp(SDL_Keycode key) {
	switch (key) {
		case SDLK_UP:
		case SDLK_DOWN:
			player.walkDirection = 0;
			break;
		case SDLK_RIGHT:
		case SDLK_LEFT:
		case SDLK_w:
		case SDLK_s:
			player.turnDirection = 0;
			break;
	}
}
