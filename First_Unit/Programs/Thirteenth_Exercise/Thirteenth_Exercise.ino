static void changeVar(uint32_t *pdata){
  *pdata = 10;
}

static void printVar(uint32_t value){
  Serial.print("var content: ");
  Serial.print(value);
  Serial.print('\n');
}

enum class Task1States{
  INIT,
  WAIT_DATA
};

static Task1States task1State = Task1States::INIT;

void task1(){
  switch(task1State){
    case Task1States::INIT:{
      Serial.begin(115200);
      task1State = Task1States::WAIT_DATA;
      break;
    }

    case Task1States::WAIT_DATA:{
      // Evento 1
      // Ha llegado al menos un dato por el puerto serial?

      if(Serial.available() > 0){
        Serial.read();
        uint32_t var = 0;
        uint32_t *pvar = &var;
        printVar(*pvar);
        changeVar(pvar);
        printVar(var);
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
