#include <bits/stdc++.h>
using namespace std;
vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k) {
  // BRUTE FORCE
  // TC O(N*N)
  // SC O(1)
  vector<int> ans;
  priority_queue<int> pq;
  int n = a.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pq.push(a[i] + b[j]);
    }
  }
  while (!pq.empty() && k > 0) {
    ans.push_back(pq.top());
    pq.pop();
    k--;
  }

  return ans;
}
vector<int> topKSumPairsOptimized(vector<int> &a, vector<int> &b, int k) {
  // BRUTE FORCE
  // TC O(N log N)
  // SC O(N log N)
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> ans;
  // We will be storing Combinations, Index
  priority_queue<pair<int, int>> pq;
  int n = a.size();

  for (int i = 0; i < n; i++) {
    int sum = a[i] + b[n - 1];
    // It stores All Values of A with last index of b and b's index
    pq.push({sum, n - 1});
  }

  while (!pq.empty() && k > 0) {
    auto it = pq.top();
    pq.pop();
    int sum = it.first;
    int index = it.second;
    ans.push_back(sum);
    if (index - 1 >= 0) {
      // - because to remove the b's value and try previous one before it
      pq.push({sum - b[index] + b[index - 1], index - 1});
    }
    k--;
  }

  return ans;
}
int main() {
  cout << "12 Maximum Sum Combination" << endl;
  // You are given two integer arrays a[] and b[] of equal size. A sum
  // combination is formed by adding one element from a[] and one from b[],
  // using each index pair (i, j) at most once. Return the top k maximum sum
  // combinations, sorted in non-increasing order.

  // Examples:

  // Input: a[] = [3, 2], b[] = [1, 4], k = 2
  // Output: [7, 6]
  // Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top
  // 2 sums are 7 and 6.

  vector<int> a = {3, 2};
  vector<int> b = {1, 4};
  int k = 2;

  cout << "Brute Force: ";
  vector<int> ans1 = topKSumPairs(a, b, k);
  for (int x : ans1) {
    cout << x << " ";
  }
  cout << endl;

  cout << "Optimized: ";
  vector<int> ans2 = topKSumPairsOptimized(a, b, k);
  for (int x : ans2) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
