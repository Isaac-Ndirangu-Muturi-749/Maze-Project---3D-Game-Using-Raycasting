#include "../headers/rain.h"

Raindrop raindrops[MAX_RAIN_DROPS];
bool isRaining = false;

void initializeRaindrops(void) {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].x = rand() % (WINDOW_WIDTH + 400);
        // Start above the screen
        raindrops[i].y = -(rand() % WINDOW_HEIGHT);
        // Random velocity
        raindrops[i].velocity = 1.0f + (rand() % 5);
    }
}

void updateRaindrops(void) {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].y += raindrops[i].velocity;
        if (raindrops[i].y > WINDOW_HEIGHT) {
            // Reset if below the screen
            raindrops[i].y = -(rand() % WINDOW_HEIGHT);
        }
    }
}

void renderRaindrops(void) {
    // Blue color
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        // Render raindrop
        SDL_RenderDrawLine(renderer, raindrops[i].x, raindrops[i].y, raindrops[i].x, raindrops[i].y + 5);
    }
}
