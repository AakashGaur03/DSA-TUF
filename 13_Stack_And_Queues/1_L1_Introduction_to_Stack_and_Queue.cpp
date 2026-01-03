

#include <bits/stdc++.h>
using namespace std;

class stImpl {
  int topIdx = -1;
  int st[10]; // Here we need to ask the interviewer the size of stack
  // It cant be Dynamic in This array-based stack implementation is static
  // If we want Dynamic we can use vector
public:
  void push(int x) {
    // TC O(1)
    if (topIdx == 9) {
      cout << "Stack Overflow\n";
      return;
    }
    topIdx = topIdx + 1;
    st[topIdx] = x;
  }
  int top() {
    // TC O(1)
    if (topIdx == -1) {
      cout << "Stack Underflow\n";
      return -1;
    }
    return st[topIdx];
  }
  void pop() {
    // TC O(1)
    if (topIdx == -1) {
      cout << "Stack Underflow\n";
      return;
    }
    topIdx = topIdx - 1;
  }
  int size() {
    // TC O(1)
    return topIdx + 1;
  }
  bool empty() {
    // TC O(1)
    return topIdx == -1;
  }
};

class quImpl {
  // It is FIFO First In First Out
  // We need to Pointers to Keep track of First In and Last Inserted
  // start and end
  // There are multiple edge cases we will cover them all

  int sizeCapacity = 10;
  int q[10];
  int currSize = 0;
  int start = -1;
  int end = -1;

public:
  void push(int x) {
    // TC O(1)
    if (currSize == sizeCapacity) {
      cout << "Queue Overflow\n";
      return;
    } else if (currSize == 0) {
      start = 0;
      end = 0;
    } else {
      end = (end + 1) % sizeCapacity;
    }
    q[end] = x;
    currSize += 1;
  }
  int pop() {
    // TC O(1)
    if (currSize == 0) {
      cout << "Queue Underflow\n";
      return -1;
    }
    int el = q[start];
    if (currSize == 1) {
      start = -1;
      end = -1;
    } else {
      start = (start + 1) % sizeCapacity;
    }
    currSize -= 1;
    return el;
  }
  int front() {
    // TC O(1)
    if (currSize == 0) {
      cout << "Queue Underflow\n";
      return -1;
    }

    return q[start];
  }
  int size() {
    // TC O(1)
    return currSize;
  }
};
int main() {
  cout << "1 L1 Introduction to Stack and Queue.cpp" << endl;
  // Stack Holds a certain type of DS
  // Can be a sinngle Data Type can be Customizes too
  // Stack is LIFO Last In First Out
  // We have 4 Operations
  // push() // Inserts at Top
  // pop() // Takes out Last Element Inserted
  // top() // Tells us the Last Inserted Element
  // size() // Tells the size of Stack

  // Queue Holds a certain type of DS
  // Can be a sinngle Data Type can be Customizes too
  // Queue is FIFO First In First Out
  // We have 4 Operations
  // push() // Inserts at Top
  // pop() // Takes out First Element Inserted
  // front() // Tells us the First Element
  // size() // Tells the size of Stack

  stack<int> st;
  st.push(3); // stack: 3
  st.push(4); // stack: 3 4 (top)
  st.pop();   // removes 4
  st.top();   // returns 3
  st.size();  // returns 1

  queue<int> qu;
  qu.push(3); // queue: 3
  qu.push(4); // queue: 3 4
  qu.pop();   // removes 3
  qu.front(); // returns 4
  qu.size();  // returns 1

  // Implementing Stack Using Array
  // CHECK CLASS ABOVE stImpl

  // Implementing Queue Using Array
  // CHECK CLASS ABOVE quImpl
  return 0;
}
