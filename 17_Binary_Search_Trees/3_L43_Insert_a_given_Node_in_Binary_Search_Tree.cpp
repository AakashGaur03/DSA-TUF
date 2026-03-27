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

TreeNode *InsertNodeBinarySearchTree(TreeNode *root, int val) {
  // TC O(Log N)
  // SC O(1)
  if (root == nullptr) {
    return new TreeNode(val);
  }
  TreeNode *curr = root;
  while (true) {
    if (curr->val <= val) {
      if (curr->right != nullptr) {
        curr = curr->right;
      } else {
        curr->right = new TreeNode(val);
        break;
      }
    } else {
      if (curr->left != nullptr) {
        curr = curr->left;
      } else {
        curr->left = new TreeNode(val);
        break;
      }
    }
  }

  return root;
}

void inorder(TreeNode *root) {
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main() {
  cout << "3 L43 Insert a given Node in Binary Search Tree" << endl;
  // BST L < N < R
  /*
     Example Tree:
             4
          /    \
         2      7
        / \
       1   3
*/

  // Constructing the tree
  TreeNode *root = new TreeNode(4);
  InsertNodeBinarySearchTree(root, 2);
  InsertNodeBinarySearchTree(root, 7);
  InsertNodeBinarySearchTree(root, 1);
  InsertNodeBinarySearchTree(root, 3);

  int val = 5;
  InsertNodeBinarySearchTree(root, val);

  // Print inorder
  cout << "Inorder Traversal: ";
  inorder(root);

  return 0;
}
