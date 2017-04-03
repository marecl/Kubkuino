#pragma once
#include <windows.h>
#include <time.h>
namespace TestAplikacjaPC_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				if(this->serialPort1->IsOpen){
					this->serialPort1->Write("qquit;");
					this->serialPort1->Close();
				}
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	public: System::IO::Ports::SerialPort^  serialPort1;
	private: 

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;


	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox5;

	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::RadioButton^  radioButton12;
	private: System::Windows::Forms::RadioButton^  radioButton11;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::CheckBox^  checkBox5;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(193, 281);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Send Command";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->Location = System::Drawing::Point(12, 283);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(175, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(57, 307);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(175, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 310);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Output:";
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 7500;
			this->serialPort1->WriteTimeout = 7500;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Connect";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 19);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(63, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Ceramika";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(75, 19);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(68, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Aluminium";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(149, 19);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Szklanka";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->checkBox5);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Location = System::Drawing::Point(6, 49);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(261, 70);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Mode";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(149, 43);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 8;
			this->button8->Text = L"\?";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(7, 47);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(82, 17);
			this->checkBox5->TabIndex = 8;
			this->checkBox5->Text = L"Dno plaskie";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox5_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->button6);
			this->groupBox2->Location = System::Drawing::Point(6, 125);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(261, 51);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Hot";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Checked = true;
			this->radioButton2->Location = System::Drawing::Point(148, 23);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(51, 17);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Read";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(205, 23);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(41, 17);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->Text = L"Set";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(88, 22);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(54, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(7, 20);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Execute";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(88, 21);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(55, 20);
			this->textBox4->TabIndex = 3;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(6, 18);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 1;
			this->button7->Text = L"Execute";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Checked = true;
			this->radioButton3->Location = System::Drawing::Point(148, 22);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(51, 17);
			this->radioButton3->TabIndex = 6;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Read";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Controls->Add(this->button7);
			this->groupBox3->Controls->Add(this->radioButton3);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Location = System::Drawing::Point(6, 182);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(261, 54);
			this->groupBox3->TabIndex = 10;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Cold";
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(205, 22);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(41, 17);
			this->radioButton4->TabIndex = 7;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Set";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->textBox10);
			this->groupBox4->Controls->Add(this->groupBox1);
			this->groupBox4->Controls->Add(this->groupBox3);
			this->groupBox4->Controls->Add(this->groupBox2);
			this->groupBox4->Location = System::Drawing::Point(12, 35);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(275, 242);
			this->groupBox4->TabIndex = 11;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Temperature Controls";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(140, 26);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"State";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Temperatura:";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(82, 23);
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(52, 20);
			this->textBox10->TabIndex = 13;
			this->textBox10->TextChanged += gcnew System::EventHandler(this, &Form1::textBox10_TextChanged_1);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->groupBox8);
			this->groupBox5->Controls->Add(this->groupBox7);
			this->groupBox5->Controls->Add(this->groupBox6);
			this->groupBox5->Location = System::Drawing::Point(293, 35);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(314, 292);
			this->groupBox5->TabIndex = 12;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"General Control";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->checkBox4);
			this->groupBox8->Controls->Add(this->label4);
			this->groupBox8->Controls->Add(this->label3);
			this->groupBox8->Controls->Add(this->label2);
			this->groupBox8->Controls->Add(this->textBox9);
			this->groupBox8->Controls->Add(this->textBox8);
			this->groupBox8->Controls->Add(this->textBox7);
			this->groupBox8->Controls->Add(this->button11);
			this->groupBox8->Controls->Add(this->checkBox3);
			this->groupBox8->Location = System::Drawing::Point(6, 195);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(301, 91);
			this->groupBox8->TabIndex = 2;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Reset";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Enabled = false;
			this->checkBox4->Location = System::Drawing::Point(7, 36);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(54, 17);
			this->checkBox4->TabIndex = 8;
			this->checkBox4->Text = L"Sure\?";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox4_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(89, 60);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Password:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(107, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(96, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Defaults:";
			// 
			// textBox9
			// 
			this->textBox9->HideSelection = false;
			this->textBox9->Location = System::Drawing::Point(151, 57);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(58, 20);
			this->textBox9->TabIndex = 4;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &Form1::textBox9_TextChanged);
			// 
			// textBox8
			// 
			this->textBox8->HideSelection = false;
			this->textBox8->Location = System::Drawing::Point(151, 37);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(58, 20);
			this->textBox8->TabIndex = 3;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Form1::textBox8_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->HideSelection = false;
			this->textBox7->Location = System::Drawing::Point(151, 17);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(58, 20);
			this->textBox7->TabIndex = 2;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Form1::textBox7_TextChanged);
			// 
			// button11
			// 
			this->button11->Enabled = false;
			this->button11->Location = System::Drawing::Point(6, 55);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(73, 23);
			this->button11->TabIndex = 1;
			this->button11->Text = L"Set Defaults";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(7, 19);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(54, 17);
			this->checkBox3->TabIndex = 0;
			this->checkBox3->Text = L"Reset";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->checkBox2);
			this->groupBox7->Controls->Add(this->checkBox1);
			this->groupBox7->Controls->Add(this->panel4);
			this->groupBox7->Controls->Add(this->panel3);
			this->groupBox7->Location = System::Drawing::Point(6, 103);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(301, 86);
			this->groupBox7->TabIndex = 1;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Power";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(174, 49);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(70, 17);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"Backlight";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(174, 23);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(50, 17);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Mute";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->radioButton12);
			this->panel4->Controls->Add(this->radioButton11);
			this->panel4->Location = System::Drawing::Point(6, 47);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(162, 22);
			this->panel4->TabIndex = 3;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel4_Paint);
			// 
			// radioButton12
			// 
			this->radioButton12->AutoSize = true;
			this->radioButton12->Location = System::Drawing::Point(85, 1);
			this->radioButton12->Name = L"radioButton12";
			this->radioButton12->Size = System::Drawing::Size(63, 17);
			this->radioButton12->TabIndex = 2;
			this->radioButton12->Text = L"LED Off";
			this->radioButton12->UseVisualStyleBackColor = true;
			this->radioButton12->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton12_CheckedChanged);
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Checked = true;
			this->radioButton11->Location = System::Drawing::Point(4, 1);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(63, 17);
			this->radioButton11->TabIndex = 0;
			this->radioButton11->TabStop = true;
			this->radioButton11->Text = L"LED On";
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton11_CheckedChanged);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->radioButton10);
			this->panel3->Controls->Add(this->radioButton9);
			this->panel3->Location = System::Drawing::Point(6, 19);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(162, 22);
			this->panel3->TabIndex = 2;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel3_Paint);
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(85, 3);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(76, 17);
			this->radioButton10->TabIndex = 1;
			this->radioButton10->Text = L"Display Off";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton10_CheckedChanged);
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Checked = true;
			this->radioButton9->Location = System::Drawing::Point(3, 3);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(76, 17);
			this->radioButton9->TabIndex = 0;
			this->radioButton9->TabStop = true;
			this->radioButton9->Text = L"Display On";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton9_CheckedChanged);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->panel2);
			this->groupBox6->Controls->Add(this->panel1);
			this->groupBox6->Controls->Add(this->textBox5);
			this->groupBox6->Controls->Add(this->textBox6);
			this->groupBox6->Controls->Add(this->button9);
			this->groupBox6->Controls->Add(this->button10);
			this->groupBox6->Location = System::Drawing::Point(6, 19);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(301, 78);
			this->groupBox6->TabIndex = 0;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Bluetooth";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->radioButton8);
			this->panel2->Controls->Add(this->radioButton7);
			this->panel2->Location = System::Drawing::Point(191, 50);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(110, 21);
			this->panel2->TabIndex = 2;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(60, 1);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(41, 17);
			this->radioButton8->TabIndex = 3;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"Set";
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton8_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Checked = true;
			this->radioButton7->Location = System::Drawing::Point(3, 1);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(51, 17);
			this->radioButton7->TabIndex = 2;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Read";
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton7_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->radioButton6);
			this->panel1->Controls->Add(this->radioButton5);
			this->panel1->Location = System::Drawing::Point(191, 15);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(110, 26);
			this->panel1->TabIndex = 1;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(60, 7);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(41, 17);
			this->radioButton6->TabIndex = 3;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Set";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton6_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Checked = true;
			this->radioButton5->Location = System::Drawing::Point(3, 7);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(51, 17);
			this->radioButton5->TabIndex = 2;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Read";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton5_CheckedChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(85, 21);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 1;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox5_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(85, 50);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 1;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Form1::textBox6_TextChanged);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(4, 19);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 0;
			this->button9->Text = L"Name";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(4, 48);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 0;
			this->button10->Text = L"Password";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"Termopara";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::notifyIcon1_MouseDoubleClick);
			// 
			// timer1
			// 
			this->timer1->Interval = 3000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button12
			// 
			this->button12->Enabled = false;
			this->button12->Location = System::Drawing::Point(93, 6);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 23);
			this->button12->TabIndex = 13;
			this->button12->Text = L"Disconnect";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(174, 8);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(44, 20);
			this->textBox11->TabIndex = 14;
			this->textBox11->Text = L"COM10";
			this->textBox11->TextChanged += gcnew System::EventHandler(this, &Form1::textBox11_TextChanged);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(241, 305);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(46, 23);
			this->button13->TabIndex = 15;
			this->button13->Text = L"Clear";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 333);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Termopara";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox2->Text = "";
				 this->serialPort1->Write(this->textBox1->Text+";");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				this->textBox11->ReadOnly = true;
				try {
					this->serialPort1->PortName = this->textBox11->Text;
					this->serialPort1->Open();
					this->serialPort1->DiscardInBuffer();
					this->serialPort1->DiscardOutBuffer();
					this->serialPort1->Write("e;");
					Sleep(100);
					this->textBox2->Text = this->serialPort1->ReadLine();
				}
				catch (...) {
					this->textBox2->Text = "ERROR";
				}
				if(this->textBox2->Text[0] == 'H'){
					this->serialPort1->Write("D7;");  //LCD, LED, MUTE, Backlight
					Sleep(1500);
					String ^ powermenu = this->serialPort1->ReadLine();
					try{
						if(powermenu[0] == '1') this->radioButton9->Checked = true;
						else if(powermenu[0] == '2') {
							this->panel3->Enabled = false;
						} else {
							this->panel3->Enabled = true;
							this->radioButton9->Checked = false;
						}
						if(powermenu[1] == '1') this->radioButton11->Checked = true;
						else this->radioButton12->Checked = true;
						if(powermenu[2] == '1') this->checkBox1->Checked = true;
						else this->checkBox1->Checked = false;
						if(powermenu[3] == '1') this->checkBox2->Checked = true;
						else if(powermenu[3] == '2'){
							this->checkBox2->Enabled = false;
						} else this->checkBox2->Enabled = true;

					} catch (System::IndexOutOfRangeException ^ c) {
						if(c) {
							this->textBox2->Text = "ERROR! ENABLING ALL";
							this->serialPort1->Write("D01;");
							this->textBox2->Text = this->serialPort1->ReadLine();
							this->serialPort1->Write("D31;");
							this->textBox2->Text = this->serialPort1->ReadLine();
							this->serialPort1->Write("D40;");
							this->textBox2->Text = this->serialPort1->ReadLine();
							this->serialPort1->Write("D51;");
							this->textBox2->Text = this->serialPort1->ReadLine();
							this->radioButton9->Checked = true;
							this->radioButton11->Checked = true;
							this->checkBox1->Checked = false;
							this->checkBox2->Checked = true;
						}
					}
					this->button12->Enabled = true;
					this->button2->Enabled = false;
					this->timer1->Enabled = true;
				} else {
					this->textBox2->Text = "Select another COM port or check the device";
					if(this->serialPort1->IsOpen) this->serialPort1->Close();
					this->button12->Enabled = false;
					this->timer1->Enabled = false;
					this->button2->Enabled = true;
					this->textBox11->ReadOnly = false;
				}
			}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->serialPort1->Write("M0;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serialPort1->Write("M1;");
			 this->textBox2->Text = this->serialPort1->ReadLine();
		 }
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serialPort1->Write("M2;");
			 this->textBox2->Text = this->serialPort1->ReadLine();
		 }
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioButton2->Checked){
				 this->serialPort1->Write("h;");
				 this->textBox3->Text = this->serialPort1->ReadLine();
			 } else if(this->radioButton1->Checked) {
				 this->serialPort1->Write("H"+this->textBox3->Text+";");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
	private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox3->ReadOnly = true;
			 this->button6->Text = "Read";
			 this->textBox3->Text = "";
		 }
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox3->ReadOnly = false;
			 this->button6->Text = "Set";
		 }
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioButton3->Checked){
				 this->serialPort1->Write("c;");
				 this->textBox4->Text = this->serialPort1->ReadLine();
			 } else if(this->radioButton4->Checked) {
				 this->serialPort1->Write("C"+this->textBox4->Text+";");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox4->ReadOnly = true;
			 this->button7->Text = "Read";
		 }
	private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox4->ReadOnly = false;
			 this->button7->Text = "Set";
			 this->textBox4->Text = "";
		 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serialPort1->Write("m;");
			 this->textBox2->Text = this->serialPort1->ReadLine();
		 }
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioButton5->Checked){
				 this->serialPort1->Write("SAT+NAME?");
				 String ^ name = this->serialPort1->ReadLine();
				 this->textBox2->Text = name;
				 String ^ nametwo = "";
				 int cnt = 6;
				 bool ^ stop = false;
				 try{
					 while(name[cnt] != '\0' || stop){
						 nametwo += name[cnt];
						 cnt++;
					 }
				 } catch (System::IndexOutOfRangeException ^ a) {
					 stop = true;
				 }
				 finally {
					 this->textBox5->Text = nametwo;
				 }
			 }
			 if(this->radioButton6->Checked){
				 this->serialPort1->Write("SAT+NAME="+this->textBox5->Text+";");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
	private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox5->ReadOnly = true;
		 }
	private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox5->ReadOnly = false;
			 this->textBox5->Text = "";
		 }
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->radioButton7->Checked){
					 this->serialPort1->Write("SAT+PSWD?");
					 String ^ name = this->serialPort1->ReadLine();
					 this->textBox2->Text = name;
					 String ^ nametwo = "";
					 int cnt = 6;
					 bool ^ stop = false;
					 try {
						 while(name[cnt] != '\0' || stop){
							 nametwo += name[cnt];
							 cnt++;
						 }
					 } catch (System::IndexOutOfRangeException ^ b) {
						 stop = true;
					 } finally {
						 this->textBox6->Text = nametwo;
					 }
				 }
				 if(this->radioButton8->Checked){
					 this->serialPort1->Write("SAT+PSWD="+this->textBox6->Text+";");
					 this->textBox2->Text = this->serialPort1->ReadLine();
				 }
			 }
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox6->ReadOnly = true;
		 }
