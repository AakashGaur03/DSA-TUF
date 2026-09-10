#include <bits/stdc++.h>
using namespace std;

int recursionSol(string &s1, string &s2, int ind1, int ind2) {

  if (ind1 < 0 || ind2 < 0) {
    return 0;
  }

  if (s1[ind1] == s2[ind2]) {
    return 1 + recursionSol(s1, s2, ind1 - 1, ind2 - 1);
  } else {
    return 0 + max(recursionSol(s1, s2, ind1 - 1, ind2),
                   recursionSol(s1, s2, ind1, ind2 - 1));
  }
}

int memoizationSol(string &s1, string &s2, int ind1, int ind2,
                   vector<vector<int>> &dp) {

  if (ind1 < 0 || ind2 < 0) {
    return 0;
  }
  if (dp[ind1][ind2] != -1) {
    return dp[ind1][ind2];
  }

  if (s1[ind1] == s2[ind2]) {
    return dp[ind1][ind2] = 1 + memoizationSol(s1, s2, ind1 - 1, ind2 - 1, dp);
  } else {
    return dp[ind1][ind2] = 0 + max(memoizationSol(s1, s2, ind1 - 1, ind2, dp),
                                    memoizationSol(s1, s2, ind1, ind2 - 1, dp));
  }
}

int tabulationSol(string &s1, string &s2, int n, int m,
                  vector<vector<int>> &dp) {

  for (int ind1 = 0; ind1 <= n; ind1++) {
    dp[ind1][0] = 0;
  }
  for (int ind2 = 0; ind2 <= m; ind2++) {
    dp[0][ind2] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1]) {
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      } else {
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
      }
    }
  }
  return dp[n][m];
}
int spaceOptimizationSol(string &s1, string &s2, int n, int m) {
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);

  for (int ind2 = 0; ind2 <= m; ind2++) {
    prev[ind2] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1]) {
        curr[ind2] = 1 + prev[ind2 - 1];
      } else {
        curr[ind2] = 0 + max(prev[ind2], curr[ind2 - 1]);
      }
    }
    prev = curr;
  }
  return prev[m];
}

int lcs(string str1, string str2) {

  int n = str1.size();
  int m = str2.size();

  // Recursion
  int ans1 = recursionSol(str1, str2, n - 1, m - 1);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int ans2 = memoizationSol(str1, str2, n - 1, m - 1, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
  int ans3 = tabulationSol(str1, str2, n, m, dp2);

  // Space Optimization
  int ans4 = spaceOptimizationSol(str1, str2, n, m);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

// | Approach           | Time Complexity | Space Complexity |
// | ------------------ | --------------: | ---------------: |
// | Recursion          |     O(2^(n+m))  |          O(n+m)  |
// | Memoization        |         O(n×m)  |          O(n×m)  |
// | Tabulation         |         O(n×m)  |          O(n×m)  |
// | Space Optimization |         O(n×m)  |            O(m)  |

int main() {

  cout << "25 Dp 25 Longest Common Subsequence | DP on Strings" << endl;
  // Subsequence means can be consecutive or non consecutive but should
  // maintain the order of the string

  //  Problem Statement: Given two strings str1 and str2, find the length of
  //  their longest common subsequence.

  // A subsequence is a sequence that appears in the same relative order but
  // not necessarily contiguous and a common subsequence of two strings is a
  // subsequence that is common to both strings.

  // Examples
  // Example 1:
  // Input:
  //  str1 = "bdefg", str2 = "bfg"
  // Output:
  //  3
  // Explanation:
  //  The longest common subsequence is "bfg", which has a length of 3.

  string str1 = "bdefg";
  string str2 = "bfg";

  cout << "Answer: " << lcs(str1, str2) << endl;

  return 0;
  return 0;
}
