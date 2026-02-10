

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
    sum = sum + (arr[right] % 2);
    while (sum > goal) {
      sum = sum - (arr[left] % 2);
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
  cout << "8 L10 Count number of Nice subarrays" << endl;
  vector<int> arr = {1, 5, 2, 1, 1};
  int k = 3;
  // Given an array of integers nums and an integer k. A continuous
  // subarray is called nice if there are k odd numbers on it.
  // Similar as 8_L9_Binary_Subarrays_With_Sum
  // WE can consider as all odd number as 1 and even number as 0
  // So we can deduce above example as {1,1,0,1,1}
  // and then same problem
  // we just add % 2 while adding in sum and subtracting in sum
  // as they give if even Number it adds 0 and if odd number it adds 1
  int res2 = optimalApproach(arr, k);
  cout << res2 << endl;
  return 0;
}
