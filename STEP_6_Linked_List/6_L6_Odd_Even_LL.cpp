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

Node *oddEvenLL(Node *head) {
  // TC O(2N)
  // SC O(N) arr
  if (head == NULL || head->next == NULL) {
    return head;
  }
  vector<int> arr;
  Node *temp = head;
  // --------
  // TC O(N/2)
  while (temp != NULL && temp->next != NULL) {
    // Pushes all odd index in arr
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp) {
    // Ex we have 1 7 8 so above condition fails for index 2 so we need to take
    // care of that
    arr.push_back(temp->data);
  }
  // --------

  // --------
  // TC O(N/2)
  temp = head->next;
  // Now this pushes all even index in arr
  while (temp != NULL && temp->next != NULL) {
    arr.push_back(temp->data);
    temp = temp->next->next;
  }
  if (temp) {
    // Ex we have 1 7 8 4 so above condition fails for index 2 so we need to
    // take care of that
    arr.push_back(temp->data);
  }
  // --------

  // Now we will traverse the arr and replace the values in LL

  int i = 0;
  temp = head;

  while (temp != NULL) {
    temp->data = arr[i];
    temp = temp->next;
    i++;
  }

  return head;
}

Node *optimalOddEvenLL(Node *head) {
  // TC O(N/2 *2)
  // SC O(1)
  // Refer to 6_L6_Odd_Even_LL_1 Image
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *odd = head;
  Node *even = head->next;
  Node *evenHead = head->next;

  while (even != NULL && even->next != NULL) {
    odd->next = odd->next->next;
    even->next = even->next->next;

    odd = odd->next;   // the odd->next already points to the next odd node.
    even = even->next; // the even->next already points to the next even node.
  }

  // For last odd to point to Even
  odd->next = evenHead;

  return head;
}

int main() {
  cout << "5 Adding Two Numbers" << endl;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
  Node *head = convertArr2LL(arr);
  printLL(head);
  head = oddEvenLL(head);
  printLL(head);

  return 0;
}
