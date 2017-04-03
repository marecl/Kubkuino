#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>
#include <ClickButton.h>
#include <Wire.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include "pitches.h"
#define buzz 3 //Buzzer
#define ctl 2 //Button - interrupt needed for wakeup
#define rled A3
#define gled A2
#define bled A1

#define TONE NOTE_D2 //Change tone (See pitches.h for available notes)
#define ALARM_TIME 10000 //How long should alarm take

/*Pomiary*/
int mode = 0; //Tryb
double hot = 60; //60
double cold = 47; //47
double pomiar, pomiarpop;
bool plaskie; //true - plaskie, false - wklesle/inne

/*Alarm*/
bool wylalarm = true; //Snooze
bool czymaalarm = false; //Should launch alarm
bool czyzimna = true; //If was previously cold
bool mute = false; //Should beep?

/*Zasilanie*/
bool lcdon = true; //LCD state
bool ledon = true; //LED state
bool lcdled = true; //LCD backlight state

/*Wszystko dziala!
  Kliki:
    1 - pomiar i granice
    2 - ustawianie trybu (1 następny, + wybor)
    3 - menu zasilania (1 nastepny, + wybor)

  Poprawki (pod loopem dac zmiany do odpowiednich trybow):
    1. Z buta odjac / dodac kilka stopni
      +Szybkie
      +Oszczedne
      ?Niedokladne
    2. Funkcja -----> poprawka(mode, pomiar) !!!
      +Oszczedne
      +Wydajne
      ?Malo miejsca
      -Duzo czasu na stworzenie
*/
String modes[] = { //Available modes - I don't think other are needed
  "CERAMIKA",
  "ALUMINIUM",
  "SZKLANKA"
};

String wybor[] = {
  "Plaskie",
  "Wklesle"
};

String powermodes[] = { //Settings list
  "   LED: ",
  "  Alarm: ",
  " Backlight:",
  "   Shutdown   ",
  "     EXIT     "
};
const uint8_t lar[] = { //Left arrow
  0x00, 0x01, 0x03, 0x07, 0x07, 0x03, 0x01, 0x00
};
const uint8_t rar[] = { //Right arrow
  0x20, 0x30, 0x38, 0x3C, 0x3C, 0x38, 0x30, 0x20
};
const uint8_t st[] = { //Degree symbol
  0x06, 0x09, 0x09, 0x06, 0x00, 0x00, 0x00, 0x00
};

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_BMP085 czuj;
ClickButton ctrl(ctl, LOW);

void setup() {
  ctrl.debounceTime = 10;
  ctrl.longClickTime = 500;
  ctrl.multiclickTime = 400;
  pinMode(buzz, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(ctl, INPUT);
  digitalWrite(rled, LOW);
  digitalWrite(gled, LOW);
  digitalWrite(bled, LOW);
  czuj.begin();
  lcd.init();
  lcd.createChar(0, lar); //Lewa strzałka
  lcd.createChar(1, rar); //Prawa strzałka
  lcd.createChar(2, st); //Stopien Celsjusza
  lcd.display();
  delay(100);
  lcd.clear();
  lcd.backlight();

  lcd.print(modes[mode]);
}

void loop() {
  updatemp(mode, 10, 0);
  alarm();
  ctrl.Update();
  switch (ctrl.clicks) {
    case 1: //Sensor readings, hot and cold trigger values
      lcd.clear();
      lcd.print("Pomiar:");
      lcd.setCursor(0, 1);
      lcd.print("C/H ");
      lcd.print(cold, 1);
      lcd.print("/");
      lcd.print(hot, 1);
      lcd.write(2);
      lcd.print("C");
      lcd.setCursor(12, 0);
      lcd.write(2);
      lcd.print("C");
      long long tempnow;
      tempnow = millis();
      while (millis() - tempnow <= 2000) {
        lcd.setCursor(8, 0);
        lcd.print(pomiar, 1);
        pomiar = czuj.readTemperature();
      } lcd.clear();
      lcd.print(modes[mode]); break;
    case 2: //Enter settings
      mode = settings();
      lcd.print(modes[mode]); break;
    case 3: powermenu(); lcd.clear(); //Enter power menu
      lcd.setCursor(0, 0); lcd.print(modes[mode]); break;
  }
}

void settings() {
  lcd.clear();
  lcd.print("Tryb:");
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
      lcd.print("Tryb:");
      lcd.write(0);
      lcd.print(modes[mode]);
      lcd.setCursor(15, 0);
      lcd.write(1);
      updatemp(mode, 0, 1);
    }
    if (bt.available()) {
      input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
      input = "";
    }
  }
  while (digitalRead(ctl) == LOW) {}
  ctrl.ClearClicks();
  lcd.setCursor(15, 0);
  lcd.print(" ");
  lcd.setCursor(5, 0);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("Dno: ");
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
  if (tempdno % 2 == 0) btctl("D51");
  else btctl("D50");
  lcd.clear();
  }
  while (digitalRead(ctl) == LOW) {}
  ctrl.ClearClicks();
  lcd.setCursor(15, 0);
  lcd.print(" ");
  lcd.setCursor(5, 0);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print("Dno: ");
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
  if (tempdno % 2 == 0) plaskie = true;
  else plaskie = false;
  lcd.clear();
}

