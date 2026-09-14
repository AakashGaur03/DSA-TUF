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

int canYouMake(string s1, string s2) {

  // Get length of input strings
  int n = s1.length();
  int m = s2.length();

  // Get length of longest palindromic subsequence
  int k = lcs(s1, s2);

  int ans = (n + m) - (2 * k);
  return ans;
}

int main() {

  cout
      << "30 DP 30 Minimum Insertions/Deletions to Convert String A to String B"
      << endl;

  //   Problem Statement: We are given two strings, str1 and str2. We are
  //   allowed the following operations:
  // 1. Delete any number of characters from string str1.
  // 2. Insert any number of characters in string str1.
  // Return the minimum number of operations required to convert str1 to str2.

  // Pre-requisite: Longest Common Subsequence

  // Examples
  // Input:  str1 = "kitten", str2 = "sitting"
  // Output: 5
  // Explanation: To transform "kitten" to "sitting", delete "k" and insert "s"
  // to get "sitten", then delete 'e' and insert "i" to get "sittin", and insert
  // "g" at the end to get "sitting".

  // Idea
  // Similar to 29_DP_29_Minimum_Insertions_to_Make_String_Palindrome
  // so a string can be made similar at worst by removing everything from one of
  // the string and then adding same of amother string

  // Here what we can do is keep the longest possible values and then that we
  // dont need to touch that we can get from longest common Subsequence
  // 26_DP_26_Print_Longest_Common_Subsequence

  // So Deletions will be n - len(lcs)
  // And we can say Insertion/Deletion from the other string will be also
  // similar m - len(lcs)
  // n is length of str1 and m is length of str2
  // and so we can say Ans is n+m - 2*len(lcs)
  string s1 = "kitten";
  string s2 = "sitting";

  int ans = canYouMake(s1, s2);

  cout << "Minimum Operations: " << ans << endl;

  return 0;
}
