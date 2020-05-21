#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

char alph[] = "abcdefghijklmnopqrstuvwxyz";
int n = sizeof(alph)/sizeof(alph[0]);

// getPowerAndMod returns the modular of a number z, being the result of 
// x to the power of y
int getPowerAndMod(int x, int y, int z) {
  long long u;
  u = pow(x,y);
  u = u % z;
  return u;
}

string checkIfValidInput() {
    string msg;
    bool insideArray = true;
    int len = msg.length();

    cin >> msg;
    for(int i= 0; i < msg.length(); i++) {
        bool inside = find(begin(alph), end(alph), msg[i]) != end(alph);
        if (!inside) {
            insideArray = false;
            break;
        } else {
            insideArray = true;
        }
    }
    while (cin.fail() || !insideArray) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\n Your message (latin letters only): ";
        cin >> msg;
    }
    return msg;
}

// numberise() replaces a string with a series of numbers
int* numberise(string input) {
    int length = input.length() - 1;
    char word[length];
    int* numberised = new int[length];

    for (int i=0; i<=length; i++) {
        word[i] = tolower(input[i]);
    }

    for (int i=0; i<=length; i++) {
        auto itr = find(alph, alph + n, word[i]);
        
        if(itr == end(alph)) {
            cout << "Error: You may use latin characters only!";
            break;
        }

        int pos = distance(alph, itr) + 1;
        numberised[i] = pos;
    }

    return numberised;
}

string alphabetise(int inputNumbers[], int length) {
    char word[length];
    string result;
    
    for (int i=0; i<=length; i++) {
        word[i] = alph[inputNumbers[i] - 1];
    }

    for (int i=0; i<=length; i++) {
        result += word[i];
    }

    return result;
}

int* encrypt(int inputArray[], int a, int n, int length) {
    int* hashed = new int[length];

    for (int i=0; i<=length; i++) {
        hashed[i] = getPowerAndMod(inputArray[i], a, n);
    }

    return hashed;
}

int* decrypt(int encrypted[], long long b, int n, int length) {
    int* decrypted = new int[length];

    for (int i=0; i<=length; i++) {
        decrypted[i] = getPowerAndMod(encrypted[i],b,n);
    }

    return decrypted;
}