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

int bruteLowestCommonAncestor(TreeNode *root, int a, int b) {
  // TC: O(N) + O(N) + O(N) ≈ O(N)
  // SC: O(N) + O(N) Two path sizes
  vector<int> path1 = RootToNode(root, a);
  vector<int> path2 = RootToNode(root, b);
  int ans = -1;
  int path1Size = path1.size();
  int path2Size = path2.size();
  // Taking the smaller Path Size
  int size = path1Size < path2Size ? path1Size : path2Size;
  for (int i = 0; i < size; i++) {
    if (path1[i] == path2[i]) {
      ans = path1[i];
    } else {
      break;
    }
  }
  return ans;
}

int main() {
  cout << "13 L27 Lowest Common Ancestor in Binary Tree" << endl;
  // Lowest Common ancestor
  // We will be given two nodes or number and we have to find there
  // common lowest ancestor Refer to
  // 13_L27_Lowest_Common_Ancestor_in_Binary_Tree_1

  // BRUTE FORCE
  // GET Root_to_Node_Path_in_Binary_Tree same as previous One
  // for both the values then check till last matching members
  /*
        Example Tree:
                1
             /    \
            2       3
           / \     / \
          4   5   8   9
             / \
            8   9


  */

  // Build tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(8);
  root->right->right = new TreeNode(9);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(7);
  int res = bruteLowestCommonAncestor(root, 4, 7);
  cout << "Brute is: " << res;
  return 0;
}
