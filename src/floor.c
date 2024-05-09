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


// Function to render floor projection


/**
 * renderFloor - render floor projection
 *
 * @WallBottomPixel: wall bottom pixel
 * @texelColor: texture color for current pixel
 * @x: current element in the rays array
*/
void renderFloor(int wallBottomPixel, color_t *texelColor, int x)
{
	int y, texture_height, texture_width, textureOffsetY, textureOffsetX;
	float distance, ratio;

	texture_width = floorTextures[0].width;
	texture_height = floorTextures[0].height;

	for (y = wallBottomPixel - 1; y < WINDOW_HEIGHT; y++)
	{
		ratio = player.height / (y - WINDOW_HEIGHT / 2);
		distance = (ratio * PROJECTION_PLANE)
					/ cos(rays[x].rayAngle - player.rotationAngle);

		textureOffsetY = (int)abs((distance * sin(rays[x].rayAngle)) + player.y);
		textureOffsetX = (int)abs((distance * cos(rays[x].rayAngle)) + player.x);

		textureOffsetX = (int)(abs(textureOffsetX * texture_width / 30)
								% texture_width);
		textureOffsetY = (int)(abs(textureOffsetY * texture_height / 30)
								% texture_height);

		*texelColor = floorTextures[0].
					  texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
		drawPixel(x, y, *texelColor);
	}
}
