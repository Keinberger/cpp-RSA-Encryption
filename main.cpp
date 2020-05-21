#include <iostream>
#include <math.h>
#include <time.h>
#include <typeinfo>
#include <cstdlib>
#include "math/calculation.cpp"
#include "crypto/cryptography.cpp"
#include "others/others.cpp"
using namespace std;

// main function of program
// executes the commands
int main() {

  srand((unsigned int)time(NULL));
  int p, q, n, m, a, len;
  int* x; 
  int* y; 
  int* z;
  long long b;
  string ans, msg, result;

  clearWindow();

  // welcome message and explanation of rsa
  cout << "Welcome to the RSA Encryption \n\n";
  cout << "Let's start with a question: \n";
  cout << "Do you want to know the variables? \n";
  cout << "If you do, type 'y', otherwise type 'n' and press enter. \n";
  cin >> ans;
  clearWindow();

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
    cout << "\np (private key) is: " << p << endl;
    cout << "q (public key) is: " << q << endl;
    cout << "n is: " << n << endl;
    cout << "m is: " << m << endl;
    cout << "a is: " << a << endl;
  }

  // asking the user for a message to encrypt
  // user may only choose messages in formate of numbers less than n
  cout << "\n Your message (latin letters only): ";
  msg = checkIfValidInput();
  len = msg.length() - 1;

  // numberising message
  // this is necessary, otherwise
  x = numberise(msg);

  // encrypting the message
  y = encrypt(x,a,n,len);

  // outputting the actual encrypted numbers
  if(ans == "y") {
      cout << endl << " Encrypted message: '";
      for (int i = 0; i<=len; i++) {
        cout << y[i];
      }
      cout << "'" << endl;
  } 
  else // outputting the encrypted message (only array)
  {
      cout << endl << " Encrypted message: '" << y << "'";
  }

  // decrypting the message
  b = getModInverse(a,m);
  z = decrypt(y,b,n,len);
  result = alphabetise(z,len+1);

  // outputtings the decrypted message
  cout << endl << " Decrypted message: '" << result << "'" << endl << endl;
}