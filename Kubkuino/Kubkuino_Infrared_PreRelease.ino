#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/sleep.h>
#include <ClickButton.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include "vars.h"

/* Mozna zmieniac ale bez przesady */
#define _NAME (String)"Kubkuino_IR" //Mozna zmienic na jakakolwiek nazwe, ale ta pasuje :P
#define _PASS (String)"0000" //Nie chcemy zeby ktos nam sie bawil. Haslo do parowania.
#define ALARM_TIME 10000 //Ile trwa piszczenie alarmu.
//#define DEBUG
#define VERSION "Release"

Adafruit_SSD1306 display;

ClickButton ctrl(ctl, LOW);
SoftwareSerial bt(btx, brx); //rx, tx

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false);
  splash();
  ctrl.debounceTime = 10;
  ctrl.longClickTime = 500;
  pinMode(btconn, INPUT);
  pinMode(btpow, OUTPUT);
  pinMode(btkey, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(ctl, INPUT);
  digitalWrite(btkey, LOW);
#if defined DEBUG
  digitalWrite(btpow, HIGH);
  glosny = false;
  lcdon = true;
  ledon = true;
  dimlcd = false;
  hot = 30;
  cold = 25;
#else
  digitalWrite(btpow, LOW);
  glosny = false;
  lcdon = true;
  ledon = true;
  dimlcd = false;
  hot = 60;
  cold = 47;
  getEEPROM();
#endif
  char chk;
  EEPROM.get(0, chk);
  if (chk != 'A') {
    defEEPROM();
    saveEEPROM();
    digitalWrite(rled, HIGH);
    delay(1000);
  }
  digitalWrite(gled, HIGH);
  delay(1000);
  bt.begin(38400);
}

void loop() {
  pomiar += readTemp();
  pomiar /= 2;
  if (pomiar != poppomiar) {
    handlemain(&hot, &cold, &pomiar, &glosny);
    poppomiar = pomiar;
  }
  if (alarm) tone(buzz, 432);
  uint32_t cycle = millis();
  while (millis() - cycle < 250) {
    ctrl.Update();
    if (ctrl.clicks == 1) {
      if (!alarm)powermenu();
      else {
        noTone(buzz);
        alarm = false;
      }
    } else if (alarm && millis() - alarmStart >= ALARM_TIME) {
      noTone(buzz);
      alarm = false;
      alarmStart = 0;
    }
    if (bt.available())
      receiveBT();
  }
}

double readTemp() {
  Wire.beginTransmission(0x5A);
  Wire.write(0x07);
  Wire.endTransmission(false);

  Wire.requestFrom(0x5A, 0x03);
  uint16_t ret = Wire.read();
  ret |= Wire.read() << 8;
  return ((ret * .02) - 273.15);
}

void handlemain(int8_t *_hot, int8_t *_cold, double *_pomiar, bool *_glosny) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.print(F("Goraca: "));
  display.print(*_hot);
  display.print(F("\xF7\x43\nZimna:  ")); //Degree, C, newline and next line
  display.print(*_cold);
  display.println(F("\xF7\x43"));

  display.setTextSize(2);
  display.print(*_pomiar, 1);
  display.println(F("\xF7\x43"));

  display.fillCircle(95, 46, 8, WHITE);
  display.fillCircle(95, 46, 5, BLACK);
  display.fillRoundRect(96, 32, 32, 32, 3, WHITE);

  if (*_pomiar > *_hot) {
    if (ledon) {
      digitalWrite(rled, HIGH);
      digitalWrite(gled, LOW);
      digitalWrite(bled, LOW);
    }
    alarmState = 0b100;
    display.drawBitmap(100, 15, state_hot, 24, 16, WHITE);
  }
  else if (*_pomiar > *_cold) {
    if (ledon) {
      digitalWrite(rled, LOW);
      digitalWrite(gled, HIGH);
      digitalWrite(bled, LOW);
    }
    bitClear(alarmState, 2);
    bitSet(alarmState, 0);
    display.drawBitmap(100, 15, state_ready, 24, 16, WHITE);
  }
  else {
    if (ledon) {
      digitalWrite(rled, LOW);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);
    }
    alarmState = 0b110;
    display.drawBitmap(100, 15, state_cold, 24, 16, WHITE);
  }
  if (digitalRead(btconn))
    display.drawBitmap(104, 40, icon, 16, 16, 0);
  if (alarmState == 0b001) {
    if (*_glosny) {
      alarm = true;
      alarmStart = millis();
    }
    alarmState = 0b110;
  }
  display.display();
  return void();
}

