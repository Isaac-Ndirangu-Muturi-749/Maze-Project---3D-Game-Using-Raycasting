#include <stdio.h>

// Function to perform floor-casting
void cast_floor_rays() {
    // Assume the bottom of the wall slices is at y-coordinate 200
    int bottom_wall_slice_y = 200;

    // Assume the bottom of the projection plane is at y-coordinate 200
    int bottom_projection_plane_y = 200;

    // Loop through each row of the projection plane in a downward direction
    for (int y = bottom_projection_plane_y; y < 320; y++) {
        // Cast a ray for each column of the projection plane
        for (int x = 0; x < 320; x++) {
            // Assume ray casting logic to find floor intersection and distance
            double distance_to_floor = ray_casting_to_floor(x, y);

            // Project the floor intersection onto the projection plane
            // (Here, we use printf to simulate drawing)
            printf("Pixel at (%d, %d): Floor drawn at distance %.2f\n", x, y, distance_to_floor);
        }
    }
}

// Function to simulate ray casting to find floor intersection and distance
double ray_casting_to_floor(int x, int y) {
    // Assume some ray casting logic to find floor intersection and distance
    // Here, we simply return a dummy distance based on the pixel coordinates
    return 277.0 / (y - 100); // Assume the distance is inversely proportional to the y-coordinate
}

int main() {
    // Perform floor-casting
    cast_floor_rays();

    return 0;
}
