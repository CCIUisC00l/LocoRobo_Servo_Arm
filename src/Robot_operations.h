#include <Servo.h>
#define is =
// Seting up 5 instances of servos
// Servo Base;
// Servo servo_2;
// Servo servo_3;
// Servo servo_4;
// Servo Claw;

// Serial.begin(115200); // Setting up a serial port

Servo Servos[5]; // Used in favor of the above system that is commented out
// This is because this list is indexable and thus the order of operations can be changed

#define Base Servos[0]
#define servo_2 Servos[1]
#define servo_3 Servos[2]
#define servo_4 Servos[3]
#define Claw Servos[4]

// Setting the variables corresponding to the pin that each servo is connected to 
int ser_1 = 3;
int ser_2 = 5;
int ser_3 = 6;
int ser_4 = 9;
int ser_5 = 10;
// Defining the position array to be used throughout the program
int pos[5] = {Base.readMicroseconds(), servo_2.readMicroseconds(), servo_3.readMicroseconds(), servo_4.readMicroseconds(), Claw.readMicroseconds()};

// This is a script to make the robot moving a specified set of coordinates
//
//  ---------------------------------------------------------
//  |                                                       |
//  |   This script is based on the arduino leonardo board  |
//  |                                                       |
//  ---------------------------------------------------------
//
// It sets up 5 servos which control the axes of the servo controlled robot

//              --------------------
//              | Axes of Movement |
//              --------------------
//
//              Servo 1:  Pin 3  (Base) axis 1
//                  The extremes of this sensor are writeMicroseconds(544), writeMicroseconds(2300)
                    #define ZeroBase Base.writeMicroseconds(400)
                    #define MaxBase Base.writeMicroseconds(2500)
//                    
//                  The middle is at writeMicroseconds(1400)
                    #define MidBase Base.writeMicroseconds(1350)
//
//              Servo 2:  Pin 5         axis 2
//                  The extremes of this sensor are writeMicroseconds(544), writeMicroseconds(2300)
                    #define Zero2 servo_2.writeMicroseconds(600)
                    #define Max2 servo_2.writeMicroseconds(2500)
                    
//                  The middle is at writeMicroseconds(1400)
                    #define Mid2 servo_2.writeMicroseconds(1620)
//                    
//              Servo 3:  Pin 6         axis 3
//                  The extremes of this sensor are writeMicroseconds(600), writeMicroseconds(2500)
                    #define Zero3 servo_3.writeMicroseconds(600)
                    #define Max3 servo_3.writeMicroseconds(2500)
                    
//                  The middle is at writeMicroseconds(1400)
                    #define Mid3 servo_3.writeMicroseconds(1550)
//
//              Servo 4:  Pin 9         axis 4
//                  The extremes of this servo are writeMicroseconds(100), writeMicroseconds(2700)
                    #define Zero4 servo_4.writeMicroseconds(100)
                    #define Max4 servo_4.writeMicroseconds(2700)
                
//                  The middle is at writeMicroseconds(1600)
                    #define Mid4 servo_4.writeMicroseconds(1600)
// 
//              Servo 5:  Pin 10 (Claw) axis 5   
//                  All the way open means writeMicroseconds(1500);
                    #define OpenClaw Claw.writeMicroseconds(1500)

//                  All the way closed means writeMicroseconds(1000);
                    #define CloseClaw Claw.writeMicroseconds(1000)
//
//
//              ---------------------
//              | Auxiliary Sensors |
//              ---------------------
//
//              Solar Cell: Seems to not be connected to the Arduino.
//
//              Light Sensor: Seems to not be connected to the Arduino.
//
//              Thermistor: Seems to not be connected to the Arduino.
//
//
//      We will move the robot by calling pre-defined motion groups as a list of microseconds to write to the robot
//
//                      ------------------------------------------------------------------
//                      |   Base    |   servo_2   |   servo_3   |   servo_4   |   Claw   |
//                      |-----------|-------------|-------------|-------------|----------|
//                      |   1200    |     900     |     2000    |     500     |   1000   |
//                      ------------------------------------------------------------------
//
//                      array = [1200, 900, 2000, 500, 1000];  // Makes an array to pass to the motion group funtion

