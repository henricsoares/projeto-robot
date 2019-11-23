#include "BluetoothSerial.h"
#include "HardwareSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
HardwareSerial myserial(1);

const int num = 4;
int angs[num] = {60,60,60,60};
boolean aux[num]={};
boolean aux1[num]={}; 

char btread[2] = {};


const int vcontrol1 = 14 ;const int motor1a = 27; const int motor1b = 26; const int motor2a = 35; const int motor2b = 33; const int vcontrol2 = 32;

int vel = 0;
const int freq = 1000; 
const int channel1 = 6; 
const int channel2 = 4; 
const int resol = 8;




void setup() {

  SerialBT.begin("Robot");
  myserial.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(vcontrol1, OUTPUT);
  pinMode(vcontrol2, OUTPUT);

  ledcAttachPin(vcontrol1, channel1);//Atribuimos o pino vcontrol1 ao canal 0.
  ledcAttachPin(vcontrol2, channel2);//Atribuimos o pino vcontrol1 ao canal 0.
  ledcSetup(channel1, freq, resol);//Atribuimos ao canal 0 a frequencia de 1000Hz com resolucao de 10bits.
  ledcSetup(channel2, freq, resol);
  ledcWrite(channel1, 0);
  ledcWrite(channel2, 0);

}

void loop() {

  for(int i =0;i<num;++i){
    aux[i]=false;
    aux1[i]=false;
    }
    
  
  while(!SerialBT.available()){
    SerialBT.println("Digite 'a' para controlar o veículo, ou 'b' para controlar o braço:");
    delay(1500);
    }

  if(SerialBT.available()){

    btread[0] = SerialBT.read();
  
    switch(btread[0]){
  
      case('a'):
      carro();
      break;

      case('b'):
      braco();
      break;

      default:
      break;
  
    }
  
  }
  
}
