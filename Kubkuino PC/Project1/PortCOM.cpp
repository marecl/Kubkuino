#include "PortCOM.h"
#using <System.dll>
using namespace System::IO::Ports;
using namespace System;

bool PortCOM::initPort(System::String^ a)
{
	seryjny = gcnew SerialPort();
	seryjny->PortName = a;
	seryjny->ReadTimeout = 5000;
	String^ test;
	try {
		seryjny->Open();
		seryjny->WriteLine("e;");
		test = seryjny->ReadLine();
	}
	catch (System::IO::IOException^ e) { //Port nie istnieje
		System::Windows::Forms::MessageBox::Show("Nieprawid³owy port", "B³¹d", System::Windows::Forms::MessageBoxButtons::OK);
		if (seryjny->IsOpen) seryjny->Close();
		return false;
	}
	catch (SystemException^ e) { //Timeout albo zly port
		System::Windows::Forms::MessageBox::Show(L"Nie mo¿na po³¹czyæ z urz¹dzeniem", "B³¹d", System::Windows::Forms::MessageBoxButtons::OK);
		if (seryjny->IsOpen) seryjny->Close();
		return false;
	}

	test = test->Trim();
	/*seryjny->Open();
	seryjny->DiscardInBuffer();
	seryjny->DiscardOutBuffer();
	seryjny->Write("e;");
	String^ x = seryjny->ReadLine();*/
	if (test->Contains("HELLO_IR")) {
		return true;
	}
	else return false;
}

void PortCOM::PortClose() {
	seryjny->Write("qquit;");
	seryjny->Close();
}

void PortCOM::PortHot(double x) {
	seryjny->Write("H" + Convert::ToString(x) + ";");
}

void PortCOM::PortCold(double x) {
	seryjny->Write("C" + Convert::ToString(x) + ";");
}

void PortCOM::PortBtDefault() {
	seryjny->Write("DB;");
}

void PortCOM::PortDefault() {
	seryjny->Write("DD;");
}

void PortCOM::PortLED(bool x) {
	seryjny->Write(x ? "D31;" : "D30;");
	return;
}

void PortCOM::PortAlarm(bool x) {
	seryjny->Write(x ? "D41;" : "D40;");
	return;
}

void PortCOM::PortScreen(bool x) {
	seryjny->Write(x ? "D01;" : "D00;");
	return;
}

void PortCOM::PortLight(bool x) {
	seryjny->Write(x ? "D11;" : "D10;");
	return;
}

String^ PortCOM::PortStatus() {
	seryjny->DiscardInBuffer();
	seryjny->DiscardOutBuffer();
	seryjny->Write("D5;");
	String^ tempState = seryjny->ReadLine();
	return tempState;
}


String^ PortCOM::PortCommute(String^ x) {
	while (wolny == false) {
		Sleep(300);
	}
	wolny = false;
	seryjny->DiscardInBuffer();
	seryjny->DiscardOutBuffer();
	seryjny->Write(x);
	String^ l;
	try {
		l = Convert::ToString(seryjny->ReadLine());
		wolny = true;
	}
	catch (...) {
		l = "Error";
	}
	wolny = true;
	return l;

}

String^ PortCOM::PortTemp(String^ prev) {
	while (wolny == false) {
		Sleep(300);
	}
	wolny = false;
	seryjny->Write("r;");
	String^ got = seryjny->ReadLine();
	wolny = true;
	if (prev == got || got == "") return prev;
	else return got;
}

void PortCOM::PortZapiszU() {
	seryjny->Write("DS;");
}
void PortCOM::PortWczytajU() {
	seryjny->Write("DL;");
}

void PortCOM::PortLEDO() {
	seryjny->Write("D3?");
	String^ x = seryjny->ReadLine();
	if (x[2] == '1')
		LED = true;
	else
		LED = false;
}
void PortCOM::PortAlarmO() {
	seryjny->Write("D4?");
	String^ x = seryjny->ReadLine();
	if (x[2] == '1')
		Alarm = true;
	else
		Alarm = false;
}
void PortCOM::PortScreenO() {
	seryjny->Write("D0?");
	String^ x = seryjny->ReadLine();
	if (x[2] == '1')
		Screen = true;
	else
		Screen = false;
}
void PortCOM::PortLightO() {
	seryjny->Write("D1?");
	String^ x = seryjny->ReadLine();
	if (x[2] == '1')
		Light = true;
	else
		Light = false;
}