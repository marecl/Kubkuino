#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <ClickButton.h>
#include <math.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include "vars.h"

/* Mozna zmieniac ale bez przesady */
#define _NAME (String)"Kubkuino_IR" //Mozna zmienic na jakakolwiek nazwe, ale ta pasuje :P
#define _PASS (String)"0000" //Nie chcemy zeby ktos nam sie bawil. Haslo do parowania.
#define TONE NOTE_D2 //Ton dzwieku alarmu
#define ALARM_TIME 10000 //Ile trwa piszczenie alarmu.

#define F_CPU 16000000

Adafruit_SSD1306 display;

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

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false);
  display.display();
  delay(500);

  drawmain(hot, cold, 0);
  bt.begin(38400);
}

void loop() {
  alarm(pomiar, hot, cold);
  pomiar = readTemp();
  drawmain(hot, cold, pomiar);

  uint32_t czas = millis();
  while (millis() - czas <= 100) {
    ctrl.Update();
    if (ctrl.clicks == 1) {
      powermenu();
      drawmain(hot, cold, readTemp());
    }
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }
  }
}

double readTemp() {
  Wire.beginTransmission(0x5A);
  Wire.write(0x07);
  Wire.endTransmission(false);

  Wire.requestFrom(0x5A, 0x03);
  uint16_t ret = Wire.read();
  ret |= Wire.read() << 8;
  return (round(10 * ((ret * .02) - 273.15))) / 10;
}

void drawmain(int _hot, int _cold, double _pomiar) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.print(F("Goraca: "));
  display.print(_hot);
  display.write(247);
  display.println('C');
  display.print(F("Zimna:  "));
  display.print(_cold);
  display.write(247);
  display.println('C');

  display.setTextSize(2);
  display.print(_pomiar, 1);
  display.write(247);
  display.print('C');

  display.fillRoundRect(96, 16, 32, 16, 2, WHITE);

  if (_pomiar > _hot)
    display.drawBitmap(100, 0, state_hot, 24, 16, WHITE);
  else if (_pomiar > _cold)
    display.drawBitmap(100, 0, state_ready, 24, 16, WHITE);
  else
    display.drawBitmap(100, 0, state_cold, 24, 16, WHITE);

  if (conn)
    display.drawBitmap(104, 16, icon, 16, 16, 0);
  display.display();
  return void();
}

