#include <avr/sleep.h>
#include <avr/power.h>
#include <Adafruit_BMP085.h>
#include <ClickButton.h>
#include <DallasTemperature.h>
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
#define dsczuj 8 //DS18B20
#define rled A1
#define gled A2
#define bled A3

/* Mozna zmieniac ale bez przesady */
#define _NAME (String)"Kubkuino" //Mozna zmienic na jakakolwiek nazwe, ale ta pasuje :P
#define _PASS (String)"0000" //Nie chcemy zeby ktos nam sie bawil. Haslo do parowania.

#define TONE NOTE_D2 //Ton dzwieku alarmu
#define ALARM_TIME 10000 //Ile trwa piszczenie alarmu.

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_BMP085 czuj;
ClickButton ctrl(ctl, LOW);
SoftwareSerial bt(btx, brx);
OneWire oneWire(dsczuj);
DallasTemperature sensors(&oneWire);
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
  czuj.begin();
  sensors.begin();
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
  lcd.print(modes[mode]);
}

void loop() {
  updatemp(mode, 10, 0);
  alarm();
  lcd.setCursor(0, 1);
  if (pomiarpop > hot)
    lcd.print(F("Goraca"));
  else if (pomiarpop < cold)
    lcd.print(F("Zimna "));
  else lcd.print(F("Ideolo"));

  ctrl.Update();

  if (bt.available()) {
    String input = bt.readStringUntil(';');
    bt.flush();
    btctl(input);
    lcd.setCursor(0, 0);
    lcd.print(modes[mode]);
  }
  if (conn == true && digitalRead(btpow) == HIGH) { //Rysuje ikone polaczenia
    lcd.setCursor(15, 1); lcd.write(3);
  } else {
    lcd.setCursor(15, 1); lcd.print(F(" "));
  }
  switch (ctrl.clicks) {
    case 1: //Odczyty, goraca, zimna
      lcd.clear();
      if (plaskie) lcd.print(F("Plaskie"));
      else lcd.print(F("Wklesle"));
      lcd.setCursor(0, 1);
      lcd.print(F("Z/G:"));
      lcd.print(cold, 1);
      lcd.print(F("/"));
      lcd.print(hot, 1);
      lcd.write(2);
      lcd.print(F("C"));
      lcd.setCursor(12, 0);
      lcd.write(2);
      lcd.print(F("C"));
      uint32_t tempnow;
      tempnow = millis();
      while (millis() - tempnow <= 2000) {
        lcd.setCursor(8, 0);
        lcd.print(pomiar, 1);
        pomiar = czuj.readTemperature();
      } lcd.clear();
      lcd.print(modes[mode]); break;
    case 2: settings(); //Ustawienia (material)
      lcd.print(modes[mode]); break;
    case 3: powermenu(); //Ustawienia zasilania
      lcd.print(modes[mode]); break;
    case 4: trybpomiaru(); //Zmiana trybu pomiaru
      lcd.clear();
      lcd.print(modes[mode]); break;
  }
}

void pomiardno() {
  tryb = 3;
  lcd.clear();
  lcd.print(F("   POMIAR DNA"));
  lcd.setCursor(4, 1);
  while (digitalRead(ctl) == LOW) {}
  ctrl.ClearClicks();
  while (ctrl.clicks != -1 && tryb == 3) {
    pomiarpop = czuj.readTemperature();
    lcd.setCursor(5, 1);
    lcd.print(pomiarpop, 1);
    lcd.write(2);
    lcd.print(F("C"));
    ctrl.Update();
    alarm();
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
      lcd.clear();
      lcd.print(F("   POMIAR DNA"));
      lcd.setCursor(4, 1);
    }
  }
  tryb = 0;
  lcd.clear();
  lcd.print(modes[mode]);
}

