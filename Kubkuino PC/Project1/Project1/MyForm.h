#pragma once
#include "Settings1.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include "PortCOM.h"
#include "help.h"
#include "thready.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnExit;
	public: System::Windows::Forms::Label^  lbl1;
	private: System::Windows::Forms::Label^  l1;
	private: System::Windows::Forms::Label^  l8;



	private: System::Windows::Forms::Label^  l7;

	private: System::Windows::Forms::Label^  l6;

	private: System::Windows::Forms::Label^  l5;

	private: System::Windows::Forms::Label^  l4;

	private: System::Windows::Forms::Label^  l3;

	private: System::Windows::Forms::Label^  l2;

	private: System::Windows::Forms::Label^  lblHot;
	private: System::Windows::Forms::Label^  lblCold;

	private: System::Windows::Forms::Label^  lblMeter;
	private: System::Windows::Forms::Label^  lblMild;
	private: System::Windows::Forms::Button^  btnSettings;



	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btnSendTemp;
	private: System::Windows::Forms::CheckBox^  ckbTempDown;
	private: System::Windows::Forms::TextBox^  txtbTempDown;
	private: System::Windows::Forms::Label^  lblTempDown;
	private: System::Windows::Forms::CheckBox^  ckbTempUp;
	private: System::Windows::Forms::TextBox^  txtbTempUp;
	private: System::Windows::Forms::Label^  lblTempUp;
	private: System::Windows::Forms::Label^  label1;




	private: System::ComponentModel::IContainer^  components;





	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>

	public:
		static String^ t;
		static double xxx;
	private: System::Windows::Forms::Timer^  timer1;

	public: ThreadStart ^ myThreadDelegate = gcnew ThreadStart(thready::DoWork);
			Thread^ thread1 = gcnew Thread(myThreadDelegate);
	private: System::Windows::Forms::Button^  WczytajU;
	public:

	private: System::Windows::Forms::Button^  ZapiszU;
	public:

	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  btnHelp;
	private: System::Windows::Forms::Button^  refreshDevice;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
			 /// jej zawartości w edytorze kodu.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				 this->btnExit = (gcnew System::Windows::Forms::Button());
				 this->lbl1 = (gcnew System::Windows::Forms::Label());
				 this->l1 = (gcnew System::Windows::Forms::Label());
				 this->l8 = (gcnew System::Windows::Forms::Label());
				 this->l7 = (gcnew System::Windows::Forms::Label());
				 this->l6 = (gcnew System::Windows::Forms::Label());
				 this->l5 = (gcnew System::Windows::Forms::Label());
				 this->l4 = (gcnew System::Windows::Forms::Label());
				 this->l3 = (gcnew System::Windows::Forms::Label());
				 this->l2 = (gcnew System::Windows::Forms::Label());
				 this->lblHot = (gcnew System::Windows::Forms::Label());
				 this->lblCold = (gcnew System::Windows::Forms::Label());
				 this->lblMeter = (gcnew System::Windows::Forms::Label());
				 this->lblMild = (gcnew System::Windows::Forms::Label());
				 this->btnSettings = (gcnew System::Windows::Forms::Button());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->btnSendTemp = (gcnew System::Windows::Forms::Button());
				 this->ckbTempDown = (gcnew System::Windows::Forms::CheckBox());
				 this->txtbTempDown = (gcnew System::Windows::Forms::TextBox());
				 this->lblTempDown = (gcnew System::Windows::Forms::Label());
				 this->ckbTempUp = (gcnew System::Windows::Forms::CheckBox());
				 this->txtbTempUp = (gcnew System::Windows::Forms::TextBox());
				 this->lblTempUp = (gcnew System::Windows::Forms::Label());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->WczytajU = (gcnew System::Windows::Forms::Button());
				 this->ZapiszU = (gcnew System::Windows::Forms::Button());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->btnHelp = (gcnew System::Windows::Forms::Button());
				 this->refreshDevice = (gcnew System::Windows::Forms::Button());
				 this->groupBox1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // btnExit
				 // 
				 this->btnExit->Location = System::Drawing::Point(16, 356);
				 this->btnExit->Margin = System::Windows::Forms::Padding(4);
				 this->btnExit->Name = L"btnExit";
				 this->btnExit->Size = System::Drawing::Size(100, 28);
				 this->btnExit->TabIndex = 0;
				 this->btnExit->Text = L"Zamknij";
				 this->btnExit->UseVisualStyleBackColor = true;
				 this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
				 // 
				 // lbl1
				 // 
				 this->lbl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				 this->lbl1->BackColor = System::Drawing::Color::Transparent;
				 this->lbl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 31, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->lbl1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
				 this->lbl1->Location = System::Drawing::Point(213, 46);
				 this->lbl1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->lbl1->Name = L"lbl1";
				 this->lbl1->Size = System::Drawing::Size(199, 66);
				 this->lbl1->TabIndex = 4;
				 this->lbl1->Text = L"120 ⁰C";
				 this->lbl1->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 this->lbl1->Click += gcnew System::EventHandler(this, &MyForm::lbl1_Click);
				 // 
				 // l1
				 // 
				 this->l1->BackColor = System::Drawing::Color::Blue;
				 this->l1->Location = System::Drawing::Point(416, 351);
				 this->l1->Margin = System::Windows::Forms::Padding(0);
				 this->l1->Name = L"l1";
				 this->l1->Size = System::Drawing::Size(56, 33);
				 this->l1->TabIndex = 16;
				 // 
				 // l8
				 // 
				 this->l8->BackColor = System::Drawing::Color::Red;
				 this->l8->Location = System::Drawing::Point(416, 32);
				 this->l8->Margin = System::Windows::Forms::Padding(0);
				 this->l8->Name = L"l8";
				 this->l8->Size = System::Drawing::Size(56, 33);
				 this->l8->TabIndex = 18;
				 // 
				 // l7
				 // 
				 this->l7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
					 static_cast<System::Int32>(static_cast<System::Byte>(50)));
				 this->l7->Location = System::Drawing::Point(416, 78);
				 this->l7->Margin = System::Windows::Forms::Padding(0);
				 this->l7->Name = L"l7";
				 this->l7->Size = System::Drawing::Size(56, 33);
				 this->l7->TabIndex = 19;
				 // 
				 // l6
				 // 
				 this->l6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
					 static_cast<System::Int32>(static_cast<System::Byte>(100)));
				 this->l6->Location = System::Drawing::Point(416, 123);
				 this->l6->Margin = System::Windows::Forms::Padding(0);
				 this->l6->Name = L"l6";
				 this->l6->Size = System::Drawing::Size(56, 33);
				 this->l6->TabIndex = 20;
				 // 
				 // l5
				 // 
				 this->l5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
					 static_cast<System::Int32>(static_cast<System::Byte>(150)));
				 this->l5->Location = System::Drawing::Point(416, 169);
				 this->l5->Margin = System::Windows::Forms::Padding(0);
				 this->l5->Name = L"l5";
				 this->l5->Size = System::Drawing::Size(56, 33);
				 this->l5->TabIndex = 21;
				 // 
				 // l4
				 // 
				 this->l4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					 static_cast<System::Int32>(static_cast<System::Byte>(200)));
				 this->l4->Location = System::Drawing::Point(416, 214);
				 this->l4->Margin = System::Windows::Forms::Padding(0);
				 this->l4->Name = L"l4";
				 this->l4->Size = System::Drawing::Size(56, 33);
				 this->l4->TabIndex = 22;
				 // 
				 // l3
				 // 
				 this->l3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->l3->Location = System::Drawing::Point(416, 260);
				 this->l3->Margin = System::Windows::Forms::Padding(0);
				 this->l3->Name = L"l3";
				 this->l3->Size = System::Drawing::Size(56, 33);
				 this->l3->TabIndex = 23;
				 // 
				 // l2
				 // 
				 this->l2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
					 static_cast<System::Int32>(static_cast<System::Byte>(255)));
				 this->l2->Location = System::Drawing::Point(416, 305);
				 this->l2->Margin = System::Windows::Forms::Padding(0);
				 this->l2->Name = L"l2";
				 this->l2->Size = System::Drawing::Size(56, 33);
				 this->l2->TabIndex = 24;
				 // 
				 // lblHot
				 // 
				 this->lblHot->AutoSize = true;
				 this->lblHot->BackColor = System::Drawing::Color::Transparent;
				 this->lblHot->Location = System::Drawing::Point(477, 28);
				 this->lblHot->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->lblHot->Name = L"lblHot";
				 this->lblHot->Size = System::Drawing::Size(59, 17);
				 this->lblHot->TabIndex = 25;
				 this->lblHot->Text = L"- 100 ⁰C";
				 // 
				 // lblCold
				 // 
				 this->lblCold->AutoSize = true;
				 this->lblCold->BackColor = System::Drawing::Color::Transparent;
				 this->lblCold->Location = System::Drawing::Point(477, 375);
				 this->lblCold->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->lblCold->Name = L"lblCold";
				 this->lblCold->Size = System::Drawing::Size(51, 17);
				 this->lblCold->TabIndex = 26;
				 this->lblCold->Text = L"- 20 ⁰C";
				 // 
				 // lblMeter
				 // 
				 this->lblMeter->BackColor = System::Drawing::Color::Transparent;
				 this->lblMeter->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->lblMeter->Location = System::Drawing::Point(412, 28);
				 this->lblMeter->Margin = System::Windows::Forms::Padding(0);
				 this->lblMeter->Name = L"lblMeter";
				 this->lblMeter->Size = System::Drawing::Size(65, 363);
				 this->lblMeter->TabIndex = 27;
				 // 
				 // lblMild
				 // 
				 this->lblMild->AutoSize = true;
				 this->lblMild->BackColor = System::Drawing::Color::Transparent;
				 this->lblMild->Location = System::Drawing::Point(477, 203);
				 this->lblMild->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->lblMild->Name = L"lblMild";
				 this->lblMild->Size = System::Drawing::Size(51, 17);
				 this->lblMild->TabIndex = 28;
				 this->lblMild->Text = L"- 60 ⁰C";
				 // 
				 // btnSettings
				 // 
				 this->btnSettings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->btnSettings->Location = System::Drawing::Point(187, 302);
				 this->btnSettings->Margin = System::Windows::Forms::Padding(4);
				 this->btnSettings->Name = L"btnSettings";
				 this->btnSettings->Size = System::Drawing::Size(221, 36);
				 this->btnSettings->TabIndex = 29;
				 this->btnSettings->Text = L"Ustawienia";
				 this->btnSettings->UseVisualStyleBackColor = true;
				 this->btnSettings->Click += gcnew System::EventHandler(this, &MyForm::btnSettings_Click);
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->btnSendTemp);
				 this->groupBox1->Controls->Add(this->ckbTempDown);
				 this->groupBox1->Controls->Add(this->txtbTempDown);
				 this->groupBox1->Controls->Add(this->lblTempDown);
				 this->groupBox1->Controls->Add(this->ckbTempUp);
				 this->groupBox1->Controls->Add(this->txtbTempUp);
				 this->groupBox1->Controls->Add(this->lblTempUp);
				 this->groupBox1->Location = System::Drawing::Point(188, 129);
				 this->groupBox1->Margin = System::Windows::Forms::Padding(4);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Padding = System::Windows::Forms::Padding(4);
				 this->groupBox1->Size = System::Drawing::Size(220, 140);
				 this->groupBox1->TabIndex = 33;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Temperatury graniczne";
				 // 
				 // btnSendTemp
				 // 
				 this->btnSendTemp->Location = System::Drawing::Point(12, 105);
				 this->btnSendTemp->Margin = System::Windows::Forms::Padding(4);
				 this->btnSendTemp->Name = L"btnSendTemp";
				 this->btnSendTemp->Size = System::Drawing::Size(200, 27);
				 this->btnSendTemp->TabIndex = 6;
				 this->btnSendTemp->Text = L"Prześlij";
				 this->btnSendTemp->UseVisualStyleBackColor = true;
				 this->btnSendTemp->Click += gcnew System::EventHandler(this, &MyForm::btnSendTemp_Click);
				 // 
				 // ckbTempDown
				 // 
				 this->ckbTempDown->AutoSize = true;
				 this->ckbTempDown->Location = System::Drawing::Point(139, 70);
				 this->ckbTempDown->Margin = System::Windows::Forms::Padding(4);
				 this->ckbTempDown->Name = L"ckbTempDown";
				 this->ckbTempDown->Size = System::Drawing::Size(68, 21);
				 this->ckbTempDown->TabIndex = 5;
				 this->ckbTempDown->Text = L"Ustaw";
				 this->ckbTempDown->UseVisualStyleBackColor = true;
				 this->ckbTempDown->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ckbTempDown_CheckedChanged);
				 // 
				 // txtbTempDown
				 // 
				 this->txtbTempDown->Enabled = false;
				 this->txtbTempDown->Location = System::Drawing::Point(72, 66);
				 this->txtbTempDown->Margin = System::Windows::Forms::Padding(4);
				 this->txtbTempDown->MaxLength = 4;
				 this->txtbTempDown->Name = L"txtbTempDown";
				 this->txtbTempDown->Size = System::Drawing::Size(57, 22);
				 this->txtbTempDown->TabIndex = 4;
				 this->txtbTempDown->Text = L"30";
				 this->txtbTempDown->TextChanged += gcnew System::EventHandler(this, &MyForm::txtbTempDown_TextChanged);
				 // 
				 // lblTempDown
				 // 
				 this->lblTempDown->AutoSize = true;
				 this->lblTempDown->Location = System::Drawing::Point(8, 71);
				 this->lblTempDown->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->lblTempDown->Name = L"lblTempDown";
				 this->lblTempDown->Size = System::Drawing::Size(47, 17);
				 this->lblTempDown->TabIndex = 3;
				 this->lblTempDown->Text = L"Zimna";
				 // 
				 // ckbTempUp
				 // 
				 this->ckbTempUp->AutoSize = true;
				 this->ckbTempUp->Location = System::Drawing::Point(139, 32);
				 this->ckbTempUp->Margin = System::Windows::Forms::Padding(4);
				 this->ckbTempUp->Name = L"ckbTempUp";
				 this->ckbTempUp->Size = System::Drawing::Size(68, 21);
				 this->ckbTempUp->TabIndex = 2;
				 this->ckbTempUp->Text = L"Ustaw";
				 this->ckbTempUp->UseVisualStyleBackColor = true;
				 this->ckbTempUp->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ckbTempUp_CheckedChanged);
				 // 
				 // txtbTempUp
				 // 
				 this->txtbTempUp->Enabled = false;
				 this->txtbTempUp->Location = System::Drawing::Point(72, 28);
				 this->txtbTempUp->Margin = System::Windows::Forms::Padding(4);
				 this->txtbTempUp->MaxLength = 4;
				 this->txtbTempUp->Name = L"txtbTempUp";
				 this->txtbTempUp->Size = System::Drawing::Size(57, 22);
				 this->txtbTempUp->TabIndex = 1;
				 this->txtbTempUp->Text = L"80";
				 this->txtbTempUp->TextChanged += gcnew System::EventHandler(this, &MyForm::txtbTempUp_TextChanged);
				 // 
				 // lblTempUp
				 // 
				 this->lblTempUp->AutoSize = true;
				 this->lblTempUp->Location = System::Drawing::Point(8, 33);
				 this->lblTempUp->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->lblTempUp->Name = L"lblTempUp";
				 this->lblTempUp->Size = System::Drawing::Size(55, 17);
				 this->lblTempUp->TabIndex = 0;
				 this->lblTempUp->Text = L"Gorąca";
				 // 
				 // label1
				 // 
				 this->label1->BackColor = System::Drawing::Color::Transparent;
				 this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->label1->Location = System::Drawing::Point(211, 28);
				 this->label1->Margin = System::Windows::Forms::Padding(0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(201, 97);
				 this->label1->TabIndex = 34;
				 // 
				 // timer1
				 // 
				 this->timer1->Interval = 5000;
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				 // 
				 // WczytajU
				 // 
				 this->WczytajU->Location = System::Drawing::Point(16, 73);
				 this->WczytajU->Margin = System::Windows::Forms::Padding(4);
				 this->WczytajU->Name = L"WczytajU";
				 this->WczytajU->Size = System::Drawing::Size(153, 28);
				 this->WczytajU->TabIndex = 37;
				 this->WczytajU->Text = L"Odczytaj";
				 this->WczytajU->UseVisualStyleBackColor = true;
				 this->WczytajU->Click += gcnew System::EventHandler(this, &MyForm::WczytajU_Click);
				 // 
				 // ZapiszU
				 // 
				 this->ZapiszU->Location = System::Drawing::Point(16, 37);
				 this->ZapiszU->Margin = System::Windows::Forms::Padding(4);
				 this->ZapiszU->Name = L"ZapiszU";
				 this->ZapiszU->Size = System::Drawing::Size(153, 28);
				 this->ZapiszU->TabIndex = 36;
				 this->ZapiszU->Text = L"Zapis";
				 this->ZapiszU->UseVisualStyleBackColor = true;
				 this->ZapiszU->Click += gcnew System::EventHandler(this, &MyForm::ZapiszU_Click);
				 // 
				 // label2
				 // 
				 this->label2->BackColor = System::Drawing::Color::GhostWhite;
				 this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->label2->Location = System::Drawing::Point(9, 28);
				 this->label2->Margin = System::Windows::Forms::Padding(0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(175, 117);
				 this->label2->TabIndex = 38;
				 // 
				 // button3
				 // 
				 this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->button3->Location = System::Drawing::Point(187, 348);
				 this->button3->Margin = System::Windows::Forms::Padding(4);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(221, 36);
				 this->button3->TabIndex = 41;
				 this->button3->Text = L"Ustawienia fabryczne";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
				 // 
				 // btnHelp
				 // 
				 this->btnHelp->Location = System::Drawing::Point(16, 320);
				 this->btnHelp->Margin = System::Windows::Forms::Padding(4);
				 this->btnHelp->Name = L"btnHelp";
				 this->btnHelp->Size = System::Drawing::Size(100, 28);
				 this->btnHelp->TabIndex = 42;
				 this->btnHelp->Text = L"Pomoc";
				 this->btnHelp->UseVisualStyleBackColor = true;
				 this->btnHelp->Click += gcnew System::EventHandler(this, &MyForm::btnHelp_Click);
				 // 
				 // refreshDevice
				 // 
				 this->refreshDevice->Location = System::Drawing::Point(16, 108);
				 this->refreshDevice->Name = L"refreshDevice";
				 this->refreshDevice->Size = System::Drawing::Size(153, 28);
				 this->refreshDevice->TabIndex = 43;
				 this->refreshDevice->Text = L"Cofnij zmiany";
				 this->refreshDevice->UseVisualStyleBackColor = true;
				 this->refreshDevice->Click += gcnew System::EventHandler(this, &MyForm::refreshDevice_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::Control;
				 this->ClientSize = System::Drawing::Size(541, 407);
				 this->Controls->Add(this->refreshDevice);
				 this->Controls->Add(this->btnHelp);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->WczytajU);
				 this->Controls->Add(this->ZapiszU);
				 this->Controls->Add(this->lbl1);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->btnSettings);
				 this->Controls->Add(this->lblMild);
				 this->Controls->Add(this->lblCold);
				 this->Controls->Add(this->lblHot);
				 this->Controls->Add(this->l2);
				 this->Controls->Add(this->l3);
				 this->Controls->Add(this->l4);
				 this->Controls->Add(this->l5);
				 this->Controls->Add(this->l6);
				 this->Controls->Add(this->l7);
				 this->Controls->Add(this->l8);
				 this->Controls->Add(this->l1);
				 this->Controls->Add(this->btnExit);
				 this->Controls->Add(this->lblMeter);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->label2);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->MaximizeBox = false;
				 this->Name = L"MyForm";
				 this->Text = L"Kubkuino";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private: System::Void btnSettings_Click(System::Object^  sender, System::EventArgs^  e) {
		Settings1^ form1 = gcnew Settings1();
		form1->ShowDialog();
	}
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		PortCOM::PortClose();
		Application::Exit();
	}
	private: System::Void ckbTempUp_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (ckbTempUp->Checked == true) {
			txtbTempUp->Enabled = true;
		}
		else {
			txtbTempUp->Enabled = false;
		}
	}
	private: System::Void ckbTempDown_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

		if (ckbTempDown->Checked == true) {
			txtbTempDown->Enabled = true;
		}
		else {
			txtbTempDown->Enabled = false;
		}
	}
	private: System::Void btnSendTemp_Click(System::Object^  sender, System::EventArgs^  e) {
		double dtemp = 12.32;
		using namespace std;
		String^ s = txtbTempUp->Text;
		s = s->Trim();
		double hotSet;
		double coldSet;
		bool check1 = false;
		bool check2 = false;
		if (Double::TryParse(s, hotSet)) {
			hotSet = Double::Parse(s);
			check1 = true;
		}
		else txtbTempUp->Text = "";

		s = txtbTempDown->Text;
		s = s->Trim();
		if (Double::TryParse(s, coldSet)) {
			coldSet = Double::Parse(s);
			check2 = true;
		}
		else txtbTempDown->Text = "";

		if (check1 && ckbTempUp->Checked)
			PortCOM::PortHot(hotSet);
		if (check2 && ckbTempDown->Checked)
			PortCOM::PortCold(coldSet);

		txtbTempUp->Enabled = false;
		txtbTempDown->Enabled = false;
		ckbTempUp->Checked = false;
		ckbTempDown->Checked = false;
	}

	private: System::Void txtbTempUp_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtbTempDown_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		String^ _hot = PortCOM::PortCommute("H?;");
		System::Threading::Thread::Sleep(1000);
		String^ _cold = PortCOM::PortCommute("C?;");
		System::Threading::Thread::Sleep(1000);
		txtbTempDown->Text = _cold;
		txtbTempUp->Text = _hot;

		thread1->IsBackground = true;
		thread1->Start();
		timer1->Enabled = true;
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		zegar();
	}


			 void zegar() {

				 if (t != thready::y) {
					 t = thready::y;

					 lbl1->Text = t + "\xB0" + "C"; //nie zmieniaj tego bo sie kodowanie krzaczy
					 t->Trim();
					 Double::TryParse(t, xxx);

					 if (xxx >= 95) {
						 l8->Visible = true;
						 l7->Visible = true;
						 l6->Visible = true;
						 l5->Visible = true;
						 l4->Visible = true;
						 l3->Visible = true;
						 l2->Visible = true;
						 l1->Visible = true;
					 }
					 else if (xxx >= 85) {
						 l8->Visible = false;
						 l7->Visible = true;
						 l6->Visible = true;
						 l5->Visible = true;
						 l4->Visible = true;
						 l3->Visible = true;
						 l2->Visible = true;
						 l1->Visible = true;
					 }
					 else if (xxx >= 75) {
						 l8->Visible = false;
						 l7->Visible = false;
						 l6->Visible = true;
						 l5->Visible = true;
						 l4->Visible = true;
						 l3->Visible = true;
						 l2->Visible = true;
						 l1->Visible = true;
					 }
					 else if (xxx >= 65) {
						 l8->Visible = false;
						 l7->Visible = false;
						 l6->Visible = false;
						 l5->Visible = true;
						 l4->Visible = true;
						 l3->Visible = true;
						 l2->Visible = true;
						 l1->Visible = true;
					 }
					 else if (xxx >= 55) {
						 l8->Visible = false;
						 l7->Visible = false;
						 l6->Visible = false;
						 l5->Visible = false;
						 l4->Visible = true;
						 l3->Visible = true;
						 l2->Visible = true;
						 l1->Visible = true;
					 }
					 else if (xxx >= 45) {
						 l8->Visible = false;
						 l7->Visible = false;
						 l6->Visible = false;
						 l5->Visible = false;
						 l4->Visible = false;
						 l3->Visible = true;
						 l2->Visible = true;
						 l1->Visible = true;
					 }
					 else if (xxx >= 35) {
						 l8->Visible = false;
						 l7->Visible = false;
						 l6->Visible = false;
						 l5->Visible = false;
						 l4->Visible = false;
						 l3->Visible = false;
						 l2->Visible = true;
						 l1->Visible = true;
					 }
					 else if (xxx >= 25) {
						 l8->Visible = false;
						 l7->Visible = false;
						 l6->Visible = false;
						 l5->Visible = false;
						 l4->Visible = false;
						 l3->Visible = false;
						 l2->Visible = false;
						 l1->Visible = true;
					 }
					 else {
						 l8->Visible = false;
						 l7->Visible = false;
						 l6->Visible = false;
						 l5->Visible = false;
						 l4->Visible = false;
						 l3->Visible = false;
						 l2->Visible = false;
						 l1->Visible = false;
					 }
				 }
			 }
	private: System::Void ZapiszU_Click(System::Object^  sender, System::EventArgs^  e) {
		PortCOM::PortZapiszU();
	}
	private: System::Void WczytajU_Click(System::Object^  sender, System::EventArgs^  e) {
		PortCOM::PortWczytajU();
		refresh();
	}
	private: System::Void btnHelp_Click(System::Object^  sender, System::EventArgs^  e) {
		help^ form2 = gcnew help();
		form2->Show();
	}
	private: System::Void lbl1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void refreshDevice_Click(System::Object^  sender, System::EventArgs^  e) {
		refresh();
	}
	private: System::Void refresh() {
		String^ _hot = PortCOM::PortCommute("H?;");
		System::Threading::Thread::Sleep(1000);
		String^ _cold = PortCOM::PortCommute("C?;");
		System::Threading::Thread::Sleep(1000);
		txtbTempDown->Text = _cold->Trim();
		txtbTempUp->Text = _hot->Trim();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (System::Windows::Forms::MessageBox::Show(L"Na pewno zresetować urządzenie do ustawień fabrycznych?",
			L"Przywróć ustawienia fabryczne", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			PortCOM::PortDefault();
		refresh();
	}
	};
}
