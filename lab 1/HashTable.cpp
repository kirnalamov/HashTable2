#include "HashTable.h"
#include <vector>
#include <cstdlib>
#include <random>
#include "HashTableModel.hpp"
#include <Windows.h>


using namespace lab2;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew HashTable);
    return 0;
}

std::vector<int> get_uniq(int n) {
    int seed = time(nullptr);
    srand(seed);
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(1e4, 1e5);

    std::vector<int> arr;
    for (int i = 0; i < n; i++) {
        int element = distribution(generator);
        while (std::find(arr.begin(), arr.end(), element) != arr.end()) {
            element = distribution(generator);
        }

        arr.push_back(element);
    }
    return arr;
}

System::Void lab2::HashTable::button_Click(System::Object^ sender, System::EventArgs^ e) {
    auto arr = get_uniq(48);
    tableModel.clear();
    for (auto& i : arr) {
        tableModel.push(i); // Используем оператор -> для доступа к методу
    }
    return System::Void();
}

System::Void lab2::HashTable::updateTable(System::Object^ sender, System::EventArgs^ e) {

    fillFactorLable->Text = "Table fill factor : " +( round(tableModel.fillFactor() * 1000) / 1000 ).ToString();
    averageLable->Text = "Average number of steps : " + (round(tableModel.average() * 1000) / 1000).ToString();
    dataGridView1->Rows->Clear();
    this->dataGridView1->ColumnCount = 2*3; 
    this->dataGridView1->RowCount = 35;

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 3; j++) {
            if (i * 3 + j >= tableModel.get_t()) break;
            dataGridView1->Rows[i]->Cells[2 * j]->Value = (i * 3 + j).ToString();
            dataGridView1->Rows[i]->Cells[2 * j]->Style->BackColor = System::Drawing::Color::LightBlue;
            if (tableModel.get_ind(i * 3 + j) >= 0) dataGridView1->Rows[i]->Cells[2*j+1]->Value = tableModel.get_ind(i * 3 + j).ToString();
            else {
                dataGridView1->Rows[i]->Cells[2 * j + 1]->Value = "";
            }
        }
    }
    // Заполняем DataGridView данными из вашей модели
  
  
}

System::Void  lab2::HashTable::checkfind_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    // Установите состояние остальных CheckBox
    if (checkfind->Checked) {
        checkDelete->Checked = false;
        checkReplace->Checked = false;
        checkInsert->Checked = false;
        ReplaceValue->ReadOnly = true;
    }
}

System::Void  lab2::HashTable::checkDelete_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (checkDelete->Checked) {
        checkfind->Checked = false;
        checkInsert->Checked = false;
        checkReplace->Checked = false;
        ReplaceValue->ReadOnly = true;
    }
}

System::Void  lab2::HashTable::checkInsert_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (checkInsert->Checked) {
        checkfind->Checked = false;
        checkDelete->Checked = false;
        checkReplace->Checked = false;
        ReplaceValue->ReadOnly = true;
    }
}

System::Void  lab2::HashTable::checkReplace_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (checkReplace->Checked) {
        checkfind->Checked = false;
        checkDelete->Checked = false;
        checkInsert->Checked = false;
        ReplaceValue->ReadOnly = false;
    }
}

