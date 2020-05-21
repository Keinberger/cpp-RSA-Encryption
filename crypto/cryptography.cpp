#include <iostream>
#include <math.h>
#include <regex>
#include "../math/calculation.cpp"
using namespace std;

// numberise() replaces a string with a series of numbers
int* numberise(string input) {
    char alph[] = "abcdefghijklmnopqrstuvwxyz";
    int n = sizeof(alph)/sizeof(alph[0]);
    int length = input.length() - 1;
    char word[length];
    int alphabetised[length];

    for (int i=0; i<=length; i++) {
        word[i] = tolower(input[i]);
    }

    for (int i=0; i<=length; i++) {
        auto itr = find(alph, alph + n, word[i]);
        
        if(itr == end(alph)) {
            cout << "Error: You may only use latin characters!";
            break;
        }

        int pos = distance(alph, itr);
        cout << i << ": " << pos << endl;
        alphabetised[i] = pos;
    }

    return alphabetised;
}