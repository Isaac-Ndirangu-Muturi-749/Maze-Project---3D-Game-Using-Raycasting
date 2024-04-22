#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define TILE_SIZE 32

#define MAX_MAP_ROWS 100
#define MAX_MAP_COLS 100

// Structure to represent the game map
typedef struct {
    char tiles[MAX_MAP_ROWS][MAX_MAP_COLS]; // 2D array to store the map tiles
    int rows;
    int cols;
} Map;

// Function to parse the map file and populate the Map structure
int parseMap(const char *filename, Map *map) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 0; // Error opening file
    }

    int row = 0;
    int col = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            map->rows = row; // Set the number of rows in the map
            col = 0; // Reset column index for next row
            row++; // Move to the next row
        } else {
            if (row < MAX_MAP_ROWS && col < MAX_MAP_COLS) {
                map->tiles[row][col] = (char)c; // Store the tile character in the map
                col++; // Move to the next column
            } else {
                printf("Error: Map size exceeds maximum limit\n");
                fclose(file);
                return 0; // Map size exceeds maximum limit
            }
        }
    }
    map->cols = col; // Set the number of columns in the map

    fclose(file);
    return 1; // Parsing successful
}

// Function to draw the map onto the window
void drawMap(SDL_Renderer *renderer, Map *map) {
    SDL_Rect tileRect;
    tileRect.w = TILE_SIZE;
    tileRect.h = TILE_SIZE;

    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            tileRect.x = j * TILE_SIZE;
            tileRect.y = i * TILE_SIZE;

            if (map->tiles[i][j] == 'W') {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color for walls
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color for empty spaces
            }

            SDL_RenderFillRect(renderer, &tileRect);
        }
    }
}

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Map Drawing Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Map map;

    // Parse the map file
    if (!parseMap("map.txt", &map)) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1; // Error parsing map file
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

        // Draw the map
        drawMap(renderer, &map);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
