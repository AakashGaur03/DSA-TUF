
#include <bits/stdc++.h>
using namespace std;

int recursionSol(int ind, int canBuy, vector<int> &values, int n,
                 int transactionCap) {
  if (ind == n) {
    return 0;
  }
  if (transactionCap == 0) {
    return 0;
  }
  int profit = 0;
  if (canBuy) {
    int buy =
        -values[ind] + recursionSol(ind + 1, 0, values, n, transactionCap);
    int notBuy = 0 + recursionSol(ind + 1, 1, values, n, transactionCap);
    profit = max(buy, notBuy);
  } else {
    int sell =
        values[ind] + recursionSol(ind + 1, 1, values, n, transactionCap - 1);
    int notSell = 0 + recursionSol(ind + 1, 0, values, n, transactionCap);
    profit = max(sell, notSell);
  }

  return profit;
}

int memoizationSol(int ind, int canBuy, vector<int> &values, int n,
                   vector<vector<vector<int>>> &dp, int transactionCap) {
  if (ind == n) {
    return 0;
  }
  if (transactionCap == 0) {
    return 0;
  }

  if (dp[ind][canBuy][transactionCap] != -1) {
    return dp[ind][canBuy][transactionCap];
  }

  int profit = 0;
  if (canBuy) {
    int buy = -values[ind] +
              memoizationSol(ind + 1, 0, values, n, dp, transactionCap);
    int notBuy = 0 + memoizationSol(ind + 1, 1, values, n, dp, transactionCap);
    profit = max(buy, notBuy);
  } else {
    int sell = values[ind] +
               memoizationSol(ind + 1, 1, values, n, dp, transactionCap - 1);
    int notSell = 0 + memoizationSol(ind + 1, 0, values, n, dp, transactionCap);
    profit = max(sell, notSell);
  }

  return dp[ind][canBuy][transactionCap] = profit;
}

int tabulationSol(vector<int> &values, int n, int k,
                  vector<vector<vector<int>>> &dp) {

  // cap == 0
  for (int ind = 0; ind < n; ind++) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      dp[ind][canBuy][0] = 0;
    }
  }
  // ind == n
  for (int canBuy = 0; canBuy <= 1; canBuy++) {
    for (int transactionCap = 0; transactionCap <= k; transactionCap++) {
      dp[n][canBuy][transactionCap] = 0;
    }
  }

  int profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      for (int transactionCap = 1; transactionCap <= k; transactionCap++) {

        if (canBuy) {
          int buy = -values[ind] + dp[ind + 1][0][transactionCap];
          int notBuy = 0 + dp[ind + 1][1][transactionCap];
          profit = max(buy, notBuy);
        } else {
          int sell = values[ind] + dp[ind + 1][1][transactionCap - 1];
          int notSell = 0 + dp[ind + 1][0][transactionCap];
          profit = max(sell, notSell);
        }
        dp[ind][canBuy][transactionCap] = profit;
      }
    }
  }
  return dp[0][1][k];
}

int spaceOptimized(vector<int> &values, int n, int k) {

  vector<vector<int>> after(2, vector<int>(k + 1, 0));
  vector<vector<int>> curr(2, vector<int>(k + 1, 0));

  int profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      for (int transactionCap = 1; transactionCap <= k; transactionCap++) {

        if (canBuy) {
          int buy = -values[ind] + after[0][transactionCap];
          int notBuy = 0 + after[1][transactionCap];
          profit = max(buy, notBuy);
        } else {
          int sell = values[ind] + after[1][transactionCap - 1];
          int notSell = 0 + after[0][transactionCap];
          profit = max(sell, notSell);
        }
        curr[canBuy][transactionCap] = profit;
      }
    }
    after = curr;
  }
  return after[1][k];
}

int getMaximumProfit(vector<int> &Arr, int n, int k) {
  // Only K transaction can be Used

  // Recursion
  int ans1 = recursionSol(0, 1, Arr, n, k);

  // Memoization
  vector<vector<vector<int>>> dp(
      n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

  int ans2 = memoizationSol(0, 1, Arr, n, dp, k);

  // Tabulation
  vector<vector<vector<int>>> dp2(
      n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

  int ans3 = tabulationSol(Arr, n, k, dp2);

  // Space Optimization
  int ans4 = spaceOptimized(Arr, n, k);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return ans4;
}

// | Approach           |                Time |                       Space |
// | ------------------ | ------------------: | --------------------------: |
// | Recursion          |              O(2^N) |        O(N) recursion stack |
// | Memoization        | O(N × 2 × 2) → O(N) | O(N × 2 × 2) + stack → O(N) |
// | Tabulation         | O(N × 2 × 2) → O(N) |         O(N × 2 × 2) → O(N) |
// | Space Optimization | O(N × 2 × 2) → O(N) |             O(2 × 2) → O(1) |

int main() {
  cout << "38 DP 38 Buy and Sell Stock IV" << endl;

  //   Best time to buy and sell stock IV
  // Given an array, arr, of n integers, where arr[i] represents the price of
  // the stock on an ith day, determine the maximum profit achievable by
  // completing at most k transactions in total. Holding at most one share of
  // the stock at any given time is allowed, meaning buying and selling the
  // stock k times is permitted, but the stock must be sold before buying it
  // again. Buying and selling the stock on the same day is allowed.

  // Example 1:
  // Input: arr = [3, 2, 6, 5, 0, 3], k = 2

  // Output: 7

  // Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
  // = 6 - 2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
  // profit = 3 - 0 = 3. Total profit is 4 + 3 = 7.

  // Example 2:
  // Input: arr = [1, 2, 4, 2, 5, 7, 2, 4, 9, 0], k = 3

  // Output: 15

  // Explanation: Buy on day 1 (price = 1) and sell on day 3 (price = 4), profit
  // = 4 - 1 = 3. Then buy on day 4 (price = 2) and sell on day 6 (price = 7),
  // profit = 7 - 2 = 5. Then buy on day 7 (price = 2) and sell on day 9 (price
  // = 9), profit = 9 - 2 = 7. Total profit is 3 + 5 + 7 = 15.

  int n = 6;

  vector<int> arr = {4, 2, 7, 1, 11, 5};
  int k = 4;
  int ans = getMaximumProfit(arr, n, k);

  cout << "Maximum Profit: " << ans << endl;

  return 0;
}
