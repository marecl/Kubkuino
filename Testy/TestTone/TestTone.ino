#include "pitches.h"
#define ctl 2
#define buzz 3
void setup() {
  pinMode(buzz, OUTPUT);
}

void loop() {
  long long temptime = millis();
  while (digitalRead(ctl) != LOW && ((millis() - temptime) <= 20000)) {
    for (int a = 0; a < 4; a++) {
      tone(buzz, NOTE_D2);
      delay(75);
      noTone(buzz);
      delay(75);
    }
    delay(500);
  }
  delay(2000);
}
