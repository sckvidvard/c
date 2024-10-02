#include "MyString.h"

int main() {
    setlocale(LC_ALL, "rus");
    MyString s1; // Вызов конструктора по умолчанию
    s1.set("ABCDEFGH"); // Ввод строки, кратной 4
    s1.print(); // Вывод строки
    s1.update(); // Изменение строки
    s1.print(); // Вывод измененной строки

    MyString s2("12345678"); // Вызов конструктора с параметрами
    s2.print();
    s2.update();
    s2.print();

    MyString s3 = s2; // Вызов конструктора копирования
    s3.print();

    return 0;
}
