#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *child;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
    child = nullptr;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
    child = nullptr;
  }
};

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void printVertical(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->child;
  }
  cout << endl;
}

Node *convertArr2LL(vector<int> arr) {
  // TC O(N)

  // Step 1: Create the first node (head) using the first element of the array
  // 'new Node(arr[0])' creates a node with 'data = arr[0]' and 'next = nullptr'
  Node *head = new Node(arr[0]);

  // Step 2: Keep a pointer 'mover' to traverse the list while building it
  Node *mover = head;

  // Step 3: Loop through the rest of the array elements (starting from index 1)
  for (int i = 1; i < arr.size(); i++) {
    // Step 4: Create a new node for the current element
    Node *temp = new Node(arr[i]);

    // Step 5: Link the previous node (mover) to this new node
    mover->next = temp;

    // Step 6: Move the 'mover' pointer ahead to the newly created node
    // This ensures the next new node will be attached to the current tail
    mover = temp;
    // mover = mover->next;  // both do the same thing
  }

  // Step 7: Return the head of the linked list (starting point)
  return head;
}
Node *convertArr2LLVertical(vector<int> arr) {
  // TC O(N)

  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);

    mover->child = temp;
    mover = temp;
  }

  // Step 7: Return the head of the linked list (starting point)
  return head;
}

Node *bruteFlatten(Node *head) {

  // Step 1 Traverse each and every element and store in array
  // Step 2 Sort them
  // Step 3 Arrange in child manner

  Node *row = head;
  vector<int> arr;
  while (row != NULL) {
    Node *col = row;
    while (col != NULL) {
      arr.push_back(col->data);
      col = col->child;
    }
    row = row->next;
  }

  // Step 2
  sort(arr.begin(), arr.end());

  // step 3
  // Convert to Vertical manner create a function like created convertArr2LL
  head = convertArr2LLVertical(arr);
  return head;
}

Node *merge2ListsVertically(Node *list1, Node *list2) {
  // TC O(N1 + N2)
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;

  while (list1 != NULL && list2 != NULL) {
    if (list1->data < list2->data) {
      res->child = list1;
      res = list1;
      list1 = list1->child;
    } else {
      res->child = list2;
      res = list2;
      list2 = list2->child;
    }
    res->next = NULL; // adter adding in child make sure that next is NULL
  }
  if (list1) {
    res->child = list1;
  }
  if (list2) {
    res->child = list2;
  }
  if (dummyNode->child) {
    dummyNode->child->next = NULL; // First Node Next should also be NULL
  }
  return dummyNode->child;
}

// After merge2ListsVertically we will use concept of recursion

Node *flattenALL(Node *head) {
  // N is Horizontal length
  // M is vetical Length
  // TC O(N)*O(2M)
  //  because of traversing it linearly
  // 2M because of merging
  // SC O(N) // recursive Stack Space
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *mergedHead = flattenALL(head->next);
  head = merge2ListsVertically(head, mergedHead);

  return head;
}

int main() {
  cout << "21 L24 Flattening a LL with sorted Child" << endl;
  cout << "Flattening a LL with sorted Child lists" << endl;

  // Creating structure:
  // 5 -> 10 -> 19 -> 28
  // |     |     |     |
  // 7     20    22    35
  // |           |     |
  // 8           50    40
  // |                 |
  // 30                45

  Node *head = new Node(5);
  head->next = new Node(10);
  head->next->next = new Node(19);
  head->next->next->next = new Node(28);

  head->child = new Node(7);
  head->child->child = new Node(8);
  head->child->child->child = new Node(30);

  head->next->child = new Node(20);

  head->next->next->child = new Node(22);
  head->next->next->child->child = new Node(50);

  head->next->next->next->child = new Node(35);
  head->next->next->next->child->child = new Node(40);
  head->next->next->next->child->child->child = new Node(45);

  Node *flattened = flattenALL(head);

  cout << "Flattened list: ";
  printVertical(flattened);

  return 0;
}
