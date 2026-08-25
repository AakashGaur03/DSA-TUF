#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, vector<int> &num, int k) {
  if (k == 0) {
    return 1;
  }
  if (ind == 0) {
    if (num[ind] == k) {
      return 1;
    } else {
      return 0;
    }
  }
  int notPick = recursionSol(ind - 1, num, k);
  int pick = 0;
  if (num[ind] <= k) {
    pick = recursionSol(ind - 1, num, k - num[ind]);
  }

  return pick + notPick;
}

int memoizationSol(int ind, vector<int> &num, int k, vector<vector<int>> &dp) {

  if (k == 0) {
    return 1;
  }
  if (ind == 0) {
    if (num[ind] == k) {
      return 1;
    } else {
      return 0;
    }
  }
  if (dp[ind][k] != -1) {
    return dp[ind][k];
  }
  int notPick = memoizationSol(ind - 1, num, k, dp);
  int pick = 0;
  if (num[ind] <= k) {
    pick = memoizationSol(ind - 1, num, k - num[ind], dp);
  }
  return dp[ind][k] = pick + notPick;
}

int tabulationSol(int n, vector<int> &num, int k, vector<vector<int>> &dp) {

  // Base Case
  // Look at Changing Parameters and write Nested Loops
  // Recursion will be same as memoization

  for (int i = 0; i < n; i++) {
    dp[i][0] = 1;
  }
  if (num[0] <= k) {
    dp[0][num[0]] = 1;
  }

  for (int ind = 1; ind < n; ind++) {
    for (int sum = 0; sum <= k; sum++) {
      int notPick = dp[ind - 1][sum];
      int pick = 0;
      if (num[ind] <= sum) {
        pick = dp[ind - 1][sum - num[ind]];
      }
      dp[ind][sum] = pick + notPick;
    }
  }

  return dp[n - 1][k];
}
int spaceOptimizedSol(int n, vector<int> &num, int k) {

  // Base Case
  // Look at Changing Parameters and write Nested Loops
  // Recursion will be same as memoization
  vector<int> prev(k + 1, 0);
  vector<int> curr(k + 1, 0);

  prev[0] = 1;
  if (num[0] <= k) {
    prev[num[0]] = 1;
  }

  for (int ind = 1; ind < n; ind++) {
    for (int sum = 0; sum <= k; sum++) {
      int notPick = prev[sum];
      int pick = 0;
      if (num[ind] <= sum) {
        pick = prev[sum - num[ind]];
      }
      curr[sum] = pick + notPick;
    }
    prev = curr;
  }

  return prev[k];
}

// | Approach        |       Time |       Space |
// | --------------- | ----------:| -----------:|
// | Recursion       |    O(2^N)  |  O(N) stack |
// | Memoization     |   O(N × K) |  O(N × K)   |
// | Tabulation      |   O(N × K) |  O(N × K)   |
// | Space Optimized |   O(N × K) |     O(K)    |

int findWays(vector<int> &num, int k) {

  int n = num.size();

  // Recursion
  int ans1 = recursionSol(n - 1, num, k);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));

  int ans2 = memoizationSol(n - 1, num, k, dp);

  // Tabulation
  vector<vector<int>> dp2(n, vector<int>(k + 1, 0));

  int ans3 = tabulationSol(n, num, k, dp2);

  // Space Optimization
  int ans4 = spaceOptimizedSol(n, num, k);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

int main() {
  cout << "17 DP 17 Counts Subsets with Sum K" << endl;
  // Problem Statement : Given an array arr of n integers and an integer K,
  // count the number of subsets of the given array that have a sum equal to K.

  // Examples
  // Input: arr = [1, 2, 2, 3], K = 3
  // Output: 3

  // Explanation: The subsets [1,2], [1,2] and [3] have a sum of 3.
  // Input: arr = [1, 2, 3, 4, 5], K = 5
  // Output: 3
  // Explanation: The subsets are [5], [2, 3], and [1, 4].
  vector<int> num = {1, 2, 2, 3};

  int k = 3;

  int ans = findWays(num, k);

  cout << "Final Answer: " << ans << endl;

  return 0;
}
