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

Node *reverseDll(Node *head) {
  // TC O(2N)
  // SC O(N) Stack
  // First Iteration Store every value of node in a Stack
  Node *temp = head;
  stack<int> st;
  while (temp != NULL) {
    st.push(temp->data);
    temp = temp->next;
  }

  // Second Interation Pop from stack replace from start to end
  temp = head;
  while (temp != NULL) {
    temp->data = st.top();
    st.pop();
    temp = temp->next;
  }
  return head;
}

Node *optimizedReverseDll(Node *head) {
  // TC O(N)
  // SC O(1)
  if (head == NULL || head->next == NULL) {
    return head;
  }
  // Update the Links for eack
  Node *current = head;
  Node *prev = NULL;
  while (current != NULL) {
    prev = current->back;
    current->back = current->next;
    current->next = prev;
    current = current->back;
  }
  // Current geos to NULL in last
  // Thats why not returning current
  return prev->back;
}

int main() {
  cout << "4 Reverse a DLL" << endl;
  vector<int> arr = {12, 5, 8, 7};
  Node *head = convertArr2DoublyLL(arr);
  printLL(head);
  head = reverseDll(head);
  printLL(head);

  head = optimizedReverseDll(head);
  printLL(head);
  return 0;
}
