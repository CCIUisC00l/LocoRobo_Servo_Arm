#include "Robot_operations.h"

void setup() {
// Attaching the servos to specific pins on the arduino
    set_servos();
    Serial.begin(115200); // starting the serial communications so we can print things about the execution of the program
}


int Lshape[5] = {0, 1620, 600, 0, 0}; // Will not affect the Base, Servo 4, or the Claw
int FullExtend[5] = {0, 700, 1550, 0, 0}; // Will not affect the Base, Servo 4, or the Claw

int Lshape_order[5] = {1, 2, 3, 0, 4}; // Specifies the order in which the script will start moving the servos
int FullExtend_order[5] = {0, 4, 3, 2, 1}; //


int halt = 500;

void robot_reset();
void delay(5000);

void loop(){


  MidBase;

  OpenClaw;
  mg(FullExtend, FullExtend_order); // Sets the robot to an "L" shape without affecting the angle or status of the claw
  delay(1000);
  CloseClaw;
  delay(1000);

  mg(Lshape, Lshape_order, halt);
  delay(500);
  ZeroBase;
  delay(500);

  mg(FullExtend, FullExtend_order);
  delay(500);
  OpenClaw;
  delay(1000);

  CloseClaw;
  mg(Lshape, Lshape_order, halt);
  delay(1000);

  Serial.println("Thus concludes the loop");

}
