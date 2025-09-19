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
  cout << "9 Diameter of a Binary Tree";
  // Longest path between 2 nodes
  // This path does not need to pass through root
  /*
             1
            / \
           2   3
              / \
             4   5
                  \
                   6
   */
  //   Diameter is through 2 -> 1 -> 3 -> 5 -> 6
  // that is 4 nodes
  /*
             1
            / \
           2   3
              / \
             4   5
            /     \
           8        6
          /          \
         9            7
   */
  //   Diameter is through 9 -> 8 ->4 -> 3 -> 5 -> 6 -> 7
  // that is 6 nodes
  return 0;
}
// Brute force can be traversing at each node get
// leftHeight and rightHeight add them return max ans