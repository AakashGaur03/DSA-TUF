

#include <bits/stdc++.h>
using namespace std;

int NumberOfSubarraysWhereSumLestThanOrEqualToGoal(vector<int> arr, int goal) {
  // TC O(2N)
  // SC O(1)

  if (goal < 0) {
    return 0;
  }
  int left = 0;
  int right = 0;
  int size = arr.size();
  int cnt = 0;
  int sum = 0;

  while (right < size) {
    sum = sum + arr[right];
    while (sum > goal) {
      sum = sum - arr[left];
      left++;
    }
    if (sum <= goal) {
      cnt = cnt + (right - left + 1);
    }
    right++;
  }
  return cnt;
}

int optimalApproach(vector<int> arr, int goal) {
  // TC O(2 * 2N)
  // SC O(1)
  // We will be calculating
  // Number of Subarrays where sum<=goal
  // and
  // Number of Subarrays where sum <= goal - 1
  // and then Subtract both of them
  return NumberOfSubarraysWhereSumLestThanOrEqualToGoal(arr, goal) -
         NumberOfSubarraysWhereSumLestThanOrEqualToGoal(arr, goal - 1);
}

int main() {
  cout << "8 L9 Binary Subarrays With Sum" << endl;
  vector<int> arr = {1, 0, 1, 0, 1};
  int goal = 2;

  // Must Know Count Subarray sum equals to K
  // 16_Count_Subarray_Sum_Equals_K.cpp
  // It is exactly same problem that will also work here
  // But here we are given Binary Subarrays so we can make
  // some optimizations
  // There TC O(N) and SC O(N)

  int res2 = optimalApproach(arr, goal);
  cout << res2 << endl;
  return 0;
}
