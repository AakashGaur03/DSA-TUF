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

// Pre-order traversal of the tree
void preOrder(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->val << " ";
  preOrder(root->left);
  preOrder(root->right);
}

bool compareTwoTrees(TreeNode *root1, TreeNode *root2) {
  // If both trees are empty, they are identical
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }

  // If one tree is empty and the other is not, they are not identical
  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }

  // If the values of the current nodes don't match, trees are not identical
  if (root1->val != root2->val) {
    return false;
  }

  // Recursively compare the left and right subtrees
  return compareTwoTrees(root1->left, root2->left) &&
         compareTwoTrees(root1->right, root2->right);
}

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == nullptr || q == nullptr) {
    return (p == q);
  }

  return (p->val == q->val) && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}
int main() {
  cout << "11 Check if Two Trees are Identical or Not" << endl;
  // WE can do any traversal that is preorder inorder postorder
  // we will comapre the both values at each step
  // at any step not same return false else return true
  // TC O(N)
  // SC O(N)

  // Create two trees for comparison
  // Tree 1:      1
  //            /   \
  //           2     3
  //          / \
  //         4   5
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);

  // Tree 2:      1
  //            /   \
  //           2     3
  //          / \
  //         4   5
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);
  root2->left->left = new TreeNode(4);
  root2->left->right = new TreeNode(5);

  // Check if the two trees are identical
  if (compareTwoTrees(root1, root2)) {
    cout << "The trees are identical." << endl;
  } else {
    cout << "The trees are not identical." << endl;
  }

  return 0;
}
