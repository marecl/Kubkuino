#pragma once

#include <windows.h>
#using <System.dll>
using namespace System::IO::Ports;
using namespace System;

public ref class PortCOM
{
public:
	static bool LED;
	static bool Alarm;
	static bool Light;
	static bool Screen;
	static bool initPort(System::String ^ a);
	static void PortClose();
	static void PortHot(double x);
	static void PortCold(double x);
	static void PortDefault();
	static void PortBtDefault();
	static String^ PortTemp(String^ prev);

	static void PortZapiszU();
	static void PortWczytajU();

	static void PortLED(bool x);
	static void PortAlarm(bool x);
	static void PortScreen(bool x);
	static void PortLight(bool x);
	static String^ PortCommute(String^ x);
	static String^ PortStatus();

	static void PortLEDO();
	static void PortAlarmO();
	static void PortScreenO();
	static void PortLightO();
private:
	static SerialPort^ seryjny;
	static bool wolny = true;
};

