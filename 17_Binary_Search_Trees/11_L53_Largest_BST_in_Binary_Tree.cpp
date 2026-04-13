using namespace std;
#include <bits/stdc++.h>

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class NodeValue {
public:
  int minNode, maxNode, maxSize;

  NodeValue(int minNode, int maxNode, int maxSize) {
    this->maxNode = maxNode;
    this->minNode = minNode;
    this->maxSize = maxSize;
  }
};

NodeValue largestBSTinBinaryTree(TreeNode *root) {
  // TC O(N)
  // SC O(1)
  if (!root) {
    // Send so that it can be compared Easily
    return NodeValue(INT_MAX, INT_MIN, 0);
  }

  // Get values from Left and Right Subtree
  auto left = largestBSTinBinaryTree(root->left);
  auto right = largestBSTinBinaryTree(root->right);

  if (left.maxNode < root->val && root->val < right.minNode) {
    // It is a BST
    return NodeValue(min(root->val, left.minNode),
                     max(root->val, right.maxNode),
                     left.maxSize + right.maxSize + 1);
  }

  // Otherwise return [INTMIN AND INTMAX] so cant be compared
  return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int main() {
  cout << "11 L53 Largest BST in Binary Tree" << endl;
  // BST L < N < R

  // We will be given a Binary Tree and we need to give Largest Size Valid BST

  /*
   Example Tree:
           10
        /    \
       5      15
     /  \       \
    1    8        7
*/

  // In above Tree Largest BST is of Size 3 that is

  /*
           5
         /  \
        1    8
  */

  // Brute Force
  // Go to each node and Validate each BST if Valid then count Nodes
  // pass node at each level to  5_L46_Check_if_a_tree_is_a_BST_or_BT
  // TC O(N^2)
  // SC O(1)

  // optimal Apporach
  // The Node is Greater than the Largest Element on the Left and
  // Smaller than the Smallest Node on the Right
  // Refer to 11_L53_Largest_BST_in_Binary_Tree_1

  // For this we will be using A Post Order Traversal As we need to compare
  // Left Right and then Node

  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(8);
  root->right->right = new TreeNode(7);

  NodeValue result = largestBSTinBinaryTree(root);

  cout << "Largest BST size: " << result.maxSize << endl;

  return 0;
}
