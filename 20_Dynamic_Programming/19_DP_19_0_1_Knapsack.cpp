#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, int bagWt, vector<int> &wt, vector<int> &val) {

  // Base Case
  if (ind == 0) {

    if (wt[0] <= bagWt) {
      return val[0];
    }

    return 0;
  }

  // Don't Pick
  int notPick = recursionSol(ind - 1, bagWt, wt, val);

  // Pick
  int pick = INT_MIN;

  if (wt[ind] <= bagWt) {
    pick = val[ind] + recursionSol(ind - 1, bagWt - wt[ind], wt, val);
  }

  return max(pick, notPick);
}

int memoizationSol(int ind, int bagWt, vector<int> &wt, vector<int> &val,
                   vector<vector<int>> &dp) {

  // Base Case
  if (ind == 0) {

    if (wt[0] <= bagWt) {
      return val[0];
    }

    return 0;
  }

  // Already calculated
  if (dp[ind][bagWt] != -1) {
    return dp[ind][bagWt];
  }

  // Don't Pick
  int notPick = memoizationSol(ind - 1, bagWt, wt, val, dp);

  // Pick
  int pick = INT_MIN;

  if (wt[ind] <= bagWt) {
    pick = val[ind] + memoizationSol(ind - 1, bagWt - wt[ind], wt, val, dp);
  }

  return dp[ind][bagWt] = max(pick, notPick);
}

int tabulationSol(int n, int bagWt, vector<int> &wt, vector<int> &val,
                  vector<vector<int>> &dp) {

  // Base Case
  for (int W = wt[0]; W <= bagWt; W++) {
    dp[0][W] = val[0];
  }

  // Fill DP table
  for (int ind = 1; ind < n; ind++) {

    for (int W = 0; W <= bagWt; W++) {

      // Don't Pick
      int notPick = dp[ind - 1][W];

      // Pick
      int pick = INT_MIN;

      if (wt[ind] <= W) {
        pick = val[ind] + dp[ind - 1][W - wt[ind]];
      }

      dp[ind][W] = max(pick, notPick);
    }
  }

  return dp[n - 1][bagWt];
}

int spaceOptimizedSol(int n, int bagWt, vector<int> &wt, vector<int> &val) {

  vector<int> prev(bagWt + 1, 0);
  vector<int> curr(bagWt + 1, 0);

  // Base Case
  for (int W = wt[0]; W <= bagWt; W++) {
    prev[W] = val[0];
  }

  for (int ind = 1; ind < n; ind++) {

    for (int W = 0; W <= bagWt; W++) {

      // Don't Pick
      int notPick = prev[W];

      // Pick
      int pick = INT_MIN;

      if (wt[ind] <= W) {
        pick = val[ind] + prev[W - wt[ind]];
      }

      curr[W] = max(pick, notPick);
    }

    prev = curr;
  }

  return prev[bagWt];
}

int spaceOptimizedSol2(int n, int bagWt, vector<int> &wt, vector<int> &val) {

  vector<int> prev(bagWt + 1, 0);

  // Base Case
  for (int W = wt[0]; W <= bagWt; W++) {
    prev[W] = val[0];
  }

  // Single array optimization
  for (int ind = 1; ind < n; ind++) {

    // Traverse from RIGHT to LEFT
    for (int W = bagWt; W >= 0; W--) {

      // Don't Pick
      int notPick = prev[W];

      // Pick
      int pick = INT_MIN;

      if (wt[ind] <= W) {
        pick = val[ind] + prev[W - wt[ind]];
      }

      prev[W] = max(pick, notPick);
    }
  }

  return prev[bagWt];
}

/*
| Approach        |       Time |       Space |
| --------------- | ----------:| -----------:|
| Recursion       |    O(2^N)  |  O(N) stack |
| Memoization     |   O(N × W) |  O(N × W)   |
| Tabulation      |   O(N × W) |  O(N × W)   |
| Space Optimized |   O(N × W) |     O(W)    |
| Single Array    |   O(N × W) |     O(W)    |
*/

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {

  // Recursion
  int ans1 = recursionSol(n - 1, w, weights, values);

  // Memoization
  vector<vector<int>> dp(n, vector<int>(w + 1, -1));

  int ans2 = memoizationSol(n - 1, w, weights, values, dp);

  // Tabulation
  vector<vector<int>> dp2(n, vector<int>(w + 1, 0));

  int ans3 = tabulationSol(n, w, weights, values, dp2);

  // Space Optimization
  int ans4 = spaceOptimizedSol(n, w, weights, values);

  // Single Array Space Optimization
  int ans5 = spaceOptimizedSol2(n, w, weights, values);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  cout << "Single Array: " << ans5 << endl;

  return ans5;
}

