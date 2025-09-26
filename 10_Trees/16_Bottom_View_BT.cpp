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

vector<int> bottomView(TreeNode *root) {
  vector<int> ans;
  if (root == nullptr)
    return ans;
  map<int, int> mpp;
  queue<pair<TreeNode *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    auto it = q.front();
    q.pop();
    TreeNode *node = it.first;
    int line = it.second;
    mpp[line] = node->val;

    if (node->left != nullptr) {
      q.push({node->left, line - 1});
    }
    if (node->right != nullptr) {
      q.push({node->right, line + 1});
    }
  }
  for (auto it : mpp) {
    ans.push_back(it.second);
  }

  return ans;
}
int main() {
  cout << "16 Bottom View of Tree" << endl;

  /*
        Example Tree:
              1
             / \
            2   3
          /  \ / \
         4   5 6  7
             / \
            8   9
  */

  // Build the tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  root->left->right->left = new TreeNode(8);
  root->left->right->right = new TreeNode(9);

  // Get bottom view
  vector<int> result = bottomView(root);

  // Print the result
  cout << "Bottom View: ";
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

/*
Expected Output:
Bottom View: 4 8 6 9 7

Explanation by horizontal distance:
-2 → 4
-1 → 8 (overwrites 2)
 0 → 6 (overwrites 1 and 5)
 1 → 9 (overwrites 3)
 2 → 7
*/