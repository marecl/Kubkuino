# Bezkontaktowy czujnik temperaturowy:
## Mikroprocesorowy analizator cieplny

Zrobiłeś kawę albo herbatę i nie chcesz pilnować aż ostygnie? To coś dla Ciebie!

Foldery:  
	* Dokumentacje - Instrukcje obsługi i program  
	* Kubkuino - kod źródłowy i model obudowy  
	* Kubkuino_PC - kod źródłowy aplikacji na PC  
	* Obsolete - starsze wersje urządzenia  
	* RawDoc - surówki do dokumentacji  

Do zrobienia:  
	-Alarm w pasku powiadomień,  
	-Wypis nazwy urządzenia przy wyborze portu COM,   
	-Manual (nie, ReadMe się nie liczy),  
	-Automatyczne tworzenie nowego pliku do zapisu danych,
  
Nawigacja:  
	1 klik - wejście do menu/następna pozycja  
	Przytrzymanie - wybór/przełączenie pozycji
	
Arduino:  
  
	Kod:  
		#define _NAME (String)"[NAZWA]" - Ustawia nazwę jako domyślną  
		#define _PASS (String)"[4 cyfry]" - Ustawia wpisane cyfry jako hasło do parowania  
		#define TONE [TON] - Dźwięk alarmu (uzupełnić na podstawie vars.h)  
		#define ALARM_TIME [milisekundy] - Ile milisekund Arduino ma piszczeć  
  
	Komendy:  
		e; - Nawiązanie połączenia (zwraca "HELLO\r\n") MUSI ZOSTAĆ WYSŁANE  
		qquit; - Rozłączenie MUSI ZOSTAĆ WYSŁANE (specjanie takie długie - na wypadek błędu komunikacji,  
			który wysyła 'q' zamiast 'r'. Nie wiem czemu.)  
		CXX.X; - Ustawienie temperatury zimna  
		HXX.X; - Ustawienie temperatury ciepła  
		C?;/H?; - sprawdzenie temperatur  
		r; - Temperatura z czujnika  
		S[komenda AT]; - Przesyła komendę AT do modułu Bluetooth. Zwraca odpowiedź modułu.  
		DXY; - Moduł zarządzania komponentami:  
			0Y* - LCD  
			1Y* - Podswietlenie  
			2Y* - Bluetooth  
			3Y* - LED  
			4Y* - Wyciszenie  
			5 - Status LCD, Podświetlenie, LED, Alarm
			6 - Przejście w tryb uśpienia  
			B - Przywrócenie modułu Bluetooth do ustawień fabrycznych  
			D - Domyślne ustaiwienia urządzenia  
			L - wczytanie ustawień z pamięci urządzenia  
			S - zapis ustawień do pamięci urządzenia  
  
		*(0 - wyłączony, 1 - włączony, ? - zwraca czy jest włączony)