System::Void lab2::HashTable::InsertElementWithDialog(int element)
{

    System::Windows::Forms::DialogResult result = MessageBox::Show(
        "Хотите вставить элемент " +(element).ToString()  + " ? ",              
        "Подтверждение вставки",                 
        MessageBoxButtons::YesNo,                
        MessageBoxIcon::Question                 
    );

    // Проверяем, выбрал ли пользователь "Yes"
    if (result == System::Windows::Forms::DialogResult::Yes) {
        // Действие по вставке элемента
        if (tableModel.find(element) >= 0) {
            MessageBox::Show("Зачение " + ElementValue->Text + " уже присудствует на индексе " + (tableModel.find(element)).ToString(), "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
            int r = tableModel.find(element);
            dataGridView1->Rows[r / 3]->Cells[2 * (r % 3)]->Style->BackColor = System::Drawing::Color::Green;
            dataGridView1->Rows[r / 3]->Cells[2 * (r % 3) + 1]->Style->BackColor = System::Drawing::Color::Green;
            return;
        }
        tableModel.push(element);
        int r = tableModel.find(element);
        dataGridView1->Rows[r / 3]->Cells[2 * (r % 3)]->Style->BackColor = System::Drawing::Color::Green;
        dataGridView1->Rows[r / 3]->Cells[2 * (r % 3) + 1]->Style->BackColor = System::Drawing::Color::Green;
        MessageBox::Show("Зачение " + ElementValue->Text + " вставленно на индекс " + (tableModel.find(element)).ToString(), "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    else {
        // Пользователь выбрал "No", ничего не делаем
        MessageBox::Show("Вставка отменена.");
    }
    return System::Void();
}



System::Void lab2::HashTable::execute_Click(System::Object^ sender, System::EventArgs^ e)
{

    this->updateTable(sender, e);
    if (checkInsert->Checked) {
        int val = Convert::ToInt32((ElementValue->Text));
        if (tableModel.find(val) >= 0) {
            MessageBox::Show("Зачение " + ElementValue->Text + " уже присудствует на индексе " + (tableModel.find(val)).ToString(), "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
            int r = tableModel.find(val);
            dataGridView1->Rows[r/3]->Cells[2 * (r%3)]->Style->BackColor = System::Drawing::Color::Green;
            dataGridView1->Rows[r/3]->Cells[2 * (r%3)+1]->Style->BackColor = System::Drawing::Color::Green;
            return;
        }
        tableModel.push(val);
        int r = tableModel.find(val);
        dataGridView1->Rows[r / 3]->Cells[2 * (r % 3)]->Style->BackColor = System::Drawing::Color::Green;
        dataGridView1->Rows[r / 3]->Cells[2 * (r % 3)+1]->Style->BackColor = System::Drawing::Color::Green;
        MessageBox::Show("Зачение " + ElementValue->Text + " вставленно на индекс " + (tableModel.find(val)).ToString(), "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    if (checkfind->Checked) {
        int val = Convert::ToInt32((ElementValue->Text));
        if (tableModel.find(val) >= 0) {
            int r = tableModel.find(val);
            dataGridView1->Rows[r / 3]->Cells[2 * (r % 3)]->Style->BackColor = System::Drawing::Color::Green;
            dataGridView1->Rows[r / 3]->Cells[2 * (r % 3) + 1]->Style->BackColor = System::Drawing::Color::Green;
            MessageBox::Show("Зачение " + ElementValue->Text + " присудствует на индексе " + (tableModel.find(val)).ToString(), "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }
        
        MessageBox::Show("Зачение " + ElementValue->Text + " отсутствует в таблице", "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    if (checkDelete->Checked) {
        int val = Convert::ToInt32((ElementValue->Text));
        if (tableModel.find(val) >= 0) {
            int r = tableModel.find(val);
            tableModel.del(tableModel.find(val));
            MessageBox::Show("Зачение " + ElementValue->Text + " удалено на индексе " + (r).ToString(), "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);

            return;
        }
        
        MessageBox::Show("Зачение " + ElementValue->Text + " отсутствует в таблице", "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    if (checkReplace->Checked) {
        int val = Convert::ToInt32((ElementValue->Text));
        int rep = Convert::ToInt32((ReplaceValue->Text));
        if (tableModel.find(val) >= 0) {
            int r = tableModel.find(val);
            tableModel.del(tableModel.find(val));
            MessageBox::Show("Зачение " + ElementValue->Text + " заменено на значение " + (rep).ToString(), "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
            
            tableModel.push(rep);
            r = tableModel.find(rep);
            dataGridView1->Rows[r / 3]->Cells[2 * (r % 3)]->Style->BackColor = System::Drawing::Color::Green;
            dataGridView1->Rows[r / 3]->Cells[2 * (r % 3) + 1]->Style->BackColor = System::Drawing::Color::Green;
            return;
        }

        MessageBox::Show("Зачение " + ElementValue->Text + " отсутствует в таблице", "Заголовок", MessageBoxButtons::OK, MessageBoxIcon::Information);
        InsertElementWithDialog(rep);
      
    }
   


    return System::Void();
}



System::Void lab2::HashTable::HashTable_Load(System::Object^ sender, System::EventArgs^ e) {
    this->tableModel.observers += gcnew System::EventHandler(this, &HashTable::updateTable);
    this->updateTable( sender,e);
    return System::Void();
}
