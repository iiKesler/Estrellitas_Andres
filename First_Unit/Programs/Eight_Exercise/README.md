## Eight Exercise

Firstly, we create the necessary enumaration classes, in this case, task1(), task2() and task3(), we then declared the states each one is going to be changing from and to, in this case they were all the same (INIT, WAIT_TIMEOUT). The program is pretty similar to the one in the sixth exercise, but for task2() and task3() we use a different interval

# Code
Here's how the code looks:

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
            Serial.print("Mensaje a 1 Hz\n");
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
            Serial.print("Mensaje a 2 Hz\n");
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
            Serial.print("Mensaje a 3 Hz\n");
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
Every void task is pretty much the same, except when it's evaluating the interalvals in the **if** statement

## Questions
-> What are the program states?
> For the whole program, all the tasks have 2 states, the INIT that is only used when the task is first called, and it initiates, in a way, what the function is going to do, in the case of all the tasks, is to declare the variable that is later going to be substracted with another variable and evaluated against an interval, when the interval wins, then it doesn't do anything, but if the substraction wins, it prints a message.

-> What are the events?
> The event in this case is the **if** statement, because it evaluates the substraction of the currentTime variable with the lastTime variable, it then asks if it is greater or equal than the interval, if true, it prints a message, if false it just loops back.

-> What are the actions?
> The begin of the Serial connection, when the if statement is true, it makes the lastTime and currentTime variables equal and it prints a message to the Serial console.
