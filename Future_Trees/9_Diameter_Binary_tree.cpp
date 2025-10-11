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
// One approach can be calculate LH and RH for each node and return the
// maximum one

// we can also use global variable
// WE pass diameter as reference so that it gets updated
int maxDepth(TreeNode *root, int &diameter) {

  if (root == nullptr)
    return 0;
  int lh = maxDepth(root->left, diameter);
  int rh = maxDepth(root->right, diameter);
  // count nodes
  // diameter = max(lh + rh + 1, diameter);

  // count edges
  diameter = max(lh + rh, diameter);
  return 1 + max(lh, rh);
}
int diameterBinaryTree(TreeNode *root) {
  // Time Complexity: O(N)
  // Space Complexity: O(N)
  int diamter = 0;
  maxDepth(root, diamter);
  return diamter;
}

int main() {
  cout << "9 Diameter of a Binary Tree";
  // Longest path between 2 nodes
  // This path does not need to pass through root

  /*
             1
            / \
           2   3
              / \
             4   5
            /
          6
   */
  //   Diameter is 2 -> 1 -> 3 -> 5 -> 6
  //   Number of nodes = 5
  //   Diameter is through 2 -> 1 -> 3 -> 5 -> 6
  // that is 4 nodes
  /*
             1
            / \
           2   3
              / \
             4   5
            /     \
           8        6
          /          \
         9            7
   */
  //   Diameter is through 9 -> 8 ->4 -> 3 -> 5 -> 6 -> 7
  // that is 6 nodes

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(5);

  int res = diameterBinaryTree(root);
  cout << "Diameter Binary Tree: " << res << endl;
  return 0;
}
// Brute force can be traversing at each node get
// leftHeight and rightHeight add them return max ans