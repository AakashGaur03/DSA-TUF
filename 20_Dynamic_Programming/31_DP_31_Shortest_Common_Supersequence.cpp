
#include <bits/stdc++.h>
using namespace std;

string memoizationSol(string &s1, string &s2, int ind1, int ind2,
                      vector<vector<string>> &dp) {

  // If s1 is exhausted, take remaining characters of s2
  if (ind1 < 0) {
    return s2.substr(0, ind2 + 1);
  }

  // If s2 is exhausted, take remaining characters of s1
  if (ind2 < 0) {
    return s1.substr(0, ind1 + 1);
  }

  if (dp[ind1][ind2] != "#") {
    return dp[ind1][ind2];
  }

  // Characters are same, take only once
  if (s1[ind1] == s2[ind2]) {

    return dp[ind1][ind2] =
               memoizationSol(s1, s2, ind1 - 1, ind2 - 1, dp) + s1[ind1];

  } else {

    // Take character from s1
    string takeS1 = memoizationSol(s1, s2, ind1 - 1, ind2, dp) + s1[ind1];

    // Take character from s2
    string takeS2 = memoizationSol(s1, s2, ind1, ind2 - 1, dp) + s2[ind2];

    // Return the shorter supersequence
    if (takeS1.length() <= takeS2.length()) {
      return dp[ind1][ind2] = takeS1;
    }
    return dp[ind1][ind2] = takeS2;
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
  string ans = "";

  int i = n;
  int j = m;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      ans += s1[i - 1];
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      ans += s1[i - 1];
      i--;
    } else {
      ans += s1[j - 1];
      j--;
    }
  }

  while (i > 0) {
    ans += s1[i - 1];
    i--;
  }
  while (j > 0) {
    ans += s2[j - 1];
    j--;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

string shortestSupersequence(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  // Memoization
  vector<vector<string>> dp(n, vector<string>(m, "#"));

  string ans1 = memoizationSol(s1, s2, n - 1, m - 1, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));

  string ans2 = tabulationSol(s1, s2, n, m, dp2);

  cout << "Memoization: " << ans1 << endl;
  cout << "Tabulation: " << ans2 << endl;

  return ans2;
}

// | Approach        |                 Time |                Space |
// | --------------- | -------------------: | -------------------: |
// |   Memoization   |  O(n × m × (n + m))  |  O(n × m × (n + m))  |
// |   Tabulation    |            O(n × m)  |            O(n × m)  |

int main() {
  cout << "31 DP 31 Shortest Common Supersequence" << endl;

  // Supersequence is which contains all the given strings

  //   Problem Statement: We are given two strings ‘S1’ and ‘S2’. We need to
  //   return their shortest common supersequence. A supersequence is defined as
  //   the string which contains both the strings S1 and S2 as subsequences.

  // Examples
  // Input : str1 = "mno", str2 = "nop"
  // Output :"mnop"
  // Explanation : The shortest common supersequence is "mnop". It contains
  // "mno" as the first three characters and "nop" as the last three characters,
  // thus including both strings as subsequences.

  // Input :str1 = "dynamic", str2 = "program"
  // Output : "dynprogramic"
  // Explanation :The shortest common supersequence is "dynprogramic". It
  // includes all characters from both "dynamic" and "program", with minimal
  // overlap. For example, "dynamic" appears as "dyn...amic" and "program"
  // appears as "...program..." within "dynprogramic".

  // Idea
  // Similar to 29_DP_29_Minimum_Insertions_to_Make_String_Palindrome +
  // 30_DP_30_Minimum_Insertions__Deletions_to_Convert_String_A_to_String_B
  // so a string can be made supersequnece at worst by taking everything from
  // both the strings

  // Here what we will do is take the LCS
  // 26_DP_26_Print_Longest_Common_Subsequence
  // and then simply length of the Longest Commom Supersequence can be n+m -
  // LCS length

  // How Do we print the Shortest Commom Supersequence
  // We will use the concept of LCS and will slightly modify it as we had a
  // table in which it tells us the occurance of the characters
  string s1 = "mno";
  string s2 = "nop";

  cout << "Shortest Common Supersequence: " << shortestSupersequence(s1, s2)
       << endl;

  return 0;
}

// Shortest Common Supersequence
//
// A Supersequence is a string which contains both S1 and S2
// as subsequences.
//
// Example:
// S1 = "mno"
// S2 = "nop"
//
// SCS = "mnop"
//
// Why does "mnop" work?
//
// S1 -> m n o
//      | | |
// SCS -> m n o p
//
// S2 ->   n o p
//
// Both strings are present as subsequences.
//
// ------------------------------------------------------------
//
// Idea:
//
// At worst, we can take all characters from both strings.
//
// Therefore:
//
// Maximum possible length = n + m
//
// But if some characters are common between both strings,
// we can use them only once.
//
// The maximum number of characters that can be shared
// between both strings is their LCS.
//
// Therefore:
//
// Length of SCS = n + m - LCS length
//
// ------------------------------------------------------------
//
// How do we construct the actual SCS?
//
// We first build the LCS DP table.
//
// The LCS table tells us which direction contains the
// longest common subsequence.
//
// Then we traverse the table backwards.
//
// Case 1:
// s1[i-1] == s2[j-1]
//
// Both strings have the same character.
//
// We only need to add it once.
//
// ans += s1[i-1]
// i--
// j--
//
// Case 2:
// s1[i-1] != s2[j-1]
//
// We have two choices:
//
// 1. Take s1[i-1]
//    Move i--
//
// 2. Take s2[j-1]
//    Move j--
//
// We choose the side having the larger LCS value.
//
// dp[i-1][j] > dp[i][j-1]
//     -> take s1[i-1]
//
// otherwise
//     -> take s2[j-1]
//
// Case 3:
// One string is completely processed.
//
// Add all remaining characters of the other string.
//
// Finally, reverse the answer because we constructed it
// from the end towards the beginning.
//
// ------------------------------------------------------------
//
// Memoization:
//
// State:
//
// memoizationSol(ind1, ind2)
//
// represents the shortest common supersequence of
// s1[0...ind1] and s2[0...ind2].
//
// If characters are equal:
//     take once
//
// If characters are different:
//     try taking from s1
//     try taking from s2
//     choose the shorter result.
//
// ------------------------------------------------------------
//
// Important:
//
// LCS is used as a guide for the tabulation approach,
// while memoization can directly construct the SCS.
//
// Tabulation is more space/time efficient because it stores
// integer lengths instead of a complete string at every state.