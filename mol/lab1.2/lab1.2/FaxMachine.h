#ifndef FAXMACHINE_H
#define FAXMACHINE_H

#include <iostream>
#include <string>

using namespace std;

class FaxMachine {
public:
    FaxMachine(string brand, int transmissionSpeed, bool supportsVoicemail);
    void sendFax(string number);
    void receiveFax();
    void checkPaperLevel();

private:
    string brand;
    int transmissionSpeed;
    bool supportsVoicemail;
};

#endif // FAXMACHINE_H
