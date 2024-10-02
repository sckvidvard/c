#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

// ����������� ������ MyString
class MyString {
private:
    char* str; // ��������� �� ������ � ������������ ������
    size_t length; // ����� ������

public:
    // ������������
    MyString(); // ����������� �� ���������
    MyString(const char* s); // ����������� � �����������
    MyString(const MyString& other); // ����������� �����������

    // ����������
    ~MyString();

    // ������
    void set(const char* s); // ����� ����� ������
    void update(); // ����� ��������� ������ �������� �������
    void print() const; // ����� ������ ������ �� �����
};

#endif // MYSTRING_H
