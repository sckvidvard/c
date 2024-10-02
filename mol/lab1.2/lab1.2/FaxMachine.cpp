#include "FaxMachine.h"

FaxMachine::FaxMachine(string brand, int transmissionSpeed, bool supportsVoicemail)
    : brand(brand), transmissionSpeed(transmissionSpeed), supportsVoicemail(supportsVoicemail) {}

void FaxMachine::sendFax(string number) {
    cout << "Sending fax to " << number << " at " << transmissionSpeed << " kbps." << endl;
}

void FaxMachine::receiveFax() {
    cout << "Receiving fax on fax machine: " << brand << endl;
}

void FaxMachine::checkPaperLevel() {
    cout << "Checking paper level for fax machine: " << brand << endl;
}
