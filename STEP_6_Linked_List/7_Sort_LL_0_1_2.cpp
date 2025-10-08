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

// See thif function when appears in code
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

Node *sort012(Node *head) {
  // TC O(2N)
  // SC O(1)
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *temp = head;
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  while (temp != NULL) {

    if (temp->data == 0) {
      cnt0++;
    } else if (temp->data == 1) {
      cnt1++;
    } else {

      cnt2++;
    }

    temp = temp->next;
  }
  // Now we will traverse the arr and replace the values in LL

  temp = head;

  while (temp != NULL) {
    if (cnt0 > 0) {
      temp->data = 0;
      cnt0--;
    } else if (cnt1 > 0) {
      temp->data = 1;
      cnt1--;
    } else if (cnt2 > 0) {
      temp->data = 2;
      cnt2--;
    }
    temp = temp->next;
  }

  return head;
}

Node *optimalSort012(Node *head) {
  // Use 3 dummy lists (for 0s, 1s, and 2s) and rearrange pointers
  // No need to rewrite data — we just rearrange node links
  // TC: O(N)
  // SC: O(1)

  // Base case: If list is empty or has one element, it's already sorted
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // Step 1: Create dummy heads for three separate lists
  // These dummy nodes help simplify list building logic
  Node *zeroHead = new Node(-1); // For nodes with data = 0
  Node *oneHead = new Node(-1);  // For nodes with data = 1
  Node *twoHead = new Node(-1);  // For nodes with data = 2

  // Step 2: Create tail pointers for each list
  Node *zero = zeroHead;
  Node *one = oneHead;
  Node *two = twoHead;

  // Step 3: Traverse the original linked list
  Node *temp = head;
  while (temp != NULL) {
    // Depending on node value, attach it to respective list
    if (temp->data == 0) {
      zero->next = temp; // connect current node to 0s list
      zero = temp;       // move tail pointer
    } else if (temp->data == 1) {
      one->next = temp; // connect current node to 1s list
      one = temp;       // move tail pointer
    } else {
      two->next = temp; // connect current node to 2s list
      two = temp;       // move tail pointer
    }
    // Move to next node in the original list
    temp = temp->next;
  }

  // Step 4: Merge the three lists together
  // Connect end of 0s list to start of 1s list if it exists,
  // otherwise connect directly to 2s list
  zero->next = (oneHead->next) ? oneHead->next : twoHead->next;

  // Connect end of 1s list to start of 2s list
  one->next = twoHead->next;

  // Terminate the final list
  two->next = NULL;

  // Step 5: The new head will be the start of 0s list (after dummy)
  Node *newHead = zeroHead->next;

  // Step 6: Delete dummy nodes to free memory
  delete zeroHead;
  delete oneHead;
  delete twoHead;

  // Step 7: Return the sorted list head
  return newHead;
}
int main() {
  cout << "5 Adding Two Numbers" << endl;
  vector<int> arr = {0, 1, 2, 2, 2, 1, 0, 2};
  Node *head = convertArr2LL(arr);
  printLL(head);
  head = sort012(head);
  printLL(head);
  head = optimalSort012(head);
  printLL(head);

  return 0;
}
