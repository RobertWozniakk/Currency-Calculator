#pragma once
#define CURL_STATICLIB

#include <iostream>
#include <curl/curl.h>
#include "C:\Libs\json.hpp"

#include <cstring>

//
static size_t Writer(char* buffer, size_t size, size_t nmemb, std::string* html) {
	int result = 0;

	if (buffer != NULL) {
		html->append(buffer, size * nmemb);
		result = size * nmemb;
	}
	return result;
}
//podlaczenie do strony internetowej
std::string get_request(std::string link) {
	CURL* curl;
	std::string data;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Writer);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	return data;
}
//przekazujemy dane do curl i on wydobywa to co nas interesuje
float get_currency(int what) {


	if (what == 1) {
		auto js_obj = nlohmann::json::parse(get_request("https://api.nbp.pl/api/exchangerates/rates/a/eur?format=json"));
		return js_obj["rates"][0]["mid"].get<double>();
	}
	else if (what == 2) {
		auto js_obj = nlohmann::json::parse(get_request("https://api.nbp.pl/api/exchangerates/rates/a/usd?format=json"));
		return js_obj["rates"][0]["mid"].get<double>();
	}
	else if (what == 3) {
		auto js_obj = nlohmann::json::parse(get_request("https://api.nbp.pl/api/exchangerates/rates/a/gbp?format=json"));
		return js_obj["rates"][0]["mid"].get<double>();
	}
	else if (what == 4) {
		auto js_obj = nlohmann::json::parse(get_request("https://api.nbp.pl/api/exchangerates/rates/a/jpy?format=json"));
		return js_obj["rates"][0]["mid"].get<double>();
	}
	else if (what == 5) {
		auto js_obj = nlohmann::json::parse(get_request("https://api.nbp.pl/api/exchangerates/rates/a/uah?format=json"));
		return js_obj["rates"][0]["mid"].get<double>();
	}


	return -1;
};

namespace Project5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 113);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(327, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 182);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(236, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Euro", L"Dollar", L"Funt", L"Jen", L"Hrywnia" });
			this->comboBox1->Location = System::Drawing::Point(15, 46);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(324, 24);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"Wybierz walute";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 251);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 38);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Oblicz";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(126, 316);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 38);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Zresetuj";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 21);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Waluta";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 21);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Ilosc";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 158);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 21);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Wynik";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(281, 182);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Waluta";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(366, 366);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Kalkulator Walut";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




		// wybor w listboxie
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			
		if (Protect()) {
			float num1, Result;
			num1 = System::Convert::ToDouble(textBox1->Text);

			if (comboBox1->SelectedItem == "Euro") {
				Result = get_currency(1) * num1;
				label4->Text = L"Złotych";
			}
			else if (comboBox1->SelectedItem == "Dollar") {
				Result = get_currency(2) * num1;
				label4->Text = L"Złotych";
			}
			else if (comboBox1->SelectedItem == "Funt") {
				Result = get_currency(3) * num1;
				label4->Text = L"Złotych";
			}
			else if (comboBox1->SelectedItem == "Jen") {
				Result = get_currency(4) * num1;
				label4->Text = L"Złotych";
			}
			else if (comboBox1->SelectedItem == "Hrywnia") {
				Result = get_currency(5) * num1;
				label4->Text = L"Złotych";
			}
			else {
				textBox1->Text = L"";
				textBox2->Text = L"";
			}
			textBox2->Text = System::Convert::ToString(Result);

		}



	}
		bool Protect() { //obsługa błędów
			if ((textBox1->Text->Length == 0) || (textBox1->Text == ""))  { return false; }
			for (int i = 0; i < textBox1->Text->Length; i++) {
				if ((textBox1->Text[i] >= '1') && (textBox1->Text[i] <= '9') || (textBox1->Text[i] == ',')) {}
				else { return false;}
			}
			return true;
		} 
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // wyczyszczenie programu
	textBox1->Text = L"";
	textBox2->Text = L"";
	label3->Text = L"Wynik";
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
