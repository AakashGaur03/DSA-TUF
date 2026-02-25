#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(Node *root) {
  // TC O(N)
  // SC O(N)

  vector<vector<int>> ans;
  if (root == nullptr)
    return ans;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; i++) {
      Node *node = q.front();
      q.pop();
      if (node->left != NULL) {
        q.push(node->left);
      }
      if (node->right != NULL) {
        q.push(node->right);
      }
      level.push_back(node->data);
    }
    ans.push_back(level);
  }
  return ans;
}

int main() {
  cout << "2 L8 Level Order Traversal of Binary Tree";

  // Level Order traversal

  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \     / \
  //   4   5   6   7

  // 1 2 3 4 5 6 7

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  vector<vector<int>> result = levelOrder(root);

  for (auto level : result) {
    for (auto val : level) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}