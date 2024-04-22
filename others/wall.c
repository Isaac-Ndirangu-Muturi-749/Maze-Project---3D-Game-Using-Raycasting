#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h> // For fprintf and stderr

#define WIDTH 640
#define HEIGHT 480
#define FOV 60 // Field of view in degrees

// Map representation using a 2D array of characters
char map[HEIGHT][WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("Raycasting Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Window could not be created! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void close() {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}

void drawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawPoint(renderer, x2, y2); // Ensure endpoint is drawn
}

void castRay(float cameraX, float cameraY, float rayAngle, int x) {
    // Precalculate trigonometric values for efficiency
    float sinAngle = sin(rayAngle);
    float cosAngle = cos(rayAngle);

    // Calculate starting position of the ray
    float rayPosX = cameraX;
    float rayPosY = cameraY;

    // Deltas for step size in x and y directions
    float deltaX = (cosAngle > 0) ? 1.0f : -1.0f;
    float deltaY = (sinAngle > 0) ? 1.0f : -1.0f;

    // Calculate first map cell and distance to next x/y wall
    int mapX = (int)rayPosX;
    int mapY = (int)rayPosY;

    float sideDistX;
    if (deltaX > 0) {
        sideDistX = (rayPosX - mapX) / deltaX;
    } else {
        sideDistX = (mapX + 1.0f - rayPosX) / deltaX;
    }
    float sideDistY;
    if (deltaY > 0) {
        sideDistY = (rayPosY - mapY) / deltaY;
    } else {
        sideDistY = (mapY + 1.0f - rayPosY) / deltaY;
    }

    // Perform Digital Differential Algorithm (DDA) for ray casting
    float distance = 0;
}



void drawMap() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set color to white
    SDL_RenderClear(renderer); // Clear the renderer with white color

    // Render the map
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set color to black for walls
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (map[y][x] == '#') {
                SDL_Rect wallRect = {x, y, 1, 1}; // Create a rectangle for each wall element
                SDL_RenderFillRect(renderer, &wallRect); // Render the wall
            }
        }
    }

    SDL_RenderPresent(renderer); // Present the renderer to the window
}

int main() {
    if (!init()) {
        return 1;
    }

    // Render the map
    drawMap();

    // Wait for a key press to exit
    SDL_Event event;
    while (1) {
        if (SDL_WaitEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
    }

    close();
    return 0;
}
