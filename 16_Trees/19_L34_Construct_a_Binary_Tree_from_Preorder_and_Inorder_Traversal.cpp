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
  cout << "19 L34 Construct a Binary Tree from Preorder and Inorder Traversal"
       << endl;
  // We have to create Binary Tree Using given Preorder and Inorder Traversal
  // Note from Prev video acc to concepts this will form a Unique Binary Tree
  // Inorder : [40 20 50 10 60 30]
  // Preorder : [10 20 40 50 30 60]
  // Inorder : LEFT ROOT RIGHT
  // Preorder : ROOT LEFT RIGHT
  // From the Preorder we know First Node is Root
  // So we have got Root
  // that is 10 then if we are able to find the root in the Inorder
  // We can say that whatever is at Left of it is Left of BT and right is right
  // of BT Refer
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_1
  // Then we can recursively Apply this Step to Left and rights and we can get a
  // Unique Binary Tree
  // Refer 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_2,
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_3,
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_4
  // 19_L34_Construct_a_Binary_Tree_from_Preorder_and_Inorder_Traversal_4

  return 0;
}
