#include <iostream>
#include <string>    // ← required for string
using namespace std;

class Musicians {
protected:
    string* strInstruments;
    string* windInstruments;
    string* percInstruments;

public:
    Musicians() {
        strInstruments = new string[5];
        windInstruments = new string[5];
        percInstruments = new string[5];
    }

    ~Musicians() {
        delete[] strInstruments;
        delete[] windInstruments;
        delete[] percInstruments;
    }
};
