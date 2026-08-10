#include <bits/stdc++.h>
using namespace std;

int recursionSol(int m, int n) {
  if (m == 0 && n == 0) {
    return 1;
  }
  if (m < 0 || n < 0) {
    return 0;
  }
  int up = recursionSol(m - 1, n);
  int left = recursionSol(m, n - 1);

  return up + left;
}

int memoizationSol(int m, int n, vector<vector<int>> &dp) {
  if (m == 0 && n == 0) {
    return 1;
  }
  if (m < 0 || n < 0) {
    return 0;
  }
  if (dp[m][n] != -1) {
    return dp[m][n];
  }
  int up = memoizationSol(m - 1, n, dp);
  int left = memoizationSol(m, n - 1, dp);

  dp[m][n] = up + left;
  return dp[m][n];
}

int tabulationSol(int m, int n, vector<vector<int>> &dp) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 1;
      } else {
        int up = 0;
        int left = 0;
        if (i > 0) {
          up = dp[i - 1][j];
        }
        if (j > 0) {
          left = dp[i][j - 1];
        }
        dp[i][j] = up + left;
      }
    }
  }
  return dp[m - 1][n - 1];
}
int spaceOptimizedSol(int m, int n, vector<int> &dp) {

  for (int i = 0; i < m; i++) {
    vector<int> curr(n, 0);
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        curr[j] = 1;
      } else {
        int up = 0;
        int left = 0;
        if (i > 0) {
          up = dp[j];
        }
        if (j > 0) {
          left = curr[j - 1];
        }
        curr[j] = up + left;
      }
    }
    dp = curr;
  }
  return dp[n - 1];
}

// | Approach        |         Time |             Space |
// | --------------- | -----------: | ----------------: |
// | Recursion       |  O(2^(m+n))  |     O(m+n)  stack |
// | Memoization     |      O(m*n)  |  O(m*n) + O(m+n)  |
// | Tabulation      |      O(m*n)  |           O(m*n)  |
// | Space Optimized |      O(m*n)  |             O(n)  |

int uniquePaths(int m, int n) {
  // 1. Recursion
  int ans1 = recursionSol(m - 1, n - 1);

  // 2. Memoization
  vector<vector<int>> dp(m, vector<int>(n, -1));

  int ans2 = memoizationSol(m - 1, n - 1, dp);

  // 3. Tabulation
  vector<vector<int>> dp2(m, vector<int>(n, -1));

  int ans3 = tabulationSol(m, n, dp2);

  // 4. Space Optimization
  vector<int> dp3(n, 0);

  int ans4 = spaceOptimizedSol(m, n, dp3);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

int main() {
  cout << "8 DP 8 Grid Unique Paths" << endl;
  // DP on Grids/2D Matrix
  // Count Paths
  // Count Paths with obstacles
  // Min Path Sum
  // Max Path Sum
  // Triangle
  // 2 Start Points

  // Question 1

  // Unique Paths
  // There is a robot on an m x n grid. The robot is initially located at the
  // top-left corner (i.e., grid[0][0]). The robot tries to move to the
  // bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
  // either down or right at any point in time.

  // Given the two integers m and n, return the number of possible unique paths
  // that the robot can take to reach the bottom-right corner.

  // The test cases are generated so that the answer will be less than or equal
  // to 2 * 109.

  int m = 3;
  int n = 7;

  cout << "Answer: " << uniquePaths(m, n) << endl;

  return 0;
}
