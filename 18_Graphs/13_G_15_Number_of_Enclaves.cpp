#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>> &grid) {
  // TC O(N*M*4)
  // SC O(N*M)
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
        if (grid[i][j] == 1) {
          q.push({i, j});
          vis[i][j] = 1;
        }
      }
    }
  }

  int delRow[] = {-1, 0, +1, 0};
  int delCol[] = {0, 1, 0, -1};

  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
        q.push({nrow, ncol});
        vis[nrow][ncol] = 1;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1 && vis[i][j] == 0) {
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  cout << "13 G 15 Number of Enclaves" << endl;

  //   You are given an m x n binary matrix grid, where 0 represents a sea cell
  //   and 1 represents a land cell.

  // A move consists of walking from one land cell to another adjacent
  // (4-directionally) land cell or walking off the boundary of the grid.

  // Return the number of land cells in grid for which we cannot walk off the
  // boundary of the grid in any number of moves.

  // Basically we want Number from which we cannot move out of boudary

  // So intution is start from the boudndary mark all the connected ones as
  // visited and then traverse whole board/grid/matrix and check if in board it
  // is 1 and not visited that cnt++

  // Can be done Similarly to Previous Question But we will try this one with
  // BFS

  // This will be called as MultiSource BFS as we start with more than 1 start
  // points

  vector<vector<int>> grid = {
      {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

  int result = numEnclaves(grid);

  cout << "Number of Enclaves: " << result << endl;

  return 0;
}