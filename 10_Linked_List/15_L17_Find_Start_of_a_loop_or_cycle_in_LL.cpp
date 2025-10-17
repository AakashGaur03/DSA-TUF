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

Node *startOfLoopLL(Node *head) {
  // TC O(N) // Unordered Map
  // SC O(N)
  // TC O(N*2*logN) N for loop 2*logN is for 2 operations of map // in map
  Node *temp = head;
  unordered_map<Node *, int> mpp;
  while (temp != NULL) {
    if (mpp.find(temp) != mpp.end()) {
      return temp;
    }
    mpp[temp] = 1;
    temp = temp->next;
  }
  return NULL;
}

Node *startingPoint(Node *slow, Node *fast, Node *head) {
  // We take slow to Head
  // Fast remains at collision point when we detected the loop
  slow = head;
  // When they will collide That is our start of Loop
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

Node *optimizedStartOfLoopLL(Node *head) {
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
      return startingPoint(slow, fast, head);
  }
  // Means there is no Loop
  return NULL;
}

/*
EXPLANATION (Connected Concept):

We use two pointers moving at different speeds:
- slow → moves one step
- fast → moves two steps

If a loop exists, both pointers will eventually meet inside the loop.
This confirms a cycle is present.

But how do we find where the loop begins?

Let's break it down mathematically:
-----------------------------------
Let:
  L1 = distance from head to start of loop
  L2 = distance from start of loop to meeting point
  C  = length of the loop

At the meeting point:
  Distance traveled by slow = L1 + L2
  Distance traveled by fast = L1 + L2 + n*C   (since fast may loop around n
times)

Because fast moves twice as fast:
  2 * (L1 + L2) = L1 + L2 + n*C
  ⟹ L1 = n*C - L2

This means:
If we move one pointer from head (L1 distance)
and one pointer from meeting point (n*C - L2 distance),
they’ll meet exactly at the loop’s starting node.


*/
int main() {
  cout << "Detect a loop or cycle in LL" << endl;
  vector<int> arr = {12, 5, 8, 7, 6};
  Node *head = convertArr2LL(arr);
  head->next->next->next->next = head->next;
  // 12 → 5 → 8 → 7 → 6 ↘
  //      ↑──────────────┘
  Node *loopStart = startOfLoopLL(head);

  if (loopStart != NULL)
    cout << "Loop starts at node with value: " << loopStart->data << endl;
  else
    cout << "No loop detected." << endl;

  Node *loopStart2 = optimizedStartOfLoopLL(head);

  if (loopStart2 != NULL)
    cout << "Loop starts at node with value: " << loopStart2->data << endl;
  else
    cout << "No loop detected." << endl;

  return 0;
}
