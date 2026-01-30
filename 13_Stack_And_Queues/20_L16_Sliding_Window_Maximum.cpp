#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximumBrute(vector<int> arr, int k) {
  // TC O((N-K)*K)
  // SC O(N-K)
  int size = arr.size();
  vector<int> ans;
  for (int i = 0; i <= size - k; i++) { // TC (N-K)
    int maxi = arr[i];
    for (int j = i; j < i + k; j++) { // TC (K)
      maxi = max(maxi, arr[j]);
    }
    ans.push_back(maxi);
  }

  return ans;
}

vector<int> slidingWindowMaximumOptimal(vector<int> arr, int k) {
  // TC O(2N)
  // TC O(K) + O(N-K)
  // K for storing in deque and N-K for returning answer
  // Approach is simple we need to keep track of K elements
  // after that we need window elements
  // MONOTONIC STACK
  // Also we need that allows us to Push from back and Pop from front
  // Deque (Monotonic Queue)
  // The deque will store INDICES of elements, not values
  // Front of deque will always store the index of the maximum element
  // of the current window

  int n = arr.size();
  vector<int> res;
  deque<int> dq; // stores indices of useful elements

  for (int i = 0; i < n; i++) { // O(N)

    // Remove elements which are OUTSIDE the current window
    // Current window range is [i - k + 1, i]
    // If an index at the front is <= i - k, it is no longer in window
    if (!dq.empty() && dq.front() <= i - k) { // All push and pop combined O(N)
      dq.pop_front();
    }

    // Maintain decreasing order in deque
    // Remove all elements from back which are smaller than current element
    // Because they can never be the maximum for this or any future window
    while (!dq.empty() && arr[dq.back()] <= arr[i]) {
      dq.pop_back();
    }

    // Add current element's index to deque
    dq.push_back(i);

    // Start adding results once first window is completed
    // The element at the front of deque is the maximum of current window
    if (i >= k - 1) {
      res.push_back(arr[dq.front()]);
    }
  }

  return res;
}
int main() {
  cout << "20 L16 Sliding Window Maximum " << endl;
  // Here K is window and we have to see in windows of three Largest element and
  // Return vector as an answer
  // 1, 3, -1      max=   3
  // 3, -1, -3     max=   3
  // -1, -3, 5     max=   5
  // -3, 5, 3      max=   5
  // 5, 3, 2,      max=   5
  // 3, 2, 1       max=   3
  // 2, 1, 6       max=   6
  // ans is
  // {3, 3, 5, 5, 5, 3, 6}

  vector<int> arr = {1, 3, -1, -3, 5, 3, 2, 1, 6};
  int k = 3;
  vector<int> ans = slidingWindowMaximumBrute(arr, k);

  for (auto it : ans) {
    cout << it << " ";
  }
  cout << endl;
  vector<int> ans2 = slidingWindowMaximumOptimal(arr, k);

  for (auto it2 : ans2) {
    cout << it2 << " ";
  }

  return 0;
}

//  # REVISITED