void pomiarmanual() {
  tryb = 2;
  lcd.clear();
  lcd.print(F("  TRYB RECZNY"));
  lcd.setCursor(4, 1);
  while (digitalRead(ctl) == LOW) {}
  ctrl.ClearClicks();
  while (ctrl.clicks != -1 && tryb == 2) {
    ctrl.Update();
    sensors.requestTemperatures();
    pomiarpop = sensors.getTempCByIndex(0);
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
      lcd.clear();
      lcd.print(F("  TRYB RECZNY"));
      lcd.setCursor(4, 1);
    }
    lcd.setCursor(4, 1);
    lcd.print(pomiarpop);
    lcd.write(2);
    lcd.print(F("C"));
    alarm();
  }
  while (digitalRead(ctl) == LOW) {}
  plaskie = true;
  tryb = 0;
  lcd.clear();
  lcd.print(modes[mode]);
}

//Wypisuje temperature w odpowiednim miejscu
//Chyba ze -1 i -1, wtedy pisze jak leci
//Moze kiedys sie przyda
void updatemp(int a, int x, int y) {
  if (!plaskie && tryb == 0) {
    plaskie = false; pomiarmanual();
  } else {
    if ((plaskie && tryb == 0) || tryb == 2 || tryb == 1)  {
      pomiar = czuj.readTemperature();
      pomiarpop = poprawka(a, pomiar);
    }
    if (x != -1 && y != -1)
      lcd.setCursor(x, y);
    lcd.print(pomiarpop, 1);
    lcd.write(2);
    lcd.print(F("C"));
  }
}

void btctl(String tinput) { //Usuwamy \r\n
  if (tinput == "\r\n" || tinput == "\n" || tinput == "\r") return void();
  char command = tinput.charAt(0);
  if (tinput.length() > 1)
    tinput.remove(0, 1);
  String tempout;
  switch (command) {
    case 'e': bt.flush(); bt.print(F("HELLO_STD\r\n"));
      conn = true; break; //Odpowiadamy - polaczono z dobrym urzadzeniem
    case 'r':
      if ((!plaskie && tryb == 0) || tryb == 2) {
        sensors.requestTemperatures();
        pomiar = sensors.getTempCByIndex(0);
        bt.print(pomiar);
      } else if ((tryb != 2 && plaskie) || tryb == 3) {
        pomiar = czuj.readTemperature();
        if (tinput[0] == '1')
          pomiarpop = poprawka(mode, pomiar);
        bt.print(pomiar);
      }
      bt.print("\r\n"); break;
    case 't': if (pomiarpop > hot) bt.print("H\r\n");
      else if (pomiarpop < cold) bt.print("C\r\n");
      else bt.print("R\r\n"); break;
    case 'd': service("AT+ORGL"); service("AT+NAME=" + _NAME); service("AT+PSWD=" + _PASS); break; //Reset do fabrycznych
    case 'q': if (tinput == "quit") {
        conn = false; service("AT+DISC"); digitalWrite(btpow, LOW); //Rozlaczanie
        delay(100); digitalWrite(btpow, HIGH);
      } break; //tak trzeba bo sie arduino zacina
    case 'H': if (tinput.length() >= 1 && tinput[0] != '?') hot = atof(tinput.c_str()); //Set hot
      else if (tinput[0] == '?')
        bt.print((String)hot + "\r\n");
      break;
    case 'C': if (tinput.length() >= 1 && tinput[0] != '?') cold = atof(tinput.c_str()); //Set cold
      else if (tinput[0] == '?')
        bt.print((String)cold + "\r\n");
      break;
    case 'M': if (tinput.length() == 1 && tinput[0] != '?')
        mode = (atoi(tinput.c_str())) % 3; //Ustawia tryb
      else if (tinput.length() == 1 && tinput[0] == '?')
        bt.print((String)mode + "\r\n");
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
        case '5': if (tinput[1] == '0') plaskie = false;
          else if (tinput[1] == '1')plaskie = true;
          else if (tinput[1] == '?') {
            if (plaskie) bt.print("1\r\n");
            else bt.print("0\r\n");
          } break;
        case '6'://Wysylamy wszystko co jest wlaczone
          //LCD, Podswietlenie, LED, Alarm, Plaskie
          tempout = "";
          if (lcdon) tempout += "1"; else tempout += "0";
          if (lcdled) tempout += "1"; else tempout += "0";
          if (ledon) tempout += "1"; else tempout += "0";
          if (glosny) tempout += "1"; else tempout += "0";
          if (plaskie) tempout += "1"; else tempout += "0";
          bt.print(tempout + "\r\n"); break;
        case '7':
          if (tinput[1] == '0') {
            mode = 0; tryb = 0;
          } else if (tinput[1] == '1') {
            mode = 0; tryb = 1;
          } else if (tinput[1] == '2') {
            tryb = 2; pomiarmanual();
          } else if (tinput[1] == '3') {
            tryb = 3; pomiardno();
          } else if (tinput[1] == '?')
            bt.print((String)tryb + "\r\n");
          break;
        case '8': poweroff(); break;
      } break;
  }
  bt.flush();
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
}

