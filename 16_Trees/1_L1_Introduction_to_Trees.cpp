#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "1 L1 Introduction to Trees" << endl;

  // A Binary Tree is a tree data structure where each node has at most two
  // children (left and right).
  //  Head of the tree is called Root Below are
  // childrens Leaf Node : A node that does not have children Sub tree : Inside
  // a root there can be multiple sub trees Ancestors:  Parents of a node are
  // called ancestors, parent ,grand parent, grand grand parent

  // Types of Binary tree
  // 1) Full Binary tree
  // 2) Complete BT
  // 3) Perfect BT
  // 4) Balanced BT
  // 5) Degenerate BT

  // Full Binary tree
  // Every node will either have 0 or 2 children

  // Complete Binary tree
  // All levels are completely filled except the last level
  // The last level has all nodes as left as possible

  // Perfect Binary tree
  // All leaf nodes are at same level

  // Balanced Binary tree
  // Height of tree can be at max of log n
  // For every node, the height difference between left and right subtree is at
  // most 1.

  // Degenerate Binary tree
  // Every node has a single children

  // Full Binary Tree: Every node has 0 or 2 children
  // Structure:
  //        1
  //      /   \
  //     2     3
  //    / \ 
  //   4   5

  // Complete Binary Tree: All levels fully filled except last, last level
  // filled as left :
  //        1
  //      /   \
  //     2     3
  //    / \   /
  //   4   5 6

  // Perfect Binary Tree: Complete + all leaf nodes at same level
  // Structure:
  //        1
  //      /   \
  //     2     3
  //    / \   / \
  //   4   5 6   7

  // Balanced Binary Tree: Height is log(n), subtree heights differ by at
  // most 1 Structure:
  // Ex Nodes = 8  log(8) = 3, So height cant be more than 3
  //        1
  //      /   \
  //     2     3
  //      \    /
  //       4  5

  // Degenerate Binary Tree: Every node has exactly one child (like linked
  // list) Structure: 1 → 2 → 3 → 4

  return 0;
}
