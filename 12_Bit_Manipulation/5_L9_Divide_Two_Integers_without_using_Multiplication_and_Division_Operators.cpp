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

int main() {
  cout << "5 L9 Divide Two Integers without using Multiplication and Division "
          "Operators"
       << endl;
  // we will be given Divided and Divisor we need to divide them
  // without using Division or Multiplication
  int dividend = 22;
  int dividor = 3;
  int res = bruteDivideTwoNumbers(dividend, dividor);
  cout << res;
  return 0;
}
