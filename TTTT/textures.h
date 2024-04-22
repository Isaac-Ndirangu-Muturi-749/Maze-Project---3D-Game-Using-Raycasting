/* Functions-variables-structs for textures */

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

texture_t wallTextures[NUM_TEXTURES];

void WallTexturesready(void);
void freeWallTextures(void);
