void task1(){
  enum class Task1States{
    INIT,
    WAIT_DATA
  };
  static Task1States task1State = Task1States::INIT;

  switch(task1State){
    case Task1States::INIT:{
      Serial.begin(115200);
      task1State = Task1States::WAIT_DATA;
      break;
    }

    case Task1States::WAIT_DATA:{
      // Evento 1
      // Ha llegado al menos un dato por el puero serial?
      if(Serial.available() > 0){
        Serial.read();
        Serial.print("Hola computador\n");
      }
      break;
    }

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
