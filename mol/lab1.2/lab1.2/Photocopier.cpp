#include "Photocopier.h"

Photocopier::Photocopier(string brand, int copySpeed, bool duplexCopying)
    : brand(brand), copySpeed(copySpeed), duplexCopying(duplexCopying) {}

void Photocopier::copyDocument(int pages) {
    cout << "Copying " << pages << " pages at " << copySpeed << " pages per minute." << endl;
}

void Photocopier::checkPaperLevel() {
    cout << "Checking paper level for photocopier: " << brand << endl;
}

void Photocopier::replaceToner() {
    cout << "Replacing toner in photocopier: " << brand << endl;
}
