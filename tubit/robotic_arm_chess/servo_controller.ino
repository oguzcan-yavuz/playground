#include <math.h>
#include <Servo.h>
#include <stdio.h>

#define BOARD_EDGE_LENGTH 4.8
#define ARM_BASE_X 4                                 // arm's location in the x axis when the x axis is considered as the horizontal diagonals of the chess board
#define ARM_BASE_Y (6.5 + 2.8) / BOARD_EDGE_LENGTH     // distance between the robotic arm and chess board
#define UPPER_ARM 18
#define FOREARM 16
#define HAND 14
#define MIN_FOREARM_ANGLE 90
#define MIN_UPPER_LEFT_ANGLE 110
#define MIN_UPPER_RIGHT_ANGLE 45
#define MIN_HAND_ANGLE 5
#define HYPOTENUSE_RANGE_POINT 20

// Servo objects
Servo base_servo, upper_arm_left_servo, upper_arm_right_servo, forearm_servo, hand_servo, finger_servo;

// Servo Pins
unsigned short base_servo_pin = 3;
unsigned short upper_arm_left_servo_pin = 4;
unsigned short upper_arm_right_servo_pin = 5;
unsigned short forearm_servo_pin = 6;
unsigned short hand_servo_pin = 7;
unsigned short finger_servo_pin = 8;

// ********** Calculation Functions **********

//double convert_to_radians(double degree) {
//  // converts degrees to radians
//  return degree * M_PI / 180;
//}

double convert_to_degrees(double rad) {
  // converts radians to degrees
  return rad * 180 / M_PI;
}

double pythagorean(double x, double y) {
  // finds hypotenuse
  return sqrt((x * x) + (y * y));
}

double find_x_distance(int x) {
  // x distance between the given x coordinate and robotic arm
  float half_board_unit = (x <= ARM_BASE_X) ? 0.5 : -0.5;
  return abs(x - ARM_BASE_X) + half_board_unit;
}

double find_y_distance(int y) {
  // y distance between the given y coordinate and robotic arm
  return (y + ARM_BASE_Y - 0.5);
}

double find_base_angle(int *coordinates, double x_distance, double y_distance) {
  // returns the angle required to move to the given coordinates
  // add 90 to the angle if x is on the left of the arm, else substract the angle from 90
  double angle = convert_to_degrees(atan(x_distance / y_distance));
  if(coordinates[0] <= ARM_BASE_X) {
    return 90 + angle;
  } else {
    return 90 - angle;
  }
}

double find_non_right_angle(double a, double b, double c) {
  // returns the angle of a non right triangle's edge
  return convert_to_degrees(acos((pow(a, 2) - (pow(b, 2) + pow(c, 2))) / (-2 * b * c)));
}

void debug_unreachable_coordinates() {
  // prints the coordinates which aren't reachable with triangle formulation
  double hypotenuse;
  double upper_arm_angle, forearm_angle;
  for(int i = 1; i <= 8; i++) {
    for(int j = 1; j <= 8; j++) {
      hypotenuse = pythagorean(find_x_distance(i), find_y_distance(j)) * BOARD_EDGE_LENGTH;
      upper_arm_angle = find_non_right_angle(FOREARM, UPPER_ARM, hypotenuse);
      forearm_angle = find_non_right_angle(hypotenuse, FOREARM, UPPER_ARM);
      if(isnan(upper_arm_angle) || isnan(forearm_angle) || forearm_angle < MIN_FOREARM_ANGLE || upper_arm_angle > MIN_UPPER_LEFT_ANGLE) {
        Serial.print(i);
        Serial.print(", ");
        Serial.print(j);
        Serial.print("    Hypotenuse: ");
        Serial.println(hypotenuse);
      }
    }
  }
}

bool is_reachable(double upper_arms_angle, double forearm_angle) {
  // returns true if the given angles are in range when arm is in a triangle form
  return !(isnan(upper_arms_angle) || isnan(forearm_angle) || forearm_angle < MIN_FOREARM_ANGLE || upper_arms_angle > MIN_UPPER_LEFT_ANGLE);
}

// ********** Movement functions **********
// TODO: complete this functions

void move_base_servo(double angle) {
  // moves the base_servo
  base_servo.write(angle);
  delay(1000);
}

void move_to_close_range(double h, int y_coordinate) {
  // moves the arm to the close range areas
  Serial.println("Close range called!");
  double upper_arm_servos_angle = 45;
  double forearm_servo_angle = 90;
  double hand_servo_angle;
  // TODO: check the Y axis and change hand_servo angle based on that
  upper_arm_left_servo.write(MIN_UPPER_LEFT_ANGLE + upper_arm_servos_angle);
  delay(1);
  upper_arm_right_servo.write(MIN_UPPER_RIGHT_ANGLE - upper_arm_servos_angle);
  delay(1000);
  hand_servo.write(hand_servo_angle);
  delay(1000);
  forearm_servo.write(forearm_servo_angle - MIN_FOREARM_ANGLE);
  delay(1);
}

