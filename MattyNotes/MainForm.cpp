#include "stdafx.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MattyNotes::MainForm form;   //MattyNotes - name of your project
	Application::Run(%form);
}