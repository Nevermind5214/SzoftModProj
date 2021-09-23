#pragma once
#include <iostream>
#include <string>
#include <vector>


double calculate(std::vector<char> inputCharVect);
static std::string toStandardString(System::String^ string);

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
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonEquals = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonEquals
			// 
			this->buttonEquals->Location = System::Drawing::Point(69, 158);
			this->buttonEquals->Name = L"buttonEquals";
			this->buttonEquals->Size = System::Drawing::Size(75, 23);
			this->buttonEquals->TabIndex = 0;
			this->buttonEquals->Text = L"=";
			this->buttonEquals->UseVisualStyleBackColor = true;
			this->buttonEquals->Click += gcnew System::EventHandler(this, &Form1::buttonEquals_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(44, 96);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonEquals);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonEquals_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string mystrung = toStandardString(this->textBox1->Text);
		std::vector<char> data(mystrung.begin(), mystrung.end());
		this->textBox1->Text = calculate(data).ToString();

	}
	};
}
