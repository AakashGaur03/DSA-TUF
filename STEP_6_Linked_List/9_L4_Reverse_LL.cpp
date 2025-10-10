#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
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

Node *reversell(Node *head) {
  // TC O(2N)
  // SC O(N)
  Node *temp = head;
  stack<int> st;

  while (temp != NULL) {
    st.push(temp->data);
    temp = temp->next;
  }

  temp = head;

  while (temp != NULL) {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

Node *optimalReversell(Node *head) {
  // TC O(N)
  // SC O(1)
  Node *temp = head;

  // 'prev' will always point to the previous node of the current node
  Node *prev = NULL;
  while (temp != NULL) {
    Node *front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

Node *recursiveReversell(Node *head) {
  // TC O(N)
  // SC O(N) // Recursive Stack Space
  // One Node (Base Case)
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *newHead = recursiveReversell(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;

  return newHead;
}

// Optimal Reverse Explaination
// // 'front' temporarily stores the next node
// // This is necessary because we are going to change temp->next
// Node *front = temp->next;
// // Reverse the link: current node now points to previous node
// temp->next = prev;
// // Move 'prev' forward: it now becomes the current node
// prev = temp;
// // Move 'temp' forward: it now becomes the next node to process
// temp = front;

// Recursive Approach

int main() {
  cout << "4 Reverse a DLL" << endl;
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArr2LL(arr);
  printLL(head);
  head = reversell(head);
  printLL(head);
  head = optimalReversell(head);
  printLL(head);
  head = recursiveReversell(head);
  printLL(head);

  return 0;
}