private: System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox6->ReadOnly = false;
			 this->textBox6->Text = "";
		 }

private: System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioButton9->Checked && this->serialPort1->IsOpen){
				 this->serialPort1->Write("D01;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioButton10->Checked && this->serialPort1->IsOpen){
				 this->serialPort1->Write("D00;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
private: System::Void radioButton11_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioButton11->Checked && this->serialPort1->IsOpen){
				 this->serialPort1->Write("D31;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
private: System::Void radioButton12_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->radioButton12->Checked && this->serialPort1->IsOpen){
				 this->serialPort1->Write("D30;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox1->Checked && this->serialPort1->IsOpen){
				 this->serialPort1->Write("D40;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 } else{
				 if(this->serialPort1->IsOpen){
					 this->serialPort1->Write("D41;");
					 this->textBox2->Text = this->serialPort1->ReadLine();
				 }
			 }
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox2->Checked && this->serialPort1->IsOpen){
				 this->serialPort1->Write("D51;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 } else {
				 if(this->serialPort1->IsOpen){
					 this->serialPort1->Write("D50;");
					 this->textBox2->Text = this->serialPort1->ReadLine();
				 }
			 }
		 }
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox3->Checked)
				 this->checkBox4->Enabled = true;
			 else{
				 this->checkBox4->Enabled = false;
				 this->checkBox4->Checked = false;
			 }
		 }
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox4->Checked)
				 this->button11->Enabled = true;
			 else
				 this->button11->Enabled = false;
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serialPort1->Write("d;");
			 this->checkBox3->Checked = false;
			 this->textBox7->Text = this->serialPort1->ReadLine();
			 this->textBox8->Text = this->serialPort1->ReadLine();
			 this->textBox9->Text = this->serialPort1->ReadLine();
		 }
