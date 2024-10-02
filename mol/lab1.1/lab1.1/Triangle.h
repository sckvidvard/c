#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <iostream>
using namespace std;

class Triangle {
public:
    Triangle(double hypotenuse, double angle);

    bool setSides(double hypotenuse, double angle);
    void increaseSide(double percent);
    void decreaseSide(double percent);
    double calculateInradius() const;
    double distanceBetweenInradiusAndCircumradius() const;
    double calculateSquareRootOfArea() const;
    void print() const;

private:
    double hypotenuse;
    double angle; // angle in degrees
    double side_a;
    double side_b;

    void updateSides();
    double toRadians(double degrees) const;
    double calculateCircumradius() const;
    double calculateArea() const;
};

#endif // TRIANGLE_H
