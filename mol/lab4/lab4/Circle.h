#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

class Circle {
public:
    Circle(double x, double y, double radius);
    Circle(const Circle& other);  // ����������� �����������
    Circle& operator=(const Circle& other); // ���������� ��������� ������������
    ~Circle();  // ����������

    void display() const;  // ����� ��� ����������� ���������� �� ����������

    Circle operator-(const Circle& other) const;  // ���������������� ��������
    Circle operator-() const;  // ������� ���������

private:
    double x;      // x-���������� ������
    double y;      // y-���������� ������
    double radius; // ������ ����������
};

#endif // CIRCLE_H
