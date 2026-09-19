
#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
  // TC O(N)
  // SC O(1)

  int mini = prices[0];
  int maxProfit = 0;
  int n = prices.size();
  for (int i = 1; i < n; i++) {
    int cost = prices[i] - mini;
    maxProfit = max(maxProfit, cost);
    mini = min(mini, prices[i]);
  }
  return maxProfit;
}

// This Problem comes in DP cause here mini  = min(mini,prices[i]) remembers the
// past

int main() {
  cout << "35 DP 35 Best Time to Buy and Sell Stock" << endl;
  // Problem Statement: We are given an array Arr[] of length n. It represents
  // the price of a stock on ‘n’ days. The following guidelines need to be
  // followed:

  // 1.We can buy and sell a stock only once.
  // 2.We can buy and sell the stock on any day but to sell the stock, we need
  // to first buy it on the same or any previous day.

  // We need to tell the maximum profit one can get by buying and selling this
  // stock.

  // Examples
  // Input : prices = [7, 1, 5, 3, 6, 4]
  // Output :5
  // Explanation :Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
  // = 6 - 1 = 5.We cannot sell before we buy, so profit is not 7 - 1 = 6.

  // Input :prices = [7, 6, 4, 3, 1]
  // Output :0
  // Explanation :No transaction is done, as the price keeps falling every day.
  // So, profit = 0.

  vector<int> prices = {7, 1, 5, 3, 6, 4};

  cout << "Maximum Profit: " << maximumProfit(prices) << endl;

  return 0;
}
