# Sixth Exercise
The point of the code is to set up a state machine that alternates between initializing Serial
communication and waiting for a timeout interval to elapse. When the timeout interval elapses,
it prints the current time to the Serial monitor (found on the top right corner of the Arduino IDE)
This cycle repeats indefinitely in the loop() function.

## Some troubleshooting
When making the code, I came across this error "a function-definition is not allowed here
before '{' token", and it pointed towards all the void functions in the code, as well as the
switch statement.

The reason for this, is because on the orinal code:

      void task1(){
         // Definición de estados y variable de estado
         enum class Task1States{
            INIT,
            WAIT_TIMEOUT
         };
         static Task1States task1State = Task1States::INIT;

         // Definición de variables static (conservan su valor entre llamadas a task1)
         static uint32_t lastTime = 0;

         // Constantes
         constexpr uint32_t INTERVAL = 1000;

         // MÁQUINA de ESTADOS 
         switch(task1State){
            case Task1States::INIT:{
               // Acciones
               Serial.begin(115200);

               // Garantiza los valores iniciales para el siguiente estado
               lastTime = millis();
               task1State = Task1States::WAIT_TIMEOUT;

               Serial.print("Task1States::WAIT_TIMEOUT\n");

               break;
            }
            case Task1States::WAIT_TIMEOUT:{
               uint32_t currentTime = millis();
               // Evento
               if ((currentTime - lastTime) >= INTERVAL){
                  // Acciones:
                  lastTime = currentTime;
                  Serial.print(currentTime);
                  Serial.print('\n');
               }
               break;
            }
            default:{
               Serial.print("Error");
            }
      }

      void setup() {
         task1();
      }

      void loop() {
         task1();
      }

Both the 

      void setup()
and the 

      void loop()
Are inside that

      void task1()
Function, so the way to resolve it is to either make sure that both of those are outside our

      void task1()
function, the way I did it was like this:

      // Definición de estados y variable de estado
      enum class Task1States{
        INIT,
        WAIT_TIMEOUT
      };

      // Definición de variables static (conservan su valor entre llamadas a task1)
      static Task1States task1State = Task1States::INIT;
      static uint32_t lastTime = 0;

      // Constantes
      constexpr uint32_t INTERVAL = 1000;

      void task1(){
        // MÁQUINA de ESTADOS 
        switch(task1State){
          case Task1States::INIT:{
            // Acciones
            Serial.begin(115200);

            // Garantiza los valores iniciales para el siguiente estado
            lastTime = millis();
            task1State = Task1States::WAIT_TIMEOUT;

            Serial.print("Task1States::WAIT_TIMEOUT\n");

            break;
          }
          case Task1States::WAIT_TIMEOUT:{
            uint32_t currentTime = millis();
            // Evento
            if ((currentTime - lastTime) >= INTERVAL){
              // Acciones:
              lastTime = currentTime;
              Serial.print(currentTime);
              Serial.print('\n');
            }
            break;
          }
          default:{
            Serial.print("Error");
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
This way I don't have to worry about making sure the

      void setup()
And the

      void loop()
Are inside the 

      void task1()
Function.
