#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *random;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
    random = nullptr;
  }

public:
  Node(int data1, Node *next1, Node *random1) {
    data = data1;
    next = next1;
    random = random1;
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
    if (temp->random)
      cout << "-> Random: " << temp->random->data << ", ";
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

Node *cloneLLwithNextAndRandom(Node *head) {
  // TC O(N + N)
  // SC O(2N)
  // SC O(N) for hashmap + O(N) for coyNode
  Node *temp = head;
  unordered_map<Node *, Node *>
      mpp; // One will be Original // Second is copied one
  while (temp != NULL) {
    Node *newNode = new Node(temp->data);
    mpp[temp] = newNode;
    temp = temp->next;
  }

  temp = head;
  while (temp != NULL) {
    Node *copyNode = mpp[temp];
    copyNode->next = mpp[temp->next];
    copyNode->random = mpp[temp->random];
    temp = temp->next;
  }
  return mpp[head];

  // Approach We will iterate over LL and create and store each node in a map;
  // So we will have a map pointing to its copy

  // Then we start creating map values as copyNode and points them acc to there
  // mapped values
}

Node *OptimalcloneLLwithNextAndRandom(Node *head) {
  // TC O(3N) // 3 Traversals
  // SC O(N) // created new List otherwise O(1)
  // Three steps
  // Include Copy nodes in between
  // Point random nodes to correct
  // Point next nodes to corect (Also Note we have to get original lost as it is
  // too)

  // Step 1 : Include Copy nodes in between
  Node *temp = head;
  while (temp != NULL) {
    Node *copyNode = new Node(temp->data, temp->next);
    temp->next = copyNode;
    temp = temp->next->next;
  }

  // Step 2 : Point random nodes to correct
  temp = head;
  while (temp != NULL && temp->next != NULL) {
    // This sets the copied node’s random to the original random node, not to
    // the copied random node.
    //  temp->next->random = temp->random ? temp->random : NULL;
    temp->next->random = temp->random ? temp->random->next : NULL;
    // means copyNode->random points to if temp->random exist to its next
    temp = temp->next->next;
  }

  // Step 3 : Point next nodes to corect
  //(Also Note we have to get original lost as it is too)
  temp = head;
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;
  while (temp != NULL && temp->next != NULL) {
    res->next = temp->next;
    temp->next = temp->next->next;
    res = res->next;
    temp = temp->next;
  }

  return dummyNode->next;
}
int main() {
  cout << "24 Clone a LinkedList with Next and Random Pointers" << endl;
  cout << "Copy List with Random Pointers" << endl;
  vector<int> arr = {1, 8, 7, 12, 3};
  Node *head = convertArr2LL(arr);

  // Manually assign random pointers
  head->random = head->next->next;                               // 1 → 7
  head->next->random = head;                                     // 8 → 1
  head->next->next->random = head->next;                         // 7 → 8
  head->next->next->next->random = head->next->next->next->next; // 12 → 3
  head->next->next->next->next->random = head;                   // 3 → 1

  cout << "Original Linked List:\n";
  printLL(head);

  Node *cloned = cloneLLwithNextAndRandom(head);

  cout << "Cloned Linked List:\n";
  printLL(cloned);

  cout << "Cloned Linked List optimal Approach:\n";
  Node *optimalCloned = OptimalcloneLLwithNextAndRandom(head);
  printLL(optimalCloned);
  return 0;
}

// ------------------- STEP 1 -------------------
// Insert cloned nodes in between original nodes.
// Example:
// Original: 1 -> 2 -> 3
// After Step 1: 1 -> 1' -> 2 -> 2' -> 3 -> 3'

// ------------------- STEP 2 -------------------
// Set random pointers of the cloned nodes.
// For each original node, its clone (temp->next)
// should have random = temp->random->next (the clone of original random)

// ------------------- STEP 3 -------------------
// Separate the two linked lists.
// Restore original list and extract cloned list.

/*
    Example:
List = 1 -> 8 -> 7 -> 12 -> 3
Randoms:
1→7, 8→1, 7→8, 12→3, 3→1

Step 1: Insert cloned nodes
1 -> 1' -> 8 -> 8' -> 7 -> 7' -> 12 -> 12' -> 3 -> 3'

Step 2: Assign random pointers
1' random = 1.random->next = 7'
8' random = 8.random->next = 1'
7' random = 7.random->next = 8'
12' random = 12.random->next = 3'
3' random = 3.random->next = 1'

Step 3: Separate both lists
Original: 1 -> 8 -> 7 -> 12 -> 3
Cloned:   1' -> 8' -> 7' -> 12' -> 3'
Randoms are correctly assigned.

-----------------------------------------------------------
*/
