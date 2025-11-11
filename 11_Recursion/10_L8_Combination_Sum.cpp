#include <bits/stdc++.h>
using namespace std;

void printCombinationSum(vector<int> arr, int target, int index, vector<int> ds,
                         int sum) {
  // TC O(2^t *k)
  // t is target and k is average length
  // SC O(k*x) x is combinations // Hypothetical
  // Depends on number of combinations
  int n = arr.size();
  if (sum == target) {
    for (auto it : ds) {
      cout << it << " ";
    }
    cout << endl;
    return;
  }
  if (index == arr.size() || sum > target) {
    return;
  }

  // Pick
  ds.push_back(arr[index]);
  sum += arr[index];
  printCombinationSum(arr, target, index, ds, sum);
  // Not Pick
  ds.pop_back();
  sum -= arr[index];
  printCombinationSum(arr, target, index + 1, ds, sum);
}

int main() {
  cout << "10 L8 Combination Sum" << endl;
  // In here it is different from Subsequence
  // AS it is saying Combination Sum so single element can be picked
  // multiple times
  vector<int> arr = {2, 3, 6, 7};
  int target = 7;
  vector<int> ds;

  printCombinationSum(arr, target, 0, ds, 0);

  return 0;
}
