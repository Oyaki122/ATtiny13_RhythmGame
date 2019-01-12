#define button 1
#define buzzer 2
#define led 3

void setup() {
    DDRB = 0b01;
    PORTB = 0b101;

    // tone(buzzer, 1000, 1000);
    delay(1000);
    PORTB &= ~0b100;
    delay(1000);
    short rhythm[5], play[5], tempo, result;

    for (char notesNum = 4; notesNum < 9; notesNum++) {
        tempo = 6 / (5 * notesNum);
        for (char count = 0; count < notesNum; count++) {
            rhythm[count] = random(0, 8);
        }
        for (char count = 0; count < notesNum; count++) {
            digitalWrite(2, HIGH);
            delay(tempo * rhythm[count] / 2);
            digitalWrite(2, LOW);
            delay(tempo * rhythm[count] / 2);
        }

        // tone(buzzer, 500, 500);
        delay(500);

        delay(1000);
    }
}

void loop() {}