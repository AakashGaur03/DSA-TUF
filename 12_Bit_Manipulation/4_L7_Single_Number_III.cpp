#include <bits/stdc++.h>
using namespace std;

vector<int> betterSingleNumberIII(vector<int> nums) {
  // We XOR all numbers
  // 2 4 2 14 8 7 7 8

  // 2^2 ^ 7^7 ^ 3^3 ^ 14^4
  // 0   ^  0  ^  0  ^  10

  // Now we will use concept of Buckets

  // Step 1 get the right most bit
  // Refer to 4_L7_Single_Number_III_1

  // (num & (num - 1)) ^ num

  // Step 2 Now we will take two buckets and separate
  // items in num on the basis of the right most bit is set or not
  // REFER to image 4_L7_Single_Number_III_2

  // Now it is sure that that both the bucket will have the single numbers

  // Now we do XOR of each buckets and we get result

  // TC O(2n)
  // SC O(1)

  // we have take long because of edge case of overflow value
  // that in array we might have 2^31 -1 so
  // performing -1 on that will lead to overlfow
  // XOR All Numbers
  long xorr = 0;
  for (int i = 0; i < nums.size(); i++) {
    xorr ^= nums[i];
  }
  // Get RightMost
  long rightMost = xorr & (-xorr);
  int b1 = 0;
  int b2 = 0;

  for (int i = 0; i < nums.size(); i++) {
    // Separate on basis of set or not
    if (nums[i] & rightMost) {
      b1 = b1 ^ nums[i];
    } else {
      b2 = b2 ^ nums[i];
    }
  }

  return {b1, b2};
}

int main() {
  cout << "4 L6 Single Number II" << endl;
  // Every Number will be appearing Twice But there will be two
  // different numbers occuring once

  // brute force will be using map and then looping over it

  vector<int> nums = {2, 4, 2, 14, 3, 7, 7, 3};
  vector<int> res = betterSingleNumberIII(nums);
  cout << res[0] << " " << res[1];
  return 0;
}