void powermenu() {
  int tmp = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    Settings    ");
  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.setCursor(15, 1);
  lcd.write(1);
  lcd.setCursor(1, 1);
  lcd.print(powermodes[tmp]); //Print menu entry
  if (ledon == true && tmp == 0) lcd.print("ON");//Show state
  if (ledon == false && tmp == 0) lcd.print("OFF");
  ctrl.Update();
  while (ctrl.clicks != -1) {
    ctrl.Update();
    if (ctrl.clicks == 1) {
      tmp++;
      if (tmp > 4) tmp = 0;
      clearline(1, 1, 14);
      lcd.setCursor(1, 1);
      lcd.print(powermodes[tmp]);
      switch (tmp) {
        case 0: if (ledon == true) lcd.print("ON");
          else lcd.print("OFF"); break;
        case 1: if (mute == false) lcd.print("ON");
          else lcd.print("OFF"); break;
        case 2: if (lcdled == true) lcd.print("ON");
          else lcd.print("OFF"); break;
      }
    }
  }
  while (digitalRead(ctl) == LOW);
  switch (tmp) { //Using btctl() to control everything
    case 0: if (ledon == true) btctl("D10"); else btctl("D11"); break;
    case 1: if (mute == false) btctl("D20"); else btctl("D21"); break;
    case 2: if (lcdled == true) btctl("D30"); else btctl("D31"); break;
    case 3: poweroff(); break;
    case 4: break;
  }
  //while (digitalRead(ctl) == LOW);
  lcd.clear();
}

void alarm() { //Prints state
  lcd.setCursor(0, 1);
  if (pomiarpop > hot) {
    lcd.print("Goraca");
    wylalarm = true;
    czyzimna = false;
    czymaalarm = false;
    if (ledon == true) {
      digitalWrite(rled, HIGH);
      digitalWrite(gled, LOW);
      digitalWrite(bled, LOW);
    }
  } else if (pomiarpop < cold) {
    lcd.print("Zimna ");
    czyzimna = true;
    czymaalarm = false;
    wylalarm = true;
    if (ledon == true) {
      digitalWrite(rled, LOW);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);
    }
  } else if (pomiarpop >= cold && pomiarpop <= hot) {
    lcd.print("Ideolo");
    czymaalarm = true;
    wylalarm = false;
    if (ledon == true) {
      digitalWrite(rled, LOW);
      digitalWrite(gled, HIGH);
      digitalWrite(bled, LOW);
    }
  }
  if (czymaalarm == true && wylalarm == false && czyzimna == false) {
    if (mute == false) bipczyk();
    wylalarm = true; //Making sure it won't false trigger
    czymaalarm = false;
    czyzimna = true;
  }
}

void bipczyk() {
  long long tempbuzz = (long long)millis();
  while (digitalRead(ctl) != LOW && (millis() - tempbuzz) <= ALARM_TIME) {
    tone(buzz, TONE);
    updatemp(mode, 10, 0);
  }
  while (digitalRead(ctl) == LOW) //Wait while button is pressed
    updatemp(mode, 10, 0);
  noTone(buzz);
}

