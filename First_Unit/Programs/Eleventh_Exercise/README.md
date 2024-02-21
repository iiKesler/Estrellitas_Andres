# Eleventh Exercise

The point of this exercise was to first test how the ScriptCommunicator software works with the Arduino IDE and the Raspberry Pi microcontroller.

## How it works
First, the program initializes the serial as we usually make it do with the state machine, in the INIT state. After that, it changes to the WAIT_DATA state, where it basically does what the name describes, it waits for any type of data value to be sent to the microcontrooller and then, when it recives the this, it prints a message and it continues to wait.
