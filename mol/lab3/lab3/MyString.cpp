#include "MyString.h"
#include <cstring>
#include <fstream>
#include <utility>

// ����������� �� ���������
MyString::MyString() : str(nullptr), length(0) {
    std::cout << "����������� �� ��������� ������" << std::endl;
}

// ����������� � �����������
MyString::MyString(const char* s) {
    std::cout << "����������� � ����������� ������" << std::endl;
    length = strlen(s);
    str = new char[length + 1];
    strcpy_s(str, length + 1, s); // ���������� ���������� ������� strcpy_s
}

// ����������� �����������
MyString::MyString(const MyString& other) {
    std::cout << "����������� ����������� ������" << std::endl;
    length = other.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str); // ���������� ���������� ������� strcpy_s
}

// ����������
MyString::~MyString() {
    std::cout << "���������� ������" << std::endl;
    delete[] str;
}

// ����� ��� ����� ������
void MyString::set(const char* s) {
    std::cout << "����� set() ������" << std::endl;
    delete[] str; // ����������� ������ ������, ���� ��� ����
    length = strlen(s);
    str = new char[length + 1];
    strcpy_s(str, length + 1, s); // ���������� ���������� ������� strcpy_s
}

// ��������� ����� ���� ������� ��� ���������...


// ����� ��� ��������� ������
void MyString::update() {
    std::cout << "����� update() ������" << std::endl;

    // ��������, ��� ����� ������ ������ 4
    if (length % 4 == 0 && length > 0) {
        // ��������� �������� ������ ��� ������ � ����
        std::string originalStr(str);

        // ������ ������ �������� ������ � ������
        size_t half_length = length / 2;
        for (size_t i = 0; i < half_length; ++i) {
            std::swap(str[i], str[half_length + i]);
        }

        // ��������� ���� ��� ������
        std::ofstream outFile("output.txt");
        if (outFile.is_open()) {
            outFile << "�������� ������: " << originalStr << std::endl;
            outFile << "���������� ������: " << str << std::endl;
            outFile.close();
            std::cout << "��������� �������� � ���� output.txt" << std::endl;
        }
        else {
            std::cerr << "������ ��� �������� �����!" << std::endl;
        }
    }
    else {
        std::cout << "����� ������ �� ������ 4, ��������� �� �����������." << std::endl;
    }
}


// ����� ��� ������ ������ �� �����
void MyString::print() const {
    std::cout << "����� print() ������" << std::endl;
    if (str != nullptr) {
        std::cout << "������: " << str << std::endl;
    }
    else {
        std::cout << "������ �����" << std::endl;
    }
}
