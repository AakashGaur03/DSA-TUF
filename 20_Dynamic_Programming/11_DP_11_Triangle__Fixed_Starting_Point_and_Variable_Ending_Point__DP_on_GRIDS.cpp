#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, int j, int n, vector<vector<int>> &triangle) {
  if (i == n - 1) {
    return triangle[i][j];
  }
  int down = triangle[i][j] + recursionSol(i + 1, j, n, triangle);
  int right = triangle[i][j] + recursionSol(i + 1, j + 1, n, triangle);

  return min(down, right);
}

int memoizationSol(int i, int j, int n, vector<vector<int>> &triangle,
                   vector<vector<int>> &dp) {
  if (i == n - 1) {
    return triangle[i][j];
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  int down = triangle[i][j] + memoizationSol(i + 1, j, n, triangle, dp);
  int right = triangle[i][j] + memoizationSol(i + 1, j + 1, n, triangle, dp);

  dp[i][j] = min(down, right);
  return dp[i][j];
}

int tabulationSol(int n, vector<vector<int>> &triangle,
                  vector<vector<int>> &dp) {

  for (int j = 0; j < n; j++) {
    dp[n - 1][j] = triangle[n - 1][j];
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      int down = triangle[i][j] + dp[i + 1][j];
      int right = triangle[i][j] + dp[i + 1][j + 1];
      dp[i][j] = min(down, right);
    }
  }

  return dp[0][0];
}

int spaceOptimizedSol(int n, vector<vector<int>> &triangle) {
  vector<int> front(n, 0);
  vector<int> curr(n, 0);
  for (int j = 0; j < n; j++) {
    front[j] = triangle[n - 1][j];
  }

  for (int i = n - 2; i >= 0; i--) {

    for (int j = i; j >= 0; j--) {
      int down = triangle[i][j] + front[j];
      int right = triangle[i][j] + front[j + 1];
      curr[j] = min(down, right);
    }
    front = curr;
  }

  return front[0];
}

// | Approach        |     Time |                Space |
// | --------------- | -------: | -------------------: |
// | Recursion       |  O(2^n)  |          O(n)  stack |
// | Memoization     |  O(n*n)  | O(n*n) + O(n)  stack |
// | Tabulation      |  O(n*n)  |              O(n*n)  |
// | Space Optimized |  O(n*n)  |                O(n)  |

int minimumTotal(vector<vector<int>> &triangle) {
  int n = triangle.size();
  int ans1 = recursionSol(0, 0, n, triangle);

  vector<vector<int>> dp(n, vector<int>(n, -1));
  int ans2 = memoizationSol(0, 0, n, triangle, dp);

  vector<vector<int>> dp2(n, vector<int>(n, 0));
  int ans3 = tabulationSol(n, triangle, dp2);

  int ans4 = spaceOptimizedSol(n, triangle);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

int main() {
  cout << "11 DP 11 Triangle | Fixed Starting Point and Variable Ending Point "
          "| DP on GRIDS"
       << endl;
  // DP on Grids/2D Matrix
  // Count Paths
  // Count Paths with obstacles
  // Min Path Sum
  // Max Path Sum
  // Triangle
  // 2 Start Points

  // Triangle
  // Given a triangle array, return the minimum path sum from top to bottom.

  // For each step, you may move to an adjacent number of the row below. More
  // formally, if you are on index i on the current row, you may move to either
  // index i or index i + 1 on the next row.

  // Example 1:
  // Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
  // Output: 11
  // Explanation: The triangle looks like:
  //    2
  //   3 4
  //  6 5 7
  // 4 1 8 3
  // The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
  // above).

  // As we can see there is no uniformity in the data so Greedy cant be applied
  // So thats how we think for recursion and then DP

  // Example 1
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

  cout << "\nMinimum Path Sum: " << minimumTotal(triangle) << endl;

  return 0;
}
