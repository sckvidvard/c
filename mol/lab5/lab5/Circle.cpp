#include "Circle.h"

// ������������� ������������ ���� count
int Circle::count = 0;

// �����������
Circle::Circle(double x, double y, double radius)
    : x(x), y(y), radius(radius), id(++count) { // ����������� ������� � ����������� �������������
    if (radius < 0) {
        this->radius = 0;  // ���������, ��� ������ �� �������������
    }
}

// ����������� �����������
Circle::Circle(const Circle& other)
    : x(other.x), y(other.y), radius(other.radius), id(other.id) {}

// ���������� ��������� ������������
Circle& Circle::operator=(const Circle& other) {
    // �������� �� ����������������
    if (this != &other) {
        x = other.x;
        y = other.y;
        radius = other.radius;
    }
    return *this; // ������� �������� �������
}

// ����������
Circle::~Circle() {
    --count; // ��������� ������� ��� ����������� �������
}

// ����� ��� ����������� ���������� �� ����������
void Circle::display() const {
    std::cout << "���������� (ID: " << id << "): �����(" << x << ", " << y << "), ������: " << radius << std::endl;
}

// ���������������� �������� ���� �����������
Circle Circle::operator-(const Circle& other) const {
    double newRadius = radius - other.radius; // �������� ��������
    if (newRadius < 0) {
        return Circle(0, 0, 0);  // ������� ���������� � �������� ����, ���� ��������� �������������
    }
    return Circle(x, y, newRadius);  // ��������� ����� ����� ��
}

// ������� ��������� ����������
Circle Circle::operator-() const {
    return Circle(-x, -y, radius);  // �������� ���������� ������������ ������ ���������
}

// ����������� ����� ��� ��������� �������� ��������
int Circle::getCount() {
    return count; // ���������� ������� �������� ��������
}
