#include <bits/stdc++.h>
using namespace std;

void bfs() {}

vector<vector<int>> nearest(vector<vector<int>> grid) {
  // TC O(N*M)
  // SC O(N*M)
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<vector<int>> distance(n, vector<int>(m, 0));
  queue<pair<pair<int, int>, int>> q; // {{grid positions}, distance}
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        q.push({{i, j}, 0}); // if it 1 then distance will be 0
        vis[i][j] = 1;
      } else {
        vis[i][j] = 0;
      }
    }
  }
  int delRow[] = {-1, 0, +1, 0};
  int delCol[] = {0, +1, 0, -1};

  while (!q.empty()) {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int steps = q.front().second;
    q.pop();
    distance[row][col] = steps;

    for (int i = 0; i < 4; i++) {
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];

      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          vis[nrow][ncol] == 0) {
        vis[nrow][ncol] = 1;
        q.push({{nrow, ncol}, steps + 1});
      }
    }
  }

  return distance;
}

int main() {
  cout << "11 G 13 Distance of nearest cell having 1" << endl;
  // We need to return the updated Matrix that shows distance of 0s with 1
  // Refer 11_G_13_Distance_of_nearest_cell_having_1_1
  // In Image Left one is question and Right is the answer
  // We can solve this one by BFS as we need to update all the zeros at each
  // step for the distance
  // We will start from 1s and also carry a distance and update the value acc to
  // distance
  vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {1, 0, 0}};

  cout << "Input Matrix:\n";
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  vector<vector<int>> result = nearest(grid);

  cout << "\nDistance Matrix:\n";
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[0].size(); j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}