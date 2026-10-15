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
    // return bit
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

int findMaximumXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
  Trie trie;

  for (auto it : arr1) {
    trie.insert(it);
  }
  int maxi = 0;
  for (auto it : arr2) {
    maxi = max(maxi, trie.getMax(it));
  }

  return maxi;
}

// TC: O(32 * (n + m)) = O(n + m)
// SC: O(32 * n) = O(n)

int main() {
  cout << "6 L6 Maximum XOR of Two Numbers in an Array" << endl;

  //   Maximum XOR of Two Numbers from two Array
  vector<int> arr1 = {6, 8};
  vector<int> arr2 = {7, 9, 5};

  int n = arr1.size();
  int m = arr2.size();

  cout << "Maximum XOR: " << findMaximumXOR(n, m, arr1, arr2) << endl;

  return 0;
}