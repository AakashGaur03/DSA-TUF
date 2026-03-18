#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findHeighLeft(TreeNode *node) {
  int height = 0;
  while (node) {
    height++;
    node = node->left;
  }
  return height;
}
int findHeighRight(TreeNode *node) {
  int height = 0;
  while (node) {
    height++;
    node = node->right;
  }
  return height;
}

int countNodesInCompleteTree(TreeNode *root) {
  // TC: O(log N * log N)
  // SC: O(log N)
  // We will be using Height and then applying 2^height -1
  // formula to get the Number of nodes if lh != rh
  // 18_L32_Count_total_Nodes_in_a_COMPLETE_Binary_Tree_1
  // means not a Full Binary Tree so We cant implicate the
  // Formula Directly So we will move to next level means
  // root->left and root->right and again check for those lh
  // == rh and recursively do this and then apply Formula
  if (root == nullptr) {
    return 0;
  }
  int lh = findHeighLeft(root);  // log N
  int rh = findHeighRight(root); // log N
  if (lh == rh) {

    return (1 << lh) - 1; // this is equivalent to 2^lh -1;
  }
  return 1 + countNodesInCompleteTree(root->left) +
         countNodesInCompleteTree(root->right);
}

int main() {
  cout << "18 L32 Count total Nodes in a COMPLETE Binary Tree" << endl;
  // Given the root of a complete binary tree, return the number of the nodes in
  // the tree.
  // every level, except possibly the last, is completely filled in a complete
  // binary tree, and all nodes in the last level are as far left as possible
  /*
        Example Tree:
                1
             /    \
            2      3
           / \     / \
          4   5    6  7
         / \
        8   9

  */

  TreeNode *root = new TreeNode(1);

  // Level 2
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  // Level 3
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // Level 4 (left filled only)
  root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(9);

  // Brute Force
  // we can simply do a traversal and count the nodes
  // So TC O(N)
  // SC O(H) = O(log N) because given Complete Tree
  int nodes = countNodesInCompleteTree(root);

  cout << "Total nodes tree: " << nodes;

  return 0;
}