void btctl(String tinput) {
  char command = tinput[0];
  String tempout = "";
  if (tinput.length() > 1)
    tinput.remove(0, 1);
  switch (command) {
    case 'e': bt.write("HELLO_IR\r\n");
      break;
    case 'r': bt.println(pomiar);
      break;
    case 'q': if (tinput == "quit")
        service(F("AT+DISC"));
      break;
    case 'H': if (tinput.length() >= 1 && tinput[0] != '?')
        hot = atoi(tinput.c_str());//Set hot
      else if (tinput[0] == '?') bt.println((String)hot);
      break;
    case 'C': if (tinput.length() >= 1 && tinput[0] != '?')
        cold = atoi(tinput.c_str());//Set cold
      else if (tinput[0] == '?') bt.print((String)cold + "\r\n");
      break;
    case 'S': if (tinput.length() >= 2 ) service(tinput);
      break;
    case 'D': switch (tinput[0]) {
        case '0':
          lcdon = (tinput[1] == '1');
          display.ssd1306_command((lcdon) ? 0xAF : 0xAE);
          break;
        case '1':
          dimlcd = (tinput[1] == '1');
          display.dim(dimlcd);
          break;
        case '2': if (tinput[1] == '0') { //BT
            service(F("AT+DISC")); digitalWrite(btpow, LOW);
          } if (tinput[1] == '1') digitalWrite(btpow, HIGH);
          break;
        case '3':
          ledon = (tinput[1] == '1');
          if (!ledon) { //LED
            digitalWrite(rled, LOW);
            digitalWrite(gled, LOW);
            digitalWrite(bled, LOW);
          }
          break;
        case '4': glosny = (tinput[1] == '1');
          break;
        case '5':
          tempout += (lcdon) ? "1" : "0";
          tempout += (dimlcd) ? "1" : "0";
          tempout += (ledon) ? "1" : "0";
          tempout += (glosny) ? "1" : "0";
          bt.println(tempout); break;
        case '6': poweroff(); break;
        case 'B': service(F("AT+ORGL")); //Bluetooth defaults
          service("AT+NAME=" + _NAME);
          service("AT+PSWD=" + _PASS);
          service(F("AT+UART=38400,0,0")); break;
        case 'D': //Device defaults
          defEEPROM();
          saveEEPROM(); break;
        case 'L': getEEPROM(); break;
        case 'S': saveEEPROM(); break;
      } break;
  }
  bt.flush();
  return void();
}

//Tutaj wchodzi komenda bez "\r\n"!
void service(String a) {
#ifdef DEBUG
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.println(a);
  display.display();
#endif
  a += "\r\n";
  bool _btpower = false;
  if (digitalRead(btpow)) _btpower = true;
  digitalWrite(btpow, HIGH);
  digitalWrite(btkey, HIGH);
  delay(500);
  for (uint8_t z = 0; z < a.length(); z++)
    bt.write(a[z]);
  uint32_t temptime = millis();
  while (bt.available() == 0 && (millis() - temptime) <= 5000);

  if (bt.available() != 0)
    a = bt.readStringUntil('\0');
  else a = F("TIMEOUT\r\n");
  digitalWrite(btkey, LOW); delay(500);
  for (uint8_t x = 0; x < a.length(); x++)
    if (a[x] == '\r' || a[x] == '\n' || a[x] == '\t') {
      a.remove(x, 1);
      x = 0;
    }
  if (!_btpower) digitalWrite(_btpower, LOW);
#ifdef DEBUG
  display.print(a);//Mozna wywalic ale pokazuje ze dziala
  display.display();
  delay(1000);
  display.clearDisplay();
#endif
  if (digitalRead(btconn)) bt.println(a);
  bt.flush();
  return void();
}

void receiveBT() {
#if defined DEBUG
  digitalWrite(rled, HIGH);
  digitalWrite(bled, HIGH);
  String input = bt.readStringUntil(';');
  input.trim();
  if (input.length()) btctl(input);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(input);
  display.display();
  delay(500);
  poppomiar = 0;
  digitalWrite(rled, LOW);
  digitalWrite(bled, LOW);
#else
  String input = bt.readStringUntil(';');
  input.trim();
  if (input.length()) btctl(input);
#endif
  poppomiar = 0;
  return void();
}

