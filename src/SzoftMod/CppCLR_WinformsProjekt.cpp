#include "pch.h"


using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

#include "Form1.h";
#include "calcmodule.h";

static std::string toStandardString(System::String^ myString)
{
	System::IntPtr pointer = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(myString);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, myString->Length);
	System::Runtime::InteropServices::Marshal::FreeHGlobal(pointer);
	return returnString;
}


static String^ toSystemString(std::string myString)
{
	String^ returnString = gcnew String(myString.c_str());
	return returnString;
}


using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 
	return 0;
}