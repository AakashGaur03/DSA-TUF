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

bool palindromeOrNot(Node *head) {
  // TC O(2N)
  // SC O(N) Stack Space
  Node *temp = head;
  stack<int> st;

  while (temp != NULL) {
    st.push(temp->data);
    temp = temp->next;
  }

  temp = head;

  while (temp != NULL) {
    if (temp->data != st.top()) {
      return false;
    }
    st.pop();
    temp = temp->next;
  }
  return true;
}

Node *reverseLL(Node *head) {
  // TC O(N)
  // SC O(N) // Recursive Stack Space
  // One Node (Base Case)
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *newHead = reverseLL(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;

  return newHead;
}

bool optimalPalindromeOrNot(Node *head) {
  // TC O(2N)
  // SC O(1)
  if (head == NULL || head->next == NULL) {
    return true;
  }
  Node *slow = head;
  Node *fast = head;

  // Gets us Middle of LL
  while (fast->next != NULL && fast->next->next != NULL) {
    // TC O(N/2)
    slow = slow->next;
    fast = fast->next->next;
  }
  // We reverse the second Half so we get as mentioned in Image
  // Again O(N/2) as reversing half
  Node *newHead = reverseLL(slow->next);

  Node *first = head;
  Node *second = newHead;

  // traversing till second becomes NULL
  while (second != NULL) {
    // TC O(N/2)
    if (first->data != second->data) {
      reverseLL(newHead); // preserve to original TC O(N/2)
      return false;
    }
    first = first->next;
    second = second->next;
  }
  // Either this or in Loop one will be executed preserve to original TC O(N/2)
  reverseLL(newHead);
  return true;
}

int main() {
  cout << "4 Reverse a DLL" << endl;
  vector<int> arr = {1, 5, 5, 1};
  Node *head = convertArr2LL(arr);
  printLL(head);
  bool isPalindrome = palindromeOrNot(head);
  cout << isPalindrome;
  bool isPalindrome2 = optimalPalindromeOrNot(head);
  cout << isPalindrome2;

  return 0;
}
