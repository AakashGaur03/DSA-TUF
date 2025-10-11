#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Tree" << endl;

  // Tree when there are two nodes in it it is called Binary Tree
  // Head of the tree is called Root
  // Below are childrens
  // Leaf Node : A node that does not have children0
  // Sub tree Inside a root there can be multiple sub trees
  // Ancestors
  // Parents of a node are called ancestors parent ,grand parent, grand grand
  // parent

  // Types of Binary tree
  // Full Binary tree
  // Complete BT
  // Perfect BT
  // Balanced BT
  // De BT

  // Full Binary tree
  // Every node will either have 0 or 2 children

  // Complete Binary tree
  // All levels are completely filled except the last level
  // The last level has all nodes as left as possible

  // Perfect Binary tree
  // All leaf nodes are at same level

  // Balanced Binary tree
  // Height of tree can be at max og log n

  // Degenerate Binary tree
  // Every node has a single children

  // Full Binary Tree: Every node has 0 or 2 children
  // Structure:
  //        1
  //      /   \
  //     2     3
  //    / \ 
  //   4   5

  // Complete Binary Tree: All levels fully filled except last, filled left to
  // right Structure:
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
  // Balanced Binary Tree: Height is log(n), subtree heights differ by at most 1
  // Structure:
  //        1
  //      /   \
  //     2     3
  //      \    /
  //       4  5

  // Degenerate Binary Tree: Every node has exactly one child (like linked list)
  // Structure:
  // 1 → 2 → 3 → 4

  // Binary Tree Representation

  //   struct Node {
  //     int data;
  //     struct Node *left;
  //     struct Node *rught;
  //     Node(int, val) {
  //       data = val;
  //       left = right = null;
  //     }
  //   }

  //   main() {
  //     struct Node *right = new Node(1);

  //     root->left = new Node(2);
  //     root->right = new Node(3);
  //     root->left->right = new Node(5);
  //   }

  //   // Root node with value 1

  //   // Left child of root → Node with value 2
  //   root->left = new Node(2);

  //   // Right child of root → Node with value 3
  //   root->right = new Node(3);

  //   // Right child of root's left child → Node with value 5
  //   root->left->right = new Node(5);

  //         1          // Root
  //        / \
  //       2   3       // Left and right children of root
  //        \
  //         5        // Right child of the first 2

  return 0;
}
