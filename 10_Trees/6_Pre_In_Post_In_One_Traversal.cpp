#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "6 Preorder Inorder Postorder traversals In One Traversal";
  // Single stack to find out all three traversals
  // we will store node,number in an stack (LIFO)
  // RULES

  // if number == 1
  // that will go to preorder
  // we push that number by doing a ++
  // and if there exist a left we enter the left

  // if number == 2
  // that will go to inorder
  // we push that number by doing a ++
  // and if there exist a right we enter the right

  // if number == 3
  // that will go to postorder
  // pop the number and node

  // TC O(3N) // we iterated over thrice for each node with number 1 2 3
  // SC O(4N) // we are using three differnt lists to store answer and
  // a stack for computation
  return 0;
}