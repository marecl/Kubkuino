#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>
#include <ClickButton.h>
#include <Wire.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include "pitches.h"
#define ctl 2 //Przycisk
#define buzz 3 //Buzzer
#define rled A3 //Czerwona dioda
#define gled A2 //Zielona dioda
#define bled A1 //Niebieska dioda

#define TONE NOTE_D2 //Na podstawie pitches.h mozna zmienic
#define ALARM_TIME 10000 //Jak dlugo ma alarm piszczec
#define BAUD 9600 //Predkosc portu

/* Pomiary */
int mode = 0; //Tryb
double hot = 60; //60
double cold = 47; //47
double pomiar, pomiarpop; //Potrzebne do pomiarow
bool plaskie = false; //true - plaskie, false - wklesle/inne

/* Connection */
bool conn = false; //Polaczony?

/* Komunikacja */
String input = ""; //Wejscie
char command; //Komenda

/* Alarm */
bool wylalarm = true; //Drzemka
bool czymaalarm = false; //Czy ma wlaczyc alarm
bool czyzimna = true; //Czy zdazyla byc zimna
bool mute = false; //Czy wyciszony

/* Zasilanie */
bool lcdon = true; //Status LCD
bool ledon = true; //Status LED
bool lcdled = true; //Status podswietlenia LCD

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
      +Wydajne
      ?Malo miejsca
      -Duzo czasu na stworzenie
*/
String modes[] = { //Tryby
  "CERAMIKA ",
  "ALUMINIUM",
  "SZKLANKA "
};

String wybor[] = {
  "Plaskie",
  "Wklesle"
};

String powermodes[] = { //Lista ustawien
  "   LED: ",
  "  Alarm: ",
  " Backlight:",
  "   Shutdown   ",
  "     EXIT     "
};
const uint8_t lar[] = { //Strzalka w lewo 0x00,0x01,0x03,0x07,0x07,0x03,0x01,0x00
  B000000,
  B000001,
  B000011,
  B000111,
  B000111,
  B000011,
  B000001,
  B000000
};
const uint8_t rar[] = { //Strzalka w prawo 0x20,0x30,0x38,0x3C,0x3C,0x38,0x30,0x20
  B100000,
  B110000,
  B111000,
  B111100,
  B111100,
  B111000,
  B110000,
  B100000
};
const uint8_t st[] = { //Symbol stopnia 0x06,0x9,0x9,0x06,0x00,0x00,0x00,0x00
  B000110,
  B001001,
  B001001,
  B000110,
  B000000,
  B000000,
  B000000,
  B000000
};

const uint8_t icon[] = { //Polaczenie z PC 0x2C, 0x76, 0xEF, 0x76, 0x2C
  B000100,
  B001110,
  B011111,
  B010101,
  B001010,
  B011111,
  B001110,
  B000100
};

//RTC - 0x68 DS1307
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_BMP085 czuj;
ClickButton ctrl(ctl, LOW);
void setup() {
  Serial.begin(BAUD);
  czuj.begin();
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
  lcd.init();
  lcd.backlight();
  lcd.noDisplay();
  lcd.createChar(0, lar);
  lcd.createChar(1, rar);
  lcd.createChar(2, st);
  lcd.createChar(3, icon);
  lcd.display();
  lcd.clear();
  lcd.print(modes[mode]);
}

