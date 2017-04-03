#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <ClickButton.h>
#define ctl 2 //Button
#define buzz 3 //Buzzer
double hot = 27.5; //Do EEPROMu
double cold = 27.1;
double pomiarpop = 0;

bool wylalarm = true;
bool czymaalarm = false;
bool czyzimna = true;
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_BMP085 czuj;
ClickButton ctrl(ctl, LOW);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.display();
  delay(10);
  lcd.clear();
  czuj.begin();
  ctrl.debounceTime = 10;
  ctrl.longClickTime = 500;
  ctrl.multiclickTime = 400;
  Serial.begin(9600);
}

void loop() {
  pomiarpop = czuj.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print(pomiarpop, 1);
  alarm();
  ctrl.Update();
}

void alarm() {
  lcd.setCursor(0, 1);
  if (pomiarpop > hot) {
    lcd.print("Goraca");
    wylalarm = true;
    czyzimna = false;
    czymaalarm = false;
  } if (pomiarpop < cold) {
    lcd.print("Zimna ");
    czyzimna = true;
    czymaalarm = false;
    wylalarm = true;
  } if (pomiarpop >= cold && pomiarpop <= hot) {
    lcd.print("Ideolo");
    czymaalarm = true;
    wylalarm = false;
  }
  if (czymaalarm == true && wylalarm == false && czyzimna == false) {
    bipczyk();
    wylalarm = true;
    czymaalarm = false;
    czyzimna = true;
  }
}

void bipczyk() {
  long long tempbuzz = millis();
  while (digitalRead(ctl) != LOW && (millis() - tempbuzz) < 5000) {
    lcd.setCursor(15, 1);
    lcd.print("!");
    tone(buzz, 1760);
    pomiarpop = czuj.readTemperature();
    lcd.setCursor(0, 0);
    lcd.print(pomiarpop, 1);
  }
    lcd.setCursor(15, 1);
    lcd.print(" ");
  noTone(buzz);
}

