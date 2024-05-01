#include "../headers/textures.h"

texture_t wallTextures[NUM_TEXTURES];

const char *textureFileNames[NUM_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/mossystone.png",
	"./images/64x64-floor.png",
	"./images/colorstone.png",
	"./images/bluestone.png",
	"./images/wood.png",
	"./images/64x64-clrsky.png",
};

texture_t weaponTextures[NUM_WEAPONS];

const char *WeaponTextureFileNames[NUM_WEAPONS] = {
    "./images/weapon1.png",
};


/**
 * WallTexturesready - load textures in the respective position
 *
*/
void WallTexturesready(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_t *upng;

		upng = upng_new_from_file(textureFileNames[i]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wallTextures[i].upngTexture = upng;
				wallTextures[i].width = upng_get_width(upng);
				wallTextures[i].height = upng_get_height(upng);
				wallTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}
}


/**
 * WeaponTexturesready - load textures in the respective position
 */
void WeaponTexturesready(void) {
    int i;

    for (i = 0; i < NUM_WEAPONS; i++) {
        upng_t *upng;

        upng = upng_new_from_file(WeaponTextureFileNames[i]);

        if (upng != NULL) {
            if (upng_decode(upng) == UPNG_EOK) {
                weaponTextures[i].upngTexture = upng;
                weaponTextures[i].width = upng_get_width(upng);
                weaponTextures[i].height = upng_get_height(upng);
                weaponTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
            }
		}
    }
}


/**
 * freeWallTextures - free wall textures
 *
*/
void freeWallTextures(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
		upng_free(wallTextures[i].upngTexture);
}


/**
 * freeWeaponTextures - free weapon textures
 */
void freeWeaponTextures(void) {
    int i;

    for (i = 0; i < NUM_WEAPONS; i++)
        upng_free(weaponTextures[i].upngTexture);
}
