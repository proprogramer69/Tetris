#include "SoftwareSerial.h"
SoftwareSerial serial_connection(5, 6);//Create a serial connection with TX and RX on these pins
#define BUFFER_SIZE 64//This will prevent buffer overruns.
int value1= 0;
int value2= 0;
int value3= 0;
int var;
void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
  serial_connection.begin(9600);
  serial_connection.println("Ready!!!");//Send something to just start comms. This will never be seen.
  Serial.println("Started");//Tell the serial monitor that the sketch has started.
}

void loop() {
  
  // put your main code here, to run repeatedly:
  value1= digitalRead(7);
  value2= digitalRead(8);
  value3= digitalRead(9);
  if (value3 == HIGH){
    var=3;
    
  }else if(value1 == HIGH){
    var=1;
    
  }else if (value2 == HIGH){
    var=2;
    
  }else{
    var=0;
   
  }
  serial_connection.println(var);
}
