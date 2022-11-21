//Programmed by KyberBeros, inspired by Howtomechatronics.com
//SERVO LIBRARY
//#include <Servo.h>
//Libreria ESP32_Servo.h para ESP32
#include <ESP32_Servo.h>

#include "BluetoothSerial.h"

// Bluetooth Serial object
BluetoothSerial SerialBT;

//SERVO AXISES
Servo Axis1, Axis2, Axis3, Axis4, Axis5, Axis6;

//INITIAL POSITIONS
int InitPosAxis1 = 90;
int InitPosAxis2 = 80;
int InitPosAxis3 = 110;
int InitPosAxis4 = 0;
int InitPosAxis5 = 90;
int InitPosAxis6 = 90;

// Handle received and sent messages
String message = "";
char incomingChar;
unsigned long tiempoini=0;
// Timer: auxiliar variables
unsigned long previousMillis = 0;    // Stores last time temperature was published
const long interval = 10000;         // interval at which to publish sensor readings
unsigned long currentMillis = millis();


//CURRENT POSITIONS
int current_posAxis1,current_posAxis2,current_posAxis3,current_posAxis4,current_posAxis5,current_posAxis6;

//SAVED POSITIONS
int Axis1Pos_saved[9],Axis2Pos_saved[9],Axis3Pos_saved[9],Axis4Pos_saved[9],Axis5Pos_saved[9],Axis6Pos_saved[9];

//STRINGS FOR BLUETOOTH COMMUNICATIONS
String data_from_Bluetooth = "";
String Marked_servo = "";
String angle_from_Bluetooth_String = "";
int angle_from_Bluetooth = 90;

//NUMBER OF REPEATINGS PER THE PATH
String number_of_repeatings_the_path_String = "";
int number_of_repeatings_the_path = 0;

//ARE THOSE AXISES SAVED?
bool Axises_saved[9] = {false};

void setup() {
  Serial.begin(9600); //Begin of serial communication
  Axis1.attach(4); Axis2.attach(32); Axis3.attach(33); Axis4.attach(34); Axis5.attach(35); Axis6.attach(36); //Axises attaching to pins
  Back_to_Init_pos(); //Set robot to initial position
  Axis1Pos_saved[9] = {InitPosAxis1}; 
  Axis2Pos_saved[9] = {InitPosAxis2}; 
  Axis3Pos_saved[9] = {InitPosAxis3}; 
  Axis4Pos_saved[9] = {InitPosAxis4}; 
  Axis5Pos_saved[9] = {InitPosAxis5}; 
  Axis6Pos_saved[9] = {InitPosAxis6};

  SerialBT.begin("MiRobot");
  Serial.println("The device started, now you can pair it with bluetooth!");
  tiempoini = millis();

}