//                      List of data must have a shape of 5. If you want to keep the current position of a servo,
//                      Set the 
//                                      
//                      mg(array);   // passing the array as a parameter to the mg function


// 
//  ------------------------------------------------
//  |   This Defines the Robot's Home Position     |
//  ------------------------------------------------

void set_servos();

void robot_reset();

void robot_reset(int wait);

void get_pos();

void print_pos();

void mg(int list[5]);

void mg(int list[5], int wait);

void mg(int list[5], int order[5]);

void mg(int list[5], int order[5], int wait);


void set_servos(){
    Base.attach(ser_1);
    servo_2.attach(ser_2);
    servo_3.attach(ser_3);
    servo_4.attach(ser_4);
    Claw.attach(ser_5);
}

void robot_reset(){
  MidBase;
  Mid2;
  Mid3;
  Mid4;
  OpenClaw;
  get_pos(); // Here we are storing the robot's current position to the position variables
  delay(1000);
}

void robot_reset(int wait){
  MidBase;
  Mid2;
  Mid3;
  Mid4;
  OpenClaw;
  get_pos(); // Here we are storing the robot's current position to the position variables
  delay(wait);
}

#define RESET robot_reset()

void get_pos(){
  pos[0] = Base.readMicroseconds();
  pos[1] = servo_2.readMicroseconds();
  pos[2] = servo_3.readMicroseconds();
  pos[3] = servo_4.readMicroseconds();
  pos[4] = Claw.readMicroseconds();
}

void print_pos(){
  get_pos();
  Serial.print(pos[0]);
  Serial.print(" ,");
  Serial.print(pos[1]);
  Serial.print(" ,");
  Serial.print(pos[2]);
  Serial.print(" ,");
  Serial.print(pos[3]);
  Serial.print(" ,");
  Serial.println(pos[4]);
  Serial.println("----------------------------");
}


// ----------------------------------------------------------------------
// |     Defining all of the mg functions with different parameters     |
// ----------------------------------------------------------------------

//      We will move the robot by calling pre-defined motion groups as a list of microseconds to write to the robot
//
//                      ------------------------------------------------------------------
//                      |   Base    |   servo_2   |   servo_3   |   servo_4   |   Claw   |
//                      |-----------|-------------|-------------|-------------|----------|
//                      |   1200    |     900     |     2000    |     500     |   1000   |
//                      ------------------------------------------------------------------
//
//                      array = [1200, 900, 2000, 500, 1000];  // Makes an array to pass to the motion group funtion

//                      List of data must have a shape of 5. If you want to keep the current position of a servo,
//                      Set the 
//                                      
//                      mg(array, order<optional> , wait<optional> );   // passing the array as a parameter to the mg function
// 
//                 ------------------------------------------------------------------------------
//                 |    PASSING A ZERO TO THE mg ARRAY RESULTS IN NO MOVEMENT ON THAT SERVO     |
//                 ------------------------------------------------------------------------------


void mg(int list[5]){ // This just takes the list and writes the motion group data to the servos.
                      // Still executes from Base to Claw

  Serial.println("-------- mg get pos --------");
  print_pos();
  
  int n_pos[5] = {0, 0, 0, 0, 0};
  for(int i=0; i<5; i++){
    
    if(list[i] != 0){
      n_pos[i] = list[i];
    }
    
    else{
      n_pos[i] = pos[i];
    }
    
  }

  Serial.println("--------New Position---------");
  Serial.print(n_pos[0]);
  Serial.print(" ,");
  Serial.print(n_pos[1]);
  Serial.print(" ,");
  Serial.print(n_pos[2]);
  Serial.print(" ,");
  Serial.print(n_pos[3]);
  Serial.print(" ,");
  Serial.println(n_pos[4]);
  Serial.println("------------------------------");

  
  for(int i=0; i<5; i++){
    Servos[i].writeMicroseconds(n_pos[i]);
    Serial.println(i);
  }
  
}

