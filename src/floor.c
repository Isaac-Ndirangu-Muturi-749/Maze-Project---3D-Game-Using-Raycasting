#include "../headers/floor.h"

static texture_t floorTextures[NUM_FLOOR_TEXTURES];
static const char *floorTextureFileNames[NUM_FLOOR_TEXTURES] = {
	"./images/64x64-floor.png",
};


// Function to load floor textures
void loadFloorTextures(void) {
	for (int i = 0; i < NUM_FLOOR_TEXTURES; i++) {
		upng_t *upng = upng_new_from_file(floorTextureFileNames[i]);
		if (upng != NULL && upng_decode(upng) == UPNG_EOK) {
			floorTextures[i].upngTexture = upng;
			floorTextures[i].width = upng_get_width(upng);
			floorTextures[i].height = upng_get_height(upng);
			floorTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
		}
	}
}


void freeFloorTextures(void) {
	for (int i = 0; i < NUM_CEILING_TEXTURES; i++) {
		if (floorTextures[i].upngTexture != NULL) {
			upng_free(floorTextures[i].upngTexture);
			floorTextures[i].upngTexture = NULL;
		}
	}
}


/**
 * renderFloor - render floor projection
 *
 * @WallBottomPixel: wall bottom pixel
 * @texelColor: texture color for current pixel
 * @rayIndex: current element in the rays array
*/
void renderFloor(int wallBottomPixel, color_t *texelColor, int rayIndex) {
    int textureWidth, textureHeight;
    getFloorTextureDimensions(&textureWidth, &textureHeight);

    for (int y = wallBottomPixel - 1; y < WINDOW_HEIGHT; y++) {
        float distance = calculateFloorDistance(y, rayIndex);

        int textureOffsetX, textureOffsetY;
        calculateFloorTextureOffsets(distance, rayIndex, &textureOffsetX, &textureOffsetY, textureWidth, textureHeight);

        fetchFloorTexelColor(texelColor, textureOffsetX, textureOffsetY, textureWidth, textureHeight);

        drawPixel(rayIndex, y, *texelColor);
    }
}


void getFloorTextureDimensions(int *textureWidth, int *textureHeight) {
    *textureWidth = floorTextures[0].width;
    *textureHeight = floorTextures[0].height;
}


float calculateFloorDistance(int screenHeight, int rayIndex) {
    float ratio = player.height / (screenHeight - WINDOW_HEIGHT / 2);
    return (ratio * PROJECTION_PLANE) / cos(rays[rayIndex].rayAngle - player.rotationAngle);
}


void calculateFloorTextureOffsets(float distance, int rayIndex, int *textureOffsetX, int *textureOffsetY, int textureWidth, int textureHeight) {
    *textureOffsetY = (int)abs((distance * sin(rays[rayIndex].rayAngle)) + player.y);
    *textureOffsetX = (int)abs((distance * cos(rays[rayIndex].rayAngle)) + player.x);

    *textureOffsetX = (int)(abs(*textureOffsetX * textureWidth / 30) % textureWidth);
    *textureOffsetY = (int)(abs(*textureOffsetY * textureHeight / 30) % textureHeight);
}


void fetchFloorTexelColor(color_t *texelColor, int textureOffsetX, int textureOffsetY, int textureWidth, int textureHeight) {
    *texelColor = floorTextures[0].texture_buffer[(textureWidth * textureOffsetY) + textureOffsetX];
}
