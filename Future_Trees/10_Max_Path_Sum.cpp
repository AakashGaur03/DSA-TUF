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

// For reference
int maxDepth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);
  return 1 + max(lh, rh);
}

int maxPath(TreeNode *root, int &maxi) {
  if (root == nullptr) {
    return 0;
  }
  // We have done max o 0 and other so that if there is negative then
  // ignore those childrens
  int leftSum = max(0, maxPath(root->left, maxi));
  int rightSum = max(0, maxPath(root->right, maxi));
  // This will give us sum for each node with left and right
  int sumWithRoot = root->val + leftSum + rightSum;
  maxi = max(maxi, sumWithRoot);
  // This returns maximum of left or right + node
  // calculates for parents
  return (root->val) + max(leftSum, rightSum);
}

int main() {
  cout << "10 Max Path Sum" << endl;

  // Create a sample tree
  TreeNode *root = new TreeNode(-10);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  // Compute max path sum
  int maxi = INT_MIN;
  maxPath(root, maxi);

  cout << "Maximum Path Sum = " << maxi << endl;

  return 0;
}

//   -10                <- root
//   /  \
//  9    20
//      /  \
//    15    7