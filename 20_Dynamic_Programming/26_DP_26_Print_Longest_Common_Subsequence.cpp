#include <bits/stdc++.h>
using namespace std;

string memoizationSol(string &s1, string &s2, int ind1, int ind2,
                      vector<vector<string>> &dp) {

  if (ind1 < 0 || ind2 < 0) {
    return "";
  }

  if (dp[ind1][ind2] != "#") {
    return dp[ind1][ind2];
  }

  if (s1[ind1] == s2[ind2]) {

    return dp[ind1][ind2] =
               memoizationSol(s1, s2, ind1 - 1, ind2 - 1, dp) + s1[ind1];

  } else {

    string notTakeS1 = memoizationSol(s1, s2, ind1 - 1, ind2, dp);

    string notTakeS2 = memoizationSol(s1, s2, ind1, ind2 - 1, dp);

    return dp[ind1][ind2] = (notTakeS1.length() >= notTakeS2.length())
                                ? notTakeS1
                                : notTakeS2;
  }
}

// SImilar to LCS
string tabulationSol(string &s1, string &s2, int n, int m,
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
  int len = dp[n][m];
  string ans = "";
  for (int i = 0; i < len; i++) {
    ans += '$';
  }
  int index = len - 1;
  int i = n;
  int j = m;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      ans[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  return ans;
}

string longestCommonSubsequence(string &text1, string &text2) {

  int n = text1.size();
  int m = text2.size();

  // Memoization
  vector<vector<string>> dp(n, vector<string>(m, "#"));

  string ans1 = memoizationSol(text1, text2, n - 1, m - 1, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));

  string ans2 = tabulationSol(text1, text2, n, m, dp2);

  cout << "Memoization LCS: " << ans1 << endl;
  cout << "Tabulation LCS: " << ans2 << endl;

  return ans2;
}

// TABULATION COMPLEXITY
// | Part           |         Time |                 Space |
// | -------------- | -----------: | --------------------: |
// | Build DP table |    O(n × m)  |             O(n × m)  |
// | Backtrack LCS  |    O(n + m)  |  O(n + m)  for answer |
// |   Overall      |   O(n × m)   |            O(n × m)   |

// | Approach                  |            Time |           Space |
// | ------------------------- | --------------: | --------------: |
// | String Memoization        |  O(n × m × L)   |  O(n × m × L)   |
// | Tabulation + Backtracking |       O(n × m)  |       O(n × m)  |

int main() {
  cout << "26 DP 26 Print Longest Common Subsequence" << endl;

  //   Problem Description: Given two strings str1 and str2, print the longest
  //   common subsequence of the two strings.

  // A subsequence of a string is a list of characters of the string where zero
  // or more characters are deleted and they should be in the same order in the
  // subsequence as in the original string.

  // Pre-requisite: Longest Common Subsequence

  // Examples
  // Input: str1 = "abcd", str2="bdef"
  // Output: "bd"
  // Explanation: LCS of two strings is "bd".
  // Input: str1 = "apple" str2 = "waffle"
  // Output: "ale"
  // Explanation: LCS of two strings is "ale".
  string str1 = "abcd";
  string str2 = "bdef";

  cout << "LCS: " << longestCommonSubsequence(str1, str2) << endl;

  return 0;
}

// EXPLAINATION OF TABULATION METHOD
// One thing to understand carefully

// There are actually two different jobs happening here:

// Job 1 — Find LCS length

// The DP table calculates:

// dp[i][j] = length of LCS of s1[0...i-1] and s2[0...j-1]

// For example:

//       ""  b  d  e  f
// ""     0  0  0  0  0
// a      0  0  0  0  0
// b      0  1  1  1  1
// c      0  1  1  1  1
// d      0  1  2  2  2

// So:

// dp[n][m]

// gives the length.

// Job 2 — Reconstruct the actual LCS

// Then you start here:

// i = n;
// j = m;

// and walk backward through the DP table.

// Match
//   ↓
// take character
//   ↓
// i--, j--

// No match
//   ↓
// compare top vs left
//   ↓
// move toward larger value

// Eventually you have the actual string.

// So your approach is:

//              LCS
//               |
//        +------+------+
//        |             |
//    DP Table       Backtracking
//        |             |
//  Find length      Find string
//        |             |
//    dp[n][m]      ans[index]