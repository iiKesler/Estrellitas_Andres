static void changeVar(uint32_t *pdata1, uint32_t *pdata2){
  *pdata1 = 5;
  *pdata2 = 25;
}

static void printVar(uint32_t value1, uint32_t value2){
  Serial.print("var1 content: ");
  Serial.print(value1 );
  Serial.print('\n');

  Serial.print("var2 content: ");
  Serial.print(value2 );
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
      // Primer evento
      // Revisar si ha llegao algun dato al puerto serial

      if(Serial.available() > 0){
        Serial.read();
        uint32_t var1 = 0;
        uint32_t var2 = 10;
        uint32_t *pvar1 = &var1;
        uint32_t *pvar2 = &var2;
        printVar(*pvar1, *pvar2);
        changeVar(pvar1, pvar2);
        printVar(*pvar1, *pvar2);
      }
      break;
    }

    default:{
      break;
    }
  }
}

void setup() {
  task1();
}

void loop() {
  task1();
}
