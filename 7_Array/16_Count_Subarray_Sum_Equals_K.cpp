#include <bits/stdc++.h>
using namespace std;
int bruteCountSubarraySumK(vector<int> arr, int size, int k) {
  // TC O(N^2)
  // SC O(1)
  int cnt = 0;
  for (int i = 0; i < size; i++) {
    int sum = 0;
    for (int j = i; j < size; j++) {
      sum = sum + arr[j];
      if (sum == k) {
        cnt++;
      }
    }
  }
  return cnt;
}

int optimalCountSubarraySumK(vector<int> arr, int size, int k) {

  // TC O(N log N) for map
  // TC O(N) for unordered_map in average case (optimal performance)
  // TC O(N^2) for unordered_map in worst case (heavy collisions)

  // SC O(N)

  int cnt = 0;

  // We use a hashmap to store the frequency of prefix sums
  // key   -> prefix sum
  // value -> how many times this prefix sum has occurred
  //   map<int, int> mpp;
  unordered_map<int, int> mpp;
  mpp[0] = 1;
  int prefSum = 0;

  for (int i = 0; i < size; i++) {
    prefSum += arr[i];

    // We want to find how many previous prefix sums equal (current prefixSum -
    // k)
    // Because if prefSum - k was seen before, it means there is a subarray
    // ending at current index with sum = k
    int remove = prefSum - k;

    // If such a prefix sum was seen before, add its count to the answer
    // This accounts for all subarrays ending at current index with sum = k
    cnt += mpp[remove];

    // Record the current prefix sum in map
    // (so it can help future subarrays)
    mpp[prefSum] += 1;
  }

  return cnt;
}
int main() {

  cout << "Array 16" << endl;
  // Number of Subarrays with Sum K
  // Contigious Part

  vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
  int sum = 3;
  //   So here we have 8 sub arrays
  //   [1,2]
  //   [1,2,3,-3]
  //   [3]
  //   [2,3,-3,1]
  //   [3,-3,1,1,1]
  //   [1,1,1]
  //   [4,2,-3]
  //   [-3,1,1,1,4,2,-3]

  // Brute force Generate all Sub array then see how many gives the sum
  int res = bruteCountSubarraySumK(arr, arr.size(), sum);
  cout << "Result: " << res;
  // we Will use concept of Prefix Sum as done in Same Folder 7_Array in
  // 3_array_Longest_subarray_sum_k
  int result = optimalCountSubarraySumK(arr, arr.size(), sum);
  cout << endl << "Result: " << result;
  return 0;
}