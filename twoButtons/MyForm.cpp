#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
//int main (array＜String^＞^args )
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	twoButtons::MyForm form; //GUI_2 is the solution name
	Application::Run(% form);
	return 0;
}