#pragma once
#include "MyForm.h"
#include "PortCOM.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Podsumowanie informacji o Connect
	/// </summary>

	public ref class Connect : public System::Windows::Forms::Form
	{
	public:
		Connect(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			GetPorts();
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Connect()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::Button^  btnExit;
	protected:


	private: System::Windows::Forms::Label^  lblTitle;
	private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::ComboBox^  comboBox1;



	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


	public:
		System::String^ port;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// btnConnect
			// 
			this->btnConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnConnect->Location = System::Drawing::Point(153, 81);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(75, 30);
			this->btnConnect->TabIndex = 0;
			this->btnConnect->Text = L"Po³¹cz";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &Connect::btnConnect_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(153, 150);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 23);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Wyjœcie";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &Connect::btnExit_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->lblTitle->Location = System::Drawing::Point(55, 22);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(143, 33);
			this->lblTitle->TabIndex = 3;
			this->lblTitle->Text = L"Kubkuino";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(34, 81);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(98, 29);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 4;
			// 
			// Connect
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(252, 185);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnConnect);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Connect";
			this->Text = L"Po³¹cz";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) {

		Cursor->Current = Cursors::WaitCursor;

		if (comboBox1->Text == "") {
			comboBox1->Text = L"Z³y port";
		}
		else {
			bool initSerial = PortCOM::initPort((String^)comboBox1->Text);
			if (initSerial) {
				MyForm^ form = gcnew MyForm();
				this->Hide();
				form->ShowDialog();
				Cursor->Current = Cursors::Default;
				//this->Close();
			}
			else {
				comboBox1->Text = "B³¹d";
				//PortCOM::PortClose();
				Cursor->Current = Cursors::Default;
			}

		}
	}
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
			 void GetPorts() {
				 array<String^>^ Ports = SerialPort::GetPortNames();
				 comboBox1->Items->AddRange(Ports);
				 //comboBox1->SelectedIndex = 0;
			 }
	};
}
