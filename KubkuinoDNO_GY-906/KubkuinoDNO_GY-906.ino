#include <avr/sleep.h>
#include <avr/power.h>
#include <ClickButton.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include "vars.h"
#define ctl 2 //Przycisk
#define buzz 3 //Buzzer
#define btpow 4 //Zasilanie BT
#define btx 5 //Bluetooth TX
#define brx 6 //Bluetooth RX
#define btkey 7 //Bt Key
#define rled A1
#define gled A2
#define bled A3
/*
   Zmienic wyswietlacz na SSD1306
*/

/* Mozna zmieniac ale bez przesady */
#define _NAME (String)"Kubkuino_IR" //Mozna zmienic na jakakolwiek nazwe, ale ta pasuje :P
#define _PASS (String)"0000" //Nie chcemy zeby ktos nam sie bawil. Haslo do parowania.

#define TONE NOTE_D2 //Ton dzwieku alarmu
#define ALARM_TIME 10000 //Ile trwa piszczenie alarmu.

LiquidCrystal_I2C lcd(0x27, 16, 2);
ClickButton ctrl(ctl, LOW);
SoftwareSerial bt(btx, brx);

void setup() {
  ctrl.debounceTime = 10;
  ctrl.longClickTime = 500;
  ctrl.multiclickTime = 400;
  pinMode(btpow, OUTPUT);
  pinMode(btkey, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(ctl, INPUT);
  digitalWrite(rled, LOW);
  digitalWrite(gled, LOW);
  digitalWrite(bled, LOW);
  digitalWrite(btkey, LOW);
  digitalWrite(btpow, LOW);
  bt.begin(38400);
  lcd.init();
  lcd.backlight();
  lcd.noDisplay();
  lcd.createChar(0, lar); //Lewa strzałka
  lcd.createChar(1, rar); //Prawa strzałka
  lcd.createChar(2, st); //Stopien Celsjusza
  lcd.createChar(3, icon); //Ikona BT
  lcd.display();
  lcd.clear();
  drawmain(hot, cold);
}

void loop() {
  updatemp(6, 0);
  alarm();
  /*if (conn == true && digitalRead(btpow) == HIGH) { //Rysuje ikone polaczenia
    lcd.setCursor(15, 1); lcd.write(3);
    } else {
    lcd.setCursor(15, 1); lcd.print(F(" "));
    }*/

  uint32_t czas = millis();
  while (millis() - czas <= 100) {
    ctrl.Update();

    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }

    if (ctrl.clicks == 1) {
      powermenu();
      drawmain(hot, cold);
    }
  }
}

double readtemp() {
  Wire.beginTransmission(0x5A);
  Wire.write(0x07);
  Wire.endTransmission(false);

  Wire.requestFrom(0x5A, 0x03);
  uint16_t ret = Wire.read();
  ret |= Wire.read() << 8;
  return (ret * .02) - 273.15;
}

void calculate(int _hot, int _cold, int _pomiar) { //Dla paska idacego od goracej do zimnej
  int curr = map(_pomiar, _cold, _hot, 0, 16);
  if (curr > 16) curr = 16;
  else if (curr < 0) curr = 0;
  lcd.setCursor(0, 1);
  if (curr == 16) lcd.print("AAAAAAAAAAAAAAAA");
  else if (curr == 0) clearline(1, 0, 15);
  else for (int a = 0; a < 16; a++)
      if (a < curr) lcd.print("A");
      else lcd.print(" ");
  lcd.print(curr);
  lcd.print("  ");
  return void();
}

//Wypisuje temperature w odpowiednim miejscu
//Chyba ze -1 i -1, wtedy pisze jak leci
//Moze kiedys sie przyda
void updatemp(int x, int y) {
  pomiar = readtemp();
  if (x != -1 && y != -1)
    lcd.setCursor(x, y);
  lcd.print(pomiar);
  lcd.write(2);
  lcd.print(F("C"));
  calculate(hot, cold, pomiar);
  return void();
}

void drawmain(int _hot, int _cold) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(_hot);
  lcd.write(2);
  lcd.print(F("C"));
  lcd.setCursor(12, 0);
  lcd.print(_cold);
  lcd.write(2);
  lcd.print(F("C"));
  return void();
}

