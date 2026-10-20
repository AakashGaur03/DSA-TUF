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
  if (num <= 1)
    return false;
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

vector<int> primesInRange(vector<vector<int>> &queries) {
  // Brute Force
  // TC: O(q * (R - L + 1) * sqrt(R))
  // Auxiliary SC: O(1), excluding output
  // Output SC: O(q)

  int q = queries.size();
  vector<int> ans;
  for (int i = 0; i < q; i++) {
    int l = queries[i][0];
    int r = queries[i][1];
    int cnt = 0;
    for (int j = l; j <= r; j++) {
      if (primeNumber(j)) {
        cnt++;
      }
    }
    ans.push_back(cnt);
  }
  return ans;
}

vector<int> sieve(int n) {
  // TC: O(n * log(log(n)))
  // SC: O(n)

  vector<int> primeArr(n + 1, 1);
  primeArr[0] = primeArr[1] = 0;

  for (int i = 2; i * i <= n; i++) {
    if (primeArr[i] == 1) {
      for (int j = i * i; j <= n; j += i) {
        primeArr[j] = 0;
      }
    }
  }

  return primeArr;
}

vector<int> primesInRangeBetterApporach(vector<vector<int>> &queries) {
  // TC: O(N * log(log(N)) + q * W)
  // Auxiliary SC: O(N)
  // Output SC: O(q)

  int q = queries.size();
  vector<int> primeArr = sieve(1e5);
  vector<int> ans;
  for (int i = 0; i < q; i++) {
    int l = queries[i][0];
    int r = queries[i][1];
    int cnt = 0;
    for (int j = l; j <= r; j++) {
      if (primeArr[j] == 1) {
        cnt++;
      }
    }
    ans.push_back(cnt);
  }
  return ans;
}

int main() {
  cout << "7 L7 Count Prime in a range L R" << endl;

  // Count primes in range L to R
  // You are given an 2D array queries of dimension n*2.

  // The queries[i] represents a range from queries[i][0] to queries[i][1]
  // (include the end points).

  // Return the count of prime numbers present in between each range in queries
  // array.

  // Example 1:
  // Input : queries = [ [2, 5], [4, 7] ]

  // Output : [3, 2]

  // Explanation : The range 2 to 5 contains three prime numbers 2, 3, 5.

  // The range 4 to 7 contains two prime numbers 5, 7.

  // Example 2:
  // Input : queries = [ [1, 7], [3, 7] ]

  // Output : [4, 3]

  // Explanation : The range 1 to 7 contains four prime numbers 2, 3, 5, 7.

  // The range 3 to 7 contains three prime numbers 3, 5, 7.

  vector<vector<int>> queries = {{2, 5}, {4, 7}, {1, 7}, {3, 7}};

  vector<int> bruteForceAns = primesInRange(queries);
  vector<int> betterAns = primesInRangeBetterApporach(queries);

  cout << "Brute Force: ";
  for (int num : bruteForceAns) {
    cout << num << " ";
  }

  cout << endl;

  cout << "Sieve Approach: ";
  for (int num : betterAns) {
    cout << num << " ";
  }

  cout << endl;
  return 0;
}
