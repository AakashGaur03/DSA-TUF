#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Binary Tree Traversal" << endl;
  // Traversal Techniques
  // BFS: Breadth First Search
  // DFS: Depth First Search

  // Depth First Search
  // It has three types
  // Inorder Traversal (Left Root Right)
  // Pre-order Traversal (Root Left Right)
  // Post-order Traversal (Left Left Right Root)

  //   EX
  //        1
  //      /   \
  //     2     3
  //    / \   / \
  //   4   5 6   7

  // Inorder Traversal (Left Root Right)
  //   4 2 5 1 6 3 7
  // Pre-order Traversal (Root Left Right)
  //   1 2 4 5 3 6 7
  // Post-order Traversal (Left Right Root)
  // 4 5 2 6 7 3 1

  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \     / \
  //   4   5   6   7
  //      /       / \
  //     8       9   10

  // Inorder Traversal (Left Root Right)
  //   4 2 8 5 1 6 3 9 7 10
  // Pre-order Traversal (Root Left Right)
  //   1 2 4 5 8 3 6 7 9 10
  // Post-order Traversal (Left Right Root)
  // 4 8 5 2 6 9 10 7 3 1

  // BFS: Breadth First Search
  // It goes Level wise
  //   EX
  //        1
  //      /   \
  //     2     3
  //    / \   / \
  //   4   5 6   7

  // 1 2 3 4 5 6 7

  //   EX
  //         1
  //      /     \
  //     2       3
  //    / \     / \
  //   4   5   6   7
  //      /       / \
  //     8       9   10

  // 1 2 3 4 5 6 7 8 9 10
  return 0;
}
