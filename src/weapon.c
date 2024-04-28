#include "weapon.h"

const char *weaponTextureFileNames[NUM_WEAPONS] = {
    "./images/weapon1.png",
    "./images/weapon2.png"
};

void loadWeaponTextures(void) {
    int i;
    for (i = 0; i < NUM_WEAPONS; i++) {
        upng_t *upng = upng_new_from_file(weaponTextureFileNames[i]);
        if (upng != NULL) {
            upng_decode(upng);
            if (upng_get_error(upng) == UPNG_EOK) {
                weaponTextures[i].texture.upngTexture = upng;
                weaponTextures[i].width = upng_get_width(upng);
                weaponTextures[i].height = upng_get_height(upng);
                weaponTextures[i].texture.texture_buffer = (color_t *)upng_get_buffer(upng);
            }
        }
    }
}

void freeWeaponTextures(void) {
    int i;
    for (i = 0; i < NUM_WEAPONS; i++) {
        upng_free(weaponTextures[i].texture.upngTexture);
    }
}
