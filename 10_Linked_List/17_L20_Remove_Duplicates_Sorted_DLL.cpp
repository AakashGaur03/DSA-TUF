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

Node *removeDuplicates(Node *head) {
  // TC O(N)
  // SC O(1)
  if (head == NULL || head->next == NULL) {
    return head;
  }

  Node *temp = head;
  while (temp != NULL && temp->next != NULL) {
    Node *newNode = temp->next;
    if (temp->data == newNode->data) {
      Node *repeatedNode = newNode;
      newNode = newNode->next;
      temp->next = newNode;
      if (newNode) {
        newNode->back = temp;
      }
      delete (repeatedNode);
    } else {
      // It comes under else because if we do it every time
      // it will only remove 1st double
      // like if we have 4 4 4
      // It will only delete 1 4 and will move the temp
      temp = temp->next;
    }
  }
  return head;
}

int main() {
  cout << "17 L20 Remove Duplicates from Sorted DLL" << endl;
  vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 4, 9};
  int sum = 5;
  // DLL is in sorted order
  Node *head = convertArr2DoublyLL(arr);
  printLL(head);

  head = removeDuplicates(head);
  printLL(head);

  return 0;
}
