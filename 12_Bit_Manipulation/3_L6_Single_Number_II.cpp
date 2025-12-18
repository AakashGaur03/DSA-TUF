#include <bits/stdc++.h>
using namespace std;
int singleNumber2Brute(vector<int> nums) {
  // TC O(n log m) + O(m)
  // SC O(m)
  // m = n / 3 + 1;
  map<int, int> mpp;
  for (int i = 0; i < nums.size(); i++) {
    mpp[nums[i]]++;
  }
  for (auto it : mpp) {
    if (it.second == 1) {
      return it.first;
    }
  }
  return 0;
}
int singleNumber2Optimal(vector<int> nums) {
  // Basically we will count the number of set bits in each index
  //  Acc to that if multiple of 3 we dont take
  //  if not multiple of 3 we take 3_L6_Single_Number_II_1
  //  Refer to
}
int main() {
  cout << "4 L6 Single Number II" << endl;
  // Every Number will be appearing Thrice Find Out Number Apprearing Once

  vector<int> nums = {4, 2, 1, 1, 2, 1, 2};
  int res = singleNumber2Brute(nums);
  cout << res;
  int res2 = singleNumber2Optimal(nums);
  cout << res2;
  return 0;
}
