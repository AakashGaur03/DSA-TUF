#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis,
         vector<pair<int, int>> &vec, int row0, int col0) {
  vis[row][col] = 1;
  vec.push_back({row - row0, col - col0});
  int n = grid.size();
  int m = grid[0].size();

  int delrow[] = {-1, 0, +1, 0};
  int delcol[] = {0, 1, 0, -1};

  for (int i = 0; i < 4; i++) {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];

    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
        vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
      dfs(nrow, ncol, grid, vis, vec, row0, col0);
    }
  }
}

int countDistinctIslands(vector<vector<int>> &grid) {
  // TC O(N*M*4*log(n*m)). // log because st.insert
  // SC O(2*N*M)
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  set<vector<pair<int, int>>> st;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && grid[i][j] == 1) {
        vector<pair<int, int>> vec;
        dfs(i, j, grid, vis, vec, i, j);
        sort(vec.begin(), vec.end()); // for safer side
        st.insert(vec);
      }
    }
  }

  return st.size();
}

int main() {
  cout << "14 G 16 Number of Distinct Islands" << endl;

  // Given a boolean 2D matrix grid of size n * m. You have to find the number
  // of distinct islands where a group of connected 1s (horizontally or
  // vertically) forms an island. Two islands are considered to be distinct if
  // and only if one island is not equal to another (not rotated or reflected).
  // Refer 14_G_16_Number_of_Distinct_Islands_1 and
  // 14_G_16_Number_of_Distinct_Islands_2

  // To identify identical we will be taking the base and subtracting it will
  // conncected 1s and storing it in a set so identical doesnt get stored
  // Refer 14_G_16_Number_of_Distinct_Islands_3

  vector<vector<int>> grid = {
      {1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}};

  int n = grid.size();
  int m = grid[0].size();

  cout << "\nInput Grid:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  int result = countDistinctIslands(grid);

  cout << "\nNumber of Distinct Islands: " << result << endl;
  return 0;
}