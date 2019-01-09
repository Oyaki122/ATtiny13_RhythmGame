#define button 1
#define buzzer 2
#define led 3

short bpmDecide(char notesNum) { return 25 * notesNum + random(-10, 11); }

void rhythmGenerator(const short* rhythm, const char notesNum) {
    for (char count = 0; count < notesNum; count++) {
        rhythm[count] = random(0, 8);
    }
}

void setup() {
    pinMode(button, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
    pinMode(led, OUTPUT);

    digitalWrite(led, HIGH);
    tone(buzzer, 1000, 1000);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
}

void loop() {
    short rhythm[5];
    short play[5];
    short bpm;
    bool result;

    for (char notesNum = 4; i < 9; i++) {
        bpm = bpmDecide(notesNum);
        rhythmGenerator(&rhythm, notesNum);
        modelShow(&rhythm, notesNum, bpm);
        tone(buzzer, 500, 500);
        delay(500);
        playInput(&play, bpm);
        result = judge(&rhythm, &play);
        showResult(result);
        delay(1000);
    }
}