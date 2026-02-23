#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
  // Descending Order
  return (double)a[0] / a[1] > (double)b[0] / b[1]; // sort by val/weight
}

double fractionalKnapsack(vector<vector<int>> arr, int capacity) {
  // TC O(N log N + N)
  // SC O(1)
  // We are gonna take time which gives me mex value for 1 weight
  // Unit Mathemetics

  //   Input: val = [100,60,100,200], wt = [20,10,50,50], capacity = 90

  // item 0: 100/20 = 5
  // item 1: 60/10 = 6
  // item 2: 100/50 = 2
  // item 3: 200/50 = 4

  // Sort the array acc to weight
  int size = arr.size();
  sort(arr.begin(), arr.end(), comp);
  double totalVal = 0;

  for (size_t i = 0; i < size; i++) {
    if (arr[i][1] <= capacity) {
      totalVal += arr[i][0];
      capacity -= arr[i][1];
    } else {
      totalVal += ((double)arr[i][0] / arr[i][1]) * capacity;
      break;
    }
  }
  return totalVal;
}

int main() {
  cout << "11 L13 Fractional Knapsack Algorithm" << endl;

  //   You have n items; the i-th item has value val[i] and weight wt[i].
  // A knapsack can carry at most capacity units of weight.
  // You may take any fraction of an item (i.e. split items).
  // Return the maximum total value that can be placed in the knapsack

  //   Input: val = [100,60,100,200], wt = [20,10,50,50], capacity = 90
  // Output: 380

  // Explanation:
  //  • Take item 0 (w=20, v=100)
  //  • Take item 1 (w=10, v=60)
  //  • Take item 3 (w=50, v=200)
  //  • Take 10 weighted data from item 2 (w=10, v=20)
  // Total value = 100 +60 + 200 + 20 = 380
  // Refer 11_L13_Fractional_Knapsack_Algorithm_1
  vector<vector<int>> arr = {{100, 20}, {60, 10}, {100, 50}, {200, 50}};
  int capacity = 90;
  double res = fractionalKnapsack(arr, capacity);
  cout << res << endl;
  return 0;
}
