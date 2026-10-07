
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s) {
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i++;
    j--;
  }
  return true;
}

int recursionSol(int i, string &s) {
  int n = s.size();
  if (i == n) {
    return 0;
  }

  int minCutCost = INT_MAX;
  for (int j = i; j < n; j++) {
    if (isPalindrome(i, j, s)) {
      int cost = 1 + recursionSol(j + 1, s);
      minCutCost = min(minCutCost, cost);
    }
  }
  return minCutCost;
}

int memoizationSol(int i, string &s, vector<int> &dp) {
  int n = s.size();
  if (i == n) {
    return 0;
  }
  if (dp[i] != -1) {
    return dp[i];
  }

  int minCutCost = INT_MAX;
  for (int j = i; j < n; j++) {
    if (isPalindrome(i, j, s)) {
      int cost = 1 + memoizationSol(j + 1, s, dp);
      minCutCost = min(minCutCost, cost);
    }
  }
  return dp[i] = minCutCost;
}

int tabulationSol(string &s, vector<int> &dp) {
  int n = s.size();

  dp[n] = 0;

  for (int i = n - 1; i >= 0; i--) {
    int minCutCost = INT_MAX;
    for (int j = i; j < n; j++) {
      if (isPalindrome(i, j, s)) {
        int cost = 1 + dp[j + 1];
        minCutCost = min(minCutCost, cost);
      }
    }
    dp[i] = minCutCost;
  }
  return dp[0];
}

int minCut(string &s) {

  int n = s.size();

  // Recursion
  int ans1 = recursionSol(0, s) - 1;

  // Memoization
  vector<int> dp(n, -1);
  int ans2 = memoizationSol(0, s, dp) - 1;

  // Tabulation
  vector<int> dp2(n + 1, 0);
  int ans3 = tabulationSol(s, dp2) - 1;

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;

  return ans3;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------: | ---------------: |
// | Recursion       |       O(3^N)    |           O(N)   |
// | Memoization     |       O(N^3)    |    O(N) + O(N)   |
// | Tabulation      |       O(N^3)    |           O(N)   |

int main() {

  cout << "53 DP 53 Palindrome Partitioning II" << endl;

  //   Palindrome Partitioning II
  // Given a string s, partition s such that every substring of the partition is
  // a palindrome.

  // Return the minimum cuts needed for a palindrome partitioning of s.

  // Example 1:

  // Input: s = "aab"
  // Output: 1
  // Explanation: The palindrome partitioning ["aa","b"] could be produced using
  // 1 cut. Example 2:

  // Input: s = "a"
  // Output: 0
  // Example 3:

  // Input: s = "ab"
  // Output: 1

  // Input: s = "bababcbadcede"
  // Output: 4

  string s1 = "aab";

  cout << "\nExample 1: " << s1 << endl;
  cout << "Answer: " << minCut(s1) << endl;

  string s2 = "a";

  cout << "\nExample 2: " << s2 << endl;
  cout << "Answer: " << minCut(s2) << endl;

  string s3 = "ab";

  cout << "\nExample 3: " << s3 << endl;
  cout << "Answer: " << minCut(s3) << endl;

  string s4 = "bababcbadcede";

  cout << "\nExample 4: " << s4 << endl;
  cout << "Answer: " << minCut(s4) << endl;

  return 0;
}
