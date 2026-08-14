#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, int j1, int j2, vector<vector<int>> &grid) {
  // Out of Bound Base Case
  int r = grid.size();
  int c = grid[0].size();
  if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) {
    return -1e8;
  }
  // Destination Base Case
  if (i == r - 1) {
    if (j1 == j2) {
      return grid[i][j1];
    } else {
      return grid[i][j1] + grid[i][j2];
    }
  }

  // One thing to Note for every single Moment of Robot 1, Robot 2 can move in 3
  // Directions
  int maxi = -1e8;
  // -1 , 0, 1
  for (int dj1 = -1; dj1 <= +1; dj1++) {
    for (int dj2 = -1; dj2 <= +1; dj2++) {
      int val = 0;
      if (j1 == j2) {
        val += grid[i][j1];
      } else {
        val = grid[i][j1] + grid[i][j2];
      }
      val += recursionSol(i + 1, j1 + dj1, j2 + dj2, grid);
      maxi = max(maxi, val);
    }
  }
  return maxi;
}

int memoizationSol(int i, int j1, int j2, vector<vector<int>> &grid,
                   vector<vector<vector<int>>> &dp) {
  // Out of Bound Base Case
  int n = grid.size();
  int m = grid[0].size();
  int maxi = INT_MIN;

  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
    return -1e8;
  }
  if (dp[i][j1][j2] != -1) {
    return dp[i][j1][j2];
  }
  // Destination Base Case
  if (i == n - 1) {
    if (j1 == j2) {
      return grid[i][j1];
    } else {
      return grid[i][j1] + grid[i][j2];
    }
  }

  // One thing to Note for every single Moment of Robot 1, Robot 2 can move in 3
  // Directions

  // -1 , 0, 1
  for (int dj1 = -1; dj1 <= 1; dj1++) {
    for (int dj2 = -1; dj2 <= 1; dj2++) {
      int val = 0;
      if (j1 == j2) {
        val += grid[i][j1];
      } else {
        val = grid[i][j1] + grid[i][j2];
      }
      val += memoizationSol(i + 1, j1 + dj1, j2 + dj2, grid, dp);
      maxi = max(maxi, val);
    }
  }
  return dp[i][j1][j2] = maxi;
}

int cherryPickup(vector<vector<int>> &grid) {
  int r = grid.size();
  int c = grid[0].size();

  // dp[r][c][c]
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

  // Recursion
  int ans1 = recursionSol(0, 0, c - 1, grid);

  // Memoization
  int ans2 = memoizationSol(0, 0, c - 1, grid, dp);

  // Console output
  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;

  // Return memoization answer
  return ans2;
}

// | Approach    |                          Time |                    Space |
// | ----------- | ----------------------------: | -----------------------: |
// | Recursion   |                       O(9^N)  |              O(N)  stack |
// | Memoization |  O(N × M² × 9)  →  O(N × M²)  |  O(N × M²) + O(N)  stack |

// | Tabulation      || |
// | Space Optimized || |
int main() {
  cout << "13 DP 13 Cherry Pickup II | 3D DP" << endl;
  // 2 Start Points

  //   You are given a rows x cols matrix grid representing a field of cherries
  //   where grid[i][j] represents the number of cherries that you can collect
  //   from the (i, j) cell.

  // You have two robots that can collect cherries for you:

  // Robot #1 is located at the top-left corner (0, 0), and
  // Robot #2 is located at the top-right corner (0, cols - 1).
  // Return the maximum number of cherries collection using both robots by
  // following the rules below:

  // From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or
  // (i + 1, j + 1). When any robot passes through a cell, It picks up all
  // cherries, and the cell becomes an empty cell. When both robots stay in the
  // same cell, only one takes the cherries. Both robots cannot move outside of
  // the grid at any moment. Both robots should reach the bottom row in grid.

  // STEPS TO FOLLOW FOR RECURSION RELATION THAT WILL HELP TO SOLVE IN DP
  // 1) TRY TO REPRESENT THE PROBLEM IN TERMS OF INDEX here we will do (i1,j1)
  // and (i2,j2)
  // 2) DO ALL POSSIBLE STEPS ON THAT INDEX ACC TO PROBLEM STATEMENT
  // 3) IF QUESTION SAYS
  // COUNT ALL THE WAYS -> SUM UP ALL THE STUFF
  // FIND MINIMUM -> GET MINIMUM OF ALL STUFF
  // FIND MAXIMUM -> GET MAXIMUM OF ALL STUFF

  vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};

  cout << "\nMaximum Cherries: " << cherryPickup(grid) << endl;

  return 0;
}
