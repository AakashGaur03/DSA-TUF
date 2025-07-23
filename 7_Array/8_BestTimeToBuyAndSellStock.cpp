#include <bits/stdc++.h>
using namespace std;
int bestTimeTobuyAndSellStock(vector<int> arr, int size) {
  // TC O(N)
  // SC O(1)
  int maxProfit = 0;
  int mini = arr[0];

  for (int i = 0; i < size; i++) {
    int cost = arr[i] - mini;
    maxProfit = max(cost, maxProfit);
    mini = min(mini, arr[i]);
  }

  return maxProfit;
};
int main() {
  cout << "Array 8";
  vector<int> arr = {7, 1, 5, 6, 4};
  int res = bestTimeTobuyAndSellStock(arr, arr.size());
  cout << endl << res;
  return 0;
}
