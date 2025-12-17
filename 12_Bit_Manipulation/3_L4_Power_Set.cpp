#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "3 L4 Power Set Print All Subsets" << endl;
  // TC O(2^n * n)
  // SC O(2^n * n) approx
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans;

  // Total Number of Subsets are 2^n
  // 2 ki power n

  // That is equal to 1 << n
  int subsets = pow(2, nums.size());
  for (int i = 0; i < subsets; i++) {
    vector<int> list;
    for (int j = 0; j < nums.size(); j++) {
      if (i & (1 << j)) {
        list.push_back(nums[j]);
      }
    }
    ans.push_back(list);
  }

  for (auto &v : ans) {
    cout << "{ ";
    for (int x : v)
      cout << x << " ";
    cout << "}\n";
  }
  return 0;
}
