#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

char alph[] = "abcdefghijklmnopqrstuvwxyz ";
int n = sizeof(alph)/sizeof(alph[0]);

// getPowerAndMod returns the modular of a number z, being the result of x to the power of y
int getPowerAndMod(int x, int y, int z) {
  long long u;
  u = pow(x,y);
  u = u % z;
  return u;
}

// checkIfLatin() checks given input for being only latin letters
bool checkIfLatin(string msg) {
    bool insideArray;
    for(int i= 0; i < msg.length(); i++) {
        bool inside = find(begin(alph), end(alph), msg[i]) != end(alph);
        if (!inside) {
            insideArray = false;
            break;
        } else {
            insideArray = true;
        }
    }
    return insideArray;
}

// checkIfValidInput() checks if the user input is valid, otherwise returns and repeats the input question
string checkIfValidInput() {
    string msg;

    cin.ignore();
    getline(cin,msg);

    bool insideArray = checkIfLatin(msg);
    while (cin.fail() || !checkIfLatin(msg)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\n Your message (latin letters only): ";
        getline(cin,msg);
        //insideArray = checkIfLatin(msg);
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

        int pos = distance(alph, itr) + 1;
        numberised[i] = pos;
    }

    return numberised;
}

// alphabetise() alphabetises a given array of numbers to letters
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

// encrypt() uses getPowerAndMod() to encrypt the given values inside of array using the private Key
int* encrypt(int inputArray[], int a, int n, int length) {
    int* hashed = new int[length];

    for (int i=0; i<=length; i++) {
        hashed[i] = getPowerAndMod(inputArray[i], a, n);
    }

    return hashed;
}

// decrypt() uses getPowerAndMod() to decrypt the given values inside of array using the public Key
int* decrypt(int encrypted[], long long b, int n, int length) {
    int* decrypted = new int[length];

    for (int i=0; i<=length; i++) {
        decrypted[i] = getPowerAndMod(encrypted[i],b,n);
    }

    return decrypted;
}