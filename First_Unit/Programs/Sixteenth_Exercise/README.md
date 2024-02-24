# Sixteenth Exercise
The code for this code is the same one of the **Fifteenth** Exercise, this is because it will be useful to answer the questions necessary.

## Questions
#### What happens when I do a `Serial.available()`?
> This function returns the number of bytes available to read in the incoming serial buffer. This is useful to check before calling `Serial.read()` to ensure there is data available.

#### What happens when I do a `Serial.read()`?
> This function reads the next byte of incoming serial data. It returns the first (oldest) byte of incoming serial data available. This byte is then removed from the buffer.

#### What happens when I do a `Serial.read()` and there is nothing in the receive buffer?
> If `Serial.read()` is called when there's nothing in the buffer, it will return `-1`. This is a way to indicate that no data is available to be read.

#### A common pattern when working with the serial port is this:

    if(Serial.available() > 0){
        int dataRx = Serial.read()
    }

#### How much data does Serial.read() read?
> Is a common way to read incoming serial data. It first checks if there is data available using `Serial.available()`. If there is, it reads the next byte using `Serial.read()`, but this specific code is only reading byte of data at time.

#### What if I want to read more than one data?
> If you want to read more than one byte, you can do so by calling `Serial.read()` in a loop as long as `Serial.available()` returns a number greater than 0. Something like this:

    while (Serial.available() > 0) {
        int dataRx = Serial.read();
