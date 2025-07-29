#include <bits/stdc++.h>
using namespace std;

// If manually reverse need to be wriiten
void reverseArray(int arr[], int n) {
  int p1 = 0;
  int p2 = n - 1;

  while (p1 < p2) {
    swap(arr[p1], arr[p2]);
    p1++, p2--;
  }
}

vector<vector<int>> bruteRotateArray90Deg(vector<vector<int>> arr) {
  // TC O(N X M)
  // SC O(N X M)
  int n = arr.size();
  int m = arr[0].size();
  //   This line initializes a 2D vector named ans with m rows and n columns.
  vector<vector<int>> ans(m, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[j][(n - 1) - i] = arr[i][j];
    }
  }

  return ans;
}
vector<vector<int>> optimalRotateArray90Deg(vector<vector<int>> &arr) {

  // TC O(N/2 X M/2) + O(N* N/2)
  // SC O(1)
  //   Original
  //   {1, 2, 3, 4},
  //   {5, 6, 7, 8},
  //   {9, 10, 11, 12},
  //   {13, 14, 15, 16},

  // step 1: we Transpose the Matrix
  // Row becomes Col
  //   {1, 5, 9, 13},
  //   {2, 6, 10, 14},
  //   {3, 7, 11, 15},
  //   {4, 8, 12, 16},

  // Step 2: Now we reverse each row we will get the result

  int n = arr.size();
  int m = arr[0].size();
  // Step 1: transpose
  // We cant traverse in whole N X M array as it will place the values again
  // So we need to figure out some condition till which we swap values
  // j= i+1 because no senes to swap arr[0][0] with arr[0][0] basically means
  // same index

  // O(N/2 X M/2)
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < m; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }

  // Step 2
  // O(N* N/2)
  for (int i = 0; i < n; i++) {
    // row is arr[i]
    reverse(arr[i].begin(), arr[i].end());
  }

  return arr;
}

int main() {
  cout << "Array 14" << endl;
  vector<vector<int>> arr = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
  };
  //   vector<vector<int>> res = bruteRotateArray90Deg(arr);
  vector<vector<int>> res = optimalRotateArray90Deg(arr);

  for (auto row : res) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}