void powermenu() {
  int8_t tmp = 0;
  bool draw = true;
  while (!digitalRead(ctl));
  ctrl.reset();
  display.setTextSize(1);
  while (tmp >= 0) {
    while (ctrl.clicks >= 0) {
      if (draw) {
        display.clearDisplay();
        display.setCursor(0, 0);
        for (uint8_t a = 0; a < 7; a++) {
          (a == tmp) ? display.setTextColor(BLACK, WHITE) :
          display.setTextColor(WHITE, BLACK);
          switch (a) {
            case 0:
              display.print(F("  Bluetooth: "));
              display.println((digitalRead(btpow)) ?
                              F("ON      ") :
                              F("OFF     ")); break;
            case 1:
              display.print(F("        LED: "));
              display.println((ledon) ?
                              F("ON      ") :
                              F("OFF     ")); break;
            case 2:
              display.print(F("      Alarm: "));
              display.println((glosny) ?
                              F("ON      ") :
                              F("OFF     ")); break;
            case 3:
              display.print(F(" Dim screen: "));
              display.println((dimlcd) ?
                              F("ON      ") :
                              F("OFF     ")); break;
            case 4: display.println(F("   Memory Settings   ")); break;
            case 5: display.println(F("         Back        ")); break;
            case 6: display.print(F("       Shutdown      ")); break;
          }
        }
        display.display();
        draw = false;
      }
      ctrl.Update();

      if (ctrl.clicks == 1) {
        (tmp < 6) ?
        tmp++ : tmp = 0;
        draw = true;
        ctrl.reset();
      }
      if (bt.available())
        receiveBT();
    }
    switch (tmp) {
      case 0: btctl(digitalRead(btpow) ? F("D20") : F("D21")); break;
      case 1: btctl((ledon) ? F("D30") : F("D31")); break;
      case 2: btctl((glosny) ? F("D40") : F("D41")); break;
      case 3: btctl((dimlcd) ? F("D10") : F("D11")); break;
      case 4: settingsEEPROM(); break;
      case 5: tmp = -1; break;
      case 6: poweroff(); tmp = -1; break;
    }

    draw = true;
    ctrl.reset();
    while (!digitalRead(ctl));
    poppomiar = 0;
  }
  return void();
}

bool permissionWindow() {
  int8_t tmp3 = 0;
  display.setTextSize(2);
  while (!digitalRead(ctl));
  ctrl.reset();
  bool draw2 = true;
  while (tmp3 < 2) {
    while (ctrl.clicks >= 0) {
      if (ctrl.clicks == 1 || draw2) {
        draw2 = false;
        for (uint8_t a = 0; a < 2; a++) {
          (a == tmp3) ? display.setTextColor(BLACK, WHITE) :
          display.setTextColor(WHITE, BLACK);
          switch (a) {
            case 0: display.setCursor(16, 24);
              display.print(F("Nah")); break;
            case 1: display.setCursor(72, 24);
              display.print(F("Yes")); break;
          }
        }
        display.display();
        (tmp3 == 0) ? tmp3 = 1 : tmp3 = 0;
        ctrl.reset();
      }
      ctrl.Update();
      if (bt.available())
        receiveBT();
    }
    switch (tmp3) {
      case 0: tmp3 = 2; break;
      case 1: tmp3 = 3; break;
    }

    ctrl.reset();
    while (!digitalRead(ctl));
  }
  display.setTextSize(1);
  if (tmp3 == 2) return true;
  return false;
}