private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox10_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(this->serialPort1->IsOpen){
				 try{
					 this->serialPort1->DiscardInBuffer();
					 this->serialPort1->DiscardOutBuffer();
					 this->serialPort1->Write("r1;");
					 this->textBox10->Text = this->serialPort1->ReadLine()+"\xB0"+"C";
					 this->serialPort1->Write("t;");
					 String ^ tmp = this->serialPort1->ReadLine();
					 switch(tmp[0]){
						 case 'H': this->label6->Text = "Too hot";break;
						 case 'R': this->label6->Text = "Perfect";break;
						 case 'C': this->label6->Text = "Too cold";break;
					 }
				 } catch (System::TimeoutException^ serex) {
					 if(this->serialPort1->IsOpen)
						 this->timer1->Stop();
						 this->textBox2->Text = "Waiting for device...";
				 }
				 this->timer1->Start();
			 } else {
				 this->textBox2->Text = "Device disconnected!";
				 this->button12->Enabled = false;
				 this->button2->Enabled = true;
				 this->timer1->Enabled = false;
				 this->textBox11->ReadOnly = false;
				 this->serialPort1->Close();
			 }
		 }
private: System::Void textBox10_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 try{
				 this->serialPort1->Write("qquit;");
			 } catch (System::TimeoutException^ btcls) {}
			 Sleep(1000);
			 if(this->serialPort1->IsOpen)
				 this->serialPort1->Close();
			 this->button12->Enabled = false;
			 this->button2->Enabled = true;
			 this->timer1->Enabled = false;
			 this->textBox11->ReadOnly = false;

		 }
private: System::Void textBox11_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox2->Text = "";
			 this->textBox1->Text = "";
		 }
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void panel4_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox5->Checked) {
				 this->serialPort1->Write("D81;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 } else {
				 this->serialPort1->Write("D80;");
				 this->textBox2->Text = this->serialPort1->ReadLine();
			 }
		 }
};
}

