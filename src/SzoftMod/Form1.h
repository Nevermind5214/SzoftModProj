#pragma once
#include <iostream>
#include <string>
#include <vector>


double calculate(std::vector<char> inputCharVect);
static std::string toStandardString(System::String^ string);
static String^ toSystemString(std::string myString);

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonEquals;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button0;
	private: System::Windows::Forms::Button^ buttonPlus;
	private: System::Windows::Forms::Button^ buttonMinus;
	private: System::Windows::Forms::Label^ labelRetVal;
	private: System::Windows::Forms::Button^ buttonDot;
	private: System::Windows::Forms::Button^ buttonMultiply;
	private: System::Windows::Forms::Button^ buttonDivide;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::Button^ buttonBackspace;
	private: System::Windows::Forms::Button^ buttonLBracket;
	private: System::Windows::Forms::Button^ buttonRBracket;
	private: System::Windows::Forms::Button^ buttonPower;
	private: System::Windows::Forms::Button^ buttonSqrt;
	private: System::Windows::Forms::Button^ buttonSin;
	private: System::Windows::Forms::Button^ buttonCos;
	private: System::Windows::Forms::Button^ buttonTan;

	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonEquals = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->buttonPlus = (gcnew System::Windows::Forms::Button());
			this->buttonMinus = (gcnew System::Windows::Forms::Button());
			this->labelRetVal = (gcnew System::Windows::Forms::Label());
			this->buttonDot = (gcnew System::Windows::Forms::Button());
			this->buttonMultiply = (gcnew System::Windows::Forms::Button());
			this->buttonDivide = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->buttonBackspace = (gcnew System::Windows::Forms::Button());
			this->buttonLBracket = (gcnew System::Windows::Forms::Button());
			this->buttonRBracket = (gcnew System::Windows::Forms::Button());
			this->buttonPower = (gcnew System::Windows::Forms::Button());
			this->buttonSqrt = (gcnew System::Windows::Forms::Button());
			this->buttonSin = (gcnew System::Windows::Forms::Button());
			this->buttonCos = (gcnew System::Windows::Forms::Button());
			this->buttonTan = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonEquals
			// 
			this->buttonEquals->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->buttonEquals->Location = System::Drawing::Point(104, 248);
			this->buttonEquals->Name = L"buttonEquals";
			this->buttonEquals->Size = System::Drawing::Size(40, 40);
			this->buttonEquals->TabIndex = 0;
			this->buttonEquals->Text = L"=";
			this->buttonEquals->UseVisualStyleBackColor = false;
			this->buttonEquals->Click += gcnew System::EventHandler(this, &Form1::buttonEquals_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(224, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Silver;
			this->button1->Location = System::Drawing::Point(12, 202);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(40, 40);
			this->button1->TabIndex = 2;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Silver;
			this->button2->Location = System::Drawing::Point(58, 202);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 40);
			this->button2->TabIndex = 3;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Silver;
			this->button3->Location = System::Drawing::Point(104, 202);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(40, 40);
			this->button3->TabIndex = 4;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Silver;
			this->button4->Location = System::Drawing::Point(12, 156);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(40, 40);
			this->button4->TabIndex = 5;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Silver;
			this->button5->Location = System::Drawing::Point(58, 156);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(40, 40);
			this->button5->TabIndex = 6;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Silver;
			this->button6->Location = System::Drawing::Point(104, 156);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(40, 40);
			this->button6->TabIndex = 7;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Silver;
			this->button7->Location = System::Drawing::Point(12, 110);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(40, 40);
			this->button7->TabIndex = 8;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Silver;
			this->button8->Location = System::Drawing::Point(58, 110);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(40, 40);
			this->button8->TabIndex = 9;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Silver;
			this->button9->Location = System::Drawing::Point(104, 110);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(40, 40);
			this->button9->TabIndex = 10;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button0
			// 
			this->button0->BackColor = System::Drawing::Color::Silver;
			this->button0->Location = System::Drawing::Point(58, 248);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(40, 40);
			this->button0->TabIndex = 11;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = false;
			this->button0->Click += gcnew System::EventHandler(this, &Form1::button0_Click);
			// 
			// buttonPlus
			// 
			this->buttonPlus->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonPlus->Location = System::Drawing::Point(150, 202);
			this->buttonPlus->Name = L"buttonPlus";
			this->buttonPlus->Size = System::Drawing::Size(40, 40);
			this->buttonPlus->TabIndex = 12;
			this->buttonPlus->Text = L"+";
			this->buttonPlus->UseVisualStyleBackColor = false;
			this->buttonPlus->Click += gcnew System::EventHandler(this, &Form1::buttonPlus_Click);
			// 
			// buttonMinus
			// 
			this->buttonMinus->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonMinus->Location = System::Drawing::Point(150, 248);
			this->buttonMinus->Name = L"buttonMinus";
			this->buttonMinus->Size = System::Drawing::Size(40, 40);
			this->buttonMinus->TabIndex = 13;
			this->buttonMinus->Text = L"-";
			this->buttonMinus->UseVisualStyleBackColor = false;
			this->buttonMinus->Click += gcnew System::EventHandler(this, &Form1::buttonMinus_Click);
			// 
			// labelRetVal
			// 
			this->labelRetVal->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->labelRetVal->AutoSize = true;
			this->labelRetVal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labelRetVal->Location = System::Drawing::Point(12, 40);
			this->labelRetVal->Name = L"labelRetVal";
			this->labelRetVal->Size = System::Drawing::Size(15, 16);
			this->labelRetVal->TabIndex = 14;
			this->labelRetVal->Text = L"0";
			this->labelRetVal->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// buttonDot
			// 
			this->buttonDot->BackColor = System::Drawing::Color::Silver;
			this->buttonDot->Location = System::Drawing::Point(12, 248);
			this->buttonDot->Name = L"buttonDot";
			this->buttonDot->Size = System::Drawing::Size(40, 40);
			this->buttonDot->TabIndex = 15;
			this->buttonDot->Text = L",";
			this->buttonDot->UseVisualStyleBackColor = false;
			this->buttonDot->Click += gcnew System::EventHandler(this, &Form1::buttonDot_Click);
			// 
			// buttonMultiply
			// 
			this->buttonMultiply->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonMultiply->Location = System::Drawing::Point(150, 156);
			this->buttonMultiply->Name = L"buttonMultiply";
			this->buttonMultiply->Size = System::Drawing::Size(40, 40);
			this->buttonMultiply->TabIndex = 16;
			this->buttonMultiply->Text = L"*";
			this->buttonMultiply->UseVisualStyleBackColor = false;
			this->buttonMultiply->Click += gcnew System::EventHandler(this, &Form1::buttonMultiply_Click);
			// 
			// buttonDivide
			// 
			this->buttonDivide->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonDivide->Location = System::Drawing::Point(150, 110);
			this->buttonDivide->Name = L"buttonDivide";
			this->buttonDivide->Size = System::Drawing::Size(40, 40);
			this->buttonDivide->TabIndex = 17;
			this->buttonDivide->Text = L"/";
			this->buttonDivide->UseVisualStyleBackColor = false;
			this->buttonDivide->Click += gcnew System::EventHandler(this, &Form1::buttonDivide_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonClear->Location = System::Drawing::Point(12, 64);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(40, 40);
			this->buttonClear->TabIndex = 18;
			this->buttonClear->Text = L"C";
			this->buttonClear->UseVisualStyleBackColor = false;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// buttonBackspace
			// 
			this->buttonBackspace->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonBackspace->Location = System::Drawing::Point(58, 64);
			this->buttonBackspace->Name = L"buttonBackspace";
			this->buttonBackspace->Size = System::Drawing::Size(40, 40);
			this->buttonBackspace->TabIndex = 19;
			this->buttonBackspace->Text = L"«";
			this->buttonBackspace->UseVisualStyleBackColor = false;
			this->buttonBackspace->Click += gcnew System::EventHandler(this, &Form1::buttonBackspace_Click);
			// 
			// buttonLBracket
			// 
			this->buttonLBracket->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonLBracket->Location = System::Drawing::Point(104, 64);
			this->buttonLBracket->Name = L"buttonLBracket";
			this->buttonLBracket->Size = System::Drawing::Size(40, 40);
			this->buttonLBracket->TabIndex = 20;
			this->buttonLBracket->Text = L"(";
			this->buttonLBracket->UseVisualStyleBackColor = false;
			this->buttonLBracket->Click += gcnew System::EventHandler(this, &Form1::buttonLBracket_Click);
			// 
			// buttonRBracket
			// 
			this->buttonRBracket->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonRBracket->Location = System::Drawing::Point(150, 64);
			this->buttonRBracket->Name = L"buttonRBracket";
			this->buttonRBracket->Size = System::Drawing::Size(40, 40);
			this->buttonRBracket->TabIndex = 21;
			this->buttonRBracket->Text = L")";
			this->buttonRBracket->UseVisualStyleBackColor = false;
			this->buttonRBracket->Click += gcnew System::EventHandler(this, &Form1::buttonRBracket_Click);
			// 
			// buttonPower
			// 
			this->buttonPower->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonPower->Location = System::Drawing::Point(196, 64);
			this->buttonPower->Name = L"buttonPower";
			this->buttonPower->Size = System::Drawing::Size(40, 40);
			this->buttonPower->TabIndex = 22;
			this->buttonPower->Text = L"x^y";
			this->buttonPower->UseVisualStyleBackColor = false;
			this->buttonPower->Click += gcnew System::EventHandler(this, &Form1::buttonPower_Click);
			// 
			// buttonSqrt
			// 
			this->buttonSqrt->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonSqrt->Location = System::Drawing::Point(196, 110);
			this->buttonSqrt->Name = L"buttonSqrt";
			this->buttonSqrt->Size = System::Drawing::Size(40, 40);
			this->buttonSqrt->TabIndex = 23;
			this->buttonSqrt->Text = L"√";
			this->buttonSqrt->UseVisualStyleBackColor = false;
			this->buttonSqrt->Click += gcnew System::EventHandler(this, &Form1::buttonSqrt_Click);
			// 
			// buttonSin
			// 
			this->buttonSin->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonSin->Location = System::Drawing::Point(196, 156);
			this->buttonSin->Name = L"buttonSin";
			this->buttonSin->Size = System::Drawing::Size(40, 40);
			this->buttonSin->TabIndex = 24;
			this->buttonSin->Text = L"Sin";
			this->buttonSin->UseVisualStyleBackColor = false;
			this->buttonSin->Click += gcnew System::EventHandler(this, &Form1::buttonSin_Click);
			// 
			// buttonCos
			// 
			this->buttonCos->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonCos->Location = System::Drawing::Point(196, 202);
			this->buttonCos->Name = L"buttonCos";
			this->buttonCos->Size = System::Drawing::Size(40, 40);
			this->buttonCos->TabIndex = 25;
			this->buttonCos->Text = L"Cos";
			this->buttonCos->UseVisualStyleBackColor = false;
			this->buttonCos->Click += gcnew System::EventHandler(this, &Form1::buttonCos_Click);
			// 
			// buttonTan
			// 
			this->buttonTan->BackColor = System::Drawing::Color::LightSteelBlue;
			this->buttonTan->Location = System::Drawing::Point(196, 248);
			this->buttonTan->Name = L"buttonTan";
			this->buttonTan->Size = System::Drawing::Size(40, 40);
			this->buttonTan->TabIndex = 26;
			this->buttonTan->Text = L"Tan";
			this->buttonTan->UseVisualStyleBackColor = false;
			this->buttonTan->Click += gcnew System::EventHandler(this, &Form1::buttonTan_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(249, 301);
			this->Controls->Add(this->buttonTan);
			this->Controls->Add(this->buttonCos);
			this->Controls->Add(this->buttonSin);
			this->Controls->Add(this->buttonSqrt);
			this->Controls->Add(this->buttonPower);
			this->Controls->Add(this->buttonRBracket);
			this->Controls->Add(this->buttonLBracket);
			this->Controls->Add(this->buttonBackspace);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonDivide);
			this->Controls->Add(this->buttonMultiply);
			this->Controls->Add(this->buttonDot);
			this->Controls->Add(this->labelRetVal);
			this->Controls->Add(this->buttonMinus);
			this->Controls->Add(this->buttonPlus);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonEquals);
			this->Name = L"Form1";
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void doTheCalc() {
			std::string mystrung = toStandardString(this->textBox1->Text);
			std::vector<char> data(mystrung.begin(), mystrung.end());

			try {
				this->labelRetVal->ForeColor = System::Drawing::Color::Black;
				this->labelRetVal->Text = toSystemString((std::to_string(calculate(data))));
			}
			catch (char const* errorText) {
				this->labelRetVal->ForeColor = System::Drawing::Color::Red;
				this->labelRetVal->Text = toSystemString(errorText);
			}
			catch (std::vector<char> errorVect) {
				std::string koztesString(errorVect.begin(), errorVect.end());
				this->labelRetVal->ForeColor = System::Drawing::Color::Red;
				this->labelRetVal->Text = toSystemString(koztesString);
			}
			catch (double value) {
				this->labelRetVal->ForeColor = System::Drawing::Color::Red;
				this->labelRetVal->Text = toSystemString(std::to_string(value));
			}
			catch (...) {
				this->labelRetVal->ForeColor = System::Drawing::Color::Red;
				this->labelRetVal->Text = "Valami hiba van báttya";
			}
		}

	private: System::Void buttonEquals_Click(System::Object^ sender, System::EventArgs^ e) {
		doTheCalc();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "1";
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "2";
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "3";
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "4";
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "5";
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "6";
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "7";
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "8";
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "9";
	}
	private: System::Void button0_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "0";
	}
	private: System::Void buttonPlus_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "+";
	}
	private: System::Void buttonMinus_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "-";
	}
	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = "";
		this->labelRetVal->Text = "0";
	}
	private: System::Void buttonDot_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + ".";
	}
	private: System::Void buttonLBracket_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "(";
	}
	private: System::Void buttonRBracket_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + ")";
	}
	private: System::Void buttonDivide_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "/";
	}
	private: System::Void buttonMultiply_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "*";
	}
	private: System::Void buttonPower_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "^";
	}
	private: System::Void buttonSqrt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "sqrt(";
	}
	private: System::Void buttonSin_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "sin(";
	}
	private: System::Void buttonCos_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "cos(";
	}
	private: System::Void buttonTan_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->textBox1->Text + "tan(";
	}
	private: System::Void buttonBackspace_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox1->Text->Length > 1) {
			this->textBox1->Text = this->textBox1->Text->Substring(0, this->textBox1->Text->Length - 1);
		}
		else {
			this->textBox1->Text = "";
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		doTheCalc();
	}
	};
}
