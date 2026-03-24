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

vector<int> getInorder(TreeNode *root) {
  vector<int> inorder;
  TreeNode *curr = root;
  while (curr != NULL) {

    // Case 1: No left child → visit node and go right
    if (curr->left == NULL) {
      inorder.push_back(curr->val);
      curr = curr->right;

      // Case 2: Left child exists
    } else {
      TreeNode *prev = curr->left;

      // Find rightmost node in left subtree (inorder predecessor)
      while (prev->right && prev->right != curr) {
        prev = prev->right;
      }

      // First time visiting this node → create thread
      if (prev->right == NULL) {
        prev->right = curr;
        curr = curr->left;

      } else {
        prev->right = nullptr;
        inorder.push_back(curr->val);
        curr = curr->right;
      }
    }
  }
  return inorder;
}

vector<int> getPreorder(TreeNode *root) {
  vector<int> preorder;
  TreeNode *curr = root;

  while (curr != NULL) {

    // Case 1: No left child → visit node and go right
    if (curr->left == NULL) {
      preorder.push_back(curr->val); // Visit node
      curr = curr->right;
    }

    // Case 2: Left child exists
    else {
      TreeNode *prev = curr->left;

      // Find rightmost node in left subtree (predecessor)
      while (prev->right && prev->right != curr) {
        prev = prev->right;
      }

      // First time visiting → create thread
      if (prev->right == NULL) {
        prev->right = curr;            // Create thread
        preorder.push_back(curr->val); // Visit BEFORE going left (key diff)
        curr = curr->left;             // Move to left subtree
      }

      // Second time → thread exists → remove it
      else {
        prev->right = nullptr; // Remove thread
        curr = curr->right;    // Move to right subtree
      }
    }
  }
  return preorder;
}

int main() {
  cout << "22 L37 Morris Traversal Preorder Inorder" << endl;
  // It takes O(N) for TIme Complexity But it doesnt consumes any Space
  // Complexity that is O(1)
  // How?
  // It uses concept of Threaded Binary Tree

  /*
     Example Tree:
             1
          /    \
         2      3
        / \
       4   5
            \
             6
*/
  TreeNode *root = new TreeNode(1);

  // Level 2
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  // Level 3
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  // Level 4
  root->left->right->right = new TreeNode(6);
  vector<int> inorder = getInorder(root);
  vector<int> preorder = getPreorder(root);

  cout << "\nInorder: ";
  for (int x : inorder)
    cout << x << " ";

  cout << "\nPreorder: ";
  for (int x : preorder)
    cout << x << " ";

  cout << endl;
  return 0;
}
