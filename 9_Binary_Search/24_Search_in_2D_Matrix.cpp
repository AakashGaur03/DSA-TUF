#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return true;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return false;
}

bool betterSearch2Dmatrix(vector<vector<int>> mat, int target) {
  // TC O(n) + O(log 2 m)
  int n = mat.size();
  int m = mat[0].size();

  for (int i = 0; i < n; i++) {
    if ((mat[i][0] <= target) && (target <= mat[i][m - 1])) {
      return binarySearch(mat[i], target);
    }
  }

  return false;
}

bool optimalSearch2Dmatrix(vector<vector<int>> mat, int target) {
  // TC  O(log 2(n*m))
  int n = mat.size();
  int m = mat[0].size();

  int low = 0;
  int high = (n * m) - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int row = mid / m; // which row in the matrix
    int col = mid % m; // which column inside that row

    if (mat[row][col] == target) {
      return true;
    } else if (mat[row][col] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return false;
}

int main() {
  cout << "24 Search in 2D Matrix" << endl;
  // Approach 1 Brute Force
  // Iterate over each element and check if present then true else false
  // TC O(n * m)
  // Approach 1 Better
  // For each row we check if target is between first and last of row
  // If yes then apply binary search on that row and true or false
  // TC O(n) + O(log 2 m)

  // Approach 3
  // we convert each element ib hypothetical single indexed array
  // and apply binary search
  // TC  O(log 2(n*m))

  vector<vector<int>> arr = {{1, 2, 3, 4},
                             {12, 23, 25},
                             {31, 31, 33, 34},
                             {{35, 36, 37, 38}},
                             {{39, 41, 42, 45}}};
  int res = betterSearch2Dmatrix(arr, 38);
  cout << res << endl;
  int res2 = optimalSearch2Dmatrix(arr, 38);
  cout << res2 << endl;
  return 0;
}

// EX
// 3   4   6   8
// 10 12  13  15
// 17 18  19  20

// If we flatten it into 1D with indices:

// Index: 0   1   2   3   4   5   6   7   8   9   10  11
// Value: 3   4   6   8   10  12  13  15  17  18  19  20

// For mid = 5:

// row = 5 / 4 = 1
// col = 5 % 4 = 1
// mat[1][1] = 12

// For mid = 10:

// row = 10 / 4 = 2
// col = 10 % 4 = 2
// mat[2][2] = 19

// We flatten the 2D matrix into a 1D array of length n*m.
// For any mid index in this 1D view:
//   row = mid / m  gives which row (integer division)
//   col = mid % m  gives which column (remainder)