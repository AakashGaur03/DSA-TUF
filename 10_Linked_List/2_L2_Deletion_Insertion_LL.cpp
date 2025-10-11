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

#include <bits/stdc++.h>
using namespace std;

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

Node *removeHead(Node *head) {
  if (head == NULL)
    return head;
  Node *temp = head;
  head = head->next;
  delete temp;
  return head;
}

Node *removeTail(Node *head) {
  if (head == NULL || head->next == NULL) { // There is only one Node
    return NULL;
  }
  Node *temp = head;

  while (temp->next->next != NULL) {
    temp = temp->next; // Move to next till Second Last Comes
  }
  delete temp->next; // Delete Last element
  temp->next = nullptr;
  return head;
}

Node *removeKthElement(Node *head, int k) {
  // TC O(K)
  if (head == NULL)
    return head;
  Node *temp = head;
  if (k == 1) {
    head = head->next;
    delete temp;
    return head;
  }
  int cnt = 0;
  Node *prev = NULL;
  while (temp != NULL) {
    cnt++;
    if (cnt == k) {
      prev->next = prev->next->next;
      delete (temp);
      // Same as Delete
      // free(temp);
      break;
    } else {
      prev = temp;
      temp = temp->next;
    }
  }
  return head;
}
Node *removeElement(Node *head, int elem) {
  // TC O(K)
  if (head == NULL)
    return head;
  Node *temp = head;
  if (temp->data == elem) {
    head = head->next;
    delete temp;
    return head;
  }
  Node *prev = NULL;
  while (temp != NULL) {

    if (temp->data == elem) {
      prev->next = prev->next->next;
      delete (temp);
      // Same as Delete
      // free(temp);
      break;
    } else {
      prev = temp;
      temp = temp->next;
    }
  }
  return head;
}

Node *insertValHead(Node *head, int val) {
  // TC O(1)
  Node *temp = new Node(val, head); // Value and where to point
  return temp;                      // Returns as new Head
}

Node *insertValTail(Node *head, int val) {
  if (head == NULL) {
    return new Node(val);
  }
  Node *temp = head;
  while (temp->next != NULL) { // here we are checking value
    temp = temp->next;
  }
  Node *newNode = new Node(val);
  temp->next = newNode;
  return head;
}

Node *insertPosition(Node *head, int el, int k) {
  if (head == NULL) {
    if (k == 1) {
      return new Node(el);
    } else {
      return head;
    }
  }
  if (k == 1) {
    Node *newHead = new Node(el, head);
    return newHead; // returns it as new Head
  }
  int cnt = 0;
  Node *temp = head;
  while (temp != NULL) {
    cnt++;
    if (cnt == (k - 1)) {
      Node *newNode = new Node(el, temp->next);
      temp->next = newNode;
      break;
    } else {
      temp = temp->next;
    }
  }
  return head;
}
Node *insertElBeforeValue(Node *head, int el, int val) {
  if (head == NULL) {
    return NULL; // No value Exist so how can we insert before that
  }
  if (head->data == val) {
    Node *newHead = new Node(el, head);
    return newHead; // returns it as new Head
  }
  Node *temp = head;
  while (temp->next != NULL) {
    if (val == temp->next->data) {
      Node *newNode = new Node(el, temp->next);
      temp->next = newNode;
      break;
    } else {
      temp = temp->next;
    }
  }
  return head;
}

int main() {
  cout << "2 L2 Deletion Insertion LL " << endl;
  // we will be solving 4 varities for Each that is
  // Head
  // Position
  // Value
  // Last

  vector<int> arr = {12, 5, 8, 7, 6, 5, 4, 3};
  Node *head = convertArr2LL(arr);
  printLL(head);

  // 1) Delete the Head of the LL
  head = removeHead(head);
  printLL(head);

  // 2) Delete the Tail of the LL
  head = removeTail(head);
  printLL(head);

  // 3) Delete Kth element of LL
  head = removeKthElement(head, 4);
  printLL(head);

  // 4) Delete element of LL
  head = removeElement(head, 4);
  printLL(head);

  // 4) Delete element of LL
  head = removeElement(head, 5);
  printLL(head);

  // INSERTION

  // 1) Inserting at Head
  head = insertValHead(head, 100);
  printLL(head);

  // 2) Inserting at Tail
  head = insertValTail(head, 59);
  printLL(head);

  // 3) Inserting at Position
  head = insertPosition(head, 9, 2);
  printLL(head);
  // 3) Inserting at Position
  head = insertPosition(head, 29, 5);
  printLL(head);

  // 4) Inserting element before value
  head = insertElBeforeValue(head, 114, 5);
  printLL(head);

  return 0;
}
