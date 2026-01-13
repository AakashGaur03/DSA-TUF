#include <bits/stdc++.h>
using namespace std;

class implementMinStack {
  // TC O(1)
  // SC O(2N)
public:
  stack<pair<int, int>> st;
  void push(int val) {
    if (st.empty()) {
      st.push({val, val});
    } else {
      //   if (val < st.top().second) {
      //     st.push({val, val});
      //   } else {
      //     st.push({val, st.top().second});
      //   }
      st.push({val, min(val, st.top().second)});
    }
  }

  void pop() {
    if (!st.empty()) {
      st.pop();
    }
  }
  int top() {
    if (!st.empty()) {
      return st.top().first;
    }
    return -1;
  }
  int size() { return st.size(); }
  int getMin() {
    if (!st.empty()) {
      return st.top().second;
    }
    return -1;
  }
};

class implementMinStack2 {
  // 8_L4_Implement_Min_Stack_2nd_Approach.png
  // 8_L4_Implement_Min_Stack_2nd_Approach_1.png

  /*
   Idea:
      We use only ONE stack and one variable `mini` to track
      the minimum element at any point.

    Trick:
      When a new element becomes the minimum, instead of pushing
      it directly, we PUSH AN ENCODED VALUE.

      Encoding formula:
        encoded = 2 * val - mini

      This encoded value is ALWAYS smaller than the new minimum,
      which helps us identify it during pop/top operations.
      */

  // TC O(1)
  // SC O(N)
public:
  stack<int> st;
  int mini = INT_MAX;
  void push(int val) {
    if (st.empty()) {
      mini = val;
      st.push(val);
    } // Case 2: New value is NOT a minimum
    else if (val > mini) {
      st.push(val); // push normally
    }
    // Case 3: New value IS the new minimum
    else {
      // Push encoded value instead of actual value
      // This helps us remember the previous minimum
      st.push(2 * val - mini);

      // Update minimum to the new value
      mini = val;
    }
  }

  void pop() {
    if (st.empty()) {
      return;
    }
    int x = st.top();
    st.pop();
    // If popped value is encoded
    if (x < mini) {
      /*
        This means:
        - Current minimum is being removed
        - We must restore the previous minimum

        Decoding formula:
          previous_min = 2 * current_min - encoded_value
      */
      mini = 2 * mini - x;
    }
  }
  int top() {
    if (st.empty()) {
      return -1;
    }
    int x = st.top();
    if (x >= mini) {
      return x;
    } else {
      return mini;
    }
  }
  int size() { return st.size(); }
  int getMin() {
    if (st.empty())
      return -1;
    return mini;
  }
};

int main() {
  cout << "8 L4 Implement Min Stack" << endl;
  // This means To design a stack in a manner that it performs its basic
  // operations that is
  // push pop top size and additionally getMin
  // getMin gives us the minimum value in the stack

  // What we will do is take a pair in stack
  // stack pair<int,int>
  // First will be value that is inserted and second is minimum value upto it
  // So that for each value we have what was the minimum value

  implementMinStack ms;
  ms.push(5);
  ms.push(3);
  ms.push(7);

  cout << "Top: " << ms.top() << endl;    // 7
  cout << "Min: " << ms.getMin() << endl; // 3

  ms.pop();

  cout << "Top after pop: " << ms.top() << endl;    // 3
  cout << "Min after pop: " << ms.getMin() << endl; // 3

  return 0;
}