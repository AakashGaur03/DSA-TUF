
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, int j, string &s, string &t) {

  if (i < 0) {
    return j + 1; // means s got exhausted and something remains in t
  }
  if (j < 0) {
    return i + 1; // means t got exhausted and something remains in s
  }

  if (s[i] == t[j]) {
    return 0 + recursionSol(i - 1, j - 1, s, t);
  }

  // So value gets inserted in front of s we dont need to reduce i and only j
  int insert = 1 + recursionSol(i, j - 1, s, t);

  // So value gets remove from s so reduce i and keep j same so can check
  // against that too
  int remove = 1 + recursionSol(i - 1, j, s, t);

  // If replace then both will be reduced
  int replace = 1 + recursionSol(i - 1, j - 1, s, t);

  return min(insert, min(remove, replace));
}

int memoizationSol(int i, int j, string &s, string &t,
                   vector<vector<int>> &dp) {

  if (j < 0) {
    return i + 1; // means t got exhausted and something remains in s
  }
  if (i < 0) {
    return j + 1; // means s got exhausted and something remains in t
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (s[i] == t[j]) {
    return 0 + memoizationSol(i - 1, j - 1, s, t, dp);
  }

  // So value gets inserted in front of s we dont need to reduce i and only j
  int insert = 1 + memoizationSol(i, j - 1, s, t, dp);

  // So value gets remove from s so reduce i and keep j same so can check
  // against that too
  int remove = 1 + memoizationSol(i - 1, j, s, t, dp);

  // If replace then both will be reduced
  int replace = 1 + memoizationSol(i - 1, j - 1, s, t, dp);

  return dp[i][j] = min(insert, min(remove, replace));
}

int tabulationSol(int n, int m, string &s, string &t, vector<vector<int>> &dp) {

  for (int i = 0; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {

        // So value gets inserted in front of s we dont need to reduce i and
        // only
        // j
        int insert = 1 + dp[i][j - 1];

        // So value gets remove from s so reduce i and keep j same so can check
        // against that too
        int remove = 1 + dp[i - 1][j];

        // If replace then both will be reduced
        int replace = 1 + dp[i - 1][j - 1];

        dp[i][j] = min(insert, min(remove, replace));
      }
    }
  }

  return dp[n][m];
}
int spaceOptimizedSol(int n, int m, string &s, string &t) {
  vector<int> curr(m + 1, 0);
  vector<int> prev(m + 1, 0);
  for (int j = 0; j <= m; j++) {
    prev[j] = j;
  }
  for (int i = 0; i <= m; i++) {
    curr[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        curr[j] = prev[j - 1];
      } else {

        // So value gets inserted in front of s we dont need to reduce i and
        // only
        // j
        int insert = 1 + curr[j - 1];

        // So value gets remove from s so reduce i and keep j same so can check
        // against that too
        int remove = 1 + prev[j];

        // If replace then both will be reduced
        int replace = 1 + prev[j - 1];

        curr[j] = min(insert, min(remove, replace));
      }
    }
    prev = curr;
  }

  return prev[m];
}

int editDistance(string &S1, string &S2) {

  int n = S1.size();
  int m = S2.size();

  // Recursion
  int ans1 = recursionSol(n - 1, m - 1, S1, S2);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int ans2 = memoizationSol(n - 1, m - 1, S1, S2, dp);

  // Tabulation
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
  int ans3 = tabulationSol(n, m, S1, S2, dp2);

  // Space Optimization
  int ans4 = spaceOptimizedSol(n, m, S1, S2);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

// | Approach           |         Time |      Space |
// | ------------------ | -----------: | ---------: |
// | Recursion          |  O(3^(n+m))  |    O(n+m)  |
// | Memoization        |    O(n × m)  |  O(n × m)  |
// | Tabulation         |    O(n × m)  |  O(n × m)  |
// | Space Optimization |    O(n × m)  |      O(m)  |

int main() {
  cout << "33 DP 33 Edit Distance" << endl;

  // We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The
  // following three operations are allowed:

  // Deletion of a character.
  // Replacement of a character with another one.
  // Insertion of a character.
  // We have to return the minimum number of operations required to convert S1
  // to S2 as our answer.

  // Examples
  // Example 1:
  // Input: start = "planet", target = "plan"
  // Output: 2
  // Explanation:
  // To transform "planet" into "plan", the following operations are required:
  // 1. Delete the character 'e': "planet" -> "plan"
  // 2. Delete the character 't': "plan" -> "plan"
  // Thus, a total of 2 operations are needed.

  // Example 2:
  // Input: start = "abcdefg", target = "azced"
  // Output: 4
  // Explanation:
  // To transform "abcdefg" into "azced", the following operations are required:
  // 1. Replace 'b' with 'z': "abcdefg" -> "azcdefg"
  // 2. Delete 'd': "azcdefg" -> "azcefg"
  // 3. Delete 'f': "azcefg" -> "azceg"
  // 4. Replace 'g' with 'd': "azceg" -> "azced"
  // Thus, a total of 4 operations are needed.

  string S1 = "abcdefg";
  string S2 = "azced";

  int ans = editDistance(S1, S2);

  return 0;
}
