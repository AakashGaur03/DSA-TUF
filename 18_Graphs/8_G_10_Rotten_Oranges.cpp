#include <bits/stdc++.h>
using namespace std;

int orrangesRotting(vector<vector<int>> &grid) {
  // TC O(N*M*4)
  // SC O(2*N*M)
  int n = grid.size();
  int m = grid[0].size();

  queue<pair<pair<int, int>, int>> q; // {{row,col},time}
  vector<vector<int>> vis(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        q.push({{i, j}, 0}); // All rotten are in Queue
        vis[i][j] = 2;
      } else {
        vis[i][j] = 0;
      }
    }
  }
  int tm = 0;
  while (!q.empty()) {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int time = q.front().second;
    tm = max(tm, time);
    q.pop();
    // Now we need to Visit all the neighbour
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, -1, 0, +1};
    for (int i = 0; i < 4; i++) { // Because 4 neighbours
      int nRow = row + delRow[i];
      int nCol = col + delCol[i];
      if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
          vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
        q.push({{nRow, nCol}, time + 1});
        vis[nRow][nCol] = 2;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] != 2 && grid[i][j] == 1) {
        return -1;
      }
    }
  }

  return tm;
}

int main() {
  cout << "8 G 10 Rotten Oranges" << endl;
  // Rotting Oranges
  // You are given an m x n grid where each cell can have one of three values:

  // 0 representing an empty cell,
  // 1 representing a fresh orange, or
  // 2 representing a rotten orange.
  // Every minute, any fresh orange that is 4-directionally adjacent to a rotten
  // orange becomes rotten.

  // Return the minimum number of minutes that must elapse until no cell has a
  // fresh orange. If this is impossible, return -1.

  // Level order Traversal (BFS)

  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  int result = orrangesRotting(grid);

  cout << "Minimum time to rot all oranges: " << result << endl;

  return 0;
}