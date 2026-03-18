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
  cout << "19 L33 Requirements needed to construct a Unique Binary Tree"
       << endl;

  // Can you create a unique Binary Tree

  // We can generate a unique Binary Tree With Inorder
  // Like if there are PostOrder and Precoder in Combo we can create multiple BT
  // Refer 19_L33_Requirements_needed_to_construct_a_Unique_Binary_Tree_1
  // If there is Inorder with it whether it is PostOrder or Inorder we can
  // create a uniquw BT Refer
  // 19_L33_Requirements_needed_to_construct_a_Unique_Binary_Tree_2

  return 0;
}
