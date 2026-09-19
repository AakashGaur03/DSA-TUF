
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, int j, string &pattern, string &text) {

  if (i < 0 && j < 0) {
    return true;
  }
  if (i < 0 && j >= 0) {
    return false;
  }
  if (j < 0 && i >= 0) {
    for (int val = 0; val <= i; val++) {
      if (pattern[val] != '*') {
        return false;
      }
    }
    return true;
  }

  if (pattern[i] == text[j] || pattern[i] == '?') {
    return recursionSol(i - 1, j - 1, pattern, text);
  }

  if (pattern[i] == '*') {
    return recursionSol(i - 1, j, pattern, text) |
           recursionSol(i, j - 1, pattern, text);
  }
  return false;
}

int memoizationSol(int i, int j, string &pattern, string &text,
                   vector<vector<int>> &dp) {

  if (i < 0 && j < 0) {
    return true;
  }
  if (i < 0 && j >= 0) {
    return false;
  }
  if (j < 0 && i >= 0) {
    for (int val = 0; val <= i; val++) {
      if (pattern[val] != '*') {
        return false;
      }
    }
    return true;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  if (pattern[i] == text[j] || pattern[i] == '?') {
    return dp[i][j] = memoizationSol(i - 1, j - 1, pattern, text, dp);
  }

  if (pattern[i] == '*') {
    return dp[i][j] = memoizationSol(i - 1, j, pattern, text, dp) |
                      memoizationSol(i, j - 1, pattern, text, dp);
  }

  return dp[i][j] = false;
}
int tabulationSol(int n, int m, string &pattern, string &text,
                  vector<vector<int>> &dp) {

  // if (i == 0 && j == 0) {
  //   return true;
  // }
  dp[0][0] = true;

  // if (i == 0 && j >= 0) {
  //   return false;
  // }
  for (int j = 1; j <= m; j++) {
    dp[0][j] = false;
  }

  // if (j == 0 && i >= 0) {
  //   for (int val = 1; val <= i; val++) {
  //     if (pattern[val-1] != '*') {
  //       return false;
  //     }
  //   }
  //   return true;
  // }
  for (int i = 1; i <= n; i++) {
    int flag = true;
    for (int val = 1; val <= i; val++) {
      if (pattern[val - 1] != '*') {
        flag = false;
      }
    }
    dp[i][0] = flag;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      }

      else if (pattern[i - 1] == '*') {
        dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
      } else
        dp[i][j] = false;
    }
  }
  return dp[n][m];
}
int spaceOptimized(int n, int m, string &pattern, string &text) {

  vector<bool> prev(m + 1, false);
  vector<bool> curr(m + 1, false);
  // if (i == 0 && j == 0) {
  //   return true;
  // }
  prev[0] = true;

  // if (i == 0 && j >= 0) {
  //   return false;
  // }
  for (int j = 1; j <= m; j++) {
    prev[j] = false;
  }

  for (int i = 1; i <= n; i++) {
    int flag = true;
    for (int val = 1; val <= i; val++) {
      if (pattern[val - 1] != '*') {
        flag = false;
      }
    }
    curr[0] = flag;
    for (int j = 1; j <= m; j++) {
      if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
        curr[j] = prev[j - 1];
      }

      else if (pattern[i - 1] == '*') {
        curr[j] = prev[j] | curr[j - 1];
      } else
        curr[j] = false;
    }
    prev = curr;
  }
  return prev[m];
}

bool wildcardMatching(string &pattern, string &text) {
  int n = pattern.size();
  int m = text.size();

  // Recursion
  int ans1 = recursionSol(n - 1, m - 1, pattern, text);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int ans2 = memoizationSol(n - 1, m - 1, pattern, text, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
  int ans3 = tabulationSol(n, m, pattern, text, dp2);

  // Space Optimization
  int ans4 = spaceOptimized(n, m, pattern, text);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

// | Approach           |         Time |      Space |
// | ------------------ | -----------: | ---------: |
// | Recursion          |  O(2^(n+m))  |    O(n+m)  |
// | Memoization        |    O(n × m)  |  O(n × m)  |
// | Tabulation         |    O(n × m)  |  O(n × m)  |
// | Space Optimization |    O(n × m)  |      O(m)  |

int main() {
  cout << "34 DP 34 Wildcard Matching" << endl;
  // Problem Statement: We are given two strings ‘S1’ and ‘S2’. String S1 can
  // have the following two special characters.

  // ‘?’ can be matched to a single character of S2.
  // ‘*’ can be matched to any sequence of characters of S2. (sequence can be
  // of length zero or more). We need to check whether strings S1 and S2 match
  // or not.

  // Examples

  // Input: S1 = "ab*cd", S2 = "abdefcd"
  // Output: true
  // Explanation: "ab" matches "ab", '*' matches "def", "cd" matches "cd". The
  // strings match.

  // Input: S1 = "*a*b", S2 = "aaab"
  // Output: true
  // Explanation: First '*' matches "aa", 'a' matches 'a', second '*' matches
  // empty string, 'b' matches 'b'. The strings match.

  string pattern = "ab*cd";
  string text = "abdefcd";

  bool ans = wildcardMatching(pattern, text);
  return 0;
}

// int recursionSol(int i, int j, string &pattern, string &text) {

//     // If both pattern and text are completely matched
//     if (i < 0 && j < 0)
//         return true;

//     // If pattern is exhausted but text is still left
//     // then pattern cannot match the remaining text
//     if (i < 0 && j >= 0)
//         return false;

//     // If text is exhausted, remaining pattern must contain only '*'
//     // because '*' can match an empty sequence
//     if (j < 0 && i >= 0) {
//         for (int val = 0; val <= i; val++) {
//             if (pattern[val] != '*')
//                 return false;
//         }
//         return true;
//     }

//     // If characters match or pattern has '?'
//     // '?' can match exactly one character
//     // So move both pattern and text
//     if (pattern[i] == text[j] || pattern[i] == '?') {
//         return recursionSol(i - 1, j - 1, pattern, text);
//     }

//     // '*' has two choices:
//     // 1. Treat '*' as empty -> move pattern only
//     // 2. Let '*' match current text character -> move text only
//     if (pattern[i] == '*') {
//         return recursionSol(i - 1, j, pattern, text) |
//                recursionSol(i, j - 1, pattern, text);
//     }

//     // If characters do not match
//     return false;
// }