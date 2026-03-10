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

bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
  if (left == nullptr || right == nullptr) {
    return left == right;
  }
  if (left->val != right->val) {
    return false;
  }

  return isSymmetricHelper(left->left, right->right) &&
         isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(TreeNode *root) {
  // TC O(N)
  // SC O(N) (Height Of the Thee)
  return root == nullptr || isSymmetricHelper(root->left, root->right);
}

int main() {
  cout << "12 L25 Check for Symmetrical Binary Trees" << endl;
  // Question asks that wheather it will form mirror at it center or not
  // Refer 12_L25_Check_for_Symmetrical_Binary_Trees_1 &
  // 12_L25_Check_for_Symmetrical_Binary_Trees_2

  //  In mirror Left will be on right
  // and Right will be on Left
  //       LEFT             RIGHT
  // Root Left Right | Root Right Left

  // Create symmetric tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);

  // Call function
  bool result = isSymmetric(root);

  cout << (result ? "Tree is Symmetric" : "Tree is NOT Symmetric") << endl;

  return 0;
}
//        1
//      /  \
//    2     2
//   / \   / \
// 3   4  4   3

/*
 Dry Run:
   Compare(2,2)
     ↳ Compare(3,3) (both leaf)
     ↳ Compare(4,4) (both leaf)
   → All matched → Tree is Symmetric
 */
