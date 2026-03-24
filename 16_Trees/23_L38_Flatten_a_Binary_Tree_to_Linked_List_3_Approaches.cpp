#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) {
    val = x;
    next = NULL;
  }
};

struct TreeNode {
  int val; // The data stored in the node (here it's an integer value)
  TreeNode *left, *right; // Pointers to the left and right child nodes

  // Constructor: initializes a node with value 'x'
  // left and right child pointers are set to NULL (meaning no children
  // initially)
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    return NULL;
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
  if (root == NULL)
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
  root->right = prev; // connect current node to next node
  root->left = NULL;  // left should always be NULL in flattened tree

  // Move prev to current node
  prev = root;
}

void flatten(TreeNode *root) {
  TreeNode *prev = NULL;
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
  flatten(root);

  // Print flattened tree (using right pointers)
  TreeNode *curr = root;
  while (curr) {
    cout << curr->val << " -> ";
    curr = curr->right;
  }
  cout << "NULL\n";

  cout << endl;
  return 0;
}
