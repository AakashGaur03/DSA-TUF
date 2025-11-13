#include <bits/stdc++.h>
using namespace std;

void optimalFindCombinations(int index, int target, vector<int> &arr,
                             vector<vector<int>> &ans, vector<int> &ds) {
  // TC O(2^n *k)
  // k is average length of every combination
  // SC O(k*x) x is combinations // Hypothetical

  if (target == 0) {
    ans.push_back(ds);
    return;
  }

  for (int i = index; i < arr.size(); i++) {
    if (i > index && arr[i] == arr[i - 1]) {
      // Means when we are at 1 we can only pick 2 3 4 5
      // when at 2 then 3 4 5 ...
      // and also starting index cant be same so arr[i] == arr[i-1]
      continue;
    }
    if (arr[i] > target) {
      break;
    }
    ds.push_back(arr[i]);
    optimalFindCombinations(i + 1, target - arr[i], arr, ans, ds);
    // Not index + 1 , i+1 because we have to try for all of the loop
    ds.pop_back();
    // When recursion going back then we need to remove this element
  }
}
int main() {
  cout << "11 L9 Combination Sum II" << endl;
  // In here it is different from Combination Sum
  // AS it is saying Combination Sum so single element can be picked
  // multiple times
  // But it is slightly Advanced Problem
  // We need to find all unique Combinations
  // Each Number can only be used once
  // The Solution must not contain duplicate combinations
  // Combinations should be in Sorted order

  // 1 1 2 5 6 7 10

  // Answers will be
  // [
  //   [ 1, 1, 6 ],
  //   [ 1, 2, 5 ],
  //   [ 1, 7 ],
  //   [ 2, 6 ]
  //   ]

  // EX [1,1,1,2,2]
  // ANS
  // 1, 1, 2
  // 2,2

  // 1 2 1 is not valid answer as we already have 1 1 2

  // Optimal
  //  PICK SUBSEQUENCES

  vector<int> arr = {1, 1, 1, 2, 2};
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  vector<int> ds;
  int target = 4;
  optimalFindCombinations(0, target, arr, ans, ds);
  for (auto &comb : ans) {
    for (auto it : comb)
      cout << it << " ";
    cout << endl;
  }

  return 0;
}
