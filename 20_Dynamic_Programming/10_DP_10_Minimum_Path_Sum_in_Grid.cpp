#include <bits/stdc++.h>
using namespace std;

int recursionSol(vector<vector<int>> &grid, int i, int j) {
  if (i == 0 && j == 0) {
    return grid[i][j];
  }
  if (i < 0 || j < 0) {
    return INT_MAX;
  }
  int up = recursionSol(grid, i - 1, j);
  int left = recursionSol(grid, i, j - 1);
  return grid[i][j] + min(up, left);
}

int memoizationSol(vector<vector<int>> &grid, int i, int j,
                   vector<vector<int>> &dp) {
  if (i == 0 && j == 0) {
    return grid[0][0];
  }
  if (i < 0 || j < 0) {
    return INT_MAX;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int up = memoizationSol(grid, i - 1, j, dp);
  int left = memoizationSol(grid, i, j - 1, dp);
  dp[i][j] = grid[i][j] + min(up, left);
  return dp[i][j];
}

int tabulationSol(vector<vector<int>> &grid, int n, int m,
                  vector<vector<int>> &dp) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = grid[i][j]; // [0][0]
      } else {
        int up = INT_MAX;   // Neglected if i is lesser than zero
        int left = INT_MAX; // Neglected if j is lesser than zero
        if (i > 0) {
          up = grid[i][j] + dp[i - 1][j];
        }
        if (j > 0) {
          left = grid[i][j] + dp[i][j - 1];
        }
        dp[i][j] = min(up, left);
      }
    }
  }

  return dp[n - 1][m - 1];
}

int spaceOptimizedSol(vector<vector<int>> &grid, int n, int m) {
  vector<int> prev(m, 0);
  for (int i = 0; i < n; i++) {
    vector<int> curr(m, 0);
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) {
        curr[j] = grid[i][j]; // [0][0]
      } else {
        int up = INT_MAX;
        int left = INT_MAX;
        if (i > 0) {
          up = grid[i][j] + prev[j];
        }
        if (j > 0) {
          left = grid[i][j] + curr[j - 1];
        }
        curr[j] = min(up, left);
      }
    }
    prev = curr;
  }

  return prev[m - 1];
}

int minPathSum(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int ans1 = recursionSol(grid, n - 1, m - 1);

  vector<vector<int>> dp(n, vector<int>(m, -1));
  int ans2 = memoizationSol(grid, n - 1, m - 1, dp);

  vector<vector<int>> dp2(n, vector<int>(m, 0));
  int ans3 = tabulationSol(grid, n, m, dp2);

  int ans4 = spaceOptimizedSol(grid, n, m);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  return ans4;
}

// | Approach        |         Time |              Space |
// | --------------- | -----------: | -----------------: |
// | Recursion       |  O(2^(m+n))  |      O(m+n)  stack |
// | Memoization     |    O(m × n)  |  O(m × n)  + stack |
// | Tabulation      |    O(m × n)  |          O(m × n)  |
// | Space Optimized |    O(m × n)  |              O(n)  |

int main() {
  cout << "DP 10 Minimum Path Sum in Grid" << endl;
  // DP on Grids/2D Matrix
  // Count Paths
  // Count Paths with obstacles
  // Min Path Sum
  // Max Path Sum
  // Triangle
  // 2 Start Points

  // Given a m x n grid filled with non-negative numbers, find a path from top
  // left to bottom right, which minimizes the sum of all numbers along its
  // path.
  // Note: You can only move either down or right at any point in time.
  // Example 1:
  // Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
  // Output: 7
  // Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
  // Example 2:
  // Input: grid = [[1,2,3],[4,5,6]]
  // Output: 12

  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  minPathSum(grid);

  return 0;
}
