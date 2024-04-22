/**
 * @file main.c
 * @brief This file contains the main function to add a rain effect in the game using SDL2.
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_RAINDROPS 1000
#define RAIN_SPEED 5

// Structure to represent a raindrop
typedef struct {
    int x, y; // Position
} Raindrop;

/**
 * @brief Main function.
 */
int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow("Rain", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    // Create raindrops
    Raindrop raindrops[MAX_RAINDROPS];
    for (int i = 0; i < MAX_RAINDROPS; ++i) {
        raindrops[i].x = rand() % WINDOW_WIDTH;
        raindrops[i].y = rand() % WINDOW_HEIGHT;
    }

    // Main loop
    int quit = 0;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Update and render raindrops
        for (int i = 0; i < MAX_RAINDROPS; ++i) {
            raindrops[i].y += RAIN_SPEED;
            if (raindrops[i].y > WINDOW_HEIGHT) {
                raindrops[i].y = 0;
                raindrops[i].x = rand() % WINDOW_WIDTH;
            }
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, raindrops[i].x, raindrops[i].y, raindrops[i].x, raindrops[i].y + 5);
        }

        // Render to window
        SDL_RenderPresent(renderer);

        // Delay to control frame rate
        SDL_Delay(16);
    }

    // Cleanup resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
