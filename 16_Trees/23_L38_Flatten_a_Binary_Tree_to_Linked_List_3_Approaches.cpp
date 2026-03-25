#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) {
    val = x;
    next = nullptr;
  }
};

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printList(ListNode *head) {
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

ListNode *bruteLinkedList(TreeNode *root) {
  if (root == nullptr) {
    return nullptr;
  }
  vector<int> preorder;
  stack<TreeNode *> st;
  st.push(root);

  // Step 1: Get preorder traversal
  while (!st.empty()) {
    TreeNode *node = st.top();
    st.pop();
    preorder.push_back(node->val);

    if (node->right)
      st.push(node->right);
    if (node->left)
      st.push(node->left);
  }

  if (preorder.empty())
    return nullptr;
  // Step 2: Create linked list
  ListNode *head = new ListNode(preorder[0]);
  ListNode *curr = head;

  for (int i = 1; i < preorder.size(); i++) {
    curr->next = new ListNode(preorder[i]);
    curr = curr->next;
  }

  return head;
}

void flattenHelper(TreeNode *root, TreeNode *&prev) {
  if (root == nullptr)
    return;

  /*
We follow REVERSE PREORDER:
Normal preorder = Root -> Left -> Right
Reverse preorder = Right -> Left -> Root

WHY?
Because we want to process nodes from BACKWARD order
so we can keep attaching nodes using 'prev'
*/
  // Reverse preorder: Right -> Left
  flattenHelper(root->right, prev);
  flattenHelper(root->left, prev);

  //  Rewire pointers
  root->right = prev;   // connect current node to next node
  root->left = nullptr; // left should always be NULL in flattened tree

  // Move prev to current node
  prev = root;
}

void flattenRecursive(TreeNode *root) {
  // TC O(N)
  // SC O(N)
  TreeNode *prev = nullptr;
  flattenHelper(root, prev);

  /*

   Example Tree:
           1
         /   \
        2     5
       / \     \
      3   4     6
               /
              7

   Execution order (Reverse Preorder):
   7 → 6 → 5 → 4 → 3 → 2 → 1

   Let's track 'prev':

   Start:
   prev = NULL

   Node 7:
   root->right = NULL
   prev = 7

   Node 6:
   root->right = 7
   prev = 6

   Node 5:
   root->right = 6
   prev = 5

   Node 4:
   root->right = 5
   prev = 4

   Node 3:
   root->right = 4
   prev = 3

   Node 2:
   root->right = 3
   prev = 2

   Node 1:
   root->right = 2
   prev = 1

   Final structure:
   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL

   ---------------------------------------------------------
   */
}

void flattenIterative(TreeNode *root) {
  // TC O(N)
  // SC O(N)
  // Yellow pointers for Right
  // Red Pointer for Left 
  // Refer 23_L38_Flatten_a_Binary_Tree_to_Linked_List_3_Approaches_3
  // 23_L38_Flatten_a_Binary_Tree_to_Linked_List_3_Approaches_4
  if (root == nullptr)
    return;

  stack<TreeNode *> st;
  st.push(root);
  /*
    IDEA:
    Simulate preorder traversal using stack:
    Root -> Left -> Right

    But stack is LIFO, so:
    Push RIGHT first, then LEFT
    */

  while (!st.empty()) {
    TreeNode *curr = st.top();
    st.pop();

    // Push right child first
    if (curr->right) {
      st.push(curr->right);
    }

    // Push left child
    if (curr->left) {
      st.push(curr->left);
    }

    /*
    Top of stack will be next node in preorder
    So connect current node's right to it
    */
    if (!st.empty()) {
      curr->right = st.top();
    }

    // Left must be NULL
    curr->left = nullptr;
  }
  /*
  ---------------- DRY RUN ----------------

  Stack initially: [1]

  Pop 1:
    push 5, push 2 → stack: [5, 2]
    1->right = 2

  Pop 2:
    push 4, push 3 → stack: [5, 4, 3]
    2->right = 3

  Pop 3:
    stack: [5, 4]
    3->right = 4

  Pop 4:
    stack: [5]
    4->right = 5

  Pop 5:
    push 6 → stack: [6]
    5->right = 6

  Pop 6:
    push 7 → stack: [7]
    6->right = 7

  Pop 7:
    stack empty → 7->right = NULL

  FINAL:
  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL

  -----------------------------------------
  */
}

void flattenMorris(TreeNode *root) {
  // TC O(N)
  // SC O(1)
  // On the left sub tree we will get the last node of preorder and connect it
  // to right of the root Refer
  // 23_L38_Flatten_a_Binary_Tree_to_Linked_List_3_Approaches_5

  TreeNode *curr = root;

  /*
  IDEA:
  For each node:
  - If left exists:
      Find rightmost node of left subtree
      Connect it to curr->right
      Move left subtree to right
  */

  while (curr != nullptr) {
    if (curr->left != nullptr) {

      // Step 1: Find rightmost node of left subtree
      TreeNode *prev = curr->left;
      while (prev->right != nullptr) {
        prev = prev->right;
      }

      // Step 2: Connect right subtree
      prev->right = curr->right;

      // Step 3: Move left subtree to right
      curr->right = curr->left;
      curr->left = nullptr;
    }

    // Step 4: Move forward
    curr = curr->right;
  }

  /*
  ---------------- DRY RUN ----------------

  At node 1:
    left = 2
    rightmost of left = 4
    4->right = 5
    1->right = 2

  At node 2:
    left = 3
    rightmost = 3
    3->right = 4
    2->right = 3

  Continue...

  FINAL:
  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL

  -----------------------------------------
  */
}
int main() {
  cout << "23 L38 Flatten a Binary Tree to Linked List 3 Approaches" << endl;

  /*
     Example Tree:
             1
          /    \
         2      5
        / \      \
       3   4      6
                 /
                7
*/
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(5);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(6);
  root->right->right->left = new TreeNode(7);
  // Simplest Way Create new LL
  // We have to represent PREORDER in a LinkedList
  // That will be 1->2->3->4->5->6->7
  // NOTE we dont have to create a new LinkedList we need to rearrage these

  ListNode *head = bruteLinkedList(root);
  printList(head);

  // But we need to do without creating a new LL
  flattenRecursive(root);

  // Print flattened tree (using right pointers)
  TreeNode *curr = root;
  while (curr) {
    cout << curr->val << " -> ";
    curr = curr->right;
  }
  cout << "NULL\n";

  // Create fresh tree again
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(5);
  root2->left->left = new TreeNode(3);
  root2->left->right = new TreeNode(4);
  root2->right->right = new TreeNode(6);
  root2->right->right->left = new TreeNode(7);

  flattenIterative(root2);

  // Print
  TreeNode *curr2 = root2;
  while (curr2) {
    cout << curr2->val << " -> ";
    curr2 = curr2->right;
  }
  cout << "NULL\n";

  // Fresh tree again
  TreeNode *root3 = new TreeNode(1);
  root3->left = new TreeNode(2);
  root3->right = new TreeNode(5);
  root3->left->left = new TreeNode(3);
  root3->left->right = new TreeNode(4);
  root3->right->right = new TreeNode(6);
  root3->right->right->left = new TreeNode(7);

  flattenMorris(root3);

  // Print
  TreeNode *curr3 = root3;
  while (curr3) {
    cout << curr3->val << " -> ";
    curr3 = curr3->right;
  }
  cout << "NULL\n";
  return 0;
}
