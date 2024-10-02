#include "MyString.h"
#include <cstring>
#include <fstream>
#include <utility>

// Конструктор по умолчанию
MyString::MyString() : str(nullptr), length(0) {
    std::cout << "Конструктор по умолчанию вызван" << std::endl;
}

// Конструктор с параметрами
MyString::MyString(const char* s) {
    std::cout << "Конструктор с параметрами вызван" << std::endl;
    length = strlen(s);
    str = new char[length + 1];
    strcpy_s(str, length + 1, s); // Используем безопасную функцию strcpy_s
}

// Конструктор копирования
MyString::MyString(const MyString& other) {
    std::cout << "Конструктор копирования вызван" << std::endl;
    length = other.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str); // Используем безопасную функцию strcpy_s
}

// Деструктор
MyString::~MyString() {
    std::cout << "Деструктор вызван" << std::endl;
    delete[] str;
}

// Метод для ввода строки
void MyString::set(const char* s) {
    std::cout << "Метод set() вызван" << std::endl;
    delete[] str; // Освобождаем старую строку, если она была
    length = strlen(s);
    str = new char[length + 1];
    strcpy_s(str, length + 1, s); // Используем безопасную функцию strcpy_s
}

// Остальная часть кода остаётся без изменений...


// Метод для изменения строки
void MyString::update() {
    std::cout << "Метод update() вызван" << std::endl;

    // Проверка, что длина строки кратна 4
    if (length % 4 == 0 && length > 0) {
        // Сохраняем исходную строку для записи в файл
        std::string originalStr(str);

        // Меняем первую половину строки с второй
        size_t half_length = length / 2;
        for (size_t i = 0; i < half_length; ++i) {
            std::swap(str[i], str[half_length + i]);
        }

        // Открываем файл для записи
        std::ofstream outFile("output.txt");
        if (outFile.is_open()) {
            outFile << "Исходная строка: " << originalStr << std::endl;
            outFile << "Измененная строка: " << str << std::endl;
            outFile.close();
            std::cout << "Результат сохранен в файл output.txt" << std::endl;
        }
        else {
            std::cerr << "Ошибка при открытии файла!" << std::endl;
        }
    }
    else {
        std::cout << "Длина строки не кратна 4, изменения не произведены." << std::endl;
    }
}


// Метод для вывода строки на экран
void MyString::print() const {
    std::cout << "Метод print() вызван" << std::endl;
    if (str != nullptr) {
        std::cout << "Строка: " << str << std::endl;
    }
    else {
        std::cout << "Строка пуста" << std::endl;
    }
}
