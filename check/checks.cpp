#include <iostream>
#include <ctype.h>
using namespace std;

string checkIfValidInput() {
    string msg;
    cin >> msg;
        while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\n Your message (latin letters only): ";
        cin >> msg;
        }
    return msg;
}