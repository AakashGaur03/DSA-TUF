#include <bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis,
         vector<vector<char>> &grid) {
  vis[row][col] = 1;
  queue<pair<int, int>> q;
  q.push({row, col});
  int n = grid.size();
  int m = grid[0].size();

  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    // Traverse in the neighbours and mark if it is a land
    for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
      for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
        int nrow = row + deltaRow;
        int ncol = col + deltaCol;
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
          vis[nrow][ncol] = 1;
          q.push({nrow, ncol});
        }
      }
    }
  }
}

int numIslands(vector<vector<char>> &grid) {
  // TC O(N*M)
  // SC O(N*M) + O(N*M)
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  int cnt = 0;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      if (!vis[row][col] && grid[row][col] == '1') {
        cnt++;
        bfs(row, col, vis, grid);
      }
    }
  }
  return cnt;
}

int main() {
  cout << "6 G 8 Number of Islands | Number of Connected Components in Matrix"
       << endl;

  // Given an m x n 2D binary grid grid which represents a map of '1's
  //(land) and '0's (water), return the number of islands.

  // An island is surrounded by water and is formed by connecting adjacent lands
  // horizontally or vertically. or diagnolly You may assume all four edges of
  // the grid are all surrounded by water.

  // Refer 6_G_8_Number_of_Islands__Number_of_Connected_Components_in_Matrix_1
  // Image has 3 islands

  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'},
                               {'1', '0', '0', '1', '1'}};

  int result = numIslands(grid);
  cout << "Number of islands: " << result << endl;

  return 0;
}