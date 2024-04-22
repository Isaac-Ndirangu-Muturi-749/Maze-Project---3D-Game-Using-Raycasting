/**
 * @file main.c
 * @brief This file contains the main function to handle multi-tasking in the game using SDL2.
 */

#include <SDL2/SDL.h>
#include <stdio.h>

// Constants for window dimensions and player movement speed
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define PLAYER_SPEED 5

// Structure to represent the player
typedef struct {
    float x; // Player's x-coordinate
    float y; // Player's y-coordinate
    float angle; // Player's rotation angle
} Player;

// Function to handle player movement
void movePlayer(Player *player, float dx, float dy) {
    // Move the player by dx and dy
    player->x += dx;
    player->y += dy;
}

// Function to handle player rotation
void rotatePlayer(Player *player, float da) {
    // Rotate the player by da
    player->angle += da;
}

// Function to handle input events
void handleInput(Player *player) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        movePlayer(player, PLAYER_SPEED * cos(player->angle), PLAYER_SPEED * sin(player->angle));
                        break;
                    case SDLK_s:
                        movePlayer(player, -PLAYER_SPEED * cos(player->angle), -PLAYER_SPEED * sin(player->angle));
                        break;
                    case SDLK_a:
                        rotatePlayer(player, -0.1); // Rotate left
                        break;
                    case SDLK_d:
                        rotatePlayer(player, 0.1); // Rotate right
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                // Handle quit event
                break;
            default:
                break;
        }
    }
}

/**
 * @brief Main function.
 */
int main() {
    // SDL initialization and window creation code omitted for brevity

    Player player = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0.0};

    // Main loop and rendering code omitted for brevity

    return 0;
}
