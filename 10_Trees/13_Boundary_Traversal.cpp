#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode *node) {
  return (node->left == NULL && node->right == NULL);
}

void addLeftBoundary(TreeNode *root, vector<int> &res) {
  TreeNode *curr = root->left;
  while (curr) {
    if (!isLeaf(curr))
      res.push_back(curr->val);
    if (curr->left)
      curr = curr->left;
    else
      curr = curr->right;
  }
}

void addRightBoundary(TreeNode *root, vector<int> &res) {
  TreeNode *curr = root->right;
  vector<int> temp; // Because we need to go in reverse
  while (curr) {
    if (!isLeaf(curr))
      temp.push_back(curr->val);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }
  // add in reverse in res
  for (int i = temp.size() - 1; i >= 0; i--) {
    res.push_back(temp[i]);
  }
}

void addLeaves(TreeNode *root, vector<int> &res) {
  if (isLeaf(root)) {
    res.push_back(root->val);
    return;
  }
  if (root->left)
    addLeaves(root->left, res);
  if (root->right)
    addLeaves(root->right, res);
}

vector<int> printBoundary(TreeNode *root) {
  // TC O(N)
  // SC O(N)
  vector<int> res;
  if (!root)
    return res;

  if (!isLeaf(root))
    res.push_back(root->val); // add root only if not leaf
  addLeftBoundary(root, res);
  addLeaves(root, res);
  addRightBoundary(root, res);

  return res;
}

int main() {
  cout << "13 Boundary Traversal" << endl;

  // Example tree:
  //        1
  //      /   \
    //     2     3
  //    / \   / \
    //   4   5 6   7
  //      / \
    //     8   9

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->right->left = new TreeNode(8);
  root->left->right->right = new TreeNode(9);

  vector<int> boundary = printBoundary(root);

  cout << "Boundary Traversal: ";
  for (int val : boundary) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
