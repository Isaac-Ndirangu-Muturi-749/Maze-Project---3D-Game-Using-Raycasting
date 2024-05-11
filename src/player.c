#include "../headers/player.h"

// Structure to store player information
player_t player;

// Function to initialize player properties
void initializePlayer(void) {
    // Set initial player position at the center of the window
    player.x = WINDOW_WIDTH / 2;
    player.y = WINDOW_HEIGHT / 2;
    // Set player dimensions
    player.width = 1;
    player.height = 30;
    // Set initial movement and turning directions and speeds
    player.walkDirection = 0;
    player.walkSpeed = 100;
    player.turnDirection = 0;
    player.turnSpeed = 45 * (PI / 180); // Convert degrees to radians
    // Set initial rotation angle
    player.rotationAngle = PI / 2;
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
 * movePlayer - set the next position of the player
 * @DeltaTime: time elapsed since the last frame
*/
void movePlayer(float DeltaTime)
{
	float moveStep, newPlayerX, newPlayerY;

	player.rotationAngle += player.turnDirection * player.turnSpeed * DeltaTime;
	moveStep = player.walkDirection * player.walkSpeed * DeltaTime;

	newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
	newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

	if (!DetectCollision(newPlayerX, newPlayerY))
	{
		player.x = newPlayerX;
		player.y = newPlayerY;
	}
}
