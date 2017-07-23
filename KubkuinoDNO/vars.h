/*
   Zmniejszamy bałagan w głównym pliku
*/

/* Pomiary */
uint8_t mode = 0; //Tryb
uint8_t tryb = 0; //0 - auto, 1 - wymus, 2 - reczny, 3 - dno
double hot = 60; //60
double cold = 47; //47
double pomiar, pomiarpop;
bool plaskie = true; //true - plaskie, false - wklesle/inne

/* Bluetooth */
bool conn = false; //Polaczony?

/* Alarm */
bool wylalarm = true; //Drzemka?
bool czymaalarm = false; //Czy ma sie odpalac
bool czyzimna = true; //Czy wczesniej byla zimna
bool glosny = true; //Czy ma piszczec?

/* Zasilanie */
bool lcdon = true;
bool ledon = true;
bool lcdled = true;

String modes[] = { //Popularne materiały
  "CERAMIKA ",
  "ALUMINIUM",
  "SZKLANKA "
};

String pomiary[] = {
  " AUTOMATYCZNY ",
  " WYMUS POMIAR ",
  "    RECZNY    ",
  "  TYLKO DNO   "
};

String wybor[] = {
  "Plaskie",
  "Wklesle"
};

String powermodes[] = { //Settings list
  " Bluetooth:",
  "   LED: ",
  "  Alarm: ",
  "Tlo ekranu:",
  "    Wylacz    ",
  "    POWROT    "
};
uint8_t lar[] = { //Lewa strzalka
  0x00, 0x01, 0x03, 0x07, 0x07, 0x03, 0x01, 0x00
};
uint8_t rar[] = { //Prawa strzalka
  0x20, 0x30, 0x38, 0x3C, 0x3C, 0x38, 0x30, 0x20
};
uint8_t st[] = { //Znak stopnia
  0x06, 0x9, 0x9, 0x06, 0x00, 0x00, 0x00, 0x00
};
uint8_t icon[] = { //Bluetooth
  0x04, 0x06, 0x15, 0x0E, 0x0E, 0x15, 0x06, 0x04
};

double poprawka(int tmode, double x) {
  if (x > 27) {
    if (plaskie) {
      switch (tmode) {
        case 0: return (-0.0000266014 * pow(x, 4) + 0.0049087474 * pow(x, 3) - 0.3324086598 * pow(x, 2) + 10.4414317754 * x - 97.8338242811);
          break;
        case 1: return (-0.0000002259 * pow(x, 5) + 0.0000546227 * pow(x, 4) - 0.005166266 * pow(x, 3) + 0.2374061139 * pow(x, 2) - 4.4286915613 * x + 48.8052073927);
          break;
        case 2: return (-0.0000103493 * pow(x, 4) + 0.0017075599 * pow(x, 3) - 0.1025942957 * pow(x, 2) + 3.2203268079 * x - 14.8065137218);
          break;
      }
    } else if (tryb == 1) {
      switch (tmode) {
        case 0: return (-0.0000000523 * pow(x, 6) + 0.0000181290 * pow(x, 5) - 0.0025664649 * pow(x, 4) + 0.1892512408 * pow(x, 3) - 7.6528408984 * pow(x, 2) + 161.3202013939 * x - 1361.6192106802);
          break;
        case 1: return (-0.0000228971 * pow(x, 4) + 0.0050144170 * pow(x, 3) - 0.4037994853 * pow(x, 2) + 14.8490090694 * x - 175.6283333484);
          break;
        case 2: return (-0.0000105179 * pow(x, 4) + 0.0016541754 * pow(x, 3) - 0.0958791221 * pow(x, 2) + 2.9379906334 * x - 11.7620175007);
          break;
      }
    }
  }
  return x;
}

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
