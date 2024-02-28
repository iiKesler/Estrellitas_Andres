void task1(){
  enum class Task1States{
    INIT,
    WAIT_DATA
  };

  static Task1States task1State = Task1States::INIT;
  static uint32_t rxData[32];
  static uint8_t dataCounter = 0;

  switch(task1State){
    case Task1States::INIT:{
      Serial.begin(115200);
      task1State = Task1States::WAIT_DATA;
      break;
    }
    
    case Task1States::WAIT_DATA:{
      
      if(Serial.available() > 0){
        rxData[dataCounter] = Serial.read();
        dataCounter++;
        if(dataCounter == 32){
          Serial.print("Mensaje de 32 bytes");
        }
      }
    }
    break;

    default:{
      break;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  task1();
}

void loop() {
  // put your main code here, to run repeatedly:
  task1();
}
