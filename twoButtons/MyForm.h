#pragma once
#include <string>
#include <iostream>
#include "Header.h"
//#include "C:/Program Files (x86)/Reference Assemblies/Microsoft/Framework/.NETFramework/v4.7.2/mscorlib.dll"
//#include "C:/Program Files (x86)/Reference Assemblies/Microsoft/Framework/.NETFramework/v4.7.2/mscorlib.dll"

bool global_variable1 = false;
bool global_variable2 = false;
int val1 = 0;
int val2 = 0;


static void func(int x) {
	std::cout << x;
}

public delegate void MyDelegate(int x);


namespace twoButtons {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Threading;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{


	public:
		ThreadHandler^ handler1;
		ThreadHandler^ handler2;
		Thread^ thread1;
		Thread^ thread2;

		MyForm(void)
		{
			InitializeComponent();
		}
	protected:

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	protected:
	private: System::Windows::Forms::Button^ button2;
		   /// <summary>
		   /// Clean up any resources being used.
		   /// </summary>
		   ~MyForm()
		   {
			   if (components)
			   {
				   delete components;
			   }
		   }

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(140, 131);
			this->button2->Margin = System::Windows::Forms::Padding(6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(288, 75);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(140, 293);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(288, 66);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(140, 462);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(288, 65);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Exit";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(568, 651);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion


	public:
	private:

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		handler1 = gcnew ThreadHandler();
		thread1 = gcnew Thread(gcnew ThreadStart(handler1, &ThreadHandler::coreFunction));
		thread1->Name = "thread1";
		handler1->printVar = 1;

		handler2 = gcnew ThreadHandler();
		thread2 = gcnew Thread(gcnew ThreadStart(handler2, &ThreadHandler::coreFunction));
		thread2->Name = "thread2";
		handler2->printVar = 2;

		thread1->Start();
		thread2->Start();
		
		Console::WriteLine("Threads initialised.. Waiting for start..");
	}
	

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		handler1->runCommand = true;
		handler2->runCommand = true;
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		handler1->runCommand = false;
		handler2->runCommand = false;
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		handler1->exitFunction = true;
		handler2->exitFunction = true;

		thread1->Join();
		thread2->Join();

		Form::Close();
	}
};
}
