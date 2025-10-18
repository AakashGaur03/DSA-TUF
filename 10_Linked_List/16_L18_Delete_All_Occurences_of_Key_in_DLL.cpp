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

Node *deleteAllOccurences(Node *head, int val) {
  // TC O(N)
  // SC O(1)
  Node *temp = head;
  if (head == NULL)
    return NULL;

  while (temp != NULL) {
    if (temp->data == val) {
      if (temp == head) {
        head = head->next;
      }
      Node *prevNode = temp->back;
      Node *nextNode = temp->next;
      if (prevNode) {
        prevNode->next = nextNode;
      }
      if (nextNode) {
        nextNode->back = prevNode;
      }
      delete (temp);
      temp = nextNode;
    } else {

      temp = temp->next;
    }
  }

  return head;
}

int main() {
  cout << "16 L18 Delete All Occurences of Key in DLL" << endl;
  // We can go in both directions

  // Array to Doubly LL
  vector<int> arr = {12, 5, 8, 7, 6, 5, 4, 3};
  int val = 5;
  Node *head = convertArr2DoublyLL(arr);
  printLL(head);
  head = deleteAllOccurences(head, val);
  printLL(head);

  return 0;
}