/*
  X - first argument
  Y - second argument

  CXX.X; - Set cold temperature - Returns K
  HXX.X; - Set Hot temperature - Returns K
  MX; - Set mode (0-2) - Returns K
  DXY;/DX; - toggle:
  0 - LCD, 1 - LED, 2 - Mute
  3 - LCD backlight, 4 - Shutdown
    0 - disable, 1 - enable*/
void btctl(String tinput) { //We don't want to \r or \n mess with our input
  char command = tinput.charAt(0);
  if (tinput.length() > 1)
    tinput.remove(0, 1);
  switch (command) {
    case 'H': if (tinput.length() >= 1) hot = atof(tinput.c_str()); break;
    //Set hot
    case 'C': if (tinput.length() >= 1) cold = atof(tinput.c_str()); break;
    //Set cold
    case 'M': if (tinput.length() == 1) mode = (atoi(tinput.c_str())) % 3; break;
    //Set mode
    case 'D': switch (tinput[0]) { //Power menu uses it
        case '0': if (tinput[1] == '0') { //LCD
            lcd.noDisplay(); lcdon = false;
            if (lcdled == true) lcd.noBacklight();
          } if (tinput[1] == '1') {
            lcd.display(); lcdon = true;
            if (lcdled == true) lcd.backlight();
          } break;
        case '1': if (tinput[1] == '0') { //LED
            ledon = false;
            digitalWrite(rled, LOW);
            digitalWrite(gled, LOW);
            digitalWrite(bled, LOW);
          } else ledon = true; break;
        case '2': if (tinput[1] == '0') { //Piezo
            tone(buzz, TONE); delay(500); noTone(buzz);
            mute = true; //Everything can be removed but this
          } else {
            tone(buzz, TONE); delay(75); noTone(buzz); delay(250);
            tone(buzz, TONE); delay(75); noTone(buzz);
            mute = false; //Here too
          } break;
        case '3': if (tinput[1] == '0') { //LCD backlight (LCD independent)
            lcdled = false; lcd.noBacklight();
          } else {
            lcdled = true; lcd.backlight();
          } break;
        case '4': poweroff(); break; //Shutdown
        case '5': if (tinput[1] == '0') plaskie = false;
          else plaskie = true; break;
      } break;
  }
}

//Wiersz, od ktorej do ktorej kolumny
void clearline(int line, int pocz, int kon) {
  lcd.setCursor(pocz, line);
  for (int a = pocz; a <= kon; a++)
    lcd.print(" ");
}

//Wypisuje temperature w odpowiednim miejscu
//Chyba ze -1 i -1, wtedy pisze jak leci
void updatemp(int a, int x, int y) {
  pomiar = czuj.readTemperature();
  pomiarpop = poprawka(a, pomiar);
  if (x != -1 && y != -1)
    lcd.setCursor(x, y);
  if (pomiar >= 160) lcd.print("Serio?");
  else {
    lcd.print(pomiarpop, 1);
    lcd.write(2);
    lcd.print("C");
  }
}

double poprawka(int tmode, double tpomiar) {
  switch (tmode) {
    case 0: if (plaskie == true) tpomiar += 3;
      else tpomiar += 5; return tpomiar; //Ceramika
    case 1: if (plaskie == true) tpomiar += 1;
      else tpomiar += 2; return tpomiar; //Aluminium
    case 2: if (plaskie == true) tpomiar += 5;
      else tpomiar += 6; return tpomiar; //Szklo
  }
}

void poweroff() {
  bool lcdledbak = lcdled;
  bool ledbak = ledon;
  while (digitalRead(ctl) == LOW);
  if (ledbak == true) btctl("D10");
  if (lcdledbak == true) btctl("D30");
  btctl("D00");
  attachInterrupt(0, poweron, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  //Put to sleep
  sleep_mode();
  //Wakes up now
  sleep_disable();
  while (digitalRead(ctl) == LOW);
  detachInterrupt(0);
  btctl("D01");
  if (lcdledbak == true) btctl("D31");
  if (ledbak == true) btctl("D11");
}
void poweron() { //Leave it empty
}