void loop() {
  currentMillis = millis();
  if (SerialBT.available() > 0) {
    //STRING LOAD FROM BLUETOOTH
    data_from_Bluetooth = SerialBT.readStringUntil('\n');
  }

   
    
    //STRINGS FOR ROBOT SET UP
    Marked_servo = data_from_Bluetooth.substring(0,2); 
   //Serial.println(Marked_servo);
    angle_from_Bluetooth_String = data_from_Bluetooth.substring(2,data_from_Bluetooth.length()); 
    angle_from_Bluetooth = angle_from_Bluetooth_String.toInt(); //120 in String => 120 in Int
    
    //SETTING UP ROBOT TO ANY POSITION----------------------------------------------------------------------------------------------------------
    if(Marked_servo == "s1"){    
      Serial.printl("--> S1--->");
      Serial.printl("angle_from_Bluetooth");
      Serial.println(angle_from_Bluetooth);
      AXIS1_func(angle_from_Bluetooth,20);
      data_from_Bluetooth = "";
      Marked_servo = "";
      angle_from_Bluetooth_String = "";
      angle_from_Bluetooth = 90;
      }
      
    if(Marked_servo == "s2"){     
      AXIS2_func(angle_from_Bluetooth,20);
      data_from_Bluetooth = "";
      Marked_servo = "";
      angle_from_Bluetooth_String = "";
      angle_from_Bluetooth = 90;
      }
      
    if(Marked_servo == "s3"){     
      AXIS3_func(angle_from_Bluetooth,20);
      data_from_Bluetooth = "";
      Marked_servo = "";
      angle_from_Bluetooth_String = "";
      angle_from_Bluetooth = 90;
      }
    if(Marked_servo == "s4"){     
      AXIS4_func(angle_from_Bluetooth,10);
      data_from_Bluetooth = "";
      Marked_servo = "";
      angle_from_Bluetooth_String = "";
      angle_from_Bluetooth = 90;
      }
    if(Marked_servo == "s5"){     
      AXIS5_func(angle_from_Bluetooth,20);
      data_from_Bluetooth = "";
      Marked_servo = "";
      angle_from_Bluetooth_String = "";
      angle_from_Bluetooth = 90;
      }
    if(Marked_servo == "s6"){     
      AXIS6_func(angle_from_Bluetooth,20);
      data_from_Bluetooth = "";
      Marked_servo = "";
      angle_from_Bluetooth_String = "";
      angle_from_Bluetooth = 90;
      }
    //----------------------------------------------------------------------------------------------------------------------------------------

//WRITE TO SAVING SLOTS      
    if(data_from_Bluetooth == "Save_pos1"){     
      Save_pos(0); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos2"){     
      Save_pos(1); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos3"){     
      Save_pos(2); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos4"){     
      Save_pos(3); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos5"){     
      Save_pos(4); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos6"){     
      Save_pos(5); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos7"){     
      Save_pos(6); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos8"){     
      Save_pos(7); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Save_pos9"){     
      Save_pos(8); 
      data_from_Bluetooth = "";
      }
      
//SEND ROBOT TO SAVED POSITION
  if(data_from_Bluetooth == "POSITION1"){  
      Serial.println("-->POSITION1");    
      Move_to_saved_positions(0); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION2"){     
      Move_to_saved_positions(1); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION3"){     
      Move_to_saved_positions(2); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION4"){     
      Move_to_saved_positions(3); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION5"){     
      Move_to_saved_positions(4); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION6"){     
      Move_to_saved_positions(5); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION7"){     
      Move_to_saved_positions(6); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION8"){     
      Move_to_saved_positions(7); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "POSITION9"){     
      Move_to_saved_positions(8); 
      data_from_Bluetooth = "";
      }

//SLOT DELETE EACH BY EACH (INDIVIDUALLY)
    if(data_from_Bluetooth == "Delete_pos_1"){     
      Delete_Positions1_9(0); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_2"){     
      Delete_Positions1_9(1); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_3"){     
      Delete_Positions1_9(2); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_4"){     
      Delete_Positions1_9(3); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_5"){     
      Delete_Positions1_9(4); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_6"){     
      Delete_Positions1_9(5); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_7"){     
      Delete_Positions1_9(6); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_8"){     
      Delete_Positions1_9(7); 
      data_from_Bluetooth = "";
      }
    if(data_from_Bluetooth == "Delete_pos_9"){     
      Delete_Positions1_9(8); 
      data_from_Bluetooth = "";
      }

//SLOT DELETE ALL TOGETHER
    if(data_from_Bluetooth == "DELETE_ALL_POS"){     
      DELETE_ALL(); 
      data_from_Bluetooth = "";
      }

      
//SEND ROBOT BACK TO INIT POSITION
    if(data_from_Bluetooth == "Return"){     
      Back_to_Init_pos(); 
      data_from_Bluetooth = "";
      }


// THE PATH MODE  
    if(data_from_Bluetooth.substring(0,8) = "THE_PATH"){ //Do the path between points
        number_of_repeatings_the_path_String = data_from_Bluetooth.substring(8,data_from_Bluetooth.length());
        number_of_repeatings_the_path = number_of_repeatings_the_path_String.toInt();
        THE_PATH();
        number_of_repeatings_the_path_String = "";
        number_of_repeatings_the_path = 0;
        data_from_Bluetooth = "";        
      }
   delay(50);
    } 


void Save_pos(int cislo_pozice){ 
  Axis1Pos_saved[cislo_pozice] = current_posAxis1;
  Axis2Pos_saved[cislo_pozice] = current_posAxis2;
  Axis3Pos_saved[cislo_pozice] = current_posAxis3;
  Axis4Pos_saved[cislo_pozice] = current_posAxis4;
  Axis5Pos_saved[cislo_pozice] = current_posAxis5;
  Axis6Pos_saved[cislo_pozice] = current_posAxis6;
  Axises_saved[cislo_pozice] = true;
  }
  
void Move_to_saved_positions(int cislo_pozice){
  AXIS1_func(Axis1Pos_saved[cislo_pozice],20);
  delay(500);
  AXIS2_func(Axis2Pos_saved[cislo_pozice],20);
  delay(500);
  AXIS3_func(Axis3Pos_saved[cislo_pozice],20);
  delay(500);
  AXIS4_func(Axis4Pos_saved[cislo_pozice],10);
  delay(500);
  AXIS5_func(Axis5Pos_saved[cislo_pozice],20);
  delay(500);
  AXIS6_func(Axis6Pos_saved[cislo_pozice],20);
  delay(500);
  }

void Delete_Positions1_9(int cislo_pozice){
  Axis1Pos_saved[cislo_pozice] = InitPosAxis1;
  Axis2Pos_saved[cislo_pozice] = InitPosAxis2;
  Axis3Pos_saved[cislo_pozice] = InitPosAxis3;
  Axis4Pos_saved[cislo_pozice] = InitPosAxis4;
  Axis5Pos_saved[cislo_pozice] = InitPosAxis5;
  Axis6Pos_saved[cislo_pozice] = InitPosAxis6;
  Axises_saved[cislo_pozice] = false;
  }

