#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

// Определение класса MyString
class MyString {
private:
    char* str; // Указатель на строку в динамической памяти
    size_t length; // Длина строки

public:
    // Конструкторы
    MyString(); // Конструктор по умолчанию
    MyString(const char* s); // Конструктор с параметрами
    MyString(const MyString& other); // Конструктор копирования

    // Деструктор
    ~MyString();

    // Методы
    void set(const char* s); // Метод ввода строки
    void update(); // Метод изменения строки согласно заданию
    void print() const; // Метод вывода строки на экран
};

#endif // MYSTRING_H
