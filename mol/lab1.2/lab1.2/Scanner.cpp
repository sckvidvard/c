#include "Scanner.h"

// Constructor to initialize Scanner object with brand, resolution, and wireless status
Scanner::Scanner(string brand, int resolution, bool wireless)
    : brand(brand), resolution(resolution), wireless(wireless) {}

// Method to simulate scanning a document
void Scanner::scanDocument() {
    cout << "Scanning document at " << resolution << " dpi." << endl;
}

// Method to check the connection status of the scanner
void Scanner::checkConnection() {
    cout << "Checking connection for scanner: " << brand << endl;
}

// Method to calibrate the scanner
void Scanner::calibrateScanner() {
    cout << "Calibrating scanner: " << brand << endl;
}