//Wiersz, od ktorej do ktorej kolumny
void clearline(int line, int pocz, int kon) {
  lcd.setCursor(pocz, line);
  for (int a = pocz; a <= kon; a++)
    lcd.print(F(" "));
}

void bipczyk() {
  uint32_t tempbuzz = millis();
  tone(buzz, TONE);
  while ((millis() - tempbuzz) <= ALARM_TIME && digitalRead(ctl) == HIGH) {
    if (tryb == 0 || tryb == 1) updatemp(mode, 10, 0);
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }
  }
  noTone(buzz);
  if (tryb == 0 || tryb == 1)
    while (digitalRead(ctl) == LOW)
      updatemp(mode, 10, 0);
  ctrl.ClearClicks();
  return;
}

void alarm() {
  if (pomiarpop > hot) {
    wylalarm = true;
    czyzimna = false;
    czymaalarm = false;
    if (ledon == true) {
      digitalWrite(rled, HIGH);
      digitalWrite(gled, LOW);
      digitalWrite(bled, LOW);
    }
  } else if (pomiarpop < cold) {
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
}

void settings() {
  lcd.clear();
  lcd.print(F("Tryb:"));
  lcd.write(0);
  lcd.print(modes[mode]);
  lcd.setCursor(15, 0);
  lcd.write(1);
  updatemp(mode, 0, 1);
  while (ctrl.clicks != -1) {
    ctrl.Update();
    if (ctrl.clicks == 1) {
      mode++;
      if (mode > 2) mode = 0;
      clearline(0, 0, 15);
      lcd.setCursor(0, 0);
      lcd.print(F("Tryb:"));
      lcd.write(0);
      lcd.print(modes[mode]);
      lcd.setCursor(15, 0);
      lcd.write(1);
      updatemp(mode, 0, 1);
    }
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }
  }
  while (digitalRead(ctl) == LOW) {}
  ctrl.ClearClicks();
  lcd.setCursor(15, 0);
  lcd.print(F(" "));
  lcd.setCursor(5, 0);
  lcd.print(F(" "));
  lcd.setCursor(0, 1);
  lcd.print(F("Dno: "));
  lcd.write(0);
  lcd.setCursor(13, 1);
  lcd.write(1);
  lcd.setCursor(6, 1);
  int tempdno = 2;
  lcd.print(wybor[tempdno % 2]);
  while (ctrl.clicks != -1) {
    ctrl.Update();
    if (ctrl.clicks == 1) {
      tempdno++;
      lcd.setCursor(6, 1);
      lcd.print(wybor[tempdno % 2]);
    }
  }
  while (digitalRead(ctl) == LOW) {}
  if (tempdno % 2 == 0) btctl("D51");
  else btctl("D50");
  lcd.clear();
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
}

void trybpomiaru() {
  int tmp = tryb;
  lcd.clear();
  lcd.print(F(" Tryb pomiaru:"));
  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.print(pomiary[tmp]);
  lcd.write(1);
  while (ctrl.clicks != -1) {
    ctrl.Update();
    if (ctrl.clicks == 1) {
      tmp++;
      if (tmp > 3) tmp = 0;
      lcd.setCursor(1, 1);
      lcd.print(pomiary[tmp]);
    }
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }
    tryb = tmp;
  }
  switch (tmp) {
    case 0: btctl("D70"); break;
    case 1: btctl("D71"); break;
    case 2: btctl("D72"); break;
    case 3: btctl("D73"); break;
  }
  lcd.clear();
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
}

void poweron() {
  sleep_disable();
  detachInterrupt(0);
}
