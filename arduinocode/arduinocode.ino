#include <VarSpeedServo.h>
const int num = 4;
VarSpeedServo servos[num];  
char rec[num]={};
int pins[num] = {13,12,11,10};
int angs[num] = {60,60,60,60}; 
boolean aux;   
boolean aux1;   


void setup() {
  
  Serial.begin(9600);
  for (int i = 0; i <num; ++i){
  
    servos[i].attach(pins[i]);
    servos[i].write(angs[i],20,false);
    
    }
  
  }

void loop() {

 
  comunica();
    
  }