void btctl(String tinput) { //Usuwamy \r\n
  if (tinput == "\r\n" || tinput == "\n" || tinput == "\r") return void();
  char command = tinput.charAt(0);
  String tempout;
  if (tinput.length() > 1)
    tinput.remove(0, 1);
  switch (command) {
    case 'e': bt.print(F("HELLO_IR\r\n")); conn = true; break; //Odpowiadamy - polaczono z dobrym urzadzeniem
    case 'r': pomiar = readtemp();
      bt.print(pomiar);
      bt.print("\r\n"); break;
    case 't': if (pomiar > hot) bt.print("H\r\n");
      else if (pomiar < cold) bt.print("C\r\n");
      else bt.print("R\r\n"); break;
    case 'd': service("AT+ORGL"); service("AT+NAME=" + _NAME); service("AT+PSWD=" + _PASS); break; //Reset do fabrycznych
    case 'q': if (tinput == "quit") {
        conn = false; service("AT+DISC"); digitalWrite(btpow, LOW); //Rozlaczanie
        delay(100); digitalWrite(btpow, HIGH);
      } break; //tak trzeba bo sie arduino zacina
    case 'H': if (tinput.length() >= 1 && tinput[0] != '?') hot = atoi(tinput.c_str()); //Set hot
      else if (tinput[0] == '?') bt.print((String)hot + "\r\n");
      break;
    case 'C': if (tinput.length() >= 1 && tinput[0] != '?') cold = atoi(tinput.c_str()); //Set cold
      else if (tinput[0] == '?')
        bt.print((String)cold + "\r\n");
      break;
    case 'S': if (tinput.length() >= 2 ) service(tinput); //Komendy AT do bluetootha
      break;
    case 'D': switch (tinput[0]) {
        case '0': if (tinput[1] == '0') { //LCD
            lcd.noDisplay(); lcdon = false;
            if (lcdled == true) lcd.noBacklight();
          } else if (tinput[1] == '1') {
            lcd.display(); lcdon = true;
            if (lcdled == true) lcd.backlight();
          } else if (tinput[1] == '?') {
            if (lcdon) bt.print("1\r\n");
            else bt.print("1\r\n");
          } break;
        case '1': if (tinput[1] == '0') { //Podswietlenie LCD
            lcdled = false; lcd.noBacklight();
          } else if (tinput[1] == '1') {
            lcdled = true; lcd.backlight();
          } else if (tinput[1] == '?') {
            if (lcdled) bt.print("1\r\n");
            else bt.print("0\r\n");
          } break;
        case '2': if (tinput[1] == '0') { //BT
            service("AT+DISC"); digitalWrite(btpow, LOW); conn = false;
          } if (tinput[1] == '1') digitalWrite(btpow, HIGH);
          break;
        case '3': if (tinput[1] == '0') { //LED
            ledon = false;
            digitalWrite(rled, LOW);
            digitalWrite(gled, LOW);
            digitalWrite(bled, LOW);
          } else if (tinput[1] == '1') ledon = true;
          else if (tinput[1] == '?') {
            if (ledon) bt.print("1\r\n");
            else bt.print("0\r\n");
          } break;
        case '4': if (tinput[1] == '0') { //Piezo
            tone(buzz, TONE); delay(500); noTone(buzz);
            glosny = false; //Wszystko poza tym mozna wywalic
          } else if (tinput[1] == '1') {
            tone(buzz, TONE); delay(75); noTone(buzz); delay(250);
            tone(buzz, TONE); delay(75); noTone(buzz);
            glosny = true; //J.w.
          } else if (tinput == "?") {
            if (glosny) bt.print("1\r\n");
            else bt.print("0\r\n");
          } break;
        case '6'://Wysylamy wszystko co jest wlaczone
          //LCD, Podswietlenie, LED, Alarm, Plaskie
          tempout = "";
          if (lcdon) tempout += "1"; else tempout += "0";
          if (lcdled) tempout += "1"; else tempout += "0";
          if (ledon) tempout += "1"; else tempout += "0";
          if (glosny) tempout += "1"; else tempout += "0";
          bt.print(tempout + "\r\n"); break;
        case '8': poweroff(); break;
      } break;
  }
  bt.flush();
  return void();
}

//Tutaj wchodzi komenda bez "\r\n"!
void service(String a) {
  lcd.clear();
  lcd.print(a);
  if (a == "AT+DISC") conn = false;
  a += "\r\n";
  digitalWrite(btkey, HIGH);
  delay(500);
  for (uint8_t z = 0; z < a.length(); z++)
    bt.write(a[z]);
  long long temptime = millis();
  while (bt.available() == 0 && (millis() - temptime) <= 5000) {}
  if (bt.available() != 0)
    a = bt.readStringUntil('\0');
  else a = "REQUEST TIMEOUT\r\n"; //Brak modułu albo wyłączony
  digitalWrite(btkey, LOW); delay(500);
  bt.flush();
  /*Smieci wylatuja*/
  a.trim();
  for (uint8_t g = 0; g < a.length(); g++) {
    if (a[g] == 0x0A || a[g] == 0x0D)
      a.remove(g);
  }
  a.trim();
  /*Odpowiadamy*/
  lcd.clear();
  lcd.print(a); //Mozna wywalic ale pokazuje ze dziala
  if (conn) bt.print(a + "\r\n");
  delay(1000);
  lcd.clear();
  return void();
}

