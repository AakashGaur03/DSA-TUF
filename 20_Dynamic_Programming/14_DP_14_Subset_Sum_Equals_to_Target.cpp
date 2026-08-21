#include <bits/stdc++.h>
using namespace std;

bool recursionSol(int ind, int target, vector<int> &arr) {
  if (target == 0)
    return true;
  if (ind == 0)
    return (arr[0] == target);

  bool notTake = recursionSol(ind - 1, target, arr);
  bool take = false;
  if (arr[ind] <= target) {
    take = recursionSol(ind - 1, target - arr[ind], arr);
  }

  return take | notTake;
}

bool memoizationSol(int ind, int target, vector<int> &arr,
                    vector<vector<int>> &dp) {
  if (target == 0)
    return true;
  if (ind == 0)
    return (arr[0] == target);
  if (dp[ind][target] != -1) {
    return dp[ind][target];
  }
  bool notTake = memoizationSol(ind - 1, target, arr, dp);
  bool take = false;
  if (arr[ind] <= target) {
    take = memoizationSol(ind - 1, target - arr[ind], arr, dp);
  }

  return dp[ind][target] = take | notTake;
}
bool tabulationSol(int n, int k, vector<int> &arr, vector<vector<bool>> &dp) {
  for (int i = 0; i < n; i++) {
    dp[i][0] = true;
  }
  dp[0][arr[0]] = true;
  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= k; target++) {
      bool notTake = dp[ind - 1][target];
      bool take = false;
      if (arr[ind] <= target) {
        take = dp[ind - 1][target - arr[ind]];
      }

      dp[ind][target] = take | notTake;
    }
  }

  return dp[n - 1][k];
}
bool spaceoptimzedSol(int n, int k, vector<int> &arr) {
  vector<bool> prev(k + 1, 0);
  vector<bool> curr(k + 1, 0);
  prev[0] = curr[0] = true;

  prev[arr[0]] = true;
  for (int ind = 1; ind < n; ind++) {
    for (int target = 1; target <= k; target++) {
      bool notTake = prev[target];
      bool take = false;
      if (arr[ind] <= target) {
        take = prev[target - arr[ind]];
      }

      curr[target] = take | notTake;
    }
    prev = curr;
  }

  return prev[k];
}

// | Approach        |       Time |        Space |
// | --------------- | ---------: | -----------: |
// | Recursion       |    O(2^N)  |  O(N)  stack |
// | Memoization     |  O(N × K)  |    O(N × K)  |
// | Tabulation      |  O(N × K)  |    O(N × K)  |
// | Space Optimized |  O(N × K)  |        O(K)  |

bool subsetSumToK(int n, int k, vector<int> &arr) {

  // dp[ind][target]

  vector<vector<int>> dp(n, vector<int>(k + 1, -1));

  vector<vector<bool>> dp2(n, vector<bool>(k + 1, false));

  // Recursion
  bool ans1 = recursionSol(n - 1, k, arr);

  // Memoization
  bool ans2 = memoizationSol(n - 1, k, arr, dp);

  // Tabulation
  bool ans3 = tabulationSol(n, k, arr, dp2);

  // Space Optimization
  bool ans4 = spaceoptimzedSol(n, k, arr);

  // Console output
  cout << "Recursion: " << ans1 << endl;

  cout << "Memoization: " << ans2 << endl;

  cout << "Tabulation: " << ans3 << endl;

  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}
int main() {
  cout << " 14 DP 14. Subset Sum Equals to Target | "
          "Subsequences and Ways to Solve them"
       << endl;

  // Problem Statement: We are given an array ‘ARR’ with N positive integers. We
  // need to find if there is a subset in “ARR” with a sum equal to K. If there
  // is, return true else return false.

  // A subset/subsequence is a contiguous or non-contiguous part of an array,
  // where elements appear in the same order as the original array. For example,
  // for the array: [2,3,1] , the subsequences will be
  // [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence
  // because its elements are not in the same order as the original array.

  //
  // Generate all subsquence and check if any of them gives a sum k
  // But question needs only 1 subsequence and we can return true

  // Step 1
  // SO Express in terms of index

  // Step 2
  // Explore all possibilities of that index
  // arr[index] part of subsequence or not part of it

  // Step 3 return T/F

  vector<int> arr = {1, 2, 3, 4};

  int n = arr.size();
  int k = 4;

  bool ans = subsetSumToK(n, k, arr);

  cout << "Final Answer: " << ans << endl;

  return 0;
}
