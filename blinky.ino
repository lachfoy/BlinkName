// ------------
// Blink an LED
// ------------

int led1 = D6; // Instead of writing D0 over and over again, we'll write led1
int led2 = D7; // Instead of writing D7 over and over again, we'll write led2

char* arr = ".-.. .- -.-. .... .-.. .- -."; // Morse code string generated for "Lachlan"
int arrSize = sizeof(arr)/sizeof(arr[0]); // doesn't work :( I just hardcode the value of 28 instead.
int timeUnit = 100;

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
    // There are rules to help people distinguish dots from dashes in Morse code.
    // The length of a dot is 1 time unit.
    // A dash is 3 time units.
    // The space between symbols (dots and dashes) of the same letter is 1 time unit.
    // The space between letters is 3 time units.
    // The space between words is 7 time units.
    for (int i = 0; i < 28; i++)
    {
        if (arr[i] == ' ') // space betweem letters
        {
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            delay(timeUnit * 3);
        }
        else
        {
            if (arr[i] == '.')
            {
                digitalWrite(led1, HIGH);
                digitalWrite(led2, HIGH);
                delay(timeUnit * 1);
            }
            else if (arr[i] == '-')
            {
                digitalWrite(led1, HIGH);
                digitalWrite(led2, HIGH);
                delay(timeUnit * 3);
            }
			
            // TODO: this will put a 1 TU space after every symbol including spaces which probably shouldn't happen...
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            delay(timeUnit * 1);
        }
    }
	
    delay(timeUnit * 7); // 7 TU space before resetting
}

