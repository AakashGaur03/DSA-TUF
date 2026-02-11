

#include <bits/stdc++.h>
using namespace std;

int bruteApporach(vector<int> arr, int k) {
  // TC O(N^2)
  // SC O(N)
  int size = arr.size();
  int cnt = 0;
  for (int i = 0; i < size; i++) {
    unordered_map<int, int> mpp;
    for (int j = i; j < size; j++) {
      mpp[arr[j]]++;

      if (mpp.size() == k) {
        cnt = cnt + 1;
      }
      if (mpp.size() > k) {
        break;
      }
    }
  }
  return cnt;
}

int subarraysWithLessThanOrEqualKDistinct(vector<int> arr, int K) {
  // TC O(2N)
  // SC O(N)

  if (K < 0) {
    return 0;
  }
  int left = 0;
  int right = 0;
  int size = arr.size();
  int cnt = 0;
  int sum = 0;
  unordered_map<int, int> mpp;
  while (right < size) {
    mpp[arr[right]]++;
    while (mpp.size() > K) {
      mpp[arr[left]]--;
      if (mpp[arr[left]] == 0) {
        mpp.erase(arr[left]);
      }
      left++;
    }
    if (mpp.size() <= K) {
      cnt = cnt + (right - left + 1);
    }
    right++;
  }
  return cnt;
}

int optimalApproach(vector<int> arr, int K) {
  // TC O(2 * 2N)
  // SC O(2* N)
  // We will be calculating
  // Number of Subarrays where sum<=K
  // and
  // Number of Subarrays where sum <= K - 1
  // and then Subtract both of them
  return subarraysWithLessThanOrEqualKDistinct(arr, K) -
         subarraysWithLessThanOrEqualKDistinct(arr, K - 1);
}

int main() {
  cout << "9 L11 Subarray with k different integers" << endl;
  vector<int> arr = {1, 2, 1, 3, 4};
  int k = 3;

  int res = bruteApporach(arr, k);
  cout << res << endl;

  int res2 = optimalApproach(arr, k);
  cout << res2 << endl;
  return 0;
}
