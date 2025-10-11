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

// See thif function when appears in code
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

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *removeNthNodefromEnd(Node *head, int N) {
  // TC O(2N)
  // SC O(1)
  Node *temp = head;
  int cnt = 0;
  while (temp != NULL) {
    cnt++;
    temp = temp->next;
  }
  if (cnt == N) {
    Node *newHead = head->next;
    delete (head);
    return newHead;
  }
  int res = cnt - N;
  temp = head;
  while (temp != NULL) {
    res--;
    if (res == 0) {
      break;
    }
    temp = temp->next;
  }
  Node *delNode = temp->next;
  temp->next = temp->next->next;
  delete (delNode);
  return head;
}

Node *optimalRemoveNthNodefromEnd(Node *head, int N) {
  // TC O(N)
  // SC O(1)
  Node *fastPtr = head;
  Node *slowPtr = head;

  for (int i = 0; i < N; i++) {
    fastPtr = fastPtr->next;
  }

  if (fastPtr == NULL) {
    Node *newHead = head->next;
    delete (head);
    return newHead;
  }

  // After this slowPtr will be at the Nth node from last
  while (fastPtr->next != NULL) {
    fastPtr = fastPtr->next;
    slowPtr = slowPtr->next;
  }

  Node *delNode = slowPtr->next;
  slowPtr->next = slowPtr->next->next;
  delete (delNode);

  return head;
}

int main() {
  cout << "8 Remove Nth Node from the end of the LinkedList" << endl;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  Node *head = convertArr2LL(arr);
  printLL(head);
  head = removeNthNodefromEnd(head, 8);
  printLL(head);
  head = optimalRemoveNthNodefromEnd(head, 7);
  printLL(head);

  return 0;
}
