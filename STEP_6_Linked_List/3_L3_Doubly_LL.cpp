#include <bits/stdc++.h>
using namespace std;

// Doubly LL
class Node {
public:
  int data;
  Node *next;
  Node *back;

public:
  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }

  // we can also add if we dont want to assign null
  // in code again and again
public:
  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
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
Node *convertArr2DoublyLL(vector<int> &arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;

  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }

  return head;
}

Node *deleteHeadDoublyLL(Node *head) {
  if (head == NULL)
    return head;
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  Node *prev = head;
  head = head->next;
  head->back = NULL;
  prev->next = NULL;
  delete (prev);

  return head;
}

Node *deleteTailDoublyLL(Node *head) {
  if (head == NULL)
    return head;
  if (head->next == NULL) {
    delete head;
    return NULL;
  }
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  Node *prev = tail->back;
  prev->next = nullptr;
  tail->back = nullptr;
  delete (tail);
  return head;
}

Node *deleteKthDoublyLL(Node *head, int k) {
  if (head == NULL)
    return NULL;
  int cnt = 0;
  Node *KNode = head;
  while (KNode != NULL) {
    cnt++;
    if (cnt == k)
      break;
    KNode = KNode->next;
  }
  Node *prev = KNode->back;
  Node *front = KNode->next;

  if (prev == NULL && front == NULL) {
    return NULL;
  } else if (prev == NULL) {
    // MEANS FIRST ELEMENT
    return deleteHeadDoublyLL(head);
  } else if (front == NULL) {
    // MEANS LAST ELEMENT
    return deleteTailDoublyLL(head);
  } else {
    // IN BETWEEN SOMEWHERE
    prev->next = front; // or KNode->next
    front->back = prev; // or KNode->back
    KNode->back = nullptr;
    KNode->next = nullptr;
    delete (KNode);
  }
  return head;
}

void deleteNodeDoublyLL(Node *temp) {
  Node *prev = temp->back;
  Node *front = temp->next;
  if (front == NULL) {
    prev->next = nullptr;
    temp->back = nullptr;
    delete (temp);
    return;
  }
  prev->next = front;
  front->back = prev;
  temp->next = temp->back = nullptr;
  delete (temp);
  return;
}

Node *insertBeforeHeadDoublyLL(Node *head, int val) {
  Node *newHead = new Node(val, head, nullptr);
  head->back = newHead;

  return newHead;
}
Node *insertBeforeTailDoublyLL(Node *head, int val) {
  if (head->next == NULL) { // Only one element
    return insertBeforeHeadDoublyLL(head, val);
  }
  Node *tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }
  Node *prev = tail->back;
  Node *newNode = new Node(val, tail, prev);
  prev->next = newNode;
  tail->back = newNode;
  return head;
}

Node *insertBeforeKthDoublyLL(Node *head, int val, int k) {
  if (head == NULL) {
    return new Node(val, NULL, NULL);
  }
  if (k == 1) {
    return insertBeforeHeadDoublyLL(head, val);
  }
  Node *temp = head;
  int cnt = 0;
  while (temp != NULL) {
    cnt++;
    if (cnt == k) {
      break;
    }
    temp = temp->next;
  }
  // Case 3: k > length → no insertion
  if (temp == NULL) {
    return head;
  }

  Node *prev = temp->back;
  Node *newNode = new Node(val, temp, prev);
  prev->next = newNode;
  temp->back = newNode;
  return head;
}

void insertBeforeNodeDoublyLL(Node *node, int val) {
  Node *prev = node->back;
  Node *newNode = new Node(val, node, prev);
  prev->next = newNode;
  node->back = newNode;
}

int main() {
  cout << "3 L3 Doubly LL" << endl;
  // We can go in both directions

  // Array to Doubly LL
  vector<int> arr = {12, 5, 8, 7, 6, 5, 4, 3};
  Node *head = convertArr2DoublyLL(arr);
  printLL(head);

  // Delete Head
  head = deleteHeadDoublyLL(head);
  printLL(head);

  // Delete Tail
  head = deleteTailDoublyLL(head);
  printLL(head);

  // Delete at index
  head = deleteKthDoublyLL(head, 3);
  printLL(head);

  // Delete Node
  // Node will never be Head
  deleteNodeDoublyLL(head->next->next);
  printLL(head);

  // Insertion Before Head
  head = insertBeforeHeadDoublyLL(head, 10);
  printLL(head);

  // Insertion Before Tail
  head = insertBeforeTailDoublyLL(head, 13);
  printLL(head);

  // Insertion Before Kth Node
  head = insertBeforeKthDoublyLL(head, 39, 3);
  printLL(head);

  // Insertion Before Node
  // This node will not be Head
  insertBeforeNodeDoublyLL(head->next->next, 23);
  printLL(head);
  return 0;
}
