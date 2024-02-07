# Sixth Exercise
The point of the code is to set up a state machine that alternates between initializing Serial
communication and waiting for a timeout interval to elapse. When the timeout interval elapses,
it prints the current time to the Serial monitor (found on the top right corner of the Arduino IDE)
This cycle repeats indefinitely in the loop() function.

## Some troubleshooting
When making the code, I came across this error "a function-definition is not allowed here
before '{' token", and it pointed towards all the void functions in the code, as well as the
switch statement.

The reason for this, is because on the orinal code
    