#include <bits/stdc++.h>
using namespace std;
vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> ans;
  priority_queue<pair<int, int>> pq;

  for (int i = 0; i < k; i++) {
  }
  // Need more understanding
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

  return 0;
}
