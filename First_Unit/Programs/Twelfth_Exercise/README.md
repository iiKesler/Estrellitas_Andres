# Twelfth Exercise

## State Machines
First the program establishes 2 different state machines, `INIT` and `WAIT_DATA`. Then it goes to a switch statement to change between machine states, since it usually starts at `INIT`, this state basically starts the serial in 115200 and then it swaps to `WAIT_DATA` to commence the actual code.

## WAIT_DATA
This state checks if there has been an entry to the serial console with an if statement, this statement reads if there's any data available to read in the serial port and then return the number of bytes available to read (hence the name). In this case, if there's at least one byte of data, the code inside the if statement executes.

## Pointer
1st, the `Serial.available()` reads the incomming data so it doesn't buffer and may end up overflowing the code. 2nd, we declare the variable `var` and we initialize it to 0. 3rd, and this is the important part, we declare the pointer `pvar`, this stores **where** the `var` variable is located. 4ht, we first print what `var` has at the moment, we then use the `*pvar` pointer to change what the variable has stored, in this case, to 10, and then we print the `var` variable one more time, this time it prints the number 10.
