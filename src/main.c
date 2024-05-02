#include "../headers/main.h"

bool GameRunning = false;
int TicksLastFrame;

/**
 * Main function
 * Return: 0
*/
int main(void) {
    // Seed random number generator
    srand(SDL_GetTicks());

    setupGame();

    while (GameRunning) {
        handleInput();
        updateGame();
        renderGame();
        // Delay to control frame rate
        SDL_Delay(10);
    }

    destroyGame();
    return 0;
}

/**
 * Setup game - initialize player variables and load textures
*/
void setupGame(void) {
    GameRunning = initializeWindow();
    initializePlayer();
    initializeRaindrops();

    // Load textures
	loadFloorTextures();
	loadCeilingTextures();
	loadWallTextures();
    loadWeaponTextures();
}

/**
 * Update game - update delta time, player movement, and ray casting
*/
void updateGame(void) {
    float deltaTime;
    int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

    if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH) {
        SDL_Delay(timeToWait);
    }

    deltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;
    TicksLastFrame = SDL_GetTicks();

    movePlayer(deltaTime);
    castAllRays();
}


/**
 * Render game - call functions needed for rendering
*/
void renderGame(void) {
    clearColorBuffer(0xFF000000);
    renderWalls();
    renderMap();
    renderRays();
    renderPlayer();
    renderColorBuffer();
    renderWeapon();
	// Update and render raindrops if raining
	if (isRaining) {
		updateRaindrops();
		renderRaindrops();
	}
    SDL_RenderPresent(renderer);

}


/**
 * Destroy game - free textures and destroy window
*/
void destroyGame(void) {
    freeWeaponTextures();
    freeWallTextures();
    freeCeilingTextures();
    freeFloorTextures();
    destroyWindow();
}
