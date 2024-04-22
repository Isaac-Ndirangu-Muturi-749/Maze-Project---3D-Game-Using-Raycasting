#include <SDL2/SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

// Map dimensions
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Define colors
#define COLOR_BLACK 0x000000FF
#define COLOR_GREEN 0x00FF00FF
#define COLOR_RED 0xFF0000FF
#define COLOR_BLUE 0x0000FFFF

// Define wall orientation
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

// Define ray parameters
#define FOV_ANGLE 60
#define RAY_ANGLE_INCREMENT (FOV_ANGLE / WINDOW_WIDTH)

// Define map
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Function prototypes
void drawWalls(SDL_Renderer *renderer, float playerAngle);

int main(int argc, char *argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Game loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // Player angle
    float playerAngle = 0;

    // Main loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw walls using raycasting
        drawWalls(renderer, playerAngle);

        // Update screen
        SDL_RenderPresent(renderer);

        // Cap frame rate
        SDL_Delay(10);
    }

    // Destroy window and renderer
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}

// Function to draw walls using raycasting
void drawWalls(SDL_Renderer *renderer, float playerAngle) {
    // Loop through each column of the window
    for (int x = 0; x < WINDOW_WIDTH; x++) {
        // Calculate ray angle
        float rayAngle = playerAngle - (FOV_ANGLE / 2) + (x * RAY_ANGLE_INCREMENT);
        if (rayAngle < 0) {
            rayAngle += 360;
        } else if (rayAngle >= 360) {
            rayAngle -= 360;
        }

        // Perform ray casting to find wall intersections

        // Calculate projected wall height
        int wallHeight = (int)((64.0f / cos(rayAngle)) * 277.0f);

        // Calculate wall color based on orientation
        Uint32 wallColor;
        if (rayAngle >= 45 && rayAngle < 135) {
            wallColor = COLOR_BLUE;
        } else if (rayAngle >= 135 && rayAngle < 225) {
            wallColor = COLOR_RED;
        } else if (rayAngle >= 225 && rayAngle < 315) {
            wallColor = COLOR_GREEN;
        } else {
            wallColor = COLOR_BLACK;
        }

        // Draw wall slice
        SDL_SetRenderDrawColor(renderer, (wallColor >> 24) & 0xFF, (wallColor >> 16) & 0xFF, (wallColor >> 8) & 0xFF, wallColor & 0xFF);
        SDL_RenderDrawLine(renderer, x, (WINDOW_HEIGHT - wallHeight) / 2, x, (WINDOW_HEIGHT + wallHeight) / 2);
    }
}
