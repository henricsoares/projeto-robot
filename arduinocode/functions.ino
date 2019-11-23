void comunica(){

  while(!Serial.available()){

    Serial.println("Digite 'a' para autoteste, 'b' para programar os servos, 'c' para informar posições atuais:");  
    delay(1500);   
    }
  
    
  if (Serial.available()){
    
    
    char received = Serial.read();

    
      
      
      
    switch(received){
      
      case('a'):
      
        Serial.println("autotestex'");
        testa();
          
        
      break;
      
      case('b'):

        delay(1000);
        for(int i = 0; i<num; ++i){
            
          angs[i] = Serial.parseInt();
          Serial.println(angs[i]);
                
          }
        goservo();  
      break;

      case('c'):
      
        Serial.print(angs[0]);
        Serial.print(", ");
        Serial.print(angs[1]);
        Serial.print(", ");
        Serial.print(angs[2]);
        Serial.print(", ");
        Serial.print(angs[3]);
        Serial.println(";");
          
      
      break;

      default:
      break;
      }
      
    }
  }

void testa(){
  
  for (int i = 0; i<num; ++i){
    
    servos[i].write(100,20,true);
    servos[i].write(60,20,true);
    
    } 
  }


void goservo(){
  for(int i=0;i<num;++i){
    angs[i] = constrain(angs[i],45,115);
    servos[i].write(angs[i],20,false);
    
    }
  Serial.print(angs[0]);
  Serial.print(", ");
  Serial.print(angs[1]);
  Serial.print(", ");
  Serial.print(angs[2]);
  Serial.print(", ");
  Serial.print(angs[3]);
  Serial.println(";");
}



void LimparBuffer(){
  
  while(Serial.available() > 0){
    Serial.read();
    }
  }
