#pragma once
#include "PortCOM.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Settings1
	/// </summary>
	public ref class Settings1 : public System::Windows::Forms::Form
	{
	public:
		Settings1(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Settings1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	public: System::Windows::Forms::CheckBox^  ckbLED;
	public: System::Windows::Forms::CheckBox^  ckbLight;
	public: System::Windows::Forms::CheckBox^  ckbAlarm;
	public: System::Windows::Forms::CheckBox^  ckbScreen;
	private: System::Windows::Forms::Button^  btnName;
	private: System::Windows::Forms::Button^  btnPassword;
	private: System::Windows::Forms::TextBox^  txtbPSWD;
	private: System::Windows::Forms::TextBox^  txtbNAME;





	private: System::Windows::Forms::Button^  btnFabric;
	private: System::Windows::Forms::TextBox^  txtbSend;
	private: System::Windows::Forms::TextBox^  txtbRead;


	private: System::Windows::Forms::Button^  btnSend;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Button^  btnReturn;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>

	public:
		bool LED;
		bool Alarm;
		bool Screen;
		bool Light;
	private: System::Windows::Forms::Button^  readBtSet;
	private: System::Windows::Forms::Button^  setRefreshBtn;
	public:

	private: System::Windows::Forms::PictureBox^  pictureBox1;




#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
			 /// jej zawartoœci w edytorze kodu.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings1::typeid));
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->ckbLED = (gcnew System::Windows::Forms::CheckBox());
				 this->ckbLight = (gcnew System::Windows::Forms::CheckBox());
				 this->ckbAlarm = (gcnew System::Windows::Forms::CheckBox());
				 this->ckbScreen = (gcnew System::Windows::Forms::CheckBox());
				 this->btnName = (gcnew System::Windows::Forms::Button());
				 this->btnPassword = (gcnew System::Windows::Forms::Button());
				 this->txtbPSWD = (gcnew System::Windows::Forms::TextBox());
				 this->txtbNAME = (gcnew System::Windows::Forms::TextBox());
				 this->btnFabric = (gcnew System::Windows::Forms::Button());
				 this->txtbSend = (gcnew System::Windows::Forms::TextBox());
				 this->txtbRead = (gcnew System::Windows::Forms::TextBox());
				 this->btnSend = (gcnew System::Windows::Forms::Button());
				 this->btnClear = (gcnew System::Windows::Forms::Button());
				 this->btnReturn = (gcnew System::Windows::Forms::Button());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->readBtSet = (gcnew System::Windows::Forms::Button());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->setRefreshBtn = (gcnew System::Windows::Forms::Button());
				 this->tableLayoutPanel1->SuspendLayout();
				 this->groupBox1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->ColumnCount = 2;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->Controls->Add(this->ckbLED, 1, 0);
				 this->tableLayoutPanel1->Controls->Add(this->ckbLight, 0, 1);
				 this->tableLayoutPanel1->Controls->Add(this->ckbAlarm, 1, 1);
				 this->tableLayoutPanel1->Controls->Add(this->ckbScreen, 0, 0);
				 this->tableLayoutPanel1->Location = System::Drawing::Point(213, 15);
				 this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 2;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(275, 91);
				 this->tableLayoutPanel1->TabIndex = 0;
				 // 
				 // ckbLED
				 // 
				 this->ckbLED->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					 static_cast<System::Int32>(static_cast<System::Byte>(200)));
				 this->ckbLED->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->ckbLED->Location = System::Drawing::Point(141, 4);
				 this->ckbLED->Margin = System::Windows::Forms::Padding(4);
				 this->ckbLED->Name = L"ckbLED";
				 this->ckbLED->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
				 this->ckbLED->Size = System::Drawing::Size(129, 37);
				 this->ckbLED->TabIndex = 1;
				 this->ckbLED->Text = L"LED";
				 this->ckbLED->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->ckbLED->UseVisualStyleBackColor = false;
				 this->ckbLED->CheckedChanged += gcnew System::EventHandler(this, &Settings1::ckbLED_CheckedChanged);
				 // 
				 // ckbLight
				 // 
				 this->ckbLight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					 static_cast<System::Int32>(static_cast<System::Byte>(200)));
				 this->ckbLight->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->ckbLight->Location = System::Drawing::Point(4, 49);
				 this->ckbLight->Margin = System::Windows::Forms::Padding(4);
				 this->ckbLight->Name = L"ckbLight";
				 this->ckbLight->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
				 this->ckbLight->Size = System::Drawing::Size(129, 38);
				 this->ckbLight->TabIndex = 2;
				 this->ckbLight->Text = L"Przyciemnij ekran";
				 this->ckbLight->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->ckbLight->UseVisualStyleBackColor = false;
				 this->ckbLight->CheckedChanged += gcnew System::EventHandler(this, &Settings1::ckbLight_CheckedChanged);
				 // 
				 // ckbAlarm
				 // 
				 this->ckbAlarm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					 static_cast<System::Int32>(static_cast<System::Byte>(200)));
				 this->ckbAlarm->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->ckbAlarm->Location = System::Drawing::Point(141, 49);
				 this->ckbAlarm->Margin = System::Windows::Forms::Padding(4);
				 this->ckbAlarm->Name = L"ckbAlarm";
				 this->ckbAlarm->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
				 this->ckbAlarm->Size = System::Drawing::Size(129, 38);
				 this->ckbAlarm->TabIndex = 3;
				 this->ckbAlarm->Text = L"Alarm";
				 this->ckbAlarm->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->ckbAlarm->UseVisualStyleBackColor = false;
				 this->ckbAlarm->CheckedChanged += gcnew System::EventHandler(this, &Settings1::ckbAlarm_CheckedChanged);
				 // 
				 // ckbScreen
				 // 
				 this->ckbScreen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					 static_cast<System::Int32>(static_cast<System::Byte>(200)));
				 this->ckbScreen->Cursor = System::Windows::Forms::Cursors::Hand;
				 this->ckbScreen->Location = System::Drawing::Point(4, 4);
				 this->ckbScreen->Margin = System::Windows::Forms::Padding(4);
				 this->ckbScreen->Name = L"ckbScreen";
				 this->ckbScreen->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
				 this->ckbScreen->Size = System::Drawing::Size(129, 37);
				 this->ckbScreen->TabIndex = 0;
				 this->ckbScreen->Text = L"Wyœwietlacz";
				 this->ckbScreen->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->ckbScreen->UseVisualStyleBackColor = false;
				 this->ckbScreen->CheckedChanged += gcnew System::EventHandler(this, &Settings1::ckbScreen_CheckedChanged);
				 // 
				 // btnName
				 // 
				 this->btnName->Location = System::Drawing::Point(17, 69);
				 this->btnName->Margin = System::Windows::Forms::Padding(4);
				 this->btnName->Name = L"btnName";
				 this->btnName->Size = System::Drawing::Size(112, 26);
				 this->btnName->TabIndex = 1;
				 this->btnName->Text = L"Zmieñ nazwê";
				 this->btnName->UseVisualStyleBackColor = true;
				 this->btnName->Click += gcnew System::EventHandler(this, &Settings1::btnName_Click);
				 // 
				 // btnPassword
				 // 
				 this->btnPassword->Location = System::Drawing::Point(17, 103);
				 this->btnPassword->Margin = System::Windows::Forms::Padding(4);
				 this->btnPassword->Name = L"btnPassword";
				 this->btnPassword->Size = System::Drawing::Size(112, 26);
				 this->btnPassword->TabIndex = 2;
				 this->btnPassword->Text = L"Zmieñ has³o";
				 this->btnPassword->UseVisualStyleBackColor = true;
				 this->btnPassword->Click += gcnew System::EventHandler(this, &Settings1::btnPassword_Click);
				 // 
				 // txtbPSWD
				 // 
				 this->txtbPSWD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->txtbPSWD->Location = System::Drawing::Point(160, 103);
				 this->txtbPSWD->Margin = System::Windows::Forms::Padding(4);
				 this->txtbPSWD->MaxLength = 4;
				 this->txtbPSWD->Name = L"txtbPSWD";
				 this->txtbPSWD->Size = System::Drawing::Size(132, 26);
				 this->txtbPSWD->TabIndex = 3;
				 // 
				 // txtbNAME
				 // 
				 this->txtbNAME->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->txtbNAME->Location = System::Drawing::Point(160, 69);
				 this->txtbNAME->Margin = System::Windows::Forms::Padding(4);
				 this->txtbNAME->Name = L"txtbNAME";
				 this->txtbNAME->Size = System::Drawing::Size(132, 26);
				 this->txtbNAME->TabIndex = 4;
				 this->txtbNAME->Text = L"Kubkuino";
				 // 
				 // btnFabric
				 // 
				 this->btnFabric->Location = System::Drawing::Point(17, 137);
				 this->btnFabric->Margin = System::Windows::Forms::Padding(4);
				 this->btnFabric->Name = L"btnFabric";
				 this->btnFabric->Size = System::Drawing::Size(275, 27);
				 this->btnFabric->TabIndex = 5;
				 this->btnFabric->Text = L"Ustawienia domyœlne";
				 this->btnFabric->UseVisualStyleBackColor = true;
				 this->btnFabric->Click += gcnew System::EventHandler(this, &Settings1::btnFabric_Click);
				 // 
				 // txtbSend
				 // 
				 this->txtbSend->Location = System::Drawing::Point(28, 334);
				 this->txtbSend->Margin = System::Windows::Forms::Padding(4);
				 this->txtbSend->Name = L"txtbSend";
				 this->txtbSend->Size = System::Drawing::Size(459, 22);
				 this->txtbSend->TabIndex = 6;
				 // 
				 // txtbRead
				 // 
				 this->txtbRead->Enabled = false;
				 this->txtbRead->Location = System::Drawing::Point(28, 389);
				 this->txtbRead->Margin = System::Windows::Forms::Padding(4);
				 this->txtbRead->Name = L"txtbRead";
				 this->txtbRead->ReadOnly = true;
				 this->txtbRead->Size = System::Drawing::Size(459, 22);
				 this->txtbRead->TabIndex = 7;
				 this->txtbRead->Visible = false;
				 // 
				 // btnSend
				 // 
				 this->btnSend->Location = System::Drawing::Point(28, 358);
				 this->btnSend->Margin = System::Windows::Forms::Padding(4);
				 this->btnSend->Name = L"btnSend";
				 this->btnSend->Size = System::Drawing::Size(164, 31);
				 this->btnSend->TabIndex = 8;
				 this->btnSend->Text = L"Wyœlij";
				 this->btnSend->UseVisualStyleBackColor = true;
				 this->btnSend->Click += gcnew System::EventHandler(this, &Settings1::btnSend_Click);
				 // 
				 // btnClear
				 // 
				 this->btnClear->Location = System::Drawing::Point(324, 358);
				 this->btnClear->Margin = System::Windows::Forms::Padding(4);
				 this->btnClear->Name = L"btnClear";
				 this->btnClear->Size = System::Drawing::Size(164, 31);
				 this->btnClear->TabIndex = 9;
				 this->btnClear->Text = L"Czytaj";
				 this->btnClear->UseVisualStyleBackColor = true;
				 this->btnClear->Click += gcnew System::EventHandler(this, &Settings1::btnClear_Click);
				 // 
				 // btnReturn
				 // 
				 this->btnReturn->Location = System::Drawing::Point(28, 18);
				 this->btnReturn->Margin = System::Windows::Forms::Padding(4);
				 this->btnReturn->Name = L"btnReturn";
				 this->btnReturn->Size = System::Drawing::Size(117, 28);
				 this->btnReturn->TabIndex = 10;
				 this->btnReturn->Text = L"Wróæ";
				 this->btnReturn->UseVisualStyleBackColor = true;
				 this->btnReturn->Click += gcnew System::EventHandler(this, &Settings1::btnReturn_Click);
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->readBtSet);
				 this->groupBox1->Controls->Add(this->btnName);
				 this->groupBox1->Controls->Add(this->txtbNAME);
				 this->groupBox1->Controls->Add(this->btnPassword);
				 this->groupBox1->Controls->Add(this->txtbPSWD);
				 this->groupBox1->Controls->Add(this->btnFabric);
				 this->groupBox1->Location = System::Drawing::Point(172, 122);
				 this->groupBox1->Margin = System::Windows::Forms::Padding(4);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Padding = System::Windows::Forms::Padding(4);
				 this->groupBox1->Size = System::Drawing::Size(316, 180);
				 this->groupBox1->TabIndex = 11;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Bluetooth";
				 // 
				 // readBtSet
				 // 
				 this->readBtSet->Location = System::Drawing::Point(17, 35);
				 this->readBtSet->Name = L"readBtSet";
				 this->readBtSet->Size = System::Drawing::Size(275, 27);
				 this->readBtSet->TabIndex = 0;
				 this->readBtSet->Text = L"Odczytaj nazwê";
				 this->readBtSet->UseVisualStyleBackColor = true;
				 this->readBtSet->Click += gcnew System::EventHandler(this, &Settings1::readBtSet_Click);
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->Location = System::Drawing::Point(28, 122);
				 this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(108, 100);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
				 this->pictureBox1->TabIndex = 12;
				 this->pictureBox1->TabStop = false;
				 // 
				 // setRefreshBtn
				 // 
				 this->setRefreshBtn->Location = System::Drawing::Point(28, 53);
				 this->setRefreshBtn->Name = L"setRefreshBtn";
				 this->setRefreshBtn->Size = System::Drawing::Size(117, 28);
				 this->setRefreshBtn->TabIndex = 13;
				 this->setRefreshBtn->Text = L"Odœwie¿";
				 this->setRefreshBtn->UseVisualStyleBackColor = true;
				 this->setRefreshBtn->Click += gcnew System::EventHandler(this, &Settings1::setRefreshBtn_Click);
				 // 
				 // Settings1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(512, 428);
				 this->Controls->Add(this->setRefreshBtn);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->btnReturn);
				 this->Controls->Add(this->btnClear);
				 this->Controls->Add(this->btnSend);
				 this->Controls->Add(this->txtbRead);
				 this->Controls->Add(this->txtbSend);
				 this->Controls->Add(this->tableLayoutPanel1);
				 this->Controls->Add(this->groupBox1);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->MaximizeBox = false;
				 this->Name = L"Settings1";
				 this->Text = L"Ustawienia";
				 this->Load += gcnew System::EventHandler(this, &Settings1::Settings1_Load);
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void btnReturn_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	public: System::Void ckbLED_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {



		if (ckbLED->CheckState == System::Windows::Forms::CheckState::Checked) {
			LED = true;
			PortCOM::LED = true;
			ckbLED->BackColor = System::Drawing::Color::FromArgb(200, 255, 255);
		}
		else {
			LED = false;
			PortCOM::LED = false;
			ckbLED->BackColor = System::Drawing::Color::FromArgb(200, 200, 200);
		}
		PortCOM::PortLED(LED);
	}
	public: System::Void ckbScreen_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (ckbScreen->CheckState == System::Windows::Forms::CheckState::Checked) {
			Screen = true;
			PortCOM::Screen = true;
			ckbScreen->BackColor = System::Drawing::Color::FromArgb(200, 255, 255);
		}
		else {
			Screen = false;
			PortCOM::Screen = false;
			ckbScreen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(200)));
		}
		PortCOM::PortScreen(Screen);
	}
	public: System::Void ckbLight_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (ckbLight->CheckState == System::Windows::Forms::CheckState::Checked) {
			Light = true;
			PortCOM::Light = true;
			ckbLight->BackColor = System::Drawing::Color::FromArgb(200, 255, 255);
		}
		else {
			Light = false;
			PortCOM::Light = false;
			ckbLight->BackColor = System::Drawing::Color::FromArgb(200, 200, 200);
		}
		PortCOM::PortLight(Light);
	}
	public: System::Void ckbAlarm_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (ckbAlarm->CheckState == System::Windows::Forms::CheckState::Checked) {

			Alarm = true;
			PortCOM::Alarm = true;
			ckbAlarm->BackColor = System::Drawing::Color::FromArgb(200, 255, 255);

		}
		else {
			Alarm = false;
			PortCOM::Alarm = false;
			ckbAlarm->BackColor = System::Drawing::Color::FromArgb(200, 200, 200);
		}
		PortCOM::PortAlarm(Alarm);
	}

	private: System::Void btnFabric_Click(System::Object^  sender, System::EventArgs^  e) {
		txtbPSWD->Text = "0000";
		txtbNAME->Text = "Kubkuino";
		PortCOM::PortDefault();
	}
	private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
		this->txtbRead->Visible = true;
		btnClear->Visible = false;
	}
	private: System::Void btnSend_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ ok = txtbSend->Text;
		txtbRead->Text = PortCOM::PortCommute(ok);
		txtbSend->Text = "";
	}
	private: System::Void btnPassword_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			Convert::ToInt16(txtbPSWD->Text);
			String^ pswd = "SAT+PSWD=" + txtbPSWD->Text + ";";
			PortCOM::PortCommute(pswd);
		}
		catch (...) {
			txtbPSWD->Text = "B³¹d";
		}
	}
	private: System::Void btnName_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ name = "SAT+NAME=" + txtbNAME->Text + ";";
		PortCOM::PortCommute(name);
	}
	private: System::Void Settings1_Load(System::Object^  sender, System::EventArgs^  e) {
		setRefresh();
	}
	private: System::Void readBtSet_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ tempName = PortCOM::PortCommute("SAT+NAME?;");
		this->txtbSend->Text = tempName;
		if (tempName != "") {
			if (tempName->Length > 8) tempName = tempName->Substring(6, tempName->Length - 9);
			else this->txtbNAME->Text = "Z³e dane";
		}
		else this->txtbNAME->Text = "Brak danych";
		this->txtbNAME->Text = tempName;
	}
	private: System::Void setRefreshBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		setRefresh();
	}
	private: void setRefresh() {
		String^ deviceStatus = PortCOM::PortStatus();
		PortCOM::Screen = (deviceStatus[0] == '0') ? false : true; //wyswietlacz
		PortCOM::Light = (deviceStatus[1] == '0') ? false : true; //przyciemnienie
		PortCOM::LED = (deviceStatus[2] == '0') ? false : true; //ledy
		PortCOM::Alarm = (deviceStatus[3] == '0') ? false : true; //alarm
		ckbLED->Enabled = false;
		ckbAlarm->Enabled = false;
		ckbLight->Enabled = false;
		ckbScreen->Enabled = false;

		if (PortCOM::Alarm) ckbAlarm->CheckState = System::Windows::Forms::CheckState::Checked;
		else ckbAlarm->CheckState = System::Windows::Forms::CheckState::Unchecked;
		if (PortCOM::Light) ckbLight->CheckState = System::Windows::Forms::CheckState::Checked;
		else ckbLight->CheckState = System::Windows::Forms::CheckState::Unchecked;
		if (PortCOM::LED) ckbLED->CheckState = System::Windows::Forms::CheckState::Checked;
		else ckbLED->CheckState = System::Windows::Forms::CheckState::Unchecked;
		if (PortCOM::Screen) ckbScreen->CheckState = System::Windows::Forms::CheckState::Checked;
		else ckbScreen->CheckState = System::Windows::Forms::CheckState::Unchecked;

		ckbLED->Enabled = true;
		ckbAlarm->Enabled = true;
		ckbLight->Enabled = true;
		ckbScreen->Enabled = true;
	}
	};
}