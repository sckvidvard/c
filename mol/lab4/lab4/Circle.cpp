#include "Circle.h"

// �����������
Circle::Circle(double x, double y, double radius)
    : x(x), y(y), radius(radius) {
    if (radius < 0) {
        this->radius = 0;  // ���������, ��� ������ �� �������������
    }
}

// ����������� �����������
Circle::Circle(const Circle& other)
    : x(other.x), y(other.y), radius(other.radius) {}

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
Circle::~Circle() {}

// ����� ��� ����������� ���������� �� ����������
void Circle::display() const {
    std::cout << "����������: �����(" << x << ", " << y << "), ������: " << radius << std::endl;
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
