#include <bits/stdc++.h>
using namespace std;

bool primeNumber(int num) {
  if (num <= 1) {
    return false;
  }

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

vector<int> primeFactors(int num) {
  vector<int> arr;

  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      if (primeNumber(i)) {
        while (num % i == 0) {
          arr.push_back(i);
          num /= i;
        }
      }
    }
  }

  if (num > 1) {
    arr.push_back(num);
  }

  return arr;
}

// TC: O(sqrt(n) * sqrt(n)) = O(n) — loose upper bound
// SC: O(log n) — output-dependent
// Auxiliary SC: O(1)

int main() {
  cout << "4 L4 Print all prime factors of a Number" << endl;
  // Prime factors of a number

  //   Input: n = 18
  // Output: [2, 3, 3]
  // Explanation: The prime factorization of 18 is 2×32.

  // Input: n = 25
  // Output: [5, 5]
  // Explanation: The prime factorization of  25 is 52.

  int num = 18;

  vector<int> ans = primeFactors(num);

  cout << "[";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i < ans.size() - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  return 0;
  return 0;
}
