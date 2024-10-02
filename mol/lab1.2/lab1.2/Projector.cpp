#include "Projector.h"

Projector::Projector(string brand, int brightness, bool supportsHD)
    : brand(brand), brightness(brightness), supportsHD(supportsHD) {}

void Projector::startPresentation() {
    cout << "Starting presentation on projector: " << brand << endl;
}

void Projector::adjustBrightness(int newBrightness) {
    brightness = newBrightness;
    cout << "Adjusting brightness to " << brightness << " lumens." << endl;
}

void Projector::checkLampStatus() {
    cout << "Checking lamp status for projector: " << brand << endl;
}
