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

void inorder(TreeNode *root) {
  if (root == nullptr)
    return;

  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}

int KthsmmallestElement(TreeNode *root, int k, int &cnt) {
  if (root == nullptr)
    return -1;

  int left = KthsmmallestElement(root->left, k, cnt);
  if (left != -1)
    return left;

  cnt++;
  if (cnt == k) {
    return root->val;
  }
  return KthsmmallestElement(root->right, k, cnt);
}

// Right Before Left
int KthLargest(TreeNode *root, int k, int &cnt) {
  if (!root)
    return -1;

  int right = KthLargest(root->right, k, cnt);
  if (right != -1)
    return right;

  cnt++;
  if (cnt == k)
    return root->val;

  return KthLargest(root->left, k, cnt);
}

int main() {
  cout << "5 L45 K th Smallest Largest Element in BST" << endl;
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
  int k = 3;
  // NOTE in BST Inorder gives us the Sorted Values as it follows L < N < R
  // So we will perform Inroder and then we can get the Kth element
  int cnt = 0;
  int val = KthsmmallestElement(root, k, cnt);
  cout << val;
  int cnt2 = 0;
  int val2 = KthLargest(root, k, cnt2);
  cout << val2;
  return 0;
}
