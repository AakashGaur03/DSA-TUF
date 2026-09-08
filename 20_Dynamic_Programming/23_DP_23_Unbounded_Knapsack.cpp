#include <bits/stdc++.h>
using namespace std;

int recursionSol(vector<int> &wt, vector<int> &val, int ind, int W) {

  if (ind == 0) {
    return ((int)(W / wt[0])) * val[0];
  }
  int notTake = recursionSol(wt, val, ind - 1, W);
  int take = 0;
  if (wt[ind] <= W) {
    take = val[ind] + recursionSol(wt, val, ind, W - wt[ind]);
  }

  return max(take, notTake);
}
int memoizationSol(vector<int> &wt, vector<int> &val, int ind, int W,
                   vector<vector<int>> &dp) {

  if (ind == 0) {
    return ((int)(W / wt[0])) * val[0];
  }

  if (dp[ind][W] != -1) {
    return dp[ind][W];
  }
  int notTake = memoizationSol(wt, val, ind - 1, W, dp);
  int take = 0;
  if (wt[ind] <= W) {
    take = val[ind] + memoizationSol(wt, val, ind, W - wt[ind], dp);
  }

  return dp[ind][W] = max(take, notTake);
}
int tabulationSol(vector<int> &wt, vector<int> &val, int n, int w,
                  vector<vector<int>> &dp) {

  for (int W = 0; W <= w; W++) {
    dp[0][W] = ((int)(W / wt[0])) * val[0];
  }

  for (int ind = 1; ind < n; ind++) {
    for (int W = 0; W <= w; W++) {
      int notTake = dp[ind - 1][W];
      int take = 0;
      if (wt[ind] <= W) {
        take = val[ind] + dp[ind][W - wt[ind]];
      }
      dp[ind][W] = max(take, notTake);
    }
  }

  return dp[n - 1][w];
}

int spaceOptimizationSol(vector<int> &wt, vector<int> &val, int n, int w) {
  vector<int> curr(w + 1, 0);
  vector<int> prev(w + 1, 0);
  for (int W = 0; W <= w; W++) {
    prev[W] = ((int)(W / wt[0])) * val[0];
  }

  for (int ind = 1; ind < n; ind++) {
    for (int W = 0; W <= w; W++) {
      int notTake = prev[W];
      int take = 0;
      if (wt[ind] <= W) {
        take = val[ind] + curr[W - wt[ind]];
      }
      curr[W] = max(take, notTake);
    }
    prev = curr;
  }

  return prev[w];
}
int spaceOptimizationSol1DArray(vector<int> &wt, vector<int> &val, int n,
                                int w) {
  vector<int> prev(w + 1, 0);
  for (int W = 0; W <= w; W++) {
    prev[W] = ((int)(W / wt[0])) * val[0];
  }

  for (int ind = 1; ind < n; ind++) {
    for (int W = 0; W <= w; W++) {
      int notTake = prev[W];
      int take = 0;
      if (wt[ind] <= W) {
        take = val[ind] + prev[W - wt[ind]];
      }
      prev[W] = max(take, notTake);
    }
  }

  return prev[w];
}

int unboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int W) {

  // 1. Recursion
  int ans1 = recursionSol(wt, val, n - 1, W);

  // 2. Memoization
  vector<vector<int>> dp(n, vector<int>(W + 1, -1));

  int ans2 = memoizationSol(wt, val, n - 1, W, dp);

  // 3. Tabulation
  vector<vector<int>> dp2(n, vector<int>(W + 1, 0));

  int ans3 = tabulationSol(wt, val, n, W, dp2);

  // 4. Space Optimization - 2 Arrays
  int ans4 = spaceOptimizationSol(wt, val, n, W);

  // 5. Space Optimization - 1 Array
  int ans5 = spaceOptimizationSol1DArray(wt, val, n, W);

  // Print all answers
  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization (2 Arrays): " << ans4 << endl;
  cout << "Space Optimization (1 Array): " << ans5 << endl;

  return ans5;
}

// | Approach                 | Time Complexity | Space Complexity          |
// | ------------------------ | --------------- | ------------------------- |
// | Recursion                | Exponential     | O(N + W) stack            |
// | Memoization              | O(N × W)        | O(N × W) + O(N + W) stack |
// | Tabulation               | O(N × W)        | O(N × W)                  |
// | Space Optimization - 2D  | O(N × W)        | O(W)                      |
// | Space Optimization - 1D  | O(N × W)        | O(W)                      |

int main() {

  cout << "23 DP 23 Unbounded Knapsack" << endl;
  // Given two integer arrays, val and wt, each of size N, representing the
  // values and weights of N items respectively, and an integer W, representing
  // the maximum capacity of a knapsack, determine the maximum value achievable
  // by selecting a subset of the items such that the total weight of the
  // selected items does not exceed the knapsack capacity W. The goal is to
  // maximize the sum of the values of the selected items while keeping the
  // total weight within the knapsack's capacity.

  // An infinite supply of each item can be assumed.

  // Example 1

  // Input: val = [5, 11, 13], wt = [2, 4, 6], W = 10

  // Output: 27

  // Explanation: Select 2 items with weights 4 and 1 item with weight 2 for a
  // total value of 11+11+5 = 27.
  vector<int> wt = {2, 4, 6};
  vector<int> val = {5, 11, 13};

  int n = wt.size();
  int W = 10;

  cout << "Weight Capacity: " << W << endl;

  int answer = unboundedKnapsack(wt, val, n, W);

  cout << "Maximum Value: " << answer << endl;

  return 0;
}
