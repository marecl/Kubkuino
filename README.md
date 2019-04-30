# Contactless liquid watchdog

Perfect for watching your coffee. Now you won't forget, that you've made one.

Directories:  
	* Dokumentacje - Documentation and final version of PC software  
	* Kubkuino - source code and case drawings  
	* Kubkuino_PC - PC software sources  
	* Obsolete - Old version  
	* RawDoc - Raw data for documentation  

ToDo list:  
	-Notification bar alarm,  
	-Print all COM ports on startup,   
	-Manual,  
	-Automatic config creation,
	-Migrate to V-USB?
  
Navigation:  
	1 click - enter menu/next item  
	Press and hold - Select/switch  
	
Arduino:  
  
	Source:  
		#define _NAME (String)"[NAME]" - Device default name  
		#define _PASS (String)"[4 digits]" - Set Bluetooth pairing PIN code  
		#define TONE [freq/tone] - Alarm frequency (or tone, based on vars.h)  
		#define ALARM_TIME [milliseconds] - Alarm duration  
  
	Bluetooth commands:  
		e; - Establish a connection (returns "HELLO\r\n") - must be sent!  
		qquit; - Disconnect - must be sent! 
		CXX.X; - Set 'cold' temperature  
		HXX.X; - Set 'hot' temperature  
		C?;/H?; - Check temperatures  
		r; - Current reading  
		S[AT command]; - Executes arbitary AT command, returns module's response  
		DXY; - Management:  
			0Y* - LCD  
			1Y* - Backlight  
			2Y* - Bluetooth  
			3Y* - LED  
			4Y* - Alarm mute  
			5 - Status of: LCD, Backlight, LED, Mute (4 bits)
			6 - Sleep mode  
			B - Revert bluetooth module to factory defaults  
			D - Device defaults  
			L - Load settings from EEPROM  
			S - Save settings to EEPROM  
  
		*(0 - OFF, 1 - ON, ? - Check status)