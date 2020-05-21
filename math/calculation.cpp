#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

// hcF (highest common factor) calculates and returns the 
// highest common factor of two numbers
unsigned int hcF(unsigned int x, unsigned int y ) {
  if (y == 0) {
    return x;
  }
  else 
  {
    return hcF(y, x % y);
  }
}

// getModInverse calculates the modular inverse of two numbers
int getModInverse(int a, int m) {
  a = a % m;
  for (int x = 1; x < m; x++) {
    if ((a * x) % m == 1) {
      return x;
    }
  }
  return 0;
}

// generatePrime creates a primer number less than 14
int generatePrime() {
  int x;
  do {
    x = rand() % 14+0;
  }
  while (hcF(x, 4) != 1 || hcF(x, 6) != 1 || x == 1);
  return x;
}

// checkIfSame checks if two numbers are equal and returns a new number y, 
// not being equal to x
int checkIfSame(int x, int y) {
  int u = y;
  while(u == x) {
      u = generatePrime();
  }
  return u;
}