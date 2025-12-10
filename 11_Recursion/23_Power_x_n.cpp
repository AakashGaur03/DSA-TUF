#include <bits/stdc++.h>
using namespace std;

int brutePower(int x, int n) {
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= x;
  }

  return ans;
}
int optimizedRecursivePower(int x, int n, int ans) {
  // Concept behind Pow(x,n)
  if (n == 0) {
    return ans;
  }
  if (n % 2 != 0) {
    ans = ans * x;
    n--;
    return optimizedRecursivePower(x, n, ans);
  } else {
    return optimizedRecursivePower(x * x, n / 2, ans);
  }
}

double optimizedPower(double x, int n) {
  // Concept behind Pow(x,n)
  double ans = 1;
  int m = n;
  n = abs(n);
  while (n != 0) {
    if (n % 2 != 0) {
      ans = ans * x;
      n--;
    } else {
      x = x * x;
      n = n / 2;
    }
  }
  if (m < 0)
    return 1.0 / ans;
  return ans;
}

// Concept is if we have odd power then multiple to ans
// if even sqaure the number and drop power by 2

//   - If n is odd: take one 'x' out and multiply into ans
//        x^n = x * x^(n-1)
//    - If n is even: square x and halve the power
//        x^n = (x*x)^(n/2)

//    This reduces complexity from O(n) → O(log n)

int main() {
  cout << "23 Power (x,n)" << endl;
  int x = 2;
  int n = 21;
  int res1 = brutePower(x, n);
  cout << "Brute Approach: " << res1 << endl;
  int res2 = optimizedRecursivePower(x, n, 1);
  cout << "Optimized Recursive Approach: " << res2 << endl;
  double x2 = 2;
  double res3 = optimizedPower(x2, n);
  cout << "Optimized Approach: " << res3;
  return 0;
}

// Start:
// x = 2, n = 21, ans = 1

// n = 21 (odd)
// → ans = ans * x = 1 * 2 = 2
// → n = 20

// n = 20 (even)
// → x = x * x = 2 * 2 = 4
// → n = 10

// n = 10 (even)
// → x = 4 * 4 = 16
// → n = 5

// n = 5 (odd)
// → ans = ans * x = 2 * 16 = 32
// → n = 4

// n = 4 (even)
// → x = 16 * 16 = 256
// → n = 2

// n = 2 (even)
// → x = 256 * 256 = 65536
// → n = 1

// n = 1 (odd)
// → ans = ans * x = 32 * 65536 = 2097152
// → n = 0

// DONE → final answer = 2097152
