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

TreeNode *searchBinarySearchTree(TreeNode *node, int val) {
  // TC O(log N)
  // SC O(1)

  while (node != nullptr) {
    if (node->val == val) {
      return node;
    }
    // Acc to BST L < N < R
    if (node->val < val) {
      node = node->right;
    } else {
      node = node->left;
    }
  }

  return nullptr;
}

// Simpler Version
TreeNode *searchBinarySearchTree2(TreeNode *node, int val) {
  while (node && node->val != val) {
    node = (val > node->val) ? node->right : node->left;
  }
  return node;
}

int main() {
  cout << "1 L40 Search in a Binary Search Tree" << endl;
  // Prerequisute is to Know Binary Trees and Traversals
  // In Binary Search Tree Left Node will be Lesser then the parent Node
  // and Right Node will be greater then the parent Node
  // L < N
  // N < R
  // So L < N < R

  /*
     Example Tree:
             8
          /    \
         5      12
        / \    /  \
       4   7  10   14
          /       /
         6        13
*/
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(5);
  root->right = new TreeNode(12);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(7);
  root->left->right->left = new TreeNode(6);

  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(14);
  root->right->right->left = new TreeNode(13);

  int target = 10;

  TreeNode *result = searchBinarySearchTree(root, target);
  TreeNode *result2 = searchBinarySearchTree2(root, target);

  if (result) {
    cout << "Found: " << result->val << endl;
  } else {
    cout << "Not Found\n";
  }
  if (result2) {
    cout << "Found: " << result2->val << endl;
  } else {
    cout << "Not Found\n";
  }
  return 0;
}
