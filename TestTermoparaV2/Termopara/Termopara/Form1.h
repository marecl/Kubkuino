#pragma once


namespace Termopara {

	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;
	using namespace System::IO;

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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				if(this->serial->IsOpen){
					 this->timer1->Enabled = false;
					this->serial->Write("qquit;");
					this->serial->Close();
				}
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::IO::Ports::SerialPort^  serial;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  button8;



	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Button^  button9;

	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::GroupBox^  groupBox9;
	private: System::Windows::Forms::Button^  button14;





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
			this->serial = (gcnew System::IO::Ports::SerialPort(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Polacz";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"COM10";
			// 
			// serial
			// 
			this->serial->ReadTimeout = 10000;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(54, 17);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(34, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(54, 44);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(34, 20);
			this->textBox3->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Gorąca";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(134, 19);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(56, 17);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Ustaw";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(134, 46);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(56, 17);
			this->checkBox2->TabIndex = 7;
			this->checkBox2->Text = L"Ustaw";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(9, 70);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Wyślij do urządzenia";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Location = System::Drawing::Point(6, 19);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(202, 106);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ustawienia Temperatur";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Zimna";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(94, 44);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(34, 20);
			this->textBox5->TabIndex = 10;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(94, 17);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(34, 20);
			this->textBox4->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(5, 122);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 39);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Odczyt";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 5000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Location = System::Drawing::Point(214, 266);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(213, 101);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Konsola";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(6, 74);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(201, 20);
			this->textBox7->TabIndex = 3;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(132, 45);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Wyczyść";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 45);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Wyślij";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(6, 19);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(201, 20);
			this->textBox6->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->groupBox5);
			this->groupBox3->Controls->Add(this->groupBox4);
			this->groupBox3->Location = System::Drawing::Point(6, 131);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(202, 185);
			this->groupBox3->TabIndex = 12;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Tryby";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button14);
			this->groupBox5->Controls->Add(this->button5);
			this->groupBox5->Controls->Add(this->comboBox1);
			this->groupBox5->Location = System::Drawing::Point(6, 106);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(184, 73);
			this->groupBox5->TabIndex = 1;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Pomiar";
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(133, 17);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(48, 23);
			this->button14->TabIndex = 2;
			this->button14->Text = L"\?";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(6, 46);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(175, 23);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Włącz tryb";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Automatyczny", L"Wymuś pomiar", L"Ręczny", L"Tylko dno"});
			this->comboBox1->Location = System::Drawing::Point(6, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"Wybierz tryb pomiaru";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button6);
			this->groupBox4->Controls->Add(this->checkBox3);
			this->groupBox4->Controls->Add(this->comboBox2);
			this->groupBox4->Controls->Add(this->button8);
			this->groupBox4->Location = System::Drawing::Point(6, 19);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(184, 81);
			this->groupBox4->TabIndex = 0;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Materiał";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(6, 42);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Ustaw";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Location = System::Drawing::Point(87, 46);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(62, 17);
			this->checkBox3->TabIndex = 5;
			this->checkBox3->Text = L"Płaskie";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox3_CheckedChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Ceramika", L"Aluminium", L"Szkło"});
			this->comboBox2->Location = System::Drawing::Point(6, 17);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->Text = L"Wybierz materiał";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(133, 15);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(48, 23);
			this->button8->TabIndex = 3;
			this->button8->Text = L"\?";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->button9);
			this->groupBox6->Controls->Add(this->checkBox7);
			this->groupBox6->Controls->Add(this->checkBox6);
			this->groupBox6->Controls->Add(this->checkBox5);
			this->groupBox6->Controls->Add(this->checkBox4);
			this->groupBox6->Location = System::Drawing::Point(6, 19);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(202, 93);
			this->groupBox6->TabIndex = 13;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Interfejs";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(6, 66);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(91, 23);
			this->button9->TabIndex = 6;
			this->button9->Text = L"Odczytaj";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(103, 43);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(52, 17);
			this->checkBox7->TabIndex = 3;
			this->checkBox7->Text = L"Alarm";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox7_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(103, 20);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(47, 17);
			this->checkBox6->TabIndex = 2;
			this->checkBox6->Text = L"LED";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox6_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(6, 43);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(91, 17);
			this->checkBox5->TabIndex = 1;
			this->checkBox5->Text = L"Podświetlenie";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox5_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(7, 20);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(85, 17);
			this->checkBox4->TabIndex = 0;
			this->checkBox4->Text = L"Wyświetlacz";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox4_CheckedChanged);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->groupBox8);
			this->groupBox7->Controls->Add(this->groupBox6);
			this->groupBox7->Location = System::Drawing::Point(214, 19);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(213, 241);
			this->groupBox7->TabIndex = 14;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Ustawienia";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->button12);
			this->groupBox8->Controls->Add(this->textBox9);
			this->groupBox8->Controls->Add(this->textBox8);
			this->groupBox8->Controls->Add(this->button11);
			this->groupBox8->Controls->Add(this->button10);
			this->groupBox8->Location = System::Drawing::Point(7, 119);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(200, 116);
			this->groupBox8->TabIndex = 14;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Bluetooth";
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(7, 80);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(181, 23);
			this->button12->TabIndex = 4;
			this->button12->Text = L"Reset do ustawień fabrycznych";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(102, 52);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(86, 20);
			this->textBox9->TabIndex = 3;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(102, 22);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(86, 20);
			this->textBox8->TabIndex = 2;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(7, 50);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(84, 23);
			this->button11->TabIndex = 1;
			this->button11->Text = L"Zmień hasło";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(7, 20);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(84, 23);
			this->button10->TabIndex = 0;
			this->button10->Text = L"Zmień nazwę";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 67);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(117, 23);
			this->button7->TabIndex = 15;
			this->button7->Text = L"Przywróć ostatnie";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click_1);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(12, 96);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(117, 23);
			this->button13->TabIndex = 16;
			this->button13->Text = L"Zapisz";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->groupBox1);
			this->groupBox9->Controls->Add(this->groupBox3);
			this->groupBox9->Controls->Add(this->groupBox7);
			this->groupBox9->Controls->Add(this->groupBox2);
			this->groupBox9->Enabled = false;
			this->groupBox9->Location = System::Drawing::Point(135, 12);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(434, 376);
			this->groupBox9->TabIndex = 17;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Zarządzanie";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(575, 393);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Termopara";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(this->button1->Text == "Polacz"){
					 this->serial->PortName = this->textBox1->Text;
					 this->serial->Open();
					 this->textBox1->ReadOnly = true;
					 this->serial->Write("e;");
					 if(String::Compare(this->serial->ReadLine(), "HELLO")){
						 this->serial->Write("H?;");
						 this->textBox2->Text = this->serial->ReadLine();
						 this->serial->Write("C?;");
						 this->textBox3->Text = this->serial->ReadLine();
						 this->button1->Text = "Rozlacz";

						 this->serial->Write("D6;");
						 String^ stan = this->serial->ReadLine();
						 bool stany[5];
						 for(int a = 0; a < 5; a++){
							 if(stan[a] == '0')	stany[a] = false;
							 else stany[a] = true;
						 }
						 if(stany[0]) this->checkBox4->Checked = true;
						 else this->checkBox4->Checked = false;
						 if(stany[1]) this->checkBox5->Checked = true;
						 else this->checkBox5->Checked = false;
						 if(stany[2]) this->checkBox6->Checked = true;
						 else this->checkBox6->Checked = false;
						 if(stany[3]) this->checkBox7->Checked = true;
						 else this->checkBox7->Checked = false;
						 if(stany[4]) this->checkBox3->Checked = true;
						 else this->checkBox3->Checked = false;

						 this->serial->Write("D7?;");
						 String^ a = this->serial->ReadLine();
						 if(a->Contains("0")) this->comboBox1->SelectedIndex = 0;
						 else if(a->Contains("1")) this->comboBox1->SelectedIndex = 1;
						 else if(a->Contains("2")) this->comboBox1->SelectedIndex = 2;
						 else if(a->Contains("3")) this->comboBox1->SelectedIndex = 3;

						 this->serial->Write("M?;");
						 a = this->serial->ReadLine();
						 if(a->Contains("0")) this->comboBox2->SelectedIndex = 0;
						 else if(a->Contains("1")) this->comboBox2->SelectedIndex = 1;
						 else if(a->Contains("2")) this->comboBox2->SelectedIndex = 2;
						 this->timer1->Enabled = true;
						 this->groupBox9->Enabled = true;
					 } else {
						 this->timer1->Enabled = false;
						 this->groupBox9->Enabled = false;
						 this->textBox1->ReadOnly = false;
						 this->serial->Write("qquit;");
						 this->serial->Close();
						 this->button1->Text = "Polacz";
					 }
				 } else {
					 this->textBox1->ReadOnly = false;
					 this->timer1->Enabled = false;
					 this->serial->Write("qquit;");
					 this->groupBox9->Enabled = false;
					 this->serial->DiscardInBuffer();
					 this->serial->DiscardOutBuffer();
					 this->serial->Close();
					 this->button1->Text = "Polacz";
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox1->Checked || this->checkBox2->Checked)
				 this->button2->Enabled = true;
			 else
				 this->button2->Enabled = false;
		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox1->Checked || this->checkBox2->Checked)
				 this->button2->Enabled = true;
			 else
				 this->button2->Enabled = false;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ tempout;
			 if(this->checkBox1->Checked){
				 tempout = "H"+this->textBox4->Text+";";
				 this->serial->Write(tempout);
				 this->textBox2->Text = this->textBox4->Text;
				 this->textBox4->Text = "";
			 }
			 if(this->checkBox2->Checked){
				 tempout = "C"+this->textBox5->Text+";";
				 this->serial->Write(tempout);
				 this->textBox3->Text = this->textBox5->Text;
				 this->textBox5->Text = "";
			 }
			 this->checkBox1->Checked = false;
			 this->checkBox2->Checked = false;
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 this->serial->DiscardInBuffer();
			 this->serial->DiscardOutBuffer();
			 this->serial->Write("r1;");
			 this->label3->Text = this->serial->ReadLine();
			 double hot,cold,ext;
			 Double::TryParse(this->textBox2->Text, hot);
			 Double::TryParse(this->textBox3->Text, cold);
			 Double::TryParse(this->label3->Text, ext);
			 if(ext > hot)
				 this->label3->ForeColor = System::Drawing::Color::Red;
			 else if (ext < cold)
				 this->label3->ForeColor = System::Drawing::Color::Blue;
			 else if (ext < hot && ext > cold)
				 this->label3->ForeColor = System::Drawing::Color::Green;

		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 int a = this->serial->ReadTimeout;
			 this->serial->ReadTimeout = 750;
			 this->serial->Write(this->textBox6->Text);
			 try { this->textBox7->Text = this->serial->ReadLine();}
			 catch(...) { this->textBox7->Text = "";}
			 finally { this->serial->ReadTimeout = a;}
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox6->Text = "";
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serial->Write("M?;");
			 String^ a = this->serial->ReadLine();
			 if(a->Contains("0")) this->comboBox2->SelectedIndex = 0;
			 else if(a->Contains("1")) this->comboBox2->SelectedIndex = 1;
			 else if(a->Contains("2")) this->comboBox2->SelectedIndex = 2;
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->comboBox1->SelectedIndex < 0 || this->comboBox1->SelectedIndex > 3)
				 this->button5->Enabled = false;
			 else this->button5->Enabled = true;
		 }

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 switch(this->comboBox1->SelectedIndex){
				 case 0: this->serial->Write("D70;");break;
				 case 1: this->serial->Write("D71;");break;
				 case 2: this->serial->Write("D72;");break;
				 case 3: this->serial->Write("D73;");break;
			 }

		 }
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 switch(this->comboBox2->SelectedIndex){
				 case 0:this->serial->Write("M0;");break;
				 case 1:this->serial->Write("M1;");break;
				 case 2:this->serial->Write("M2;");break;
			 }
			 if(this->checkBox3->Checked)
				 this->serial->Write("D51;");
			 else
				 this->serial->Write("D50;");
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serial->Write("D6;");
			 String^ stan = this->serial->ReadLine();
			 bool stany[5];
			 for(int a = 0; a < 5; a++){
				 if(stan[a] == '0')	stany[a] = false;
				 else stany[a] = true;
			 }
			 this->checkBox4->Enabled = false;
			 this->checkBox5->Enabled = false;
			 this->checkBox6->Enabled = false;
			 this->checkBox7->Enabled = false;
			 if(stany[0]) this->checkBox4->Checked = true;
			 else this->checkBox4->Checked = false;
			 if(stany[1]) this->checkBox5->Checked = true;
			 else this->checkBox5->Checked = false;
			 if(stany[2]) this->checkBox6->Checked = true;
			 else this->checkBox6->Checked = false;
			 if(stany[3]) this->checkBox7->Checked = true;
			 else this->checkBox7->Checked = false;
			 if(stany[4]) this->checkBox3->Checked = true;
			 else this->checkBox3->Checked = false;
			 this->checkBox4->Enabled = true;
			 this->checkBox5->Enabled = true;
			 this->checkBox6->Enabled = true;
			 this->checkBox7->Enabled = true;
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(!(String::IsNullOrEmpty(this->textBox8->Text))){
				 String^ tempout = this->textBox8->Text;
				 tempout = "SAT+NAME="+tempout;
				 this->serial->Write(tempout);
				 this->textBox8->Text = this->serial->ReadLine();
			 }
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(!(String::IsNullOrEmpty(this->textBox9->Text))){
				 String^ tempout = this->textBox9->Text;
				 tempout = "SAT+PSWD="+tempout;
				 this->serial->Write(tempout);
				 this->textBox9->Text = this->serial->ReadLine();
			 }
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->button12->Text[0] == 'R'){
				 this->button12->Text = "Na pewno?";
				 return;
			 }
			 if(this->button12->Text[0] == 'N'){
				 this->button12->Text = "Resetowanie... Czekaj";
				 this->serial->Write("d;");
				 this->textBox7->Text = this->serial->ReadLine();
				 this->textBox7->Text = this->serial->ReadLine();
				 this->textBox7->Text = this->serial->ReadLine();
				 this->button12->Text = "Reset do ustawien fabrycznych";
			 }
		 }
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox4->Checked) this->serial->Write("D01;");
			 else this->serial->Write("D00;");
		 }
