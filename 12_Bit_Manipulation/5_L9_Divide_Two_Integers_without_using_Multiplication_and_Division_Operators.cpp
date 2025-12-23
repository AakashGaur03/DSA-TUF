#include <bits/stdc++.h>
using namespace std;

int bruteDivideTwoNumbers(int dividend, int divisor) {
  // TC O(Dividend) in cases where divisor is 1
  // SC O(1)
  int val = 0;
  int cnt = 0;

  while (val <= dividend) {
    cnt += 1;
    val += divisor;
  }
  // We are returing cnt-1 because we add till it is equal so thats why
  // also if we want to do return cnt we need to update while condition to
  // while (val <= dividend-divisor)

  return cnt - 1;
}

int optimalDivideTwoNumbers(int dividend, int divisor) {

  // TC: O(log(dividend))
  // SC: O(1)

  if (dividend == divisor) {
    return 1;
  }
  if (divisor == 0)
    return INT_MAX;

  bool sign = true;
  if (dividend >= 0 && divisor < 0)
    sign = false;
  else if (dividend <= 0 && divisor > 0)
    sign = false;

  long n = abs(dividend);
  long d = abs(divisor);
  long quotient = 0;
  while (n >= d) {
    int cnt = 0;
    while (n >= (d << (cnt + 1))) { // d*2^(cnt+1)
      // Find the largest power such that (d << cnt) <= n
      cnt += 1;
    }
    quotient += 1 << cnt; // Add 2^cnt to quotient
    n -= (d << cnt);      // Subtract d * 2^cnt
  }
  if (quotient > INT_MAX)
    return sign ? INT_MAX : INT_MIN;

  return sign ? quotient : -quotient;
}

int main() {
  cout << "5 L9 Divide Two Integers without using Multiplication and Division "
          "Operators"
       << endl;
  // we will be given Divided and Divisor we need to divide them
  // without using Division or Multiplication
  int dividend = 22;
  int divisor = 3;
  int res = bruteDivideTwoNumbers(dividend, divisor);
  cout << res;
  int res2 = optimalDivideTwoNumbers(dividend, divisor);
  cout << res2;
  return 0;
}