void loop() {
  updatemp(mode, 10, 0);
  alarm();
  ctrl.Update();
  if (Serial.available()) { //In case of bluetooth commands
    input = Serial.readStringUntil(';'); //Bez ";\r\n"
    Serial.flush();
    btctl(input);
    input = "";
    lcd.setCursor(0, 0);
    lcd.print(modes[mode]);
  }
  if (conn == true) { //Rysujemy ikone polaczenia
    lcd.setCursor(15, 1); lcd.write(3);
  } else {
    lcd.setCursor(15, 1); lcd.print(" ");
  }
  switch (ctrl.clicks) {
    case 1: //Odczyt, granica cieplej i zimnej
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
      tempnow = (long long)millis();
      while (millis() - tempnow <= 2000) {
        lcd.setCursor(8, 0);
        lcd.print(pomiar, 1);
        pomiar = czuj.readTemperature();
      } lcd.clear();
      lcd.print(modes[mode]); break;
    case 2: settings(); //Wybor trybu
      lcd.print(modes[mode]); break;
    case 3: powermenu(); //Ustawienia
      lcd.print(modes[mode]); break;
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
    if (Serial.available()) {
      input = Serial.readStringUntil(';');
      Serial.flush();
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
  if (tempdno % 2 == 0) btctl("D81");
  else btctl("D80");
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
  lcd.print(powermodes[tmp]); //Pierwszy element trzeba wyswietlic
  if (ledon == true) lcd.print("ON"); else lcd.print("OFF");
  ctrl.Update();
  while (ctrl.clicks != -1) {
    ctrl.Update();
    if (Serial.available()) {
      input = Serial.readStringUntil(';');
      Serial.flush();
      btctl(input);
      input = "";
    }
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
  switch (tmp) { //Uzywamy btctl() do zmiany ustawien
    case 0: if (ledon == true) btctl("D30"); else btctl("D31"); break;
    case 1: if (mute == false) btctl("D40"); else btctl("D41"); break;
    case 2: if (lcdled == true) btctl("D50"); else btctl("D51"); break;
    case 3: poweroff(); break;
    case 4: break;
  }
  lcd.clear();
}

void alarm() { //Pisze stan
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
    wylalarm = true; //Nie powinno sie wlaczyc przez przypadek
    czymaalarm = false;
    czyzimna = true;
  }
}

void bipczyk() {
  long long tempbuzz = (long long)millis();
  while (digitalRead(ctl) != LOW && (millis() - tempbuzz) <= ALARM_TIME) {
    tone(buzz, TONE);
    updatemp(mode, 10, 0);
    if (Serial.available()) { //Na wypadek oczekujacych komend
      input = Serial.readStringUntil(';');
      Serial.flush();
      btctl(input);
      input = "";
    }
  }
  while (digitalRead(ctl) == LOW) //Czekamy na puszczenie przycisku
    updatemp(mode, 10, 0);
  noTone(buzz);
}

/*
  X - first argument
  Y - second argument

  e; - Connect (kind of "hello")
  qquit; - Disconnect
  CXX.X; - Set cold temperature - Returns K
  HXX.X; - Set Hot temperature - Returns K
  MX; - Set mode (0-2) - Returns K
  S[AT command] - Returns HC-05 response
  DXY;/DX; - toggle:
                0 - LCD, 1, 2, 3 - LED,
                4 - Mute, 5 - LCD backlight, 6 - Shutdown
                7 - Send string what is enabled (0,3,4,5)
                0 - disable, 1 - enable
    d; - Sets default name and password
    c; - Prints cold
    h; - Prints hot
    r; - Prints sensor temperature and patched temperature - Returns XX.X/YY.Y
    t; - Returns state as char (H - Hot, R - Ready, C - Cold)
    m; - Returns mode (CERAMIKA, ALUMINIUM, SZKLO)
*/
void btctl(String tinput) { //\r i \n nie moga nam mieszac
  String tempout = "";
  if (input == "\r\n" || input == "\n" || input == "\r") return (0);
  command = tinput.charAt(0);
  if (tinput.length() > 1)
    tinput.remove(0, 1);
  switch (command) {
    case 'e': Serial.print("HELLO\r\n"); conn = true; break; //Pokazujemy ze jestesmy dobryn urzadzeniem
    case 'h': Serial.print(hot); Serial.print("\r\n"); break; //Granica goracej
    case 'c': Serial.print(cold); Serial.print("\r\n"); break; //Granica zimnej
    case 'r':
      if (tinput[0] == '0') Serial.print(czuj.readTemperature()); //Odczyt czujnika
      else Serial.print(pomiarpop); //Wyliczona temperatura
      Serial.print("\r\n"); break;
    case 'm': input = modes[mode]; input.trim(); //Send current mode as text
      if (plaskie == true) input += " Plaskie dno";
      else input += " Wklesle dno";
      Serial.print(input); Serial.print("\r\n"); break;
    case 't': if (pomiarpop > hot) Serial.print("H\r\n"); //Wysyla stan
      if (pomiarpop < cold) Serial.print("C\r\n");
      if (pomiarpop >= cold && pomiarpop <= hot) Serial.print("R\r\n"); break;
    case 'd': for (int zyx = 0; zyx < 3; zyx++)Serial.print("No device\r\n"); break; //Reset modulu BT
    case 'q': if (tinput == "quit") {
        conn = false; delay(200);
      } break;
    case 'H': if (tinput.length() >= 1) hot = atof(tinput.c_str()); //Ustaw granice ciepla
      Serial.print("\r\n"); break;
    case 'C': if (tinput.length() >= 1) cold = atof(tinput.c_str()); //Ustaw granice zimna
      Serial.print("\r\n"); break;
    case 'M': if (tinput.length() == 1) mode = (atoi(tinput.c_str())) % 3; //Ustaw tryb
      Serial.print("\r\n"); break;
    case 'S': Serial.print("No device\r\n"); //Halo, tu nie ma BT...
      break;
    case 'D': switch (tinput[0]) { //Odwolania do menu zasilania
        case '0': if (tinput[1] == '0') { //LCD
            lcd.noDisplay(); lcdon = false;
            if (lcdled == true) lcd.noBacklight();
          } if (tinput[1] == '1') {
            lcd.display(); lcdon = true;
            if (lcdled == true) lcd.backlight();
          } break;
        case '1': Serial.print("No device"); break; //BT
        case '2': Serial.print("No device"); break; //BT+LCD
        case '3': if (tinput[1] == '0') { //LED
            ledon = false;
            digitalWrite(rled, LOW);
            digitalWrite(gled, LOW);
            digitalWrite(bled, LOW);
          } else ledon = true; break;
        case '4': if (tinput[1] == '0') { //Piezo
            tone(buzz, TONE); delay(500); noTone(buzz);
            mute = true; //W sumie wszystko poza tym moze byc usuniete
          } else {
            tone(buzz, TONE); delay(75); noTone(buzz); delay(250);
            tone(buzz, TONE); delay(75); noTone(buzz);
            mute = false; //Tu tez
          } break;
        case '5': if (tinput[1] == '0') { //Podswietlenie LCD (niezalezne)
            lcdled = false; lcd.noBacklight();
          } else {
            lcdled = true; lcd.backlight();
          } break;
        case '6': poweroff(); break; //Wylaczenie
        case '7'://Wysylamy co jest aktywne
          //LCD, LED, MUTE, LCD backlight
          if (lcdon == true) tempout += "1"; else tempout += "0";
          if (ledon == true) tempout += "1"; else tempout += "0";
          if (mute == true) tempout += "1"; else tempout += "0";
          if (lcdled == true) tempout += "1"; else tempout += "0";
          Serial.print(tempout); break;
        case '8': if (tinput[1] == '0') plaskie = false;
          else plaskie = true; break;
      } Serial.print("\r\n"); break;
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
//Moze kiedys sie przyda
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
  bool lcdbak = lcdon;
  if (ledbak == true) btctl("D30;");
  if (lcdledbak == true) btctl("D50;");
  if (lcdbak == true) btctl("D00;");
  while (digitalRead(ctl) == LOW);
  attachInterrupt(0, poweron, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  //Put to sleep
  sleep_mode();
  //Wakes up now
  sleep_disable();
  detachInterrupt(0);
  if (lcdbak == true)btctl("D01;");
  if (lcdledbak == true) btctl("D51;");
  if (ledbak == true) btctl("D31;");
}
void poweron() {
}
