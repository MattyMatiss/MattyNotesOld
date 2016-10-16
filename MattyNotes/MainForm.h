#pragma once


#include "stdafx.h"
#include "MattyTime.h"
using namespace std;
namespace MattyNotes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:




	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  Clocks;






	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->Clocks = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->monthCalendar1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->monthCalendar1->Location = System::Drawing::Point(27, 108);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(244, 108);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(469, 369);
			this->panel1->TabIndex = 2;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->richTextBox2);
			this->groupBox2->Location = System::Drawing::Point(64, 251);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(323, 180);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"\?\?\?\?\?\?\?\?\?";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(215, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(85, 15);
			this->label5->TabIndex = 3;
			this->label5->Text = L"\?\?\?\? \?\?\?\?\?\?\?\?:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(110, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 15);
			this->label6->TabIndex = 2;
			this->label6->Text = L"\?\?\?\? \?\?\?\?\?\?\?";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(16, 36);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 15);
			this->label7->TabIndex = 1;
			this->label7->Text = L"\?\?\? \?\?\?\?\?\?\?";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox2->BackColor = System::Drawing::Color::Snow;
			this->richTextBox2->Location = System::Drawing::Point(19, 67);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(284, 96);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Location = System::Drawing::Point(64, 44);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(323, 180);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"\?\?\?\?\?\?\?\?\?";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(215, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 15);
			this->label4->TabIndex = 3;
			this->label4->Text = L"\?\?\?\? \?\?\?\?\?\?\?\?:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(110, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"\?\?\?\? \?\?\?\?\?\?\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"\?\?\? \?\?\?\?\?\?\?";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::Color::Snow;
			this->richTextBox1->Location = System::Drawing::Point(19, 67);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(284, 96);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// Clocks
			// 
			this->Clocks->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Clocks->AutoSize = true;
			this->Clocks->Font = (gcnew System::Drawing::Font(L"Century Gothic", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clocks->ForeColor = System::Drawing::Color::Indigo;
			this->Clocks->Location = System::Drawing::Point(12, 9);
			this->Clocks->Name = L"Clocks";
			this->Clocks->Size = System::Drawing::Size(191, 78);
			this->Clocks->TabIndex = 3;
			this->Clocks->Text = L"10:12";
			this->Clocks->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::Clocks_MouseDoubleClick);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Ivory;
			this->ClientSize = System::Drawing::Size(888, 500);
			this->Controls->Add(this->Clocks);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->monthCalendar1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"MattyNotes";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		streambuf* orig_buf = cout.rdbuf();
		cout.rdbuf(NULL);
		// cout.rdbuf(orig_buf); for enabling
		MattyTime^ temp = gcnew MattyTime();
		MattyTime::PrintCurrDate();
		MattyTime::PrintCurrTime();
		MattyTime::PrintCurrTimeAndDate();
		MattyTime::PrintCurrTimeFull();
		MattyTime::PrintCurrTimeFullAndDate();
		temp->PrintUserDate();
		temp->PrintUserTime();
		temp->PrintUserTimeAndDate();
		temp->PrintUserTimeFull();
		temp->PrintUserTimeFullAndDate();
		Clocks->Text = MattyTime::PrintCurrTime();
	}
	private: System::Void Clocks_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (Clocks->Text->Length <= 5)
			Clocks->Text = MattyTime::PrintCurrTimeFull();
		else
			Clocks->Text = MattyTime::PrintCurrTime();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (Clocks->Text->Length <= 5)
			Clocks->Text = MattyTime::PrintCurrTime();
		else
			Clocks->Text = MattyTime::PrintCurrTimeFull();
	}
	};
}