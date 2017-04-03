#include <DallasTemperature.h>
#include <OneWire.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
  !!! Przed wrzuceniem do excela - zmienic kropki na przecinki!!!
*/

OneWire oneWire(8);
DallasTemperature herbata(&oneWire);
Adafruit_BMP085 dno;
LiquidCrystal_I2C lcd(0x27, 16, 2);

double prevtemp = 0;
double nowtemp = 0;
double temp = 0;

void setup(void) {
  Serial.begin(9600);
  herbata.begin();
  dno.begin();
  lcd.init();
  lcd.backlight();
  lcd.display();
  lcd.clear();
  herbata.requestTemperatures();
  nowtemp = herbata.getTempCByIndex(0);
  lcd.print("Czekam...");
  while (nowtemp < 75) {
    herbata.requestTemperatures();
    nowtemp = herbata.getTempCByIndex(0);
    lcd.setCursor(0, 1);
    lcd.print(nowtemp);
  }
  Serial.println("Kubek;Dno");
  lcd.clear();
  lcd.print("Dno: ");
  lcd.setCursor(0, 1);
  lcd.print("Kubek: ");
}

void loop(void) {
  herbata.requestTemperatures();
  nowtemp = herbata.getTempCByIndex(0);
  temp = dno.readTemperature();
  lcd.setCursor(5, 0);
  lcd.print(temp);
  lcd.setCursor(7, 1);
  lcd.print(nowtemp);
  if (prevtemp > nowtemp) {
    Serial.print(nowtemp); Serial.print(";");
    Serial.print(temp, 1); Serial.println();
  }
  prevtemp = nowtemp;
}
