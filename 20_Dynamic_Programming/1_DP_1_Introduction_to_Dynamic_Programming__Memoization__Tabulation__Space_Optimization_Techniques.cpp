#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
  // TC O(2^N)
  // SC O(2N)

  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// DP
int fibonacciMemoization(int n, vector<int> &dpArr) {
  // TC O(N)
  // SC O(2N)
  if (n <= 1) {
    return n;
  }
  if (dpArr[n] != -1) {
    return dpArr[n];
  }
  dpArr[n] =
      fibonacciMemoization(n - 1, dpArr) + fibonacciMemoization(n - 2, dpArr);

  return dpArr[n];
}

int main() {
  cout << "1 DP 1 Introduction to Dynamic Programming | Memoization | "
          "Tabulation | Space Optimization Techniques"
       << endl;

  // Those who cannot remember the past condemned to repeat it

  // Ways to Solve DP
  // Tabulation // Bottom Up
  // Memoization // Top - Dowm

  // Lets Take an example of Fibonacci Number
  // 0 1 1 2 3 5 8 13 21 ....
  // we need f(5) this is 5 for 0 based indexing
  //
  //                     fib(5)
  //                    /      \
  //               fib(4)      fib(3)
  //              /     \    
  //         fib(3)   fib(2)
  //         /   \    
  //    fib(2) fib(1)
  //     / \
  // fib(1) fib(0)

  // Here fib(2) under fib(4) and fib(3) under fib(5) represents
  // Overlapping Sub Problems
  // This is where Memoization comes in
  // we tend to store values of sub problems in some map/table

  int n = 5;
  vector<int> dpArr(n + 1, -1);
  cout << fibonacciMemoization(n, dpArr);
  return 0;
}
