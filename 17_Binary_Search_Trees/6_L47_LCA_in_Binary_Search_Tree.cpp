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

TreeNode *lcaBST(TreeNode *root, TreeNode *p, TreeNode *q) {
  // TC O(H)
  // SC O(1)
  if (root == nullptr) {
    return nullptr;
  }
  int curr = root->val;
  // Both of Right
  if (curr < p->val && curr < q->val) {
    return lcaBST(root->right, p, q);
  }
  // Both of Left
  if (curr > p->val && curr > q->val) {
    return lcaBST(root->left, p, q);
  }
  return root;
}

int main() {
  cout << "6 L47 LCA in Binary Search Tree" << endl;
  // BST L < N < R
  /*
     Example Tree:
             6
          /    \
         2      8
        / \    / \
       0   4  7   9
          / \
         3   5
*/

  TreeNode *root = new TreeNode(6);

  root->left = new TreeNode(2);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  // Example: find LCA of 5 and 0
  TreeNode *p = root->left->right->right; // 5
  TreeNode *q = root->left->left;         // 0

  // LCA is Lowest Common Ancestor
  // That is First intersection Point from bottom or
  // Last intersection Point from top
  // So we will give given to Find out the LCA (5,0)
  // That will be 2

  // Number of cases
  // Both are on Right of node
  // Both are on Left of node
  // One number is on Left of node and one is on Right
  // Refer 6_L47_LCA_in_Binary_Search_Tree_1

  // One of the Number is Node
  // Means now Both Number are not on Left or Right
  // so now this is LCA
  // Refer 6_L47_LCA_in_Binary_Search_Tree_2
  TreeNode *res = lcaBST(root, p, q);
  if (res) {
    cout << "LCA: " << res->val << endl;
  }

  return 0;
}
