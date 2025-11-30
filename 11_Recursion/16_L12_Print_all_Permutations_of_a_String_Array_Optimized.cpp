#include <bits/stdc++.h>
using namespace std;

void printAllPermutation(int index, vector<int> &nums,
                         vector<vector<int>> &ans) {
  int n = nums.size();
  if (index == n) {
    ans.push_back(nums);
    return;
  }
  // index is currently at which we have
  // i is that we have to swap with each element
  for (int i = index; i < n; i++) {
    swap(nums[index], nums[i]);
    printAllPermutation(index + 1, nums, ans);
    swap(nums[index], nums[i]);
  }
}

int main() {
  cout << "16 L13 Print all Permutations of a String Array Optimized" << endl;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans;
  vector<int> ds;

  printAllPermutation(0, nums, ans);
  for (auto &vec : ans) {
    for (int x : vec)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}

// TC O(n! * n)
// SC O(1) not using map even ds
// O(n!) for returning the answer
// Auziliary space O(n) that is depth of Recusrion Stack