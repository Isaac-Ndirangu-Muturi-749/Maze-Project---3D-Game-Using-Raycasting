#include <math.h>

// Define constants for field of view and projection plane dimensions
#define FOV_DEGREES 60
#define PLANE_WIDTH 320
#define PLANE_HEIGHT 200
#define PLANE_CENTER_X 160
#define PLANE_CENTER_Y 100
#define PLANE_DISTANCE 277

// Function to correct fishbowl effect by multiplying distance by cosine of angle BETA
double correct_fishbowl_effect(double distance, double ray_angle) {
    double beta = ray_angle - (FOV_DEGREES / 2.0); // Calculate angle BETA relative to viewing angle
    double corrected_distance = distance * cos(beta); // Multiply distance by cosine of angle BETA
    return corrected_distance;
}

int main() {
    double distance_to_wall = 300; // Example distance obtained from ray-casting equation
    double ray_angle = 30; // Example angle of the ray relative to viewing angle (BETA)

    // Correct fishbowl effect
    double corrected_distance = correct_fishbowl_effect(distance_to_wall, ray_angle);

    printf("Distance before correction: %.2f\n", distance_to_wall);
    printf("Corrected distance after correction: %.2f\n", corrected_distance);

    return 0;
}
