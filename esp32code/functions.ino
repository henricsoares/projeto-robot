void carro(){
  while(!aux1[0]){
    LimparBuffer();
    SerialBT.println("Digite 'a' para mover-se para frente, 'b' para esquerda, 'c' para direita, 'd' para parar, 'x' para sair:");
    while(!SerialBT.available()){}
    if(SerialBT.available()){
      for(int i =0;i<num;++i){
        aux[i]=false;
        aux1[i]=false;
        }
      
      while(!aux1[1]){
        comunica2();
        }
        LimparBuffer();
      }
      
    }
  }

void braco(){
  while(!aux1[0]){
    LimparBuffer();
    
    SerialBT.println("Digite 'a' para autoteste, 'b' para programar os servos, 'c' para informar posições atuais, 'x' para sair:");
    
    while(!SerialBT.available()){}
    if(SerialBT.available()){
      for(int i =0;i<num;++i){
        aux[i]=false;
        aux1[i]=false;
        }
      
      while(!aux1[1]){
        comunica1();
        }
        LimparBuffer();
      }
      
    }
  }





void comunica1(){
  char received = SerialBT.read();
  switch(received){
    case('a'):
    myserial.println('a');
    //SerialBT.println("Digite 'a' para autoteste, 'b' para programar os servos, 'c' para informar posições atuais, 'd' para sair:");
    aux1[1]=true;
    break;
      
      
    case('b'):
      while(aux[0]==false){
        LimparBuffer();
        SerialBT.println("Digite a posição do servo 1:");
        while(!SerialBT.available()){}
        if(SerialBT.available()){
          angs[0]=SerialBT.parseInt();
          angs[0] = constrain(angs[0],45,115);
          while(aux[1]==false){
            LimparBuffer();
            SerialBT.println("Digite a posição do servo 2:");
            while(!SerialBT.available()){}
            if(SerialBT.available()){
              angs[1]=SerialBT.parseInt();
              angs[1] = constrain(angs[1],45,115);
              while(aux[2]==false){
                SerialBT.println("Digite a posição do servo 3:");
                LimparBuffer();
                while(!SerialBT.available()){}
                if(SerialBT.available()){
                  angs[2]=SerialBT.parseInt();
                  angs[2] = constrain(angs[2],45,115);
                  while(aux[3]==false){
                    SerialBT.println("Digite a posição do servo 4:");
                    LimparBuffer();
                    while(!SerialBT.available()){}
                    if(SerialBT.available()){
                      angs[3]=SerialBT.parseInt();
                      angs[3] = constrain(angs[3],45,115);
                      for(int i =0;i<num;++i){
                        aux[i]=true;
                        }
                      }
                    }
                  }
                }
              }
            }
          } 
        } 
        SerialBT.print(angs[0]);
        SerialBT.print(", ");
        SerialBT.print(angs[1]);
        SerialBT.print(", ");
        SerialBT.print(angs[2]);
        SerialBT.print(", ");
        SerialBT.print(angs[3]);
        SerialBT.println(";");
        //SerialBT.println("Digite 'a' para autoteste, 'b' para programar os servos, 'c' para informar posições atuais, 'd' para sair:");
        myserial.println('b');
        myserial.println(angs[0]);
        myserial.println(angs[1]);
        myserial.println(angs[2]);
        myserial.println(angs[3]);
        
        aux1[1]=true;
    break;

    case('c'):

      
      SerialBT.print(angs[0]);
      SerialBT.print(", ");
      SerialBT.print(angs[1]);
      SerialBT.print(", ");
      SerialBT.print(angs[2]);
      SerialBT.print(", ");
      SerialBT.print(angs[3]);
      SerialBT.println(";");
      aux1[1]=true;
      //SerialBT.println("Digite 'a' para autoteste, 'b' para programar os servos, 'c' para informar posições atuais, 'd' para sair:");
    break;

    case('x'):
      aux1[1]=true; 
      aux1[0]=true;  
    break;
    
    default:
    break;
    }
  }



void comunica2(){
  
  char received = SerialBT.read();
  switch(received){
    case('a'):
    
      ledcWrite(channel1, 512);
      ledcWrite(channel2, 512);     
      digitalWrite(motor1b, HIGH);
      digitalWrite(motor1a, LOW);
      digitalWrite(motor2b, HIGH);
      digitalWrite(motor2a, LOW);
      
      Serial.println("Para frente");
      
      
      aux1[1]=true;
    break;
      
      
    case('b'):
      
      
      ledcWrite(channel1, 512);
      ledcWrite(channel2, 200);    
      digitalWrite(motor1b, HIGH);
      digitalWrite(motor1a, LOW);
      digitalWrite(motor2b, HIGH);
      digitalWrite(motor2a, LOW);
      
      Serial.println("Para esquerda");
      
      
      aux1[1]=true;
    break;

    case('c'):
      
      ledcWrite(channel2, 512);
      ledcWrite(channel1, 200);    
      digitalWrite(motor1b, HIGH);
      digitalWrite(motor1a, LOW);
      digitalWrite(motor2b, HIGH);
      digitalWrite(motor2a, LOW);
      
      Serial.println("Para direita");  
    
      aux1[1]=true;
    break;

    case('d'):

      ledcWrite(channel1, 0);
      ledcWrite(channel2, 0);
      digitalWrite(motor1a, LOW);
      digitalWrite(motor1b, LOW);
      digitalWrite(motor2a, LOW);
      digitalWrite(motor2b, LOW);
     
      Serial.println("Parado");
      
    
      aux1[1]=true;
    break;

    case('x'):
      aux1[1]=true; 
      aux1[0]=true;  
    break;
    
    default:
    break;
    }
  
  
  }
 
void LimparBuffer(){
  while(SerialBT.available() > 0){
    SerialBT.read();
    }
  }