void move_to_mid_range(double upper_arm_angle, double forearm_angle) {
  // moves the arm to the areas where arm can reach while in a triangle form
  // TODO: determine the angle of hand_servo.
  Serial.println("Mid range called!");
  double hand_servo_angle;
  upper_arm_left_servo.write(MIN_UPPER_LEFT_ANGLE + upper_arm_angle);
  delay(1);
  upper_arm_right_servo.write(MIN_UPPER_RIGHT_ANGLE - upper_arm_angle);
  delay(1000);
  hand_servo.write(hand_servo_angle);
  delay(1000);
  forearm_servo.write(forearm_angle - MIN_FOREARM_ANGLE);
  delay(1);
  
}

void move_to_long_range(double h, int y_coordinate) {
  // moves the arm to the long ranges where arm needs to be in a vertical form
  Serial.println("Long range called!");
  double upper_arm_servos_angle = 0;
  double forearm_servo_angle = 180;
  double hand_servo_angle;
  if(y_coordinate >= 7) {
    hand_servo_angle = 80;    // it is aligned vertically at 80 degrees
  } else {
    hand_servo_angle = 30;
  }
  upper_arm_left_servo.write(MIN_UPPER_LEFT_ANGLE + upper_arm_servos_angle);
  delay(1);
  upper_arm_right_servo.write(MIN_UPPER_RIGHT_ANGLE - upper_arm_servos_angle);
  delay(1000);
  hand_servo.write(hand_servo_angle);
  delay(1000);
  forearm_servo.write(forearm_servo_angle - MIN_FOREARM_ANGLE);
  delay(1);
}

// TODO: finger servo functions for grabbing and dropping chessmans
//void grab() {
//  
//}
//
//void drop() {
//  
//}

// ********** Main Functions **********

void move_chessman(int *coordinates) {
  double x_distance = find_x_distance(coordinates[0]);
  double y_distance = find_y_distance(coordinates[1]);
  double angle, hypotenuse;
  angle = find_base_angle(coordinates, x_distance, y_distance);
  Serial.print("Given x: ");
  Serial.println(coordinates[0]);
  Serial.print("Given y: ");
  Serial.println(coordinates[1]);
  Serial.print("x dist: ");
  Serial.println(x_distance);
  Serial.print("y dist: ");
  Serial.println(y_distance);
  Serial.print("Base angle: ");
  Serial.println(angle);
  hypotenuse = pythagorean(x_distance, y_distance) * BOARD_EDGE_LENGTH;
  Serial.print("Hypotenuse: ");
  Serial.println(hypotenuse);
  // move_base_servo(angle);
    
  // distance calculations
  double upper_arm_servos_angle = find_non_right_angle(FOREARM, UPPER_ARM, hypotenuse);
  double forearm_servo_angle = find_non_right_angle(hypotenuse, FOREARM, UPPER_ARM);

  // TODO: Determine if the hypotenuse is in close, mid or long range by considering unreachable coordinates and y axis. call the proper function.
    
  Serial.print("Upper arm servo angle: ");
  Serial.println(upper_arm_servos_angle);
  Serial.print("Forearm servo angle: ");
  Serial.println(forearm_servo_angle);

  // TODO: check if the hypotenuse is in mid range, if not; determine the range of the hypotenuse
  if(is_reachable(upper_arm_servos_angle, forearm_servo_angle)) {
    move_to_mid_range(upper_arm_servos_angle, forearm_servo_angle);
  } else {
    if(coordinates[1] > 4) {
      move_to_long_range(hypotenuse, coordinates[1]);
    } else {
      move_to_close_range(hypotenuse, coordinates[1]);
    }
  }

  
  // move upper arm and forearm servos
    
//  upper_arm_left_servo.write(155);
//  delay(1);
//  upper_arm_right_servo.write(0);
//  delay(1000);
//  upper_arm_right_servo.detach();
//  forearm_servo.write(forearm_servo_angle);
//  forearm_servo.write(90);
//  delay(1000);
//  hand_servo.write(80);
//  delay(1000);
//  move_to_long_range(coordinates[1]);
//  forearm_servo.write(90);
//  delay(1000);
}

void setup() {
  Serial.begin(9600);
  // Attach the servos to the used pins
//  base_servo.attach(base_servo_pin);
//  upper_arm_left_servo.attach(upper_arm_left_servo_pin);
//  upper_arm_right_servo.attach(upper_arm_right_servo_pin);
//  forearm_servo.attach(forearm_servo_pin);
//  hand_servo.attach(hand_servo_pin);
//  finger_servo.attach(finger_servo_pin);
  // set the starter angle of the base_servo to 90
//  move_base_servo(90);

  // doing random stuff after this line
  int current[2] = {4, 4};
  int target[2] = {2, 4};
  move_chessman(current);
//  move_chessman(target);
  debug_unreachable_coordinates();
}

void loop() {
  // write function rotates the servo at given degree
}


