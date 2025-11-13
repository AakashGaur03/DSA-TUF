#include <bits/stdc++.h>
using namespace std;

void findCombinations(int index, vector<int> arr, int target, vector<int> ds,
                      vector<vector<int>> &ans) {
  // TC O(2^t *k)
  // t is target and k is average length
  // SC O(k*x) x is combinations // Hypothetical
  // Depends on number of combinations

  if (index == arr.size()) {
    if (target == 0) {
      ans.push_back(ds);
    }
    return;
  }
  // Pick the Element (if Doesnt exceeds)
  if (arr[index] <= target) {
    ds.push_back(arr[index]);
    findCombinations(index, arr, target - arr[index], ds, ans);
    ds.pop_back();
  }
  // Not Pick
  findCombinations(index + 1, arr, target, ds, ans);
}

int main() {
  cout << "10 L8 Combination Sum" << endl;
  // In here it is different from Subsequence
  // AS it is saying Combination Sum so single element can be picked
  // multiple times
  vector<int> arr = {2, 3, 6, 7};
  int target = 7;
  vector<int> ds;
  vector<vector<int>> ans;

  findCombinations(0, arr, target, ds, ans);

  for (auto &comb : ans) {
    for (auto it : comb)
      cout << it << " ";
    cout << endl;
  }

  return 0;
}
