#include <Adafruit_BMP085.h>
#include <ClickButton.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include "pitches.h"
#define ctl 2 //Button - interrupt needed for wakeup
#define buzz 3 //Buzzer
#define btpow 4 //Bt Power
#define btx 5 //Bluetooth TX
#define brx 6 //Bluetooth RX
#define btkey 7 //Bt Key pin
#define rled A3
#define gled A2
#define bled A1

/* Customizable stuff */
#define NAME "HC-05" //Can be changed ie. for specific location like "kitchen"
#define PASSWORD "0000" //We don't want others to mess with our coffe... Right?

#define TONE NOTE_D2 //Change tone (See pitches.h for available notes)
#define ALARM_TIME 10000 //How long should alarm take

/* Pomiary */
int mode = 0; //Tryb
double hot = 60; //60
double cold = 47; //47
double pomiar, pomiarpop;

/* Bluetooth */
const String ndefcom = "AT+NAME="; //Set default name
const String ndefout = ndefcom + NAME;
const String pdefcom = "AT+PSWD="; //Set default password
const String pdefout = pdefcom + PASSWORD;
bool conn = false; //Is BT device connected?

/* Komunikacja */
String input = ""; //Input string
char command; //Command

/* Alarm */
bool wylalarm = true; //Snooze
bool czymaalarm = false; //Should launch alarm
bool czyzimna = true; //If was previously cold
bool mute = false; //Should beep?

/* Zasilanie */
bool ledon = true; //LED state

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
String modes[] = { //Available modes - I don't think other are needed
  "CERAMIKA ",
  "ALUMINIUM",
  "SZKLANKA "
};