void btctl(String tinput) { //Usuwamy \r\n
  if (tinput == "\r\n" || tinput == "\n" || tinput == "\r") return void();
  tinput.trim();
  char command = tinput.charAt(0);
  String tempout;
  if (tinput.length() > 1)
    tinput.remove(0, 1);
  switch (command) {
    case 'e': bt.print(F("HELLO_IR\r\n"));
      conn = true; break; //Odpowiadamy - polaczono z dobrym urzadzeniem
    case 'r': pomiar = readTemp();
      bt.print(pomiar, 1);
      bt.print(F("\r\n")); break;
    case 't': if (pomiar > hot) bt.print(F("H\r\n"));
      else if (pomiar < cold) bt.print(F("C\r\n"));
      else bt.print(F("R\r\n")); break;
    case 'd': service(F("AT+ORGL"));
      service("AT+NAME=" + _NAME);
      service("AT+PSWD=" + _PASS); break; //Reset do fabrycznych
    case 'q': if (tinput == "quit") {
        conn = false; service(F("AT+DISC"));
        digitalWrite(btpow, LOW);//Rozlaczanie
        delay(100); digitalWrite(btpow, HIGH);
      } break;//tak trzeba bo sie arduino zacina
    case 'H': if (tinput.length() >= 1 && tinput[0] != '?')
        hot = atoi(tinput.c_str());//Set hot
      else if (tinput[0] == '?') bt.print((String)hot + "\r\n");
      break;
    case 'C': if (tinput.length() >= 1 && tinput[0] != '?')
        cold = atoi(tinput.c_str());//Set cold
      else if (tinput[0] == '?')
        bt.print((String)cold + "\r\n");
      break;
    case 'S': if (tinput.length() >= 2 ) service(tinput);//Komendy AT do bluetootha
      break;
    case 'D': switch (tinput[0]) {
        case '0': if (tinput[1] == '0') { //LCD
            display.displayOn(false); lcdon = false;
          } else if (tinput[1] == '1') {
            display.displayOn(true); lcdon = true;
          } else if (tinput[1] == '?') {
            if (lcdon) bt.print(F("1\r\n"));
            else bt.print(F("1\r\n"));
          } break;
        case '1': if (tinput[1] == '0') { //Tylko do celow kompatybilnosci
            dimlcd = false;
            display.dim(false);
          } else if (tinput[1] == '1') {
            dimlcd = true;
            display.dim(true);
          } else if (tinput[1] == '?') {
            if (dimlcd) bt.print(F("1\r\n"));
            else bt.print(F("0\r\n"));
          } break;
        case '2': if (tinput[1] == '0') { //BT
            service(F("AT+DISC")); digitalWrite(btpow, LOW); conn = false;
          } if (tinput[1] == '1') digitalWrite(btpow, HIGH);
          break;
        case '3': if (tinput[1] == '0') { //LED
            ledon = false;
            digitalWrite(rled, LOW);
            digitalWrite(gled, LOW);
            digitalWrite(bled, LOW);
          } else if (tinput[1] == '1') ledon = true;
          else if (tinput[1] == '?') {
            if (ledon) bt.print(F("1\r\n"));
            else bt.print(F("0\r\n"));
          } break;
        case '4': if (tinput[1] == '0') { //Piezo
            tone(buzz, TONE); delay(500); noTone(buzz);
            glosny = false;//Wszystko poza tym mozna wywalic
          } else if (tinput[1] == '1') {
            tone(buzz, TONE); delay(75); noTone(buzz); delay(250);
            tone(buzz, TONE); delay(75); noTone(buzz);
            glosny = true;//J.w.
          } else if (tinput == "?") {
            if (glosny) bt.print(F("1\r\n"));
            else bt.print(F("0\r\n"));
          } break;
        case '6'://Wysylamy wszystko co jest wlaczone
          //LCD, Podswietlenie, LED, Alarm, Plaskie
          tempout = "";
          if (lcdon) tempout += "1"; else tempout += "0";
          if (dimlcd) tempout += "1"; else tempout += "0";
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
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println(a);
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
  else a = "REQUEST TIMEOUT\r\n";
  digitalWrite(btkey, LOW); delay(500);
  bt.flush();
  a.trim();
  for (uint8_t g = 0; g < a.length(); g++) {
    if (a[g] == 0x0A || a[g] == 0x0D)
      a.remove(g);
  }
  a.trim();
  display.print(a);//Mozna wywalic ale pokazuje ze dziala
  if (conn) bt.print(a + "\r\n");

  display.display();
  delay(1000);
  display.clearDisplay();
  return void();
}

void bipczyk() {
  uint32_t tempbuzz = millis();
  tone(buzz, TONE);
  while ((millis() - tempbuzz) <= ALARM_TIME && digitalRead(ctl) == HIGH) {
    drawmain(hot, cold, readTemp());
    if (bt.available()) {
      String input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
    }
  }
  noTone(buzz);
  while (digitalRead(ctl) == LOW)
    drawmain(hot, cold, readTemp());
  ctrl.clearClicks();
  return void();
}

void alarm(double _pomiar, int _hot, int _cold) {
  if (_pomiar > _hot) {
    wylalarm = true;
    czyzimna = false;
    czymaalarm = false;
    if (ledon == true) {
      digitalWrite(rled, HIGH);
      digitalWrite(gled, LOW);
      digitalWrite(bled, LOW);
    }
  } else if (_pomiar < _cold) {
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
    wylalarm = true;//Wlaczy sie tylko jak musi
    czymaalarm = false;//Magia booli. Nie ruszaj prosze :c
    czyzimna = true;
  }
  return void();
}

void powermenu() {
  int tmp = 0;
  int _dn = 0;
  bool draw = true;
  ctrl.clearClicks();
  while (true) {
    while (ctrl.clicks != -1) {
      if (draw) {
        display.clearDisplay();
        display.setCursor(0, 0);
        display.setTextSize(1);
        for (int a = _dn; a < _dn + 4; a++) {
          if (a == tmp) display.setTextColor(BLACK, WHITE);
          else display.setTextColor(WHITE, BLACK);
          display.print(powermodes[a]);
          switch (a) {
            case 0:
              digitalRead(btpow) ?
              display.println(F("ON      ")) :
              display.println(F("OFF     ")); break;
            case 1: ledon ?
              display.println(F("ON      ")) :
              display.println(F("OFF     ")); break;
            case 2: glosny ?
              display.println(F("ON      ")) :
              display.println(F("OFF     ")); break;
            case 3: dimlcd ?
              display.println(F("ON      ")) :
              display.println(F("OFF     ")); break;
          }
        }
        display.display();
        draw = false;
      }
      ctrl.Update();

      if (ctrl.clicks == 1) {
        if (tmp < 5) tmp++;
        else tmp = 0;

        if (tmp > 3 && tmp < 6) _dn = tmp - 3;
        else _dn = 0;
        draw = true;
        ctrl.clearClicks();
      }
    }
    switch (tmp) {
      case 0: if (digitalRead(btpow) == HIGH) btctl("D20"); else btctl("D21");
        break;
      case 1: ledon ? btctl(F("D30")) : btctl(F("D31")); break;
      case 2: glosny ? btctl(F("D40")) : btctl(F("D41")); break;
      case 3: dimlcd ? btctl(F("D10")) : btctl(F("D11")); break;
      case 4: return void(); break;
      case 5:  poweroff(); return void(); break;
    }

    draw = true;
    ctrl.clearClicks();
    while (!digitalRead(ctl));
  }
  return void();
}

void poweroff() {
  bool btbak = false;
  if (digitalRead(btpow) == HIGH) btbak = true;
  bool ledbak = ledon;
  bool lcdbak = lcdon;
  if (lcdbak) btctl(F("D00;"));
  if (btbak) btctl(F("D20;"));
  if (ledbak) btctl(F("D30;"));
  while (digitalRead(ctl) == LOW);
  attachInterrupt(0, poweron, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();//Zasypia

  sleep_disable();
  if (lcdbak)btctl(F("D01;"));
  if (btbak) btctl(F("D21;"));
  if (ledbak) btctl(F("D31;"));
  return void();
}

void poweron() {
  sleep_disable();
  detachInterrupt(0);
  return void();
}

