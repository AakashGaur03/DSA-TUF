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

void printLevelOrder(TreeNode *root) {
  if (!root)
    return;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    cout << node->val << " ";

    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }
}

void childSumProperty(TreeNode *root) {
  // TC O(N)
  // SC O(N)
  if (root == nullptr) {
    return;
  }

  int child = 0;
  if (root->left) {
    child += root->left->val;
  }
  if (root->right) {
    child += root->right->val;
  }

  // If value of Child is greater that node then simply update the node
  // else update either Left or right to node and then sum will be greater or
  // equal to node only
  if (child >= root->val) {
    root->val = child;
  } else {
    if (root->left) {
      root->left->val = root->val;
    }
    if (root->right) {
      root->right->val = root->val;
    }
  }

  childSumProperty(root->left);
  childSumProperty(root->right);

  int total = 0;
  if (root->left) {
    total += root->left->val;
  }
  if (root->right) {
    total += root->right->val;
  }
  if (root->left or root->right) {
    root->val = total;
  }
}

int main() {
  cout << "15 L29 Children Sum Property in Binary Tree" << endl;
  //. Node Value Should be equal to Left Node + Right Node value
  // If Tree Doesnt Follow Children Sum Property Then we can increment that
  // node value by 1 any Number of Times
  // We cant simply add Left and Right Values and put up in node Because
  // there might be an case that node value is higher than the left + right
  // refer 15_L29_Children_Sum_Property_in_Binary_Tree_1

  // We will use the approrach that if left and right val sum are smaller than
  // nodes then update left and right with node values
  // Refer 15_L29_Children_Sum_Property_in_Binary_Tree_2
  /*
        Example Tree:
                2
             /    \
            35     10
           / \     / \
          2   3   5   2


  */

  // Build tree
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(35);
  root->right = new TreeNode(10);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(2);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(3);

  childSumProperty(root);

  cout << "Tree after enforcing Children Sum Property:" << endl;
  printLevelOrder(root);
  return 0;
}
