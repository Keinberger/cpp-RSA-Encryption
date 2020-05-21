#include <iostream>
#include <math.h>
#include <time.h>
#include <typeinfo>
#include "math/calculation.cpp"
using namespace std;

// main function of program
// executes the commands
int main() {

  srand((unsigned int)time(NULL));
  int p, q, x, n, m, a, y, z;
  long long b;
  string ans;

  // welcome message and explanation of rsa
  system("clear"); // Only works with unix systems
  cout << "Welcome to © Philipp's great RSA Encryption \n\n";
  cout << "Let's start with a question: \n";
  cout << "Do you care about knowing the variables? \n";
  cout << "If you do, type 'y', otherwise type 'n' and press enter. \n";
  cin >> ans;
  system("clear"); // Only works with unix systems

  // the do-while is just a measure, to ensure that b 
  // is not greater than or equal to 11
  // The decryption would not be able to work otherwise, 
  // bc it would exceed the long long int boundaries (Overflow Error)
  do {
  // generating p and q
  p = generatePrime();
  q = generatePrime();
  q = checkIfSame(p,q);

  // claculating n and m
  n = p*q;
  m = (p-1)*(q-1);

  // generating a, being coprime to m
  do {
    a = generatePrime();
  }
  while (m % a == 0);
  
  }
  while(getModInverse(a,m) >= 11);

  // Outputting p, q, n, m, a if user wants to
  if (ans == "y") {
    cout << "\np is: " << p << endl;
    cout << "q is: " << q << endl;
    cout << "n is: " << n << endl;
    cout << "m is: " << m << endl;
    cout << "a is: " << a << endl;
  }

  // asking the user for a message to encrypt
  // user may only choose messages in formate of numbers less than n
  cout << "\n Your message (<" << n << "): ";
  x = checkIfNumber(n);

  // ecnrypting the message
  y = getPowerAndMod(x,a,n);
  cout << "\n Encrypted message: '" << y << "' \n";

  // decrypting the message
  b = getModInverse(a,m);
  z = getPowerAndMod(y,b,n);
  cout << "\n Decrypted message: '" << z << "'\n\n";

}