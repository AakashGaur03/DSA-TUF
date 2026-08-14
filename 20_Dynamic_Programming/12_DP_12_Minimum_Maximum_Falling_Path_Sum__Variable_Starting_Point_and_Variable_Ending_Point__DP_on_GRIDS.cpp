#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, int j, vector<vector<int>> &matrix) {
  // TC O(3^(N))
  // SC O(N) Stack space
  int m = matrix[0].size();
  if (j < 0 || j >= m)
    return -1e8;
  if (i == 0) {
    return matrix[i][j];
  }
  int up = recursionSol(i - 1, j, matrix);
  int leftDiagonal = recursionSol(i - 1, j - 1, matrix);
  int rightDiagonal = recursionSol(i - 1, j + 1, matrix);

  return matrix[i][j] + max(up, max(leftDiagonal, rightDiagonal));
}

int memoizationSol(int i, int j, vector<vector<int>> &matrix,
                   vector<vector<int>> &dp) {
  // TC O(N * M)
  // SC O(N * M) Matrix  + O(N) Stack space
  int m = matrix[0].size();
  if (j < 0 || j >= m)
    return -1e8;
  if (i == 0) {
    return matrix[i][j];
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int up = memoizationSol(i - 1, j, matrix, dp);
  int leftDiagnol = memoizationSol(i - 1, j - 1, matrix, dp);
  int rightDiagnol = memoizationSol(i - 1, j + 1, matrix, dp);

  dp[i][j] = matrix[i][j] + max(up, max(leftDiagnol, rightDiagnol));
  return dp[i][j];
}

int tabulationSol(int n, int m, vector<vector<int>> &matrix,
                  vector<vector<int>> &dp) {
  // TC O(N * M) + O(N)
  // SC O(N * M)

  for (int j = 0; j < m; j++) {
    dp[0][j] = matrix[0][j];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {

      int up = matrix[i][j] + dp[i - 1][j];
      int leftDiagnol = -1e8;
      if (j - 1 >= 0) {
        leftDiagnol = matrix[i][j] + dp[i - 1][j - 1];
      }
      int rightDiagnol = -1e8;
      if (j + 1 < m) {
        rightDiagnol = matrix[i][j] + dp[i - 1][j + 1];
      }
      dp[i][j] = max(up, max(leftDiagnol, rightDiagnol));
    }
  }

  int maxi = dp[n - 1][0];
  // Because Now its not fix so we need iterate over the row
  for (int j = 0; j < m; j++) {
    maxi = max(maxi, dp[n - 1][j]);
  }

  return maxi;
}

int spaceOptimizationSol(int n, int m, vector<vector<int>> &matrix) {
  // TC O(N * M) + O(N)
  // SC O(N)
  vector<int> prev(m, 0);
  vector<int> curr(m, 0);
  for (int j = 0; j < m; j++) {
    prev[j] = matrix[0][j];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {

      int up = matrix[i][j] + prev[j];
      int leftDiagnol = -1e8;
      if (j - 1 >= 0) {
        leftDiagnol = matrix[i][j] + prev[j - 1];
      }

      int rightDiagnol = -1e8;
      if (j + 1 < m) {
        rightDiagnol = matrix[i][j] + prev[j + 1];
      }

      curr[j] = max(up, max(leftDiagnol, rightDiagnol));
    }
    prev = curr;
  }

  int maxi = prev[0];
  // Because Now its not fix so we need iterate over the row
  for (int j = 0; j < m; j++) {
    maxi = max(maxi, prev[j]);
  }

  return maxi;
}

// | Approach        |   Time |               Space |
// | --------------- | -----: | ------------------: |
// | Recursion       |  O(3ᴺ) |          O(N) stack |
// | Memoization     | O(N×M) | O(N×M) + O(N) stack |
// | Tabulation      | O(N×M) |              O(N×M) |
// | Space Optimized | O(N×M) |                O(M) |

int getMaxPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  // Recursion
  int ans1 = -1e8;

  for (int j = 0; j < m; j++) {
    ans1 = max(ans1, recursionSol(n - 1, j, matrix));
  }

  // Memoization
  vector<vector<int>> dp(n, vector<int>(m, -1));

  int ans2 = -1e8;

  for (int j = 0; j < m; j++) {
    ans2 = max(ans2, memoizationSol(n - 1, j, matrix, dp));
  }

  // Tabulation
  vector<vector<int>> dp2(n, vector<int>(m, 0));

  int ans3 = tabulationSol(n, m, matrix, dp2);

  // Space Optimization
  int ans4 = spaceOptimizationSol(n, m, matrix);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}
int main() {
  cout << "12 DP 12 Minimum Maximum Falling Path Sum | Variable Starting "
          "Point "
          "and Variable Ending Point | DP on GRIDS"
       << endl;

  // Maximum Path Sum in Matrix
  // You have been given an N*M matrix filled with integer numbers, find the
  // maximum sum that can be obtained from a path starting from any cell in
  // the first row to any cell in the last row.

  // From a cell in a row, you can move to another cell directly below that
  // row, or diagonally below left or right. So from a particular cell (row,
  // col), we can move in three directions i.e.

  // Down: (row+1,col)
  // Down left diagonal: (row+1,col-1)
  // Down right diagonal: (row+1, col+1)
  vector<vector<int>> matrix = {{10, 2, 3}, {3, 7, 2}, {8, 1, 5}};

  cout << "\nMaximum Path Sum: " << getMaxPathSum(matrix) << endl;

  // NOTE USED -1e8 instead of INT_MIN so that when adding Integer Overflow dont
  // happen
  return 0;
}
