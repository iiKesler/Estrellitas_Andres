uint32_t last_time = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
	// Print a heartbeat
	if ( (millis() - last_time) >  2000)
    {
        Serial.print("Arduino is alive!!");
        Serial.print('\n');
        last_time = millis();
    }

// Send some message when I receive an 'A' or a 'Z'.
switch (Serial.read())
    {
			case 'A':
            Serial.print("That's the first letter of the abecedarium.");
            Serial.print('\n');
						break;
			case 'Z':
            Serial.print("That's the last letter of the abecedarium.");
            Serial.print('\n');
						break;
    }
}