# Documentation of the Final Proyect of the third unit

This is a 2 part documentation, for the first part, click this [link](https://github.com/Mafe-Garcia/estrellitas_misc/tree/main/finalUnidad2)

## Arduino Code
The code is divided in 3 main status, the **ON** or **OFF** status, where the user has to turn on the media player first. Then, the **SETUP** state, where the user chooses what song they want to listen to from the list, then chose a the volume and lastly, how long they want to listen the song for. Atfer that, the media player starts printing out the duration of the song and the current temperature of the player, the temperature is a safeguard in case the player gets too hot, in which case, it turns off to keep it safe. Once all of the parameters are selected, the player is now in the **PLAYING** state.

### Binary protocol
At any point, the user may send the 'Z' letter, once that's done, the variables get printed in binary, and the `checksum` is made.

### Implementation of the checksum
This implementation is fairly simple, we have 3 different methods for it, first, we send every variable to our first method:

    // Function to calculate checksum for a float
    uint8_t calculateChecksum(float value) {
        uint8_t* bytePointer = (uint8_t*)&value;
        uint8_t checksum = 0;
        for (size_t i = 0; i < sizeof(float); i++) {
            checksum += bytePointer[i];
        }
        return checksum;
    }

Once this is done, it returns a `checksum` variable that then is going to be used to verify the data. This is made by the `handeReceivedData` method, it looks like this:

    // Function to handle received data
    void handleReceivedData(float temperature, float deltaTemperature, float volume, float deltaVolume, float currentTrack, float deltaCurrentTime, float trackDuration, float deltaTrackDuration, uint8_t receivedChecksum) {
        // Calculate the checksum of the received data
        uint8_t calculatedChecksum = calculateReceivedChecksum(temperature) ^ calculateReceivedChecksum(deltaTemperature) ^ calculateReceivedChecksum(volume) ^ calculateReceivedChecksum(deltaVolume) ^ 
                calculateReceivedChecksum(currentTrack) ^ calculateReceivedChecksum(deltaCurrentTime) ^ calculateReceivedChecksum(trackDuration) ^ calculateReceivedChecksum(deltaTrackDuration);
    
        // Compare the calculated checksum with the received checksum
        if (calculatedChecksum != receivedChecksum) {
            // If the checksums do not match, print an error message
            Serial.println("Error: Checksum does not match. Data may be corrupted.");
        } else {
            // If the checksums match, process the data
            // ...
        }
    }

This, makes basically the same process as the first `checksum`, however, it uses a new method to make the calculation of the checksum:

    // Function to calculate checksum for a received float
    uint8_t calculateReceivedChecksum(float value) {
        uint8_t* bytePointer = (uint8_t*)&value;
        uint8_t checksum = 0;
        for (size_t i = 0; i < sizeof(float); i++) {
            checksum += bytePointer[i];
        }
        return checksum;
    }

And once this is done, it evaluates both results, and check if they are the same, in the case that they aren't, an error message would get printed, otherwise, the program continues as normally

### Temperature
Like I pointed out at the beginnig, the temperature is used for the player to always check that is not getting overheated, and in the case that it does get overheated, it turns off. The implementation looks like this:

    void playingState() {
        if (playerOn) {
            task();
            if (currentState == STATE_PLAYING){
                // Print the current temperature
                float temperature = readTemperature();
                Serial.print("Current temperature: ");
                Serial.println(temperature);
                Serial.println("\n");
    
                // Check if the temperature reaches a certain value
                if (temperature >= 45.0) {
                    // If the temperature is too high, turn off the player             
                    Serial.println("Player turned off due to high temperature.");
                    playerOn = false;
                    currentState = STATE_OFF;
                    return; // Exit the function early
                }
                // Rest of the code
              }
            }
          }

Since the `playingState()` method is only called when the player is in the **PLAYING** state (exactly when is most likely for the player to overheat) we only call the temperature check and print here, and in the case that it goes aboved the threshold, it forces the player off, restarting the whole program

## Unity
The way this code works with unity is like this: The Unity editor sends what track the user wants to listen to, then at what volume, and once the user hits the play button, it starts the song. For now, it is not possible to change the duration of the song "in game" (this means it is possible to change the duration inside the unity editor, by inspecting the slider that is acts as the length of the song) so it just gets a default value. The issue comes with trying to implement the temperature as a visual manner, since the way it works is basically

> We **send** what track the user wants to listen to
> 
> We **send** at what volume they want to listen
> 
> We **send** how long the track is
> 
> We **receive** at what temperature is the player

And this... is the problem, because I haven't been able to properly set up the reading of that specific data that the player sends, it's always incorrect one way or the other, the other variables work as intended, but not this one, since it's basically the only one that sends the information from the microcontroller to the project, and all the other are the other way around. I have to keep working on it to fix this issue.

## Status Diagram
The status diagram for this project looks like this:

![Status_Diagram](https://github.com/iiKesler/Estrellitas_Andres/assets/89699466/14ef91d7-fb19-4a00-a60b-ee995b24c131)

