#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOARD_LENGTH 5
#define HALF_BOARD_UNIT BOARD_LENGTH / 2
#define ARM_BASE_X 4
#define ARM_BASE_Y 30
#define PI 3.14159265

double convert_to_degrees(double radians) {
    double converter = 180.0 / PI;
    return radians * converter;
}

double pythagorean(double x, double y) {
    return sqrt((x * x) + (y * y));
}

void move_chessman(int *current_coordinates, int *target_coordinates) {
    int current_x = current_coordinates[0];
    int current_y = current_coordinates[1];
    int target_x = target_coordinates[0];
    int target_y = target_coordinates[1];

    double x, y, angle, hypotenuse;

    // TODO: determine the direction of angle (left or right) by comparing current_x and ARM_BASE_X
    x = abs(current_x - ARM_BASE_X) + HALF_BOARD_UNIT;
    y = current_y + ARM_BASE_Y + HALF_BOARD_UNIT;
    angle = convert_to_degrees(atan(x / y));
    hypotenuse = pythagorean(x, y);

}

int main() {
    int current_coordinates[2] = {2, 1};
    int target_coordinates[2] = {2, 3};
    move_chessman(current_coordinates, target_coordinates);
    return 0;
}
