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

void optimalSetMarkZero(vector<vector<int>> &arr) {
  // In the better approach we used extra space (rowSize, colSize arrays).
  // In this optimal approach, we use the matrix itself to store the markers.
  // We use first row and first column as marker arrays.
  // Special care is taken for arr[0][0], which is common to both row and col.
  // So, we use a separate variable `col0` to track if the first column needs to
  // be zeroed.

  // TC O(NXM) + O(NXM)
  // SC O(1)
  int n = arr.size();    // row
  int m = arr[0].size(); // col

  // vector<int> rowSize(n, 0);     -> matrix[0][...]
  // vector<int> colSize(m, 0);     -> matrix[...][0]

  // Step 2: Traverse the matrix and mark the corresponding row and column
  // if a cell contains 0
  int col0 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        // mark the ith row
        arr[i][0] = 0; // mark current row
        // mark the jth col
        if (j != 0) {

          arr[0][j] = 0; // mark current column
        } else
          col0 = 0; // special case for column 0
      }
    }
  }
  // Marking is done in above loop

  // Step 2: Use markers to set cells to zero (skip first row and column)
  // Now we will iterate without inplace row and col
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (arr[i][j] != 0) {
        // Check for col and row
        if (arr[0][j] == 0 || arr[i][0] == 0) {
          arr[i][j] = 0;
        }
      }
    }
  }
  // Step 3: Handle first row separately
  // Check first row
  if (arr[0][0] == 0) {
    for (int j = 0; j < m; j++) {
      arr[0][j] = 0;
    }
  }
  // Step 4: Handle first column separately (using col0 flag)
  // Check for col
  if (col0 == 0) {
    for (int i = 0; i < n; i++) {
      arr[i][0] = 0;
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
  // betterSetMarkZero(arr);
  optimalSetMarkZero(arr);

  for (auto row : arr) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}