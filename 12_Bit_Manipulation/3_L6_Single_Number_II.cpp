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

int singleNumber2SligtBetterApproach(vector<int> nums) {
  // TC O(32 * N)
  // Basically we will count the number of set bits in each index
  //  Acc to that if multiple of 3 we dont take
  //  if not multiple of 3 we take
  //  Refer to 3_L6_Single_Number_II_1
  int ans = 0;
  for (int bitIndex = 0; bitIndex <= 31; bitIndex++) {
    int cnt = 0;
    for (int j = 0; j < nums.size(); j++) {
      // Check if the bitIndex-th bit is set in nums[j]
      // (nums[j] >> bitIndex) & 1  → extracts that bit
      if (nums[j] & (1 << bitIndex)) {
        cnt++;
      }
    }
    if (cnt % 3 == 1) {
      ans |= (1 << bitIndex);
    }
  }
  return ans;

  /*
     Key idea:
     - All numbers except one appear exactly 3 times
     - So their bits contribute in multiples of 3
     - The unique number contributes +1 at its set bits

     If cnt % 3 == 1, that means the unique number
     has this bit set.
   */
}

int singleNumber3Approach(vector<int> nums) {
  // TC O(n log n) + n/3 ;
  // SC O(1)
  // We sort the numbers
  // then we have all three numbers together
  // we will start from 1st index check before it
  // is same them move 3 steps
  // till we dont get a number that is not only once
  // if we goes out of bound then last number appears only once

  sort(nums.begin(), nums.end());               // n log n
  for (int i = 1; i < nums.size(); i = i + 3) { // n/3
    if (nums[i] != nums[i - 1]) {
      return nums[i - 1];
    }
  }
  return nums[nums.size() - 1];
  /*
   Idea:
   - Every number appears exactly 3 times except one
   - After sorting, equal numbers will be adjacent
   - Triplets will appear as: x, x, x
   - The unique number will break this pattern
 */
}

int singleNumber4Optimal(vector<int> nums) {
  // TC O(N)
  // SC O(1)
  // concept of buckets
  // Refer to 3_L6_Single_Number_II_2

  // We will be tacking three buckets with ones two threes
  // with Below Rules
  // nums[i] will go to ones, if not in twos
  // nums[i] will go to twos, if it is in ones
  // nums[i] will go to threes, if it is in twos
  int ones = 0;
  int twos = 0;
  for (int i = 0; i < nums.size(); i++) {
    ones = (ones ^ nums[i]) & ~twos;
    twos = (twos ^ nums[i]) & ~ones;
  }
  return ones;

  /*
  Idea:
  - Every number appears exactly 3 times except one
  - We count bits modulo 3 using two variables (buckets)

  ones  → stores bits that have appeared once
  twos  → stores bits that have appeared twice

  When a bit appears the 3rd time, it is removed from both

*/

  /*
    Step 1:
    - XOR adds nums[i] bits to 'ones'
    - AND with ~twos removes bits already in 'twos'
  */
  // ones = (ones ^ nums[i]) & ~twos;

  /*
    Step 2:
    - XOR adds nums[i] bits to 'twos'
    - AND with ~ones removes bits that just moved to 'ones'
  */
  // twos = (twos ^ nums[i]) & ~ones;

  /*
  After processing all numbers:
  - Bits appearing 3 times are removed
  - Only bits of the unique number remain in 'ones'
*/
  // return ones;
}
int main() {
  cout << "4 L6 Single Number II" << endl;
  // Every Number will be appearing Thrice Find Out Number Apprearing Once

  vector<int> nums = {4, 2, 1, 1, 2, 1, 2};
  int res = singleNumber2Brute(nums);
  cout << res;
  int res2 = singleNumber2SligtBetterApproach(nums);
  cout << res2;
  int res3 = singleNumber3Approach(nums);
  cout << res3;
  int res4 = singleNumber4Optimal(nums);
  cout << res4;
  return 0;
}
