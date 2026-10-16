#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *links[2];
  Node() {
    for (int i = 0; i < 2; i++) {
      links[i] = nullptr;
    }
  }

  bool containsKey(int bit) {
    // Check if bit is set or not
    return links[bit] != NULL;
  }

  Node *get(int bit) {
    // return bit
    return links[bit];
  }

  void *put(int bit, Node *node) {
    // bit
    links[bit] = node;
  }
};

class Trie {
private:
  Node *root;

public:
  Trie() { root = new Node(); }

  void insert(int num) {
    Node *node = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (num >> i) & 1; // Current Bit
      if (!node->containsKey(bit)) {
        node->put(bit, new Node());
      }
      node = node->get(bit);
    }
  }

  int getMax(int num) {
    Node *node = root;
    int maxNum = 0;
    for (int i = 31; i >= 0; i--) {
      // Current Bit
      int bit = (num >> i) & 1;
      if (node->containsKey(1 - bit)) {
        maxNum = maxNum | (1 << i);
        node = node->get(1 - bit);
      } else {
        node = node->get(bit);
      }
    }
    return maxNum;
  };
};

vector<int> maximizeXor(vector<int> &arr, vector<vector<int>> &queries) {
  sort(arr.begin(), arr.end());
  vector<pair<int, pair<int, int>>> offlineQueries;
  int q = queries.size();
  for (int i = 0; i < q; i++) {
    offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
  }
  sort(offlineQueries.begin(), offlineQueries.end());
  vector<int> ans(q, 0);
  int ind = 0;
  Trie trie;

  for (int i = 0; i < q; i++) {
    int mi = offlineQueries[i].first;
    int xi = offlineQueries[i].second.first;
    int qInd = offlineQueries[i].second.second;
    while (ind < arr.size() && arr[ind] <= mi) {
      trie.insert(arr[ind]);
      ind++;
    }
    if (ind == 0) {
      ans[qInd] = -1;
    } else {
      ans[qInd] = trie.getMax(xi);
    }
  }
  return ans;
}

// TC: O(N * log N + Q * log Q + 32 * (N + Q))
// SC: O(32 * N + Q)

int main() {
  cout << "7 L7 Maximum XOR With an Element From Array" << endl;

  // Maximum XOR With an Element From Array

  // You are given an array nums consisting of non-negative integers. You are
  // also given a queries array, where queries[i] = [xi, mi].

  // The answer to the ith query is the maximum bitwise XOR value of xi and any
  // element of nums that does not exceed mi. In other words, the answer is
  // max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in
  // nums are larger than mi, then the answer is -1.

  // Return an integer array answer where answer.length == queries.length and
  // answer[i] is the answer to the ith query.

  // Example 1:

  // Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
  // Output: [3,3,7]
  // Explanation:
  // 1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1
  // XOR 3 = 2. The larger of the two is 3. 2) 1 XOR 2 = 3. 3) 5 XOR 2 = 7.
  // Example 2:

  // Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
  // Output: [15,-1,5]

  // We can solve this as an extension of Previous Problem
  // 6_L6_Maximum_XOR_of_Two_Numbers_in_an_Array
  // Here what we will store in Trie are Numbers that are already
  // Lesser than or Equal to mi so then we can directly use our previous logic

  // We will sort the queries acc to the mi

  vector<int> arr = {0, 1, 2, 3, 4};

  vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};

  vector<int> ans = maximizeXor(arr, queries);

  for (int num : ans) {
    cout << num << " ";
  }

  cout << endl;
  return 0;
}