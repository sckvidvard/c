#include "Triangle.h"
#include <cmath>  // ��� ������� cos, sin, sqrt � ����������� ����� PI
#include <iostream>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846  // ����������� PI, ���� ��� �� ����������
#endif

Triangle::Triangle(double hypotenuse, double angle) : hypotenuse(hypotenuse), angle(angle) {
    if (!setSides(hypotenuse, angle)) {
        cerr << "������: �������� ��������� ���������." << endl;
    }
}

bool Triangle::setSides(double hypotenuse, double angle) {
    if (hypotenuse <= 0 || angle <= 0 || angle >= 90) {
        cout << "������: ������������ �������� ���������� ��� ����." << endl;
        return false;
    }

    this->hypotenuse = hypotenuse;
    this->angle = angle;
    updateSides();
    return true;
}

void Triangle::updateSides() {
    double angleRad = toRadians(angle);
    side_a = hypotenuse * cos(angleRad);
    side_b = hypotenuse * sin(angleRad);
}

double Triangle::toRadians(double degrees) const {
    return degrees * M_PI / 180.0;
}

double Triangle::calculateInradius() const {
    return (side_a + side_b - hypotenuse) / 2.0;
}

double Triangle::calculateCircumradius() const {
    return hypotenuse / 2.0;
}

double Triangle::distanceBetweenInradiusAndCircumradius() const {
    return fabs(calculateCircumradius() - calculateInradius());
}

double Triangle::calculateArea() const {
    return 0.5 * side_a * side_b;
}

double Triangle::calculateSquareRootOfArea() const {
    return sqrt(calculateArea());
}

void Triangle::increaseSide(double percent) {
    side_a *= (1 + percent / 100);
    side_b *= (1 + percent / 100);
    hypotenuse = sqrt(side_a * side_a + side_b * side_b);
}

void Triangle::decreaseSide(double percent) {
    side_a *= (1 - percent / 100);
    side_b *= (1 - percent / 100);
    hypotenuse = sqrt(side_a * side_a + side_b * side_b);
}

void Triangle::print() const {
    cout << "����������: " << hypotenuse << endl;
    cout << "����: " << angle << endl;
    cout << "����� A: " << side_a << endl;
    cout << "����� B: " << side_b << endl;
}
