#include "../headers/ceiling.h"

static texture_t ceilingTextures[NUM_CEILING_TEXTURES];
static const char *ceilingTextureFileNames[NUM_CEILING_TEXTURES] = {
    "./images/64x64-clrsky.png",
};

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


/**
 * renderCeiling - render ceiling projection
 * @WallTopPixel: wall top pixel
 * @texelColor: texture color for current pixel
 * @rayIndex: current element in the rays array
*/
void renderCeiling(int wallTopPixel, color_t *texelColor, int rayIndex) {
    int textureWidth, textureHeight;
    getCeilingTextureDimensions(&textureWidth, &textureHeight);

    for (int y = 0; y < wallTopPixel; y++) {
        float distance = calculateCeilingDistance(y, rayIndex);

        int textureOffsetX, textureOffsetY;
        calculateCeilingTextureOffsets(distance, rayIndex, &textureOffsetX, &textureOffsetY, textureWidth, textureHeight);

        fetchCeilingTexelColor(texelColor, textureOffsetX, textureOffsetY, textureWidth, textureHeight);

        drawPixel(rayIndex, y, *texelColor);
    }
}

void getCeilingTextureDimensions(int *textureWidth, int *textureHeight) {
    *textureWidth = ceilingTextures[0].width;
    *textureHeight = ceilingTextures[0].height;
}

float calculateCeilingDistance(int screenHeight, int rayIndex) {
    float ratio = player.height / (screenHeight - WINDOW_HEIGHT / 2);
    return (ratio * PROJECTION_PLANE) / cos(rays[rayIndex].rayAngle - player.rotationAngle);
}

void calculateCeilingTextureOffsets(float distance, int rayIndex, int *textureOffsetX, int *textureOffsetY, int textureWidth, int textureHeight) {
    *textureOffsetY = (int)abs((-distance * sin(rays[rayIndex].rayAngle)) + player.y);
    *textureOffsetX = (int)abs((-distance * cos(rays[rayIndex].rayAngle)) + player.x);

    *textureOffsetX = (int)(abs(*textureOffsetX * textureWidth / 40) % textureWidth);
    *textureOffsetY = (int)(abs(*textureOffsetY * textureHeight / 40) % textureHeight);
}

void fetchCeilingTexelColor(color_t *texelColor, int textureOffsetX, int textureOffsetY, int textureWidth, int textureHeight) {
    *texelColor = ceilingTextures[0].texture_buffer[(textureWidth * textureOffsetY) + textureOffsetX];
}
