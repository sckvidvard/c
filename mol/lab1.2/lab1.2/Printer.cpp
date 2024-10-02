#include "Printer.h"

Printer::Printer(string brand, int printSpeed, bool colorPrinting)
    : Scanner(brand, 300, false), printSpeed(printSpeed), colorPrinting(colorPrinting) {}

void Printer::scanDocument() {
    cout << "Printing document instead of scanning at " << printSpeed << " pages per minute." << endl;
}

void Printer::printDocument(int pages) {
    cout << "Printing " << pages << " pages at " << printSpeed << " pages per minute." << endl;
}

void Printer::checkInkLevel() {
    cout << "Checking ink level for printer: " << getBrand() << endl;  // Using the getter
}

void Printer::replaceCartridge() {
    cout << "Replacing cartridge in printer: " << getBrand() << endl;  // Using the getter
}
