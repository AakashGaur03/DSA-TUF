

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithAtMostKZeros(vector<int> arr, int k) {
  // TC O(N^2)
  // SC O(1)
  // Generate all subarrays
  // Then find longest one with at most k zeros
  int size = arr.size();
  int maxLen = 0;
  for (int i = 0; i < size; i++) {
    int zeros = 0;
    for (int j = i; j < size; j++) {

      if (arr[j] == 0) {
        zeros++;
      }
      if (zeros > k) {
        break;
      }
      maxLen = max(maxLen, j - i + 1);
    }
  }
  return maxLen;
}
int longestSubarrayWithAtMostKZerosSlidingWindow2Pointer(vector<int> arr,
                                                         int k) {
  // TC O(2N)
  // SC O(1)
  int size = arr.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int zeros = 0;
  for (int right = 0; right < size; right++) {
    if (arr[right] == 0) {
      zeros++;
    }
    while (zeros > k) {
      if (arr[left] == 0) {
        zeros--;
      }
      left++;
    }
    if (zeros <= k) {
      maxLen = max(maxLen, right - left + 1);
    }
  }
  return maxLen;
}
int longestSubarrayWithAtMostKZerosSlidingWindow2PointerOptimal(vector<int> arr,
                                                                int k) {
  // TC O(N)
  // SC O(1)
  int size = arr.size();
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int zeros = 0;
  for (int right = 0; right < size; right++) {
    if (arr[right] == 0) {
      zeros++;
    }
    if (zeros > k) {
      if (arr[left] == 0) {
        zeros--;
      }
      left++;
    }
    if (zeros <= k) {
      maxLen = max(maxLen, right - left + 1);
    }
  }
  return maxLen;
}

int main() {
  cout << "4 L4 Max Consecutive Ones III" << endl;
  // We will be given Array with 0s and 1s
  // We need to return maximum Number of 1s there can be after flipping
  // k zeros

  // We can also say it as Longest Subarray with at most k zeros
  vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  int res = longestSubarrayWithAtMostKZeros(arr, k);
  cout << res << endl;
  int res2 = longestSubarrayWithAtMostKZerosSlidingWindow2Pointer(arr, k);
  cout << res2 << endl;
  int res3 =
      longestSubarrayWithAtMostKZerosSlidingWindow2PointerOptimal(arr, k);
  cout << res3 << endl;
  return 0;
}
