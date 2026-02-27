#include <bits/stdc++.h>
using namespace std;

// Definition of Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Iterative Postorder Traversal using 1 Stack: Left -> Right -> Root
vector<int> iterativePostOrder(Node *root) {
  // TC O(2N)
  // SC O(N)
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
  cout << "4 L12 Iterative Postorder Traversal using 1 Stack" << endl;

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

  //   Go as LEFT as possible
  // Then check RIGHT subtree
  // Only after both are done → process ROOT

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

/*
=========================================================
ITERATIVE POSTORDER TRAVERSAL (1 STACK) - STEP BY STEP
Tree Structure:

                1
              /   \
             2     7
            /     /
           3     8
            \
             4
              \
               5
                \
                 6

Postorder Rule:
Left → Right → Root
=========================================================


Algorithm Idea:
1. Go LEFT as much as possible (push nodes into stack)
2. If no left:
      - If right exists AND not visited → go right
      - Else → pop and process node
3. Use lastVisited pointer to track processed right subtree


=========================================================
STEP-BY-STEP DRY RUN
=========================================================

Initial State:
curr = 1
stack = []
lastVisited = NULL


-----------------------------
STEP 1: Go Left Completely
-----------------------------

Push 1
Push 2
Push 3

stack = [1, 2, 3]
curr = NULL


-----------------------------
STEP 2: Check Node 3
-----------------------------

Top = 3
Right child = 4
lastVisited != 4

→ Move to right

curr = 4


-----------------------------
STEP 3: Push 4
-----------------------------

Push 4

stack = [1, 2, 3, 4]
curr = NULL

Right child = 5
Not visited

→ Move to right

curr = 5


-----------------------------
STEP 4: Push 5
-----------------------------

Push 5

stack = [1, 2, 3, 4, 5]
curr = NULL

Right child = 6
Not visited

→ Move to right

curr = 6


-----------------------------
STEP 5: Push 6
-----------------------------

Push 6

stack = [1, 2, 3, 4, 5, 6]
curr = NULL

6 has no left and no right

→ Pop 6

postorder = [6]
lastVisited = 6

stack = [1, 2, 3, 4, 5]


-----------------------------
STEP 6: Revisit 5
-----------------------------

Top = 5
Right child = 6
lastVisited == 6

→ Pop 5

postorder = [6, 5]
lastVisited = 5

stack = [1, 2, 3, 4]


-----------------------------
STEP 7: Revisit 4
-----------------------------

Right child = 5
lastVisited == 5

→ Pop 4

postorder = [6, 5, 4]
lastVisited = 4

stack = [1, 2, 3]


-----------------------------
STEP 8: Revisit 3
-----------------------------

Right child = 4
lastVisited == 4

→ Pop 3

postorder = [6, 5, 4, 3]
lastVisited = 3

stack = [1, 2]


-----------------------------
STEP 9: Revisit 2
-----------------------------

2 has no right child

→ Pop 2

postorder = [6, 5, 4, 3, 2]
lastVisited = 2

stack = [1]


-----------------------------
STEP 10: Revisit 1
-----------------------------

Right child = 7
lastVisited != 7

→ Move to right

curr = 7


-----------------------------
STEP 11: Process 7 Subtree
-----------------------------

Push 7
Push 8

stack = [1, 7, 8]
curr = NULL

8 has no children

→ Pop 8

postorder = [6, 5, 4, 3, 2, 8]
lastVisited = 8

stack = [1, 7]


-----------------------------
STEP 12: Revisit 7
-----------------------------

7 has no right child

→ Pop 7

postorder = [6, 5, 4, 3, 2, 8, 7]
lastVisited = 7

stack = [1]


-----------------------------
STEP 13: Final Step (Node 1)
-----------------------------

Right child = 7
lastVisited == 7

→ Pop 1

postorder = [6, 5, 4, 3, 2, 8, 7, 1]


=========================================================
FINAL POSTORDER OUTPUT:
6 5 4 3 2 8 7 1
=========================================================


Key Understanding:
A node is processed ONLY after:
1. Left subtree is done
2. Right subtree is done

That is why we use:
lastVisited pointer
=========================================================
*/