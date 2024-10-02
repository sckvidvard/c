#include <iostream>
#include <vector>
#include "Triangle.h"

using namespace std;

void printMenu() {
    cout << "\nВыберите операцию:" << endl;
    cout << "1. Увеличить размер стороны" << endl;
    cout << "2. Уменьшить размер стороны" << endl;
    cout << "3. Вычислить радиус вписанной окружности" << endl;
    cout << "4. Определить расстояние между центрами вписанной и описанной окружностей" << endl;
    cout << "5. Вычислить квадратный корень из площади" << endl;
    cout << "0. Выход" << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<Triangle> triangles;
    int numTriangles;
    cout << "Введите количество треугольников: ";
    cin >> numTriangles;

    while (cin.fail() || numTriangles <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: введите положительное число." << endl;
        cout << "Введите количество треугольников: ";
        cin >> numTriangles;
    }

    for (int i = 0; i < numTriangles; ++i) {
        double hypotenuse, angle;
        cout << "\nВведите параметры треугольника " << (i + 1) << ":\n";
        cout << "Гипотенуза: ";
        cin >> hypotenuse;

        while (cin.fail() || hypotenuse <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите положительное число для гипотенузы." << endl;
            cout << "Гипотенуза: ";
            cin >> hypotenuse;
        }

        cout << "Угол (в градусах): ";
        cin >> angle;

        while (cin.fail() || angle <= 0 || angle >= 90) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите угол в диапазоне от 0 до 90 градусов, исключая 90." << endl;
            cout << "Угол (в градусах): ";
            cin >> angle;
        }

        Triangle triangle(hypotenuse, angle);
        triangles.push_back(triangle);
    }

    int choice;
    while (true) {
        cout << "\nСписок введенных треугольников:" << endl;
        for (int i = 0; i < triangles.size(); ++i) {
            cout << "\nТреугольник " << (i + 1) << ":" << endl;
            triangles[i].print();
        }

        cout << "\nВыберите номер треугольника для выполнения операции (или 0 для выхода): ";
        int index;
        cin >> index;

        while (cin.fail() || index < 0 || index > triangles.size()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите корректный номер треугольника." << endl;
            cout << "Выберите номер треугольника для выполнения операции (или 0 для выхода): ";
            cin >> index;
        }

        if (index == 0) break;

        Triangle& selectedTriangle = triangles[index - 1];
        printMenu();
        cout << "Выберите операцию: ";
        cin >> choice;

        while (cin.fail() || choice < 0 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите корректный номер операции." << endl;
            printMenu();
            cout << "Выберите операцию: ";
            cin >> choice;
        }

        switch (choice) {
        case 1: {
            double percent;
            cout << "Введите процент увеличения: ";
            cin >> percent;

            while (cin.fail() || percent < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка: введите положительный процент." << endl;
                cout << "Введите процент увеличения: ";
                cin >> percent;
            }

            selectedTriangle.increaseSide(percent);
            break;
        }
        case 2: {
            double percent;
            cout << "Введите процент уменьшения: ";
            cin >> percent;

            while (cin.fail() || percent < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка: введите положительный процент." << endl;
                cout << "Введите процент уменьшения: ";
                cin >> percent;
            }

            selectedTriangle.decreaseSide(percent);
            break;
        }
        case 3:
            cout << "Радиус вписанной окружности: " << selectedTriangle.calculateInradius() << endl;
            break;
        case 4:
            cout << "Расстояние между центрами вписанной и описанной окружностей: "
                << selectedTriangle.distanceBetweenInradiusAndCircumradius() << endl;
            break;
        case 5:
            cout << "Квадратный корень из площади: " << selectedTriangle.calculateSquareRootOfArea() << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
            break;
        }

        cout << "\nТреугольник с обновленными параметрами:" << endl;
        selectedTriangle.print();
    }

    return 0;
}
