#include "../headers/window.h"

SDL_Renderer *renderer;
color_t *colorBuffer;
SDL_Texture *colorBufferTexture;
SDL_Window *window;


bool initializeWindow(void) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
		return false;
	}

	SDL_DisplayMode displayMode;
	if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0) {
		fprintf(stderr, "Error getting display mode: %s\n", SDL_GetError());
		SDL_Quit();
		return false;
	}

	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
							  displayMode.w, displayMode.h, SDL_WINDOW_BORDERLESS);
	if (!window) {
		fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	// Allocate memory for the color buffer
	colorBuffer = malloc(sizeof(color_t) * WINDOW_WIDTH * WINDOW_HEIGHT);
	if (!colorBuffer) {
		fprintf(stderr, "Error allocating memory for color buffer\n");
		destroyWindow();
		return false;
	}

	// Create an SDL_Texture to display the color buffer
	colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
											SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!colorBufferTexture) {
		fprintf(stderr, "Error creating color buffer texture: %s\n", SDL_GetError());
		destroyWindow();
		return false;
	}

	return true;
}

void destroyWindow(void) {
	free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
