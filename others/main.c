#include <SDL2/SDL.h> // Include SDL2 header
#include <stdbool.h>


int main() {
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow(
        "SDL2 Window",            // Window title
        SDL_WINDOWPOS_UNDEFINED,  // Initial X position
        SDL_WINDOWPOS_UNDEFINED,  // Initial Y position
        640,                      // Width, in pixels
        480,                      // Height, in pixels
        SDL_WINDOW_SHOWN          // Flags
    );
    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Main loop
    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Draw your game here (not implemented in this example)

        SDL_Delay(16); // Cap frame rate to roughly 60 frames per second
    }

    // Clean up resources
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
