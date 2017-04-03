#include <avr/sleep.h>
#include <avr/power.h>
#define ctl 2

//
//// Przełącza pin A1!
//
void setup() {
  pinMode(A1, OUTPUT);
  digitalWrite(A1, HIGH);
}

void loop() {
  if (digitalRead(ctl) == LOW) poweroff();
}

void poweroff() {
  while (digitalRead(ctl) == LOW);
  digitalWrite(A1, LOW);
  attachInterrupt(0, poweron, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  sleep_mode();

  sleep_disable();
  while (digitalRead(ctl) == LOW);
  detachInterrupt(0);
  digitalWrite(A1, HIGH);
}
void poweron() { //Leave it empty
}
