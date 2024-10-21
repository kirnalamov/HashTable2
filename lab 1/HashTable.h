#pragma once
#include "HashTableModel.hpp"
namespace lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ HashTable
	/// </summary>
	public ref class HashTable : public System::Windows::Forms::Form
	{
	public: HashTableModel tableModel;

	
	public:
		
		HashTable(void)
		{	

			
			InitializeComponent();
			
		}
		


	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~HashTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ fillFactorLable;
	private: System::Windows::Forms::Label^ averageLable;
	private: System::Windows::Forms::Button^ button;
	private: System::Windows::Forms::CheckBox^ checkfind;
	private: System::Windows::Forms::CheckBox^ checkDelete;

	private: System::Windows::Forms::CheckBox^ checkInsert;
	private: System::Windows::Forms::TextBox^ ElementValue;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ execute;
	private: System::Windows::Forms::TextBox^ ReplaceValue;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkReplace;







	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->fillFactorLable = (gcnew System::Windows::Forms::Label());
			this->averageLable = (gcnew System::Windows::Forms::Label());
			this->button = (gcnew System::Windows::Forms::Button());
			this->checkfind = (gcnew System::Windows::Forms::CheckBox());
			this->checkDelete = (gcnew System::Windows::Forms::CheckBox());
			this->checkInsert = (gcnew System::Windows::Forms::CheckBox());
			this->ElementValue = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->execute = (gcnew System::Windows::Forms::Button());
			this->ReplaceValue = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkReplace = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(22, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(698, 463);
			this->dataGridView1->TabIndex = 0;
			// 
			// fillFactorLable
			// 
			this->fillFactorLable->AutoSize = true;
			this->fillFactorLable->Font = (gcnew System::Drawing::Font(L"Open Sans", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fillFactorLable->Location = System::Drawing::Point(739, 29);
			this->fillFactorLable->Name = L"fillFactorLable";
			this->fillFactorLable->Size = System::Drawing::Size(169, 31);
			this->fillFactorLable->TabIndex = 1;
			this->fillFactorLable->Text = L"Table fill factor :";
			// 
			// averageLable
			// 
			this->averageLable->AutoSize = true;
			this->averageLable->Font = (gcnew System::Drawing::Font(L"Open Sans", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->averageLable->Location = System::Drawing::Point(739, 84);
			this->averageLable->Name = L"averageLable";
			this->averageLable->Size = System::Drawing::Size(270, 31);
			this->averageLable->TabIndex = 2;
			this->averageLable->Text = L"Average number of steps: ";
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(828, 442);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(163, 50);
			this->button->TabIndex = 3;
			this->button->Text = L"fill with random numbers";
			this->button->UseVisualStyleBackColor = true;
			this->button->Click += gcnew System::EventHandler(this, &HashTable::button_Click);
			// 
			// checkfind
			// 
			this->checkfind->AutoSize = true;
			this->checkfind->Location = System::Drawing::Point(745, 134);
			this->checkfind->Name = L"checkfind";
			this->checkfind->Size = System::Drawing::Size(49, 17);
			this->checkfind->TabIndex = 4;
			this->checkfind->Text = L"Find ";
			this->checkfind->UseVisualStyleBackColor = true;
			this->checkfind->CheckedChanged += gcnew System::EventHandler(this, &HashTable::checkfind_CheckedChanged);
			// 
			// checkDelete
			// 
			this->checkDelete->AutoSize = true;
			this->checkDelete->Location = System::Drawing::Point(800, 134);
			this->checkDelete->Name = L"checkDelete";
			this->checkDelete->Size = System::Drawing::Size(57, 17);
			this->checkDelete->TabIndex = 4;
			this->checkDelete->Text = L"Delete";
			this->checkDelete->UseVisualStyleBackColor = true;
			this->checkDelete->CheckedChanged += gcnew System::EventHandler(this, &HashTable::checkDelete_CheckedChanged);
			// 
			// checkInsert
			// 
			this->checkInsert->AutoSize = true;
			this->checkInsert->Location = System::Drawing::Point(863, 134);
			this->checkInsert->Name = L"checkInsert";
			this->checkInsert->Size = System::Drawing::Size(52, 17);
			this->checkInsert->TabIndex = 5;
			this->checkInsert->Text = L"Insert";
			this->checkInsert->UseVisualStyleBackColor = true;
			this->checkInsert->CheckedChanged += gcnew System::EventHandler(this, &HashTable::checkInsert_CheckedChanged);
			// 
			// ElementValue
			// 
			this->ElementValue->Font = (gcnew System::Drawing::Font(L"Open Sans Medium", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ElementValue->Location = System::Drawing::Point(745, 216);
			this->ElementValue->Name = L"ElementValue";
			this->ElementValue->Size = System::Drawing::Size(159, 36);
			this->ElementValue->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Open Sans Medium", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(739, 182);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 31);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Element";
			// 
			// execute
			// 
			this->execute->Location = System::Drawing::Point(745, 388);
			this->execute->Name = L"execute";
			this->execute->Size = System::Drawing::Size(172, 34);
			this->execute->TabIndex = 9;
			this->execute->Text = L"execute";
			this->execute->UseVisualStyleBackColor = true;
			this->execute->Click += gcnew System::EventHandler(this, &HashTable::execute_Click);
			// 
			// ReplaceValue
			// 
			this->ReplaceValue->Font = (gcnew System::Drawing::Font(L"Open Sans Medium", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ReplaceValue->Location = System::Drawing::Point(745, 330);
			this->ReplaceValue->Name = L"ReplaceValue";
			this->ReplaceValue->Size = System::Drawing::Size(159, 36);
			this->ReplaceValue->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Open Sans Medium", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(739, 276);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(195, 31);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Replace element";
			// 
			// checkReplace
			// 
			this->checkReplace->AutoSize = true;
			this->checkReplace->Location = System::Drawing::Point(921, 134);
			this->checkReplace->Name = L"checkReplace";
			this->checkReplace->Size = System::Drawing::Size(66, 17);
			this->checkReplace->TabIndex = 10;
			this->checkReplace->Text = L"Replace";
			this->checkReplace->UseVisualStyleBackColor = true;
			this->checkReplace->CheckedChanged += gcnew System::EventHandler(this, &HashTable::checkReplace_CheckedChanged);
			// 
			// HashTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1085, 507);
			this->Controls->Add(this->checkReplace);
			this->Controls->Add(this->execute);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ReplaceValue);
			this->Controls->Add(this->ElementValue);
			this->Controls->Add(this->checkInsert);
			this->Controls->Add(this->checkDelete);
			this->Controls->Add(this->checkfind);
			this->Controls->Add(this->button);
			this->Controls->Add(this->averageLable);
			this->Controls->Add(this->fillFactorLable);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"HashTable";
			this->Text = L"HashTable";
			this->Load += gcnew System::EventHandler(this, &HashTable::HashTable_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void HashTable_Load(System::Object^ sender, System::EventArgs^ e);
	public:  System::Void HashTable::updateTable(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void checkfind_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkDelete_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkInsert_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void execute_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkReplace_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void InsertElementWithDialog(int element);
};
}
