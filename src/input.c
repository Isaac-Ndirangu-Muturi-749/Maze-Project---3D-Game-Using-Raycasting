#include "../headers/input.h"

// Function to handle user input events
void handleInput(void) {
    SDL_Event event;

    // Process each event in the event queue
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            // Quit event: Exit the game
            case SDL_QUIT:
                GameRunning = false;
                break;
            // Keydown event: Handle key press
            case SDL_KEYDOWN:
                handleKeyDown(event.key.keysym.sym);
                break;
            // Keyup event: Handle key release
            case SDL_KEYUP:
                handleKeyUp(event.key.keysym.sym);
                break;
        }
    }

    // Check if spacebar is pressed to toggle rain effect
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (keyboardState[SDL_SCANCODE_SPACE])
        isRaining = !isRaining; // Toggle rain effect on/off
}

// Function to handle key press events
void handleKeyDown(SDL_Keycode key) {
    switch (key) {
        // Escape key: Exit the game
        case SDLK_ESCAPE:
            GameRunning = false;
            break;
        // Movement keys: Update player's movement direction
        case SDLK_UP:
        case SDLK_w:
            player.walkDirection = +1; // Move forward
            break;
        case SDLK_DOWN:
        case SDLK_s:
            player.walkDirection = -1; // Move backward
            break;
        // Rotation keys: Update player's turning direction
        case SDLK_RIGHT:
        case SDLK_d:
            player.turnDirection = +1; // Turn right
            break;
        case SDLK_LEFT:
        case SDLK_a:
            player.turnDirection = -1; // Turn left
            break;
    }
}

// Function to handle key release events
void handleKeyUp(SDL_Keycode key) {
    switch (key) {
        // Stop player's movement when up or down keys are released
        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_w:
        case SDLK_s:
            player.walkDirection = 0;
            break;
        // Stop player's turning when left or right keys are released
        case SDLK_RIGHT:
        case SDLK_LEFT:
        case SDLK_d:
        case SDLK_a:
            player.turnDirection = 0;
            break;
    }
}
