#pragma once

namespace yazlabProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for threadForm
	/// </summary>
	public ref class threadForm : public System::Windows::Forms::Form
	{
	public:
		threadForm(void)
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
		~threadForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnBasadon;
	protected:
	private: System::Windows::Forms::Button^  btnBack;
	private: System::Windows::Forms::Button^  btnNext;
	private: System::Windows::Forms::Button^  btnDurdur;
	private: System::Windows::Forms::Button^  btnBaslat;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  labelThreadNo;
	private: System::Windows::Forms::Label^  label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(threadForm::typeid));
			this->btnBasadon = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnDurdur = (gcnew System::Windows::Forms::Button());
			this->btnBaslat = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelThreadNo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnBasadon
			// 
			this->btnBasadon->Location = System::Drawing::Point(217, 186);
			this->btnBasadon->Name = L"btnBasadon";
			this->btnBasadon->Size = System::Drawing::Size(109, 23);
			this->btnBasadon->TabIndex = 15;
			this->btnBasadon->Text = L"Baþa dön";
			this->btnBasadon->UseVisualStyleBackColor = true;
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(217, 156);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(109, 23);
			this->btnBack->TabIndex = 14;
			this->btnBack->Text = L"Manual Geri";
			this->btnBack->UseVisualStyleBackColor = true;
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(217, 126);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(109, 23);
			this->btnNext->TabIndex = 13;
			this->btnNext->Text = L"Manual Ýleri";
			this->btnNext->UseVisualStyleBackColor = true;
			// 
			// btnDurdur
			// 
			this->btnDurdur->Location = System::Drawing::Point(217, 96);
			this->btnDurdur->Name = L"btnDurdur";
			this->btnDurdur->Size = System::Drawing::Size(109, 23);
			this->btnDurdur->TabIndex = 12;
			this->btnDurdur->Text = L"Animasyon Durdur";
			this->btnDurdur->UseVisualStyleBackColor = true;
			// 
			// btnBaslat
			// 
			this->btnBaslat->Location = System::Drawing::Point(217, 66);
			this->btnBaslat->Name = L"btnBaslat";
			this->btnBaslat->Size = System::Drawing::Size(109, 23);
			this->btnBaslat->TabIndex = 11;
			this->btnBaslat->Text = L"Animasyon Baþlat";
			this->btnBaslat->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(214, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Çözüm Süresi : 0.312s";
			// 
			// labelThreadNo
			// 
			this->labelThreadNo->AutoSize = true;
			this->labelThreadNo->Location = System::Drawing::Point(214, 12);
			this->labelThreadNo->Name = L"labelThreadNo";
			this->labelThreadNo->Size = System::Drawing::Size(73, 13);
			this->labelThreadNo->TabIndex = 9;
			this->labelThreadNo->Text = L"Thread No : 1";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(184, 256);
			this->label1->TabIndex = 8;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// threadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(344, 266);
			this->Controls->Add(this->btnBasadon);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnDurdur);
			this->Controls->Add(this->btnBaslat);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labelThreadNo);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"threadForm";
			this->Text = L"Thread 1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
