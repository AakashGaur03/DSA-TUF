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

int floorBinarySearchTree(TreeNode *node, int key) {
  // TC O(Log N)
  // SC O(1)
  int floor = -1;
  while (node != nullptr) {
    if (node->val == key) {
      return node->val;
    }

    if (node->val < key) {
      floor = node->val;  // store candidate
      node = node->right; // try smaller
    } else {
      node = node->left; // need bigger value
    }
  }

  return floor;
}

int main() {
  cout << "2 L42 Floor in a Binary Search Tree" << endl;
  // BST L < N < R
  // We need to get the key or the Highest Value that is smaller than the Key

  /*
     Example Tree:
             10
          /    \
         5      13
        / \    /  \
       3   6  11   14
            \
             9
*/

  // Constructing the tree
  TreeNode *root = new TreeNode(10);

  root->left = new TreeNode(5);
  root->right = new TreeNode(13);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(6);
  root->left->right->right = new TreeNode(9);

  root->right->left = new TreeNode(11);
  root->right->right = new TreeNode(14);

  int key = 8;
  // So in this we have to find lowest value that is greater than 8 so acc to
  // above we will get 6.

  int floorValue = floorBinarySearchTree(root, key);

  if (floorValue != -1) {
    cout << "Floor of " << key << " is: " << floorValue << endl;
  } else {
    cout << "No floor found for " << key << endl;
  }

  return 0;
}