void settingsEEPROM() {
  int8_t tmp2 = 0;
  bool draw2 = true;
  while (!digitalRead(ctl));
  ctrl.reset();
  display.setTextSize(1);
  while (tmp2 >= 0) {
    while (ctrl.clicks >= 0) {
      if (draw2) {
        display.clearDisplay();
        display.setCursor(0, 0);
        for (uint8_t a = 0; a < 5; a++) {
          (a == tmp2) ? display.setTextColor(BLACK, WHITE) :
          display.setTextColor(WHITE, BLACK);
          switch (a) {
            case 0:
              display.print(F("    Save Settings    ")); break;
            case 1:
              display.print(F("    Load Settings    ")); break;
            case 2:
              display.print(F("   Device Defaults   ")); break;
            case 3:
              display.print(F("  Bluetooth Defaults ")); break;
            case 4:
              display.print(F("         Back        ")); break;
          }
        }
        display.display();
        draw2 = false;
      }
      ctrl.Update();

      if (ctrl.clicks == 1) {
        (tmp2 < 4) ?
        tmp2++ : tmp2 = 0;
        draw2 = true;
        ctrl.reset();
      }
      if (bt.available())
        receiveBT();
    }
    switch (tmp2) {
      case 0:
        if (permissionWindow()) {
          btctl(F("DS")); display.print(F("\n\nSaved"));
        }
        else display.print(F("\n\nAbort"));
        display.display(); break;
      case 1:
        if (permissionWindow()) {
          btctl(F("DL")); display.print(F("\n\nLoaded"));
        }
        else display.print(F("\n\nAbort"));
        display.display(); break;
      case 2:
        if (permissionWindow()) {
          btctl(F("DD")); display.print(F("\n\nRestored Defaults"));
        }
        else display.print(F("\n\nAbort"));
        display.display(); break;
      case 3:
        if (permissionWindow()) {
          display.print(F("\n\nPlease wait...\n")); display.display();
          btctl(F("DB")); display.print(F("Restored Defaults"));
        }
        else display.print(F("\n\nAbort"));
        display.display(); break;
      case 4: tmp2 = -1; break;
    }
    delay(1000);
    draw2 = true;
    ctrl.reset();
    while (!digitalRead(ctl));
  }
  return void();
}

void poweroff() {
  bool _btpow = false;
  if (digitalRead(btpow)) _btpow = true;
  bool _dimlcd = dimlcd;
  bool _ledon = ledon;
  bool _lcdon = lcdon;
  if (_lcdon) btctl(F("D00;"));
  if (_dimlcd) btctl(F("D10;"));
  if (_btpow) btctl(F("D20;"));
  if (_ledon) btctl(F("D30;"));
  while (!digitalRead(ctl));
  delay(50);
  attachInterrupt(0, poweron, LOW);
  delay(50);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();

  sleep_disable();

  if (_lcdon) btctl(F("D01;"));
  if (_dimlcd) btctl(F("D11;"));
  if (_btpow) btctl(F("D21;"));
  if (_ledon) btctl(F("D31;"));
  return void();
}

void poweron() {
  detachInterrupt(0);
  return void();
}

void splash() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(2);
  display.println(F("Kubkuino"));
  display.setTextSize(1);
  display.println(F(VERSION));
  display.print(__TIME__);
  display.print(F(" "));
  display.print(__DATE__);
#if defined DEBUG
  display.print(F("DEBUG"));
#endif
  display.display();
  return void();
}

void defEEPROM() {
  if (!digitalRead(btconn))
    digitalWrite(btpow, LOW);
  glosny = true;
  lcdon = true;
  ledon = true;
  dimlcd = false;
  hot = 60;
  cold = 45;
  EEPROM.put(0, (char)'A');
}

void saveEEPROM() {
  uint8_t addr = sizeof(char);
  EEPROM.update(addr, hot);
  addr += sizeof(int8_t);
  EEPROM.update(addr, cold);
  addr += sizeof(int8_t);
  EEPROM.update(addr, glosny);
  addr += sizeof(bool);
  EEPROM.update(addr, lcdon);
  addr += sizeof(bool);
  EEPROM.update(addr, dimlcd);
  addr += sizeof(bool);
  EEPROM.update(addr, ledon);
  addr += sizeof(bool);
  EEPROM.update(addr, (bool)digitalRead(btpow));
}

void getEEPROM() {
  uint8_t addr = sizeof(char);
  EEPROM.get(addr, hot);
  addr += sizeof(int8_t);
  EEPROM.get(addr, cold);
  addr += sizeof(int8_t);
  EEPROM.get(addr, glosny);
  addr += sizeof(bool);
  EEPROM.get(addr, lcdon);
  addr += sizeof(bool);
  EEPROM.get(addr, dimlcd);
  addr += sizeof(bool);
  EEPROM.get(addr, ledon);
  addr += sizeof(bool);
  bool _btpow;
  EEPROM.get(addr, _btpow);
  digitalWrite(btpow, (_btpow) ? HIGH : LOW);
  (lcdon) ? btctl(F("D01")) : btctl(F("D00"));
  (dimlcd) ? btctl(F("D11")) : btctl(F("D10"));
  (ledon) ? btctl(F("D31")) : btctl(F("D30"));
  (glosny) ? btctl(F("D41")) : btctl(F("D40"));
}
