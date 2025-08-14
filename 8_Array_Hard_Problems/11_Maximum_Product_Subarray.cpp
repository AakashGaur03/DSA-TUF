#include <bits/stdc++.h>
using namespace std;

long long bruteMaximumSubArray(vector<int> arr, int size) {
  // TC O(N^2)
  // SC O(1)
  long long maxProduct = LLONG_MIN;

  for (int i = 0; i < size; i++) {
    long long product = 1;
    for (int j = i; j < size; j++) {
      product *= arr[j];
      maxProduct = max(maxProduct, product);
    }
  }

  return maxProduct;
}

int optimalMaximumSubArray(vector<int> arr, int size) {
  // TC O(N)
  // SC O(1)

  // prefix: product from left to right
  // suffix: product from right to left
  int prefix = 1;
  int suffix = 1;
  int ans = INT_MIN;
  for (int i = 0; i < size; i++) {
    // Reset prefix if it becomes 0 (because multiplying further will always
    // give 0)
    if (prefix == 0)
      prefix = 1;

    // Reset suffix if it becomes 0
    if (suffix == 0)
      suffix = 1;

    // Multiply prefix with element from left
    prefix *= arr[i];

    // Multiply suffix with element from right
    suffix *= arr[size - i - 1];

    // Update max product using both directions
    ans = max(ans, max(prefix, suffix));
  }
  return ans;
}

int main() {
  cout << "11 Maximum Product Sub array" << endl;
  // Which Subarray gives maximum Product
  vector<int> arr = {2, 3, -2, 4};
  long long res = bruteMaximumSubArray(arr, arr.size());
  cout << res << endl;

  // If all are Positive
  // If even Positive and even Negatives
  // If odd Negatives
  // If Zero Present

  int res2 = optimalMaximumSubArray(arr, arr.size());
  cout << res2 << endl;
  return 0;
}