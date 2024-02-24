# Fifteenth Exercise
First I'm going to explain how the code is divided and explain what part does what.

## First part
First we have a function called `processData`, and it looks like this:

    static void processData(uint8_t *pData, uint8_t size, uint8_t *res){
      uint8_t sum = 0;
      for(int i = 0; i < size; i++){
        sum = sum + (pData[i] - 0x30);
      }
      *res = sum;
    }

This is, in a way, the heart of this code. That's because it's making a sum of the hex codes of the data that's entering and then returning the result and saved it in the direction where `res` is pointing at.

## Second part
This part is just declaring the state machines for the `task1()` function as we have been doing for a while now

        enum class Task1States{
          INIT,
          WAIT_DATA
        };

## Third part
This is where we declare the static variables that weill be used throught the code, I'll explain why they have to be static in the **Questions** section of this README.

        static Task1States task1State = Task1States::INIT;
        static uint8_t rxData[5];
        static uint8_t dataCounter = 0;

## Fourh part
Then we have the `task1()` function, this is very similar to the one we've creating for a while too. But this one has a particularity, more specifically on the conditional to check the `WAIT_DATA` state.

        void task1(){
          switch(task1State){
            case Task1States::INIT:{
              Serial.begin(115200);
              task1State = Task1States::WAIT_DATA;
              break;
            }
            
            case Task1States::WAIT_DATA:{
              // Evento 1:
        
              if(Serial.available() > 0){
                rxData[dataCounter] = Serial.read();
                dataCounter++;
                if(dataCounter == 5){
                  uint8_t result = 0;
                  processData(rxData, dataCounter, &result);
                  dataCounter = 0;
                  Serial.print("result: ");
                  Serial.print(result);
                  Serial.print('\n');
                }
              }
              break;
            }
        
            default:{
              break;
            }
          }
        }
The `if(Serial.available() > 0)` check if there is any data getting in, then using the `rxData[]` and the `dataCounter` variables declared earlier, we start counting *how* many data is actually going in, in this case it check if there has been exactly **5** and that's when the `processData()` function gets called to do the sum of the hex code data and send the result back. Lastly, the result gets printed and since we're putting the `task1()` in the `void loop()` it's gonna keep checking if there's more data comming in.

## Fifth part
This is were the `void setup()` and `void loop()` functions are located, we already know how this work.

        void setup() {
          task1();
        }
        
        void loop() {
          task1();
        }

# Questions
#### Why is it necessary to declare `rxData` static? and if it is not static, what happens?
> The `rxData` array is declared as static to ensure that it retains its values between function calls. Local variables are typically stored on the stack and are destroyed when the function returns. By declaring `rxData` as static, it is stored in the data segment of the program’s memory instead, which persists for the lifetime of the program. If `rxData` were not static, it would be reinitialized to its default value (which is indeterminate for arrays) every time `task1()` is called, and any data stored in it from previous calls to `task1()` would be lost.

#### `dataCounter` is defined static and is initialized to 0. Every time you enter the loop function dataCounter is initialized to 0? Why is it necessary to declare it static?
> The `dataCounter` variable is declared as static for similar reasons as `rxData`. It needs to retain its value between calls to `task1()` so that it can correctly count the number of data items received. If `dataCounter` were not static, it would be reinitialized to 0 every time `task1()` is called, and it would not be able to correctly count the number of data items received.

#### Finally, the constant `0x30` in `(pData[i] - 0x30)` why is it necessary?
> The constant `0x30` is the ASCII value of the character `‘0’`. If the data in the `pData` array is ASCII-encoded decimal digits, then subtracting `0x30` from each element converts the ASCII-encoded decimal digits to their actual numeric values. For example, the ASCII value of `‘0’` is `0x30`, so `('0' - 0x30)` gives `0`. Similarly, `('1' - 0x30)` gives `1`, `('2' - 0x30)` gives `2`, and so on.
