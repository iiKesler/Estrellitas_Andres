// Definición de estados y variable de estados
enum class Task1States{
  INIT,
  WAIT_TIMEOUT
};

enum class Task2States{
  INIT,
  WAIT_TIMEOUT
};

enum class Task3States{
  INIT,
  WAIT_TIMEOUT
};

// Definición variables static
static Task1States task1State = Task1States::INIT;
static uint32_t lastTime_task1 = 0;

static Task2States task2State = Task2States::INIT;
static uint32_t lastTime_task2 = 0;

static Task3States task3State = Task3States::INIT;
static uint32_t lastTime_task3 = 0;

// Constantes
constexpr uint32_t INTERVAL_task1 = 1000;
constexpr uint32_t INTERVAL_task2 = 2000;
constexpr uint32_t INTERVAL_task3 = 3000;

void task1(){
  // Máquina de estados
  switch (task1State){
    case Task1States::INIT:{
      // Acciones
      Serial.begin(115200);

      // Valores iniciales siguiente estado
      lastTime_task1 = millis();
      task1State = Task1States::WAIT_TIMEOUT;

      break;
    }
    case Task1States::WAIT_TIMEOUT:{
      uint32_t currentTime = millis();
      // Evento
      if ((currentTime - lastTime_task1) >= INTERVAL_task1){
        // Acciones
        lastTime_task1 = currentTime;
        Serial.print("Mensaje a 1 segundo\n");
      }
      break;
    }
    default:{
      break;
    }
  }
}

void task2(){
  // Máquina de estados
  switch(task2State){
    case Task2States::INIT:{
      // Acciones
      Serial.begin(115200);

      // Valores iniciales siguiente estado
      lastTime_task2 = millis();
      task2State = Task2States::WAIT_TIMEOUT;

      break;
    }
    case Task2States::WAIT_TIMEOUT:{
      uint32_t currentTime = millis();
      // Evento
      if ((currentTime - lastTime_task2) >= INTERVAL_task2){
        // Acciones
        lastTime_task2 = currentTime;
        Serial.print("Mensaje a 2 segundos\n");
      }
      break;
    }
    default:{
      break;
    }
  }
}

void task3(){
  // Máquina de estados
  switch(task3State){
    case  Task3States::INIT:{
      // Acciones
      Serial.begin(115200);

      // Valores iniciales siguiente estado
      lastTime_task3 = millis();
      task3State = Task3States::WAIT_TIMEOUT;

      break;
    }
    case Task3States::WAIT_TIMEOUT:{
      uint32_t currentTime = millis();
      // Evento
      if((currentTime - lastTime_task3) >= INTERVAL_task3){
        // Acciones
        lastTime_task3 = currentTime;
        Serial.print("Mensaje a 3 segundos\n");
      }
      break;
    }
    default:{
      break;
    }
  }
}

void setup(){
    task1();
    task2();
    task3();
}

void loop(){
    task1();
    task2();
    task3();
}