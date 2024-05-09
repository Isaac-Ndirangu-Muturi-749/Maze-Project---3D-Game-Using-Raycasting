#include "../headers/weapon.h"

static texture_t weaponTextures[NUM_WEAPONS];
static const char *WeaponTextureFileNames[NUM_WEAPONS] = {
	"./images/gun1.png",
};


void loadWeaponTextures(void) {
	for (int i = 0; i < NUM_WEAPONS; i++) {
		upng_t *upng = upng_new_from_file(WeaponTextureFileNames[i]);

		if (upng != NULL && upng_decode(upng) == UPNG_EOK) {
			weaponTextures[i].upngTexture = upng;
			weaponTextures[i].width = upng_get_width(upng);
			weaponTextures[i].height = upng_get_height(upng);
			weaponTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
		}
	}
}


void freeWeaponTextures(void) {
	for (int i = 0; i < NUM_WEAPONS; i++) {
		upng_free(weaponTextures[i].upngTexture);
	}
}


/**
 * renderWeapon - render the weapon texture
 */
void renderWeapon(void)
{
	// Load the weapon image
	SDL_Surface* loadedSurface = IMG_Load("./images/gun1.png");

	// Get the weapon texture information
	uint32_t weaponWidth = loadedSurface->w;
	uint32_t weaponHeight = loadedSurface->h;

	// Calculate the position to render the weapon texture
	int weaponX = (WINDOW_WIDTH - 200) / 2;
	int weaponY = WINDOW_HEIGHT - 270; // Adjusted position


	// Create an SDL_Rect structure for the weapon texture position and dimensions
	SDL_Rect weaponRect = { weaponX, weaponY, weaponWidth, weaponHeight };

	// Create texture from surface
	SDL_Texture* weaponTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	// Render the weapon texture onto the screen
	SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
	SDL_RenderPresent(renderer);

	// Clean up
	SDL_DestroyTexture(weaponTexture);
	SDL_FreeSurface(loadedSurface);
}
