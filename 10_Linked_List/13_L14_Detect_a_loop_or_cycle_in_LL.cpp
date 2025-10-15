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

bool detectLoopLL(Node *head) {
  Node *temp = head;
  unordered_map<Node *, int> mpp;
  while (temp != NULL) {
    if (mpp.find(temp) != mpp.end()) {
      return true;
    }
    mpp[temp] = 1;
    temp = temp->next;
  }
  return false;
}

bool optimizedDetectLoopLL(Node *head) {
  // TC O(N)
  // SC O(1)
  // Slow Pointer and Fast Pointer
  // Slow Pointer moves 1 step
  // Fast Pointer moves 2 step
  Node *slow = head;
  Node *fast = head;
  while (fast != NULL && fast->next != NULL) {
    // When Odd Fast goes on last Node
    slow = slow->next;
    // When Even Fast goes on NULL Node
    fast = fast->next->next;
    if (fast == slow)
      return true;
  }
  return false;
}

int main() {
  cout << "Detect a loop or cycle in LL" << endl;
  vector<int> arr = {12, 5, 8, 7, 6};
  Node *head = convertArr2LL(arr);
  head->next->next->next->next = head->next;
  // 12 → 5 → 8 → 7 → 6 ↘
  //      ↑──────────────┘

  if (detectLoopLL(head))
    cout << "Loop detected (using map method)" << endl;
  else
    cout << "No loop (using map method)" << endl;

  if (optimizedDetectLoopLL(head))
    cout << "Loop detected (using optimized method)" << endl;
  else
    cout << "No loop (using optimized method)" << endl;

  return 0;
}
