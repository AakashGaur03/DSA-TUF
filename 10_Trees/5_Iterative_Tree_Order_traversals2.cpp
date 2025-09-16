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
// Iterative Postorder Traversal using 1 Stack: Left -> Right -> Root
vector<int> iterativePostOrder(Node *root) {
  vector<int> postorder;

  if (root == nullptr)
    return postorder;

  stack<Node *> st;
  Node *curr = root;
  Node *lastVisited = nullptr;

  while (curr != nullptr || !st.empty()) {
    if (curr != nullptr) {
      st.push(curr);
      curr = curr->left;
    } else {
      Node *peekNode = st.top();
      if (peekNode->right != nullptr && lastVisited != peekNode->right) {
        curr = peekNode->right;
      } else {
        postorder.push_back(peekNode->data);
        lastVisited = peekNode;
        st.pop();
      }
    }
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

  /*
  Step by Step Stack Behavior Explanation (1 Stack Method):

  [Initial]       Stack: [], curr: 1

  1. Push 1 → Stack: [1], curr moves to left → curr: 2

  2. Push 2 → Stack: [1, 2], curr moves to left → curr: 4

  3. Push 4 → Stack: [1, 2, 4], curr moves to left → curr: nullptr

  4. curr is nullptr, peek at top (4). No right child, so:
     Pop 4 → Stack: [1, 2], Output: [4], lastVisited = 4

  5. curr is nullptr, peek at top (2). Right child is 5 and lastVisited != 5:
     curr = 5

  6. Push 5 → Stack: [1, 2, 5], curr moves to left → curr: nullptr

  7. curr is nullptr, peek at top (5). No right child, so:
     Pop 5 → Stack: [1, 2], Output: [4, 5], lastVisited = 5

  8. curr is nullptr, peek at top (2). Right child is 5 and lastVisited == 5:
     Pop 2 → Stack: [1], Output: [4, 5, 2], lastVisited = 2

  9. curr is nullptr, peek at top (1). Right child is 3 and lastVisited != 3:
     curr = 3

  10. Push 3 → Stack: [1, 3], curr moves to left → curr: nullptr

  11. curr is nullptr, peek at top (3). No right child, so:
      Pop 3 → Stack: [1], Output: [4, 5, 2, 3], lastVisited = 3

  12. curr is nullptr, peek at top (1). Right child is 3 and lastVisited == 3:
      Pop 1 → Stack: [], Output: [4, 5, 2, 3, 1]

  Final Postorder Output: [4, 5, 2, 3, 1]
  */

  return 0;
}
