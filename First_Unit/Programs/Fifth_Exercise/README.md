# Fifth exercise
## Documentation for Raspberry pi with Arduino
To install the libraries for Raspberry pi, you first need to go to the arduino IDE and add this link to the preferences of the IDE itself

    https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
That link then allows you, from the boards manager, to download the Raspberry Pi microcontrollers.

## Contributing to the project
There's also a way to contribute to the project, since is an open source one, by downloading the repository, making changes and doing a push request, it then gets evaluated and, if it's useful, added to the original code for the rest of the world to use.

## Using PlatformIO
PlatformIO is an extension to basically any IDE besides the default Arduino IDE. It works with VSCode, CLion, etc. And it's basically a quality of life tool, where it uses autocomplete tools for a better experience while coding in Arduino

## Using Bluethooth in Pico W
This can be enabled in the "Tools" section of the IDE, under "Bluethooth Stack", since it's a beta/alpha version, is not very stable and errors, bugs or glitches are to be expected and should be reported. This is specially useful because it gets rid of the cable, making it possible to send the code directly to the microcontroller, so if your code needs to be updated for whatever and any reason, you don't have to plug the microcontroller again.

## Using WiFi in Pico W
This is similar in a way to the bluethooth section, in the fact that you don't need a cable to update your code, however this one, based on its documentation, doesn't present that many bugs and/or errors, but you need an internet conection to be able to "talk" to the microcontroller, and you're not always going to have one, at least not for now.

## Conclusion
It is impossible to talk about all the documentation of the Arduino IDE, the Arduino microcontrollers and the Raspberry Pi microcontrollers, it is a very extense documentation, and it resolves every single question you might come across.
The entire documentation is here:

    https://arduino-pico.readthedocs.io/en/latest/#
