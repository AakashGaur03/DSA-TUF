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

bool isSetLeftShift(int n, int i) {
  // TC O(1)
  // SC O(1)

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

bool isSetRightShift(int n, int i) {
  // TC O(1)
  // SC O(1)

  // Is Set using Right Shift operator
  // 13 = 1 1 0 1
  //      3 2 1 0
  // i = 2
  // So we simply do right shift by 2 that index comes at last

  // 1 1 0 1 >> 2

  // 00.. 11

  // Then we do & with 1
  // so if that gives us 1 then set otherwise not set

  // so whatever is there in rest  1 1 1 1 1 1 ..... 0 0 1
  // we are and with 1 so          0 0 0 0 0 0 ..... 0 0 1

  // Everything will be 0 anywasys so if we get result 1 then set othwise not

  return (n >> i) & 1;
}

int setIthBit(int n, int i) {
  // we need to set the ith bit to 1
  // Ex we are given N = 9 and i = 2

  // 1 0 0 1
  //   2nd

  // so result is
  // 1 1 0 1 = 13

  // If i th bit is already 1 then return as it is.

  // Its simple we take a 1 left shift it by ith times
  // then perform an OR operator

  // 0000... 1 0 0 1
  // 1 left rotated by two times is 1 0 0
  // 0000... 0 1 0 0
  // OR THEM

  // 0000... 1 0 0 1
  // 0000... 0 1 0 0
  // 0000... 1 1 0 1

  return n | (1 << i);
}

int clearIthBit(int n, int i) {
  // we need to clear the ith bit to 1
  // Ex we are given N = 3 and i = 2

  // 1 1 0 1
  //   2nd

  // so result is
  // 1 0 0 1 = 9

  // If i th bit is already 0 then return as it is.

  // Its simple we take a 1 left shift it by ith times and do a NOT
  // then perform an AND operator

  // 0000... 1 0 0 1
  // 1 left rotated by two times is 000... 1 0 0
  //   and then NOT is  111... 0 1 1
  // 1111... 1 0 1 1
  // AND THEM

  // 0000... 1 0 0 1
  // 1111... 1 0 1 1
  // 0000... 1 0 0 1

  return n & (~(1 << i));
}

int toggleIthBit(int n, int i) {
  // We do this simply by XOR operator
  // as we know
  // Number of 1's are odd then 1
  // Number of 1's are even then 0

  // SO let N = 13 i = 2
  // 1 1 0 1
  //   ^
  //   |
  // toggle this

  //   result 1 0 0 1

  // SO let N = 9 i = 2
  // 1 0 0 1
  //   ^
  //   |
  // toggle this

  //   result 1 1 0 1

  // so we do left shift of 1 by i then XOR

  // 1 1 0 1   i = 2
  // left shift of 1 by 2
  // 0 1 0 0

  // When we perform XOR
  // Nubmer of 1s are even so it will be 0
  // Nubmer of 1s are odd so it will be 1

  // 1 0 0 1

  return n ^ (1 << i);
}
int main() {
  cout << "2 L2 Must Know Tricks in Bit Manipulation" << endl;

  // Swap two numbers
  // Without Third Variable
  int a = 5;
  int b = 3;
  vector<int> res = swapXor(a, b);
  cout << res[0] << " " << res[1];

  // Check if ith bit is set or not using Left Shift
  int n = 13;
  int i = 0;
  bool res2 = isSetLeftShift(n, i);
  cout << endl;
  cout << res2;

  // Check if ith bit is set or not using Right Shift
  int n2 = 13;
  int i2 = 1;
  bool res3 = isSetRightShift(n2, i2);
  cout << endl;
  cout << res3;

  // Set the ith bit
  int n3 = 9;
  int i3 = 2;
  int res4 = setIthBit(n3, i3);
  cout << endl;
  cout << res4;

  // Clear the ith bit
  int n4 = 13;
  int i4 = 2;
  int res5 = clearIthBit(n4, i4);
  cout << endl;
  cout << res5;

  // Toggling the ith bit
  int n5 = 13;
  int i5 = 2;
  int res6 = toggleIthBit(n5, i5);
  cout << endl;
  cout << res6;

  return 0;
}
