#include "../headers/window.h"

// Define static variables
SDL_Renderer *renderer;
color_t *colorBuffer;
SDL_Texture *colorBufferTexture;
SDL_Window *window;


/**
 * initializeWindow - Initialize window to display the maze
 * Return: true in case of success, false if it fails
*/
bool initializeWindow(void)
{
	SDL_DisplayMode display_mode;
	int fullScreenWidth, fullScreenHeight;

	SDL_GetCurrentDisplayMode(0, &display_mode);
	fullScreenWidth = display_mode.w;
	fullScreenHeight = display_mode.h;
	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		fullScreenWidth,
		fullScreenHeight,
		SDL_WINDOW_BORDERLESS
	);

	renderer = SDL_CreateRenderer(window, -1, 1);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	/* allocate the total amount of bytes in memory to hold our colorbuffer */
	colorBuffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);

	/* create an SDL_Texture to display the colorbuffer */
	colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
		SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

	return (true);
}


/**
 * destroyWindow - destroy window when the game is over
 *
*/
void destroyWindow(void)
{
	free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
