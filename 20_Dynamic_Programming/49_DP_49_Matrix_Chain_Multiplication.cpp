
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int i, int j, vector<int> &arr) {
  if (i == j) {
    return 0;
  }
  int mini = 1e9;
  for (int k = i; k < j; k++) {
    int steps = arr[i - 1] * arr[k] * arr[j] + recursionSol(i, k, arr) +
                recursionSol(k + 1, j, arr);
    if (steps < mini) {
      mini = steps;
    }
  }

  return mini;
}

int memoizationSol(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
  if (i == j) {
    return 0;
  }
  int mini = 1e9;
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  for (int k = i; k < j; k++) {
    int steps = arr[i - 1] * arr[k] * arr[j] + memoizationSol(i, k, arr, dp) +
                memoizationSol(k + 1, j, arr, dp);
    if (steps < mini) {
      mini = steps;
    }
  }

  return dp[i][j] = mini;
}

int tabulationSol(vector<int> &arr, vector<vector<int>> &dp) {
  int n = arr.size();
  for (int i = 1; i < n; i++) {
    dp[i][i] = 0;
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = i + 1; j < n; j++) {
      int mini = 1e9;

      for (int k = i; k < j; k++) {
        int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
        if (steps < mini) {
          mini = steps;
        }
      }

      dp[i][j] = mini;
    }
  }
  return dp[1][n - 1];
}

int matrixMultiplication(vector<int> &nums) {

  int n = nums.size();

  // Recursion
  int ans1 = recursionSol(1, n - 1, nums);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(n, -1));

  int ans2 = memoizationSol(1, n - 1, nums, dp);

  vector<vector<int>> dp2(n, vector<int>(n, 0));

  int ans3 = tabulationSol(nums, dp2);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;

  return ans2;
}

// | Approach     | Time Complexity | Space Complexity |
// |--------------|-----------------|------------------|
// | Recursion    | O(2^N)          | O(N)             |
// | Memoization  | O(N³)           | O(N²)            |
// | Tabulation   | O(N³)           | O(N²)            |

int main() {

  cout << "49 DP 49 Matrix Chain Multiplication" << endl;

  // Partition  DP

  // Matrix chain multiplication
  // Given a chain of matrices A1, A2, A3,.....An, you have to figure out the
  // most efficient way to multiply these matrices. In other words, determine
  // where to place parentheses to minimize the number of multiplications.

  // Given an array nums of size n. Dimension of matrix Ai ( 0 < i < n ) is
  // nums[i - 1] x nums[i].Find a minimum number of multiplications needed to
  // multiply the chain.

  // Example 1:
  // Input : nums = [10, 15, 20, 25]

  // Output : 8000

  // Explanation : There are two ways to multiply the chain - A1*(A2*A3) or
  // (A1*A2)*A3.

  // If we multiply in order- A1*(A2*A3), then number of multiplications
  // required are 11250.

  // If we multiply in order- (A1*A2)*A3, then number of multiplications
  // required are 8000.

  // Refer 48_DP_48_Matrix_Chain_Multiplication_1

  // Thus minimum number of multiplications required is 8000.

  // If we have to solve out in terms of pattern then we use Partition DP

  // Rules for Partition DP

  // 1) Start with Entire Array/Block
  //  -> + Write the Base Case
  // 2) Try out all Partitions
  //  -> Run a loop to try out all Partitions
  // 3) Return the best possible 2 partition

  vector<int> nums = {10, 15, 20, 25};

  int answer = matrixMultiplication(nums);

  cout << "Final Answer: " << answer << endl;
  return 0;
}
