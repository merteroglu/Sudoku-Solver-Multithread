#pragma once

#include "Solver.h"
#include <Windows.h>
#include <process.h>

namespace yazlabProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    int sudoku[9][9];
	int sudokuT1[9][9];
	int sudokuT2[9][9];
	int sudokuT3[9][9];
	int sudokuT4[9][9];

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
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
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Button^  btnCoz;
	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::TextBox^  txtPath;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  btnT1;
	private: System::Windows::Forms::Label^  labelT1Durum;
	private: System::Windows::Forms::Label^  labelT1Step;
	private: System::Windows::Forms::Label^  labelT1Time;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  btnT2;
	private: System::Windows::Forms::Label^  labelT2Durum;
	private: System::Windows::Forms::Label^  labelT2Step;
	private: System::Windows::Forms::Label^  labelT2Time;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  btnT3;
	private: System::Windows::Forms::Label^  labelT3Durum;
	private: System::Windows::Forms::Label^  labelT3Step;
	private: System::Windows::Forms::Label^  labelT3Time;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Button^  btnT4;
	private: System::Windows::Forms::Label^  labelT4Durum;
	private: System::Windows::Forms::Label^  labelT4Step;
	private: System::Windows::Forms::Label^  labelT4Time;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  labelTest;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnCoz = (gcnew System::Windows::Forms::Button());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->txtPath = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnT1 = (gcnew System::Windows::Forms::Button());
			this->labelT1Durum = (gcnew System::Windows::Forms::Label());
			this->labelT1Step = (gcnew System::Windows::Forms::Label());
			this->labelT1Time = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->btnT2 = (gcnew System::Windows::Forms::Button());
			this->labelT2Durum = (gcnew System::Windows::Forms::Label());
			this->labelT2Step = (gcnew System::Windows::Forms::Label());
			this->labelT2Time = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->btnT3 = (gcnew System::Windows::Forms::Button());
			this->labelT3Durum = (gcnew System::Windows::Forms::Label());
			this->labelT3Step = (gcnew System::Windows::Forms::Label());
			this->labelT3Time = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->btnT4 = (gcnew System::Windows::Forms::Button());
			this->labelT4Durum = (gcnew System::Windows::Forms::Label());
			this->labelT4Step = (gcnew System::Windows::Forms::Label());
			this->labelT4Time = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->labelTest = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnCoz);
			this->groupBox1->Controls->Add(this->btnOpen);
			this->groupBox1->Controls->Add(this->txtPath);
			this->groupBox1->Location = System::Drawing::Point(12, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(313, 50);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Dosya Seç";
			// 
			// btnCoz
			// 
			this->btnCoz->Location = System::Drawing::Point(224, 19);
			this->btnCoz->Name = L"btnCoz";
			this->btnCoz->Size = System::Drawing::Size(75, 23);
			this->btnCoz->TabIndex = 2;
			this->btnCoz->Text = L"Çöz";
			this->btnCoz->UseVisualStyleBackColor = true;
			this->btnCoz->Click += gcnew System::EventHandler(this, &mainForm::btnCoz_Click);
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(143, 19);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(75, 23);
			this->btnOpen->TabIndex = 1;
			this->btnOpen->Text = L"Dosya Aç";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &mainForm::btnOpen_Click);
			// 
			// txtPath
			// 
			this->txtPath->Location = System::Drawing::Point(7, 20);
			this->txtPath->Name = L"txtPath";
			this->txtPath->Size = System::Drawing::Size(130, 20);
			this->txtPath->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btnT1);
			this->groupBox2->Controls->Add(this->labelT1Durum);
			this->groupBox2->Controls->Add(this->labelT1Step);
			this->groupBox2->Controls->Add(this->labelT1Time);
			this->groupBox2->Location = System::Drawing::Point(12, 59);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(313, 80);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Thread 1";
			// 
			// btnT1
			// 
			this->btnT1->Location = System::Drawing::Point(252, 19);
			this->btnT1->Name = L"btnT1";
			this->btnT1->Size = System::Drawing::Size(55, 49);
			this->btnT1->TabIndex = 3;
			this->btnT1->Text = L"Ýncele";
			this->btnT1->UseVisualStyleBackColor = true;
			// 
			// labelT1Durum
			// 
			this->labelT1Durum->AutoSize = true;
			this->labelT1Durum->Location = System::Drawing::Point(6, 16);
			this->labelT1Durum->Name = L"labelT1Durum";
			this->labelT1Durum->Size = System::Drawing::Size(85, 13);
			this->labelT1Durum->TabIndex = 2;
			this->labelT1Durum->Text = L"Durum : Çözüldü";
			// 
			// labelT1Step
			// 
			this->labelT1Step->AutoSize = true;
			this->labelT1Step->Location = System::Drawing::Point(6, 36);
			this->labelT1Step->Name = L"labelT1Step";
			this->labelT1Step->Size = System::Drawing::Size(85, 13);
			this->labelT1Step->TabIndex = 1;
			this->labelT1Step->Text = L"Adým sayýsý : 539";
			// 
			// labelT1Time
			// 
			this->labelT1Time->AutoSize = true;
			this->labelT1Time->Location = System::Drawing::Point(6, 55);
			this->labelT1Time->Name = L"labelT1Time";
			this->labelT1Time->Size = System::Drawing::Size(112, 13);
			this->labelT1Time->TabIndex = 0;
			this->labelT1Time->Text = L"Çözüm Süresi : 0.212s";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->btnT2);
			this->groupBox3->Controls->Add(this->labelT2Durum);
			this->groupBox3->Controls->Add(this->labelT2Step);
			this->groupBox3->Controls->Add(this->labelT2Time);
			this->groupBox3->Location = System::Drawing::Point(12, 145);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(313, 80);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Thread 2";
			// 
			// btnT2
			// 
			this->btnT2->Location = System::Drawing::Point(252, 19);
			this->btnT2->Name = L"btnT2";
			this->btnT2->Size = System::Drawing::Size(55, 49);
			this->btnT2->TabIndex = 3;
			this->btnT2->Text = L"Ýncele";
			this->btnT2->UseVisualStyleBackColor = true;
			// 
			// labelT2Durum
			// 
			this->labelT2Durum->AutoSize = true;
			this->labelT2Durum->Location = System::Drawing::Point(6, 16);
			this->labelT2Durum->Name = L"labelT2Durum";
			this->labelT2Durum->Size = System::Drawing::Size(101, 13);
			this->labelT2Durum->TabIndex = 2;
			this->labelT2Durum->Text = L"Durum : Çözülemedi";
			// 
			// labelT2Step
			// 
			this->labelT2Step->AutoSize = true;
			this->labelT2Step->Location = System::Drawing::Point(6, 36);
			this->labelT2Step->Name = L"labelT2Step";
			this->labelT2Step->Size = System::Drawing::Size(85, 13);
			this->labelT2Step->TabIndex = 1;
			this->labelT2Step->Text = L"Adým sayýsý : 480";
			// 
			// labelT2Time
			// 
			this->labelT2Time->AutoSize = true;
			this->labelT2Time->Location = System::Drawing::Point(6, 55);
			this->labelT2Time->Name = L"labelT2Time";
			this->labelT2Time->Size = System::Drawing::Size(83, 13);
			this->labelT2Time->TabIndex = 0;
			this->labelT2Time->Text = L"Çözüm Süresi : -";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->btnT3);
			this->groupBox4->Controls->Add(this->labelT3Durum);
			this->groupBox4->Controls->Add(this->labelT3Step);
			this->groupBox4->Controls->Add(this->labelT3Time);
			this->groupBox4->Location = System::Drawing::Point(12, 231);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(313, 80);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Thread 3";
			// 
			// btnT3
			// 
			this->btnT3->Location = System::Drawing::Point(252, 19);
			this->btnT3->Name = L"btnT3";
			this->btnT3->Size = System::Drawing::Size(55, 49);
			this->btnT3->TabIndex = 3;
			this->btnT3->Text = L"Ýncele";
			this->btnT3->UseVisualStyleBackColor = true;
			// 
			// labelT3Durum
			// 
			this->labelT3Durum->AutoSize = true;
			this->labelT3Durum->Location = System::Drawing::Point(6, 16);
			this->labelT3Durum->Name = L"labelT3Durum";
			this->labelT3Durum->Size = System::Drawing::Size(101, 13);
			this->labelT3Durum->TabIndex = 2;
			this->labelT3Durum->Text = L"Durum : Çözülemedi";
			// 
			// labelT3Step
			// 
			this->labelT3Step->AutoSize = true;
			this->labelT3Step->Location = System::Drawing::Point(6, 36);
			this->labelT3Step->Name = L"labelT3Step";
			this->labelT3Step->Size = System::Drawing::Size(85, 13);
			this->labelT3Step->TabIndex = 1;
			this->labelT3Step->Text = L"Adým sayýsý : 480";
			// 
			// labelT3Time
			// 
			this->labelT3Time->AutoSize = true;
			this->labelT3Time->Location = System::Drawing::Point(6, 55);
			this->labelT3Time->Name = L"labelT3Time";
			this->labelT3Time->Size = System::Drawing::Size(83, 13);
			this->labelT3Time->TabIndex = 0;
			this->labelT3Time->Text = L"Çözüm Süresi : -";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->btnT4);
			this->groupBox5->Controls->Add(this->labelT4Durum);
			this->groupBox5->Controls->Add(this->labelT4Step);
			this->groupBox5->Controls->Add(this->labelT4Time);
			this->groupBox5->Location = System::Drawing::Point(12, 317);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(313, 80);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Thread 4";
			// 
			// btnT4
			// 
			this->btnT4->Location = System::Drawing::Point(252, 19);
			this->btnT4->Name = L"btnT4";
			this->btnT4->Size = System::Drawing::Size(55, 49);
			this->btnT4->TabIndex = 3;
			this->btnT4->Text = L"Ýncele";
			this->btnT4->UseVisualStyleBackColor = true;
			// 
			// labelT4Durum
			// 
			this->labelT4Durum->AutoSize = true;
			this->labelT4Durum->Location = System::Drawing::Point(6, 16);
			this->labelT4Durum->Name = L"labelT4Durum";
			this->labelT4Durum->Size = System::Drawing::Size(101, 13);
			this->labelT4Durum->TabIndex = 2;
			this->labelT4Durum->Text = L"Durum : Çözülemedi";
			// 
			// labelT4Step
			// 
			this->labelT4Step->AutoSize = true;
			this->labelT4Step->Location = System::Drawing::Point(6, 36);
			this->labelT4Step->Name = L"labelT4Step";
			this->labelT4Step->Size = System::Drawing::Size(85, 13);
			this->labelT4Step->TabIndex = 1;
			this->labelT4Step->Text = L"Adým sayýsý : 480";
			// 
			// labelT4Time
			// 
			this->labelT4Time->AutoSize = true;
			this->labelT4Time->Location = System::Drawing::Point(6, 55);
			this->labelT4Time->Name = L"labelT4Time";
			this->labelT4Time->Size = System::Drawing::Size(83, 13);
			this->labelT4Time->TabIndex = 0;
			this->labelT4Time->Text = L"Çözüm Süresi : -";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// labelTest
			// 
			this->labelTest->Location = System::Drawing::Point(19, 404);
			this->labelTest->Name = L"labelTest";
			this->labelTest->Size = System::Drawing::Size(306, 136);
			this->labelTest->TabIndex = 5;
			// 
			// mainForm
			// 
			this->ClientSize = System::Drawing::Size(334, 594);
			this->Controls->Add(this->labelTest);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"mainForm";
			this->Text = L"form";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		try {
			openFileDialog1->Filter = "Text files |*.txt";
			openFileDialog1->Title = "Select sudoku text file";

			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::IO::StreamReader ^sr = gcnew System::IO::StreamReader(openFileDialog1->FileName);
				txtPath->Text = openFileDialog1->FileName;
				//MessageBox::Show(sr->ReadToEnd());

				String^ str;
				for (int i = 0; i < 9; i++) {
					str = sr->ReadLine();
					str = str->Replace("*", "0");
					array<Char>^ dizi = gcnew array<Char>(9);
					dizi = str->ToCharArray();
					for (int j = 0; j < 9; j++) {
						sudoku[i][j] = Convert::ToInt32(dizi->GetValue(j)->ToString());
					}

				}

				sudokuThreadsDoldur();
				printMatris();

				sr->Close();
			}

		}
		catch (...) {

		}

	}

private: System::Void sudokuThreadsDoldur() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudokuT1[i][j] = sudokuT2[i][j] = sudokuT3[i][j] = sudokuT4[i][j] = sudoku[i][j];
		}
	}
}

private: System::Void btnCoz_Click(System::Object^  sender, System::EventArgs^  e) {
	solveT3(sudoku);
	printMatris();
}

private: System::Void printMatris() {
	labelTest->Text = "";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			labelTest->Text = labelTest->Text + " " + sudoku[i][j];
		}
		labelTest->Text = labelTest->Text + "\n";
	}
}

		 

};
}
