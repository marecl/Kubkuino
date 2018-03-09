#include "Connect.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String ^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project1::Connect form;
	Application::Run(%form);
	return 0;
}