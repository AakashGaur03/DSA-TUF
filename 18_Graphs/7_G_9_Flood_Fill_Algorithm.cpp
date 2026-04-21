#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image,
         int newColor, int delRow[], int delCol[], int iniColor) {
  ans[row][col] = newColor;
  int n = image.size();
  int m = image[0].size();

  for (int i = 0; i < 4; i++) {
    int nrow = row + delRow[i];
    int ncol = col + delCol[i];

    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
        image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
      dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
    }
  }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int newColor) {
  // TC: O(N * M)
  // Each cell is visited at most once

  // SC: O(N * M) + O(N * M)
  // O(N*M) -> for answer matrix (ans)
  // O(N*M) -> worst-case recursion stack (DFS)
  int iniColor = image[sr][sc];
  vector<vector<int>> ans = image;
  // check for 4 neighoubrs

  int delRow[] = {-1, 0, +1, 0};
  int delCol[] = {0, +1, 0, -1};
  dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);

  return ans;
}

int main() {
  cout << "7 G 9 Flood Fill Algorithm" << endl;

  // You are given a 2D grid image[][], where each image[i][j] represents the
  // color of a pixel in the image. Also provided a coordinate (sr, sc)
  // representing the starting pixel (row and column) and a new color value
  // newColor.

  // Your task is to perform a flood fill starting from the pixel (sr, sc),
  // changing its color to newColor and the color of all the connected pixels
  // that have the same original color. Two pixels are considered connected if
  // they are adjacent horizontally or vertically (not diagonally) and have the
  // same original color.

  // Flood Fill Algorithm (Simple Explanation)

  // We are given a 2D grid (image) where each cell represents a color.

  // We are also given:
  // sr -> starting row
  // sc -> starting column
  // newColor -> the color we want to fill with

  // Goal:
  // Change the color of the starting cell (sr, sc)
  // and ALL connected cells that have the SAME original color.

  // "Connected" means:
  // - We can move in 4 directions only:
  //   up, down, left, right
  // - NO diagonal movement
  // - Only move to cells that have the SAME color as the starting cell

  // Steps:
  // 1. Store the original color of (sr, sc)
  // 2. Start from (sr, sc)
  // 3. Visit all neighboring cells (up, down, left, right)
  // 4. If a neighbor has the same original color, change it to newColor
  // 5. Repeat this process (using DFS or BFS) for all such cells

  // Important:
  // - Do NOT change cells that already have a different color
  // - Avoid revisiting the same cell again (use visited)

  // Analogy:
  // Like the "paint bucket" tool in MS Paint,
  // it fills the entire connected region of the same color.

  // Sample input image
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};

  int sr = 1, sc = 1; // starting point
  int newColor = 2;   // color to fill

  // Call flood fill
  vector<vector<int>> result = floodFill(image, sr, sc, newColor);

  // Print result
  cout << "Resultant Image:\n";
  for (auto &row : result) {
    for (auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}