// ####################################################################################################

void mg(int list[5], int wait){ // This puts a delay in between the servo movements.
                                // Still executes from Base to Claw

  Serial.println("---------- mg get pos ------------");
  print_pos();
  
  int n_pos[5] = {0, 0, 0, 0, 0};
  for(int i=0; i<5; i++){
    
    if(list[i] != 0){
      n_pos[i] = list[i];
    }
    
    else{
      n_pos[i] = pos[i];
    }
    
  }

  Serial.println("--------New Position---------");
  Serial.print(n_pos[0]);
  Serial.print(" ,");
  Serial.print(n_pos[1]);
  Serial.print(" ,");
  Serial.print(n_pos[2]);
  Serial.print(" ,");
  Serial.print(n_pos[3]);
  Serial.print(" ,");
  Serial.println(n_pos[4]);
  Serial.println("------------------------------");

  
  for(int i=0; i<5; i++){
    Servos[i].writeMicroseconds(n_pos[i]);
    delay(wait);
    Serial.println(i);
  }
  
  
}

// ##############################################################################################################

void mg(int list[5], int order[5]){ // This takes writes the list array to the robot
                                    // Executes the movement in the order specified 
                                    // From the order array. The order list should have
                                    // the numbers 0, 1, 2, 3, and 4. 0 will move the base.
                                    // 4 will move the Claw.
                                    //------------------------------------------------------
                                    //                    Example
                                    //------------------------------------------------------

                                    // order = {3, 1, 2, 0, 4} will execute in the order:
                                    // servo_4, servo_2, servo_3, Base, Claw

  Serial.println("---------- mg get pos ------------");
  print_pos();
  
  int n_pos[5] = {0, 0, 0, 0, 0};
  for(int i=0; i<5; i++){
    
    if(list[i] != 0){
      n_pos[i] = list[i];
    }
    
    else{
      n_pos[i] = pos[i];
    }
    
  }

  Serial.println("--------New Position---------");
  Serial.print(n_pos[0]);
  Serial.print(" ,");
  Serial.print(n_pos[1]);
  Serial.print(" ,");
  Serial.print(n_pos[2]);
  Serial.print(" ,");
  Serial.print(n_pos[3]);
  Serial.print(" ,");
  Serial.println(n_pos[4]);
  Serial.println("------------------------------");

  
  for(int i=0; 1<5; i++){
    Servos[i].writeMicroseconds(n_pos[order[i]]);
  }
}

// ###################################################################################################################

void mg(int list[5], int order[5], int wait){ // This takes writes the list array to the robot
                                              // Executes the movement in the order specified 
                                              // From the order array. The order list should have
                                              // the numbers 0, 1, 2, 3, and 4. 0 will move the base.
                                              // 4 will move the Claw.
                                              //------------------------------------------------------
                                              //                    Example
                                              //------------------------------------------------------

                                              // order = {3, 1, 2, 0, 4} will execute in the order:
                                              // servo_4, servo_2, servo_3, Base, Claw

  Serial.println("---------- mg get pos ------------");
  print_pos();
  
  int n_pos[5] = {0, 0, 0, 0, 0};
  for(int i=0; i<5; i++){
    
    if(list[i] != 0){
      n_pos[i] = list[i];
    }
    
    else{
      n_pos[i] = pos[i];
    }
    
  }

  Serial.println("--------New Position---------");
  Serial.print(n_pos[0]);
  Serial.print(" ,");
  Serial.print(n_pos[1]);
  Serial.print(" ,");
  Serial.print(n_pos[2]);
  Serial.print(" ,");
  Serial.print(n_pos[3]);
  Serial.print(" ,");
  Serial.println(n_pos[4]);
  Serial.println("------------------------------");

  
  for(int i=0; i<5; i++){
    Serial.println(order[i]);
    Serial.println(i);
    Serial.println("-----------");
    Servos[order[i]].writeMicroseconds(n_pos[order[i]]);
    delay(wait);
  }
}