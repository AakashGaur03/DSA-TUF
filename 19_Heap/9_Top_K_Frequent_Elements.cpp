#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
  int n = nums.size();
  map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    mpp[nums[i]]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minHeap;

  for (auto it = mpp.begin(); it != mpp.end(); it++) {
    minHeap.push({it->second, it->first});
    if (minHeap.size() > k) {
      minHeap.pop();
    }
  }
  vector<int> ans;
  while (!minHeap.empty()) {
    auto it = minHeap.top();
    ans.push_back(it.second);
    minHeap.pop();
  }

  return ans;
}

int main() {
  cout << "9 Top K Frequent Elements" << endl;

  // Given an integer array nums and an integer k, return the k most frequent
  // elements. You may return the answer in any order.

  // Example 1:

  // Input: nums = [1,1,1,2,2,3], k = 2

  // Output: [1,2]

  // Example 2:

  // Input: nums = [1], k = 1

  // Output: [1]

  vector<int> nums1 = {1, 1, 1, 2, 2, 3};
  int k1 = 2;

  vector<int> ans1 = topKFrequent(nums1, k1);

  cout << "Example 1 Output: ";
  for (int x : ans1) {
    cout << x << " ";
  }
  cout << endl;

  // Example 2
  vector<int> nums2 = {1};
  int k2 = 1;

  vector<int> ans2 = topKFrequent(nums2, k2);

  cout << "Example 2 Output: ";
  for (int x : ans2) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