int main() {

  cout << "19 DP 19 0/1 Knapsack | Recursion to Single Array Space Optimised "
          "Approach | DP on Subsequences"
       << endl;
  // Problem statement
  // A thief is robbing a store and can carry a maximum weight of ‘W’ into his
  // knapsack. There are 'N' items available in the store and the weight and
  // value of each item is known to the thief. Considering the constraints of
  // the maximum weight that a knapsack can carry, you have to find the maximum
  // profit that a thief can generate by stealing items.

  // Note: The thief is not allowed to break the items.

  // For example, N = 4, W = 10 and the weights and values of items are weights
  // = [6, 1, 5, 3] and values = [3, 6, 1, 4]. Then the best way to fill the
  // knapsack is to choose items with weight 6, 1 and 3. The total value of
  // knapsack = 3 + 6 + 4 = 13.

  // Problem:
  //
  // N = 4
  // W = 10
  //
  // weights = [6, 1, 5, 3]
  // values  = [3, 6, 1, 4]
  //
  // Best choice:
  //
  // weight = 6 + 1 + 3 = 10
  // value  = 3 + 6 + 4 = 13

  vector<int> weights = {6, 1, 5, 3};
  vector<int> values = {3, 6, 1, 4};

  int n = weights.size();
  int W = 10;

  int ans = maxProfit(values, weights, n, W);

  cout << "Final Answer: " << ans << endl;

  return 0;
}

int spaceOptimizedSolSingleArray(int n, int bagWt, vector<int> &wt,
                                 vector<int> &val) {

  // ------------------------------------------------------------
  // Single Array Space Optimization
  // ------------------------------------------------------------
  //
  // In the 2-array approach we have:
  //
  //     prev[W] = answer using previous items
  //     curr[W] = answer using current item
  //
  // But while calculating curr[W], we only need values from
  // the previous row:
  //
  //     notPick = prev[W]
  //     pick    = val[ind] + prev[W - wt[ind]]
  //
  // Therefore, we don't actually need a separate curr array.
  //
  // We can update prev[] itself.
  //
  // BUT there is one important condition:
  //
  // We MUST traverse W from RIGHT -> LEFT.
  //
  // ------------------------------------------------------------

  vector<int> prev(bagWt + 1, 0);

  // Base Case:
  //
  // Using only the first item (index 0):
  //
  // If the current capacity W can accommodate item 0,
  // then we can take its value.
  //
  // For W < wt[0], answer remains 0.
  //
  for (int W = wt[0]; W <= bagWt; W++) {
    prev[W] = val[0];
  }

  // Process remaining items
  for (int ind = 1; ind < n; ind++) {

    // IMPORTANT:
    // Traverse capacity from RIGHT -> LEFT.
    //
    // Why?
    //
    // For 0/1 Knapsack, every item can be used ONLY ONCE.
    //
    // When calculating:
    //
    //     prev[W - wt[ind]]
    //
    // we need the value from the PREVIOUS ROW.
    //
    // Since we are updating the same array, if we traverse
    // from LEFT -> RIGHT, prev[W - wt[ind]] may already have
    // been updated using the CURRENT item.
    //
    // That would allow us to use the same item multiple times.
    //
    // RIGHT -> LEFT prevents this.
    //
    for (int W = bagWt; W >= 0; W--) {

      // Don't Pick the current item.
      //
      // Keep the answer that was already present for
      // this capacity.
      int notPick = prev[W];

      // Pick the current item.
      int pick = INT_MIN;

      if (wt[ind] <= W) {

        // IMPORTANT:
        //
        // prev[W - wt[ind]] is still the OLD value
        // because we are moving from right to left.
        //
        // Therefore it represents the answer using
        // previous items only.
        //
        // This guarantees that the current item is
        // NOT used again.
        pick = val[ind] + prev[W - wt[ind]];
      }

      // Store the best choice directly in prev[].
      prev[W] = max(pick, notPick);
    }
  }

  return prev[bagWt];
}