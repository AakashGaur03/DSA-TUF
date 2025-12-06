#include <bits/stdc++.h>
using namespace std;
void solveRatInMaze(int i, int j, vector<vector<int>> &a, int n,
                    vector<string> &ans, string move,
                    vector<vector<int>> &vis) {

  if (i == n - 1 && j == n - 1) {
    ans.push_back(move);
    return;
  }
  vis[i][j] = 1;

  // downward
  if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
    solveRatInMaze(i + 1, j, a, n, ans, move + 'D', vis);
  }
  // left
  if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
    solveRatInMaze(i, j - 1, a, n, ans, move + 'L', vis);
  }
  // right
  if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
    solveRatInMaze(i, j + 1, a, n, ans, move + 'R', vis);
  }
  // upward
  if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
    solveRatInMaze(i - 1, j, a, n, ans, move + 'U', vis);
  }
  vis[i][j] = 0;
}

// Refer Image 21_L18_Rat_In_a_Maze_3
void solveRatInMaze2(int i, int j, vector<vector<int>> &a, int n,
                     vector<string> &ans, string move, vector<vector<int>> &vis,
                     int di[], int dj[]) {

  if (i == n - 1 && j == n - 1) {
    ans.push_back(move);
    return;
  }
  vis[i][j] = 1;

  string dir = "DLRU";
  for (int ind = 0; ind < 4; ind++) {
    int nexti = i + di[ind];
    int nextj = j + dj[ind];
    if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n &&
        !vis[nexti][nextj] && a[nexti][nextj] == 1) {
      solveRatInMaze2(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
    }
  }
  vis[i][j] = 0;
}
int main() {
  cout << "21 L18 Rat In a Maze" << endl;
  // Answer should be in Sorted order i.e. Lexicographical order
  // Down Left Right Up
  // D L R U

  // TC 4^(n*m) we are trying 4 directions in each col (approx)
  // SC (Auxiliary Space) O(m*n)

  vector<vector<int>> a = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

  int n = a.size();
  vector<string> ans1, ans2;

  vector<vector<int>> vis(n, vector<int>(n, 0));

  if (a[0][0] == 1)
    solveRatInMaze(0, 0, a, n, ans1, "", vis);

  vis = vector<vector<int>>(n, vector<int>(n, 0));

  int di[] = {+1, 0, 0, -1};
  int dj[] = {0, -1, 1, 0};

  if (a[0][0] == 1)
    solveRatInMaze2(0, 0, a, n, ans2, "", vis, di, dj);

  for (auto &path : ans1)
    cout << path << " ";
  for (auto &path : ans2)
    cout << path << " ";
  return 0;
}