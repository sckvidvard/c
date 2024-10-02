#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

class Circle {
public:
    Circle(double x, double y, double radius);
    Circle(const Circle& other);  // Конструктор копирования
    Circle& operator=(const Circle& other); // Перегрузка оператора присваивания
    ~Circle();  // Деструктор

    void display() const;  // Метод для отображения информации об окружности

    Circle operator-(const Circle& other) const;  // Несимметрическая разность
    Circle operator-() const;  // Унарное отражение

    static int getCount(); // Статический метод для получения значения счетчика

private:
    double x;      // x-координата центра
    double y;      // y-координата центра
    double radius; // Радиус окружности
    static int count; // Статический член-данные для подсчета объектов
    const int id;   // Константное поле для идентификатора объекта
};

#endif // CIRCLE_H
