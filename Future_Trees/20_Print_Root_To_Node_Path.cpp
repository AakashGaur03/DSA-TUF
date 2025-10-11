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

bool getPath(TreeNode *root, vector<int> &arr, int x) {
  if (!root) {
    return false;
  }
  arr.push_back(root->val);

  if (root->val == x) {
    return true;
  }

  if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
    return true;
  }

  arr.pop_back();
  return false;
}

vector<int> RootToNode(TreeNode *A, int B) {
  // TC O(N)
  // SC O(N) Height Of the Tree
  vector<int> arr;

  if (A == nullptr) {
    return arr;
  }
  getPath(A, arr, B);
  return arr;
}

int main() {
  cout << "20 Print Root To Node Path" << endl;
  // We will do an inorder traveraal Recursively
  // we will travere Root Left Right
  // We goes on left and Right one by one
  // we push root value in DS that might be array or vector
  // if both Left and right gives false meeans Node Value
  // Not present remove that Root from DS
  // when we get a single true then we can return true
  // and we get our answer

  /*
        Example Tree:
              1
             / \
            2   3
           / \
          4   5

      Target: 5
      Path: [1, 2, 5]
  */

  // Build tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  int target = 5;
  vector<int> result = RootToNode(root, target);

  cout << "Path from Root to Node " << target << ": ";
  for (int val : result)
    cout << val << " ";
  cout << endl;

  /*
   Dry Run:
      getPath(1):
        → push 1
        → not target → search left
      getPath(2):
        → push 2
        → not target → search left
      getPath(4):
        → push 4 → not target → left=null, right=null → pop 4
      getPath(5):
        → push 5 → target found  → return true
      Stack unwinds, final vector: [1, 2, 5]
  */

  return 0;
}
