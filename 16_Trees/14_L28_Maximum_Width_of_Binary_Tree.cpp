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

int main() {
  cout << "14 L28 Maximum Width of Binary Tree" << endl;
  // Maximum Width is No of nodes in a level between any two nodes
  // Refer 14_L28_Maximum_Width_of_Binary_Tree_1
  // We will be using Level Order Traversal WHY because we have to take
  // First node of the Level and the Last Node of the Level
  // We will try to index the tree and then we can simple subtract the Indexes
  // and get the answer
  // Refer 14_L28_Maximum_Width_of_Binary_Tree_2 &
  // 14_L28_Maximum_Width_of_Binary_Tree_3
  /*
        Example Tree:
                1
             /    \
            2       3
           / \     / \
          4   5   8   9
             / \
            8   9


  */

  // Build tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(8);
  root->right->right = new TreeNode(9);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(7);
  return 0;
}
