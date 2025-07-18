#include <bits/stdc++.h>
using namespace std;
int bruteLongestSubarrayWithSumKPositives(vector<int> arr, int k) {
  // O(N^2)
  int res = 0;
  for (int i = 0; i < arr.size(); i++) {
    int addition = 0;
    for (int j = i; j < arr.size(); j++) {
      addition += arr[j];
      if (addition == k) {
        res = max(res, j - i + 1);
      }
      if (addition > k) {
        break;
      }
    }
  }
  return res;
}

// Works for Positive Zero and Negative And also the optimal approach with
// positive ,zero and negatives
int betterLongestSubarrayWithSumKPositives(vector<int> arr, long long k) {
  // TC (N logN) Ordermap
  // TC (N^2) UnOrdermap
  // SC (N)
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (sum == k) {
      maxLen = max(maxLen, i + 1);
    }
    long long rem = sum - k;
    if (preSumMap.find(rem) != preSumMap.end()) {
      int len = i - preSumMap[rem];
      maxLen = max(maxLen, len);
    }
    if (preSumMap.find(sum) == preSumMap.end()) {
      preSumMap[sum] = i;
    }
  }
  return maxLen;
}

//// Only works when the array contains non-negative numbers (positives or 0)
int optimalLongestSubarrayWithSumKPositivesAndZeroes(vector<int> arr,
                                                     long long k) {
  // 2 pointer
  // SC O(1)
  // TC O(2N)
  // Outer while loop runs till right < n --> at most N steps
  // Inner while loop shrinks window from left only when needed --> at most N
  // steps So total complexity is O(N + N) = O(2N) = O(N)
  int left = 0;
  int right = 0;
  long long sum = arr[0];
  int maxLen = 0;
  int n = arr.size();

  while (left <= right && right < n) {
    // Step 1: Shrink window from the left if sum exceeds k
    while (sum > k) {
      sum -= arr[left]; // remove left element from window
      left++;           // move window start forward
    }

    // Step 2: If current window sum equals k, update max length
    if (sum == k) {
      maxLen = max(maxLen, right - left + 1);
    }

    // Step 3: Expand window to the right
    right++;
    if (right < n)
      sum += arr[right];
  }

  return maxLen;
}

int main() {
  cout << " Array 3" << endl;
  vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
  int sum = 6;
  // Subarray -> contigious part of the array

  // Longest subArray with sum K with positive numbers
  // Generate all sub arrays whose sum are equal to k and longest

  // int res = bruteLongestSubarrayWithSumKPositives(arr, sum);
  // int res = betterLongestSubarrayWithSumKPositives(arr, sum);
  // cout << endl << "Ans :" << res;
  int res = optimalLongestSubarrayWithSumKPositivesAndZeroes(arr, sum);
  cout << endl << "Ans :" << res;
  return 0;
}