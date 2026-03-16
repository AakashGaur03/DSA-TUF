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

TreeNode *bfsToMapParents(TreeNode *root, map<TreeNode *, TreeNode *> &mpp,
                          int start) {
  queue<TreeNode *> q;
  q.push(root);
  TreeNode *res = NULL;
  while (!q.empty()) {
    TreeNode *node = q.front();
    if (node->val == start) {
      res = node;
    }
    q.pop();
    if (node->left) {
      mpp[node->left] = node;
      q.push(node->left);
    }
    if (node->right) {
      mpp[node->right] = node;
      q.push(node->right);
    }
  }
  return res;
}

int minimumTimeToBurnTree(map<TreeNode *, TreeNode *> &mpp, TreeNode *target) {
  queue<TreeNode *> q;

  q.push(target);
  map<TreeNode *, int> vis;
  vis[target] = 1;
  int time = 0;

  // fl is a flag that at that level there was some Node that was burnt
  while (!q.empty()) {
    int size = q.size();
    int fl = 0;
    for (int i = 0; i < size; i++) {
      auto node = q.front();
      q.pop();
      if (node->left && !vis[node->left]) {
        fl = 1;
        vis[node->left] = 1;
        q.push(node->left);
      }
      if (node->right && !vis[node->right]) {
        fl = 1;
        vis[node->right] = 1;
        q.push(node->right);
      }
      if (mpp[node] && !vis[mpp[node]]) {
        fl = 1;
        vis[mpp[node]] = 1;
        q.push(mpp[node]);
      }
    }
    // If at a level node is burnt then increase the time
    if (fl)
      time++;
  }
  return time;
}

int main() {
  cout << "17 L31 Minimum time taken to BURN the Binary Tree from a Node"
       << endl;
  // We will be given a node
  // Number of steps to reach to a node simultaniouly is the time to burn the
  // trees like in prev question we were getting steps similarly like that

  /*
        Example Tree:
                1
             /    \
            2      3
           / \     / \
          4       5   6
           \
            7
  */

  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->left->right = new TreeNode(7);

  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);

  int start = 2;

  map<TreeNode *, TreeNode *> mpp;
  // TC O(2N)
  // SC O(2N)
  TreeNode *target = bfsToMapParents(root, mpp, start);

  int time = minimumTimeToBurnTree(mpp, target);

  cout << "Time to burn tree: " << time;

  return 0;
}
