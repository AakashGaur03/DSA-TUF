#include <bits/stdc++.h>
using namespace std;

// Fibonacci
int fibonacci(int n) {
  if (n <= 1)
    return n;

  int sum = 0;
  int first = 0;
  int second = 1;
  for (int i = 2; i <= n; i++) {
    sum = first + second;
    first = second;
    second = sum;
  }
  return sum;
}

int fibonacciRecursion(int n) {
  // TC O(2^n) approx
  // For each we are calling two functions
  if (n <= 1)
    return n;

  return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
}

int main() {
  cout << "5 Re 5 Multiple Recursion Calls" << endl;
  int res = fibonacci(12);
  cout << res;
  cout << endl;
  int res2 = fibonacciRecursion(12);
  cout << res2;
  return 0;
}