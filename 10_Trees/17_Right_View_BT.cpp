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

// Recursive helper function to get right view
void recursion(TreeNode *root, int level, vector<int> &res) {
  if (root == nullptr)
    return;

  // If this is the first node we're visiting at this level,
  // it will be part of the right view
  if (res.size() == level) {
    res.push_back(root->val);
  }

  // Traverse right first, then left (Reverse Preorder)
  recursion(root->right, level + 1, res);
  recursion(root->left, level + 1, res);
}

// Main function to get the right side view of a binary tree
vector<int> rightSideView(TreeNode *root) {
  vector<int> res;
  recursion(root, 0, res);
  return res;
}
int main() {
  cout << "17 Right View of Tree" << endl;
  // Last node at each level
  // And if we traversing from right then first node at ech level
  // We will follow recursive approach
  // Reverse Pre Order traversal
  // So pre order traversal is Root Left Right
  // So Reverse pre order traversal is Root Right Left

  /*
        Example Tree:
              1
             / \
            2   3
             \   \
              5   4

      Right View: [1, 3, 4]
  */

  // Build the tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(4);

  // Get the right side view
  vector<int> result = rightSideView(root);

  // Print result
  cout << "Right View: ";
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}

/*
🔹 Explanation:
We do a "reverse preorder" traversal: Root → Right → Left.
At each level, the first node we encounter is the one visible from the right.

Level 0 → Node 1 (added)
Level 1 → Node 3 (added)
Level 2 → Node 4 (added)
Output: [1, 3, 4]
*/