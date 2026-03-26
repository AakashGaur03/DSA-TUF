#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
  cout << "24 L39 Introduction to Binary Search Tree" << endl;
  // Prerequisute is to Know Binary Trees and Traversals
  // In Binary Search Tree Left Node will be Lesser then the parent Node
  // and Right Node will be greater then the parent Node
  // L < N
  // N < R
  // So L < N < R
  // Not even equal in both cases
  // Simalrly Entire Left SubTree abd Right SubTree should also be Binary Search
  // Tree
  // In case if anywhere it is mentioned that Duplicates are allowed then it
  // will be L <= N < R
  /*
     Example Tree:
             8
          /    \
         3      10
        / \      \
       1   6      14
          / \     /
         4   7   13
*/
  return 0;
}