private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox5->Checked) this->serial->Write("D11;");
			 else this->serial->Write("D10;");
		 }
private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox6->Checked) this->serial->Write("D31;");
			 else this->serial->Write("D30;");
		 }
private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->checkBox7->Checked) this->serial->Write("D41;");
			 else this->serial->Write("D40;");
		 }
private: System::Void button7_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 if(File::Exists("config.xml")){
				 XmlTextReader^ config = gcnew XmlTextReader("config.xml");
				 while(config->Read()){
					 if(String::Compare(config->Name, "goraca") == 0){
						 this->textBox4->Text = config->ReadElementContentAsString();
						 this->checkBox1->Checked = true;
					}
					 if(String::Compare(config->Name, "zimna") == 0){
						 this->textBox5->Text = config->ReadElementContentAsString();
						 this->checkBox2->Checked = true;
					 }
					 if(String::Compare(config->Name, "material") == 0){
						 switch(config->ReadElementContentAsInt()){
							case 0: this->comboBox2->SelectedIndex = 0;break;
							case 1: this->comboBox2->SelectedIndex = 1;break;
							case 2: this->comboBox2->SelectedIndex = 2;break;
						 }
					 }
					 if(String::Compare(config->Name, "pomiar") == 0){
						 switch(config->ReadElementContentAsInt()){
							case 0: this->comboBox1->SelectedIndex = 0;break;
							case 1: this->comboBox1->SelectedIndex = 1;break;
							case 2: this->comboBox1->SelectedIndex = 2;break;
							case 3: this->comboBox1->SelectedIndex = 3;break;
						 }
					 }
					 if(String::Compare(config->Name, "wyswietlacz") == 0)
						 this->checkBox4->Checked = config->ReadElementContentAsBoolean();
					 if(String::Compare(config->Name, "podswietlenie") == 0)
						 this->checkBox5->Checked = config->ReadElementContentAsBoolean();
					 if(String::Compare(config->Name, "led") == 0)
						this->checkBox6->Checked = config->ReadElementContentAsBoolean();
					 if(String::Compare(config->Name, "alarm") == 0)
						 this->checkBox7->Checked = config->ReadElementContentAsBoolean();
					 if(String::Compare(config->Name, "plaskie") == 0)
						 this->checkBox3->Checked = config->ReadElementContentAsBoolean();
					config->MoveToNextAttribute();
				 }
				 this->button2->PerformClick();
				 this->button5->PerformClick();
				 this->button6->PerformClick();
				 config->Close();
			 }
			 else MessageBox::Show(L"Nie znaleziono pliku konfiguracyjnego!");
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(File::Exists("config.xml")){
				 XmlDocument^ save = gcnew XmlDocument;
				 save->Load("config.xml");
				 XmlNode^ wart = save->DocumentElement->SelectSingleNode("goraca");
				 wart->InnerText = (String^)this->textBox2->Text;

				 wart = save->DocumentElement->SelectSingleNode("zimna");
				 wart->InnerText = (String^)this->textBox3->Text;

				 wart = save->DocumentElement->SelectSingleNode("material");
				 if(this->comboBox2->SelectedIndex == -1) wart->InnerText = "0";
				 else wart->InnerText = System::Convert::ToString(this->comboBox2->SelectedIndex);

				 wart = save->DocumentElement->SelectSingleNode("pomiar");
				 if(this->comboBox2->SelectedIndex == -1) wart->InnerText = "0";
				 else wart->InnerText = System::Convert::ToString(this->comboBox1->SelectedIndex);

				 wart = save->DocumentElement->SelectSingleNode("wyswietlacz");
				 if(this->checkBox4->Checked) wart->InnerText = "true";
				 else wart->InnerText = "false";

				 wart = save->DocumentElement->SelectSingleNode("podswietlenie");
				 if(this->checkBox5->Checked) wart->InnerText = "true";
				 else wart->InnerText = "false";

				 wart = save->DocumentElement->SelectSingleNode("led");
				 if(this->checkBox6->Checked) wart->InnerText = "true";
				 else wart->InnerText = "false";

				 wart = save->DocumentElement->SelectSingleNode("alarm");
				 if(this->checkBox7->Checked) wart->InnerText = "true";
				 else wart->InnerText = "false";

				 wart = save->DocumentElement->SelectSingleNode("plaskie");
				 if(this->checkBox3->Checked) wart->InnerText = "true";
				 else wart->InnerText = "false";
				 save->Save("config.xml");
			 }
		 }
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serial->Write("D7?;");
			 String^ a = this->serial->ReadLine();
			 if(a->Contains("0")) this->comboBox1->SelectedIndex = 0;
			 else if(a->Contains("1")) this->comboBox1->SelectedIndex = 1;
			 else if(a->Contains("2")) this->comboBox1->SelectedIndex = 2;
			 else if(a->Contains("3")) this->comboBox1->SelectedIndex = 3;
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}