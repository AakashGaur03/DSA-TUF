#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n) {
  vector<int> arr;

  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      arr.push_back(i);

      if (n / i != i) {
        arr.push_back(n / i);
      }
    }
  }

  sort(arr.begin(), arr.end());

  return arr;
}

// TC: (O(sqrt{n} + dlog d))
// SC: (O(d))
// (d) is the number of divisors of (n)
int main() {
  cout << "2 L2 Print all Divisors of a Number" << endl;

  //   You are given an integer n. You need to find all the divisors of n.
  //   Return all the divisors of n as an array or list in a sorted order.

  // A number which completely divides another number is called it's divisor.

  // Example 1:
  // Input: n = 6

  // Output = [1, 2, 3, 6]

  // Explanation: The divisors of 6 are 1, 2, 3, 6.

  // Example 2:
  // Input: n = 8

  // Output: [1, 2, 4, 8]

  // Explanation: The divisors of 8 are 1, 2, 4, 8.

  int n = 36;

  vector<int> ans = divisors(n);

  for (int num : ans) {
    cout << num << " ";
  }

  cout << endl;

  return 0;
}
