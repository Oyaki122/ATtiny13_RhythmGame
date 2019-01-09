#define button 1
#define buzzer 2
#define led 3

short tempoDecide(char notesNum) {
    return 60 / (2 * 25 * notesNum + random(-10, 11)) * 1000;
}

void rhythmGenerator(const short* rhythm, const char notesNum) {
    for (char count = 0; count < notesNum; count++) {
        rhythm[count] = random(0, 8);
    }
}

void modelShow(const short* rhythm, const char notesNum, const short tempo) {
    for (char count = 0; count < notesNum; count++) {
        tone(buzzer, 1000, tempo * rhythm[count] / 2);
        delay(tempo * rhythm[count]);
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
    short tempo;
    bool result;

    for (char notesNum = 4; i < 9; i++) {
        tempo = tempoDecide(notesNum);
        rhythmGenerator(&rhythm, notesNum);
        modelShow(&rhythm, notesNum, tempo);
        tone(buzzer, 500, 500);
        delay(500);
        playInput(&play, tempo);
        result = judge(&rhythm, &play);
        showResult(result);
        delay(1000);
    }
}