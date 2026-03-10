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

void recursion(TreeNode *root, int level, vector<int> &res) {
  if (root == nullptr)
    return;

  if (res.size() == level) {
    res.push_back(root->val);
  }

  recursion(root->left, level + 1, res);
  recursion(root->right, level + 1, res);
}

vector<int> leftSideView(TreeNode *root) {
  vector<int> res;
  recursion(root, 0, res);
  return res;
}

int main() {
  cout << "18 Left View of Tree" << endl;

  /*
        Example Tree:
              1
             / \
            2   3
             \   \
              5   4

      Left View = [1, 2, 5]
  */

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);

  vector<int> result = leftSideView(root);

  cout << "Left View: ";
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

/*
🔹 Explanation:
We do a "Preorder traversal" (Root → Left → Right)
At each level, the first node we encounter is the one visible from the left.

Level 0 → Node 1 (added)
Level 1 → Node 2 (added)
Level 2 → Node 5 (added)
Output: [1, 2, 5]
*/