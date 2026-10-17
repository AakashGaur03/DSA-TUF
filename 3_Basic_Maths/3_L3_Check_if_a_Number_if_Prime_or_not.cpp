#include <bits/stdc++.h>
using namespace std;

bool primeNumber(int num) {
  // prime Number is
  // That has exactly two factors 1 and Itself

  // TC O(n)
  // int cnt = 0;
  // for (int i = 0; i <= num; i++) {
  //   if (num % i == 0) {
  //     cnt++;
  //   }
  // }
  // if (cnt == 2) {
  //   return true;
  // } else
  //   return false;

  // TC O(sqrt n)
  int cnt = 0;
  for (int i = 1; i * i <= num; i++) {
    if (num % i == 0) {
      if (i == num / i) {
        cnt++;
      } else {
        cnt += 2;
      }
    }
  }
  return cnt == 2;
}

// TC: O(sqrt(n))
// SC: O(1)

int main() {
  cout << "3 L3 Check if a Number if Prime or not" << endl;
  // Check for Prime Number
  // You are given an integer n. You need to check if the number is prime or
  // not. Return true if it is a prime number, otherwise return false.

  // A prime number is a number which has no divisors except 1 and itself.

  // Example 1:
  // Input: n = 5

  // Output: true

  // Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

  // Example 2:
  // Input: n = 8

  // Output: false

  // Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime
  // number.

  int num = 5;

  if (primeNumber(num)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
