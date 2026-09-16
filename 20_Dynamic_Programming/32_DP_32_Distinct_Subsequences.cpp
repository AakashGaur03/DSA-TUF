
#include <bits/stdc++.h>
using namespace std;

// We start from the end of both strings.
//
// i -> current character of s
// j -> current character of t
//
// Base Case 1:
// If j < 0, it means all characters of t have been matched.
// Therefore, we found one valid subsequence.
// return 1;
//
// Base Case 2:
// If i < 0, it means s is exhausted but t is still remaining.
// Therefore, t cannot be formed.
// return 0;
//
// If s[i] == t[j]:
//
// We have two choices:
//
// 1. Take s[i]
//    Use it to match t[j].
//    Move both i and j.
//    recursionSol(i-1, j-1)
//
// 2. Don't take s[i]
//    Skip this character of s.
//    Keep j at the same position.
//    recursionSol(i-1, j)
//
// Since we are counting all possible ways,
// we ADD both choices.
//
// If s[i] != t[j]:
//
// We cannot use s[i] to match t[j].
// So we must skip s[i].
//
// recursionSol(i-1, j)
int recursionSol(int i, int j, string &s, string &t) {
  if (j < 0) {
    return 1;
  }
  if (i < 0) {
    return 0;
  }

  if (s[i] == t[j]) {
    return recursionSol(i - 1, j - 1, s, t) + recursionSol(i - 1, j, s, t);
  } else {
    return recursionSol(i - 1, j, s, t);
  }
};

int memoizationSol(int i, int j, string &s, string &t,
                   vector<vector<int>> &dp) {
  if (j < 0) {
    return 1;
  }
  if (i < 0) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  if (s[i] == t[j]) {
    return dp[i][j] = memoizationSol(i - 1, j - 1, s, t, dp) +
                      memoizationSol(i - 1, j, s, t, dp);
  } else {
    return dp[i][j] = memoizationSol(i - 1, j, s, t, dp);
  }
};

int tabulationSol(int n, int m, string &s, string &t, vector<vector<int>> &dp) {
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int j = 1; j <= m; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  return dp[n][m];
};

int spaceOptimizedSol(int n, int m, string &s, string &t) {
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);

  prev[0] = curr[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        curr[j] = prev[j - 1] + prev[j];
      } else {
        curr[j] = prev[j];
      }
    }
    prev = curr;
  }
  return prev[m];
};

int spaceOptimized1DArraySol(int n, int m, string &s, string &t) {
  vector<int> prev(m + 1, 0);

  prev[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      if (s[i - 1] == t[j - 1]) {
        prev[j] = prev[j - 1] + prev[j];
      }
      // else {
      // CAN BE SKIPPED
      // prev[j] = prev[j];
      // }
    }
  }
  return prev[m];
};

int numDistinct(string s, string t) {
  int n = s.size();
  int m = t.size();

  // Recursion
  int ans1 = recursionSol(n - 1, m - 1, s, t);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int ans2 = memoizationSol(n - 1, m - 1, s, t, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
  int ans3 = tabulationSol(n, m, s, t, dp2);

  // Space Optimization
  int ans4 = spaceOptimizedSol(n, m, s, t);

  // 1D Space Optimization
  int ans5 = spaceOptimized1DArraySol(n, m, s, t);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  cout << "1D Space Optimization: " << ans5 << endl;

  return ans5;
}

// | Approach              |       Time |      Space |
// | --------------------- | ---------: | ---------: |
// | Recursion             |    O(2^n)  |      O(n)  |
// | Memoization           |  O(n × m)  |  O(n × m)  |
// | Tabulation            |  O(n × m)  |  O(n × m)  |
// | 2D Space Optimization |  O(n × m)  |      O(m)  |
// | 1D Space Optimization |  O(n × m)  |      O(m)  |

int main() {
  cout << "32 DP 32 Distinct Subsequences" << endl;

  // Problem Statement : Given two strings s and t, return the number of
  // distinct subsequences of s that equal t.

  // A subsequence of a string is a new string generated from the original
  // string with some characters (can be none) deleted without changing the
  // relative order of the remaining characters. For example, "ace" is a
  // subsequence of "abcde" while "aec" is not.

  // The task is to count how many different ways we can form t from s by
  // deleting some (or no) characters from s.

  // Examples
  // Input: s = "axbxax", t = "axa"
  // Output: 2
  // Explanation: In the string "axbxax", there are two distinct subsequences
  // "axa": (a)(x)bx(a)x (a)xb(x)(a)x Input: s = "babgbag", t = "bag" Output: 5
  // Explanation: In the string "babgbag", there are five distinct subsequences
  // "bag": (ba)(b)(ga)(g) (ba)(bg)(ag) (bab)(ga)(g) (bab)(g)(ag) (babg)(a)(g)

  string s = "babgbag";
  string t = "bag";

  numDistinct(s, t);
  return 0;
}
