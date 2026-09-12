#include <bits/stdc++.h>
using namespace std;

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
    return dp[ind1][ind2] = 0;
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
  int ans = 0;

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1]) {
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
        ans = max(ans, dp[ind1][ind2]);
      } else {
        dp[ind1][ind2] = 0;
      }
    }
  }

  return ans;
}
int spaceOptimizationSol(string &s1, string &s2, int n, int m) {
  vector<int> prev(m + 1, 0);
  vector<int> curr(m + 1, 0);
  int ans = 0;

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1]) {
        curr[ind2] = 1 + prev[ind2 - 1];
        ans = max(ans, curr[ind2]);
      } else {
        curr[ind2] = 0;
      }
    }
    prev = curr;
  }

  return ans;
}

int longestCommonSubstr(string str1, string str2) {

  int n = str1.size();
  int m = str2.size();

  // Memoization
  vector<vector<int>> dp1(n, vector<int>(m, -1));

  int ans1 = 0;

  for (int ind1 = 0; ind1 < n; ind1++) {
    for (int ind2 = 0; ind2 < m; ind2++) {

      ans1 = max(ans1, memoizationSol(str1, str2, ind1, ind2, dp1));
    }
  }
  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));

  int ans2 = tabulationSol(str1, str2, n, m, dp2);

  // Space Optimization
  int ans3 = spaceOptimizationSol(str1, str2, n, m);

  cout << "Memoization: " << ans1 << endl;
  cout << "Tabulation: " << ans2 << endl;
  cout << "Space Optimization: " << ans3 << endl;

  return ans2;
}

// | Approach           |         Time |      Space |
// | ------------------ | -----------: | ---------: |
// | Recursion          |  O(2^(n+m))  |    O(n+m)  |
// | Memoization        |    O(n × m)  |  O(n × m)  |
// | Tabulation         |    O(n × m)  |  O(n × m)  |
// | Space Optimization |    O(n × m)  |      O(m)  |

int main() {
  cout << "27 DP 27 Longest Common Substring" << endl;

  // Substring : It means the string should be consecutive

  //   Problem Statement: Given two strings str1 and str2, find the length of
  //   their longest common substring.

  // A substring is a contiguous sequence of characters within a string.

  // Examples
  // Example 1:
  // Input:
  //  str1 = "abcde", str2 = "abfce"
  // Output:
  //  2
  // Explanation:
  //  The longest common substring is "ab", which has a length of 2.

  string str1 = "abcde";
  string str2 = "abfce";

  cout << "Answer: " << longestCommonSubstr(str1, str2) << endl;

  return 0;
}