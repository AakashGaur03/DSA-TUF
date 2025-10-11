#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// brute force approach) TC = O(N), SC = O(N) (recursion stack for skew tree)
int maxDepth(TreeNode *root) {
  if (root == nullptr)
    return 0;

  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);

  return 1 + max(lh, rh);
}

// Brute Force Approach
// TC = O(N^2) -> for every node we call height function
// SC = O(N) recursion stack
bool bruteCheckBalancedBinaryTree(TreeNode *node) {
  if (node == nullptr)
    return true;

  // get height of left and right subtrees
  int lh = maxDepth(node->left);
  int rh = maxDepth(node->right);

  // if difference is more than 1 -> not balanced
  if (abs(lh - rh) > 1)
    return false;

  // recursively check for left and right subtrees
  bool left = bruteCheckBalancedBinaryTree(node->left);
  bool right = bruteCheckBalancedBinaryTree(node->right);

  if (!left || !right)
    return false;

  return true;
}

// Optimized Approach
// Idea: calculate height and check balance in one traversal
// If subtree is not balanced, return -1
// Else return height of subtree
int dfsHeight(TreeNode *node) {
  if (node == nullptr)
    return 0;

  int lh = dfsHeight(node->left);
  if (lh == -1)
    return -1; // left subtree not balanced

  int rh = dfsHeight(node->right);
  if (rh == -1)
    return -1; // right subtree not balanced

  // check difference
  if (abs(lh - rh) > 1)
    return -1;

  // return height if balanced
  return 1 + max(lh, rh);
}

// Wrapper function to check balance
bool optimizedBalancedBinaryTree(TreeNode *root) {
  return dfsHeight(root) != -1;
}

int main() {
  cout << "8 Check For Balanced Binary Tree" << endl;

  /*
     Example Balanced Tree:
           1
          / \
         2   3
        / \
       4   5
     - Height of left subtree = 2
     - Height of right subtree = 1
     - Difference = 1 -> Balanced
  */

  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);

  cout << "Brute: " << bruteCheckBalancedBinaryTree(root1) << endl; // 1 (true)
  cout << "Optimized: " << optimizedBalancedBinaryTree(root1)
       << endl; // 1 (true)

  /*
     Example Unbalanced Tree:
           1
          / \
         2   3
            / \
           4   5
                \
                 6
     - Left subtree height = 1
     - Right subtree height = 3
     - Difference = 2 -> Not Balanced
  */

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);
  root2->right->left = new TreeNode(4);
  root2->right->right = new TreeNode(5);
  root2->right->right->right = new TreeNode(6);

  cout << "Brute: " << bruteCheckBalancedBinaryTree(root2) << endl; // 0 (false)
  cout << "Optimized: " << optimizedBalancedBinaryTree(root2)
       << endl; // 0 (false)

  return 0;
}
