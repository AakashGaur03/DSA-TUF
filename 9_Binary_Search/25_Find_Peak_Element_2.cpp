#include <bits/stdc++.h>
using namespace std;

int findMaxIndex(vector<vector<int>> &arr, int n, int m, int col) {

  int maxValue = -1;
  int index = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i][col] > maxValue) {
      maxValue = arr[i][col];
      index = i;
    }
  }

  return index;
}

vector<int> findPeak2Darray(vector<vector<int>> arr, int n, int m) {
  int low = 0;
  int high = m - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    // Find max in col
    int maxRowIndex = findMaxIndex(arr, n, m, mid);
    int left = mid - 1 >= 0 ? arr[maxRowIndex][mid - 1] : -1;
    int right = mid + 1 < m ? arr[maxRowIndex][mid + 1] : -1;
    // Compare that with left and right return ans or eliminate other half
    if (arr[maxRowIndex][mid] > left && arr[maxRowIndex][mid] > right) {
      return {maxRowIndex, mid};
    } else if (arr[maxRowIndex][mid] < left) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return {-1, -1};
}

int main() {
  cout << "25 Find Peak Element 2";
  vector<vector<int>> arr = {{4, 3, 5, 1, 4, 5},
                             {2, 9, 3, 2, 3, 2},
                             {1, 7, 6, 0, 1, 3},
                             {3, 6, 2, 3, 7, 2}};
  // No adjacent cell will be equal
  // Out outers are -1
  // If there are multiple elements then we have to return row and
  // col of any peak element

  // Worst approach
  // We scan though each element and check all for spaces that is
  // before after top bottom if greater then return
  // TC O(N*M*4)
  // Better approach (Slight reduce)
  // We scan though each element and check for the largest element
  // That will also be our peak element
  // TC O(N*M)
  // Best approach
  // We take single columns in array by applying BS
  // we find the max element of the array
  // If that element is peak that is greater than 4 direction than reutrn
  // Otherwise the bigger element can be on left or right
  // cant be on top or bottom as we have selected max of rhe columns
  // so in direction where there is big element we will move at
  // that side in BS eleminating shorter side
  // we can do same with row too we ened to find max of row
  // TC O(N* log2 M)

  vector<int> res = findPeak2Darray(arr, arr.size(), arr[0].size());
  for (auto it : res) {
    cout << it << " ";
  }

  return 0;
}