
#include <bits/stdc++.h>
using namespace std;

long recursionSol(int ind, int canBuy, vector<long> &values, int n, int fee) {
  if (ind == n) {
    return 0;
  }
  long profit = 0;
  if (canBuy) {
    long buy = -values[ind] - fee + recursionSol(ind + 1, 0, values, n, fee);
    long notBuy = 0 + recursionSol(ind + 1, 1, values, n, fee);
    profit = max(buy, notBuy);
  } else {
    long sell = values[ind] + recursionSol(ind + 1, 1, values, n, fee);
    long notSell = 0 + recursionSol(ind + 1, 0, values, n, fee);
    profit = max(sell, notSell);
  }

  return profit;
}

long memoizationSol(int ind, int canBuy, vector<long> &values, int n,
                    vector<vector<long>> &dp, int fee) {
  if (ind == n) {
    return 0;
  }

  if (dp[ind][canBuy] != -1) {
    return dp[ind][canBuy];
  }

  long profit = 0;
  if (canBuy) {
    long buy =
        -values[ind] - fee + memoizationSol(ind + 1, 0, values, n, dp, fee);
    long notBuy = 0 + memoizationSol(ind + 1, 1, values, n, dp, fee);
    profit = max(buy, notBuy);
  } else {
    long sell = values[ind] + memoizationSol(ind + 1, 1, values, n, dp, fee);
    long notSell = 0 + memoizationSol(ind + 1, 0, values, n, dp, fee);
    profit = max(sell, notSell);
  }

  return dp[ind][canBuy] = profit;
}

long tabulationSol(vector<long> &values, int n, vector<vector<long>> &dp,
                   int fee) {

  dp[n][0] = dp[n][1] = 0;

  long profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      if (canBuy) {
        long buy = -values[ind] - fee + dp[ind + 1][0];
        long notBuy = 0 + dp[ind + 1][1];
        profit = max(buy, notBuy);
      } else {
        long sell = values[ind] + dp[ind + 1][1];
        long notSell = 0 + dp[ind + 1][0];
        profit = max(sell, notSell);
      }
      dp[ind][canBuy] = profit;
    }
  }
  return dp[0][1];
}

long spaceOptimized(vector<long> &values, int n, int fee) {

  vector<long> ahead(2, 0);
  vector<long> curr(2, 0);
  ahead[0] = ahead[1] = 0;

  long profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      if (canBuy) {
        long buy = -values[ind] - fee + ahead[0];
        long notBuy = 0 + ahead[1];
        profit = max(buy, notBuy);
      } else {
        long sell = values[ind] + ahead[1];
        long notSell = 0 + ahead[0];
        profit = max(sell, notSell);
      }
      curr[canBuy] = profit;
    }
    ahead = curr;
  }
  return ahead[1];
}

long spaceOptimized2ndApproach(vector<long> &values, int n, int fee) {

  long aheadNotBuy, aheadBuy, currBuy, currNotBuy;

  aheadNotBuy = aheadBuy = 0;

  for (int ind = n - 1; ind >= 0; ind--) {

    // canBuy = 1
    long buy = -values[ind] - fee + aheadNotBuy;
    long notBuy = aheadBuy;

    currBuy = max(buy, notBuy);

    // canBuy = 0
    long sell = values[ind] + aheadBuy;
    long notSell = aheadNotBuy;

    currNotBuy = max(sell, notSell);

    aheadBuy = currBuy;
    aheadNotBuy = currNotBuy;
  }

  return aheadBuy;
}
long getMaximumProfit(vector<long> &Arr, int n) {
  int fee = 2;
  // Recursion
  long ans1 = recursionSol(0, 1, Arr, n, fee);

  // Memoization
  vector<vector<long>> dp(n, vector<long>(2, -1));
  long ans2 = memoizationSol(0, 1, Arr, n, dp, fee);

  // Tabulation
  vector<vector<long>> dp2(n + 1, vector<long>(2, 0));
  long ans3 = tabulationSol(Arr, n, dp2, fee);

  // Space Optimization
  long ans4 = spaceOptimized(Arr, n, fee);

  // Space Optimization - 2nd Approach
  long ans5 = spaceOptimized2ndApproach(Arr, n, fee);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;
  cout << "Space Optimization 2nd Approach: " << ans5 << endl;

  return ans5;
}

// | Approach                |                Time |                  Space |
// | ----------------------- | ------------------: | ---------------------: |
// | Recursion               |             O(2^N)  |  O(N) recursion stack |
// | Memoization             |  O(N × 2) → O(N)    |  O(N × 2) + stack     |
// | Tabulation              |  O(N × 2) → O(N)    |  O(N × 2)             |
// | Space Optimization      |  O(N × 2) → O(N)    |  O(2) → O(1)          |
// | Space Optimization 2nd  |  O(N × 2) → O(N)    |  O(1)                 |

int main() {

  cout << "40 DP 40 Buy and Sell Stocks With Transaction Fee" << endl;

  // Similar to 36_DP_36_Buy_and_Sell_Stock_II with slight Updations

  //   You are given an array prices where prices[i] is the price of a given
  //   stock on the ith day, and an integer fee representing a transaction fee.

  // Find the maximum profit you can achieve. You may complete as many
  // transactions as you like, but you need to pay the transaction fee for each
  // transaction.

  // Note:

  // You may not engage in multiple transactions simultaneously (i.e., you must
  // sell the stock before you buy again). The transaction fee is only charged
  // once for each stock purchase and sale.

  // Example 1:

  // Input: prices = [1,3,2,8,4,9], fee = 2
  // Output: 8
  // Explanation: The maximum profit can be achieved by:
  // - Buying at prices[0] = 1
  // - Selling at prices[3] = 8
  // - Buying at prices[4] = 4
  // - Selling at prices[5] = 9
  // The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
  // Example 2:

  // Input: prices = [1,3,7,5,10,3], fee = 3
  // Output: 6

  // Example 1
  vector<long> prices1 = {1, 3, 2, 8, 4, 9};

  long ans1 = getMaximumProfit(prices1, prices1.size());

  cout << "--------------------------------" << endl;
  cout << "Example 1" << endl;

  cout << "Prices: ";

  for (long price : prices1) {
    cout << price << " ";
  }

  cout << endl;
  cout << "Fee: 2" << endl;
  cout << "Maximum Profit: " << ans1 << endl;

  // Example 2:
  // prices = [1,3,7,5,10,3]
  // fee = 3
  // Output = 6

  vector<long> prices2 = {1, 3, 7, 5, 10, 3};

  long ans2 = getMaximumProfit(prices2, prices2.size());

  cout << "--------------------------------" << endl;
  cout << "Example 2" << endl;

  cout << "Prices: ";

  for (long price : prices2) {
    cout << price << " ";
  }

  cout << endl;
  cout << "Fee: 2" << endl;
  cout << "Maximum Profit: " << ans2 << endl;

  return 0;
}