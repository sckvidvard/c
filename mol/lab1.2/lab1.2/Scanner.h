#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <string>

using namespace std;

class Scanner {
public:
    Scanner(string brand, int resolution, bool wireless);
    virtual void scanDocument();
    void checkConnection();
    void calibrateScanner();

    string getBrand() const { return brand; }  // Геттер для brand

private:
    string brand;
    int resolution;
    bool wireless;
};

#endif // SCANNER_H
