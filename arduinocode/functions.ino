void comunica(){

  aux = true;
  aux1 = true;
  while(!Serial.available()){

    Serial.println("Digite 'a' para autoteste, 'b' para programar os servos, 'c' para controlar servos individualmente, 'd' para posições atuais:");  
    delay(1500);   
    }
  
    
  if (Serial.available()){
    
    
    char received = Serial.read();

    
      
      
      
    switch(received){
      
      case('a'):
      
<<<<<<< HEAD
          Serial.println("auto-teste");
          testa();
=======
        Serial.println("autotestex'");
        testa();
>>>>>>> 7bbf8a7f4d753c0718bc39e8479fbc8e9eb7fdf9
          
        
      break;
      
      case('b'):

        delay(1000);
        for(int i = 0; i<num; ++i){
            
          angs[i] = Serial.parseInt();
          Serial.println(angs[i]);
                
          }
        goservo();  
      break;

<<<<<<< HEAD
        case('c'):

          controla();

        break;

        case('d'):
=======
      case('c'):
>>>>>>> 7bbf8a7f4d753c0718bc39e8479fbc8e9eb7fdf9
      
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



void controla(){
  
            aux = false;  
          while(!aux){

            Serial.println("Digite '1' para servo 1 e etc, 'x' para sair");
            while(!Serial.available()){}
            
            char getdata = Serial.read();
            switch (getdata){

              case('1'):
                
                 
                aux1 = false;
                while(!aux1){
                  Serial.println("Controlando servo 1: aperte 'cima' para avançar, 'baixo' para recuar,'x' para sair");
                  while(!Serial.available()){}
                  char getdata1 = Serial.read();
                  switch(getdata1){

                    case('a'):
                    angs[0] = angs[0]+10;
                    angs[0] = constrain(angs[0],45,115);
                    Serial.println(angs[0]);
                    servos[0].write(angs[0],50,false);
                    
                    break;

                    case('d'):
                    angs[0] = angs[0]-10;
                    angs[0] = constrain(angs[0],45,115);
                    Serial.println(angs[0]);
                    servos[0].write(angs[0],50,false);
                    break;

                    case('x'):
                    aux1 = true;
                    break;

                    default:
                    break;
                    
                    }
                  
                  
                  
                  }
              break;

              case('2'):

              aux1 = false;
                while(!aux1){
                  Serial.println("Controlando servo 2: aperte 'cima' para avançar, 'baixo' para recuar,'x' para sair");
                  while(!Serial.available()){}
                  char getdata1 = Serial.read();
                  switch(getdata1){
                    case('a'):
                    angs[1] = angs[1]+10;
                    angs[1] = constrain(angs[1],45,115);
                    Serial.println(angs[1]);
                    servos[1].write(angs[1],50,false);
                    
                    break;

                    case('d'):
                    angs[1] = angs[1]-10;
                    angs[1] = constrain(angs[1],45,115);
                    Serial.println(angs[1]);
                    servos[1].write(angs[1],50,false);
                    break;

                    case('x'):
                    aux1 = true;
                    break;

                    default:
                    break;
                    
                    }
                  
                  
                  
                  }
              
              break;

              case('3'):

              aux1 = false;
                while(!aux1){
                  Serial.println("Controlando servo 3: aperte 'cima' para avançar, 'baixo' para recuar,'x' para sair");
                  while(!Serial.available()){}
                  char getdata1 = Serial.read();
                  switch(getdata1){
                    case('a'):
                    angs[2] = angs[2]+10;
                    angs[2] = constrain(angs[2],45,115);
                    Serial.println(angs[2]);
                    servos[2].write(angs[2],50,false);
                    
                    break;

                    case('d'):
                    angs[2] = angs[2]-10;
                    angs[2] = constrain(angs[2],45,115);
                    Serial.println(angs[2]);
                    servos[2].write(angs[2],50,false);
                    break;

                    case('x'):
                    aux1 = true;
                    break;

                    default:
                    break;
                    
                    }
                  
                  
                  
                  }
              
              break;

              case('4'):

              aux1 = false;
              while(!aux1){
                  Serial.println("Controlando servo 4: aperte 'cima' para avançar, 'baixo' para recuar,'x' para sair");
                  while(!Serial.available()){}
                  char getdata1 = Serial.read();
                  switch(getdata1){
                    case('a'):
                    angs[3] = angs[3]+10;
                    angs[3] = constrain(angs[3],45,115);
                    Serial.println(angs[3]);
                    servos[3].write(angs[3],50,false);
                    
                    break;

                    case('d'):
                    angs[3] = angs[3]-10;
                    angs[3] = constrain(angs[3],45,115);
                    Serial.println(angs[3]);
                    servos[3].write(angs[3],50,false);
                    break;

                    case('x'):
                    aux1 = true;
                    break;

                    default:
                    break;
                    
                    }
                  
                  
                  
                  }

              
              break;

              case('x'):
              aux = true;
              break;

              default:
              break;
              }
    

            
            
            }
          
      
  
  
  
  }



void LimparBuffer(){
  
  while(Serial.available() > 0){
    Serial.read();
    }
  }
