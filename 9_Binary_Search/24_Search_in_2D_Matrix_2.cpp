#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

vector<int> betterSearch2Dmatrix(vector<vector<int>> mat, int target) {
  // TC O(n * log m)
  int n = mat.size();
  int m = mat[0].size();

  for (int i = 0; i < n; i++) {
    if ((mat[i][0] <= target) && (target <= mat[i][m - 1])) {
      int res = binarySearch(mat[i], target);
      if (res != -1) {

        return {i, res};
      }
    }
  }

  return {-1, -1};
}

vector<int> optimalSearch2DMatrix(vector<vector<int>> mat, int target) {
  // TC O(n + m)
  int n = mat.size();
  int m = mat[0].size();
  int row = 0;
  int col = m - 1;
  while (row < n && col >= 0) {
    if (mat[row][col] == target) {
      return {row, col};
    } else if (mat[row][col] < target) {
      row++;
    } else {
      col--;
    }
  }
  return {-1, -1};
}
int main() {
  cout << "24 Search in 2D Matrix 2" << endl;
  // Indiviual Rows and Indiviual Columns will be sorted
  // We have to find Coordinates of the Target element
  // Approach 1 Brute Force
  // Iterate over each element and check if present then indexes else {-1,-1}
  // TC O(n * m)
  // Approach 1 Better
  // For each row we check if target is between first and last of row
  // If yes then apply binary search on that row and true or false
  // WE just need to return index here instead of true and false
  // TC O(n) * O(log 2 m)

  // Brute and Better Apporach Remains the same
  // WE can't use same Appraoch third as we dont have all the matrix in fully
  // sorted manner like in previous case

  // Here Direct Binary Search is not present
  // But Concept of Elimination so indirectly it is applied
  // Optimal Approach (Staircase Search):
  // Start from top-right corner of the matrix.
  // At each step:
  //   - If current element == target → return coordinates.
  //   - If current element < target → move down (row++).
  //   - If current element > target → move left (col--).
  // Time Complexity: O(n + m) → At most n + m steps in the worst case.
  // Space Complexity: O(1).
  // Works because both rows and columns are individually sorted.

  vector<vector<int>> arr = {{1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10, 13, 14, 17, 24},
                             {18, 21, 23, 26, 30}};
  vector<int> res = betterSearch2Dmatrix(arr, 23);
  cout << endl;
  for (auto it : res) {
    cout << it << " ";
  }
  vector<int> res2 = optimalSearch2DMatrix(arr, 23);
  cout << endl;
  for (auto it2 : res2) {
    cout << it2 << " ";
  }

  return 0;
}