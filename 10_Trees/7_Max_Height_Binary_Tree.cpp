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

int maxDepth(TreeNode *root) {
  // TC O(N) // we need to traverse each element
  // SC O(N) // worst case if a skew tree
  // means
  // 1
  // |
  // 2
  // |
  // 3
  // |
  // 4
  if (root == nullptr)
    return 0;

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return 1 + max(lh, rh);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(5);

  int res = maxDepth(root);
  cout << "Maximum Depth of Tree: " << res << endl;
  return 0;
}

// Logic Behind is example

//            1
//           / \
//          2   3
//             / \
//            4   6
//           /
//          5

/*
Step by Step Recursive Execution:

- Start at root (1):
    leftDepth = maxDepth(2)
    rightDepth = maxDepth(3)

- At node (2):
    left = NULL → 0
    right = NULL → 0
    depth(2) = 1 + max(0, 0) = 1

- At node (3):
    leftDepth = maxDepth(4)
    rightDepth = maxDepth(6)

- At node (6):
    left = NULL → 0
    right = NULL → 0
    depth(6) = 1 + max(0, 0) = 1

- At node (4):
    leftDepth = maxDepth(5)
    rightDepth = NULL → 0

- At node (5):
    left = NULL → 0
    right = NULL → 0
    depth(5) = 1 + max(0, 0) = 1

- Back to node (4):
    leftDepth = 1 (from node 5)
    rightDepth = 0
    depth(4) = 1 + max(1, 0) = 2

- Back to node (3):
    leftDepth = 2 (from node 4)
    rightDepth = 1 (from node 6)
    depth(3) = 1 + max(2, 1) = 3

- Finally at root (1):
    leftDepth = 1 (from node 2)
    rightDepth = 3 (from node 3)
    depth(1) = 1 + max(1, 3) = 4

Final Answer = 4
*/
