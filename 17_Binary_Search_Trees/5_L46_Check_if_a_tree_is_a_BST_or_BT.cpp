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

bool isValidHelper(TreeNode *root, long minVal, long maxVal) {
  if (root == nullptr) {
    return true;
  }
  if (root->val >= maxVal || root->val <= minVal) {
    return false;
  }
  return isValidHelper(root->left, minVal, root->val) &&
         isValidHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root) {
  return isValidHelper(root, LONG_MIN, LONG_MAX);
}

int main() {
  cout << "5 L46 Check if a tree is a BST or BT" << endl;
  // BST L < N < R
  /*
     Example Tree:
             5
          /    \
         3      6
        / \      \
       2   4       7
*/

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  // In this for each node we will have a range that it should be between in
  // this, This will come in handy for the deeper nodes
  // Refer 5_L46_Check_if_a_tree_is_a_BST_or_BT_1
  // -IM refers to INT MIN and IM to INT MAX

  // Use a recursive range approach where each node must lie within a valid(min,
  // max) range propagated from its ancestors.
  bool check = isValidBST(root);
  cout << (check ? "Valid BST" : "Not a BST") << endl;
  return 0;
}
