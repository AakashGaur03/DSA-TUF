#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c) {
      return false;
    }
    if (board[row][i] == c) {
      return false;
    }

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
      return false;
    }
  }
  return true;
}

bool solve(vector<vector<char>> &board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {

      if (board[i][j] == '.') {

        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solve(board) == true) {
              return true;
            } else {
              board[i][j] = '.';
            }
          }
        }
        return false;
      }
    }
  }
  return true; // At every index some number is placed
}

void printBoard(const vector<vector<char>> &board) {
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      cout << board[i][j] << (j == 8 ? "" : " ");
      if ((j + 1) % 3 == 0 && j != 8)
        cout << "| ";
    }
    cout << endl;
    if ((i + 1) % 3 == 0 && i != 8) {
      cout << "---------------------" << endl;
    }
  }
}
int main() {
  cout << "18 L15 Sudoko Solver" << endl;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  cout << "\n--- Original Board ---" << endl;
  printBoard(board);

  if (solve(board)) {
    cout << "\n--- Solved Board ---" << endl;
    printBoard(board);
  } else {
    cout << "\nFailed to solve the board." << endl;
  }

  return 0;
  return 0;
}

//  3. Check 3x3 Subgrid
// The indices for the 3x3 subgrid are calculated using integer division:
// board[start_row + offset_i][start_col + offset_j]
// int subgrid_row = 3 * (row / 3) + i / 3;
// int subgrid_col = 3 * (col / 3) + i % 3;

// if (board[subgrid_row][subgrid_col] == c) {
//   return false;
// }

// void printBoard(const vector<vector<char>> &board) {
//   // Loop through each row (i from 0 to 8)
//   for (int i = 0; i < 9; ++i) {
//     // Loop through each column (j from 0 to 8)
//     for (int j = 0; j < 9; ++j) {

//       // 1. Print the cell value and a space separator
//       // (j == 8 ? "" : " ") is a ternary operator.
//       // It prints a space after the number, UNLESS it is the last column
//       (j=8). cout << board[i][j] << (j == 8 ? "" : " ");

//       // 2. Print the vertical 3x3 separator (|)
//       // (j + 1) % 3 == 0 checks if the column index is 2, 5, or 8 (i.e., the
//       end of a 3-cell group).
//       // j != 8 ensures we don't print the separator after the absolute last
//       column. if ((j + 1) % 3 == 0 && j != 8)
//         cout << "| ";
//     }

//     // End the current row after the inner loop finishes
//     cout << endl;

//     // 3. Print the horizontal 3x3 separator (-----)
//     // (i + 1) % 3 == 0 checks if the row index is 2 or 5 (i.e., the end of a
//     3-row group).
//     // i != 8 ensures we don't print the separator after the absolute last
//     row. if ((i + 1) % 3 == 0 && i != 8) {
//       cout << "---------------------" << endl;
//     }
//   }
// }