//RTC - 0x68 DS1307
Adafruit_BMP085 czuj;
SoftwareSerial bt(btx, brx); //tx, rx
void setup() {
  pinMode(btpow, OUTPUT);
  pinMode(btkey, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(rled, OUTPUT);
  pinMode(gled, OUTPUT);
  pinMode(bled, OUTPUT);
  pinMode(ctl, INPUT);
  czuj.begin();
  digitalWrite(rled, LOW);
  digitalWrite(gled, LOW);
  digitalWrite(bled, LOW);
  digitalWrite(btkey, LOW);
  digitalWrite(btpow, HIGH);
  bt.begin(38400);
}

void loop() {
  updatemp(mode);
  alarm();
  if (bt.available()) { //In case of bluetooth commands
    input = bt.readStringUntil(';'); //;\r\n will be discarded
    bt.flush();
    btctl(input);
    input = "";
  }
}

void alarm() { //Prints state
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
    if (ledon == true) {
      digitalWrite(rled, LOW);
      digitalWrite(gled, LOW);
      digitalWrite(bled, HIGH);
    }
  } else if (pomiarpop >= cold && pomiarpop <= hot) {
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
    updatemp(mode);
    if (bt.available()) { //In case of bluetooth commands - avoid timeout
      input = bt.readStringUntil(';');
      bt.flush();
      btctl(input);
      input = "";
    }
  }
  while (digitalRead(ctl) == LOW) //Wait while button is pressed
    updatemp(mode);
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
                0 - LCD, 1 - BT, 2 - BT+LCD, 3 - LED,
                4 - Mute, 5 - LCD backlight, 6 - Shutdown
                7 - Send string what is enabled (0,3,4,5)
                  0 - disabled, 1 - enabled, 2 - unimplemented
                0 - disable, 1 - enable
    d; - Sets default name and password
    c; - Prints cold
    h; - Prints hot
    r; - Prints sensor temperature and patched temperature - Returns XX.X/YY.Y
    t; - Returns state as char (H - Hot, R - Ready, C - Cold)
    m; - Returns mode (CERAMIKA, ALUMINIUM, SZKLO)
      K; - Command accepted
      N; - Command rejected*/
void btctl(String tinput) { //We don't want to \r or \n mess with our input
   String tempout = ""; 
  if (input == "\r\n" || input == "\n" || input == "\r") return (0);
  command = tinput.charAt(0);
  if (tinput.length() > 1)
    tinput.remove(0, 1);
  switch (command) {
    case 'e': bt.print("HELLO\r\n"); conn = true; break; //Response to show we are connected to right device
    case 'h': bt.print(hot); bt.print("\r\n"); break; //Prints hot
    case 'c': bt.print(cold); bt.print("\r\n"); break; //Prints cold
    case 'r': if (tinput[0] == "0") bt.print(czuj.readTemperature()); //Prints sensor reading
      else bt.print(pomiarpop); //Or patched value
      bt.print("\r\n"); break;
    case 'm': input = modes[mode]; input.trim(); //Send current mode as text
      bt.print(input); bt.print("\r\n"); break;
    case 't': if (pomiarpop > hot) bt.print("H\r\n"); //Send state
      if (pomiarpop < cold) bt.print("C\r\n");
      if (pomiarpop >= cold && pomiarpop <= hot) bt.print("R\r\n"); break;
    case 'd': service("AT+ORGL"); service(ndefout); service(pdefout); break; //Reset to defaults
    case 'q': if (tinput == "quit") {
        conn = false; service("AT+DISC"); digitalWrite(btpow, LOW); //End connection
        delay(100); digitalWrite(btpow, HIGH);
      }
      break; //tak trzeba bo sie arduino zacina
    case 'H': if (tinput.length() >= 1) hot = atof(tinput.c_str()); //Set hot
      bt.print("\r\n"); break;
    case 'C': if (tinput.length() >= 1) cold = atof(tinput.c_str()); //Set cold
      bt.print("\r\n"); break;
    case 'M': if (tinput.length() == 1) mode = (atoi(tinput.c_str())) % 3; //Set mode
      bt.print("\r\n"); break;
    case 'S': if (tinput.length() >= 2 ) service(tinput); //Send AT commands
      break;
    case 'D': switch (tinput[0]) { //Power menu uses it
        case '0': bt.print("No device");
        case '1': if (tinput[1] == '0') { //BT
            service("AT+DISC"); digitalWrite(btpow, LOW); conn = false;
          } if (tinput[1] == '1') digitalWrite(btpow, HIGH);
          break;
        case '2': bt.print("No device");
        case '3': if (tinput[1] == '0') { //LED
            ledon = false;
            digitalWrite(rled, LOW);
            digitalWrite(gled, LOW);
            digitalWrite(bled, LOW);
          } else ledon = true; break;
        case '4': if (tinput[1] == '0') { //Piezo
            tone(buzz, TONE); delay(500); noTone(buzz);
            mute = true; //Everything can be removed but this
          } else {
            tone(buzz, TONE); delay(75); noTone(buzz); delay(250);
            tone(buzz, TONE); delay(75); noTone(buzz);
            mute = false; //Here too
          } break;
        case '5': bt.print("No device");
        case '6': poweroff(); break; //Shutdown
        case '7'://Send what is enabled
          //2, LED, MUTE, 2
          tempout += "2";
          if (ledon == true) tempout += "1"; else tempout += "0";
          if (mute == true) tempout += "1"; else tempout += "0";
          tempout += "2";
          bt.print(tempout); break;
      } bt.print("\r\n"); break;
  }
}

//Command must be sent without \r\n terminator.
void service(String a) {
  if (a == "AT+DISC") conn = false;
  a += "\r\n";
  digitalWrite(btkey, HIGH);
  delay(500);
  for (int z = 0; z < a.length(); z++)
    bt.write(a[z]);
  long long temptime = millis();
  while (bt.available() == 0 && (millis() - temptime) <= 5000) {}
  if (bt.available() != 0)
    a = bt.readStringUntil('\0');
  else a = "REQUEST TIMEOUT\r\n"; //If module dosen't work. Mostly because it's disabled
  digitalWrite(btkey, LOW); delay(500);
  bt.flush();
  /*Remove trash*/
  a.trim();
  for (int g = 0; g < a.length(); g++) {
    if (a[g] == 0x0A || a[g] == 0x0D)
      a.remove(g);
  }
  a.trim();
  /*Now we can respond*/
  if (conn == true) bt.print(a + "\r\n");
}

//Wypisuje temperature w odpowiednim miejscu
//Chyba ze -1 i -1, wtedy pisze jak leci
//Moze kiedys sie przyda
void updatemp(int a) {
  pomiar = czuj.readTemperature();
  pomiarpop = poprawka(a, pomiar);
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
  bool btbak = false;
  if (digitalRead(btpow) == HIGH) btbak = true;
  bool ledbak = ledon;
  if (btbak == true) btctl("D10;");
  if (ledbak == true) btctl("D30;");
  while (digitalRead(ctl) == LOW);
  attachInterrupt(0, poweron, LOW);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  //Put to sleep
  sleep_mode();
  //Wakes up now
  sleep_disable();
  detachInterrupt(0);
  if (btbak == true) btctl("D11;");
  if (ledbak == true) btctl("D31;");
}
void poweron() {
}
