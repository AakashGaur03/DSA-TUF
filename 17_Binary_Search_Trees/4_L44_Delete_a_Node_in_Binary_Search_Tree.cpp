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

// Finds the rightmost (maximum) node in a subtree
// This node is the inorder predecessor
TreeNode *findLastRight(TreeNode *root) {
  if (root->right == nullptr) {
    return root;
  }
  return findLastRight(root->right);
}

// Handles deletion of a node and returns the new root of this subtree
// Case 1: No left child → return right subtree
// Case 2: No right child → return left subtree
// Case 3: Both children exist:
//   → Attach right subtree to the rightmost node of left subtree
//   → Return left subtree as new root
//
// Why this works:
// All nodes in left subtree < root < all nodes in right subtree
// So attaching right subtree to the maximum node of left subtree
// preserves BST property
TreeNode *helper(TreeNode *root) {
  if (root->left == nullptr) {
    return root->right;
  } else if (root->right == nullptr) {
    return root->left;
  }

  TreeNode *rightChild = root->right;
  TreeNode *lastRightOfLeft = findLastRight(root->left);
  lastRightOfLeft->right = rightChild;
  return root->left;
}

// If root itself is the node to delete
// Return the new subtree root after deletion
TreeNode *deleteNodeBinarySearchTree(TreeNode *root, int key) {
  // TC O(H)
  // SC O(1)
  if (root == nullptr) {
    return nullptr;
  }

  if (root->val == key) {
    return helper(root);
  }

  TreeNode *dummy = root;
  while (root != nullptr) {
    if (root->val > key) {
      if (root->left != nullptr && root->left->val == key) {
        root->left = helper(root->left);
        break;
      } else {
        root = root->left;
      }
    } else {
      if (root->right != nullptr && root->right->val == key) {
        root->right = helper(root->right);
        break;
      } else {
        root = root->right;
      }
    }
  }

  return dummy;
}

void inorder(TreeNode *root) {
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int main() {
  cout << "4 L44 Delete a Node in Binary Search Tree" << endl;
  // BST L < N < R
  /*
     Example Tree:
             5
          /    \
         3      6
        / \      \
       2   4       7
*/

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  int val = 3;

  // After Deletion

  /*
     Example Tree:
             5
          /    \
         4      6
        /         \
       2           7
*/
  // OR

  /*
     Example Tree:
             5
          /    \
         2      6
          \       \
            4      7
*/
  // All nodes in the left subtree of a node must be smaller than that node (not
  // just the immediate parent, but ALL ancestors).

  // So when we get the node that needs to be deleted
  // Everything on the left of the Node that needs to be deleted will be less
  // than the node on the right
  // Refer 4_L44_Delete_a_Node_in_Binary_Search_Tree_1

  // We will simple delete it mark the parent node (Of Deleted one) and connect
  // with Left one and acc to logic of BST the rightmost node of Left Node we
  // can connect rest of the tree (Right part of Deleted Node)
  // Refer 4_L44_Delete_a_Node_in_Binary_Search_Tree_2

  // or we can do inverse we can delete and mark with the Right one and the left
  // one will be linked to rights leftmost Node Refer
  // 4_L44_Delete_a_Node_in_Binary_Search_Tree_3

  root = deleteNodeBinarySearchTree(root, val);

  // Print inorder
  cout << "Inorder Traversal: ";
  inorder(root);

  return 0;
}
