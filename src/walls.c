#include "../headers/walls.h"

static texture_t wallTextures[NUM_WALL_TEXTURES];
// Define texture file names for walls
static const char *wallTextureFileNames[NUM_WALL_TEXTURES] = {
    "./images/redbrick.png",
    "./images/purplestone.png",
    "./images/mossystone.png",
    "./images/colorstone.png",
    "./images/bluestone.png",
    "./images/wood.png"
};

// Function to load wall textures
void loadWallTextures(void) {
    for (int i = 0; i < NUM_WALL_TEXTURES; i++) {
        upng_t *upng = upng_new_from_file(wallTextureFileNames[i]);
        if (upng != NULL && upng_decode(upng) == UPNG_EOK) {
            wallTextures[i].upngTexture = upng;
            wallTextures[i].width = upng_get_width(upng);
            wallTextures[i].height = upng_get_height(upng);
            wallTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
        }
    }
}

// Function to free wall textures
void freeWallTextures(void) {
    for (int i = 0; i < NUM_WALL_TEXTURES; i++) {
        if (wallTextures[i].upngTexture != NULL) {
            upng_free(wallTextures[i].upngTexture);
            wallTextures[i].upngTexture = NULL;
        }
    }
}

// Function to render wall projection
void renderWall(void) {
    for (int x = 0; x < NUM_RAYS; x++) {
        float perpDistance = rays[x].distance * cos(rays[x].rayAngle - player.rotationAngle);
        float projectedWallHeight = (TILE_SIZE / perpDistance) * PROJECTION_PLANE;
        int wallStripHeight = (int)projectedWallHeight;
        int wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
        int wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);

        // Ensure wallTopPixel and wallBottomPixel are within screen bounds
        wallTopPixel = (wallTopPixel < 0) ? 0 : wallTopPixel;
        wallBottomPixel = (wallBottomPixel > WINDOW_HEIGHT) ? WINDOW_HEIGHT : wallBottomPixel;

        int texNum = rays[x].wallHitContent - 1;
        int texture_width = wallTextures[texNum].width;
        int texture_height = wallTextures[texNum].height;

        for (int y = wallTopPixel; y < wallBottomPixel; y++) {
            int distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
            int textureOffsetY = distanceFromTop * ((float)texture_height / wallStripHeight);
            int textureOffsetX = rays[x].wasHitVertical ? ((int)rays[x].wallHitY % TILE_SIZE) :
                                                           ((int)rays[x].wallHitX % TILE_SIZE);
            color_t texelColor = wallTextures[texNum].texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];

            // Adjust color intensity for vertical walls
            if (rays[x].wasHitVertical) {
                changeColorIntensity(&texelColor, 0.5);
            }

            drawPixel(x, y, texelColor);
        }
    }
}

/**
 * changeColorIntensity - change color intensity
 * based on a factor value between 0 and 1
 * @factor: intensity factor
 * @color: color for intensity
*/
void changeColorIntensity(color_t *color, float factor)
{
	color_t a = (*color & 0xFF000000);
	color_t r = (*color & 0x00FF0000) * factor;
	color_t g = (*color & 0x0000FF00) * factor;
	color_t b = (*color & 0x000000FF) * factor;

	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}
