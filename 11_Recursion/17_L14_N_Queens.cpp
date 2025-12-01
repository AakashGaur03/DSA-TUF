#include <bits/stdc++.h>
using namespace std;

bool isSafeToPlace(int row, int col, vector<string> &board, int n) {
  int duprow = row;
  int dupcol = col;

  // ------------------------------------------
  // 1. Check UPPER-LEFT DIAGONAL
  // Move (row--, col--) and see if any queen exists
  // ------------------------------------------
  while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    row--;
    col--;
  }

  // Reset row, col
  row = duprow;
  col = dupcol;

  // ------------------------------------------
  // 2. Check LEFT SIDE (same row)
  // Move only col-- and check for any queen
  // ------------------------------------------

  while (col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    col--;
  }

  // Reset row, col
  row = duprow;
  col = dupcol;

  // ------------------------------------------
  // 3. Check LOWER-LEFT DIAGONAL
  // Move (row++, col--) and check for queens
  // ------------------------------------------

  while (row < n && col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    row++;
    col--;
  }

  return true;
}

void solveNQuuen(int col, vector<string> &board, vector<vector<string>> &ans,
                 int n) {

  // TC O(N × N!)
  // Each column must place exactly 1 queen
  // You try all rows for each column

  // SC Board of size N × N
  // takes O(N²) space

  // Recursion depth = N
  // → uses O(N) call stack

  //   Total auxiliary space(excluding output) = O(N²).

  if (col == n) {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (isSafeToPlace(row, col, board, n)) {
      board[row][col] = 'Q';
      solveNQuuen(col + 1, board, ans, n);
      board[row][col] = '.';
    }
  }
}
int main() {
  cout << "17 L14 N Queens" << endl;
  int n = 4;
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++) {
    board[i] = s;
  }
  solveNQuuen(0, board, ans, n);

  for (auto &sol : ans) {
    for (auto &row : sol)
      cout << row << endl;
    cout << endl;
  }
  return 0;
}
