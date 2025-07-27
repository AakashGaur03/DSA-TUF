#include <bits/stdc++.h>
using namespace std;

void markRow(int i, vector<vector<int>> &arr, int m) {
  for (int j = 0; j < m; j++) {
    if (arr[i][j] != 0) {
      arr[i][j] = -1;
    }
  }
}
void markCol(int j, vector<vector<int>> &arr, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i][j] != 0) {
      arr[i][j] = -1;
    }
  }
}

void bruteSetMarkZero(vector<vector<int>> &arr) {
  // TC O(N X M)(N+M) + O(N X M)
  // (N X M) for two loop on row and collate
  // (N+M) for markRow and markCol Functions
  //   O(N X M) for marking zero
  int n = arr.size();
  int m = arr[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        markRow(i, arr, m);
        markCol(j, arr, n);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == -1) {
        arr[i][j] = 0;
      }
    }
  }
}

void betterSetMarkZero(vector<vector<int>> &arr) {
  // TC O(NXM) + O(NXM)
  // SC O(N) + O(M)
  int n = arr.size();    // row
  int m = arr[0].size(); // col

  // Step 1: Create two marker arrays to keep track of
  // which rows and columns need to be set to 0

  vector<int> rowSize(n, 0);
  vector<int> colSize(m, 0);

  // Step 2: Traverse the matrix and mark the corresponding row and column
  // if a cell contains 0
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        rowSize[i] = 1; // mark entire row to be zeroed
        colSize[j] = 1; // mark entire column to be zeroed
      }
    }
  }

  // Step 3: Iterate again and set cells to 0 if their row or column is marked
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (rowSize[i] == 1 || colSize[j] == 1) {
        arr[i][j] = 0;
      }
    }
  }
}
int main() {
  cout << "Array 13" << endl;

  //   N X N Matrix find out zero and after that
  // Mark entire Row and Coloumn corresponding to that zero mark them zeros

  // 1 1 1 1
  // 1 1 1 1
  // 1 0 0 1
  // 1 1 1 1

  // 1 0 0 1
  // 1 0 0 1
  // 0 0 0 0
  // 1 0 0 1
  vector<vector<int>> arr = {
      {1, 1, 1, 1},
      {1, 1, 1, 1},
      {1, 0, 0, 1},
      {1, 1, 1, 1},
  };
  //   bruteSetMarkZero(arr);
  betterSetMarkZero(arr);

  for (auto row : arr) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}