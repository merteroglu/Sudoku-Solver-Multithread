#pragma once

namespace yazlabProject2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	
	

	/// <summary>
	/// Summary for threadForm
	/// </summary>
	public ref class threadForm : public System::Windows::Forms::Form
	{
	public:

		int threadNo = 1;
		float sure = 0;
		int step = 0;
		int totalStep = 0;
		System::IO::StreamReader ^sr;
		ArrayList ^arrayList = gcnew ArrayList();

	private: System::Windows::Forms::Label^  labelTotalStep;
	public:
	private: System::Windows::Forms::Label^  labelStep;


	private: System::Windows::Forms::Timer^  timer1;

	public:
		

		threadForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		

		}

		threadForm(int tNo, float s, int totalSt) {
			InitializeComponent();
			threadNo = tNo;
			sure = s;
			totalStep = totalSt;
			this->Text = "Thread" + threadNo;
			labelThreadNo->Text = "Thread No: " + threadNo;
			labelSure->Text = "Çözüm süresi:" + sure +"s";
			labelTotalStep->Text = "Toplam adým:" + totalStep;
			System::String^ path;
			System::String^ mainPath = Directory::GetCurrentDirectory();
			switch (threadNo)
			{
			case 1:
				path = mainPath + "/anims/thread1.txt";
				break;
			case 2:
				path = mainPath + "/anims/thread2.txt";
				break;
			case 3:
				path = mainPath + "/anims/thread3.txt";
				break;
			case 4:
				path = mainPath + "/anims/thread4.txt";
				break;

			}

			sr = gcnew System::IO::StreamReader(path);
			
			String ^line;
			line = sr->ReadLine();
			while (line != nullptr) {
				arrayList->Add(line);
				line = sr->ReadLine();
			}
			sr->Close();
			printMatris();
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
	private: System::Windows::Forms::Label^  labelSure;

	private: System::Windows::Forms::Label^  labelThreadNo;
	private: System::Windows::Forms::Label^  label1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(threadForm::typeid));
			this->btnBasadon = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnNext = (gcnew System::Windows::Forms::Button());
			this->btnDurdur = (gcnew System::Windows::Forms::Button());
			this->btnBaslat = (gcnew System::Windows::Forms::Button());
			this->labelSure = (gcnew System::Windows::Forms::Label());
			this->labelThreadNo = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelTotalStep = (gcnew System::Windows::Forms::Label());
			this->labelStep = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnBasadon
			// 
			this->btnBasadon->Location = System::Drawing::Point(217, 231);
			this->btnBasadon->Name = L"btnBasadon";
			this->btnBasadon->Size = System::Drawing::Size(109, 23);
			this->btnBasadon->TabIndex = 15;
			this->btnBasadon->Text = L"Baþa dön";
			this->btnBasadon->UseVisualStyleBackColor = true;
			this->btnBasadon->Click += gcnew System::EventHandler(this, &threadForm::btnBasadon_Click);
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(217, 201);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(109, 23);
			this->btnBack->TabIndex = 14;
			this->btnBack->Text = L"Manual Geri";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &threadForm::btnBack_Click);
			// 
			// btnNext
			// 
			this->btnNext->Location = System::Drawing::Point(217, 171);
			this->btnNext->Name = L"btnNext";
			this->btnNext->Size = System::Drawing::Size(109, 23);
			this->btnNext->TabIndex = 13;
			this->btnNext->Text = L"Manual Ýleri";
			this->btnNext->UseVisualStyleBackColor = true;
			this->btnNext->Click += gcnew System::EventHandler(this, &threadForm::btnNext_Click);
			// 
			// btnDurdur
			// 
			this->btnDurdur->Location = System::Drawing::Point(217, 141);
			this->btnDurdur->Name = L"btnDurdur";
			this->btnDurdur->Size = System::Drawing::Size(109, 23);
			this->btnDurdur->TabIndex = 12;
			this->btnDurdur->Text = L"Animasyon Durdur";
			this->btnDurdur->UseVisualStyleBackColor = true;
			this->btnDurdur->Click += gcnew System::EventHandler(this, &threadForm::btnDurdur_Click);
			// 
			// btnBaslat
			// 
			this->btnBaslat->Location = System::Drawing::Point(217, 111);
			this->btnBaslat->Name = L"btnBaslat";
			this->btnBaslat->Size = System::Drawing::Size(109, 23);
			this->btnBaslat->TabIndex = 11;
			this->btnBaslat->Text = L"Animasyon Baþlat";
			this->btnBaslat->UseVisualStyleBackColor = true;
			this->btnBaslat->Click += gcnew System::EventHandler(this, &threadForm::btnBaslat_Click);
			// 
			// labelSure
			// 
			this->labelSure->AutoSize = true;
			this->labelSure->Location = System::Drawing::Point(214, 35);
			this->labelSure->Name = L"labelSure";
			this->labelSure->Size = System::Drawing::Size(112, 13);
			this->labelSure->TabIndex = 10;
			this->labelSure->Text = L"Çözüm Süresi : 0.312s";
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
			// timer1
			// 
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &threadForm::timer1_Tick);
			// 
			// labelTotalStep
			// 
			this->labelTotalStep->AutoSize = true;
			this->labelTotalStep->Location = System::Drawing::Point(214, 57);
			this->labelTotalStep->Name = L"labelTotalStep";
			this->labelTotalStep->Size = System::Drawing::Size(83, 13);
			this->labelTotalStep->TabIndex = 16;
			this->labelTotalStep->Text = L"Toplam Adým : 0";
			// 
			// labelStep
			// 
			this->labelStep->AutoSize = true;
			this->labelStep->Location = System::Drawing::Point(214, 79);
			this->labelStep->Name = L"labelStep";
			this->labelStep->Size = System::Drawing::Size(83, 13);
			this->labelStep->TabIndex = 17;
			this->labelStep->Text = L"Þuan ki adým : 0";
			// 
			// threadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(344, 266);
			this->Controls->Add(this->labelStep);
			this->Controls->Add(this->labelTotalStep);
			this->Controls->Add(this->btnBasadon);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnNext);
			this->Controls->Add(this->btnDurdur);
			this->Controls->Add(this->btnBaslat);
			this->Controls->Add(this->labelSure);
			this->Controls->Add(this->labelThreadNo);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->Name = L"threadForm";
			this->Text = L"Thread 1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: System::Void printMatris() {
			
			int stepPlus;

			if (step < arrayList->Count - 1) {
				stepPlus = step + 9;
			}else{
				timer1->Enabled = false;
				return;
			}
			label1->Text = "";

			for (; step < stepPlus; step++) {
				label1->Text = label1->Text + arrayList[step]->ToString()->Replace(" ","    ") + "\n\n";
				labelStep->Text = "Þuan ki adým : " + (step+1)/9;
			}

		}

#pragma endregion

	private: System::Void btnNext_Click(System::Object^  sender, System::EventArgs^  e) {
		printMatris();
	}

private: System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e) {
	if (step >= 18) {
		step -= 18;
		printMatris();
	}
}


private: System::Void btnBasadon_Click(System::Object^  sender, System::EventArgs^  e) {
	step = 0;
	printMatris();
}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	printMatris();
}

private: System::Void btnBaslat_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = true;
}

private: System::Void btnDurdur_Click(System::Object^  sender, System::EventArgs^  e) {
	timer1->Enabled = false;
}
};
}
