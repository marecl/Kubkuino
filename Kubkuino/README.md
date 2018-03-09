# Specjalizowany czujnik temperaturowy:
## Mikroprocesorowy analizator cieplny 

Zrobiłeś kawę albo herbatę i nie chcesz pilnować aż ostygnie? To coś dla Ciebie!

Ta wersja będzie rozwijana dalej na głównym programie - uwaga na inny rozkład komend!!!  

Do zrobienia:
	1. Zapisywanie odebranych ustawień w EEPROM
	2. Resety potwierdzane + timeout  
	3. Reset urządzenia  

Komendy:  
	X - Pierwszy argument  
	Y - Drugi argument  
  
	e; - Nawiązanie połączenia (zwraca "HELLO_IR\r\n") Może ale nie musi zostać wysłane - po prostu wiemy że to to   
	qquit; - Rozłączenie MUSI ZOSTAĆ WYSŁANE (specjanie takie długie - na wypadek błędu komunikacji,  
		który wysyła 'q' zamiast 'r'. Nie wiem czemu.)  
	CXX.X; - Ustawienie temperatury zimna  
	HXX.X; - Ustawienie temperatury ciepła  
		C?;/H?; - sprawdzenie temperatur  
	S[komenda AT]; - Przesyła komendę AT do modułu Bluetooth. Zwraca odpowiedź modułu.  
	db; - Reset modułu Bluetooth (zwraca 4x OK albo Error(0)) 
	dd; - Reset Kubkuino do ustawień domyślnych  
	ds; - Zapisuje obecny stan do EEPROM
	dl; - Przywraca ustawienia zapisane w EEPROM
	r - Zwraca bieżący odczyt z czujnika  
	DXY; - Moduł zarządzania komponentami:  
		0Y* - LCD (1 - włącz, 0 - wyłącz)  
		1Y* - Ściemnienie wyświetlacza (1 - włącz, 0 - wyłącz)  
		2Y - BT (1 - włącz, 0 - wyłącz)  
		3Y* - LED (1 - włącz, 0 - wyłącz)  
		4Y* - Alarm (1 - wyciszony, 0 - głośny)  
		5 - Status LCD, Podświetlenie, LED, Alarm (1 - włączony, 0 - wyłączony)  
		6 - Przejście w tryb uśpienia  
  
	*Jak jako argument poda się znak zapytania (?) zostanie zwrócony stan pojedynczego modułu  
  
Każda komenda jest zakończona średnikiem ';'!  
