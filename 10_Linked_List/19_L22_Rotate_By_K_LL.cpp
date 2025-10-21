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

Node *findNthNode(Node *temp, int k) {
  int cnt = 1;
  while (temp != NULL) {
    if (cnt == k) {
      return temp;
    }
    cnt++;
    temp = temp->next;
  }
  return temp;
}

Node *rotateByK(Node *head, int k) {
  // TC O(2N)
  // SC O(1)
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // Find the tail and length of LL
  Node *tail = head;
  int length = 1;
  while (tail->next != NULL) {
    length++;
    tail = tail->next;
  }

  // If k is multiple of length → no rotation needed
  if (k % length == 0) {
    return head;
  }

  // Connect tail to head to make it circular
  tail->next = head;
  k = k % length;

  // Find the new last node (length - k)
  Node *newLastNode = findNthNode(head, length - k);

  // New head will be next of newLastNode
  head = newLastNode->next;

  // Break the circle
  newLastNode->next = NULL;
  return head;
}

int main() {
  cout << "19 L22 Rotate By K LL" << endl;
  vector<int> arr = {1, 2, 3, 4, 5};
  Node *head = convertArr2LL(arr);
  printLL(head);
  // After rotating it for 2 times
  // K = 1:  5 1 2 3 4
  // K = 2:  4 5 1 2 3

  // Basically what we need to do is we need to point tail to head
  // then the point at which we need that is length of LL - k (3 in our case)
  // we just update the head as temp->next and then temp->next = NULL
  int k = 2;
  head = rotateByK(head, 2);
  printLL(head);

  return 0;
}
