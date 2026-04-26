#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis,
         vector<vector<char>> &mat) {
  vis[row][col] = 1;
  int n = mat.size();
  int m = mat[0].size();
  int delRow[] = {-1, 0, +1, 0};
  int delCol[] = {0, 1, 0, -1};

  for (int i = 0; i < 4; i++) {
    int nrow = row + delRow[i];
    int ncol = col + delCol[i];

    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&
        mat[nrow][ncol] == 'O') {
      vis[nrow][ncol] = 1;
      dfs(nrow, ncol, vis, mat);
    }
  }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
  // TC O(N*M*4)
  // SC O(N*M)
  vector<vector<int>> vis(n, vector<int>(m, 0));

  for (int j = 0; j < m; j++) {
    // Traverse First Row and Last Row
    if (!vis[0][j] && mat[0][j] == 'O') {
      // First Row
      dfs(0, j, vis, mat);
    }
    if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
      // Last Row
      dfs(n - 1, j, vis, mat);
    }
  }

  for (int i = 0; i < n; i++) {
    // Traverse First Col and Last Col
    if (!vis[i][0] && mat[i][0] == 'O') {
      // First Col
      dfs(i, 0, vis, mat);
    }
    if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
      // Last Col
      dfs(i, m - 1, vis, mat);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && mat[i][j] == 'O') {
        mat[i][j] = 'X';
      }
    }
  }
  return mat;
}

int main() {
  cout << "12 G 14 Surrounded Regions | Replace O with X" << endl;
  // Problems states only Replace O's with X's when surronded by all four
  // direction Top Right Bottom Left
  // Refer to 12_G_14_Surrounded_Regions__Replace_O_with_X_1
  // If someone is on the boundary they cant be changed
  // So Set of X connected to a boundary 'O', cant be converted
  // So if we do a BFS or DFS from the O's that are on boundary and have
  // connected O's so those cant be converted and once we finish the traversal
  // on all we can update the rest of O's to X
  vector<vector<char>> mat = {{'X', 'X', 'X', 'X'},
                              {'X', 'O', 'O', 'X'},
                              {'X', 'X', 'O', 'X'},
                              {'X', 'O', 'X', 'X'}};

  int n = mat.size();
  int m = mat[0].size();

  vector<vector<char>> result = fill(n, m, mat);

  cout << "\nOutput Matrix:\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}