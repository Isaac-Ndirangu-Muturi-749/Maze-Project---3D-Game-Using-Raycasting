#include "../headers/render.h"


/**
 * render - calls all functions needed for on-screen rendering
 *
*/
void render_game(void)
{
	clearColorBuffer(0xFF000000);

	renderWall();

	renderMap();
	renderRays();
	renderPlayer();

	renderColorBuffer();
}


/**
 * renderColorBuffer - render buffer for every frame
 *
*/
void renderColorBuffer(void)
{
	SDL_UpdateTexture(
		colorBufferTexture,
		NULL,
		colorBuffer,
		(int)(SCREEN_WIDTH * sizeof(color_t))
	);
	SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}


/**
 * clearColorBuffer - clear buffer for every frame
 * @color: color buffer
*/
void clearColorBuffer(color_t color)
{
	int i;

	for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		colorBuffer[i] = color;
}


/**
 * renderMap - render the map
 *
*/
void renderMap(void)
{
	int i, j, tileX, tileY;
	color_t tileColor;

	for (i = 0; i < MAP_NUM_ROWS; i++)
	{
		for (j = 0; j < MAP_NUM_COLS; j++)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			tileColor = map[i][j] != 0 ? 0xFFFFFFFF : 0x00000000;

			drawRect(
				tileX * MINIMAP_SCALE_FACTOR,
				tileY * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				TILE_SIZE * MINIMAP_SCALE_FACTOR,
				tileColor
			);
		}
	}
}


/**
 * renderRays - draw all the rays
 *
 */
void renderRays(void)
{
	int i;

	for (i = 0; i < NUM_RAYS; i += 50)
	{
		drawLine(
			player.x * MINIMAP_SCALE_FACTOR,
			player.y * MINIMAP_SCALE_FACTOR,
			rays[i].wallHitX * MINIMAP_SCALE_FACTOR,
			rays[i].wallHitY * MINIMAP_SCALE_FACTOR,
			0xFF0000FF
		);
	}
}


/**
 * renderPlayer - render the player
 *
*/
void renderPlayer(void)
{
	drawRect(
		player.x * MINIMAP_SCALE_FACTOR,
		player.y * MINIMAP_SCALE_FACTOR,
		player.width * MINIMAP_SCALE_FACTOR,
		player.height * MINIMAP_SCALE_FACTOR,
		0xFFFFFFFF
	);
}



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

	texture_width = wallTextures[3].width;
	texture_height = wallTextures[3].height;

	for (y = wallBottomPixel - 1; y < SCREEN_HEIGHT; y++)
	{
		ratio = player.height / (y - SCREEN_HEIGHT / 2);
		distance = (ratio * PROJ_PLANE)
					/ cos(rays[x].rayAngle - player.rotationAngle);

		textureOffsetY = (int)abs((distance * sin(rays[x].rayAngle)) + player.y);
		textureOffsetX = (int)abs((distance * cos(rays[x].rayAngle)) + player.x);

		textureOffsetX = (int)(abs(textureOffsetX * texture_width / 30)
								% texture_width);
		textureOffsetY = (int)(abs(textureOffsetY * texture_height / 30)
								% texture_height);

		*texelColor = wallTextures[3].
					  texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
		drawPixel(x, y, *texelColor);
	}
}


/**
 * renderCeil - render Ceil projection
 * @WallTopPixel: wall top pixel
 * @texelColor: texture color for current pixel
 * @x: current element in the rays array
*/
void renderCeil(int wallTopPixel, color_t *texelColor, int x)
{
	int y, texture_width, texture_height, textureOffsetY, textureOffsetX;

	texture_width = wallTextures[3].width;
	texture_height = wallTextures[3].height;

	for (y = 0; y < wallTopPixel; y++)
	{
		float distance, ratio;

		ratio = player.height / (y - SCREEN_HEIGHT / 2);
		distance = (ratio * PROJ_PLANE)
					/ cos(rays[x].rayAngle - player.rotationAngle);

		textureOffsetY = (int)abs((-distance * sin(rays[x].rayAngle)) + player.y);
		textureOffsetX = (int)abs((-distance * cos(rays[x].rayAngle)) + player.x);

		textureOffsetX = (int)(abs(textureOffsetX * texture_width / 40)
								% texture_width);
		textureOffsetY = (int)(abs(textureOffsetY * texture_height / 40)
								% texture_height);

		*texelColor = wallTextures[7].
					  texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
		drawPixel(x, y, *texelColor);

	}
}


/**
 * renderWall - render wall projection
 *
*/
void renderWall(void)
{
	int x, y, texNum, texture_width, texture_height,
		textureOffsetX, wallBottomPixel, wallStripHeight,
		wallTopPixel, distanceFromTop, textureOffsetY;
	float perpDistance, projectedWallHeight;
	color_t texelColor;

	for (x = 0; x < NUM_RAYS; x++)
	{
		perpDistance = rays[x].distance * cos(rays[x].rayAngle
							- player.rotationAngle);
		projectedWallHeight = (TILE_SIZE / perpDistance) * PROJ_PLANE;
		wallStripHeight = (int)projectedWallHeight;
		wallTopPixel = (SCREEN_HEIGHT / 2) - (wallStripHeight / 2);
		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
		wallBottomPixel = (SCREEN_HEIGHT / 2) + (wallStripHeight / 2);
		wallBottomPixel = wallBottomPixel > SCREEN_HEIGHT
							? SCREEN_HEIGHT : wallBottomPixel;
		texNum = rays[x].wallHitContent - 1;
		texture_width = wallTextures[texNum].width;
		texture_height = wallTextures[texNum].height;
		renderFloor(wallBottomPixel, &texelColor, x);
		renderCeil(wallTopPixel, &texelColor, x);

		if (rays[x].wasHitVertical)
			textureOffsetX = (int)rays[x].wallHitY % TILE_SIZE;
		else
			textureOffsetX = (int)rays[x].wallHitX % TILE_SIZE;

		for (y = wallTopPixel; y < wallBottomPixel; y++)
		{
			distanceFromTop = y + (wallStripHeight / 2) - (SCREEN_HEIGHT / 2);
			textureOffsetY = distanceFromTop *
								((float)texture_height / wallStripHeight);
			texelColor = wallTextures[texNum].
						 texture_buffer[(texture_width * textureOffsetY) + textureOffsetX];
			if (rays[x].wasHitVertical)
				changeColorIntensity(&texelColor, 0.5);
			drawPixel(x, y, texelColor);
		}
	}
}
