#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *optimalSuccessorBST(TreeNode *root, TreeNode *p) {
  TreeNode *successor = nullptr;

  while (root != nullptr) {
    if (root->val <= p->val) {
      root = root->right;
    } else {
      successor = root;
      root = root->left;
    }
  }
  return successor;
}
TreeNode *optimalPredecessorBST(TreeNode *root, TreeNode *p) {
  TreeNode *predecessor = nullptr;

  while (root != nullptr) {
    if (root->val < p->val) {
      predecessor = root;
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return predecessor;
}

int main() {
  cout << "8 L49 Inorder Successor Predecessor in BST" << endl;
  // BST L < N < R

  // We will be given a BST we have to find the Inorder Successor
  // Means Inorder and then next term of that given value

  // Apporach 1 we can do Inorder Traversal and get the inorder and then
  // traverse again and get the next value
  // These Apporach will take TC O(N) and SC O(N)

  // Apporach 2 we can do Inorder Traversal and get the next value on the fly
  // without storing it
  // These Apporach will take TC O(N) and SC O(1)

  // Apporach 3 we can simply search for the first value greater than the given
  // Value
  // These Apporach will take TC O(H) and SC O(1)

  return 0;
}
