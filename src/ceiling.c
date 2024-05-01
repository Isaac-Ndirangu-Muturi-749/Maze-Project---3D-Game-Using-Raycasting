#include "../headers/ceiling.h"

static texture_t ceilingTextures[NUM_CEILING_TEXTURES];
static const char *ceilingTextureFileNames[NUM_CEILING_TEXTURES] = {
    "./images/64x64-clrsky.png",
};

// Function to load ceiling textures
void loadCeilingTextures(void) {
    for (int i = 0; i < NUM_CEILING_TEXTURES; i++) {
        upng_t *upng = upng_new_from_file(ceilingTextureFileNames[i]);
        if (upng != NULL && upng_decode(upng) == UPNG_EOK) {
            ceilingTextures[i].upngTexture = upng;
            ceilingTextures[i].width = upng_get_width(upng);
            ceilingTextures[i].height = upng_get_height(upng);
            ceilingTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
        }
    }
}

void freeCeilingTextures(void) {
    for (int i = 0; i < NUM_CEILING_TEXTURES; i++) {
        if (ceilingTextures[i].upngTexture != NULL) {
            upng_free(ceilingTextures[i].upngTexture);
            ceilingTextures[i].upngTexture = NULL;
        }
    }
}


// Function to render the ceiling projection
void renderCeil(int wallTopPixel, color_t *texelColor, int x) {
    int y, texture_width, texture_height, textureOffsetY, textureOffsetX;

    texture_width = ceilingTextures[0].width; // Assuming all ceiling textures have the same dimensions
    texture_height = ceilingTextures[0].height;

    for (y = 0; y < wallTopPixel; y++) {
        float distance, ratio;

        ratio = player.height / (y - WINDOW_HEIGHT / 2);
        distance = (ratio * PROJECTION_PLANE) / cos(rays[x].rayAngle - player.rotationAngle);

        textureOffsetY = (int)abs((-distance * sin(rays[x].rayAngle)) + player.y);
        textureOffsetX = (int)abs((-distance * cos(rays[x].rayAngle)) + player.x);

        textureOffsetX = (int)(abs(textureOffsetX * texture_width / 40) % texture_width);
        textureOffsetY = (int)(abs(textureOffsetY * texture_height / 40) % texture_height);

        *texelColor = ceilingTextures[0].texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
        drawPixel(x, y, *texelColor);
    }
}
