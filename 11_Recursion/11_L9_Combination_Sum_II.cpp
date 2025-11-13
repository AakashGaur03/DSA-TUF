#include <bits/stdc++.h>
using namespace std;

// BRUTE APPROACH SIMILAR TO COMBINATION SUM
// CHANGES MADE ARE
// 1-> WE TOOK SET TO REMOVE DUPLICATES
// 2-> IN PICK ELEMENT TOO WE TOOK NEXT INDEX NOT THE SAME  ONE
void findCombinations(int index, vector<int> arr, int target, vector<int> ds,
                      set<vector<int>> &ansSet) {
  // BRUTE FORCE
  // TC O(2^t *k * log N)
  // t is target and k is average length
  // and Here it is K log N because we are using Set
  // SC O(k*x) x is combinations // Hypothetical
  // Depends on number of combinations

  if (index == arr.size()) {
    if (target == 0) {
      ansSet.insert(ds);
    }
    return;
  }
  // Pick the Element (if Doesnt exceeds)
  if (arr[index] <= target) {
    ds.push_back(arr[index]);
    findCombinations(index + 1, arr, target - arr[index], ds, ansSet);
    ds.pop_back();
  }
  // Not Pick
  findCombinations(index + 1, arr, target, ds, ansSet);
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
  vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  vector<int> ds;
  set<vector<int>> ansSet;
  sort(arr.begin(), arr.end());
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

  findCombinations(0, arr, target, ds, ansSet);
  vector<vector<int>> ans(ansSet.begin(), ansSet.end());
  for (auto &comb : ans) {
    for (auto it : comb)
      cout << it << " ";
    cout << endl;
  }

  return 0;
}

// vector<vector<int>> ans(ansSet.begin(), ansSet.end());
// internally doing
// for (auto it = ansSet.begin(); it != ansSet.end(); ++it) {
//     ans.push_back(*it);
// }

// it is an iterator object —
// It doesn’t directly hold the value, it points to an element inside the set.
// So if you write:
// cout << it;
// that’s invalid — because it is not the element itself.
// You must dereference it using * to access the actual element (the combination
// vector)