void DELETE_ALL(){
  for(int i = 0; i<9;i++){
    Axis1Pos_saved[i] = InitPosAxis1;
    Axis2Pos_saved[i] = InitPosAxis2;
    Axis3Pos_saved[i] = InitPosAxis3;
    Axis4Pos_saved[i] = InitPosAxis4;
    Axis5Pos_saved[i] = InitPosAxis5;
    Axis6Pos_saved[i] = InitPosAxis6;
    Axises_saved[i] = false;
    } 
  }

//Realizing THE PATH
void THE_PATH(){
  for(int i = 0; i<number_of_repeatings_the_path;i++){
    for(int j = 0; j<9;j++){
      if(Axises_saved[j] == true){      
        AXIS1_func(Axis1Pos_saved[j],20);
        delay(500);
  
        AXIS2_func(Axis2Pos_saved[j],20);
        delay(500);
   
        AXIS3_func(Axis3Pos_saved[j],20);
        delay(500);
   
        AXIS4_func(Axis4Pos_saved[j],20);
        delay(500);

        AXIS5_func(Axis5Pos_saved[j],20);
        delay(500);
 
        AXIS6_func(Axis6Pos_saved[j],20);
        delay(500);
        }     
      }
    }
  }

//BACK TO INITIAL POSITION FUNCTION
void Back_to_Init_pos(){
  current_posAxis1 = InitPosAxis1;
  AXIS1_func(current_posAxis1,20);
  delay(500);
  
  current_posAxis2 = InitPosAxis2;
  AXIS2_func(current_posAxis2,20);
  delay(500);
   
  current_posAxis3 = InitPosAxis3;
  AXIS3_func(current_posAxis3,20);
  delay(500);
   
  current_posAxis4 = InitPosAxis4;
  AXIS4_func(current_posAxis4,20);
  delay(500);

  current_posAxis5 = InitPosAxis5;
  AXIS5_func(current_posAxis5,20);
  delay(500);
  
  current_posAxis6 = InitPosAxis6;
  AXIS6_func(current_posAxis6,20);
  delay(500);
}

//ROBOT MOVING FUNCTIONS AXIS1 - AXIS6
void AXIS1_func(int aPos, int aRychlost)
{
  Serial.print("Apos: ");
  Serial.println(aPos);
  Serial.print("current_posAxis1: ");
  Serial.println(current_posAxis1);
  if(aPos>current_posAxis1){
    for (int pos = current_posAxis1; pos <= aPos; pos++) { 
    Axis1.write(pos);             
    delay(aRychlost);
    current_posAxis1++;                       
         }
  }else{
    
    for (int pos = current_posAxis1; pos >= aPos; pos--) { 
    Axis1.write(pos);             
    delay(aRychlost); 
    current_posAxis1--;                      
         }
      }
}
void AXIS2_func(int aPos, int aRychlost)
{
  if(aPos>current_posAxis2){
    for (int pos = current_posAxis2; pos <= aPos; pos++) { 
    Axis2.write(pos);             
    delay(aRychlost);
    current_posAxis2++;                       
         }
  }else{
    
    for (int pos = current_posAxis2; pos >= aPos; pos--) { 
    Axis2.write(pos);             
    delay(aRychlost); 
    current_posAxis2--;                      
         }
      }
}
void AXIS3_func(int aPos, int aRychlost)
{
  if(aPos>current_posAxis3){
    for (int pos = current_posAxis3; pos <= aPos; pos++) { 
    Axis3.write(pos);             
    delay(aRychlost);
    current_posAxis3++;                       
         }
  }else{
    
    for (int pos = current_posAxis3; pos >= aPos; pos--) { 
    Axis3.write(pos);             
    delay(aRychlost); 
    current_posAxis3--;                      
         }
      }
}
void AXIS4_func(int aPos, int aRychlost)
{
  if(aPos>current_posAxis4){
    for (int pos = current_posAxis4; pos <= aPos; pos++) { 
    Axis4.write(pos);             
    delay(aRychlost);
    current_posAxis4++;                       
         }
  }else{
    
    for (int pos = current_posAxis4; pos >= aPos; pos--) { 
    Axis4.write(pos);             
    delay(aRychlost); 
    current_posAxis4--;                      
         }
      }
}
void AXIS5_func(int aPos, int aRychlost)
{
  if(aPos>current_posAxis5){
    for (int pos = current_posAxis5; pos <= aPos; pos++) { 
    Axis5.write(pos);             
    delay(aRychlost);
    current_posAxis5++;                       
         }
  }else{
    
    for (int pos = current_posAxis5; pos >= aPos; pos--) { 
    Axis5.write(pos);             
    delay(aRychlost); 
    current_posAxis5--;                      
         }
      }
}
void AXIS6_func(int aPos, int aRychlost)
{
  if(aPos>current_posAxis6){
    for (int pos = current_posAxis6; pos <= aPos; pos++) { 
    Axis6.write(pos);             
    delay(aRychlost);
    current_posAxis6++;                       
         }
  }else{
    
    for (int pos = current_posAxis6; pos >= aPos; pos--) { 
    Axis6.write(pos);             
    delay(aRychlost); 
    current_posAxis6--;                      
         }
      }
}
