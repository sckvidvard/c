#include "Circle.h"

// Конструктор
Circle::Circle(double x, double y, double radius)
    : x(x), y(y), radius(radius) {
    if (radius < 0) {
        this->radius = 0;  // Убедиться, что радиус не отрицательный
    }
}

// Конструктор копирования
Circle::Circle(const Circle& other)
    : x(other.x), y(other.y), radius(other.radius) {}

// Перегрузка оператора присваивания
Circle& Circle::operator=(const Circle& other) {
    // Проверка на самоприсваивание
    if (this != &other) {
        x = other.x;
        y = other.y;
        radius = other.radius;
    }
    return *this; // Возврат текущего объекта
}

// Деструктор
Circle::~Circle() {}

// Метод для отображения информации об окружности
void Circle::display() const {
    std::cout << "Окружность: Центр(" << x << ", " << y << "), Радиус: " << radius << std::endl;
}

// Несимметрическая разность двух окружностей
Circle Circle::operator-(const Circle& other) const {
    double newRadius = radius - other.radius; // Разность радиусов
    if (newRadius < 0) {
        return Circle(0, 0, 0);  // Вернуть окружность с радиусом ноль, если результат отрицательный
    }
    return Circle(x, y, newRadius);  // Сохранить центр таким же
}

// Унарное отражение окружности
Circle Circle::operator-() const {
    return Circle(-x, -y, radius);  // Отразить окружность относительно начала координат
}
