# Eighteenth Exercise
The exercise expect this from us:
- Create an application with a task.
- The task must have its own receive buffer and a capacity of 32 bytes.
- The task stores the serial data in its own receive buffer (the buffer will be an array).
- The buffer must be encapsulated in the task.
- The buffered data cannot be lost between calls to the task.
- The task must have some mechanism for counting the amount of data that has arrived. How would you do this?

### Creating the task
This is an easy part of the code, since it's what we've been doing since pretty much the beggining of the Activity Path, it's a voide type function and we declare the state machines on it first (Note: all the code from here on out except `void setup()`and `void loop()` is inside this `void task1()` function) here's how that first part looks:

    void task1(){
      enum class Task1States{
        INIT,
        WAIT_DATA
      };

        static Task1States task1State = Task1States::INIT;
Just 2 different state machines, one for the initialization and one to wait on the data that's gonna come through the buffer receptor later.

### Buffer reciever. Array buffer
The reciever needs to be of 32 bytes, that means, when it reaches 32 on the buffer, something must happen. In our case, we use 2 variables to ensure this

      static uint32_t rxData[32];
      static uint8_t dataCounter = 0;
The `rxData[]` is the array where the data will be saved, and the `dataCounter` is just that, a counter to know how many bytes are in at any given time, the reason this variables are static will be explained later.

### Buffer encapsulated 
This just means that the buffer is inside the `void task()` function and can't be directly called by other functions.

### Buffer data not lost
To ensure the data on the buffer, we have to declare the before mentioned variables `rxData[]` and `dataCounter` as static, that way, they don't change between callings.

### Counting amount of Data
This is done in the `if` statement where we check if any data has been entered first, it looks like this:

          if(Serial.available() > 0){
            rxData[dataCounter] = Serial.read();
            dataCounter++;
            if(dataCounter == 32){
              Serial.print("Mensaje de 32 bytes");
            }
          }
Here, `dataCounter` keeps track of how many data is entering the buffer, and when it reaches 32 it prints a message and then it resets to 0 again.

## Complete Code
Here's how the fully code looks like:

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
