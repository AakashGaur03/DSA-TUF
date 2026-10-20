#include <bits/stdc++.h>
using namespace std;

// Brute Force is simply Iterate till N Check each Number is Prime if Yes then
// add to answer

vector<int> sieve(int n) {
  // TC: O(n * log(log(n)))
  // SC: O(n)

  vector<int> primeArr(n + 1, 1);
  for (int i = 2; i * i <= n; i++) {
    if (primeArr[i] == 1) {
      for (int j = i * i; j <= n; j += i) {
        primeArr[j] = 0;
      }
    }
  }

  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    if (primeArr[i] == 1) {
      ans.push_back(i);
    }
  }
  return ans;
}

int main() {
  cout << "6 L6 Sieve of Eratosthenes" << endl;

  // Given a number n, find all prime numbers less than or equal to n.
  // Examples:

  // Input: n = 10
  // Output: [2, 3, 5, 7]
  // Explanation: The prime numbers up to 10 obtained by Sieve of Eratosthenes
  // are [2, 3, 5, 7].

  // Input: n = 35
  // Output: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
  // Explanation: The prime numbers up to 35 obtained by Sieve of Eratosthenes
  // are [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31].

  int n = 35;

  vector<int> ans = sieve(n);

  cout << "[";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i < ans.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
  return 0;
}