#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

// getPowerAndMod returns the modular of a number z, being the result of 
// x to the power of y
int getPowerAndMod(int x, int y, int z) {
  long long u;
  u = pow(x,y);
  u = u % z;
  return u;
}

// numberise() replaces a string with a series of numbers
int* numberise(string input) {
    char alph[] = "abcdefghijklmnopqrstuvwxyz";
    int n = sizeof(alph)/sizeof(alph[0]);
    int length = input.length() - 1;
    char word[length];
    int* alphabetised = new int[length];

    for (int i=0; i<=length; i++) {
        word[i] = tolower(input[i]);
    }

    for (int i=0; i<=length; i++) {
        auto itr = find(alph, alph + n, word[i]);
        
        if(itr == end(alph)) {
            cout << "Error: You may only use latin characters!";
            break;
        }

        int pos = distance(alph, itr) + 1;
        alphabetised[i] = pos;
    }

    return alphabetised;
}

int* encrypt(int inputArray[], int a, int n, int length) {
    int* hashed = new int[length];

    for (int i=0; i<=length; i++) {
        hashed[i] = getPowerAndMod(inputArray[i], a, n);
    }
    
    return hashed;
}