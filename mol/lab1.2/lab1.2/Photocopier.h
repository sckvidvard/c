#ifndef PHOTOCOPIER_H
#define PHOTOCOPIER_H

#include <iostream>
#include <string>

using namespace std;

class Photocopier {
public:
    Photocopier(string brand, int copySpeed, bool duplexCopying);
    void copyDocument(int pages);
    void checkPaperLevel();
    void replaceToner();

private:
    string brand;
    int copySpeed;
    bool duplexCopying;
};

#endif // PHOTOCOPIER_H
