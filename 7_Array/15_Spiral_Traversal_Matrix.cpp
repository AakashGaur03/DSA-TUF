#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &mat) {
  // TC O(N X M)
  // SC O(N X M)
  int n = mat.size();
  int m = mat[0].size();
  int left = 0;
  int right = m - 1;
  int top = 0;
  int bottom = n - 1;
  vector<int> ans;
  while (top <= bottom && left <= right) {

    // Right
    for (int i = left; i <= right; i++) {
      ans.push_back(mat[top][i]);
    }
    top++;

    // top to bottom
    for (int i = top; i <= bottom; i++) {
      ans.push_back(mat[i][right]);
    }
    right--;

    if (top <= bottom) {

      // Bottom to left
      for (int i = right; i >= left; i--) {
        ans.push_back(mat[bottom][i]);
      }

      bottom--;
    }

    if (left <= right) {

      // Bottom to Top
      for (int i = bottom; i >= top; i--) {
        ans.push_back(mat[i][left]);
      }

      left++;
    }
  }

  return ans;
}

int main() {
  cout << "Array 15" << endl;

  // Print Spiral Matrix

  // Ex
  // 1 2 3
  // 4 5 6
  // 7 8 9

  // Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
  // Output: [1,2,3,6,9,8,7,4,5]

  // Right -> Bottom -> Left -> Top
  vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  vector<int> ans = spiralMatrix(mat);

  for (auto it : ans) {
    cout << it << " ";
  }

  return 0;
}

// Complete Logic Overview for Practice
// Spiral Matrix

// Left to right
// Right to Bottom
// Bottom to Left
// Bottom to Top

// top , left = 0
// right , bottom = n-1
// while(left<=right && top<=bottom){

// for(i=Left; i<=right i++){ans.push_back(arr[top][i])}
// top++
// for(i=Right; i<=Bottom i++{ans.push_back(arr[i][right])}
// right--
// if(top<=bottom){for(i=Bottom; i>=Left i--){ans.push_back(arr[bottom][i])}
// bottom--}
// if(left<=right){
// for(i=Bottom; i>=Top i--){ans.push_back(arr[i][left])}
// left++}

// }
