int LED_BUILTIN = 2; // o cambiar a 13 si es arduino
String Marked_servo = "";
int angulo = 0;


#include <ESP32Servo.h>

Servo myservo1, myservo2, myservo3, myservo4, myservo5, myservo6; // create servo object to control a servo
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33
int servo1_2 = 15;
int servo2_5 = 2;
int servo3_4 = 4;
int servo4_15 = 5;
int servo5_22 = 22;
int servo6_23 = 23;
int j = 0;

void setup() {
  Serial.begin(115200); // opens serial port, sets data rate to 115200 bps
  pinMode(LED_BUILTIN, OUTPUT);
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo1.setPeriodHertz(50);    // standard 50 hz servo
  myservo2.setPeriodHertz(50);    // standard 50 hz servo
  myservo3.setPeriodHertz(50);    // standard 50 hz servo

  myservo1.attach(servo1_2, 500, 2400);
  myservo2.attach(servo2_5, 500, 2400);
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
  // send data only when you receive data:

  
  if (Serial.available() > 0) {

    Marked_servo = Serial.readStringUntil('\n');
    Marked_servo = Marked_servo.substring(0,1); 
    Serial.println(Marked_servo);

     if(Marked_servo == "a"){ 
      
          myservo1.write(90);
          myservo2.write(90);
          myservo3.write(90);
          myservo4.write(90);
          myservo5.write(90);
          myservo6.write(90);
          delay(50);
      }

      if(Marked_servo == "b"){ 
          myservo1.write(180);
          myservo2.write(120);
          myservo3.write(90);
          myservo4.write(45);
          myservo5.write(90);
          myservo6.write(90);
          delay(50);
      }
    if(Marked_servo == "c"){ 
          myservo1.write(180);
          myservo2.write(130);
          myservo3.write(45);
          myservo4.write(45);
          myservo5.write(0);
          myservo6.write(90);
          delay(50);
      } 
      if(Marked_servo == "d"){ 
          myservo1.write(180);
          myservo2.write(130);
          myservo3.write(45);
          myservo4.write(45);
          myservo5.write(90);
          myservo6.write(90);
    delay(50);
      } 
       if(Marked_servo == "e"){ 
            myservo1.write(180);
          myservo2.write(130);
          myservo3.write(45);
          myservo4.write(45);
          myservo5.write(90);
          myservo6.write(20);
    delay(50);
      } 
         if(Marked_servo == "f"){ 
            myservo1.write(0);
           myservo2.write(130);
          myservo3.write(45);
          myservo4.write(45);
          myservo5.write(90);
          myservo6.write(20);
    delay(50);
      } 
         if(Marked_servo == "g"){
           myservo1.write(0);
           myservo2.write(130);
          myservo3.write(45);
          myservo4.write(45);
          myservo5.write(90);
          myservo6.write(90);
    delay(50);
      } 
       if(Marked_servo == "h"){ 
      
          myservo1.write(90);
          myservo2.write(90);
          myservo3.write(90);
          myservo4.write(90);
          myservo5.write(90);
          myservo6.write(90);
          delay(50);
      }

    delay(500);


  }
}
