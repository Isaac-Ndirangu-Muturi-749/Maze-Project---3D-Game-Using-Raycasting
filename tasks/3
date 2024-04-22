#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define MOVEMENT_SPEED 5 // Adjust movement speed as needed

void drawWalls(SDL_Renderer *renderer) {
    // Example: Drawing walls with different orientations
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 100, 100, 100, 200); // Wall facing NORTH
    SDL_RenderDrawLine(renderer, 200, 100, 200, 200); // Wall facing NORTH
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

    // Camera position (initially at the center of the window)
    int cameraX = WINDOW_WIDTH / 2;
    int cameraY = WINDOW_HEIGHT / 2;

    // Main loop
    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            } else if (event.type == SDL_KEYDOWN) {
                // Handle movement keys
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        cameraY -= MOVEMENT_SPEED; // Move camera up
                        break;
                    case SDLK_s:
                        cameraY += MOVEMENT_SPEED; // Move camera down
                        break;
                    case SDLK_a:
                        cameraX -= MOVEMENT_SPEED; // Move camera left
                        break;
                    case SDLK_d:
                        cameraX += MOVEMENT_SPEED; // Move camera right
                        break;
                }
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        SDL_RenderClear(renderer);

        // Draw walls
        drawWalls(renderer);

        // Draw camera position
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_RenderDrawPoint(renderer, cameraX, cameraY);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
