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

// Function to render walls based on raycasting results
void renderWalls(void)
{
    int x, y, texNum, texture_width, texture_height,
        textureOffsetX, wallBottomPixel, wallStripHeight,
        wallTopPixel, distanceFromTop, textureOffsetY;
    float perpDistance, projectedWallHeight;
    color_t texelColor;

    // Loop through each ray
    for (x = 0; x < NUM_RAYS; x++)
    {
        // Calculate perpendicular distance and projected wall height
        perpDistance = rays[x].distance * cos(rays[x].rayAngle - player.rotationAngle);
        projectedWallHeight = (TILE_SIZE / perpDistance) * PROJECTION_PLANE;
        wallStripHeight = (int)projectedWallHeight;

        // Calculate top and bottom pixels of the wall strip
        wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
        wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;

        // Determine texture number and dimensions
        texNum = rays[x].wallHitContent - 1;
        texture_width = wallTextures[texNum].width;
        texture_height = wallTextures[texNum].height;

        // Render floor and ceiling
        renderFloor(wallBottomPixel, &texelColor, x);
        renderCeiling(wallTopPixel, &texelColor, x);

        // Calculate texture offset
        if (rays[x].wasHitVertical)
            textureOffsetX = (int)rays[x].wallHitY % TILE_SIZE;
        else
            textureOffsetX = (int)rays[x].wallHitX % TILE_SIZE;

        // Loop through pixels in the wall strip
        for (y = wallTopPixel; y < wallBottomPixel; y++)
        {
            distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
            textureOffsetY = distanceFromTop * ((float)texture_height / wallStripHeight);
            // Get texel color from texture buffer
            texelColor = wallTextures[texNum].texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
            // Darken color if the wall was hit vertically
            if (rays[x].wasHitVertical)
                changeColorIntensity(&texelColor, 0.5);
            // Draw pixel on the screen
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
