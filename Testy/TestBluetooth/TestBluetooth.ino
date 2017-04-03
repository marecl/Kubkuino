//Test komend AT
//Przyklad: AT+NAME?;
#include <String.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define btpow 4 //Bt Power
#define btx 5 //Bluetooth TX
#define brx 6 //Bluetooth RX
#define btkey 7 //Bt Key pin
String a = "Ready";
SoftwareSerial bt(btx, brx); //tx, rx
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  pinMode(btpow, OUTPUT);
  pinMode(btkey, OUTPUT);
  digitalWrite(btpow, LOW);
  delay(1000);
  digitalWrite(btkey, LOW);
  delay(1000);
  digitalWrite(btpow, HIGH);
  delay(1000);
  bt.begin(38400);
  Serial.begin(9600);
}
void loop() {
  Serial.println(a);
  while (bt.available() == 0) {}
  if (bt.available() !=  0)
    a = bt.readStringUntil(';');
  lcd.clear();
  lcd.print(a);

  a += "\r\n";
  digitalWrite(btkey, HIGH);
  delay(500);
  for (int z = 0; z < a.length(); z++)
    bt.write(a[z]);
  long long temptime = millis();
  while (bt.available() == 0 && (millis() - temptime) <= 5000) {}
  if (bt.available() != 0)
    a = bt.readStringUntil('\0');
  digitalWrite(btkey, LOW); delay(500);
  bt.flush();

  a.trim();
  for (int g = 0; g < a.length(); g++) {
    if (a[g] == 0x0A || a[g] == 0x0D)
      a.remove(g);
  }
  lcd.clear();
  lcd.print(a);
  bt.print(a + "\r\n");
  delay(1000);
  lcd.clear();
}
