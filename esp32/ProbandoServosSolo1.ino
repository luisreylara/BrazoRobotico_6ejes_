

#include <ESP32Servo.h>

Servo myservo1, myservo2,myservo3,myservo4, myservo5,myservo6;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servo1_2 = 2;
int servo2_3 = 3;
int servo3_4 = 4;
int servo4_15 = 15;
int servo5_22 = 22;
int servo6_23 = 23;

void setup() {
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo1.setPeriodHertz(50);    // standard 50 hz servo
  myservo2.setPeriodHertz(50);    // standard 50 hz servo
  myservo3.setPeriodHertz(50);    // standard 50 hz servo
  
  myservo1.attach(servo1_2, 500, 2400);
  myservo2.attach(servo2_3, 500, 2400);
  myservo3.attach(servo3_4, 500, 2400);
  myservo4.attach(servo4_15, 500, 2400);
  myservo5.attach(servo5_22, 500, 2400);
  myservo6.attach(servo6_23, 500, 2400);
  
  // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
}

void loop() {

  for (pos = 0; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);    // tell servo to go to position in variable 'pos'
    delay(500);             // waits 15ms for the servo to reach the position
  }
 
 
  
   for (pos = 180; pos >= 0; pos -= 2) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);    // tell servo to go to position in variable 'pos'
    delay(500);             // waits 15ms for the servo to reach the position
  }
 
  
}
