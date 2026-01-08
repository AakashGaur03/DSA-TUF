

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
  // Concept is that whenever we push a new element we will take all the
  // elements and then push them again
  queue<int> qu;

public:
  void push(int x) {
    // TC O(N)
    int s = qu.size();
    qu.push(x);

    // Move all previous elements behind the new element
    for (int i = 0; i < s; i++) {
      qu.push(qu.front());
      qu.pop();
    }
  }
  void pop() {
    // TC O(1)
    if (qu.empty()) {
      cout << "Stack is empty\n";
      return;
    }
    qu.pop();
  }
  int top() {
    // TC O(1)
    if (qu.empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    return qu.front();
  }
  int size() {
    // TC O(1)
    return qu.size();
  }
};

class quImpl {
  // Queue using 2 stacks (push-costly)

  // Concept is
  // For Push Operation
  // -  Whatever there is in S1 put in S2
  // -  Put x variable in S1
  // -  Put All elements from S2 to S1
  stack<int> st1;
  stack<int> st2;

public:
  void push(int x) {
    // TC O(2N)
    while (st1.size()) {
      st2.push(st1.top());
      st1.pop();
    }
    st1.push(x);
    while (st2.size()) {
      st1.push(st2.top());
      st2.pop();
    }
  }

  void pop() {
    // TC O(1)
    if (st1.empty()) {
      cout << "Queue is empty\n";
      return;
    }
    st1.pop();
  }

  int top() {
    // TC O(1)
    if (st1.empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    return st1.top();
  }

  int size() {
    // TC O(1)
    return st1.size();
  }
};
class quImpl2 {
  // Queue using 2 stacks (pop and top costly)

  stack<int> st1;
  stack<int> st2;

public:
  void push(int x) {
    // TC O(1)
    st1.push(x);
  }

  void pop() {
    // TC O(N)
    if (st1.empty() && st2.empty()) {
      cout << "Queue is empty\n";
      return;
    }
    if (!st2.empty()) {
      st2.pop();
    } else {
      while (st1.size()) {
        st2.push(st1.top());
        st1.pop();
      }
      st2.pop();
    }
  }

  int top() {
    // TC O(N)

    if (st1.empty() && st2.empty()) {
      cout << "Queue is empty\n";
      return -1;
    }

    if (!st2.empty()) {
      return st2.top();
    } else {
      while (st1.size()) {
        st2.push(st1.top());
        st1.pop();
      }
      return st2.top();
    }
  }

  int size() {
    // TC O(N)
    return st1.size() + st2.size();
  }
};

int main() {
  cout << "3 L1 Introduction to Stack and Queue.cpp" << endl;

  // Implementing Stack Using Queue DS
  // CHECK CLASS ABOVE stImpl

  // Implementing Queue Using Stack DS
  // CHECK CLASS ABOVE quImpl (Push expensive When less push operations) and
  // quImpl2 (when more push operations)
  return 0;
}
