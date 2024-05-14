#include "../headers/window.h"

SDL_Renderer *renderer;
color_t *colorBuffer;
SDL_Texture *colorBufferTexture;
SDL_Window *window;

bool initializeWindow(void) {
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        // SDL initialization failed
        return false;
    }

    // Get the current display mode
    SDL_DisplayMode displayMode;
    if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0) {
        // Failed to get display mode
        SDL_Quit();
        return false;
    }

    // Create a window using the current display mode
    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              displayMode.w, displayMode.h, SDL_WINDOW_BORDERLESS);
    if (!window) {
        // Failed to create SDL window
        SDL_Quit();
        return false;
    }

    // Create a renderer for the window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        // Failed to create SDL renderer
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    // Set blend mode for the renderer
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Allocate memory for the color buffer
    colorBuffer = malloc(sizeof(color_t) * WINDOW_WIDTH * WINDOW_HEIGHT);
    if (!colorBuffer) {
        // Memory allocation failed
        destroyWindow();
        return false;
    }

    // Create an SDL_Texture to display the color buffer
    colorBufferTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
                                            SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!colorBufferTexture) {
        // Failed to create color buffer texture
        destroyWindow();
        return false;
    }

    // Window initialization succeeded
    return true;
}


void destroyWindow(void) {
    free(colorBuffer);
    SDL_DestroyTexture(colorBufferTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
