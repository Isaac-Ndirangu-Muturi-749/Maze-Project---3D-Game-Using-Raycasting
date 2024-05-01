#include "../headers/rain.h"

Raindrop raindrops[MAX_RAIN_DROPS];
bool isRaining = false;

void initializeRaindrops(void) {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].x = rand() % SCREEN_WIDTH;
        raindrops[i].y = -(rand() % SCREEN_HEIGHT); // Start above the screen
        raindrops[i].velocity = 1.0f + (rand() % 5); // Random velocity
    }
}

void updateRaindrops(void) {
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        raindrops[i].y += raindrops[i].velocity;
        if (raindrops[i].y > SCREEN_WIDTH) {
            raindrops[i].y = -(rand() % SCREEN_HEIGHT); // Reset if below the screen
        }
    }
}

void renderRaindrops(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color
    for (int i = 0; i < MAX_RAIN_DROPS; i++) {
        SDL_RenderDrawLine(renderer, raindrops[i].x, raindrops[i].y, raindrops[i].x, raindrops[i].y + 5); // Render raindrop
    }
}
