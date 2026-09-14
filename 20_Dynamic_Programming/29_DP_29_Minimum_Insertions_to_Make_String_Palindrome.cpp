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

int longestPalinSubseq(string s) {
  string s2 = s;
  reverse(s2.begin(), s2.end());
  return lcs(s, s2);
}

int minInsertion(string s) {

  // Get length of input string
  int n = s.size();

  // Get length of longest palindromic subsequence
  int k = longestPalinSubseq(s);

  // Return total - palindromic length
  return n - k;
}

int main() {

  cout << "29 DP 29 Minimum Insertions to Make String Palindrome" << endl;
  // Problem Statement: Given a string s, find the minimum number of insertions
  // needed to make it a palindrome. A palindrome is a sequence that reads the
  // same backward as forward. You can insert characters at any position in the
  // string.

  // Pre-req: Longest Common Subsequence, Longest Palindromic Subsequence.

  // Examples
  // Input:  s = "abcaa"
  // Output: 2
  // Explanation: Insert 2 characters "c", and "b" to make "abcacba", which is a
  // palindrome. Input : s = "ba" Output: 1 Explanation : Insert "a" at the
  // beginning to make "aba", which is a palindrome.

  // Idea

  // so a string can be made Palindromic at worst by adding a own reversal at
  // the end

  // Here what we can do is keep the longest Palindromic String Intact and then
  // rest we add from left as reverse in Right and vice versa for Right

  // So at most n that minimum insertions will be length - longest palindromic
  // subsequence

  string s = "abcaa";

  int ans = minInsertion(s);

  cout << "Minimum Insertions: " << ans << endl;

  return 0;
}