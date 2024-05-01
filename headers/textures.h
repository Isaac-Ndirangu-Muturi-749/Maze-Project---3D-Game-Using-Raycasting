#ifndef TEXTURES_H
#define TEXTURES_H

#include "upng.h"
#include "main.h"

#include <stdint.h>
typedef uint32_t color_t;

// Constants
#define NUM_TEXTURES 9
#define NUM_WEAPONS 1


/**
 * struct texture_s - struct for the textures
 * @width: texture width
 * @height: texture height
 * @texture_buffer: pointer to texture buffer
 * @upngTexture: pointer to upng buffer
 *
 */
typedef struct texture_s
{
	int width;
	int height;
	color_t *texture_buffer;
	upng_t *upngTexture;
} texture_t;

// Global array to store textures
extern texture_t wallTextures[NUM_TEXTURES];
extern const char *textureFileNames[NUM_TEXTURES];
extern texture_t weaponTextures[NUM_WEAPONS];
extern const char *WeaponTextureFileNames[NUM_WEAPONS];

// Function prototypes
void WallTexturesready(void);
void freeWallTextures(void);
void WeaponTexturesready(void);
void freeWeaponTextures(void);

#endif /* TEXTURES_H */
