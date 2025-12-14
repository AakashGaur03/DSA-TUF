#include <bits/stdc++.h>
using namespace std;

vector<int> swapXor(int a, int b) {
  // We will do using XOR Operator
  //   as
  // Number of 1's are odd then 1
  // Number of 1's are even then 0

  //   XOR of same number will be 0
  // and XORing any number with zero is that that Number only

  // we will do

  //   a = a;
  //   b = b;

  // a = a XOR b

  // b= a XOR b = (a^b)^ b
  // which will gives us
  // b = a
  //   now again
  //  a = a ^ b as from above a = a^b and b = a
  //   a = (a ^ b) ^ a = b
  // a = b;
  a = a ^ b;
  b = a ^ b; // ( (a^ b) ^ b) // b = a
  a = a ^ b;
  return {a, b};
}

bool isSet(int n, int i) {
  // N = 13 i = 2
  //     1 1 0 1 we count i from right to left
  // So  3 2 1 0
  // So yes 2nd is 1 that is set

  // N = 13 i = 1
  //     1 1 0 1 we count i from right to left
  // So  3 2 1 0
  // So 2nd is 0 that is not set

  // N = 13 i = 10
  //     00000...    1 1 0 1 we count i from right to left
  // S0 10th           3 2 1 0
  // So 10th is 0 that is not set

  // WE will try using Left Shift Operator
  // So lets we want
  //   n = 13 and i = 2
  //   we do 1 << 2
  //   this gives us 100
  // then we and this with 13
  //   1 1 0 1
  //   0 1 0 0
  //     1
  // We know only that index will be either 1 or 0 rest all will be Zero

  // So if it comes up any number then True else false

  // Like here
  //   1 1 0 1
  //   0 1 0 0
  // AND
  //   0 1 0 0
  //   So we get 4 as result so it was set

  // N = 13 i = 1

  //   1 1 0 1
  //   0 0 1 0
  // AND
  //   0 0 0 0
  // So we get 0 means FALSE

  //   N & (1<< i)!= 0 then true else false

  return (n & (1 << i)) != 0;
}

int main() {
  cout << "2 L2 Must Know Tricks in Bit Manipulation" << endl;

  // Swap two numbers
  // Without Third Variable
  int a = 5;
  int b = 3;
  vector<int> res = swapXor(a, b);
  cout << res[0] << " " << res[1];

  // Check if ith bit is set or not
  int n = 13;
  int i = 0;
  bool res2 = isSet(n, i);
  cout << endl;
  cout << res2;
  return 0;
}
