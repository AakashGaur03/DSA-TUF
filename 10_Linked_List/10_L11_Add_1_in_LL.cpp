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

Node *reverseLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;
  return newHead;
}

Node *addOne(Node *head) {
  // TC O(3N)
  // SC O(2N) // two time reverse so two time Stack space
  head = reverseLL(head); // TC O(N)
  int carry = 1;          // we need to add 1;
  Node *temp = head;
  while (temp != NULL) {
    // TC O(N)
    temp->data = temp->data + carry;
    if (temp->data < 10) {
      carry = 0;
      break;
    } else {
      temp->data = 0;
      carry = 1;
    }
    temp = temp->next;
  }
  // once Traversal is completed we have two case that we have breaked out
  // because carry = 0 ( 129 + 1)
  // or LL is exhaused and we have a carry value EX in case 9999 + 1
  if (carry == 1) {
    Node *newNode = new Node(1);
    head = reverseLL(head); // TC O(N)
    newNode->next = head;
    return newNode;
  }
  // Here means we have carry = 0
  head = reverseLL(head); // TC O(N)
  return head;
}

int addHelper(Node *temp) {
  if (temp == NULL) {
    return 1; // When in base case we send 1 to add from last Node
  }
  int carry = addHelper(temp->next); // Moving to Last Node
  // Now when code comes here it is to last node
  temp->data += carry; // adds in last node
  if (temp->data < 10) {
    // we have added to temp->data we just need to return 0
    return 0;
  }
  // Means Number is 10
  temp->data = 0; // sets last to 0
  return 1;       // retutns carry as 1
}

Node *optimalAddOne(Node *head) {
  // Recursive Approach BACKTRACKING
  // TC O(N)
  // SC O(N) Recursive Stack Space
  int carry = addHelper(head);
  if (carry == 1) {
    Node *newNode = new Node(1);
    newNode->next = head;
    return newNode;
  }
  return head;
}

int main() {
  cout << "4 Reverse a DLL" << endl;
  vector<int> arr = {1, 5, 5, 9};
  Node *head = convertArr2LL(arr);
  printLL(head);
  head = addOne(head);
  printLL(head);
  head = optimalAddOne(head);
  printLL(head);

  return 0;
}
