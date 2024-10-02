#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <iostream>
#include <string>

using namespace std;

class Projector {
public:
    Projector(string brand, int brightness, bool supportsHD);
    void startPresentation();
    void adjustBrightness(int newBrightness);
    void checkLampStatus();

private:
    string brand;
    int brightness;
    bool supportsHD;
};

#endif // PROJECTOR_H
