#include <bits/stdc++.h>
using namespace std;

// Definition of Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Iterative Postorder Traversal using 2 Stacks: Left -> Right -> Root
vector<int> iterativePostOrder(Node *root) {
  vector<int> postorder;

  if (root == nullptr)
    return postorder;

  stack<Node *> st1, st2;
  st1.push(root);

  while (!st1.empty()) {
    root = st1.top();
    st1.pop();
    st2.push(root);

    // Left pushed first, so right gets processed first
    if (root->left)
      st1.push(root->left);
    if (root->right)
      st1.push(root->right);
  }

  while (!st2.empty()) {
    postorder.push_back(st2.top()->data);
    st2.pop();
  }

  return postorder;
}

int main() {
  cout << "Iterative Postorder Traversal with 2 Stack Example:\n";

  // Example Tree:
  //       1
  //      / \
  //     2   3
  //    / \
  //   4   5

  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  vector<int> result = iterativePostOrder(root);

  cout << "Postorder Traversal: ";
  for (int val : result)
    cout << val << " ";
  cout << endl;

  /*
  Step by Step Stack Behavior Explanation:

  [Initial]       st1: [1]

  1. Pop 1 → st1: [], st2: [1], Push 2 and 3 → st1: [2, 3]

  2. Pop 3 → st1: [2], st2: [1, 3]

  3. Pop 2 → st1: [], st2: [1, 3, 2], Push 4 and 5 → st1: [4, 5]

  4. Pop 5 → st1: [4], st2: [1, 3, 2, 5]

  5. Pop 4 → st1: [], st2: [1, 3, 2, 5, 4]

  Final output by popping from st2: [4, 5, 2, 3, 1]
  */

  return 0;
}
