

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

class stImpl {
  Node *topEl = nullptr;
  int sizeLL = 0;

public:
  void push(int x) {
    Node *temp = new Node(x);
    temp->next = topEl;
    topEl = temp;
    sizeLL = sizeLL + 1;
  }
  void pop() {
    if (topEl == nullptr) {
      cout << "Stack is empty\n";
      return;
    }
    Node *temp = topEl;
    topEl = topEl->next;
    delete (temp);
    sizeLL = sizeLL - 1;
  }
  int top() {
    if (topEl == nullptr) {
      cout << "Stack is empty\n";
      return -1;
    }
    return topEl->data;
  }
  int size() { return sizeLL; }
};

class quImpl {
  Node *start = nullptr;
  Node *end = nullptr;
  int sizeLL = 0;

public:
  void push(int x) {
    Node *temp = new Node(x);
    if (start == nullptr) {
      start = end = temp;
    } else {
      end->next = temp;
      end = temp;
    }
    sizeLL++;
  }
  void pop() {
    if (start == nullptr) {
      cout << "Queue UnderFlow \n";
      return;
    }
    Node *temp = start;
    start = start->next;
    delete temp;
    sizeLL--;
    if (start == nullptr) { // queue became empty
      end = nullptr;
    }
  }
  int top() {
    if (start == nullptr) {
      cout << "Queue UnderFlow \n";
      return -1;
    }
    return start->data;
  }
  int size() { return sizeLL; }
};

int main() {
  cout << "2 L1 Introduction to Stack and Queue.cpp" << endl;

  // Implementing Stack Using LinkedList
  // CHECK CLASS ABOVE stImpl

  // Implementing Queue Using LinkedList
  // CHECK CLASS ABOVE quImpl
  return 0;
}
