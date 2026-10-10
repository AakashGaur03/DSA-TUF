
#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>> &matrix, vector<vector<int>> &dp) {
  int n = matrix.size();
  int m = matrix[0].size();
  for (int i = 0; i < n; i++) {
    dp[i][0] = matrix[i][0];
  }
  for (int j = 0; j < m; j++) {
    dp[0][j] = matrix[0][j];
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (matrix[i][j] == 0) {
        dp[i][j] = 0;
      } else {

        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
      }
    }
  }

  int sum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum += dp[i][j];
    }
  }
  return sum;
}

// Complexity:
// Time: O(n×m)
// Space: O(n×m) for the DP table.

int main() {

  cout << "56 DP 56 Count Square Submatrices with All Ones" << endl;
  // Count Square Submatrices with All Ones
  // Given a m * n matrix of ones and zeros, return how many square submatrices
  // have all ones.

  // Example 1:

  // Input: matrix =
  // [
  //   [0,1,1,1],
  //   [1,1,1,1],
  //   [0,1,1,1]
  // ]
  // Output: 15
  // Explanation:
  // There are 10 squares of side 1.
  // There are 4 squares of side 2.
  // There is  1 square of side 3.
  // Total number of squares = 10 + 4 + 1 = 15.
  // Example 2:

  // Input: matrix =
  // [
  //   [1,0,1],
  //   [1,1,0],
  //   [1,1,0]
  // ]
  // Output: 7
  // Explanation:
  // There are 6 squares of side 1.
  // There is 1 square of side 2.
  // Total number of squares = 6 + 1 = 7.

  // Constraints:

  // 1 <= arr.length <= 300
  // 1 <= arr[0].length <= 300
  // 0 <= arr[i][j] <= 1

  // Example 1
  vector<vector<int>> matrix1 = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};

  vector<vector<int>> dp1(matrix1.size(), vector<int>(matrix1[0].size(), 0));

  cout << "\nExample 1:" << endl;
  cout << "Output: " << countSquares(matrix1, dp1) << endl;
  // Expected: 15

  // Example 2
  vector<vector<int>> matrix2 = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};

  vector<vector<int>> dp2(matrix2.size(), vector<int>(matrix2[0].size(), 0));

  cout << "\nExample 2:" << endl;
  cout << "Output: " << countSquares(matrix2, dp2) << endl;
  // Expected: 7

  // Example 3
  vector<vector<int>> matrix3 = {{1}};

  vector<vector<int>> dp3(matrix3.size(), vector<int>(matrix3[0].size(), 0));

  cout << "\nExample 3:" << endl;
  cout << "Output: " << countSquares(matrix3, dp3) << endl;
  // Expected: 1
  return 0;
}

// Refer 56_DP_56_Count_Square_Submatrices_with_All_Ones_1
// So Approach here is that For the First Row and Coloumn our DP table will Look
// Same then for the rest we will check if that index is itself one and if yes
// then add 1 with minimal of left Top and Left Top Diagnol that means how many
// number of Sqaure can be made up to that i,j
// And then we can simply add a for loop or carry a total varibale that adds all
// of the dp arrays values
