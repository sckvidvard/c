#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
#include "Scanner.h"  // Подключаем заголовочный файл Scanner

using namespace std;

class Printer : public Scanner {  // Наследуем от Scanner
public:
    Printer(string brand, int printSpeed, bool colorPrinting);
    void scanDocument() override;  // Переопределяем метод scanDocument
    void printDocument(int pages);
    void checkInkLevel();
    void replaceCartridge();

private:
    int printSpeed;
    bool colorPrinting;
};

#endif // PRINTER_H
