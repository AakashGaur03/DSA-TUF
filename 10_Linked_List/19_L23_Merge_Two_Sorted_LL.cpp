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

Node *merge2LL(Node *head1, Node *head2) {
  // TC O(N1 + N2 + NLogN + N)
  // SC O(N + N) N for storing array and N for returning ans
  Node *temp1 = head1;
  Node *temp2 = head2;
  vector<int> arr;
  while (temp1 != NULL) { // O(N1)
    arr.push_back(temp1->data);
    temp1 = temp1->next;
  }
  while (temp2 != NULL) { // O(N2)
    arr.push_back(temp2->data);
    temp2 = temp2->next;
  }

  sort(arr.begin(), arr.end());       // O(NLogN)
  Node *newHead = convertArr2LL(arr); // O(N)
  return newHead;
}

Node *optimizedMerge2LL(Node *head1, Node *head2) {
  // TC O(N1+N2)
  // SC O(1)
  Node *temp1 = head1;
  Node *temp2 = head2;
  Node *dummyNode = new Node(-1);
  Node *curr = dummyNode;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data < temp2->data) {
      curr->next = temp1;
      curr = temp1;
      temp1 = temp1->next;
    } else {
      curr->next = temp2;
      curr = temp2;
      temp2 = temp2->next;
    }
  }
  while (temp1 != NULL) {
    curr->next = temp1;
    curr = temp1;
    temp1 = temp1->next;
  }
  while (temp2 != NULL) {
    curr->next = temp2;
    curr = temp2;
    temp2 = temp2->next;
  }

  return dummyNode->next;
}

Node *optimizedMerge2LLPractice(Node *head1, Node *head2) {
  Node *dummyNode = new Node(-1);
  Node *temp = dummyNode;
  Node *temp1 = head1;
  Node *temp2 = head2;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data < temp2->data) {
      temp = temp1;
      temp1 = temp1->next;

    } else {
      temp = temp2;
      temp2 = temp2->next;
    }
    temp = temp->next;
  }

  while (temp1 != NULL) {
    temp = temp1;
    temp1 = temp1->next;
    temp = temp->next;
  }
  while (temp2 != NULL) {
    temp = temp2;
    temp2 = temp2->next;
    temp = temp->next;
  }

  return dummyNode->next;
}

int main() {
  cout << "20 L23 Merge Two Sorted LL" << endl;
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> arr2 = {1, 3, 3, 6, 11, 15};
  Node *head = convertArr2LL(arr);
  Node *head2 = convertArr2LL(arr2);
  printLL(head);
  printLL(head2);

  Node *head3 = merge2LL(head, head2);
  printLL(head3);
  Node *head4 = optimizedMerge2LL(head, head2);
  printLL(head4);
  Node *head5 = optimizedMerge2LLPractice(head, head2);
  printLL(head5);

  return 0;
}
