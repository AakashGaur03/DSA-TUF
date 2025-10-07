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

Node *addTwoNumbers(Node *t1, Node *t2) {
  // TC O (max(N1,N2))
  // SC O(max(N1,N2))
  // if we want we can store t1 and t2 as temp1 and temp2 and do
  // iteration so we dont update the heads
  Node *dummyNode = new Node(-1);
  Node *curr = dummyNode;
  int carry = 0;
  while (t1 != NULL || t2 != NULL) {
    int sum = carry;
    if (t1) {
      sum = sum + t1->data;
    }
    if (t2) {
      sum = sum + t2->data;
    }
    Node *newNode = new Node(sum % 10);
    carry = sum / 10;
    curr->next = newNode;
    curr = curr->next;

    if (t1) {
      t1 = t1->next;
    }
    if (t2) {
      t2 = t2->next;
    }
  }

  if (carry) {
    Node *newNode = new Node(carry);
    curr->next = newNode;
  }
  return dummyNode->next;
}
int main() {
  cout << "5 Adding Two Numbers" << endl;
  vector<int> arr1 = {1, 2, 3};
  vector<int> arr2 = {4, 5, 6};
  Node *head1 = convertArr2LL(arr1);
  Node *head2 = convertArr2LL(arr2);
  Node *head = addTwoNumbers(head1, head2);
  printLL(head);
  return 0;
}
