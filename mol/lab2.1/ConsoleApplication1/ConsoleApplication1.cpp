#include <iostream>
#include <string> // Для работы с std::string

using namespace std;

// Определение класса Worker
class Worker {
public:
    int age;
    string name; // Изменение на std::string для корректной работы со строками

    // Конструктор
    Worker() {
        age = 0;
        weight = 0.0;
        mood = 10; // Настроение по умолчанию
    }
    void setName(const string& workerName) {
        name = workerName;
    }

    // Метод для увеличения веса после еды
    void eat(float how_much);

    // Метод для получения текущего веса
    float get_weight();

    // Методы для изменения настроения
    void walk();
    void dance();
    void work();

    // Метод для получения текущего настроения
    int get_mood();

private:
    float weight;
    int mood; // Скрытое поле настроение
};

// Реализация метода eat
void Worker::eat(float how_much) {
    if (how_much > 10) {
        age++; // Увеличиваем возраст, если за раз съедает более 10 кг
        weight += how_much / 2; // Увеличиваем вес на половину
    }
    else {
        weight += how_much;
    }
}

// Реализация метода get_weight
float Worker::get_weight() {
    return weight;
}

// Реализация метода walk
void Worker::walk() {
    mood += 1; // Гулять увеличивает настроение на 1
}

// Реализация метода dance
void Worker::dance() {
    mood += 2; // Танцевать увеличивает настроение на 2
}

// Реализация метода work
void Worker::work() {
    if (mood > 0) {
        mood -= 2; // Работать уменьшает настроение на 2
        if (mood < 0) mood = 0; // Настроение не может быть меньше 0
    }
}

// Реализация метода get_mood
int Worker::get_mood() {
    return mood;
}

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");
    // Создание объекта класса Worker
    Worker* wrk1 = new Worker();

    // Ввод имени и возраста с клавиатуры
    cout << "Введите имя рабочего: ";
    string nw;
    cin >> nw; // Вводим имя с использованием std::string
    wrk1->setName(nw);

    cout << "Введите возраст рабочего: ";
    cin >> wrk1->age;

    // Демонстрация записи данных
    cout << "Рабочий создан. Имя: " << wrk1->name << ", возраст: " << wrk1->age << endl;

    // Рабочий съедает 2 и 3 кг еды
    wrk1->eat(2);
    wrk1->eat(3);

    // Получение текущего веса
    float ves = wrk1->get_weight();
    cout << "Вес рабочего после еды: " << ves << " кг" << endl;

    // Рабочий съедает 15 кг еды
    wrk1->eat(15);
    ves = wrk1->get_weight();
    cout << "Вес рабочего после того, как он съел 15 кг: " << ves << " кг" << endl;
    cout << "Возраст рабочего после большой порции: " << wrk1->age << " лет" << endl;

    // Рабочий дважды гуляет и трижды танцует
    wrk1->walk();
    wrk1->walk();
    wrk1->dance();
    wrk1->dance();
    wrk1->dance();

    // Вывод текущего настроения
    int mood = wrk1->get_mood();
    cout << "Настроение рабочего после прогулок и танцев: " << mood << endl;

    // Рабочий работает 9 раз
    for (int i = 0; i < 9; i++) {
        wrk1->work();
    }

    // Вывод настроения после работы
    mood = wrk1->get_mood();
    cout << "Настроение рабочего после работы: " << mood << endl;

    // Освобождение памяти
    delete wrk1;

    return 0;
}
