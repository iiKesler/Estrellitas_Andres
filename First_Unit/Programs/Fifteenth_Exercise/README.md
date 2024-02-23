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

This is, in a way, the heart of this code. That's because it's making a sum of the hex codes of the data that's entering