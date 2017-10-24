#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	yazlabProject2::mainForm form;
	try {
		Application::Run(%form);
	}
	catch (...) {

	}


}