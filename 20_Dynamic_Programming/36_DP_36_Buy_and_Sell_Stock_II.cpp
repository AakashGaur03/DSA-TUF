
#include <bits/stdc++.h>
using namespace std;

long recursionSol(int ind, int canBuy, vector<long> &values, int n) {
  if (ind == n) {
    return 0;
  }
  long profit = 0;
  if (canBuy) {
    long buy = -values[ind] + recursionSol(ind + 1, 0, values, n);
    long notBuy = 0 + recursionSol(ind + 1, 1, values, n);
    profit = max(buy, notBuy);
  } else {
    long sell = values[ind] + recursionSol(ind + 1, 1, values, n);
    long notSell = 0 + recursionSol(ind + 1, 0, values, n);
    profit = max(sell, notSell);
  }

  return profit;
}

long memoizationSol(int ind, int canBuy, vector<long> &values, int n,
                    vector<vector<long>> &dp) {
  if (ind == n) {
    return 0;
  }

  if (dp[ind][canBuy] != -1) {
    return dp[ind][canBuy];
  }

  long profit = 0;
  if (canBuy) {
    long buy = -values[ind] + memoizationSol(ind + 1, 0, values, n, dp);
    long notBuy = 0 + memoizationSol(ind + 1, 1, values, n, dp);
    profit = max(buy, notBuy);
  } else {
    long sell = values[ind] + memoizationSol(ind + 1, 1, values, n, dp);
    long notSell = 0 + memoizationSol(ind + 1, 0, values, n, dp);
    profit = max(sell, notSell);
  }

  return dp[ind][canBuy] = profit;
}

long tabulationSol(vector<long> &values, int n, vector<vector<long>> &dp) {

  dp[n][0] = dp[n][1] = 0;

  long profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      if (canBuy) {
        long buy = -values[ind] + dp[ind + 1][0];
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

long spaceOptimized(vector<long> &values, int n) {

  vector<long> ahead(2, 0);
  vector<long> curr(2, 0);
  ahead[0] = ahead[1] = 0;

  long profit = 0;

  for (int ind = n - 1; ind >= 0; ind--) {
    for (int canBuy = 0; canBuy <= 1; canBuy++) {
      if (canBuy) {
        long buy = -values[ind] + ahead[0];
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
long spaceOptimized2ndApproach(vector<long> &values, int n) {

  long aheadNotBuy, aheadBuy, currBuy, currNotBuy;

  aheadNotBuy = aheadBuy = 0;

  for (int ind = n - 1; ind >= 0; ind--) {

    // canBuy = 1
    long buy = -values[ind] + aheadNotBuy;
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

  // Recursion
  long ans1 = recursionSol(0, 1, Arr, n);

  // Memoization
  vector<vector<long>> dp(n, vector<long>(2, -1));
  long ans2 = memoizationSol(0, 1, Arr, n, dp);

  // Tabulation
  vector<vector<long>> dp2(n + 1, vector<long>(2, 0));
  long ans3 = tabulationSol(Arr, n, dp2);

  // Space Optimization
  long ans4 = spaceOptimized(Arr, n);

  // Space Optimization - 2nd Approach
  long ans5 = spaceOptimized2ndApproach(Arr, n);

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
  cout << "36 DP 36 Buy and Sell Stock II" << endl;
  // Buy as many times you want and Sell as many times you want
  // NOTE When we Buy so before buying the second time we have first Sell the
  // Stock

  // We are given an array Arr[] of length n. It represents the price of a stock
  // on ‘n’ days. The following guidelines need to be followed:

  // We can buy and sell the stock any number of times.
  // In order to sell the stock, we need to first buy it on the same or any
  // previous day. We can’t buy a stock again after buying it once. In other
  // words, we first buy a stock and then sell it. After selling we can buy and
  // sell again. But we can’t sell before buying and can’t buy before selling
  // any previously bought stock. Example 1:

  // Array={7, 1, 5, 3, 6, 4}
  // N=6
  // MaxProfit=7 as ((5-1) + (6-3))
  // Explaination: Buy the stock on 1st day at price 1 and sell the stock on 2nd
  // day at the price of 5. Then again buy stock at day 3 and sell the stock at
  // 4

  int n = 6;

  vector<long> arr = {7, 1, 5, 3, 6, 4};

  cout << "Maximum Profit: " << getMaximumProfit(arr, n) << endl;
  return 0;
}

// long recursionSol(int ind, int canBuy, long **values, int n) {

//     // Base Case:
//     // If we have reached the end of the array,
//     // there are no more days left to buy or sell.
//     // So, no more profit can be made.
//     if (ind == n) {
//         return 0;
//     }

//     long profit = 0;

//     // canBuy = 1 means:
//     // We are currently NOT holding any stock,
//     // so we are allowed to BUY a stock.
//     if (canBuy) {

//         // Option 1: BUY the stock on the current day.
//         //
//         // Buying costs us values[ind], so we subtract it.
//         // After buying, we cannot buy again until we sell.
//         // Therefore, canBuy becomes 0.
//         long buy =
//             -values[ind] +
//             recursionSol(ind + 1, 0, values, n);

//         // Option 2: DO NOT BUY the stock.
//         //
//         // We simply move to the next day.
//         // Since we still don't own any stock,
//         // canBuy remains 1.
//         long notBuy =
//             recursionSol(ind + 1, 1, values, n);

//         // Choose whichever option gives us more profit.
//         profit = max(buy, notBuy);

//     } else {

//         // canBuy = 0 means:
//         // We are currently holding a stock,
//         // so we cannot buy another stock.
//         // Our choices are SELL or NOT SELL.

//         // Option 1: SELL the stock on the current day.
//         //
//         // Selling gives us values[ind] profit.
//         // After selling, we no longer hold a stock,
//         // so we can buy again.
//         // Therefore, canBuy becomes 1.
//         long sell =
//             values[ind] +
//             recursionSol(ind + 1, 1, values, n);

//         // Option 2: DO NOT SELL the stock.
//         //
//         // We keep holding the stock and move to
//         // the next day.
//         // Therefore, canBuy remains 0.
//         long notSell =
//             recursionSol(ind + 1, 0, values, n);

//         // Choose whichever option gives us more profit.
//         profit = max(sell, notSell);
//     }

//     // Return the maximum profit possible from
//     // the current day and current state.
//     return profit;
// }