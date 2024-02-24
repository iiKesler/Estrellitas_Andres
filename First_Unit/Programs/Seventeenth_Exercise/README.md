# Seventeenth Exercise
The code of this exercise are just snippets of some other code to answer some questions, it is not supposed to be ran at all because it's not going to work

# Questions
#### This way you can read 3 data that have arrived at the serial port:

    if(Serial.available() >= 3){
        int dataRx1 = Serial.read()
        int dataRx2 = Serial.read()
        int dataRx3 = Serial.read()
    }

#### What scenarios could you have in this case?

    if(Serial.available() >= 2){
        int dataRx1 = Serial.read()
        int dataRx2 = Serial.read()
        int dataRx3 = Serial.read()
    }
> In the second case, you’re checking if there are at least 2 bytes available to read. If there are, you read 2 bytes from the buffer. However, you’re then attempting to read a third byte (dataRx3 = Serial.read()) without checking if it’s available. This could lead to a couple of scenarios:
> 
> 1) If a third byte is available: Serial.read() will return the third byte as expected. This is the ideal scenario.
> 2) If a third byte is not available: Serial.read() will return -1, indicating that no data was available to read. This could potentially cause issues in your code if you’re expecting dataRx3 to be a valid byte value.
>
> So the first snippet is safer to use in general. It's always good to check if there is data available for read before using the `Serial.read()` to avoid any issues.
