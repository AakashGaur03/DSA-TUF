#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> nums) {
  // TC O(N)
  int res = 0;
  //   a ^ a = 0 → same numbers cancel out
  // a ^ 0 = a → XOR with 0 gives the number back
  for (int i = 0; i < nums.size(); i++) {
    res ^= nums[i];
  }
  return res;
}

int main() {
  cout << "4 L5 Single Number" << endl;
  // Every Number will be appearing Twice Find Out Number Apprearing Once

  vector<int> nums = {4, 1, 2, 1, 2};
  int res = singleNumber(nums);
  cout << res;
  return 0;
}
