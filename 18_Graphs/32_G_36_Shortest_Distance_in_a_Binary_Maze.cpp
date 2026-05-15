#include <bits/stdc++.h>
using namespace std;

// n is number of nodes
// m is number of edges
int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination) {
  queue<pair<int, pair<int, int>>> q;
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  dist[source.first][source.second] = 0;
  q.push({0, {source.first, source.second}});

  vector<int> delRow = {-1, 0, 1, 0};
  vector<int> delCol = {0, 1, 0, -1};

  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    int dis = it.first;
    int row = it.second.first;
    int col = it.second.second;

    for (int i = 0; i < 4; i++) {
      int newRow = row + delRow[i];

      int newCol = col + delCol[i];

      if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
          grid[newRow][newCol] == 1 && dis + 1 < dist[newRow][newCol]) {
        dist[newRow][newCol] = dis + 1;
        if (newRow == destination.first && newCol == destination.second) {
          return dis + 1;
        }
        q.push({1 + dis, {newRow, newCol}});
      }
    }
  }

  return -1;
}

int main() {
  cout << "32 G 36 Shortest Distance in a Binary Maze" << endl;

  //   Given a n * m matrix grid where each element can either be 0 or 1. You
  //   need to find the shortest distance between a given source cell to a
  //   destination cell. The path can only be created out of a cell if its value
  //   is 1.

  // If the path is not possible between source cell and destination cell, then
  // return -1.

  // If not mentioned in question then For each cell distance taken is 1
  // Initial Configuration will have a PQ and a Distance Array similar to 2D
  // array will all having INT_MAX value

  // HERE we can also use Queue because there is Unit Distance only and we
  // needed PQ only because we had to sort them acc to distance

  vector<vector<int>> grid = {
      {1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 0, 1, 1}};

  pair<int, int> source = {0, 0};
  pair<int, int> destination = {3, 3};

  int ans = shortestPath(grid, source, destination);

  cout << "Shortest Distance: " << ans << endl;
  return 0;
}
