#include "../headers/walls.h"

static texture_t wallTextures[NUM_WALL_TEXTURES];

// Define texture file names for walls
static const char *wallTextureFileNames[NUM_WALL_TEXTURES] = {
	"./images/redbrick.png",
	"./images/purplestone.png",
	"./images/colorstone.png",
	"./images/wood.png",
	"./images/graystone.png",
	"./images/mossystone.png",
	"./images/bluestone.png",
	"./images/eagle.png",
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


int wallTopPixel;
int wallBottomPixel;
color_t texelColor;
float projectedWallHeight;
int wallStripHeight;


void renderWalls(void) {
    for (int rayIndex = 0; rayIndex < NUM_RAYS; rayIndex++) {
        float perpDistance = calculatePerpendicularDistance(rayIndex);
        float projectedWallHeight = calculateProjectedWallHeight(perpDistance);
        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel, wallBottomPixel;
        calculateWallStripPixels(projectedWallHeight, &wallTopPixel, &wallBottomPixel);

        int textureNum = rays[rayIndex].wallHitContent - 1;
        int textureWidth = wallTextures[textureNum].width;
        int textureHeight = wallTextures[textureNum].height;

        // Render floor and ceiling
        renderFloor(wallBottomPixel, &texelColor, rayIndex);
        renderCeiling(wallTopPixel, &texelColor, rayIndex);

        int textureOffsetX = calculateTextureOffsetX(rayIndex);

        renderWallStrip(rayIndex, wallTopPixel, wallBottomPixel, textureOffsetX, textureNum, textureWidth, textureHeight, projectedWallHeight, wallStripHeight);
    }
}

float calculatePerpendicularDistance(int rayIndex) {
    return rays[rayIndex].distance * cos(rays[rayIndex].rayAngle - player.rotationAngle);
}

float calculateProjectedWallHeight(float perpDistance) {
    return (TILE_SIZE / perpDistance) * PROJECTION_PLANE;
}

void calculateWallStripPixels(float projectedWallHeight, int *wallTopPixel, int *wallBottomPixel) {
    *wallTopPixel = (WINDOW_HEIGHT / 2) - ((int)projectedWallHeight / 2);
    *wallTopPixel = *wallTopPixel < 0 ? 0 : *wallTopPixel;
    *wallBottomPixel = (WINDOW_HEIGHT / 2) + ((int)projectedWallHeight / 2);
    *wallBottomPixel = *wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : *wallBottomPixel;
}

int calculateTextureOffsetX(int rayIndex) {
    if (rays[rayIndex].wasHitVertical)
        return (int)rays[rayIndex].wallHitY % TILE_SIZE;
    else
        return (int)rays[rayIndex].wallHitX % TILE_SIZE;
}


void renderWallStrip(int rayIndex, int wallTopPixel, int wallBottomPixel, int textureOffsetX, int textureNum, int textureWidth, int textureHeight, float projectedWallHeight, int wallStripHeight) {
    for (int y = wallTopPixel; y < wallBottomPixel; y++) {
        int distanceFromTop = y + ((int)projectedWallHeight / 2) - (WINDOW_HEIGHT / 2);
        int textureOffsetY = distanceFromTop * ((float)textureHeight / wallStripHeight);

        texelColor = wallTextures[textureNum].texture_buffer[(textureWidth * textureOffsetY) + textureOffsetX];

        if (rays[rayIndex].wasHitVertical)
            adjustColorIntensity(&texelColor, 0.5);

        drawPixel(rayIndex, y, texelColor);
    }
}



/**
 * adjustColorIntensity - Adjust the intensity of a color by a given factor
 * @color: Pointer to the color to be adjusted
 * @factor: Factor by which to adjust the color intensity
 */
void adjustColorIntensity(color_t *color, float factor)
{
	color_t alpha = (*color & 0xFF000000);
	color_t red = (*color & 0x00FF0000) * factor;
	color_t green = (*color & 0x0000FF00) * factor;
	color_t blue = (*color & 0x000000FF) * factor;

	*color = alpha | (red & 0x00FF0000) | (green & 0x0000FF00) | (blue & 0x000000FF);
}
