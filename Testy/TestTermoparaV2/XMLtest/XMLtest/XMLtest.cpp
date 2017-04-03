// XMLtest.cpp : main project file.

#include "stdafx.h"
#include <tchar.h>
#using <mscorlib.dll>
#using <System.xml.dll>

using namespace System;
using namespace System::Xml;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
    if(File::Exists("config.xml")){
		XmlTextReader^ config = gcnew XmlTextReader("config.xml");
		while(config->Read()){
			switch(config->NodeType){
				case XmlNodeType::Element:
					Console::Write(config->Name + L" = ");break;
				case XmlNodeType::Text:
					Console::WriteLine(config->Value);break;
				case XmlNodeType::EndElement:
					config->MoveToNextAttribute();
			}
		}
	}
	Console::ReadLine();
}
