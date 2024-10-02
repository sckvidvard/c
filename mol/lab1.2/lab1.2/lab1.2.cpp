#include <iostream>
#include "Printer.h"
#include "Scanner.h"
#include "Photocopier.h"
#include "FaxMachine.h"
#include "Projector.h"

using namespace std;

int main() {
    // Создание 7 объектов каждого класса офисного оборудования
    Printer printers[7] = {
        Printer("HP", 20, true),
        Printer("Canon", 15, false),
        Printer("Epson", 25, true),
        Printer("Brother", 18, true),
        Printer("Xerox", 30, false),
        Printer("Lexmark", 22, true),
        Printer("Ricoh", 24, false)
    };

    Scanner scanners[7] = {
        Scanner("Canon", 300, false),
        Scanner("Epson", 600, true),
        Scanner("HP", 150, false),
        Scanner("Brother", 1200, true),
        Scanner("Xerox", 600, false),
        Scanner("Lexmark", 300, true),
        Scanner("Ricoh", 1200, false)
    };

    Photocopier photocopiers[7] = {
        Photocopier("Xerox", 15, true),
        Photocopier("Canon", 10, false),
        Photocopier("HP", 12, true),
        Photocopier("Ricoh", 20, false),
        Photocopier("Brother", 25, true),
        Photocopier("Lexmark", 18, false),
        Photocopier("Epson", 16, true)
    };

    FaxMachine faxMachines[7] = {
        FaxMachine("Brother", 14, true),
        FaxMachine("Canon", 12, false),
        FaxMachine("HP", 10, true),
        FaxMachine("Xerox", 15, true),
        FaxMachine("Ricoh", 20, false),
        FaxMachine("Lexmark", 18, true),
        FaxMachine("Epson", 16, false)
    };

    Projector projectors[7] = {
        Projector("Epson", 3000, true),
        Projector("Benq", 3500, false),
        Projector("Canon", 4000, true),
        Projector("Sony", 4500, true),
        Projector("Acer", 3200, false),
        Projector("Dell", 2900, true),
        Projector("ViewSonic", 3100, false)
    };

    // Вызов всех трех методов для одного объекта каждого класса
    printers[0].printDocument(5);
    printers[0].checkInkLevel();
    printers[0].replaceCartridge();

    scanners[0].scanDocument();
    scanners[0].checkConnection();
    scanners[0].calibrateScanner();

    photocopiers[0].copyDocument(10);
    photocopiers[0].checkPaperLevel();
    photocopiers[0].replaceToner();

    faxMachines[0].sendFax("123-456-7890");
    faxMachines[0].receiveFax();
    faxMachines[0].checkPaperLevel();

    projectors[0].startPresentation();
    projectors[0].adjustBrightness(2500);
    projectors[0].checkLampStatus();

    return 0;
}
