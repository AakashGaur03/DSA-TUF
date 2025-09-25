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

int main() {
  cout << "15 Top View of Tree" << endl;
  // Refer to 16_Bottom_View_BT Image
  // Level Order Traversal
  // We follow kind of same approach as previous
  // when mones left -1 when right +1
  // Here for each we only take one value that is from the last node
}
