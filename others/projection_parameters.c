// projection_parameters.c

#include <stdio.h>

// Define constants for projection plane dimensions
#define PLANE_WIDTH 320
#define PLANE_HEIGHT 200

// Define constants for projection plane center
#define PLANE_CENTER_X 160
#define PLANE_CENTER_Y 100

// Define constant for distance to projection plane
#define PLANE_DISTANCE 277

// Calculate angle between subsequent rays
#define ANGLE_BETWEEN_RAYS (60.0 / PLANE_WIDTH)

int main() {
    printf("Dimension of the Projection Plane: %d x %d units\n", PLANE_WIDTH, PLANE_HEIGHT);
    printf("Center of the Projection Plane: (%d, %d)\n", PLANE_CENTER_X, PLANE_CENTER_Y);
    printf("Distance to the Projection Plane: %d units\n", PLANE_DISTANCE);
    printf("Angle between subsequent rays: %.2f degrees\n", ANGLE_BETWEEN_RAYS);

    return 0;
}
