#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

void drawWalls(SDL_Renderer *renderer) {
    // Example: Drawing walls with different orientations
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color for walls facing NORTH and SOUTH
    SDL_RenderDrawLine(renderer, 100, 100, 100, 200); // Wall facing NORTH
    SDL_RenderDrawLine(renderer, 200, 100, 200, 200); // Wall facing NORTH

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green color for walls facing EAST and WEST
    SDL_RenderDrawLine(renderer, 300, 100, 400, 100); // Wall facing EAST
    SDL_RenderDrawLine(renderer, 300, 200, 400, 200); // Wall facing EAST
}

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Raycasting Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        // Draw walls
        drawWalls(renderer);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