//Wiersz, od ktorej do ktorej kolumny
void clearline(int line, int pocz, int kon) {
  lcd.setCursor(pocz, line);
  for (int a = pocz; a <= kon; a++)
    lcd.print(F(" "));
  return void();
}

void bipczyk() {
  uint32_t tempbuzz = millis();
  tone(buzz, TONE);
  while ((millis() - tempbuzz) <= ALARM_TIME && digitalRead(ctl) == HIGH) {
    updatemp(6, 0);
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }
  }
  noTone(buzz);
  while (digitalRead(ctl) == LOW)
    updatemp(6, 0);
  ctrl.ClearClicks();
  return void();
}

void alarm() {
  if (pomiar > hot) {
    wylalarm = true;
    czyzimna = false;
    czymaalarm = false;
    if (ledon == true) {
      digitalWrite(rled, HIGH);
      digitalWrite(gled, LOW);
      digitalWrite(bled, LOW);
    }
  } else if (pomiar < cold) {
    czyzimna = true;
    czymaalarm = false;
    wylalarm = true;
    if (ledon) {
      digitalWrite(rled, LOW);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);
    }
  } else {
    czymaalarm = true;
    wylalarm = false;
    if (ledon) {
      digitalWrite(rled, LOW);
      digitalWrite(gled, HIGH);
      digitalWrite(bled, LOW);
    }
  }
  if (czymaalarm && !wylalarm && !czyzimna) {
    if (glosny) bipczyk();
    wylalarm = true; //Wlaczy sie tylko jak musi
    czymaalarm = false; //Magia booli. Nie ruszaj prosze :c
    czyzimna = true;
  }
  return void();
}

void powermenu() {
  int tmp = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("   Ustawienia   "));
  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.setCursor(15, 1);
  lcd.write(1);
  lcd.setCursor(1, 1);
  lcd.print(powermodes[tmp]); //Pierwszy element menu
  if (digitalRead(btpow) == HIGH) lcd.print(F("ON"));//Status pierwszego elementu
  else lcd.print(F("OFF"));
  ctrl.Update();
  while (ctrl.clicks != -1) {
    ctrl.Update();
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }
    if (ctrl.clicks == 1) {
      tmp++;
      if (tmp > 5) tmp = 0;
      clearline(1, 1, 14);
      lcd.setCursor(1, 1);
      lcd.print(powermodes[tmp]);
      switch (tmp) {
        case 0: if (digitalRead(btpow) == HIGH) lcd.print(F("ON"));
          else lcd.print(F("OFF")); break;
        case 1: if (ledon) lcd.print(F("ON"));
          else lcd.print(F("OFF")); break;
        case 2: if (glosny) lcd.print(F("ON"));
          else lcd.print(F("OFF")); break;
        case 3: if (lcdled) lcd.print(F("ON"));
          else lcd.print(F("OFF")); break;
      }
    }
  }
  switch (tmp) { //btctl() kontroluje wszystko
    case 0: if (digitalRead(btpow) == HIGH) btctl("D20"); else btctl("D21");
      break;
    case 1: if (ledon) btctl("D30"); else btctl("D31"); break;
    case 2: if (!glosny) btctl("D40"); else btctl("D41"); break;
    case 3: if (lcdled) btctl("D10"); else btctl("D11"); break;
    case 4: poweroff(); break;
    case 5: break;
  }
  lcd.clear();
  return void();
}

void poweroff() {
  bool btbak = false;
  if (digitalRead(btpow) == HIGH) btbak = true;
  bool lcdledbak = lcdled;
  bool ledbak = ledon;
  bool lcdbak = lcdon;
  if (lcdbak)btctl("D00;");
  if (lcdledbak) btctl("D10;");
  if (btbak) btctl("D20;");
  if (ledbak) btctl("D30;");
  while (digitalRead(ctl) == LOW);
  attachInterrupt(0, poweron, LOW);
  delay(150);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode(); //Zasypia
  //Budzi się
  sleep_disable();
  if (lcdbak)btctl("D01;");
  if (lcdledbak) btctl("D11;");
  if (btbak) btctl("D21;");
  if (ledbak) btctl("D31;");
  return void();
}

void poweron() {
  sleep_disable();
  detachInterrupt(0);
  return void();
}
