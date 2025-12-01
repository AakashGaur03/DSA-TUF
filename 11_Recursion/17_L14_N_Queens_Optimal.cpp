#include <bits/stdc++.h>
using namespace std;

void solveNQueenOptimal(int col, vector<string> &board,
                        vector<vector<string>> &ans, vector<int> &leftRow,
                        vector<int> &upperDiagonal, vector<int> &lowerDiagonal,
                        int n) {

  // Base case: if all queens are placed (col reached n)
  if (col == n) {
    ans.push_back(board); // store the valid board configuration
    return;
  }

  // Try placing a queen in every row of the current column
  for (int row = 0; row < n; row++) {

    // Check if placing a queen at (row, col) is safe
    if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
        upperDiagonal[n - 1 + col - row] == 0) {

      // Place the queen
      board[row][col] = 'Q';

      // Mark row, lower diagonal, upper diagonal as occupied
      leftRow[row] = 1;
      lowerDiagonal[row + col] = 1;
      upperDiagonal[n - 1 + col - row] = 1;

      // Recurse for next column
      solveNQueenOptimal(col + 1, board, ans, leftRow, upperDiagonal,
                         lowerDiagonal, n);

      // Backtrack: Remove the queen and unmark
      board[row][col] = '.';
      leftRow[row] = 0;
      lowerDiagonal[row + col] = 0;
      upperDiagonal[n - 1 + col - row] = 0;
    }
  }
}
int main() {
  cout << "17 L14 N Queens Optimal" << endl;
  int n = 4;
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++) {
    board[i] = s;
  }

  vector<int> leftRow(n, 0);
  vector<int> upperDiagonal(2 * n - 1, 0);
  vector<int> lowerDiagonal(2 * n - 1, 0);
  solveNQueenOptimal(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

  // This is the clean, optimal N-Queens solution using:
  // O(1) safety checks using row + diagonals arrays
  // O(N!) time complexity
  // O(N) extra space for diagonal + row arrays

  for (auto &sol : ans) {
    for (auto &row : sol)
      cout << row << endl;
    cout << endl;
  }
  return 0;
}
