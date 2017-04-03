#include <DallasTemperature.h>
#include <OneWire.h>
const int hot = 25;
const int cold = 22;
#define c A1
#define z A2
#define n A3
OneWire oneWire(8);
DallasTemperature sensors(&oneWire);
void setup(void) {
  pinMode(c, OUTPUT);
  pinMode(z, OUTPUT);
  pinMode(n, OUTPUT);
  sensors.begin();
  Serial.begin(9600);
}
double temperatura;
void loop(void) {
  sensors.requestTemperatures();
  temperatura = sensors.getTempCByIndex(0);
  if (temperatura > hot) {
    digitalWrite(c, HIGH);
    digitalWrite(z, LOW);
    digitalWrite(n, LOW);
  }
  if (cold <= temperatura && temperatura <= hot) {
    digitalWrite(c, LOW);
    digitalWrite(z, HIGH);
    digitalWrite(n, LOW);
  }
  if (temperatura < cold) {
    digitalWrite(c, LOW);
    digitalWrite(z, LOW);
    digitalWrite(n, HIGH);
  }
  Serial.println(temperatura);
}
