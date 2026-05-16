#include <bits/stdc++.h>
using namespace std;

int minimumEffor(vector<vector<int>> &heights) {
  // TC  O(E Log V) = n * m * 4 * log(n*m)
  // SC O(n*m)
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;
  int n = heights.size();
  int m = heights[0].size();
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  dist[0][0] = 0;
  pq.push({0, {0, 0}});

  vector<int> delRow = {-1, 0, 1, 0};
  vector<int> delCol = {0, 1, 0, -1};

  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    int diff = it.first;
    int row = it.second.first;
    int col = it.second.second;

    if ((row == n - 1) && (col == m - 1)) {
      return diff;
    }

    for (int i = 0; i < 4; i++) {
      int newRow = row + delRow[i];
      int newCol = col + delCol[i];

      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
        int newEffort =
            max(abs(heights[row][col] - heights[newRow][newCol]), diff);
        if (newEffort < dist[newRow][newCol]) {
          dist[newRow][newCol] = newEffort;
          pq.push({newEffort, {newRow, newCol}});
        }
      }
    }
  }

  return -1;
}

int main() {
  cout << "33 G 37 Path With Minimum Effort" << endl;

  //   You are given a 2D array mat[][], of size n*m. Your task is to find the
  //   minimum possible path cost from the top-left cell (0, 0) to the
  //   bottom-right cell (n-1, m-1) by moving up, down, left, or right between
  //   adjacent cells.

  // Note: The cost of a path is defined as the maximum absolute difference
  // between the values of any two consecutive cells along that path.

  // Refer
  // 33_G_37_Path_With_Minimum_Effort_1,
  // 33_G_37_Path_With_Minimum_Effort_2,
  // 33_G_37_Path_With_Minimum_Effort_3

  // We will take Initally PQ with {distanceDifference,{row,col}}
  // and a distance [][] with infinity

  vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

  cout << minimumEffor(heights) << endl;

  return 0;
  return 0;
}
